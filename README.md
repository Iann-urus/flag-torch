# flag-torch
an arduino project to detect types of fires 
## Components
Arduino Mega
MQ-135
MQ-5
SHT3x
RGB Led

## Gases Detected
| Sensor | Gases |
| ----------- | ----------- |
| MQ-135 | Ammonia (NH3), nitrogen oxides (NOx), benzene, smoke, and CO2 |
| MQ-5 | LPG, Natural Gas, Coal Gas |

## Explanation
### How the sensors work
Each sensor has a heated piece of tin dioxide doped with other stuff, depending on the sonsor.
To detect the presence of a gas,the tin dioxide changes resistance as it reacts with the ambient gas.
The heating coil is used to increase the process of the chemical reaction. 

![image](https://github.com/Iann-urus/flag-torch/assets/67041860/36c81588-3a08-40b7-8475-51e341f849d6)

### MQ-135 & MQ-5

After getting the analog reading from the ADC we need to convert the 
According to the datasheet each gas has a distinct power function.

![image](https://github.com/Iann-urus/flag-torch/assets/67041860/43077666-6915-4626-a44f-1360fffdc962)
