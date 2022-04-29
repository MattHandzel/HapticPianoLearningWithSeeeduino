# HapticPianoLearningWithSeeeduino

Hello! This project is a passive haptic feedback learning device that teaches the user how to play piano. I started working on this after I saw this TedTalk -> (I wrote it after being inspired from this TedTalk: https://www.youtube.com/watch?v=HthrTEfSH9I) and wanted to try to make it on my own.

To summarize, this device will buzz vibration motors on your fingers (corresponding to what note should be played) in the proper order and timing for the user to play a basic melody of a song. This is a passive learning device, that means that this should be worn for extended periods of time and the brain should just learn the patter (watch the TedTalk--it explains this and is awesome).

# Technical details:
This device is basically a glove with a mount in the center for the electrical components, and then 8mm coin vibration motors on the fingers where each motor corresponsds to a different note that should be played. It is powered by a basic 9V battery, and I use the Seeediuno Xiao to run the code off of for its small form factor. 
This project is mostly done, if I revisit it, I will add the ability for the user to input a text file of a song they want to play (I think there are translations out there from songs to sheet music), more motors (1 on each finger, so more notes can be played), and better mount for the electronics. A fun challenege could be to make two of these devices, put one on each hand, and then figure out how to sync the two of them up.
