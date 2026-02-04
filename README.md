Keyboard configurations.

```
curl -L -o install.qmk.sh https://install.qmk.fm
bash ./install.qmk.sh --skip-package-manager --skip-uv
qmk setup --home ~/Development/keyboards/qmk_firmware
qmk config user.overlay_dir=$(realpath .)

qmk compile -c -kb preonic/rev3_drop -km radekw
qmk compile -c -kb bastardkb/charybdis/4x6/v2/splinky_3 -km radekw
qmk compile -c -kb bastardkb/charybdis/3x6/v2/splinky_3 -km radekw
qmk compile -c -kb bastardkb/dilemma/4x6_4 -km radekw
qmk compile -c -kb ploopyco/madromys -km radekw

qmk compile -c -kb sofle/rev1 -km radekw -e CONVERT_TO=kb2040
qmk compile -c -kb lily58/rev1 -km radekw
qmk compile -c -kb massdrop/ctrl -km radekw
```
