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

# Heatmap
```
./hid_listen | egrep --line-buffered "(0x[A-F0-9]+,)?(NA|[0-9]+),(NA|[0-9]+),[0-9]{1,2}" | tee -a keylog.csv

.\hid_listen.exe > keys.csv

.\hid_listen.exe | tee -a keys.csv

```


# Handwired
```

keyboards\handwired\6davkey\keymaps\default\keymap.c

qmk compile -kb handwired/6davkey -km default
```