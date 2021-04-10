# My keymap for kinesis-advantage


## git to pull

```
git remote -v

git pull upstream master
git pull qmkupstream master


git push origin master
```


## QMK commands

```
qmk setup davmarksman/qmk_firmware -H "/c/Dev/Tools/KinT/qmk"
qmk compile -kb kinesis/kint2pp -km default
qmk config user.keyboard=kinesis/kint2pp
qmk config user.keymap=davmarksman
y
y


qmk json2c  "/c/Dev/Tools/KinT/qmk_firmware-kinesis-kint2pp-kinesis_kint2pp_layout_mine/qmk_firmware\kinesis_kint2pp_default.json"

/c/Dev/Tools/KinT/qmk/keyboards/kinesis/keymaps/davmarksman/keymap.c

python keymapviz "/c/Dev/Tools/KinT/qmk/keyboards/kinesis/keymaps/davmarksman/keymap.c"



```


# Handwired
```

keyboards\handwired\6davkey\keymaps\default\keymap.c

qmk compile -kb handwired/6davkey -km default
```