# MediCheck
An Arduino based mini-project on Tinkercad

MediCheck is a smart monitoring and logging system that operates in a hospital environment. There are multiple independent modules that have been integrated into a single embedded system, where the master module logs the activities that are done by the slave modules for regulatory information for a patient. This allows a medical professional to better monitor a patient’s health and provide more appropriate care. The heartrate sensor is simulated. The slave modules that are connected are as follows:
•	Temperature and Heartrate Sensor
•	Hand sanitizer dispenser
•	Pill Dispenser
Temperature and Heartrate Sensor:
This module monitors the heartrate and body temperature of a patient each second, and will log it to the master module. This will help the medical staff to detect any anomalies or abnormal behaviour.
Hand sanitizer dispenser:
This module dispenses hand sanitizer based on ultraviolet sensor (proximity sensor HC-SR04). This detects motion up to a range of 15cm, to which it dispenses an appropriate amount of sanitizer.
Pill Dispenser:
This module works on a clock (RTC module), in which we set a time for the alarm to ring and the pill to dispense. This data is logged by the master module for regulatory purposes.
