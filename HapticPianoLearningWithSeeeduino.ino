/*
This is the code for my haptic glove learning project.
I wrote it after being inspired from this TedTalk: https://www.youtube.com/watch?v=HthrTEfSH9I


*/

// This is so that i can type print instead of Serial.print and be lazy
#define print Serial.print

/*
Create a motor class, it will have a pin for where it outputs as well as a note, the purpose of the note
is so that, potentially, I can just input the notes from a song (like the sheet music), and then it would use
those notes to translate it into the fingers that need to be pressed.
*/
class Motor
{
public:
  int pin;
  char note;

  Motor(int pin, char note)
  {
    this->pin = pin;
  }

  // Sets the power to the inputted power (these are on the SEEDIUINO's analog pins (:D))
  void setPower(double power)
  {
    analogWrite(this->pin, (int)(power * 255));
  }
};

/*
This is the class that holds the data about the song, it is pretty creudly made, where the randomSong (i think its a justin bieber song) is written
into the array randomSong. This code kinda sucks tbh, I wrote it like 6 months ago.
This project was meant to be expanded on, more motors, more fingers, and a better way of inputting songs. I made this in my 'piano' phase, when I
wanted to learn how to play piano and was excited about how good I could get passively.
*/
class Pattern
{
public:
  Motor index = Motor(3, 'C');
  Motor middle = Motor(1, 'D');
  Motor ring = Motor(2, 'E');
  const float timeSlowDown = 2;
  Motor *fingers[5];
  double rest[2] = {-1, 0.25};
  double randomSong[40][2] = {{0, 0.125}, {1, 0.125}, {2, 0.125}, {2, 0.16666}, {2, 0.16666}, {2, 0.16666}, {2, 0.16666}, {2, 0.16666}, {2, 0.16666}, {1, 0.25}, {0, 0.125}, {1, 0.125}, {-1, 0.125}, {0, 0.125}, {1, 0.125}, {2, 0.125}, {2, 0.16666}, {2, 0.16666}, {2, 0.16666}, {2, 0.16666}, {2, 0.16666}, {2, 0.16666}, {1, 0.25}, {0, 0.125}, {1, 0.125}, {-1, 0.125}, {0, 0.125}, {1, 0.125}, {2, 0.125}, {2, 0.375}, {1, 0.125}, {0, 0.25}, {-1, 0.25}, {0, 0.125}, {0, 0.125}, {0, 0.125}, {0, 0.125}, {0, 0.166666666}, {1, 0.166666666}, {2, 0.166666666}};

  double motorPower = 1.0;

  Pattern()
  {
    this->fingers[0] = &this->index;
    this->fingers[1] = &this->middle;
    this->fingers[2] = &this->ring;
  }

  // This function will play the song, it will also output the note that should as well as for how long it should be played for in the Serial monitor for debugging
  void play()
  {

    for (int i = 0; i < 41; i++)
    {
      print(i);
      print(" , ");
      print((int)randomSong[i][0]);
      Serial.println(" , " + String(randomSong[i][1]));
      if (randomSong[i][0] == -1)
      {
        delay(randomSong[i][1] * 1920 * this->timeSlowDown);
      }
      else
      {
        this->fingers[(int)randomSong[i][0]]->setPower(this->motorPower);

        delay(randomSong[i][1] * 1920 * 0.75 * this->timeSlowDown);
        this->fingers[(int)randomSong[i][0]]->setPower(0);
        delay(randomSong[i][1] * 1920 * 0.25 * this->timeSlowDown);
      }
    }
  }

  // This function is for debugging, it makes each motor run indiviaully, then all together to check to see if my soldering
  // went well (I soldered these very poorly)
  void checkIfMotorsWorkingWell()
  {
    this->fingers[0]->setPower(this->motorPower);
    delay(1000);
    this->fingers[0]->setPower(0);
    this->fingers[1]->setPower(this->motorPower);
    delay(1000);
    this->fingers[1]->setPower(0);
    this->fingers[2]->setPower(this->motorPower);
    delay(1000);
    this->fingers[2]->setPower(0);
    delay(1000);
    this->fingers[0]->setPower(this->motorPower);
    this->fingers[1]->setPower(this->motorPower);
    this->fingers[2]->setPower(this->motorPower);
    delay(2000);
    this->fingers[0]->setPower(0);
    this->fingers[1]->setPower(0);
    this->fingers[2]->setPower(0);
    delay(2000);
  }

  // Again, this function was to be used in a bigger way to convert from character the the note is played, to what the finger represents
  int notesToNumbers(char c)
  {
    switch (c)
    {
    case 'A':
      return 0;
    case 'B':
      return 1;
    case 'C':
      return 2;
    }
  }
};

Pattern pattern = Pattern();
void setup()
{
  // put your setup code here, to run once:
  SerialUSB.begin(9600);

  // Set the pins that we're going to be used to output mode (this could have been made in the motor class)
  pinMode(1, OUTPUT); // index
  pinMode(2, OUTPUT); // middle
  pinMode(3, OUTPUT); // ring
}

void loop()
{
  // put your main code here, to run repeatedly:
  pattern.play();

  // between song runs, wait 5 seconds
  delay(5000);
}
