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

void touchMove(){
	motor[motorC] = 0;
	motor[motorB] = 0;

	wait1Msec(500);

	//Multiplied by negative 1 to go backwards
	motor[motorC] = speed *-1;
	motor[motorB] = speed *-1;
	wait1Msec(1000);

	//Multiplied by .5 to go half speed
	motor[motorC] = speed;
	motor[motorB] = speed *.5;
	wait1Msec(1000);

}

task main()
{
	//Do this when not touched
 while (SensorValue(touchSensor) == 0) {
 	lightMove();
 }
 	//Do touchmove when touched
	touchMove();

	while (SensorValue(touchSensor) == 0) {
 	lightMove();
 }
	touchMove();
}
