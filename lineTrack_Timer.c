#pragma config(Sensor, S1,     touchSensor,    sensorTouch)
#pragma config(Sensor, S3,     lightSensor,    sensorLightActive)
//*!!Code automatically generated by 'ROBOTC' configuration wizard               !!*//

//Variables
//Speed defined as 50u
int speed = 50;
int x = 50;

//Functions
//Int X defined as threshold
void lightMove(){

	if(SensorValue(lightSensor) > x){
	motor[motorC] = speed;
	motor[motorB] = 0;
	}
	else{
	motor[motorC] = 0;
	motor[motorB] = speed;
	}

}

task main()
{
	clearTimer(T1);
	//Do this when not touched
	while (time1[T1] < 3000) {
		lightMove();
	}
}
