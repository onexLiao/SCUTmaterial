1.  CBBBA DBABA
2.  (1) (!L1.remove(temp))  L1.next();  L1.insert(temp);
     (2) int i = (l+r)/2; r = i; return i; l = i; return l
     (3)最矮高度：n=0,1时，答案为n，n大于或等于2时，为2；
     最高高度： n  

3. 
![](https://upload-images.jianshu.io/upload_images/15206312-c41aa4a15bcdec25.PNG?imageMogr2/auto-orient/strip%7CimageView2/2/w/1240)
4. 
![](https://upload-images.jianshu.io/upload_images/15206312-83b0eaa51b0b11ad.PNG?imageMogr2/auto-orient/strip%7CimageView2/2/w/1240)
5. 
| A | B | C | D | E | F | G | H |
|:-:|:-:|:-:|:-:|:-:|:-:|:-:|:-:|
| 0110 | 10 | 0000 | 0111 | 001 | 010 | 11 | 0001 |
4 * 5 + 2 * 25 + 4 * 3 + 4 * 6 + 3 * 10 + 3 * 11 + 2 * 36 + 4 * 4 = 257, 257 / 100 = 2.57
![](https://upload-images.jianshu.io/upload_images/15206312-370197aca31337d3.PNG?imageMogr2/auto-orient/strip%7CimageView2/2/w/1240)
<br>
6. 72    6    57    88    60    42   83   73   48   85
48    6    57    42    60    88   83   73   72   85
6     42   57    48    60    72   73   85   88   83
6     42   48    57    60    72   73   85   83   88
6     42   48    57    60    72   73   83   85   88
<br>
7. The first question is How many tracks are required by the file? 
A track holds **144\*0.5K = 72K**.  Thus, the file requires **5** tracks. 
The time to read a track is seek time to the 
**track + latency time + (interleaf factor × rotation time).**
Average seek time is defined to be 80 ms. Latency time is **0.5 \* 16.7**ms, 
and track rotation time is **16.7** ms for a total time to read the first track of
**80 + 4.5 * 16.7 ≈ 155 ms.**
Seek time for the remaining four tracks is defined to be **20** ms (since they are
adjacent), with identical latency and read times. 
Thus, the total file read time is
**155 + 4(20 + 4.5 * 16.7) ≈ 536 ms**
8.
 ![](https://upload-images.jianshu.io/upload_images/15206312-e1bb0c3a64940de8.png?imageMogr2/auto-orient/strip%7CimageView2/2/w/1240)

9.  H1(22)=0, H1(41)=2 H1(53)=5 H1(46)=6 H1(30)=2 H1(13)=6 H1(1)=3 H1(67)=3 H2(30)=1 H2(13)=2 H2(1)=8 H2(67)=10

22进0,  41进2,  53进5,   46进6,   30进3,   13进8,  1进10,  67进1

