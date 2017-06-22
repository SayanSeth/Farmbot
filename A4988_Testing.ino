int XstepPin = 2;
int YstepPin = 3;
int ZstepPin = 4;

int XDir = 5;
int YDir = 6;
int ZDir = 7;

int pulseWidthMicros = 500;
int StepsDelayMilli = 50;

int i = 0;
int Dir = 0;
int Step = 0;



void setup()
{
	pinMode(XstepPin, OUTPUT);
	pinMode(YstepPin, OUTPUT);
	pinMode(ZstepPin, OUTPUT); 

	pinMode(XDir, OUTPUT);
	pinMode(YDir, OUTPUT);
	pinMode(ZDir, OUTPUT);

	Serial.begin(9600);
	Serial.println("Testing Started!");



}


void loop()
{
	Serial.println("Input Command");
	String Buffer = "";
	Buffer = Serial.readString();
	Dir = Buffer.substring(1,2).toInt();
	Step = Buffer.substring(3).toInt();

	if (Buffer.startsWith("x"))
	{
		Xstep(Dir,Step);

	}
	else if (Buffer.startsWith("y"))
	{
		Ystep(Dir,Step);
	}
	else if(Buffer.startsWith("z"))
	{
		Zstep(Dir,Step);
	}

	else
	{
		Serial.println("Invalid Command");

	}
}

void Xstep(int Dir,int Step)
{
  if (Dir == 1)   
  digitalWrite(XDir, HIGH);
  else 
  digitalWrite(XDir, LOW);
  
	for (i=0 ; i < Step ; i++)
	{
		digitalWrite(XstepPin, HIGH);
        delayMicroseconds(pulseWidthMicros);
        digitalWrite(XstepPin, LOW);
        delayMicroseconds(pulseWidthMicros);

        delay(StepsDelayMilli);
	}

	Serial.println("X Axis");
  Serial.print ("\t");
  Serial.print("Steps = ");
  Serial.print(Step);
  Serial.print("\t");
  Serial.print("Direction = ");
  Serial.print(Dir);

}

void Ystep(int Dir,int Step)
{   
  if (Dir == 1)   
  digitalWrite(YDir, HIGH);
  else 
  digitalWrite(YDir, LOW);

	for (i=0 ; i < Step ; i++)
	{
		
	    digitalWrite(YstepPin, HIGH);
        delayMicroseconds(pulseWidthMicros);
        digitalWrite(XstepPin, LOW);
        delayMicroseconds(pulseWidthMicros);

        delay(StepsDelayMilli);
	}
  Serial.println("Y Axis");
  Serial.print ("\t");
  Serial.print("Steps = ");
  Serial.print(Step);
  Serial.print("\t");
  Serial.print("Direction = ");
  Serial.print(Dir);
}

void Zstep(int Dir,int Step)
{
  if (Dir == 1)   
	digitalWrite(ZDir, HIGH);
  else 
  digitalWrite(ZDir, LOW);

	for (i=0 ; i < Step ; i++)
	{
		
	    digitalWrite(ZstepPin, HIGH);
        delayMicroseconds(pulseWidthMicros);
        digitalWrite(ZstepPin, LOW);
        delayMicroseconds(pulseWidthMicros);

        delay(StepsDelayMilli);
	}
  Serial.println("Z Axis");
  Serial.print ("\t");
  Serial.print("Steps = ");
  Serial.print(Step);
  Serial.print("\t");
  Serial.print("Direction = ");
  Serial.print(Dir);
}