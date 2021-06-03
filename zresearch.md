# Finally decided to take the plunge and move of qwerty

Possible options:
- Dvorak
- RTSHD
- Colemax
- Custom

Tasks:
[] Start logging keys
[] Research layouts 


Input scope analysis:
 
- Bkspace
- Shift
- Space
- E

# General
- Thinking should move = to a more ergonomic place? It and minus require a finger spray motion but typing them seem to has a high accuracy
- Esc position? Check frequency, corner equals position or thumb key?
- Also when coding (), {}, and [] auto complete. So maybe try mapping sdf to those and above them to their close. Will free up 2 keys on main
- Opposing thumb layers feels like it would be better.


# Open questions/Design considerations

1. Want control key mod on home row Middle finger postion
2. Programming focused
3. Thumb E? - too much thumb wor
4. Digraph th? - don't do th enough
5. Right pinky A needs to be a less infrequently used key. While home row it is more strain on my pinky

# Layouts
### Dvorak
Pros:
- Kinesis has labels for this
- ., is in a great position
- with thumb key e mod, home row ctrl is in perfect position
- F and L positons are not ideal
- Alternating hands

Cons:
- A is left pinky. Can swap with E
- ; is in an horrible positions on the left hand. 
- Moves alot of keys (harder to learn)


http://xahlee.info/kbd/keyboard_dvorak_layout.html  
http://xahlee.info/kbd/dvorak_vs_colemak.html  

Users: Xahlee


### Coleman DHm Mod & Miryoku
Pros:
- Not important for me: Copy paste designed to be in same place but don't really use those keys but balanced by their position is fine on my weakest fingers
- Rolling
- popular in ergo world


Cons:
- Semicolon finger movement is not ideal painful (qwerty P)
- Other letters that I think are cumbersome with Colemak are the letters G, L, and O. I believe that by moving these letters, horizontal and diagonal stretching could be made less and the load on the right pinky could be reduced.
- A is left pinky.

Recommendations:
- swap A with E postion. E thumb
- swap A and R

https://colemak.com/
https://colemakmods.github.io/mod-dh/  
http://xahlee.info/kbd/dvorak_vs_colemak.html  
https://github.com/manna-harbour/qmk_firmware/blob/miryoku/users/manna-harbour_miryoku/miryoku.org#numerals-and-symbols-nsl

Users: Precondition


### Norman 
- Very few keys move
- ASD with thumb key E mod
- H is on weak right pinky
- Semicolon finger movement is not ideal painful (qwerty P)

http://normanlayout.info/about


### RTHSD
- Thumb E built in


### Beakl
http://thedarnedestthing.com/beakl%20wi

### Hands down layout
https://sites.google.com/alanreiser.com/handsdown


# The experiment
Decided to try handsdown alt-e and colemak dhm

Colemax:
- Popular
- good ,./ position. semicolon is not ideal but we can work with it
- left pinky with A is doing a bit too much work for my liking but that is its only key

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

- Looking at the heatmap
- Should have shift on second thumb rather than first
- Maybe e in the map as thumbs doing alot of work.
- Work seems more towards Backspace
- Defo move L. Swap with K.

# Colemak heatmap

- Seems balanced across both hands
- L postion is not so idea. Swap with H.


# Comparing heatmaps

E defo the elephant in the room
L is a large use key for me not accounted for in optimisers. Maybe from Lothea? ctrl L? let? class?
Both look good. Think it will come down to do I like index corners free for symbols and can handle load on thumb e
Defo need to move that backspace postion. Looking at the stats its in a horrible positon

# difficulty matrix
https://workmanlayout.org/#back-to-the-drawing-board  
https://colemakmods.github.io/mod-dh/compare.html  
https://deskthority.net/wiki/BEAKL#Effort_Grid  
https://stevep99.github.io/keyboard-effort-grid/


# 12/5/21
So decided to go for the Alt N mod

