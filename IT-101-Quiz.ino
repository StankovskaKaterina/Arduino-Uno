#include <LiquidCrystal.h>
// initialize the library with the numbers of the interface pins

LiquidCrystal lcd(12, 11, 5, 4, 3, 2);
boolean buttonLeft;
boolean buttonRight;

String topQuestions[] = {"1011 XOR 0110 =", "1 Kilobyte =", "Is monitor an", "Is keyboard an", "Does 1 byte =", 
                          "0011 XOR 1110 =", "java source file", " Is lcd an", "Excel Workbook", " Is 1 MB =",
                          "111 in binary", " decade 6 is", "Linux is an", "10 in binary"};

String bottomQuestions[] = {"= 1101 ", "= 1024 Bytes ?", "output device ?", "output device ?", "10 bits ?",
                            "= 1101", "extension = .c", "input device ?", "extension=.xlsx", "1000 bytes? ",
                            " is 7 in decade", "001 in binary", "operating system", "is 4 in decade"};
int totalQuestions = 14;
int NumQuestions = 0;
int answers[] = {1, 1, 1, 0, 0, 1, 0, 0, 1, 0,1, 0, 1, 0};    //1 is correct - 0 is wrong
int score = 0;


void setup() {
Serial.begin(9600);
pinMode(7, INPUT);   //setting the left pushbutton
pinMode(13, INPUT);  //setting the right pushbutton
lcd.begin(16, 2);
lcd.setCursor(0, 0);

  lcd.print("WELCOME TO THE");
  lcd.setCursor(0, 1);
  lcd.print("QUIZ: IT-101");
    delay(800);
    lcd.clear();
    lcd.setCursor(0, 0);
    lcd.print("LET'S BEGIN ...");
    delay(800);
    lcd.clear();
}


void correctAnswer()
{                                   //Function for correct answers
    lcd.clear();
    lcd.setCursor(0, 0);
    lcd.print("CORRECT!");
    delay(200);
    lcd.clear();
}

void wrongAnswer()
{                                      //Function for Wrong answers
    lcd.clear();
    lcd.setCursor(0, 0);
    lcd.print("WRONG!");
    delay(200);
    lcd.clear();
}


void showScore()                        //Score on screen
{
    lcd.clear();
    lcd.setCursor(0, 0);
    lcd.print("Thanks 4 playing");
    lcd.setCursor(0, 1);
    lcd.print("Your score:");
    lcd.setCursor(13, 1);
    lcd.print(score);
    delay(1200);
    if (score < 5)                      //LED according to score
    { 
        lcd.clear();
        lcd.setCursor(0, 0);
        lcd.print("You failed :(");
        lcd.setCursor(0, 1);
        lcd.print("Grade: 5");
    }
    else if (score == 5 || score==6)
    {   lcd.clear();
        lcd.setCursor(0, 0);
        lcd.print("You passed!");
        lcd.setCursor(0, 1);
        lcd.print("Grade: 6");
        
    }
    else if (score == 7 || score==8)
    {   lcd.clear();
        lcd.setCursor(0, 0);
        lcd.print("You passed!");
        lcd.setCursor(0, 1);
        lcd.print("Grade: 7");
    }
    else if (score == 9 || score==10)
    {   lcd.clear();
        lcd.setCursor(0, 0);
        lcd.print("You passed!");
        lcd.setCursor(0, 1);
        lcd.print("Grade: 8");
    }
    else if (score == 11 || score==12)
    {   lcd.clear();
        lcd.setCursor(0, 0);
        lcd.print("You passed!");
        lcd.setCursor(0, 1);
        lcd.print("Grade: 9");
    }
    else if (score == 13 || score==14)
    {   lcd.clear();
        lcd.setCursor(0, 0);
        lcd.print("You passed!");
        lcd.setCursor(0, 1);
        lcd.print("Grade: 10");
    }
    delay(30000);                       //end of game
}


  
void loop()
{
    buttonLeft = digitalRead(7);         //False button
    buttonRight = digitalRead(13);       //True button

    if (NumQuestions != totalQuestions)
    {
        lcd.setCursor(0, 0);                        //display question
        lcd.print(topQuestions[NumQuestions]);
        lcd.setCursor(0, 1);                        //display possible answer
        lcd.print(bottomQuestions[NumQuestions]);

        if (buttonRight == HIGH)                     //if True button is clicked
        {
            if ((answers[NumQuestions]) == 1)       
            {
                correctAnswer();
                NumQuestions++;
                score++;
                //Serial.print(score);
                //Serial.println(NumQuestions);
            }
            else if ((answers[NumQuestions]) == 0)
            {
                wrongAnswer();
                NumQuestions++;
            }
        }
        if (buttonLeft == HIGH)                     //if False button is clicked
        {
            if ((answers[NumQuestions]) == 0)
            {
                correctAnswer();
                NumQuestions++;
                score++;
                //Serial.print(score);
                //Serial.println(NumQuestions);
            }
            else if ((answers[NumQuestions]) == 1)
            {
                wrongAnswer();
                NumQuestions++;
            }
        }
    }
    if (NumQuestions == totalQuestions)   // once all questions are answered
    {
        showScore();
    }
}