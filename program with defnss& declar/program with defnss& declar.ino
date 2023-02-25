void setup() {
 
// Declare inputs and ouputs LDR,LED,IR sensor 
// Declare all variables
}

void loop() {

    switch(state)
          {
          case 1: IDLE1
          // Go to PLACE_BOTTLE when IR sensor LOW for more than 2 hours
          IR_Sensor_Value = Read_IR_Sensor(); // Returns 
          if (IR_Sensor_Value == LOW && IR_Sensor_Count >= 72000)
          {
            state = PLACE_BOTTLE;
          }
          // Go to CLEAN_BOTTLE when IR  sensor ON for more than 8 hours
          IR_Sensor_Value = Read_IR_Sensor(); // Returns 
          if (IR_Sensor_Value == ON && IR_Sensor_Count >= 480000)
          {
            state = CLEAN_BOTTLE;
          }
          // Go to DRINK when IR sensor ON for 2 hours
          IR_Sensor_Value = Read_IR_Sensor(); // Returns 
          if (IR_Sensor_Value == LOW && IR_Sensor_Count >= 72000)
          {
            state = DRINK;
          }
          // Go to DND when LDR is LOW
          LDR_Sensor_Value = Read_LDR_Sensor(); // Returns LOW/HIGH
          if (LDR_Sensor_Value == LOW)
          {
            state = DND;          
          }
           // From DND to IDLE when LDR is HIGH
            LDR_Sensor_Value = Read_LDR_Sensor(); // Returns HIGH
          if (LDR_Sensor_Value == HIGH)
          {
            state = ACTIVE;          
          }
          
----------------------------------------------------------------------------------------------------------------
          case 2:PLACE_BOTTLE
          PLACE_BOTTLE_LED = HIGH
          delay =2000;
          state = IDLE1; 
          
      
----------------------------------------------------------------------------------------------------------------
          case 3:DND
           //buzzer,LED=OFF
        
----------------------------------------------------------------------------------------------------------------
          case 4:DRINK_WATER
         //buzzer,LED=ON

          case 5:CLEAN_BOTTLE .
         //buzzer,LED=ON
       }

  }

            void Read_LDR()
            {
              digitalRead()
            }