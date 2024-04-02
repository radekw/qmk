```
mkdir -p ~/code
cd ~/code
git clone https://github.com/FrameworkComputer/qmk_firmware.git qmk_firmware_framework
cd qmk_firmware_framework
git switch fl16-v0.2.8-prep
cd keyboards/framework/ansi/keymaps
ln -s /home/radek/code/qmk/keyboards/framework/ansi/keymaps/radekw .
cd -

sudo qmk_hid --vid 32ac --pid 0012 via --bootloader
qmk compile -c -kb framework/ansi -km radekw
qmk flash -kb framework/ansi -km radekw
````
