
# RETRO PIE GAMING CONSOLE

## **Project Idea**

In order to relive our childhood memories, we decided to design a personal-retro gaming console for our final semester project for ECE 4180: Embedded System Design. The motivation behind the design was the (seemingly) ease-of-use that the Raspbeerry Pi Model 3 B+ supports for hosting a nodes.js applications and a respective webserver. In order to build system that was portable and ergonomic for display as well as use, a 3D model was constructed to house the display, the pi, the battery pack, on board speakers, and miscellaneous electronics. 

![alt text](https://github.com/svia3/ECE4180-RetroPie-Gaming-Console/blob/master/images/IMG_20191206_002154.jpg)

## **SOFTWARE SETUP AND VERSION CONTROL**

As a disclaimer, our team had to switch from a Raspberry Pi Model 4 to a Raspberry Pi Model 3 B+ because the model 4 had newer versions of npm and node.js installed in /usr/local/bin that took way too long to downgrade and thus caused way too much of a hassle. Many tedious hours were spent trying to uninstall local copies of node and npm, reinstalling using a node version manager very similar to the process utilized during Lab 4. Further troubleshooting proved to be ineffective in ensuring that the dependenices for node were correct and in-line with those used for npm. 

## **Install RetroPie**

After that, we need to install the correct packages for RetroPie setup and run the .sh script:

    sudo apt-get install git lsb-release

Downloading the latest RetroPie setup script:

    cd
        git clone --depth=1 https://github.com/RetroPie/RetroPie-Setup.git

Executed by:

    cd RetroPie-Setup
        chmod +x retropie_setup.sh
        sudo ./retropie_setup.sh

### Install Virtual Gamepad (Must Be Run As Root!)
    
    su
    git clone https://github.com/miroof/node-virtual-gamepads
    cd node-virtual-gamepads
    npm install
    
    
### Enable Virtual Gamepad on Boot
    
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

The core components needed for RetroPie to function are:

- **RetroArch:** Frontend for the libretro api, necessary for most emulators to run.
- **EmulationStation:** Frontend for sorting and launching all of your games.
- **RetroPie Menu:** Menu in emulationstation for simpler configuration of your system.
- **Runcommand:** The runcommand launch menu that assists launching your games with proper configurations see related wiki page [HERE](https://github.com/RetroPie/RetroPie-Setup/wiki/runcommand).

### ROM Management

A ROM files are copied from read-only memory chips in famous retro catridge based games through a process known as *dumping*.   In order to copy over our favorite games, a secure socket connection was established in order to transfer popular arcade games using SCP commands to send files from local to a remote system. An example of the command executed is as follows:

    scp PACMAN.SMC pi@192.168.43.227:/home/pi/RetroPie/roms/snes
    
## Ardafruit Speaker Bonnet

In order to ensure that our speakers worked, we had to update the driver software on our board. In order to do this, various github curl requests were performed to ensure that our speakers were set up with the right calibration and right volume. Also, we had to adjust the pin assignment's on the RPI GPIO to ensure that they aligned with the pin assignment's in the speaker drivers config files. The curl request performed, once for installation, and once for testing:

    curl -sS https://raw.githubusercontent.com/adafruit/Raspberry-Pi-Installer-Scripts/master/i2samp.sh | bash

    
## Hardware Specs

Below is a list of the parts required:
- Adafruit I2S 3W Stereo Speaker Bonnet
- RPI Model 4 
- Ardafruit HDMI 7" 800x480 Display Backpack - With Touchscreen
- iOS device with WIFI connection

## Future Additions & Revisions

During the course of our project, we decided that we wanted to build an additional controller using a joystick and pushbuttons for manual controller, in case of server failure of simply low phone battery. The hardware used to design this controller is provided in the list below:
- **Thumb Slide Joystick-COM-09426-Sparkfun** (This is a joystick very similar to the 'analog' joysticks on PS2 (PlayStation 2) controllers. Directional movements are simply two potentiometers - one for each axis. Pots are ~10k each. This joystick also has a select button that is actuated when the joystick is pressed down.)
- **Basic Digital-In Switches**
- **mBed** for output scaling and bit manipulation for RPI GPIO ports


    
