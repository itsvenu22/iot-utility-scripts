// This code will send random data (0-21) via serial


void setup() 
{
    // Initialize Serial communication
    Serial.begin(115200); 

    // Seed the random generator
    randomSeed(analogRead(0)); 
}

void loop() 
{
    // Generate random number between 0 and 20
    int randomValue = random(0, 21); 
    
    // Send the random number via Serial
    Serial.println(randomValue);    
    
    // Send data every 500 ms
    delay(500);                     
}
