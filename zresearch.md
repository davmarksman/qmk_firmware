# Finally decided to take the plunge and move of qwerty

Possible options:

-   Dvorak
-   RTSHD
-   Colemax
-   Custom

Tasks:
[] Start logging keys
[] Research layouts

Input scope analysis:

-   Bkspace
-   Shift
-   Space
-   E

# General

-   Thinking should move = to a more ergonomic place? It and minus require a finger spray motion but typing them seem to has a high accuracy
-   Esc position? Check frequency, corner equals position or thumb key?
-   Also when coding (), {}, and [] auto complete. So maybe try mapping sdf to those and above them to their close. Will free up 2 keys on main
-   Opposing thumb layers feels like it would be better.

# Open questions/Design considerations

1. Want control key mod on home row Middle finger postion
2. Programming focused
3. Thumb E? - too much thumb wor
4. Digraph th? - don't do th enough
5. Right pinky A needs to be a less infrequently used key. While home row it is more strain on my pinky

# Layouts

### Dvorak

Pros:

-   Kinesis has labels for this
-   ., is in a great position
-   with thumb key e mod, home row ctrl is in perfect position
-   F and L positons are not ideal
-   Alternating hands

Cons:

-   A is left pinky. Can swap with E
-   ; is in an horrible positions on the left hand.
-   Moves alot of keys (harder to learn)

http://xahlee.info/kbd/keyboard_dvorak_layout.html  
http://xahlee.info/kbd/dvorak_vs_colemak.html

Users: Xahlee

### Coleman DHm Mod & Miryoku

Pros:

-   Not important for me: Copy paste designed to be in same place but don't really use those keys but balanced by their position is fine on my weakest fingers
-   Rolling
-   popular in ergo world

Cons:

-   Semicolon finger movement is not ideal painful (qwerty P)
-   Other letters that I think are cumbersome with Colemak are the letters G, L, and O. I believe that by moving these letters, horizontal and diagonal stretching could be made less and the load on the right pinky could be reduced.
-   A is left pinky.

Recommendations:

-   swap A with E postion. E thumb
-   swap A and R

https://colemak.com/
https://colemakmods.github.io/mod-dh/  
http://xahlee.info/kbd/dvorak_vs_colemak.html  
https://github.com/manna-harbour/qmk_firmware/blob/miryoku/users/manna-harbour_miryoku/miryoku.org#numerals-and-symbols-nsl

Users: Precondition

### Norman

-   Very few keys move
-   ASD with thumb key E mod
-   A is unchanged on weak pinky
-   Semicolon finger movement is not ideal painful (qwerty P)

http://normanlayout.info/about

### RTHSD

-   Thumb E built in

### Beakl

http://thedarnedestthing.com/beakl%20wi

### Hands down layout

https://sites.google.com/alanreiser.com/handsdown

# The experiment

Decided to try handsdown alt-e and colemak dhm

Colemax:

-   Popular
-   good ,./ position. semicolon is not ideal but we can work with it
-   left pinky with A is doing a bit too much work for my liking but that is its only key

Handsdown Alt-E: not well tested but looks like it might be better for my requirements. Being designed with thumb E, home row mods, and reduced pinky in mind.

decided not dovorak as semicolon position is not ideal
decided not breakl as thumb key reduction was too much from person tried it out feedback

Will try both and see which I prefer. Goal is to get to 20wpm with each and then see how it goes.
There is diminishing returns so either of the two selected will be good.

# New ideas

