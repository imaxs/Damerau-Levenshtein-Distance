# Damerau-Levenshtein-Distance
The method for finding all occurrences of a substring / word in a string using the Damerau-Levenshtein distance calculation.

ℹ️ Informally, the Damerau–Levenshtein distance between two words is the minimum number of operations (consisting of insertions, deletions or substitutions of a single character, or transposition of two adjacent characters) required to change one word into the other.

The restricted distance function is defined recursively as:

![Image alt](https://wikimedia.org/api/rest_v1/media/math/render/svg/22ea8d20aa45964a576e30f15646feecdef1b5b7)

This code sample shows how you can using the algorithm.

Input data:

The string whose content is searched — **"Search the world's information, including webpages, images, videos and more. Googole has many special features to help you find exactly what you're looking"**.
```CPP
char* str = "searchtheworldsinformationincludingwebpagesimagesvideosandmorpgoogolehasmanyspecialfeaturestohelpyoufindexactlywhatyourelookinss";
```
_Note: In the code, the string is converted to lowercase and spaces have been removed._

The word to search for — **"Google"**.
```CPP
char* word = "google";
```
_Note: In the code, the word is converted to lowercase._

First this method searches for a character in a string.
```CPP
if (str[k] == word[i])
```
Then the Damerau-Levenshtein algorithm is applied to the section of the string in which the character was successfully found.
```CPP
if ((k - i) < 0 || (k - i + length) > strsize) continue;
string strword = data.substr(k - i, length);
int dist = GetDamerauLevenshteinDistance(word, &strword[0]);
```
![Image alt](https://github.com/imaxs/Damerau-Levenshtein-Distance/blob/main/pic.png)

Result:
```
gwebpa[4]
gesima[5]
gesvid[5]
googol[2]
goleha[4]
worlds[5]
format[5]
ioninc[4]
eosand[5]
morpgo[5]
googol[2]
oogole[2]
goleha[4]
tohelp[4]
youfin[5]
yourel[4]
lookin[4]
ookins[5]
eworld[4]
nforma[5]
tionin[5]
deosan[5]
dmorpg[5]
pgoogo[3]
googol[2]
ogoleh[3]
stohel[4]
pyoufi[5]
tyoure[4]
elooki[5]
lookin[4]
dingwe[4]
bpages[5]
images[4]
orpgoo[5]
googol[2]
eworld[4]
ninclu[5]
oogole[2]
ecialf[5]
tohelp[4]
xactly[5]
ourelo[5]
rchthe[5]
dingwe[4]
ebpage[5]
simage[4]
esvide[5]
oogole[2]
anyspe[5]
cialfe[5]
eature[5]
estohe[5]
ufinde[5]
tyoure[4]
Time: 60 ms
```
