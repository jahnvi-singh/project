 /* HIGH/LOW GAME */<br />
#include<iostream.h><br />
#include<conio.h><br />
#include<stdlib.h><br />
/*<br />
This program plays a simple game.The computer picks a random number<br />
from<br />
0 to 100, and the user tries to guess the number.<br />
*/<br />
const int totchan=7;<br />
void main()<br />
{<br />
 int number;        //the computer’s random number<br />
 int guess;         //the user’s guess<br />
 int chances=0,score=0,chanscor;        //chanscor stores score for 1<br />
successful chance.<br />
 char ans;<br />
 do<br />
 { clrscr();<br />
   chances=score=0;<br />
   cout<<”<br />
				Welcome to the High/Low game.”;<br />
   cout<<”<br />
			I will pick a random number from 0 to 100.”;<br />
   cout<<”<br />
			    You must try to guess the number.<br />
“;<br />
   randomize();<br />
   number=(int)(rand()%100);<br />
   chanscor=100/totchan;        //score for each successful chance<br />
   do<br />
   {<br />
     cout<<”<br />
	What is your guess? (0 to 100) “;<br />
     cin>>guess;<br />
     if((guess<0)||(guess>100))<br />
     {<br />
	cout<<“Sorry, but your guess “<<guess<<“must be from 0 to 100.”;<br />
     }<br />
     else if(guess < number)<br />
     {<br />
	cout<<guess<<” is low.Try a higher number.”;<br />
     }<br />
     else if(guess > number)<br />
     {<br />
	cout<<guess<<” is high.Try a lower number.”;<br />
     }<br />
     else		//if correct number is guessed<br />
     {			//number is correct, and the “do” loop will end below<br />
	cout<<guess<<” is correct. Congratulations!”;<br />
	score=chanscor*(totchan-chances);   //score calculated for number of<br />
chances left<br />
	cout<<”<br />
	Your score is “<<score<<endl;<br />
        break;<br />
     }<br />
     chances++;<br />
     if(guess!=number)<br />
	 cout<<”</p>
<p>Now you have “<<totchan-chances<<“chances left.”<<endl;<br />
     if(chances==totchan)<br />
	 { cout<<”</p>
<p>Only “<<totchan<<“chances are allowed.Better luck next<br />
time”;<br />
	   cout<<”<br />
The actual number was “<<number<<endl;<br />
	   break;<br />
	 }<br />
     }while (guess!=number);<br />
     cout<<”</p>
<p>Thank you for playing High/Low!”;<br />
     cout<<“Want to play it again? (y/n)…”;<br />
     cin>>ans;<br />
   }while(ans==’y’ || ans==’Y’);<br />
 }
