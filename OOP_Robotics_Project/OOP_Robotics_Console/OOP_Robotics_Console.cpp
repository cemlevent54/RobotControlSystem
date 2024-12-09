// OOP_Robotics_Console.cpp : This file contains the 'main' function. Program execution begins and ends there.
//

#include <iostream>
#include "Pose.h"
#include "RobotControler.h"
#include "../../oop_project/Project_Packet/FestoRobotAPI.h"
#include "TestRobotControler.h"
#include "TestPose.h"

// buras� uygulaman�n �al��aca�� konsol k�sm�
// burada �u anl�k testler �al��t�r�labilir. Daha sonra konsol uygulamas�
// yaz�lacak ve burada �a�r�lacak. A�a��da �rnek bir test �a�r�s� var.

int main() {

    
	TestPose testPose;
	testPose.runAllTests();
}
