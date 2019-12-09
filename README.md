
# RETRO PIE GAMING CONSOLE

## **Project Idea**

In order to relive our childhood memories, we decided to design a personal-retro gaming console for our final semester project for ECE 4180: Embedded System Design. The motivation behind the design was the ease-of-use that the Raspbeerry Pi Model 4 supports for hosting a nodes.js applications and a respective webserver. In order to build system that was portable and ergonomic for display as well as use, a 3D model was constructed to house the display, the pi, the battery pack, on board speakers, and miscellaneous electronics. 

![alt text](https://github.com/svia3/ECE4180-RetroPie-Gaming-Console/blob/master/images/IMG_20191206_002154.jpg)

## **SOFTWARE SETUP AND VERSION CONTROL**

As a disclaimer, our team used Raspberry Pi Model 4 which newer versions of npm and node.js installed in /usr/local/bin that required a downgarde. Many tedious hours were spent trying to uninstall local copies of node and npm, reinstalling using a node version manager very similar to the process utilized during Lab 4. Further troubleshooting proved to be effective in ensuring that the dependenices for node were correct and in-line with those used for npm and pm2.

## **Install RetroPie**

After that, we need to install the correct packages for RetroPie setup and run the .sh script:

    sudo apt-get install git lsb-release

Cloning github repository RetroPie specifically for Pi4:

    git clone --single-branch --branch fkms_rpi4 --depth=1 https://github.com/RetroPie/RetroPie-Setup.git
    cd ./RetroPie-Setup
    git fetch && git checkout fkms_rpi4

Linking dependencies and sources, manually building binaries:

    sudo ./retropie_packages.sh 833 depends
    sudo ./retropie_packages.sh 833 sources
    sudo ./retropie_packages.sh 833 build
    cd ./tmp/build/sdl2/
    sudo dpkg -i libsdl2-2.0-0_2.0.10*.deb

Execute:

    cd ../../..
    sudo ./retropie_setup.sh
    # go to basic install
    #setup autoboot to emulation station
    
The core components needed for RetroPie to function are:

- **RetroArch:** Frontend for the libretro api, necessary for most emulators to run.
- **EmulationStation:** Frontend for sorting and launching all of your games.
- **RetroPie Menu:** Menu in emulationstation for simpler configuration of your system.
- **Runcommand:** The runcommand launch menu that assists launching your games with proper configurations see related wiki page [HERE](https://github.com/RetroPie/RetroPie-Setup/wiki/runcommand).

### Install Virtual Gamepad (Must Be Run As Root!)
    
    su
    git clone https://github.com/miroof/node-virtual-gamepads
    cd node-virtual-gamepads
    npm install
    
    
### Enable Virtual Gamepad on Boot
***Disclaimer*** Node 5.8.0 and NPM v12.13.0 were used for this project. We cannot ensure that more updated versions of node or NPM will be compatible with our system, as this proved to be a problem during software installation.

    sudo npm install pm2 -g
    sudo pm2 start main.js
    sudo pm2 startup
    sudo pm2 save
    
### EmulationStation Controller Config:
  
  Adding this config file allows controller inputs from a browser display to be routed and linked emulationstation. 

      /opt/retropie/configs/all/retroarch-joypads/Virtualgamepad.cfg

      input_device = "Virtual gamepad"
      input_driver = "udev"
      input_r_btn = "5"
      input_save_state_btn = "5"
      input_start_btn = "7"
      input_exit_emulator_btn = "7"
      input_l_btn = "4"
      input_load_state_btn = "4"
      input_up_axis = "-1"
      input_a_btn = "0"
      input_b_btn = "1"
      input_reset_btn = "1"
      input_down_axis = "+1"
      input_right_axis = "+0"
      input_state_slot_increase_axis = "+0"
      input_x_btn = "2"
      input_menu_toggle_btn = "2"
      input_select_btn = "6"
      input_enable_hotkey_btn = "6"
      input_y_btn = "3"
      input_left_axis = "-0"
      input_state_slot_decrease_axis = "-0"
   
      ### **Core Packages**


### ROM Management

A ROM files are copied from read-only memory chips in famous retro catridge based games through a process known as *dumping*.   In order to copy over our favorite games, a secure socket connection was established in order to transfer popular arcade games using SCP commands to send files from local to a remote system. An example of the command executed is as follows:

    scp PACMAN.SMC pi@192.168.43.227:/home/pi/RetroPie/roms/snes
    
## Ardafruit Speaker Bonnet

In order to ensure that our speakers worked, we had to update the driver software on our board. In order to do this, various github curl requests were performed to ensure that our speakers were set up with the right calibration and right volume. Also, we had to adjust the pin assignment's on the RPI GPIO to ensure that they aligned with the pin assignment's in the speaker drivers config files. The curl request performed, once for installation, and once for testing:

    curl -sS https://raw.githubusercontent.com/adafruit/Raspberry-Pi-Installer-Scripts/master/i2samp.sh | bash

    
## Hardware Specs

Below is a list of the parts required:
- [Adafruit I2S 3W Stereo Speaker Bonnet](https://www.adafruit.com/product/3346?gclid=CjwKCAiAlajvBRB_EiwA4vAqiHQcNQkVz3aT_HM0JRcWzLdMDHznrnivz6ugUeZ69-h08Wrbsb3G6RoCYK0QAvD_BwE)
- [RPI Model 4](digikey.com/en/product-highlight/r/raspberry-pi/raspberry-pi-4-model-b?utm_adgroup=xGeneral&utm_term=&slid=&gclid=CjwKCAiAlajvBRB_EiwA4vAqiIZCv4XYz5jgaRusfV0OuZFOaj20aDCZJcriM3BMQJ0u7XkVlLBV_BoC7o4QAvD_BwE&utm_campaign=Dynamic+Search&utm_medium=cpc&utm_source=google)
- [Ardafruit HDMI 7" 800x480 Display Backpack - With Touchscreen](https://www.adafruit.com/product/2407?gclid=CjwKCAiAlajvBRB_EiwA4vAqiEwhR-1Wpg9jJ27-zChQ5AqEUgX4d99syMU-0qYxdd4fccZBwSj3axoCqP4QAvD_BwE)
- iOS device with WIFI connection

## Block Diagram

![alt text](https://github.com/svia3/ECE4180-RetroPie-Gaming-Console/blob/master/images/4180%2Bblock%2Bdiagram.png)
 
 ## Video Demo
 
 https://www.youtube.com/watch?v=HwX_u9vSdPw


## Future Additions & Revisions

During the course of our project, we decided that we wanted to build an additional controller using a joystick and pushbuttons for manual controller, in case of server failure of simply low phone battery. The hardware used to design this controller is provided in the list below:
- **Thumb Slide Joystick-COM-09426-Sparkfun** (This is a joystick very similar to the 'analog' joysticks on PS2 (PlayStation 2) controllers. Directional movements are simply two potentiometers - one for each axis. Pots are ~10k each. This joystick also has a select button that is actuated when the joystick is pressed down.)
- **Basic Digital-In Switches**
- **mBed** for output scaling and bit manipulation for RPI GPIO ports

 ## On-Board Controller
 
 In order to make our gaming system more robust, we decided to design and create a physical on-board controller that uses analong inputs from a pushbutton joystick. We used an mBED as a simple analog to digital converter on a breadboard, feeding forward the two inputs from our joystick, HORZ and VERT as digital outputs UP, DOWN, LEFT, and RIGHT. We also included push buttons for the 'A', 'B', 'Start', and 'Select Buttons.' This design had a few bugs that required further testing and trouble shooting before it would be ready for deployment. RetroPie supports multiple on-board controllers for 2-player games, and we wanted to challenge are selves to take the virtual controller offline in the case that phone battery may be low or there is no internet connection. Below is a picture of the controller:
 

![alt text](https://github.com/svia3/ECE4180-RetroPie-Gaming-Console/blob/master/images/IMG_20191206_002904.jpg)

Because the RPI does not accept analog inputs, converting to digital inputs on the GPIO ports used to following pin assignments for button inputs and joystick values (code included in ad_converter.cpp file):

![alt text](https://github.com/svia3/ECE4180-RetroPie-Gaming-Console/blob/master/images/rpGPIO.png)



   