- F is on right hand. Good for Ctrl-F
- Swapped L and H. TH is top bigram, CL is a common bigram (GL also but lower). Getting around the TH problem by mapping TL&TH combo to TH, and TD combo to the (d get it?)
- N on thumb is used a lot but E is 150-200% of N so ok.
- Will have - on right index bottom right. Gets used alot: Notes, code, trello and that is a nice spot for my hands to reach.
- As mentioned before bkspace and shift swapped
- Also between 2 keys may be nicer chord

Really happy with layout. Think will be a pleasure to type



- Swap UK
- rotate right home row one to the right.


# 15/5/21
layout implemented. the s is giving me a pain in the ass tho and the h is fine but does play well with rolls

# 16/5/21
thinking changes
- D on home row then RS back in orginal position on pinky. Tried for a bit but doesn't gel well and worried about left pinky use

- Swap F and H so f on home row. plays more nicely with ctrl f, but think will map home row fore finger to ctrl f
- swap CL <> GM - as top has lower effor than bottom, and use cl more than gm


Liking this layout


# Top keys
See also
- https://gist.github.com/lydell/c439049abac2c9226e53
- http://norvig.com/mayzner.html
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
```
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
```

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

- TH bigram not great but way around with th/the combos.
- ow/wo other bigram not great. But occurence is sufficently lOW
- left index has high utilisation > 20%. But my f vs h usuage is neligable (think ctrl+f is to blame=10%)

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
- Penalise left pinky
- Top ring and middle better 
- Top index RU and index bottom right is hard on kimiko but ok on kinesis

# Options: 

- 'H' position is fine but feel should be better
- Thinking swapping h with y or w as on kimiko index stretch doesn't feel comfortable
- wsad arrow keys position feels more natural. or can try on ijkl. requires swapping symbol and nav triggers to other hands.
- alt ex has 'p' in position i like, where 'h' currently is 
- left index has high utilisation > 20%. But my 'f' vs 'h'  usuage is neligable (think ctrl+f is to blame=10%)

### Pinky dilema:
- swapping 'g' and 'f' might be worth doing. As with ing combo would not use 'g' as frequently and its already lower than 'f'. B1jiion;ei6piiiiiiiiieeeei889wkwfffff1jbrings almost on par with g.
- also nice to have: f has a homing key that makes it ideal to find home. popping j on i so get that homing too.
- Only way to reduce right pink would be to swap 'f' and 'w'. Plus 'for' combo to negate sfb. 
- From my data fo gram ok as long as have for combo. For was 139/163 fo grams

### 'L' Dilema
- Don't like P position. Think it's recieved such a nice position considering its usuage.
- 'L' position is not ideal as use 'L' alot. I would also argue reverse. On kinesis it almost same as 'p' and only slightly worse on kimiko

Swapping l and p gives problems with li bigram. V. Common in my dataset  
Same-Finger Bigrams  
finger 7 	LI 	0.557%  
finger 7 	IL 	0.433%  
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
- 'w', 'f', 'h', change - fix issue of left pinky overwork by replacing with lower freq 'w'. Also read 'h' gels better as a const on the vowel hand. 
- 'g' and 'b' change - not really nessary - optional change as use both the same frequency. Keeps 'g' in qwerty pos, but b on qwerty finger. On kimiko index pos is slightly easier. kinesis other way
- 'r' 's' change - Been hard to learn new 's' and 'r' pos. This return 's' to qwerty pos. Slight stats improvement
- Jay-Z change - move 'j' and 'z' to original hands. No stat change.


# 29/5/21   
- Feel 'C-S-B' finger not gelling on b. Having big row jumps e.g BaCk

# Typing pratice
Goal is to get to my current avg - 50 wpm
```
84.84%
88.89%
88.76%
85.16%
86.39%
89.60%
91.78%
90.67%
91.55%
93.48%
88.72%
92.44%
93.28%
87.88%

84.20%
89.10%
96.33%
92.99%
94.46%
92.42%
93.43%
93.14%
92.61%

84.66%
92.63%
93.00%
88.27%

89.70%
92.25%
93.59%
90.25%

90.439
92.80%
91.14%
92.83%
91.85%
89.80%

93.45%
```


