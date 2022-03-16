# Passphoria — External Documentation
*A fun, user-friendly, console-based passphrase generator.*

## Overview
In today's digital age, it is becoming increasingly difficult to protect individual privacy and security. Given Moore's law and the exponential development of AI technology, hackers are equipped with a plethora of tools to compromise sensitive accounts and exploit the resultant data. If giant tech companies like Yahoo and eBay can be breached given a sufficiently motivated group of hackers, where does that leave us—the unassuming and fragile everyday internet user? 

It is hard to say for sure, but there are simple techniques that can be leveraged to safeguard your accounts. One such technique is the creation of a passphrase in lieu of a simple password. Whereas passwords tend to be short and easy to crack, passphrases are lengthy and robust. By combining randomly-selected words in a sequence that spans dozens of characters, you are able to significantly mitigate the risk that a bad actor will programatically guess your credentials.

That brings us to Passphoria—a free and intuitive passphrase generator that does more than create a passphrase. Far from your ordinary console application, Passphoria allows you to uniquely customize your user experience by configuring items like text colour and username. What's more, you are given free reign over how you would like to customize your passphrase, from capitalization to the number of languages involved. Think English is too layman? Then try Latin you esoteric savant! Want even more fun? Why not combine English, Latin, and German? Passphoria's limitless customizability—okay, maybe not limitless—coupled with its colourful and intuitive interface is what makes it one of the leading passphrase generators in the Westmount Tech Department (and soon the world). Some unnamed individuals even claim it may be the next Facebook—just without the data spying part.

## List of Enhancements
We know you're already frothing at the mouth, but since we're all about euphoria, we wanted to detail the full package of enhancements Passphoria has to offer.

* Beautiful external documentation (look at what you're reading!)
* *Mission: Impossible* background music (because it will be impossible for hackers to guess your passphrase)
* A dedicated console home screen so you feel welcome right from the get-go
* Ability to mix in multiple languages, including English, Latin, and German
* Vivid colouring so you don't feel bored staring at a console window—including the ability to change your input colour!
* Freedom to adjust the number of spaces between words
* Passphrase strength indicator for added confidence
* Ability to generate the passphrase in UPPERCASE or lowercase
* Bonus security involving special characters
* Passphrase confirmation (to make sure you won't forget!)

## Setup: How to Get Passphoria Up and Running
Passphoria is a lightweight program, so you should be able to get up and running in no time. Just follow the steps below:
1. Make sure you are using Windows OS, as Passphoria uses Windows-specific dependencies
2. Download the ZIP Passphoria-main.zip and save the inner Passphoria-main folder on your computer. It is critical that the names of the text files are preserved
3. Open up main.cpp in Code Blocks (highly recommended) or a similar IDE
4. Download soundtrack.wav from https://drive.google.com/file/d/10VE6oLD11TFzalsQyA7fxTCyIjE2Hfow/view?usp=sharing or use your own music. Note that it must be a WAV file and named soundtrack.wav
5. Save audio file in the same directory as main.cpp
6. In order for the music to play, go to Settings → Compiler... → Linker settings → Other linker options → -lwinmm → OK
7. Build and run

## What is your data policy? How do I know you're not storing my passphrases and using them for malicious purposes?
None of the passphrases we generate are stored in a database. Thus, as soon as you exit the program, you can rest assured that *only you* know your passphrase. Since Passphoria is an entirely offline service, this also prevents your passphrase from being leaked over the internet.

## Figma Mockups
Figma is a tool for designing and prototyping applicatons before they are coded. It was used to create mockups for Passphoria to streamline the development workflow. Check out the mockups here: https://www.figma.com/file/3mxGWYGiT8WY2MRms6F2pU/Passphoria-Mockups?node-id=0%3A1.

## Video Walkthrough
Here is a video specially made to walk you through Passphoria. It serves 3 objectives:
1. Demonstrate how to set up Passphoria on your local computer
2. What the program actually looks like
3. Showcase of Figma mockups

https://user-images.githubusercontent.com/52507573/158310964-1a3605d5-3ae0-4a20-a078-9fea1374490c.mp4
