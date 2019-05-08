
##READ ME##

###Coding Style###
- This project is following the QT coding style. (https://wiki.qt.io/Qt_Coding_Style)

###Config File###
- config.txt is the configuration file used in this project. Lack of config.txt would terminate the program.
	- These entries are mandatory
		- **background**: choose the background picture in the *images* folder you want to use. Just put the file name directly without images/, in this case, either *background.png* or *long.png*. Wrong file name would terminate the program.
		- **size**: choose size from *tiny*,*normal*,*large* and *giant*. Other input would terminate the program.
		- **xCoordinate**: enter a number between 0 and 600. Other input would terminate the program.
		- **velocity**: enter a number between 0 and 600. Other input would terminate the program.
	- These entries are optional (extensions)
		- **player**: choose the stickman picture in the *images* folder you want to use. Just put the file name directly without images/, in this case, either *man.png* ,*man1.png* or *man2.png*. Wrong file name would terminate the program.
		- **bgm**: choose the stickman picture in the *bgm* folder you want to use. Just put the file name directly without bgm/, in this case, either *bgm.mp3* or *bgm2.mp3*. Wrong file name would terminate the program.

###Extension###
- Allow user to modify their own stickman picture to use as stated above.
- Allow user to modify their own background music to play as stated above.
- Add stickman animation.
- Add pause button on the top right corner. Clicking on the button would pause the program, and reclick on the button would resume the program.