On L2 have [({ just the first bit on the home row

Also maybe a coding mode where symbols and numbers are inverted

# Top keys seem to be:

```
Bk/Ctrl
Space
E
Shift
T
O
I
S
A
N
R
D
L
```

For symbols:  
I thought @ would be higher...

```
.
-
,
nos 1/2
=
"
(
/
{
X
Q
Esc + nos
;
[
+
J
_
)
:
...
Z
```

# Hands down heatmap

-   Looking at the heatmap
-   Should have shift on second thumb rather than first
-   Maybe e in the map as thumbs doing alot of work.
-   Work seems more towards Backspace
-   Defo move L. Swap with K.

# Colemak heatmap

-   Seems balanced across both hands
-   L postion is not so idea. Swap with H.

# Comparing heatmaps

E defo the elephant in the room
L is a large use key for me not accounted for in optimisers. Maybe from Lothea? ctrl L? let? class?
Both look good. Think it will come down to do I like index corners free for symbols and can handle load on thumb e
Defo need to move that backspace postion. Looking at the stats its in a horrible positon

# difficulty matrix / effort grid

https://workmanlayout.org/#back-to-the-drawing-board  
https://colemakmods.github.io/mod-dh/compare.html  
https://deskthority.net/wiki/BEAKL#Effort_Grid  
https://stevep99.github.io/keyboard-effort-grid/

# 12/5/21

So decided to go for the Alt N mod

-   F is on right hand. Good for Ctrl-F
-   Swapped L and H. TH is top bigram, CL is a common bigram (GL also but lower). Getting around the TH problem by mapping TL&TH combo to TH, and TD combo to the (d get it?)
-   N on thumb is used a lot but E is 150-200% of N so ok.
-   Will have - on right index bottom right. Gets used alot: Notes, code, trello and that is a nice spot for my hands to reach.
-   As mentioned before bkspace and shift swapped
-   Also between 2 keys may be nicer chord

Really happy with layout. Think will be a pleasure to type

-   Swap UK
-   rotate right home row one to the right.

# 15/5/21

layout implemented. the s is giving me a pain in the ass tho and the h is fine but does play well with rolls

# 16/5/21

thinking changes

-   D on home row then RS back in orginal position on pinky. Tried for a bit but doesn't gel well and worried about left pinky use

-   Swap F and H so f on home row. plays more nicely with ctrl f, but think will map home row fore finger to ctrl f
-   swap CL <> GM - as top has lower effor than bottom, and use cl more than gm

Liking this layout

# Top keys

See also

-   https://gist.github.com/lydell/c439049abac2c9226e53
-   http://norvig.com/mayzner.html

```
Bk    - 8670
Space   - 6459
E          - 4012
T          - 3100
I          - 2758
O          - 2721
Shift      - 2719
N          - 2461
A          - 2446
S          - 2407
R          - 2396
Enter      - 2352
D_Mod      - 1907
L          - 1802

---

C          - 1232           I-N             - 742
M          - 1092           E-Space         - 715
H          - 1025           T-Space         - 621
U          - 1014           Space-T         - 544
F/F_Mod    - 987            E-R             - 506
P          - 962            R-E             - 457
L1         - 765            S-Space         - 447
G          - 746            O-N             - 428
B          - 734            O-R             - 392
K_Mod      - 640            R-Space         - 371
.          - 632            N-Space         - 358
                            S-T             - 353
                            A-N             - 352
---                         T-I             - 351
                            T-H             - 334
                            T-E             - 328
Y          - 569            E-S             - 317
Tab        - 517            I-T             - 315
W          - 499            L-I             - 307
V          - 478            E-N             - 303
                            N-T             - 300
---                         C-O             - 299

Right      - 303            I-O-N  - 157
-          - 290            I-N-G  - 141
0          - 276            F-O-R  - 139
,          - 274            T-H-E  - 130
1          - 232            E-N-T  - 129
=          - 191            A-N-D  - 102
/          - 189            ??L-I-N           - 121
OSM(SYM)   - 186
X          - 178            V-A-R
2          - 169            broker
J_Mod      - 166            david
;          - 153
(          - 143
Q          - 139
Left       - 135
{          - 112
"          - 112
Del        - 100

---

[          - 94
'          - 93
Alt/Esc    - 91
Ctrl-S     - 85
5          - 84
F10        - 82
3          - 77
4          - 70
)          - 69
:          - 67
Ctrl-F     - 64
Win        - 63
7          - 63
_          - 63
Down       - 59
Media      - 55
8          - 52
]          - 50
+          - 46
Snip       - 44
6          - 44
AHK        - 43
>          - 36
*          - 35
Up         - 34
Z          - 34
9          - 33
Clipboard  - 30
}          - 28
@          - 25
$          - 25
!          - 22
#          - 22
<          - 22
\          - 21
Ctrl-J     - 21
Ctrl-L     - 19
£          - 17
Ctrl-A     - 14
%          - 12
Ctrl-N     - 12
xLT(Nav)   - 10
&          - 10
F12        - 10
Ctrl-/     - 9
Undo Tab   - 8
`          - 8
F2         - 8
Global     - 7
Ctrl-Enter - 7
&&         - 6
Ctrl-O     - 6
F4         - 6
|          - 5
||         - 4
```

# Updated frequencies

```
Bk/Ctrl    - 11334 - 15.233%
Bk         - 11271 - 15.148%
Space/L1   - 7124 - 9.575%
Space      - 6323 - 8.498%
E          - 4314 - 5.798%
S          - 3453 - 4.641%
T          - 3386 - 4.551%
Shift      - 3333 - 4.48%
O          - 3151 - 4.235%
A          - 2948 - 3.962%
I          - 2926 - 3.933%
Enter      - 2752 - 3.699%
N          - 2582 - 3.47%
R          - 2177 - 2.926%
L          - 1983 - 2.665%
D/Ctrl     - 1940 - 2.607%
D          - 1898 - 2.551%


C          - 1488 - 2%
M          - 1370 - 1.841%
P          - 1230 - 1.653%
U          - 1174 - 1.578%
H          - 1132 - 1.521%
F          - 1059 - 1.423%
B          - 910 - 1.223%
K          - 845 - 1.136%
G          - 840 - 1.129%


L1         - 796 - 1.07%
.          - 731 - 0.982%
K/Ctrl     - 676 - 0.909%
Tab        - 667 - 0.896%
W          - 659 - 0.886%
N/SYM      - 658 - 0.884%
Y          - 656 - 0.882%
V          - 565 - 0.759%
S/Ctrl     - 542 - 0.728%
Right      - 441 - 0.593%
0          - 438 - 0.589%
Ctrl       - 382 - 0.513%
-          - 361 - 0.485%
1          - 283 - 0.38%
,          - 275 - 0.37%
Enter/SYM  - 261 - 0.351%
SYM        - 250 - 0.336%
=          - 245 - 0.329%
;          - 245 - 0.329%
2          - 234 - 0.314%
Left       - 213 - 0.286%
X          - 209 - 0.281%
Down       - 183 - 0.246%
Up         - 177 - 0.238%
(          - 173 - 0.233%
J/Shift    - 159 - 0.214%
/          - 159 - 0.214%
5          - 158 - 0.212%
Q          - 148 - 0.199%
Del        - 135 - 0.181%
J          - 128 - 0.172%
{          - 125 - 0.168%
Ctrl-S     - 123 - 0.165%
Blank      - 119 - 0.16%
"          - 112 - 0.151%
3          - 107 - 0.144%
'          - 104 - 0.14%
Win        - 103 - 0.138%
Alt/Esc    - 101 - 0.136%
:          - 98 - 0.132%
4          - 96 - 0.129%
OSM(SYM)   - 88 - 0.118%
)          - 86 - 0.116%
F10        - 82 - 0.11%
#          - 81 - 0.109%
7          - 76 - 0.102%
Ctrl-F     - 75 - 0.101%
_          - 73 - 0.098%
Esc        - 70 - 0.094%
AHK        - 69 - 0.093%
*          - 68 - 0.091%
8          - 67 - 0.09%
Tab/Alt    - 66 - 0.089%
6          - 63 - 0.085%
9          - 60 - 0.081%
+          - 59 - 0.079%
Z          - 57 - 0.077%
Unknown Custom - 57 - 0.077%
Snip       - 56 - 0.075%
Del/Ctrl   - 45 - 0.06%
@          - 45 - 0.06%
[          - 44 - 0.059%
>          - 43 - 0.058%
Clipboard  - 41 - 0.055%
Ctrl-Right - 36 - 0.048%
\          - 34 - 0.046%
!          - 34 - 0.046%
?          - 34 - 0.046%
Ctrl-J/Shift - 32 - 0.043%
```

# Kimiko only frequencies 2/6/21

````
Bk/Ctrl    - 8629 - 18.595%
Bk         - 8629 - 18.595%
Space/L1   - 3822 - 8.236%
Space      - 3537 - 7.622%
E          - 3008 - 6.482%
T          - 2257 - 4.864%
N/SYM      - 2151 - 4.635%
R          - 1964 - 4.232%
R/Ctrl     - 1943 - 4.187%
O          - 1895 - 4.084%
S          - 1817 - 3.915%
A          - 1764 - 3.801%
N          - 1721 - 3.709%
Shift      - 1664 - 3.586%
I          - 1622 - 3.495%
L          - 1368 - 2.948%
Enter      - 1197 - 2.579%
U          - 1159 - 2.498%
D          - 1073 - 2.312%
M          - 944 - 2.034%
C          - 811 - 1.748%
P          - 691 - 1.489%
F          - 676 - 1.457%
B          - 597 - 1.286%
H          - 524 - 1.129%
K          - 522 - 1.125%
SYM        - 481 - 1.037%
G          - 474 - 1.021%
W          - 433 - 0.933%
V          - 425 - 0.916%
Y          - 389 - 0.838%
Down       - 387 - 0.834%
Right      - 348 - 0.75%
Tab        - 346 - 0.746%
.          - 318 - 0.685%
L1         - 285 - 0.614%
;          - 264 - 0.569%
-          - 219 - 0.472%
Up         - 209 - 0.45%
Tab/SYM    - 186 - 0.401%
Left       - 164 - 0.353%
/          - 117 - 0.252%
J          - 117 - 0.252%
0          - 117 - 0.252%
,          - 104 - 0.224%
1          - 102 - 0.22%
Tab/Alt    - 94 - 0.203%
NxtApp     - 93 - 0.2%
=          - 91 - 0.196%
X          - 90 - 0.194%
Esc        - 85 - 0.183%
2          - 75 - 0.162%
Z          - 71 - 0.153%
Del        - 71 - 0.153%
Win        - 59 - 0.127%
5          - 50 - 0.108%
"          - 48 - 0.103%
(          - 48 - 0.103%
3          - 45 - 0.097%
Alt(2nd)   - 44 - 0.095%
'          - 43 - 0.093%
#          - 41 - 0.088%
9          - 39 - 0.084%
_          - 38 - 0.082%
4          - 30 - 0.065%
AHK        - 29 - 0.062%
)          - 29 - 0.062%
*          - 28 - 0.06%
+          - 28 - 0.06%
Blank      - 28 - 0.06%
XXX-0x002C - 27 - 0.058%
XXX-0x00E0 - 25 - 0.054%
6          - 23 - 0.05%
{          - 23 - 0.05%
7          - 21 - 0.045%
Global     - 20 - 0.043%
!          - 19 - 0.041%
\          - 18 - 0.039%
8          - 17 - 0.037%
?          - 16 - 0.034%
<          - 16 - 0.034%
Del/Ctrl   - 15 - 0.032%
End        - 14 - 0.03%
```        - 14 - 0.03%
[          - 13 - 0.028%
Q          - 13 - 0.028%
XXX-0x00E6 - 12 - 0.026%
|          - 12 - 0.026%
>          - 11 - 0.024%
Clipboard  - 10 - 0.022%
`          - 10 - 0.022%
:          - 9 - 0.019%
&&         - 9 - 0.019%
XXX-Shft-0x00E0 - 9 - 0.019%
Snip       - 8 - 0.017%
XXX-0x6116 - 7 - 0.015%
XXX-0x0450 - 7 - 0.015%
XXX-Shft-0x6116 - 6 - 0.013%
£          - 6 - 0.013%
@          - 6 - 0.013%
x => x     - 6 - 0.013%
Home       - 6 - 0.013%
Undo Tab   - 5 - 0.011%
&          - 5 - 0.011%
F2         - 5 - 0.011%
````

# Combined 02/06/21

```
Keycode	        Perc
Bk		        - 15.801%
Space	        	- 8.765%
E		        - 6.200%
T		        - 4.766%
O		        - 4.202%
Shift	        	- 4.117%
S		        - 4.116%
I		        - 3.924%
A		        - 3.872%
N		        - 3.685%
R		        - 3.644%
Enter	        	- 3.328%
L		        - 2.817%
D		        - 2.622%
C		        - 1.896%
U		        - 1.891%
M		        - 1.865%
P		        - 1.553%
F		        - 1.478%
H		        - 1.422%
B		        - 1.222%
G		        - 1.108%
K		        - 1.090%
L1		        - 0.963%
.		        - 0.888%
Y		        - 0.872%
W		        - 0.868%
Tab		        - 0.819%
V		        - 0.809%
Right	        	- 0.607%
Ctrl	        	- 0.513%
Dash	        	- 0.471%
0		        - 0.425%
Down	        	- 0.391%
;		        - 0.380%
Com		        - 0.342%
1		        - 0.322%
Left	        	- 0.284%
=		        - 0.275%
/		        - 0.255%
X		        - 0.252%
2		        - 0.247%
Up		        - 0.247%
J		        - 0.229%
OSM(SYM)        		- 0.206%
(		        - 0.187%
Ctrl+S	        	- 0.165%
Del		        - 0.164%
5		        - 0.151%
Q		        - 0.149%
Tab/Alt	        	- 0.146%
Quot	        	- 0.143%
Alt/Esc	        	- 0.140%
Esc		        - 0.139%
Ctrl-S	        	- 0.134%
{		        - 0.131%
F10 	        	- 0.129%
Win		        - 0.121%
3		        - 0.121%
4		        - 0.101%
Ctrl-F 	        	- 0.101%
)		        - 0.096%
Alt		        - 0.095%
Z		        - 0.095%
_		        - 0.093%
'		        - 0.093%
Media	        	- 0.087%
:		        - 0.086%
7		        - 0.082%
]		        - 0.079%
[		        - 0.078%
#		        - 0.077%
AHK		        - 0.074%
9		        - 0.072%
+		        - 0.070%
8		        - 0.070%
Star	        	- 0.069%
6		        - 0.068%
Snip	        	- 0.054%
}		        - 0.044%
Clipboard       - 0.041%
!		        - 0.041%
>		        - 0.040%
$		        - 0.039%
\		        - 0.039%
@		        - 0.037%
<		        - 0.034%
Ctrl-J 	        - 0.033%
Ctrl-L 	        	- 0.030%
Ctrl-A 	        - 0.022%
£		        - 0.020%
%		        - 0.019%
Ctrl-N 	        - 0.019%
`		        - 0.017%
|		        - 0.017%
xLT(Nav)        - 0.016%
F12 	        - 0.016%
&&		        - 0.014%
Ctrl-/ 	        - 0.014%
&		        - 0.013%
Undo Tab        - 0.013%
F2		        - 0.012%
Global 	        - 0.011%
Ctrl-Enter      - 0.011%
Ctrl-O 	        - 0.009%
F4		        - 0.009%
||		        - 0.006%

```

# Hands down

## Original alt-nx

```
1  2  3  4  5  6  7  8  9  0  q
w  g  m  f  =  '  k  u  j  z  [  ]
r  s  t  h  b  y  i  e  o  a  ;
x  c  l  d  v  -  p  /  ,  .  n
```

## Original alt

```
w c h f v   / y u q j
r s n t g   k i e o a
x m l d b   z p ' , .
```

# Layout testing

Tried my layout here.

-   TH bigram not great but way around with th/the combos.
-   ow/wo other bigram not great. But occurence is sufficently lOW
-   left index has high utilisation > 20%. But my f vs h usuage is neligable (think ctrl+f is to blame=10%)

http://colemakmods.github.io/mod-dh/analyze.html

```
1  2  3  4  5  6  7  8  9  0  q
j  c  l  h  =  -  k  u  w  z  [  ]
f  r  s  t  b  y  i  e  o  a  '
x  g  m  d  v  ;  p  ,  .  /  n
```

```
effort: 4
4.0 3.3 2.8 2.8 3.6 3.6 2.8 2.8 3.3 4.0  4.7 3.9
5.0 2.4 2.0 2.2 3.2 3.2 2.2 2.0 2.4 3.0  4.4 4.4
3.4 1.3 1.1 1.0 2.9 2.9 1.0 1.1 1.3 1.6  3.4
5.2 2.6 2.3 1.6 3.0 3.0 1.6 2.3 2.6 3.2  1.0
penalties:
 2.5  3.0  4.0  #same-finger
 0.5  1.0  1.5  #pinky-ring
 0.1  0.2  0.3  #ring-middle
-0.2 -0.1  0.0  #middle-index
fingers: 4
1 1 2 3 3 6 6 7 8 8 9 8
0 1 2 3 3 6 6 7 8 9 3 6
0 1 2 3 3 6 6 7 8 9 9
0 1 2 3 3 6 6 7 8 9 5
type:
matrix
```

## Finger distribution with my layout:

```
Finger 0 - 2.28%
Finger 1 - 7.21%
Finger 2 - 8.46%
Finger 3 - 8.81%

Finger 5 - 7.45%
Finger 6 - 7.96%
Finger 7 - 6.46%
Finger 8 - 4.88%

Finger 11 - 17.73%
Finger 12 - 16.94%
```

# Effort Matrix

-   Penalise left pinky
-   Top ring and middle better
-   Top index RU and index bottom right is hard on kimiko but ok on kinesis

# Options:

-   'H' position is fine but feel should be better
-   Thinking swapping h with y or w as on kimiko index stretch doesn't feel comfortable
-   wsad arrow keys position feels more natural. or can try on ijkl. requires swapping symbol and nav triggers to other hands.
-   alt ex has 'p' in position i like, where 'h' currently is
-   left index has high utilisation > 20%. But my 'f' vs 'h' usuage is neligable (think ctrl+f is to blame=10%)

### Pinky dilema:

-   swapping 'g' and 'f' might be worth doing. As with ing combo would not use 'g' as frequently and its already lower than 'f'. B1jiion;ei6piiiiiiiiieeeei889wkwfffff1jbrings almost on par with g.
-   also nice to have: f has a homing key that makes it ideal to find home. popping j on i so get that homing too.
-   Only way to reduce right pink would be to swap 'f' and 'w'. Plus 'for' combo to negate sfb.
-   From my data fo gram ok as long as have for combo. For was 139/163 fo grams

### 'L' Dilema

-   Don't like P position. Think it's recieved such a nice position considering its usuage.
-   'L' position is not ideal as use 'L' alot. I would also argue reverse. On kinesis it almost same as 'p' and only slightly worse on kimiko

Swapping l and p gives problems with li bigram. V. Common in my dataset  
Same-Finger Bigrams  
finger 7 LI 0.557%  
finger 7 IL 0.433%  
th is like 3%

## Proposal

updated would look like:

```
1  2  3  4  5  6  7  8  9  0  q
j  c  f  h  =  -  k  u  p  z  [  ]
w  r  s  t  b  y  i  e  o  a  '
x  g  m  d  v  ;  l  ,  .  /  n
```

'w', 'f', 'l', 'p' change.  
Finger distribution with my layout:

```
Finger 0 - 1.54%
Finger 1 - 7.21%
Finger 2 - 7.35%
Finger 3 - 8.81%

Finger 5 - 8.47%
Finger 6 - 7.96%
Finger 7 - 7.29%
Finger 8 - 4.88%

Finger 11 - 17.73%
Finger 12 - 16.94%
```

## Proposal Pink

Accepted this proposal

```
1  2  3  4  5  6  7  8  9  0  q
j  c  l  f  =  -  k  u  h  z  [  ]
w  r  s  t  b  y  i  e  o  a  '
x  g  m  d  v  ;  p  ,  .  /  n
```

'w', 'f', 'h', change.

Finger distribution with my layout:

```
Finger 0 - 1.54%
Finger 1 - 7.21%
Finger 2 - 8.46%
Finger 3 - 8.81%

Finger 5 - 7.45%
Finger 6 - 7.96%
Finger 7 - 7.2%
Finger 8 - 4.88%

Finger 11 - 17.73%
Finger 12 - 16.94%
```

# Realised that my map actually creates some character clashes with home row left

looked to fix like this but stats bad
's' doesn't play as well with 'l' or 'm'. Same for 'r' col.

```
1  2  3  4  5  6  7  8  9  0  q
j  l  c  g  =  -  k  u  f  z  [  ]
w  r  s  t  b  y  i  e  o  a  '
x  h  m  d  v  ;  p  ,  .  /  n
```

# Programming

Base

```
.          - 581 - 1.137%
,          - 239 - 0.468%
-          - 223 - 0.437%
=          - 199 - 0.39%
;          - 115 - 0.225%
/          - 113 - 0.221%
:          - 88 - 0.172%
'          - 75 - 0.147%
>          - 39 - 0.076%
@          - 39 - 0.076%
?          - 24 - 0.047%
<          - 24 - 0.047%
%          - 19 - 0.037%
\          - 18 - 0.035%
£          - 12 - 0.023%
```

Programming

```
(          - 148 - 0.29%
{          - 117 - 0.229%
"          - 89 - 0.174%
)          - 70 - 0.137%
_          - 53 - 0.104%
+          - 45 - 0.088%
[          - 42 - 0.082%
*          - 38 - 0.074%
}          - 20 - 0.039%
!          - 18 - 0.035%
&          - 17 - 0.033%
$          - 16 - 0.031%
|          - 11 - 0.022%
```

Editing

```
#          - 34 - 0.067%
`          - 19 - 0.037%
```

# 23/5/21

Accepted change

```
1  2  3  4  5  6  7  8  9  0  q
j  c  l  f  =  -  k  u  h  z  [  ]
w  r  s  t  g  y  i  e  o  a  '
x  b  m  d  v  ;  p  ,  .  /  n
```

-   'w', 'f', 'h', change - fix issue of left pinky overwork by replacing with lower freq 'w'. Also read 'h' gels better as a const on the vowel hand.
-   'g' and 'b' change - not really nessary - optional change as use both the same frequency. Keeps 'g' in qwerty pos, but b on qwerty finger. On kimiko index pos is slightly easier. kinesis other way
-   'r' 's' change - Been hard to learn new 's' and 'r' pos. This return 's' to qwerty pos. Slight stats improvement
-   Jay-Z change - move 'j' and 'z' to original hands. No stat change.

# 29/5/21

-   Feel 'C-S-B' finger not gelling on b. Having big row jumps e.g BaCk

# On combos.

-   Seem way to go.
    https://www.reddit.com/r/ErgoMechKeyboards/comments/ifrd24/my_36_key_layout_with_only_2_layers_and_lots_of/
    https://www.jonashietala.se/blog/2021/06/03/the-t-34-keyboard-layout/

So from it:

-   Vertical combos - Less missfire
-   Combos more comfortable

I don't think combo type really matters. Find thumb plus letter good (and, ent), and horizontal/ vertical combos work well.

Also interesting one here where () where on base layer:
So trying {} combo. See how that workes out

```
(-A             - 124 - 0.075%
A-(             - 72 - 0.043%
A-)             - 40 - 0.024%
A-Space-(       - 39 - 0.024%
{-Enter-A       - 29 - 0.018%
(-Shift-A       - 28 - 0.017%
)-A             - 27 - 0.016%
)-Space-A
```

where A is a letter.
So most brackets are followed with a letter. Not same for braces which is normally followed by enter

# On Visual studio

Normally type 2 letters, pause to see what comes up, then tab/enter to select, type more or Nav+arrs

# 6/7/21

```
LPinky          - 1873 - 1.377%
LRing           - 12303 - 9.042%
LMid            - 13320 - 9.789%
LIndex          - 15981 - 11.745%
RIndex          - 12525 - 9.205%
RMid            - 13110 - 9.635%
RRing           - 10322 - 7.586%
RPinky          - 6387 - 4.694%
LThumb          - 25127 - 18.467%
RThumb          - 25118 - 18.46%
```

Thumbs have a very high usage: 18.5%. Twice as most fingers. Pinky usage is good

updated key frequencies

```
Bk         - 19042 - 13.945%
Bk/SYM     - 19013 - 13.924%
Space/L1   - 15108 - 11.064%
Space      - 14303 - 10.475%
E          - 8633 - 6.322%
R/Ctrl     - 6494 - 4.756%
S          - 5871 - 4.3%
O          - 5822 - 4.264%
A          - 5775 - 4.229%
T          - 5624 - 4.119%
R          - 5264 - 3.855%
I          - 4940 - 3.618%
Shift      - 4692 - 3.436%
N          - 4311 - 3.157%
Enter      - 4118 - 3.016%
L          - 3490 - 2.556%
C          - 3297 - 2.415%
D          - 2730 - 1.999%
U          - 2498 - 1.829%
M          - 2485 - 1.82%
P          - 2008 - 1.471%
H          - 1676 - 1.227%
W          - 1521 - 1.114%
B          - 1498 - 1.097%
Y          - 1424 - 1.043%
th bi(est) - 1400 = 1100 + 300 (bigrams)
Ctrl       - 1392 - 1.019%
h alone(est)- 1376 = 1676 - 300 (bigrams)
F          - 1343 - 0.984%
Bk/Ctrl    - 1199 - 0.878%
G          - 1179 - 0.863%
K          - 1176 - 0.861%
N/SYM      - 1175 - 0.861%
.          - 981 - 0.718%
V          - 939 - 0.688%
SYM        - 922 - 0.675%
L1         - 792 - 0.58%
Down       - 770 - 0.564%
Tab        - 685 - 0.502%
Right      - 632 - 0.463%
Ctrl-S     - 601 - 0.44%
THE        - 594 - 0.435%
Left       - 576 - 0.422%
;          - 546 - 0.4%
TH         - 508 - 0.372%
ING        - 474 - 0.347%
-          - 468 - 0.343%
Ctrl-Bk/SYM - 384 - 0.281%n
,          - 373 - 0.273%
Up         - 346 - 0.253%
0          - 307 - 0.225%
FOR        - 301 - 0.22%
X          - 276 - 0.202%
Media      - 270 - 0.198%
1          - 263 - 0.193%
/          - 240 - 0.176%
'          - 234 - 0.171%
AND        - 221 - 0.162%
2          - 217 - 0.159%
Del        - 204 - 0.149%
Alt/Esc    - 202 - 0.148%
(          - 197 - 0.144%
AHK        - 194 - 0.142%
Ctrl-Left  - 181 - 0.133%
Ctrl-Right - 171 - 0.125%
J          - 168 - 0.123%
ION        - 164 - 0.12%
)          - 158 - 0.116%
"          - 145 - 0.106%
BRO        - 136 - 0.1%
3          - 129 - 0.094%
=          - 127 - 0.093%
ENT        - 117 - 0.086%
Blank      - 111 - 0.081%
XXX-Comb-IN/SYM - 104 - 0.076%
XXX-0x012A - 99 - 0.073%
QU         - 94 - 0.069%
5          - 90 - 0.066%
4          - 78 - 0.057%
?          - 77 - 0.056%
YOU        - 77 - 0.056%
F2         - 76 - 0.056%
Clipboard  - 76 - 0.056%
9          - 72 - 0.053%
Q          - 71 - 0.052%
XXX-Comb-IE - 71 - 0.052%
XXX-Comb-FL - 68 - 0.05%
Z          - 67 - 0.049%
_          - 64 - 0.047%
XXX-Comb-ON/SYM - 63 - 0.046%
End        - 57 - 0.042%
{          - 52 - 0.038%
*          - 52 - 0.038%
BL         - 52 - 0.038%
Undo Tab   - 51 - 0.037%
6          - 47 - 0.034%
#          - 44 - 0.032%
Win        - 43 - 0.031%
Alt        - 43 - 0.031%
XXX-Comb-FI - 42 - 0.031%
XXX-Comb-IP - 42 - 0.031%
7          - 40 - 0.029%
Ctrl-B     - 39 - 0.029%
XXX-Comb-DN/SYM - 38 - 0.028%
XXX-0x1300 - 38 - 0.028%
XXX-Comb-IO - 38 - 0.028%
F12        - 36 - 0.026%
Ctrl-T     - 35 - 0.026%
F10        - 33 - 0.024%
Ctrl-O     - 32 - 0.023%
!          - 32 - 0.023%
8          - 32 - 0.023%
Ctrl-Down  - 31 - 0.023%
x => x     - 31 - 0.023%
```

## Errors

looks like L, C, b, M

```
Bk-E            - 466 - 0.341%
Bk-R            - 423 - 0.31%
Bk-Enter        - 414 - 0.303%
Bk-T            - 385 - 0.282%
Bk-S            - 342 - 0.25%
Bk-L            - 332 - 0.243%
Bk-Ctrl         - 329 - 0.241%
Bk-I            - 316 - 0.231%
Bk-C            - 311 - 0.228%
Bk-A            - 298 - 0.218%
Bk-B            - 276 - 0.202%
Bk-D            - 239 - 0.175%
Bk-M            - 236 - 0.173%
B-Bk            - 232 - 0.17%
Bk-O            - 227 - 0.166%
Bk-.            - 216 - 0.158%
Bk-W            - 206 - 0.151%
Bk-N            - 202 - 0.148%
```

## 12/07/21 Investigating layout

-   'C', 'L', 'B', 'M' get confused constantly
-   Can swap 'W' & 'B'
-   'G' & 'T' Can get confused. So is 'F' with 'T' for historic reasons
-   'IK' is bad
-   do't have good inward rolls
-   'LD' combo?

tcis
tcat
tce
witc
tc

## Hands down gold.

Might be worth a try. Modifications
Swap 'R' and 'C'

```
j  kz m  fq v   ?! ,; /| "# '@
r  s  n  h  p   .: a  e  i  c
x  g  l  d  b   -+ u  o  y  w
            t   ␣
```

```
   j  kz m  fq v   -+    c  w '@
   h  s  t  r  p   y  i  e  o  a
q  x  g  l  d  b   ?! u  ,;  .:  /?
                   ␣  n
```

```
   z  k  m  fq v   ?! ,; /| "#  j
   h  s  t  r  p   y  a  e  i  c  '@
q  x  g  l  d  b   -+ u  o  .: w
                   ␣  n
```

```
   z  k  m  fq th  v  -  ,;  k  j
   h  s  t  r  p   y  a  e  i  c '@
q  x  g  l  d  b   =  u  o .: /?
                   ␣  n
```

th - 1000

-              - 567 - 0.348%

```
1  2  3  4  5  6  7  8  9  0  q
j  c  l  f  ({ )} k  u  h  z
w  r  s  t  g  y  i  e  o  a  '
x  b  m  d  v  -=  p  ,  .  /  n
```

```
1  2  3  4  5  6  7  8  9  0  q
z  b  l  f  th -  k  o  p  j
h  s  r  t  w  y  a  e  i  c
x  g  m  d  v  =  u  ,  .  /
                   ␣  n
```

## Pairs

Interesting 'Th' is actually not that frequent. 'ER', 'RE' and 'IN'. But its getting its own key (others are all on home row)

```
E-__            - 2321 - 1.251%
T-__            - 1800 - 0.97%
S-__            - 1764 - 0.951%
R-E             - 1678 - 0.905%
__-Shift        - 1617 - 0.872%
E-R             - 1544 - 0.832%
I-N             - 1391 - 0.75%
__-A            - 1350 - 0.728%
__-T            - 1246 - 0.672%
T-H  (est)      - 1200 - 0.62%
__-C            - 1070 - 0.577%
T-O             - 1051 - 0.567%
O-__            - 1044 - 0.563%
A-N             - 1021 - 0.55%
E-S             - 1009 - 0.544%
__-I            - 990 - 0.534%
N-__            - 978 - 0.527%
T-E             - 967 - 0.521%
D-__            - 947 - 0.51%
E-Bk            - 943 - 0.508%
__-S            - 924 - 0.498%
S-T             - 904 - 0.487%
A-T             - 883 - 0.476%
E-N             - 882 - 0.475%
O-N             - 859 - 0.463%
O-U             - 831 - 0.448%
R-__            - 819 - 0.441%
__-O            - 819 - 0.441%
Y-__            - 795 - 0.429%
A-L             - 790 - 0.426%
I-T             - 788 - 0.425%
O-R             - 779 - 0.42%
C-O             - 750 - 0.404%
S-E             - 739 - 0.398%
A-R             - 701 - 0.378%
L-E             - 694 - 0.374%
R-O             - 677 - 0.365%
N-T             - 676 - 0.364%
__-W            - 674 - 0.363%
N-E             - 629 - 0.339%
A-Bk            - 622 - 0.335%
O-Bk            - 618 - 0.333%
E-D             - 617 - 0.333%
__-P            - 615 - 0.332%
L-I             - 615 - 0.332%
M-E             - 614 - 0.331%
Bk-E            - 613 - 0.33%
O-M             - 598 - 0.322%
C-H             - 586 - 0.316%
__-B            - 583 - 0.314%
I-S             - 582 - 0.314%
T-Bk            - 574 - 0.309%
T-A             - 563 - 0.303%
__-D            - 560 - 0.302%
Bk-R            - 552 - 0.298%
ING-__          - 547 - 0.295%
__-M            - 543 - 0.293%
M-A             - 541 - 0.292%
E-A             - 541 - 0.292%
U-S             - 536 - 0.289%
Shift-I         - 535 - 0.288%
C-E             - 529 - 0.285%
R-Bk            - 526 - 0.284%
H-A             - 524 - 0.282%
--__            - 520 - 0.28%
S-Bk            - 519 - 0.28%
L-__            - 513 - 0.277%
V-E             - 505 - 0.272%
I-Bk            - 501 - 0.27%
Bk-T            - 495 - 0.267%
N-D             - 491 - 0.265%
A-S             - 481 - 0.259%
U-R             - 477 - 0.257%
__-R            - 477 - 0.257%
P-R             - 475 - 0.256%
.-__            - 469 - 0.253%
A-__            - 466 - 0.251%
R-A             - 465 - 0.251%
A-C             - 462 - 0.249%
D-E             - 460 - 0.248%
R-S             - 454 - 0.245%
__-THE          - 451 - 0.243%
K-E             - 445 - 0.24%
C-A             - 443 - 0.239%
Shift-C         - 442 - 0.238%
E-T             - 437 - 0.236%
L-L             - 436 - 0.235%
U-T             - 435 - 0.234%
__-F            - 434 - 0.234%
L-O             - 431 - 0.232%
E-C             - 430 - 0.232%
S-O             - 429 - 0.231%
E-E             - 420 - 0.226%
__-L            - 418 - 0.225%
```

## 18/7/2021 On 'OU'

Thinking swapping 'OU' so 'O' on index (qwerty 'M'). Looked good until discovered how frequent 'OU' bigram is. And top index is definitely better position for that. Maybe 'O' on bottom index

```
O-A             - 47 - 0.025%
A-O             - 3 - 0.002%
A-U             - 102 - 0.055%
U-A             - 60 - 0.032%


Y-O-U           - 188 - 0.101%
O-U             - 831 - 0.448%
I-O             - 105 - 0.057


U-E             - 74 - 0.04%
E-U             - 22 - 0.012%
```

-   qu should not be on vowel hand. Almost always followed by a vowel. Tried consonants hand but didn't work (bl roll too OP)
-   'h' and 'w' swap places. As 'sh' 'wh' freq bigrams. Can swap. Decide 'w' retain org position as
    -   consonant rolls horrible with 'h'. e.g 'sh' 'gh' 'th'.
    -   'w' is more leading and normally swap hands
-   Thinking 'AO' on index. And adaptive , key so ou is a roll. But screws 'po' roll and index will be doing alot of work.
-   Can make cp adaptive key for 'ch'

## 21/7/21

-   Thought about swapping 'h' and 'th'. Decided no. Effort matrix for th still high. (see https://colemakmods.github.io/mod-dh/model.html)
-   Instead will still keep 'the' combo - so th key only used 1/2 as much
-   Can swap th and v with good results

```
f - 1343
th - 1400 = 1100 + 300 (bigrams)
H  - 1376 = 1676 - 300 (bigrams)
v - 939
```

-   Don't like th postion. Also srt is not as great
-

## 27/7/21

Well hands down has a new update. Sigh.

-   I'm unhappy with the 'th' key. Don't like 'th' combo. I think 'th'

Proposals

-   remove 'th' key. 'Th' is not ideal as that is now through a combo
-   (gold) - right pinky as 'h' instead of 'c'. But 'bsc' on ring was previously error prone
-   can also swap thumb 'n' with 't' but I think that 'n' works better as I have 'ion' 'and' 'ing' combos that eliminate o

-   r on right pinky. Radical design but right pinky is strong enough. Only problem is breaks swapping hands. would solve 'r' 's' confusion

```
z  b  l  f  =  -  k  o  p  j
h  s  t  d  w  y  a  e  i  r
x  g  m  c  v  ;  u  ,  .  /
            ␣  n
```

t,g,s + d = x+h
w tends to be leading

```
z  b  l  f  =  -  k  o  p  j
w  s  t  d  h  y  a  e  i  r
x  g  m  c  v  ;  u  ,  .  /
            ␣  n
```

cm = cl

c pos is horrible for ch

```
z  b  l  f  =  -  k  o  p  j
w  s  t  d  g  y  a  e  i  r
x  c  m  h  v  ;  u  ,  .  /
            ␣  n
```

gh horrible

### Original looks best with 'th' combo.

```
z  b  l  f  =  -  k  o  p  j
w  s  r  t  h  y  a  e  i  c
x  g  m  d  v  ;  u  ,  .  /
            ␣  n
```

can swap c and h. but index will be doing so much.

alt-h

```
z  b  l  f  h   -  k  o  p  j
w  s  r  t  th  y  a  e  i  c
x  g  m  d  v   ;  u  ,  .  /
            ␣   n
```

can map g-th to ght
and

alt-gh. requires s adaptive key for sh

```
z  b  l  f  g   -  k  o  p  j
w  s  r  t  th  y  a  e  i  c
x  h  m  d  v   ;  u  ,  .  /
            ␣   n
```

now:
w - 1809
h - 1831 = 3427 - 1596
th - 1596
g - 1482 = 2294 - 812
k - 1314

kimko:
h - 548 = 747 - 199
th -199
g - 484 = 576 - 92
k - 475

qwerty:
h - 747 = 1212 - 465
th- 465
g - 618 = 839 - 221
k - 870(more k's as k was mod)

'g' and 'k' roughly same so 'k' position is fine
'h' significantly more than

```
z  b  l  f  g   -  k  o  p  j
h  s  r  t  th  y  a  e  i  c
x  w  m  d  v   ;  u  ,  .  /
            ␣   n
```

dont like h at end. no nice const grams so shouldn't isolate ('ht')

```
z  b  l  f  g   -  k  o  p  j
th s  r  t  h  y  a  e  i  c
x  w  m  d  v   ;  u  ,  .  /
            ␣   n
```

reduces load on right pink. But effectively same as 'th' 'g' swap

```
z  b  l  f  th -  k  o  p  j
w  s  r  t  g  y  a  e  i  c
x  h  m  d  v   ;  u  ,  .  /
            ␣   n
```

sh bad combo,

revist r

```
z  b  l  f  =  -  k  o  p  j
h  s  t  dh w  y  a  e  i  r
x  g  m  c  v  ;  u  ,  .  /
            ␣  n
```

This produced alot of pinballing with r. And performed less well on analyses

Beakl preformed really well in the analysers
https://deskthority.net/wiki/BEAKL#BEAKL_15

```
z  b  l  f  =  -  k  o  p  j
h  s  r  t  g  y  a  e  i  c
x  w  m  d  v  ;  u  ,  .  /
            ␣  n
```

```
z  b  l  f  =  -  k  o  y  j
p  s  r  t  g  y  a  e  i  h
x  w  m  d  v  ;  u  ,  .  /
            ␣  n
```

## 29/7/21 - Gold mod vs Hands down gold mirror

### Gold mod

- Nice Th combo
- Less Off mouse: Consonants more likely to start a word (http://www.norvig.com/mayzner.html)
- Really nice one hand ctrl combos (d, s, t)

### Hands down gold mirror

- rolls better
- fits my usage pattern better


### Index bigrams
'AK' bigram issue: Make 'AK' combo 

```
I-P             - 71 - 0.038%
P-I             - 70 - 0.038%

O-E             - 57 - 0.031%
E-O             - 63 - 0.034%

A-U             - 102 - 0.055%
U-A             - 60 - 0.032%

A-Y             - 191 - 0.103%
Y-A             - 11 - 0.006%

A-K             - 137 - 0.074%
U-K             - 37 - 0.02%
K-A             - 18 - 0.01%
C-K             - 192 - 0.103%
```

```
K-E             - 445 - 0.24%
K-__            - 303 - 0.163%
K-I             - 73 - 0.039%
I-K             - 101 - 0.054%
```


## 12/8/21
- '.' can't be next to 'e' or 'o'. Frequent with '.'
- Swap 'y' with '.'?

```
**Y          - 1424 - 1.043%  **
F          - 1343 - 0.984%
G          - 1179 - 0.863%
K          - 1176 - 0.861%
**.        - 981 - 0.718%   **
V          - 939 - 0.688%



P-.             - 13 - 0.007%
Y-I             - 4 - 0.002%
Y-ING           - 62 - 0.033%
I-Y             - 2 - 0.001%
Y-O             - 209 - 0.113%
A-Y             - 191 - 0.103%
E-Y             - 112 - 0.06%
P-Y             - 90 - 0.049%


P-A             - 268 - 0.144%
```

Base
```
Y-A-U-K - 538%
.-I-P - 158%
```
Move 'Y'
```
Y-I-P - 229%
.-A-U-K - 388%
```
Move 'K': 'ay' is 40% and easily resolved by 'ay' combo
```
K-I-P - 282%
.-A-U-Y - 428%
```

Looking at rolls. Fear will be a nightmare as all roll with 'o' and 'e' alot so need to be next to both
- 'K' best bet as can make 'ok' a combo. Tons of 'ook' tho
- Can move 'Y' and make 'O' adaptive key 
```
>  O-K - 188
>  K-O - 26
K-O - 188% - 214

>  K-E - 445
>  E-K - 53
K-E - 438% - 498

>  Y-O - 209
>  O-Y - 29
Y-O - 210% - 238

>  E-Y - 112
>  Y-E - 93
Y-E - 180% - 205

----
>  O-P - 297
>  P-O - 229
P-O - 463% - 526

>  P-E - 322
>  E-P - 101
P-E - 372% - 423
```

# 3/10/21
Usage of base arrows vs layer arrows
```
Base Left           - 52 - 3.652%
Base Right            - 23 - 1.615%
Layer Left          - 600 - 42.135%
Layer Right           - 749 - 52.598%
```

Seems I like the layer ones 10-20x more 


# 30/10/21 p-fix
Taking inspiration from: https://keyboard-design.com/letterlayout.html?layout=maks-sx.en.ergodox

current
```
q  p  o  k  =  -  f  l  b  j
h  i  e  a  .  w  d  t  s  r
z  y  ,  u  ;  v  c  m  g  x
            ␣  n
```

p-fix
'p' > 'b' > 'g' > '-' > '.' > 'y'
swap k and - or move ; to that position
Retain ou combo is now 'o-'
```
q  y  o  -  =  b  f  l  p  j
h  i  e  a  k  w  d  t  s  r
z  .  ,  u  ;  v  c  m  g  x
            ␣  n
```
In terms of clash p-fix has 8% less clashes. Nothing to brag about  
but people becomes easier to type.  
Scores slightly better on analyser but not that much better  
```
Current finger usages
Finger LPinky          - 2.05%
Finger LRing           - 7.8%
Finger LMid            - 11.43%
Finger LIndex          - 8.92%
Finger RIndex          - 7.59%
Finger RMid            - 9.37%
Finger RRing           - 5.76%
Finger RPinky          - 4.12%
Finger LThumb          - 19.54%
Finger RThumb          - 17.12%
Hand Left      - 49.74%
Hand Right     - 43.97%


Projected finger usages
Finger LPinky          - 2.05%
Finger LRing           - 7.1%
Finger LMid            - 11.43%
Finger LIndex          - 8.31%
Finger RIndex          - 8.25%
Finger RMid            - 9.37%
Finger RRing           - 6.41%
Finger RPinky          - 4.12%
Finger LThumb          - 19.54%
Finger RThumb          - 17.12%
Hand Left      - 48.43%
Hand Right     - 45.27%
```
Practising it seems nicer to play with. 'k' '.' and 'y' hard to learn


# Updated frequ 9/5/22
```
Bk/NAV     - 55117 - 12.106%
Bk         - 48252 - 10.598%
Space/L1   - 47064 - 10.337%
Space      - 43217 - 9.492%
E          - 31044 - 6.818%
T          - 23172 - 5.089%
A/Ctrl     - 22357 - 4.91%
A          - 20776 - 4.563%
O          - 18756 - 4.12%
I          - 17451 - 3.833%
R          - 16999 - 3.734%
N          - 16333 - 3.587%
S          - 16330 - 3.587%
Shift      - 15702 - 3.449%
Enter      - 15572 - 3.42%
L          - 11577 - 2.543%
D          - 10258 - 2.253%
C          - 9250 - 2.032%
H          - 9242 - 2.03%
U          - 7922 - 1.74%
M          - 7786 - 1.71%
P          - 6868 - 1.508%
NAV        - 6865 - 1.508%
F          - 5045 - 1.108%
W          - 4838 - 1.063%
G          - 4608 - 1.012%
Y          - 4224 - 0.928%
Tab        - 4212 - 0.925%
.          - 4036 - 0.886%
B          - 3941 - 0.866%
L1         - 3837 - 0.843%
Right      - 3797 - 0.834%
K          - 3643 - 0.8%
,          - 3583 - 0.787%
V          - 3455 - 0.759%
Del        - 3073 - 0.675%
Left       - 2997 - 0.658%
Down       - 2808 - 0.617%
0          - 2201 - 0.483%
Delword    - 2194 - 0.482%
Ctrl       - 1808 - 0.397%
1          - 1658 - 0.364%
ING        - 1610 - 0.354%
2          - 1580 - 0.347%
Alt/Esc    - 1494 - 0.328%
-          - 1421 - 0.312%
X          - 1314 - 0.289%
J          - 1284 - 0.282%
=          - 1244 - 0.273%
/          - 1148 - 0.252%
;          - 1101 - 0.242%
(          - 1016 - 0.223%
Up         - 945 - 0.208%
'          - 941 - 0.207%
AHK        - 817 - 0.179%
)          - 804 - 0.177%
3          - 778 - 0.171%
K_CUR_BK   - 727 - 0.16%
XXX-Comb--O - 631 - 0.139%
5          - 587 - 0.129%
{          - 542 - 0.119%
Q          - 539 - 0.118%
Z          - 534 - 0.117%
Media      - 505 - 0.111%
"          - 478 - 0.105%
Ctrl-T     - 464 - 0.102%
4          - 459 - 0.101%
XXX-Comb-PS - 410 - 0.09%
XXX-Comb-Y- - 374 - 0.082%
Ctrl-Left  - 358 - 0.079%
#          - 356 - 0.078%
QU         - 353 - 0.078%
8          - 337 - 0.074%
6          - 325 - 0.071%
7          - 310 - 0.068%
9          - 310 - 0.068%
Ctrl-D     - 300 - 0.066%
F2         - 289 - 0.063%
Ctrl-H     - 287 - 0.063%
?          - 286 - 0.063%
Clipboard  - 268 - 0.059%
XXX-Comb-FB - 253 - 0.056%
_          - 233 - 0.051%
+          - 223 - 0.049%
XXX-Comb-QY - 218 - 0.048%
End        - 217 - 0.048%
Ctrl-Right - 207 - 0.045%
[          - 196 - 0.043%
!          - 181 - 0.04%
XXX-Comb-U, - 173 - 0.038%
*          - 172 - 0.038%
Ctrl-/     - 171 - 0.038%
XXX-0x012B - 144 - 0.032%
F10        - 139 - 0.031%
OA         - 139 - 0.031%
Blank      - 132 - 0.029%
>          - 123 - 0.027%
$          - 111 - 0.024%
XXX-0x5D67 - 110 - 0.024%
XXX-0x0039 - 105 - 0.023%
Global     - 103 - 0.023%
Ctrl-I     - 103 - 0.023%
Ctrl-R     - 100 - 0.022%
Undo Tab   - 99 - 0.022%
Win        - 97 - 0.021%
Home       - 97 - 0.021%
XXX-0x0109 - 97 - 0.021%
<          - 96 - 0.021%
]          - 93 - 0.02%
Snip       - 93 - 0.02%
Ctrl-B     - 87 - 0.019%
XXX-0x5D29 - 84 - 0.018%
£          - 82 - 0.018%
Ctrl-N     - 76 - 0.017%
XXX-0x022E - 75 - 0.016%
XXX-Comb-YQ - 74 - 0.016%
%          - 72 - 0.016%
@          - 64 - 0.014%
XXX-Comb-,U - 64 - 0.014%
&          - 60 - 0.013%
XXX-Shft-0x0234 - 56 - 0.012%
XXX-0x5D65 - 54 - 0.012%
DAVID      - 53 - 0.012%
XXX-0x032B - 53 - 0.012%
```

# 9/5/22
- Swap 'k' and ','
- Need to fix 'mp' - more common than 'mb'
- swap 'h' and 'k' ?

```
Current usage:
=============================
Finger LPinky          - 2.51%
Finger LRing           - 7.04%
Finger LMid            - 12.25%
Finger LIndex          - 13.32%
Finger RIndex          - 8.68%
Finger RMid            - 9.42%
Finger RRing           - 6.46%
Finger RPinky          - 4.51%
Finger LThumb          - 17.04%
Finger RThumb          - 17.34%
Hand Left      - 52.16%
Hand Right     - 46.41%
```

```
Proposed usage:
=============================
Finger LPinky          - 2.51%
Finger LRing           - 7.04%
Finger LMid            - 12.26%
Finger LIndex          - 13.31%
Finger RIndex          - 8.68%
Finger RMid            - 9.42%
Finger RRing           - 6.46%
Finger RPinky          - 4.51%
Finger LThumb          - 17.04%
Finger RThumb          - 17.34%
Hand Left      - 52.16%
Hand Right     - 46.41%
```

But 'k' clashes alot with 'o' and 'e':
```
--A-U-K - 305% - 884
O-E-, - 241% - 699


--A-U-, - 190% - 550
O-E-K - 593% - 1720
```

### swap 'h' and 'k' ?
'h' has 3x usage. But I wonder how much of that is adative keys? Est (6937)
H   - 2400 (non adaptive)
K   - 3643 

So it and k similar then... but k maybe slighly more use

New method to Look at position 2 key combos to see how much typing 'h' key right now. And how would clash with 'o' or 'e' if move to where ',' currently is

But h leading an o or e outnumbers k doing the same by a significant majority
```
{X=3,Y=1} = 434 - h followed by o
{X=3,Y=2} = 839 - h followed by e
{X=4,Y=2} = 1024 - h followed by a


{X=4,Y=2} = 102- k followed by a
... 
{X=2,Y=2} = 272 - k followed by i
{X=4,Y=6} = 361 - K followed by bkspc
{X=3,Y=2} = 739 - k followed by e
{X=7,Y=5} = 790 - k followed by space
```

# 11/05/22
- swap 'u' => ',' => 'k'

Already have ou combo which I'm guessing is most of u use case

