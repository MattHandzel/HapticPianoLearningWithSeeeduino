# HapticPianoLearningWithSeeeduino!
Hello! This project is a passive haptic feedback learning device that teaches the user how to play piano. I started working on this after I saw this TedTalk -> (https://www.youtube.com/watch?v=HthrTEfSH9I) and wanted to try to make it on my own.

![IMG_20220501_205139751 SMALLER](https://user-images.githubusercontent.com/39449480/167306824-9e0eb8b8-a6ac-4c09-a959-de996d16b12e.png)

To summarize, this device will buzz vibration motors on your fingers (corresponding to what note should be played) in the proper order and timing for the user to play a basic melody of a song. This is a passive learning device, that means that this should be worn for extended periods of time and the brain should just learn the patter (watch the TedTalk--it explains this and is awesome).

# Technical details:
This device is basically a glove with a mount in the center for the electrical components, and then 8mm coin vibration motors on the fingers where each motor corresponds to a different note that should be played. It is powered by a stanard 9V battery, and uses the Seeediuno Xiao to control the motors. I chose the Xiao because of its small form factor and large memory/storage (also it uses USB-C to program 🥳). 
![image](https://user-images.githubusercontent.com/39449480/167306271-f867d360-72f3-4cf4-a2ed-e61fc8929eda.png)

This project is mostly done; if I revisit it, I will add the ability for the user to input a text file of a song they want to play (I think there are translations out there from songs to sheet music), more motors (1 on each finger, so more notes can be played), and better mount for the electronics. A fun challenege could be to make two of these devices, put one on each hand, and then figure out how to sync the two of them up.
