
byte FreqPin0 = 3;//46
unsigned long PrintTimer;

const byte FreqSamples = 20;
unsigned int Frequency;

unsigned long TimeDelta0 = 0;
boolean Freq0Ready = false;
unsigned int Frequency0 = 0;

// Lookup table Freq to Flow rate from WIS T7 and 3.0L Diesel MAFs
int LU_Freq[] = {200, 1045, 1312, 1527, 2012, 2355, 2788, 3134, 3678, 4095, 4764, 5289, 5730, 6114, 6753, 7286, 7743, 8158};
float LU_Flow[] = {0, 1, 1.5, 2, 3.5, 5, 7.5, 10, 15, 20, 30, 40, 50, 60, 80, 100, 120, 140};

void setup()
{
  pinMode(FreqPin0, INPUT_PULLUP);
  attachInterrupt(digitalPinToInterrupt(FreqPin0), FreqCounter0, FALLING);

  Serial.begin(230400);
}



void loop()

{



  if (millis() - PrintTimer > 10) {
    Freq0Ready = false;
    FreqEval(TimeDelta0);
    float FlowRate = (6.8646E-15)*pow(Frequency,4)+(1.5286E-10)*pow(Frequency,3)+(3.5219E-7)*pow(Frequency,2)+(4.0284E-4)*Frequency-0.0521; // 0 g/s being 200 Hz

//// Linear interpolation from the table in WIS  
//    float FlowRate=0;   
//    for (byte i = 0; i < 18; i++) { 
//      if (Frequency < LU_Freq[0]) {
//        break;
//      }
//      if (Frequency > LU_Freq[i] && Frequency <= LU_Freq[i + 1]) {
//        FlowRate = LU_Flow[i+1] * (Frequency /((float)LU_Freq[i]+(float)LU_Freq[i+1]));
//        break;
//      }
//    }

    Serial.print("Flowrate: ");
    Serial.print(FlowRate);
    Serial.println(" g/s");
    
    PrintTimer = millis();

  }

}

  void FreqCounter0() {
    static volatile byte i = 0;
    static volatile unsigned long StartFreq = 0;

    if (i < FreqSamples ) {
      if (i == 0) {
        StartFreq = micros();
      }
      i++; // increment index
    }
    else {
      TimeDelta0 = micros() - StartFreq; // Record time of pulse
      //     detachInterrupt(digitalPinToInterrupt(FreqPin0));
      i = 0;
      Freq0Ready = true;
    }
  }



  void FreqEval(unsigned long TimeDelta) {

    Frequency = (FreqSamples) * 1e6 / (TimeDelta);

  }

