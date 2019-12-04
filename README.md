
# RETRO PIE GAMING CONSOLE

## PROJECT IDEA

In order to relive our childhood memories, we decided to design a personal-retro gaming console for our final semester project for ECE 4180: Embedded System Design. The motivation behind the design was the (seemingly) ease-of-use that the Raspbeerry Pi Model 3 B+ supports for hosting a nodes.js applications and a respective webserver. In order to build system that was portable and ergonomic for display as well as use, a 3D model was constructed to house the display, the pi, the battery pack, on board speakers, and miscellaneous electronics. 

## **SOFTWARE SETUP AND VERSION CONTROL**

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
   
## **Install RetroPie**

After that, we install the needed packages for the RetroPie setup script:

    sudo apt-get install git lsb-release

Then we download the latest RetroPie setup script with

    cd
        git clone --depth=1 https://github.com/RetroPie/RetroPie-Setup.git

The script is executed with

    cd RetroPie-Setup
        chmod +x retropie_setup.sh
        sudo ./retropie_setup.sh
      
 
