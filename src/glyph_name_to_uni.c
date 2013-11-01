/* ANSI-C code produced by gperf version 3.0.3 */
/* Command-line: gperf -CGD -L ANSI-C -e ';' -t -N glyph_name_to_uni -H glyph_name_hash --output-file=pdfdoc/glyph_name_to_uni.c pdfdoc/glyphlist.txt  */
/* Computed positions: -k'1-8,12-13,16,$' */

#if !((' ' == 32) && ('!' == 33) && ('"' == 34) && ('#' == 35) \
      && ('%' == 37) && ('&' == 38) && ('\'' == 39) && ('(' == 40) \
      && (')' == 41) && ('*' == 42) && ('+' == 43) && (',' == 44) \
      && ('-' == 45) && ('.' == 46) && ('/' == 47) && ('0' == 48) \
      && ('1' == 49) && ('2' == 50) && ('3' == 51) && ('4' == 52) \
      && ('5' == 53) && ('6' == 54) && ('7' == 55) && ('8' == 56) \
      && ('9' == 57) && (':' == 58) && (';' == 59) && ('<' == 60) \
      && ('=' == 61) && ('>' == 62) && ('?' == 63) && ('A' == 65) \
      && ('B' == 66) && ('C' == 67) && ('D' == 68) && ('E' == 69) \
      && ('F' == 70) && ('G' == 71) && ('H' == 72) && ('I' == 73) \
      && ('J' == 74) && ('K' == 75) && ('L' == 76) && ('M' == 77) \
      && ('N' == 78) && ('O' == 79) && ('P' == 80) && ('Q' == 81) \
      && ('R' == 82) && ('S' == 83) && ('T' == 84) && ('U' == 85) \
      && ('V' == 86) && ('W' == 87) && ('X' == 88) && ('Y' == 89) \
      && ('Z' == 90) && ('[' == 91) && ('\\' == 92) && (']' == 93) \
      && ('^' == 94) && ('_' == 95) && ('a' == 97) && ('b' == 98) \
      && ('c' == 99) && ('d' == 100) && ('e' == 101) && ('f' == 102) \
      && ('g' == 103) && ('h' == 104) && ('i' == 105) && ('j' == 106) \
      && ('k' == 107) && ('l' == 108) && ('m' == 109) && ('n' == 110) \
      && ('o' == 111) && ('p' == 112) && ('q' == 113) && ('r' == 114) \
      && ('s' == 115) && ('t' == 116) && ('u' == 117) && ('v' == 118) \
      && ('w' == 119) && ('x' == 120) && ('y' == 121) && ('z' == 122) \
      && ('{' == 123) && ('|' == 124) && ('}' == 125) && ('~' == 126))
/* The character set is not based on ISO-646.  */
#error "gperf generated tables don't work with this execution character set. Please report a bug to <bug-gnu-gperf@gnu.org>."
#endif

#line 1 "pdfdoc/glyphlist.txt"

/*
# Name:          Adobe Glyph List
# Table version: 2.0
# Date:          September 20, 2002
#
# See http://partners.adobe.com/asn/developer/typeforum/unicodegn.html
#
# Format: Semicolon-delimited fields:
#            (1) glyph name
#            (2) Unicode scalar value
*/
#include <string.h>
#line 16 "pdfdoc/glyphlist.txt"
struct glyphlist { char* name; char *unicode; };

#define TOTAL_KEYWORDS 4281
#define MIN_WORD_LENGTH 1
#define MAX_WORD_LENGTH 39
#define MIN_HASH_VALUE 16
#define MAX_HASH_VALUE 75515
/* maximum key range = 75500, duplicates = 0 */

#ifdef __GNUC__
__inline
#else
#ifdef __cplusplus
inline
#endif
#endif
static unsigned int
glyph_name_hash (register const char *str, register unsigned int len)
{
  static const unsigned int asso_values[] =
    {
      75516, 75516, 75516, 75516, 75516, 75516, 75516, 75516, 75516, 75516,
      75516, 75516, 75516, 75516, 75516, 75516, 75516, 75516, 75516, 75516,
      75516, 75516, 75516, 75516, 75516, 75516, 75516, 75516, 75516, 75516,
      75516, 75516, 75516, 75516, 75516, 75516, 75516, 75516, 75516, 75516,
      75516, 75516, 75516, 75516, 75516, 75516, 75516, 75516,    25,     5,
         60,   955,   575,    95,   470,   125,  1405,  1190,     0,    10,
        705,  2380,  2020,  3200,  1530,    10,     0,   195,   340,    15,
        110,   330,  2835,  2645,    25,    20,     0,     0,     5,  2170,
         40,   460,    45,  7410,   145,   625,   175,   135,   105,   620,
         50,    75,    60,   910,   225,   130,    55,     0,  7968,    25,
       1930,    20,  8212,   155,    10,    25, 12239,    90,   425,   160,
         55,    15,  2950,  5590,    35,   205,   125,     5,   890,   555,
         30,  5350,  1275,  7105,   385,  7430,  3550, 13797, 10267,  4000,
      23334, 15507,  9252, 16129,  3023, 20509,  7275,     0,    30,    30,
      75516, 75516, 75516, 75516, 75516, 75516, 75516, 75516, 75516, 75516,
      75516, 75516, 75516, 75516, 75516, 75516, 75516, 75516, 75516, 75516,
      75516, 75516, 75516, 75516, 75516, 75516, 75516, 75516, 75516, 75516,
      75516, 75516, 75516, 75516, 75516, 75516, 75516, 75516, 75516, 75516,
      75516, 75516, 75516, 75516, 75516, 75516, 75516, 75516, 75516, 75516,
      75516, 75516, 75516, 75516, 75516, 75516, 75516, 75516, 75516, 75516,
      75516, 75516, 75516, 75516, 75516, 75516, 75516, 75516, 75516, 75516,
      75516, 75516, 75516, 75516, 75516, 75516, 75516, 75516, 75516, 75516,
      75516, 75516, 75516, 75516, 75516, 75516, 75516, 75516, 75516, 75516,
      75516, 75516, 75516, 75516, 75516, 75516, 75516, 75516, 75516, 75516,
      75516, 75516, 75516, 75516, 75516, 75516, 75516, 75516, 75516, 75516,
      75516, 75516, 75516, 75516, 75516, 75516, 75516, 75516, 75516, 75516,
      75516, 75516, 75516, 75516, 75516, 75516, 75516, 75516, 75516, 75516,
      75516, 75516, 75516
    };
  register int hval = len;

  switch (hval)
    {
      default:
        hval += asso_values[(unsigned char)str[15]];
      /*FALLTHROUGH*/
      case 15:
      case 14:
      case 13:
        hval += asso_values[(unsigned char)str[12]];
      /*FALLTHROUGH*/
      case 12:
        hval += asso_values[(unsigned char)str[11]];
      /*FALLTHROUGH*/
      case 11:
      case 10:
      case 9:
      case 8:
        hval += asso_values[(unsigned char)str[7]+12];
      /*FALLTHROUGH*/
      case 7:
        hval += asso_values[(unsigned char)str[6]+17];
      /*FALLTHROUGH*/
      case 6:
        hval += asso_values[(unsigned char)str[5]];
      /*FALLTHROUGH*/
      case 5:
        hval += asso_values[(unsigned char)str[4]];
      /*FALLTHROUGH*/
      case 4:
        hval += asso_values[(unsigned char)str[3]+6];
      /*FALLTHROUGH*/
      case 3:
        hval += asso_values[(unsigned char)str[2]];
      /*FALLTHROUGH*/
      case 2:
        hval += asso_values[(unsigned char)str[1]];
      /*FALLTHROUGH*/
      case 1:
        hval += asso_values[(unsigned char)str[0]+14];
        break;
    }
  return hval + asso_values[(unsigned char)str[len - 1]];
}

static const struct glyphlist wordlist[] =
  {
#line 752 "pdfdoc/glyphlist.txt"
    {"a","0061"},
#line 69 "pdfdoc/glyphlist.txt"
    {"B","0042"},
#line 355 "pdfdoc/glyphlist.txt"
    {"L","004C"},
#line 357 "pdfdoc/glyphlist.txt"
    {"LL","F6BF"},
#line 798 "pdfdoc/glyphlist.txt"
    {"ae","00E6"},
#line 729 "pdfdoc/glyphlist.txt"
    {"Z","005A"},
#line 390 "pdfdoc/glyphlist.txt"
    {"N","004E"},
#line 410 "pdfdoc/glyphlist.txt"
    {"Nu","039D"},
#line 377 "pdfdoc/glyphlist.txt"
    {"M","004D"},
#line 389 "pdfdoc/glyphlist.txt"
    {"Mu","039C"},
#line 509 "pdfdoc/glyphlist.txt"
    {"Rho","03A1"},
#line 496 "pdfdoc/glyphlist.txt"
    {"R","0052"},
#line 356 "pdfdoc/glyphlist.txt"
    {"LJ","01C7"},
#line 1127 "pdfdoc/glyphlist.txt"
    {"arc","2312"},
#line 391 "pdfdoc/glyphlist.txt"
    {"NJ","01CA"},
#line 319 "pdfdoc/glyphlist.txt"
    {"J","004A"},
#line 112 "pdfdoc/glyphlist.txt"
    {"DZ","01F1"},
#line 686 "pdfdoc/glyphlist.txt"
    {"W","0057"},
#line 1928 "pdfdoc/glyphlist.txt"
    {"g","0067"},
#line 1845 "pdfdoc/glyphlist.txt"
    {"fi","FB01"},
#line 561 "pdfdoc/glyphlist.txt"
    {"Scaron","0160"},
#line 276 "pdfdoc/glyphlist.txt"
    {"IJ","0132"},
#line 1946 "pdfdoc/glyphlist.txt"
    {"gcaron","01E7"},
#line 645 "pdfdoc/glyphlist.txt"
    {"Uhorn","01AF"},
#line 732 "pdfdoc/glyphlist.txt"
    {"Zcaron","017D"},
#line 774 "pdfdoc/glyphlist.txt"
    {"acaron","01CE"},
#line 625 "pdfdoc/glyphlist.txt"
    {"Ucaron","01D3"},
#line 1900 "pdfdoc/glyphlist.txt"
    {"four","0034"},
#line 2330 "pdfdoc/glyphlist.txt"
    {"jcaron","01F0"},
#line 1978 "pdfdoc/glyphlist.txt"
    {"ghook","0260"},
#line 1569 "pdfdoc/glyphlist.txt"
    {"dcaron","010F"},
#line 1668 "pdfdoc/glyphlist.txt"
    {"e","0065"},
#line 116 "pdfdoc/glyphlist.txt"
    {"Dcaron","010E"},
#line 360 "pdfdoc/glyphlist.txt"
    {"Lcaron","013D"},
#line 499 "pdfdoc/glyphlist.txt"
    {"Rcaron","0158"},
#line 393 "pdfdoc/glyphlist.txt"
    {"Ncaron","0147"},
#line 1605 "pdfdoc/glyphlist.txt"
    {"dhook","0257"},
#line 76 "pdfdoc/glyphlist.txt"
    {"Bhook","0181"},
#line 210 "pdfdoc/glyphlist.txt"
    {"F","0046"},
#line 127 "pdfdoc/glyphlist.txt"
    {"Dhook","018A"},
#line 379 "pdfdoc/glyphlist.txt"
    {"Macron","F6D0"},
#line 1938 "pdfdoc/glyphlist.txt"
    {"gahiragana","304C"},
#line 477 "pdfdoc/glyphlist.txt"
    {"P","0050"},
#line 1190 "pdfdoc/glyphlist.txt"
    {"at","0040"},
#line 1808 "pdfdoc/glyphlist.txt"
    {"euro","20AC"},
#line 2022 "pdfdoc/glyphlist.txt"
    {"guhiragana","3050"},
#line 486 "pdfdoc/glyphlist.txt"
    {"Pi","03A0"},
#line 1999 "pdfdoc/glyphlist.txt"
    {"gohiragana","3054"},
#line 1954 "pdfdoc/glyphlist.txt"
    {"gehiragana","3052"},
#line 484 "pdfdoc/glyphlist.txt"
    {"Phi","03A6"},
#line 1980 "pdfdoc/glyphlist.txt"
    {"gihiragana","304E"},
#line 1513 "pdfdoc/glyphlist.txt"
    {"dahiragana","3060"},
#line 1659 "pdfdoc/glyphlist.txt"
    {"duhiragana","3065"},
#line 1102 "pdfdoc/glyphlist.txt"
    {"angle","2220"},
#line 1590 "pdfdoc/glyphlist.txt"
    {"degree","00B0"},
#line 1631 "pdfdoc/glyphlist.txt"
    {"dohiragana","3069"},
#line 742 "pdfdoc/glyphlist.txt"
    {"Zeta","0396"},
#line 1592 "pdfdoc/glyphlist.txt"
    {"dehiragana","3067"},
#line 1616 "pdfdoc/glyphlist.txt"
    {"dihiragana","3062"},
#line 281 "pdfdoc/glyphlist.txt"
    {"Icaron","01CF"},
#line 1964 "pdfdoc/glyphlist.txt"
    {"ghabengali","0998"},
#line 1796 "pdfdoc/glyphlist.txt"
    {"eta","03B7"},
#line 1901 "pdfdoc/glyphlist.txt"
    {"fourarabic","0664"},
#line 1927 "pdfdoc/glyphlist.txt"
    {"franc","20A3"},
#line 75 "pdfdoc/glyphlist.txt"
    {"Beta","0392"},
#line 2342 "pdfdoc/glyphlist.txt"
    {"jhabengali","099D"},
#line 1799 "pdfdoc/glyphlist.txt"
    {"eth","00F0"},
#line 1601 "pdfdoc/glyphlist.txt"
    {"dhabengali","09A7"},
#line 1573 "pdfdoc/glyphlist.txt"
    {"dcroat","0111"},
#line 215 "pdfdoc/glyphlist.txt"
    {"Fhook","0191"},
#line 120 "pdfdoc/glyphlist.txt"
    {"Dcroat","0110"},
#line 717 "pdfdoc/glyphlist.txt"
    {"Yhook","01B3"},
#line 1940 "pdfdoc/glyphlist.txt"
    {"gamma","03B3"},
#line 1923 "pdfdoc/glyphlist.txt"
    {"fourthai","0E54"},
#line 111 "pdfdoc/glyphlist.txt"
    {"D","0044"},
#line 582 "pdfdoc/glyphlist.txt"
    {"Sigma","03A3"},
#line 1678 "pdfdoc/glyphlist.txt"
    {"ecaron","011B"},
#line 2826 "pdfdoc/glyphlist.txt"
    {"nu","03BD"},
#line 1639 "pdfdoc/glyphlist.txt"
    {"dong","20AB"},
#line 1785 "pdfdoc/glyphlist.txt"
    {"esh","0283"},
#line 309 "pdfdoc/glyphlist.txt"
    {"Iota","0399"},
#line 2336 "pdfdoc/glyphlist.txt"
    {"jeemarabic","062C"},
#line 485 "pdfdoc/glyphlist.txt"
    {"Phook","01A4"},
#line 2703 "pdfdoc/glyphlist.txt"
    {"n","006E"},
#line 1509 "pdfdoc/glyphlist.txt"
    {"dagger","2020"},
#line 2347 "pdfdoc/glyphlist.txt"
    {"jis","3004"},
#line 2004 "pdfdoc/glyphlist.txt"
    {"grave","0060"},
#line 489 "pdfdoc/glyphlist.txt"
    {"Psi","03A8"},
#line 2340 "pdfdoc/glyphlist.txt"
    {"jeharabic","0698"},
#line 2840 "pdfdoc/glyphlist.txt"
    {"nun","05E0"},
#line 1507 "pdfdoc/glyphlist.txt"
    {"dagesh","05BC"},
#line 1129 "pdfdoc/glyphlist.txt"
    {"aring","00E5"},
#line 105 "pdfdoc/glyphlist.txt"
    {"Chi","03A7"},
#line 668 "pdfdoc/glyphlist.txt"
    {"Uring","016E"},
#line 1060 "pdfdoc/glyphlist.txt"
    {"ainarabic","0639"},
#line 2339 "pdfdoc/glyphlist.txt"
    {"jeemmedialarabic","FEA0"},
#line 2717 "pdfdoc/glyphlist.txt"
    {"ncaron","0148"},
#line 1759 "pdfdoc/glyphlist.txt"
    {"eng","014B"},
#line 2752 "pdfdoc/glyphlist.txt"
    {"nine","0039"},
#line 2181 "pdfdoc/glyphlist.txt"
    {"i","0069"},
#line 1633 "pdfdoc/glyphlist.txt"
    {"dollar","0024"},
#line 1835 "pdfdoc/glyphlist.txt"
    {"feharabic","0641"},
#line 492 "pdfdoc/glyphlist.txt"
    {"Q","0051"},
#line 1960 "pdfdoc/glyphlist.txt"
    {"germandbls","00DF"},
#line 85 "pdfdoc/glyphlist.txt"
    {"Caron","F6CA"},
#line 1812 "pdfdoc/glyphlist.txt"
    {"exclam","0021"},
#line 327 "pdfdoc/glyphlist.txt"
    {"K","004B"},
#line 2710 "pdfdoc/glyphlist.txt"
    {"nahiragana","306A"},
#line 87 "pdfdoc/glyphlist.txt"
    {"Ccaron","010C"},
#line 2827 "pdfdoc/glyphlist.txt"
    {"nuhiragana","306C"},
#line 621 "pdfdoc/glyphlist.txt"
    {"U","0055"},
#line 82 "pdfdoc/glyphlist.txt"
    {"C","0043"},
#line 2788 "pdfdoc/glyphlist.txt"
    {"nohiragana","306E"},
#line 2724 "pdfdoc/glyphlist.txt"
    {"nehiragana","306D"},
#line 2747 "pdfdoc/glyphlist.txt"
    {"nihiragana","306B"},
#line 106 "pdfdoc/glyphlist.txt"
    {"Chook","0187"},
#line 672 "pdfdoc/glyphlist.txt"
    {"Ustraightstrokecyrillic","04B0"},
#line 671 "pdfdoc/glyphlist.txt"
    {"Ustraightcyrillic","04AE"},
#line 1707 "pdfdoc/glyphlist.txt"
    {"eight","0038"},
#line 2794 "pdfdoc/glyphlist.txt"
    {"noonarabic","0646"},
#line 2839 "pdfdoc/glyphlist.txt"
    {"numero","2116"},
#line 2753 "pdfdoc/glyphlist.txt"
    {"ninearabic","0669"},
#line 570 "pdfdoc/glyphlist.txt"
    {"Scommaaccent","0218"},
#line 1950 "pdfdoc/glyphlist.txt"
    {"gcommaaccent","0123"},
#line 1893 "pdfdoc/glyphlist.txt"
    {"florin","0192"},
#line 2187 "pdfdoc/glyphlist.txt"
    {"icaron","01D0"},
#line 1115 "pdfdoc/glyphlist.txt"
    {"aogonek","0105"},
#line 2783 "pdfdoc/glyphlist.txt"
    {"nnabengali","09A3"},
#line 659 "pdfdoc/glyphlist.txt"
    {"Uogonek","0172"},
#line 2774 "pdfdoc/glyphlist.txt"
    {"ninethai","0E59"},
#line 364 "pdfdoc/glyphlist.txt"
    {"Lcommaaccent","013B"},
#line 502 "pdfdoc/glyphlist.txt"
    {"Rcommaaccent","0156"},
#line 704 "pdfdoc/glyphlist.txt"
    {"Y","0059"},
#line 397 "pdfdoc/glyphlist.txt"
    {"Ncommaaccent","0145"},
#line 1516 "pdfdoc/glyphlist.txt"
    {"dalet","05D3"},
#line 338 "pdfdoc/glyphlist.txt"
    {"Kcaron","01E8"},
#line 228 "pdfdoc/glyphlist.txt"
    {"Gcaron","01E6"},
#line 2802 "pdfdoc/glyphlist.txt"
    {"noonmedialarabic","FEE8"},
#line 347 "pdfdoc/glyphlist.txt"
    {"Khook","0198"},
#line 240 "pdfdoc/glyphlist.txt"
    {"Ghook","0193"},
#line 2729 "pdfdoc/glyphlist.txt"
    {"ngabengali","0999"},
#line 2299 "pdfdoc/glyphlist.txt"
    {"iota","03B9"},
#line 758 "pdfdoc/glyphlist.txt"
    {"aamatragurmukhi","0A3E"},
#line 308 "pdfdoc/glyphlist.txt"
    {"Iogonek","012E"},
#line 1201 "pdfdoc/glyphlist.txt"
    {"aumatragurmukhi","0A4C"},
#line 1059 "pdfdoc/glyphlist.txt"
    {"aimatragurmukhi","0A48"},
#line 1515 "pdfdoc/glyphlist.txt"
    {"dalarabic","062F"},
#line 1510 "pdfdoc/glyphlist.txt"
    {"daggerdbl","2021"},
#line 2030 "pdfdoc/glyphlist.txt"
    {"h","0068"},
#line 1050 "pdfdoc/glyphlist.txt"
    {"agurmukhi","0A05"},
#line 1939 "pdfdoc/glyphlist.txt"
    {"gakatakana","30AC"},
#line 1841 "pdfdoc/glyphlist.txt"
    {"female","2640"},
#line 2094 "pdfdoc/glyphlist.txt"
    {"he","05D4"},
#line 521 "pdfdoc/glyphlist.txt"
    {"SF040000","2518"},
#line 2027 "pdfdoc/glyphlist.txt"
    {"gukatakana","30B0"},
#line 1764 "pdfdoc/glyphlist.txt"
    {"eogonek","0119"},
#line 412 "pdfdoc/glyphlist.txt"
    {"OE","0152"},
#line 522 "pdfdoc/glyphlist.txt"
    {"SF050000","253C"},
#line 2000 "pdfdoc/glyphlist.txt"
    {"gokatakana","30B4"},
#line 1814 "pdfdoc/glyphlist.txt"
    {"exclamdbl","203C"},
#line 1955 "pdfdoc/glyphlist.txt"
    {"gekatakana","30B2"},
#line 1981 "pdfdoc/glyphlist.txt"
    {"gikatakana","30AE"},
#line 221 "pdfdoc/glyphlist.txt"
    {"G","0047"},
#line 1514 "pdfdoc/glyphlist.txt"
    {"dakatakana","30C0"},
#line 449 "pdfdoc/glyphlist.txt"
    {"Oi","01A2"},
#line 1660 "pdfdoc/glyphlist.txt"
    {"dukatakana","30C5"},
#line 534 "pdfdoc/glyphlist.txt"
    {"SF240000","2551"},
#line 1632 "pdfdoc/glyphlist.txt"
    {"dokatakana","30C9"},
#line 1892 "pdfdoc/glyphlist.txt"
    {"fl","FB02"},
#line 535 "pdfdoc/glyphlist.txt"
    {"SF250000","2557"},
#line 1594 "pdfdoc/glyphlist.txt"
    {"dekatakana","30C7"},
#line 1617 "pdfdoc/glyphlist.txt"
    {"dikatakana","30C2"},
#line 224 "pdfdoc/glyphlist.txt"
    {"Gamma","0393"},
#line 557 "pdfdoc/glyphlist.txt"
    {"SF540000","256A"},
#line 1657 "pdfdoc/glyphlist.txt"
    {"dtail","0256"},
#line 528 "pdfdoc/glyphlist.txt"
    {"SF110000","2502"},
#line 1072 "pdfdoc/glyphlist.txt"
    {"alefarabic","0627"},
#line 518 "pdfdoc/glyphlist.txt"
    {"SF010000","250C"},
#line 137 "pdfdoc/glyphlist.txt"
    {"Dslash","0110"},
#line 374 "pdfdoc/glyphlist.txt"
    {"Lslash","0141"},
#line 1698 "pdfdoc/glyphlist.txt"
    {"eematragurmukhi","0A47"},
#line 442 "pdfdoc/glyphlist.txt"
    {"Ohorn","01A0"},
#line 245 "pdfdoc/glyphlist.txt"
    {"Grave","F6CE"},
#line 531 "pdfdoc/glyphlist.txt"
    {"SF210000","2556"},
#line 419 "pdfdoc/glyphlist.txt"
    {"Ocaron","01D1"},
#line 2721 "pdfdoc/glyphlist.txt"
    {"ncommaaccent","0146"},
#line 2121 "pdfdoc/glyphlist.txt"
    {"hhook","0266"},
#line 799 "pdfdoc/glyphlist.txt"
    {"aeacute","01FD"},
#line 2289 "pdfdoc/glyphlist.txt"
    {"integralex","F8F5"},
#line 1161 "pdfdoc/glyphlist.txt"
    {"arrowtableft","21E4"},
#line 554 "pdfdoc/glyphlist.txt"
    {"SF510000","2552"},
#line 132 "pdfdoc/glyphlist.txt"
    {"Digammagreek","03DC"},
#line 1162 "pdfdoc/glyphlist.txt"
    {"arrowtabright","21E5"},
#line 1983 "pdfdoc/glyphlist.txt"
    {"gimel","05D2"},
#line 2041 "pdfdoc/glyphlist.txt"
    {"hahiragana","306F"},
#line 1871 "pdfdoc/glyphlist.txt"
    {"five","0035"},
#line 2168 "pdfdoc/glyphlist.txt"
    {"huhiragana","3075"},
#line 1957 "pdfdoc/glyphlist.txt"
    {"gereshaccenthebrew","059C"},
#line 510 "pdfdoc/glyphlist.txt"
    {"Ringsmall","F6FC"},
#line 2119 "pdfdoc/glyphlist.txt"
    {"het","05D7"},
#line 2143 "pdfdoc/glyphlist.txt"
    {"hohiragana","307B"},
#line 2110 "pdfdoc/glyphlist.txt"
    {"hehiragana","3078"},
#line 2128 "pdfdoc/glyphlist.txt"
    {"hihiragana","3072"},
#line 2251 "pdfdoc/glyphlist.txt"
    {"ieungacirclekorean","3275"},
#line 1853 "pdfdoc/glyphlist.txt"
    {"finalkafdagesh","FB3A"},
#line 2095 "pdfdoc/glyphlist.txt"
    {"heart","2665"},
#line 2288 "pdfdoc/glyphlist.txt"
    {"integralbt","2321"},
#line 440 "pdfdoc/glyphlist.txt"
    {"Ohm","2126"},
#line 454 "pdfdoc/glyphlist.txt"
    {"Omega","2126"},
#line 2298 "pdfdoc/glyphlist.txt"
    {"iogonek","012F"},
#line 1856 "pdfdoc/glyphlist.txt"
    {"finalkafqamats","05DA 05B8"},
#line 1872 "pdfdoc/glyphlist.txt"
    {"fivearabic","0665"},
#line 1739 "pdfdoc/glyphlist.txt"
    {"elevencircle","246A"},
#line 1048 "pdfdoc/glyphlist.txt"
    {"agrave","00E0"},
#line 693 "pdfdoc/glyphlist.txt"
    {"Wgrave","1E80"},
#line 642 "pdfdoc/glyphlist.txt"
    {"Ugrave","00D9"},
#line 2711 "pdfdoc/glyphlist.txt"
    {"nakatakana","30CA"},
#line 2828 "pdfdoc/glyphlist.txt"
    {"nukatakana","30CC"},
#line 2789 "pdfdoc/glyphlist.txt"
    {"nokatakana","30CE"},
#line 2725 "pdfdoc/glyphlist.txt"
    {"nekatakana","30CD"},
#line 2038 "pdfdoc/glyphlist.txt"
    {"haharabic","062D"},
#line 2748 "pdfdoc/glyphlist.txt"
    {"nikatakana","30CB"},
#line 341 "pdfdoc/glyphlist.txt"
    {"Kcommaaccent","0136"},
#line 1891 "pdfdoc/glyphlist.txt"
    {"fivethai","0E55"},
#line 232 "pdfdoc/glyphlist.txt"
    {"Gcommaaccent","0122"},
#line 2101 "pdfdoc/glyphlist.txt"
    {"heharabic","0647"},
#line 1805 "pdfdoc/glyphlist.txt"
    {"etnahtalefthebrew","0591"},
#line 782 "pdfdoc/glyphlist.txt"
    {"acute","00B4"},
#line 1802 "pdfdoc/glyphlist.txt"
    {"etnahtafoukhhebrew","0591"},
#line 1089 "pdfdoc/glyphlist.txt"
    {"aleph","2135"},
#line 527 "pdfdoc/glyphlist.txt"
    {"SF100000","2500"},
#line 2021 "pdfdoc/glyphlist.txt"
    {"gstroke","01E5"},
#line 751 "pdfdoc/glyphlist.txt"
    {"Zstroke","01B5"},
#line 2287 "pdfdoc/glyphlist.txt"
    {"integralbottom","2321"},
#line 1600 "pdfdoc/glyphlist.txt"
    {"dezh","02A4"},
#line 297 "pdfdoc/glyphlist.txt"
    {"Igrave","00CC"},
#line 2266 "pdfdoc/glyphlist.txt"
    {"iimatragurmukhi","0A40"},
#line 716 "pdfdoc/glyphlist.txt"
    {"Ygrave","1EF2"},
#line 530 "pdfdoc/glyphlist.txt"
    {"SF200000","2562"},
#line 568 "pdfdoc/glyphlist.txt"
    {"Scircle","24C8"},
#line 1948 "pdfdoc/glyphlist.txt"
    {"gcircle","24D6"},
#line 2258 "pdfdoc/glyphlist.txt"
    {"igurmukhi","0A07"},
#line 734 "pdfdoc/glyphlist.txt"
    {"Zcircle","24CF"},
#line 2506 "pdfdoc/glyphlist.txt"
    {"lcaron","013E"},
#line 775 "pdfdoc/glyphlist.txt"
    {"acircle","24D0"},
#line 688 "pdfdoc/glyphlist.txt"
    {"Wcircle","24CC"},
#line 626 "pdfdoc/glyphlist.txt"
    {"Ucircle","24CA"},
#line 553 "pdfdoc/glyphlist.txt"
    {"SF500000","2558"},
#line 2331 "pdfdoc/glyphlist.txt"
    {"jcircle","24D9"},
#line 1571 "pdfdoc/glyphlist.txt"
    {"dcircle","24D3"},
#line 547 "pdfdoc/glyphlist.txt"
    {"SF440000","256C"},
#line 1700 "pdfdoc/glyphlist.txt"
    {"egrave","00E8"},
#line 70 "pdfdoc/glyphlist.txt"
    {"Bcircle","24B7"},
#line 118 "pdfdoc/glyphlist.txt"
    {"Dcircle","24B9"},
#line 548 "pdfdoc/glyphlist.txt"
    {"SF450000","2567"},
#line 2528 "pdfdoc/glyphlist.txt"
    {"lira","20A4"},
#line 362 "pdfdoc/glyphlist.txt"
    {"Lcircle","24C1"},
#line 501 "pdfdoc/glyphlist.txt"
    {"Rcircle","24C7"},
#line 1820 "pdfdoc/glyphlist.txt"
    {"ezh","0292"},
#line 395 "pdfdoc/glyphlist.txt"
    {"Ncircle","24C3"},
#line 2286 "pdfdoc/glyphlist.txt"
    {"integral","222B"},
#line 2560 "pdfdoc/glyphlist.txt"
    {"luthai","0E26"},
#line 314 "pdfdoc/glyphlist.txt"
    {"Istroke","0197"},
#line 382 "pdfdoc/glyphlist.txt"
    {"Mcircle","24C2"},
#line 1670 "pdfdoc/glyphlist.txt"
    {"earth","2641"},
#line 1877 "pdfdoc/glyphlist.txt"
    {"fiveeighths","215D"},
#line 321 "pdfdoc/glyphlist.txt"
    {"Jcircle","24BF"},
#line 1051 "pdfdoc/glyphlist.txt"
    {"ahiragana","3042"},
#line 800 "pdfdoc/glyphlist.txt"
    {"aekorean","3150"},
#line 1855 "pdfdoc/glyphlist.txt"
    {"finalkafhebrew","05DA"},
#line 1833 "pdfdoc/glyphlist.txt"
    {"fcircle","24D5"},
#line 493 "pdfdoc/glyphlist.txt"
    {"Qcircle","24C6"},
#line 282 "pdfdoc/glyphlist.txt"
    {"Icircle","24BE"},
#line 2779 "pdfdoc/glyphlist.txt"
    {"nlegrightlong","019E"},
#line 211 "pdfdoc/glyphlist.txt"
    {"Fcircle","24BB"},
#line 650 "pdfdoc/glyphlist.txt"
    {"Uhorntilde","1EEE"},
#line 708 "pdfdoc/glyphlist.txt"
    {"Ycircle","24CE"},
#line 544 "pdfdoc/glyphlist.txt"
    {"SF410000","2566"},
#line 1899 "pdfdoc/glyphlist.txt"
    {"forall","2200"},
#line 262 "pdfdoc/glyphlist.txt"
    {"Hcircle","24BD"},
#line 583 "pdfdoc/glyphlist.txt"
    {"Sixroman","2165"},
#line 523 "pdfdoc/glyphlist.txt"
    {"SF060000","252C"},
#line 2103 "pdfdoc/glyphlist.txt"
    {"hehfinalaltonearabic","FBA7"},
#line 464 "pdfdoc/glyphlist.txt"
    {"Oogonek","01EA"},
#line 1682 "pdfdoc/glyphlist.txt"
    {"ecircle","24D4"},
#line 400 "pdfdoc/glyphlist.txt"
    {"Nhookleft","019D"},
#line 1857 "pdfdoc/glyphlist.txt"
    {"finalkafqamatshebrew","05DA 05B8"},
#line 479 "pdfdoc/glyphlist.txt"
    {"Pcircle","24C5"},
#line 536 "pdfdoc/glyphlist.txt"
    {"SF260000","255D"},
#line 2465 "pdfdoc/glyphlist.txt"
    {"l","006C"},
#line 253 "pdfdoc/glyphlist.txt"
    {"H18551","25AB"},
#line 1807 "pdfdoc/glyphlist.txt"
    {"eukorean","3161"},
#line 1765 "pdfdoc/glyphlist.txt"
    {"eokorean","3153"},
#line 1704 "pdfdoc/glyphlist.txt"
    {"ehiragana","3048"},
#line 1174 "pdfdoc/glyphlist.txt"
    {"asciitilde","007E"},
#line 1546 "pdfdoc/glyphlist.txt"
    {"dargahebrew","05A7"},
#line 1597 "pdfdoc/glyphlist.txt"
    {"delta","03B4"},
#line 1107 "pdfdoc/glyphlist.txt"
    {"angleleft","2329"},
#line 1854 "pdfdoc/glyphlist.txt"
    {"finalkafdageshhebrew","FB3A"},
#line 2295 "pdfdoc/glyphlist.txt"
    {"invcircle","25D9"},
#line 125 "pdfdoc/glyphlist.txt"
    {"Delta","2206"},
#line 2712 "pdfdoc/glyphlist.txt"
    {"nakatakanahalfwidth","FF85"},
#line 2829 "pdfdoc/glyphlist.txt"
    {"nukatakanahalfwidth","FF87"},
#line 2790 "pdfdoc/glyphlist.txt"
    {"nokatakanahalfwidth","FF89"},
#line 2726 "pdfdoc/glyphlist.txt"
    {"nekatakanahalfwidth","FF88"},
#line 586 "pdfdoc/glyphlist.txt"
    {"Ssmall","F773"},
#line 2749 "pdfdoc/glyphlist.txt"
    {"nikatakanahalfwidth","FF86"},
#line 2146 "pdfdoc/glyphlist.txt"
    {"holam","05B9"},
#line 750 "pdfdoc/glyphlist.txt"
    {"Zsmall","F77A"},
#line 2044 "pdfdoc/glyphlist.txt"
    {"hakatakana","30CF"},
#line 2170 "pdfdoc/glyphlist.txt"
    {"hukatakana","30D5"},
#line 695 "pdfdoc/glyphlist.txt"
    {"Wsmall","F777"},
#line 670 "pdfdoc/glyphlist.txt"
    {"Usmall","F775"},
#line 2144 "pdfdoc/glyphlist.txt"
    {"hokatakana","30DB"},
#line 2719 "pdfdoc/glyphlist.txt"
    {"ncircle","24DD"},
#line 2114 "pdfdoc/glyphlist.txt"
    {"hekatakana","30D8"},
#line 2256 "pdfdoc/glyphlist.txt"
    {"igrave","00EC"},
#line 2129 "pdfdoc/glyphlist.txt"
    {"hikatakana","30D2"},
#line 80 "pdfdoc/glyphlist.txt"
    {"Bsmall","F762"},
#line 138 "pdfdoc/glyphlist.txt"
    {"Dsmall","F764"},
#line 1858 "pdfdoc/glyphlist.txt"
    {"finalkafsheva","05DA 05B0"},
#line 376 "pdfdoc/glyphlist.txt"
    {"Lsmall","F76C"},
#line 514 "pdfdoc/glyphlist.txt"
    {"Rsmall","F772"},
#line 407 "pdfdoc/glyphlist.txt"
    {"Nsmall","F76E"},
#line 2480 "pdfdoc/glyphlist.txt"
    {"lamarabic","0644"},
#line 387 "pdfdoc/glyphlist.txt"
    {"Msmall","F76D"},
#line 1803 "pdfdoc/glyphlist.txt"
    {"etnahtafoukhlefthebrew","0591"},
#line 107 "pdfdoc/glyphlist.txt"
    {"Circumflexsmall","F6F6"},
#line 326 "pdfdoc/glyphlist.txt"
    {"Jsmall","F76A"},
#line 91 "pdfdoc/glyphlist.txt"
    {"Ccircle","24B8"},
#line 2550 "pdfdoc/glyphlist.txt"
    {"longs","017F"},
#line 1719 "pdfdoc/glyphlist.txt"
    {"eighthangzhou","3028"},
#line 2734 "pdfdoc/glyphlist.txt"
    {"nhiragana","3093"},
#line 467 "pdfdoc/glyphlist.txt"
    {"Oslash","00D8"},
#line 1108 "pdfdoc/glyphlist.txt"
    {"angleright","232A"},
#line 495 "pdfdoc/glyphlist.txt"
    {"Qsmall","F771"},
#line 313 "pdfdoc/glyphlist.txt"
    {"Ismall","F769"},
#line 2310 "pdfdoc/glyphlist.txt"
    {"istroke","0268"},
#line 220 "pdfdoc/glyphlist.txt"
    {"Fsmall","F766"},
#line 2816 "pdfdoc/glyphlist.txt"
    {"notparallel","2226"},
#line 543 "pdfdoc/glyphlist.txt"
    {"SF400000","2569"},
#line 723 "pdfdoc/glyphlist.txt"
    {"Ysmall","F779"},
#line 1499 "pdfdoc/glyphlist.txt"
    {"d","0064"},
#line 270 "pdfdoc/glyphlist.txt"
    {"Hsmall","F768"},
#line 1804 "pdfdoc/glyphlist.txt"
    {"etnahtahebrew","0591"},
#line 1543 "pdfdoc/glyphlist.txt"
    {"dammatanaltonearabic","064C"},
#line 2735 "pdfdoc/glyphlist.txt"
    {"nhookleft","0272"},
#line 468 "pdfdoc/glyphlist.txt"
    {"Oslashacute","01FE"},
#line 2510 "pdfdoc/glyphlist.txt"
    {"lcommaaccent","013C"},
#line 1179 "pdfdoc/glyphlist.txt"
    {"asmallkatakana","30A1"},
#line 2188 "pdfdoc/glyphlist.txt"
    {"icircle","24D8"},
#line 249 "pdfdoc/glyphlist.txt"
    {"Gstroke","01E4"},
#line 1180 "pdfdoc/glyphlist.txt"
    {"asmallkatakanahalfwidth","FF67"},
#line 491 "pdfdoc/glyphlist.txt"
    {"Psmall","F770"},
#line 340 "pdfdoc/glyphlist.txt"
    {"Kcircle","24C0"},
#line 230 "pdfdoc/glyphlist.txt"
    {"Gcircle","24BC"},
#line 2292 "pdfdoc/glyphlist.txt"
    {"intersection","2229"},
#line 2259 "pdfdoc/glyphlist.txt"
    {"ihiragana","3044"},
#line 676 "pdfdoc/glyphlist.txt"
    {"V","0056"},
#line 520 "pdfdoc/glyphlist.txt"
    {"SF030000","2510"},
#line 2532 "pdfdoc/glyphlist.txt"
    {"ll","F6C0"},
#line 1151 "pdfdoc/glyphlist.txt"
    {"arrowleft","2190"},
#line 681 "pdfdoc/glyphlist.txt"
    {"Vhook","01B2"},
#line 359 "pdfdoc/glyphlist.txt"
    {"Lambda","039B"},
#line 533 "pdfdoc/glyphlist.txt"
    {"SF230000","2563"},
#line 1578 "pdfdoc/glyphlist.txt"
    {"ddalarabic","0688"},
#line 1191 "pdfdoc/glyphlist.txt"
    {"atilde","00E3"},
#line 2056 "pdfdoc/glyphlist.txt"
    {"hangulfiller","3164"},
#line 1155 "pdfdoc/glyphlist.txt"
    {"arrowleftwhite","21E6"},
#line 18 "pdfdoc/glyphlist.txt"
    {"A","0041"},
#line 673 "pdfdoc/glyphlist.txt"
    {"Utilde","0168"},
#line 549 "pdfdoc/glyphlist.txt"
    {"SF460000","2568"},
#line 1792 "pdfdoc/glyphlist.txt"
    {"esmallkatakana","30A7"},
#line 437 "pdfdoc/glyphlist.txt"
    {"Ograve","00D2"},
#line 1194 "pdfdoc/glyphlist.txt"
    {"aturned","0250"},
#line 556 "pdfdoc/glyphlist.txt"
    {"SF530000","256B"},
#line 1523 "pdfdoc/glyphlist.txt"
    {"dalethebrew","05D3"},
#line 19 "pdfdoc/glyphlist.txt"
    {"AE","00C6"},
#line 1793 "pdfdoc/glyphlist.txt"
    {"esmallkatakanahalfwidth","FF6A"},
#line 408 "pdfdoc/glyphlist.txt"
    {"Ntilde","00D1"},
#line 1986 "pdfdoc/glyphlist.txt"
    {"gimelhebrew","05D2"},
#line 1160 "pdfdoc/glyphlist.txt"
    {"arrowrightwhite","21E8"},
#line 674 "pdfdoc/glyphlist.txt"
    {"Utildeacute","1E78"},
#line 2104 "pdfdoc/glyphlist.txt"
    {"hehfinalalttwoarabic","FEEA"},
#line 388 "pdfdoc/glyphlist.txt"
    {"Mturned","019C"},
#line 110 "pdfdoc/glyphlist.txt"
    {"Csmall","F763"},
#line 1574 "pdfdoc/glyphlist.txt"
    {"ddabengali","09A1"},
#line 1608 "pdfdoc/glyphlist.txt"
    {"diamond","2666"},
#line 2045 "pdfdoc/glyphlist.txt"
    {"hakatakanahalfwidth","FF8A"},
#line 2171 "pdfdoc/glyphlist.txt"
    {"hukatakanahalfwidth","FF8C"},
#line 2556 "pdfdoc/glyphlist.txt"
    {"lslash","0142"},
#line 1156 "pdfdoc/glyphlist.txt"
    {"arrowright","2192"},
#line 315 "pdfdoc/glyphlist.txt"
    {"Itilde","0128"},
#line 1763 "pdfdoc/glyphlist.txt"
    {"enspace","2002"},
#line 2145 "pdfdoc/glyphlist.txt"
    {"hokatakanahalfwidth","FF8E"},
#line 2107 "pdfdoc/glyphlist.txt"
    {"hehhamzaaboveisolatedarabic","FBA4"},
#line 2115 "pdfdoc/glyphlist.txt"
    {"hekatakanahalfwidth","FF8D"},
#line 2130 "pdfdoc/glyphlist.txt"
    {"hikatakanahalfwidth","FF8B"},
#line 724 "pdfdoc/glyphlist.txt"
    {"Ytilde","1EF8"},
#line 2089 "pdfdoc/glyphlist.txt"
    {"hcircle","24D7"},
#line 519 "pdfdoc/glyphlist.txt"
    {"SF020000","2514"},
#line 2106 "pdfdoc/glyphlist.txt"
    {"hehhamzaabovefinalarabic","FBA5"},
#line 1154 "pdfdoc/glyphlist.txt"
    {"arrowleftoverright","21C6"},
#line 792 "pdfdoc/glyphlist.txt"
    {"adeva","0905"},
#line 32 "pdfdoc/glyphlist.txt"
    {"Acaron","01CD"},
#line 421 "pdfdoc/glyphlist.txt"
    {"Ocircle","24C4"},
#line 1800 "pdfdoc/glyphlist.txt"
    {"etilde","1EBD"},
#line 532 "pdfdoc/glyphlist.txt"
    {"SF220000","2555"},
#line 1806 "pdfdoc/glyphlist.txt"
    {"eturned","01DD"},
#line 1502 "pdfdoc/glyphlist.txt"
    {"dadarabic","0636"},
#line 555 "pdfdoc/glyphlist.txt"
    {"SF520000","2553"},
#line 1534 "pdfdoc/glyphlist.txt"
    {"daletsegol","05D3 05B6"},
#line 1973 "pdfdoc/glyphlist.txt"
    {"ghemiddlehookcyrillic","0495"},
#line 354 "pdfdoc/glyphlist.txt"
    {"Ksmall","F76B"},
#line 247 "pdfdoc/glyphlist.txt"
    {"Gsmall","F767"},
#line 471 "pdfdoc/glyphlist.txt"
    {"Ostrokeacute","01FE"},
#line 447 "pdfdoc/glyphlist.txt"
    {"Ohorntilde","1EE0"},
#line 2148 "pdfdoc/glyphlist.txt"
    {"holam26","05B9"},
#line 2307 "pdfdoc/glyphlist.txt"
    {"ismallkatakana","30A3"},
#line 1692 "pdfdoc/glyphlist.txt"
    {"edeva","090F"},
#line 2825 "pdfdoc/glyphlist.txt"
    {"ntilde","00F1"},
#line 2308 "pdfdoc/glyphlist.txt"
    {"ismallkatakanahalfwidth","FF68"},
#line 463 "pdfdoc/glyphlist.txt"
    {"Oneroman","2160"},
#line 539 "pdfdoc/glyphlist.txt"
    {"SF360000","255E"},
#line 1756 "pdfdoc/glyphlist.txt"
    {"endash","2013"},
#line 1661 "pdfdoc/glyphlist.txt"
    {"dz","01F3"},
#line 576 "pdfdoc/glyphlist.txt"
    {"Shaarmenian","0547"},
#line 140 "pdfdoc/glyphlist.txt"
    {"Dz","01F2"},
#line 574 "pdfdoc/glyphlist.txt"
    {"Seharmenian","054D"},
#line 743 "pdfdoc/glyphlist.txt"
    {"Zhearmenian","053A"},
#line 1921 "pdfdoc/glyphlist.txt"
    {"fourteenparen","2481"},
#line 1675 "pdfdoc/glyphlist.txt"
    {"ecandragujarati","0A8D"},
#line 2525 "pdfdoc/glyphlist.txt"
    {"lezh","026E"},
#line 507 "pdfdoc/glyphlist.txt"
    {"Reharmenian","0550"},
#line 61 "pdfdoc/glyphlist.txt"
    {"Aring","00C5"},
#line 2174 "pdfdoc/glyphlist.txt"
    {"hv","0195"},
#line 546 "pdfdoc/glyphlist.txt"
    {"SF430000","2550"},
#line 1153 "pdfdoc/glyphlist.txt"
    {"arrowleftdblstroke","21CD"},
#line 1641 "pdfdoc/glyphlist.txt"
    {"dotaccent","02D9"},
#line 1749 "pdfdoc/glyphlist.txt"
    {"emdash","2014"},
#line 74 "pdfdoc/glyphlist.txt"
    {"Benarmenian","0532"},
#line 317 "pdfdoc/glyphlist.txt"
    {"Izhitsacyrillic","0474"},
#line 1110 "pdfdoc/glyphlist.txt"
    {"anoteleia","0387"},
#line 470 "pdfdoc/glyphlist.txt"
    {"Osmall","F76F"},
#line 2314 "pdfdoc/glyphlist.txt"
    {"itilde","0129"},
#line 2508 "pdfdoc/glyphlist.txt"
    {"lcircle","24DB"},
#line 385 "pdfdoc/glyphlist.txt"
    {"Menarmenian","0544"},
#line 1836 "pdfdoc/glyphlist.txt"
    {"feharmenian","0586"},
#line 213 "pdfdoc/glyphlist.txt"
    {"Feharmenian","0556"},
#line 2477 "pdfdoc/glyphlist.txt"
    {"lamalefisolatedarabic","FEFB"},
#line 1982 "pdfdoc/glyphlist.txt"
    {"gimarmenian","0563"},
#line 274 "pdfdoc/glyphlist.txt"
    {"I","0049"},
#line 1068 "pdfdoc/glyphlist.txt"
    {"akatakana","30A2"},
#line 306 "pdfdoc/glyphlist.txt"
    {"Iniarmenian","053B"},
#line 254 "pdfdoc/glyphlist.txt"
    {"H22073","25A1"},
#line 1680 "pdfdoc/glyphlist.txt"
    {"echarmenian","0565"},
#line 482 "pdfdoc/glyphlist.txt"
    {"Peharmenian","054A"},
#line 1137 "pdfdoc/glyphlist.txt"
    {"arrowdblboth","21D4"},
#line 1152 "pdfdoc/glyphlist.txt"
    {"arrowleftdbl","21D0"},
#line 2149 "pdfdoc/glyphlist.txt"
    {"holam32","05B9"},
#line 1517 "pdfdoc/glyphlist.txt"
    {"daletdagesh","FB33"},
#line 2147 "pdfdoc/glyphlist.txt"
    {"holam19","05B9"},
#line 545 "pdfdoc/glyphlist.txt"
    {"SF420000","2560"},
#line 1714 "pdfdoc/glyphlist.txt"
    {"eighteenparen","2485"},
#line 2244 "pdfdoc/glyphlist.txt"
    {"ideva","0907"},
#line 1984 "pdfdoc/glyphlist.txt"
    {"gimeldagesh","FB32"},
#line 60 "pdfdoc/glyphlist.txt"
    {"Aogonek","0104"},
#line 1931 "pdfdoc/glyphlist.txt"
    {"gadeva","0917"},
#line 755 "pdfdoc/glyphlist.txt"
    {"aadeva","0906"},
#line 1138 "pdfdoc/glyphlist.txt"
    {"arrowdbldown","21D3"},
#line 1197 "pdfdoc/glyphlist.txt"
    {"audeva","0914"},
#line 1619 "pdfdoc/glyphlist.txt"
    {"divide","00F7"},
#line 2326 "pdfdoc/glyphlist.txt"
    {"jadeva","091C"},
#line 1503 "pdfdoc/glyphlist.txt"
    {"dadeva","0926"},
#line 525 "pdfdoc/glyphlist.txt"
    {"SF080000","251C"},
#line 1055 "pdfdoc/glyphlist.txt"
    {"aideva","0910"},
#line 1920 "pdfdoc/glyphlist.txt"
    {"fourteencircle","246D"},
#line 1733 "pdfdoc/glyphlist.txt"
    {"ekatakana","30A8"},
#line 538 "pdfdoc/glyphlist.txt"
    {"SF280000","255B"},
#line 2772 "pdfdoc/glyphlist.txt"
    {"nineteenparen","2486"},
#line 250 "pdfdoc/glyphlist.txt"
    {"H","0048"},
#line 2551 "pdfdoc/glyphlist.txt"
    {"lowlinecenterline","FE4E"},
#line 1220 "pdfdoc/glyphlist.txt"
    {"bar","007C"},
#line 2276 "pdfdoc/glyphlist.txt"
    {"ilde","02DC"},
#line 237 "pdfdoc/glyphlist.txt"
    {"Ghemiddlehookcyrillic","0494"},
#line 1826 "pdfdoc/glyphlist.txt"
    {"fadeva","095E"},
#line 96 "pdfdoc/glyphlist.txt"
    {"Chaarmenian","0549"},
#line 4119 "pdfdoc/glyphlist.txt"
    {"x","0078"},
#line 2167 "pdfdoc/glyphlist.txt"
    {"hturned","0265"},
#line 473 "pdfdoc/glyphlist.txt"
    {"Otilde","00D5"},
#line 1139 "pdfdoc/glyphlist.txt"
    {"arrowdblleft","21D0"},
#line 4126 "pdfdoc/glyphlist.txt"
    {"xi","03BE"},
#line 411 "pdfdoc/glyphlist.txt"
    {"O","004F"},
#line 1140 "pdfdoc/glyphlist.txt"
    {"arrowdblright","21D2"},
#line 1287 "pdfdoc/glyphlist.txt"
    {"braceex","F8F4"},
#line 2001 "pdfdoc/glyphlist.txt"
    {"gparen","24A2"},
#line 2321 "pdfdoc/glyphlist.txt"
    {"izhitsacyrillic","0475"},
#line 474 "pdfdoc/glyphlist.txt"
    {"Otildeacute","1E4C"},
#line 1117 "pdfdoc/glyphlist.txt"
    {"aparen","249C"},
#line 2283 "pdfdoc/glyphlist.txt"
    {"increment","2206"},
#line 2349 "pdfdoc/glyphlist.txt"
    {"jparen","24A5"},
#line 1655 "pdfdoc/glyphlist.txt"
    {"dparen","249F"},
#line 2777 "pdfdoc/glyphlist.txt"
    {"nkatakana","30F3"},
#line 1250 "pdfdoc/glyphlist.txt"
    {"bhook","0253"},
#line 2150 "pdfdoc/glyphlist.txt"
    {"holamhebrew","05B9"},
#line 2198 "pdfdoc/glyphlist.txt"
    {"ideographiccomma","3001"},
#line 1634 "pdfdoc/glyphlist.txt"
    {"dollarinferior","F6E3"},
#line 1217 "pdfdoc/glyphlist.txt"
    {"bahiragana","3070"},
#line 406 "pdfdoc/glyphlist.txt"
    {"Nowarmenian","0546"},
#line 1324 "pdfdoc/glyphlist.txt"
    {"buhiragana","3076"},
#line 2285 "pdfdoc/glyphlist.txt"
    {"iniarmenian","056B"},
#line 2210 "pdfdoc/glyphlist.txt"
    {"ideographichighcircle","32A4"},
#line 1239 "pdfdoc/glyphlist.txt"
    {"bet","05D1"},
#line 2201 "pdfdoc/glyphlist.txt"
    {"ideographiccorrectcircle","32A3"},
#line 1283 "pdfdoc/glyphlist.txt"
    {"bohiragana","307C"},
#line 2202 "pdfdoc/glyphlist.txt"
    {"ideographicearthparen","322F"},
#line 1232 "pdfdoc/glyphlist.txt"
    {"behiragana","3079"},
#line 343 "pdfdoc/glyphlist.txt"
    {"Keharmenian","0554"},
#line 1623 "pdfdoc/glyphlist.txt"
    {"dkshade","2593"},
#line 1159 "pdfdoc/glyphlist.txt"
    {"arrowrightoverleft","21C4"},
#line 1713 "pdfdoc/glyphlist.txt"
    {"eighteencircle","2471"},
#line 1251 "pdfdoc/glyphlist.txt"
    {"bihiragana","3073"},
#line 1925 "pdfdoc/glyphlist.txt"
    {"fparen","24A1"},
#line 2196 "pdfdoc/glyphlist.txt"
    {"ideographiccentrecircle","32A5"},
#line 2193 "pdfdoc/glyphlist.txt"
    {"ideographfirecircle","328B"},
#line 1240 "pdfdoc/glyphlist.txt"
    {"beta","03B2"},
#line 20 "pdfdoc/glyphlist.txt"
    {"AEacute","01FC"},
#line 2224 "pdfdoc/glyphlist.txt"
    {"ideographicresourceparen","323E"},
#line 2222 "pdfdoc/glyphlist.txt"
    {"ideographicreachparen","3243"},
#line 2241 "pdfdoc/glyphlist.txt"
    {"ideographsuncircle","3290"},
#line 2239 "pdfdoc/glyphlist.txt"
    {"ideographmooncircle","328A"},
#line 1246 "pdfdoc/glyphlist.txt"
    {"bhabengali","09AD"},
#line 2223 "pdfdoc/glyphlist.txt"
    {"ideographicrepresentparen","3239"},
#line 344 "pdfdoc/glyphlist.txt"
    {"Kenarmenian","053F"},
#line 337 "pdfdoc/glyphlist.txt"
    {"Kaverticalstrokecyrillic","049C"},
#line 2200 "pdfdoc/glyphlist.txt"
    {"ideographiccongratulationparen","3237"},
#line 2707 "pdfdoc/glyphlist.txt"
    {"nadeva","0928"},
#line 2199 "pdfdoc/glyphlist.txt"
    {"ideographiccommaleft","FF64"},
#line 2238 "pdfdoc/glyphlist.txt"
    {"ideographmetalcircle","328E"},
#line 2203 "pdfdoc/glyphlist.txt"
    {"ideographicenterpriseparen","323D"},
#line 524 "pdfdoc/glyphlist.txt"
    {"SF070000","2534"},
#line 1771 "pdfdoc/glyphlist.txt"
    {"eparen","24A0"},
#line 2273 "pdfdoc/glyphlist.txt"
    {"ikatakana","30A4"},
#line 2242 "pdfdoc/glyphlist.txt"
    {"ideographwatercircle","328C"},
#line 2192 "pdfdoc/glyphlist.txt"
    {"ideographearthcircle","328F"},
#line 2225 "pdfdoc/glyphlist.txt"
    {"ideographicrightcircle","32A8"},
#line 537 "pdfdoc/glyphlist.txt"
    {"SF270000","255C"},
#line 2771 "pdfdoc/glyphlist.txt"
    {"nineteencircle","2472"},
#line 1951 "pdfdoc/glyphlist.txt"
    {"gdot","0121"},
#line 736 "pdfdoc/glyphlist.txt"
    {"Zdot","017B"},
#line 2216 "pdfdoc/glyphlist.txt"
    {"ideographicmedicinecircle","32A9"},
#line 2240 "pdfdoc/glyphlist.txt"
    {"ideographnamecircle","3294"},
#line 1766 "pdfdoc/glyphlist.txt"
    {"eopen","025B"},
#line 677 "pdfdoc/glyphlist.txt"
    {"Vcircle","24CB"},
#line 2481 "pdfdoc/glyphlist.txt"
    {"lambda","03BB"},
#line 2211 "pdfdoc/glyphlist.txt"
    {"ideographiciterationmark","3005"},
#line 241 "pdfdoc/glyphlist.txt"
    {"Gimarmenian","0533"},
#line 365 "pdfdoc/glyphlist.txt"
    {"Ldot","013F"},
#line 2233 "pdfdoc/glyphlist.txt"
    {"ideographicsunparen","3230"},
#line 2226 "pdfdoc/glyphlist.txt"
    {"ideographicsecretcircle","3299"},
#line 1229 "pdfdoc/glyphlist.txt"
    {"beharabic","0628"},
#line 136 "pdfdoc/glyphlist.txt"
    {"Dotaccentsmall","F6F7"},
#line 1312 "pdfdoc/glyphlist.txt"
    {"breve","02D8"},
#line 2228 "pdfdoc/glyphlist.txt"
    {"ideographicsocietyparen","3233"},
#line 2234 "pdfdoc/glyphlist.txt"
    {"ideographicsuperviseparen","323C"},
#line 1091 "pdfdoc/glyphlist.txt"
    {"alpha","03B1"},
#line 51 "pdfdoc/glyphlist.txt"
    {"Agrave","00C0"},
#line 1518 "pdfdoc/glyphlist.txt"
    {"daletdageshhebrew","FB33"},
#line 1654 "pdfdoc/glyphlist.txt"
    {"downtackmod","02D5"},
#line 291 "pdfdoc/glyphlist.txt"
    {"Idot","0130"},
#line 2263 "pdfdoc/glyphlist.txt"
    {"iideva","0908"},
#line 1985 "pdfdoc/glyphlist.txt"
    {"gimeldageshhebrew","FB32"},
#line 2822 "pdfdoc/glyphlist.txt"
    {"nparen","24A9"},
#line 551 "pdfdoc/glyphlist.txt"
    {"SF480000","2565"},
#line 475 "pdfdoc/glyphlist.txt"
    {"Otildedieresis","1E4E"},
#line 41 "pdfdoc/glyphlist.txt"
    {"Acute","F6C9"},
#line 2821 "pdfdoc/glyphlist.txt"
    {"nowarmenian","0576"},
#line 1694 "pdfdoc/glyphlist.txt"
    {"edot","0117"},
#line 1650 "pdfdoc/glyphlist.txt"
    {"dottedcircle","25CC"},
#line 3031 "pdfdoc/glyphlist.txt"
    {"pe","05E4"},
#line 1280 "pdfdoc/glyphlist.txt"
    {"block","2588"},
#line 3082 "pdfdoc/glyphlist.txt"
    {"pi","03C0"},
#line 3068 "pdfdoc/glyphlist.txt"
    {"phi","03C6"},
#line 2231 "pdfdoc/glyphlist.txt"
    {"ideographicstockparen","3231"},
#line 33 "pdfdoc/glyphlist.txt"
    {"Acircle","24B6"},
#line 2212 "pdfdoc/glyphlist.txt"
    {"ideographiclaborcircle","3298"},
#line 2194 "pdfdoc/glyphlist.txt"
    {"ideographicallianceparen","323F"},
#line 2215 "pdfdoc/glyphlist.txt"
    {"ideographiclowcircle","32A6"},
#line 2197 "pdfdoc/glyphlist.txt"
    {"ideographicclose","3006"},
#line 2214 "pdfdoc/glyphlist.txt"
    {"ideographicleftcircle","32A7"},
#line 2204 "pdfdoc/glyphlist.txt"
    {"ideographicexcellentcircle","329D"},
#line 2213 "pdfdoc/glyphlist.txt"
    {"ideographiclaborparen","3238"},
#line 2473 "pdfdoc/glyphlist.txt"
    {"lamalefhamzaabovefinalarabic","FEF8"},
#line 2474 "pdfdoc/glyphlist.txt"
    {"lamalefhamzaaboveisolatedarabic","FEF7"},
#line 2304 "pdfdoc/glyphlist.txt"
    {"iparen","24A4"},
#line 1278 "pdfdoc/glyphlist.txt"
    {"blank","2423"},
#line 1326 "pdfdoc/glyphlist.txt"
    {"bullet","2022"},
#line 3069 "pdfdoc/glyphlist.txt"
    {"phi1","03D5"},
#line 684 "pdfdoc/glyphlist.txt"
    {"Vsmall","F776"},
#line 569 "pdfdoc/glyphlist.txt"
    {"Scircumflex","015C"},
#line 1949 "pdfdoc/glyphlist.txt"
    {"gcircumflex","011D"},
#line 735 "pdfdoc/glyphlist.txt"
    {"Zcircumflex","1E90"},
#line 776 "pdfdoc/glyphlist.txt"
    {"acircumflex","00E2"},
#line 689 "pdfdoc/glyphlist.txt"
    {"Wcircumflex","0174"},
#line 627 "pdfdoc/glyphlist.txt"
    {"Ucircumflex","00DB"},
#line 3078 "pdfdoc/glyphlist.txt"
    {"phook","01A5"},
#line 2332 "pdfdoc/glyphlist.txt"
    {"jcircumflex","0135"},
#line 780 "pdfdoc/glyphlist.txt"
    {"acircumflexhookabove","1EA9"},
#line 2554 "pdfdoc/glyphlist.txt"
    {"lozenge","25CA"},
#line 578 "pdfdoc/glyphlist.txt"
    {"Shchacyrillic","0429"},
#line 2235 "pdfdoc/glyphlist.txt"
    {"ideographicwaterparen","322C"},
#line 777 "pdfdoc/glyphlist.txt"
    {"acircumflexacute","1EA5"},
#line 2217 "pdfdoc/glyphlist.txt"
    {"ideographicmetalparen","322E"},
#line 2035 "pdfdoc/glyphlist.txt"
    {"hadeva","0939"},
#line 3131 "pdfdoc/glyphlist.txt"
    {"psi","03C8"},
#line 93 "pdfdoc/glyphlist.txt"
    {"Cdot","010A"},
#line 2987 "pdfdoc/glyphlist.txt"
    {"pahiragana","3071"},
#line 3135 "pdfdoc/glyphlist.txt"
    {"puhiragana","3077"},
#line 1149 "pdfdoc/glyphlist.txt"
    {"arrowheadupmod","02C4"},
#line 3109 "pdfdoc/glyphlist.txt"
    {"pohiragana","307D"},
#line 3042 "pdfdoc/glyphlist.txt"
    {"pehiragana","307A"},
#line 1148 "pdfdoc/glyphlist.txt"
    {"arrowheadrightmod","02C3"},
#line 3095 "pdfdoc/glyphlist.txt"
    {"pihiragana","3074"},
#line 322 "pdfdoc/glyphlist.txt"
    {"Jcircumflex","0134"},
#line 3019 "pdfdoc/glyphlist.txt"
    {"patah","05B7"},
#line 3020 "pdfdoc/glyphlist.txt"
    {"patah11","05B7"},
#line 550 "pdfdoc/glyphlist.txt"
    {"SF470000","2564"},
#line 3064 "pdfdoc/glyphlist.txt"
    {"phabengali","09AB"},
#line 283 "pdfdoc/glyphlist.txt"
    {"Icircumflex","00CE"},
#line 1219 "pdfdoc/glyphlist.txt"
    {"bakatakana","30D0"},
#line 1325 "pdfdoc/glyphlist.txt"
    {"bukatakana","30D6"},
#line 541 "pdfdoc/glyphlist.txt"
    {"SF380000","255A"},
#line 1284 "pdfdoc/glyphlist.txt"
    {"bokatakana","30DC"},
#line 709 "pdfdoc/glyphlist.txt"
    {"Ycircumflex","0176"},
#line 1237 "pdfdoc/glyphlist.txt"
    {"bekatakana","30D9"},
#line 1252 "pdfdoc/glyphlist.txt"
    {"bikatakana","30D3"},
#line 263 "pdfdoc/glyphlist.txt"
    {"Hcircumflex","0124"},
#line 781 "pdfdoc/glyphlist.txt"
    {"acircumflextilde","1EAB"},
#line 2562 "pdfdoc/glyphlist.txt"
    {"lvocalicdeva","090C"},
#line 1683 "pdfdoc/glyphlist.txt"
    {"ecircumflex","00EA"},
#line 3022 "pdfdoc/glyphlist.txt"
    {"patah2a","05B7"},
#line 779 "pdfdoc/glyphlist.txt"
    {"acircumflexgrave","1EA7"},
#line 1688 "pdfdoc/glyphlist.txt"
    {"ecircumflexhookabove","1EC3"},
#line 65 "pdfdoc/glyphlist.txt"
    {"Asmall","F761"},
#line 233 "pdfdoc/glyphlist.txt"
    {"Gdot","0120"},
#line 1684 "pdfdoc/glyphlist.txt"
    {"ecircumflexacute","1EBF"},
#line 3062 "pdfdoc/glyphlist.txt"
    {"peseta","20A7"},
#line 1918 "pdfdoc/glyphlist.txt"
    {"fourroman","2173"},
#line 2165 "pdfdoc/glyphlist.txt"
    {"hparen","24A3"},
#line 3037 "pdfdoc/glyphlist.txt"
    {"peharabic","067E"},
#line 219 "pdfdoc/glyphlist.txt"
    {"Fourroman","2163"},
#line 2291 "pdfdoc/glyphlist.txt"
    {"integraltp","2320"},
#line 2290 "pdfdoc/glyphlist.txt"
    {"integraltop","2320"},
#line 401 "pdfdoc/glyphlist.txt"
    {"Nineroman","2168"},
#line 466 "pdfdoc/glyphlist.txt"
    {"Oopen","0186"},
#line 1942 "pdfdoc/glyphlist.txt"
    {"gammasuperior","02E0"},
#line 252 "pdfdoc/glyphlist.txt"
    {"H18543","25AA"},
#line 3554 "pdfdoc/glyphlist.txt"
    {"six","0036"},
#line 685 "pdfdoc/glyphlist.txt"
    {"Vtilde","1E7C"},
#line 1689 "pdfdoc/glyphlist.txt"
    {"ecircumflextilde","1EC5"},
#line 529 "pdfdoc/glyphlist.txt"
    {"SF190000","2561"},
#line 2561 "pdfdoc/glyphlist.txt"
    {"lvocalicbengali","098C"},
#line 3648 "pdfdoc/glyphlist.txt"
    {"sun","263C"},
#line 526 "pdfdoc/glyphlist.txt"
    {"SF090000","2524"},
#line 1813 "pdfdoc/glyphlist.txt"
    {"exclamarmenian","055C"},
#line 1687 "pdfdoc/glyphlist.txt"
    {"ecircumflexgrave","1EC1"},
#line 587 "pdfdoc/glyphlist.txt"
    {"Stigmagreek","03DA"},
#line 516 "pdfdoc/glyphlist.txt"
    {"Rsmallinvertedsuperior","02B6"},
#line 1761 "pdfdoc/glyphlist.txt"
    {"enghecyrillic","04A5"},
#line 3414 "pdfdoc/glyphlist.txt"
    {"scaron","0161"},
#line 1972 "pdfdoc/glyphlist.txt"
    {"ghainmedialarabic","FED0"},
#line 2468 "pdfdoc/glyphlist.txt"
    {"ladeva","0932"},
#line 92 "pdfdoc/glyphlist.txt"
    {"Ccircumflex","0108"},
#line 3376 "pdfdoc/glyphlist.txt"
    {"s","0073"},
#line 3532 "pdfdoc/glyphlist.txt"
    {"shook","0282"},
#line 3519 "pdfdoc/glyphlist.txt"
    {"shin","05E9"},
#line 540 "pdfdoc/glyphlist.txt"
    {"SF370000","255F"},
#line 3387 "pdfdoc/glyphlist.txt"
    {"sahiragana","3055"},
#line 3643 "pdfdoc/glyphlist.txt"
    {"suhiragana","3059"},
#line 3587 "pdfdoc/glyphlist.txt"
    {"sohiragana","305D"},
#line 1729 "pdfdoc/glyphlist.txt"
    {"eightsuperior","2078"},
#line 1227 "pdfdoc/glyphlist.txt"
    {"because","2235"},
#line 3445 "pdfdoc/glyphlist.txt"
    {"sehiragana","305B"},
#line 3537 "pdfdoc/glyphlist.txt"
    {"sihiragana","3057"},
#line 646 "pdfdoc/glyphlist.txt"
    {"Uhornacute","1EE8"},
#line 2189 "pdfdoc/glyphlist.txt"
    {"icircumflex","00EE"},
#line 3482 "pdfdoc/glyphlist.txt"
    {"shabengali","09B6"},
#line 2791 "pdfdoc/glyphlist.txt"
    {"nonbreakingspace","00A0"},
#line 3557 "pdfdoc/glyphlist.txt"
    {"sixcircle","2465"},
#line 3431 "pdfdoc/glyphlist.txt"
    {"seenarabic","0633"},
#line 66 "pdfdoc/glyphlist.txt"
    {"Atilde","00C3"},
#line 1321 "pdfdoc/glyphlist.txt"
    {"bstroke","0180"},
#line 231 "pdfdoc/glyphlist.txt"
    {"Gcircumflex","011C"},
#line 3556 "pdfdoc/glyphlist.txt"
    {"sixbengali","09EC"},
#line 3391 "pdfdoc/glyphlist.txt"
    {"samekh","05E1"},
#line 2993 "pdfdoc/glyphlist.txt"
    {"paragraph","00B6"},
#line 2769 "pdfdoc/glyphlist.txt"
    {"nineroman","2178"},
#line 3533 "pdfdoc/glyphlist.txt"
    {"sigma","03C3"},
#line 2555 "pdfdoc/glyphlist.txt"
    {"lparen","24A7"},
#line 1223 "pdfdoc/glyphlist.txt"
    {"bcircle","24D1"},
#line 3534 "pdfdoc/glyphlist.txt"
    {"sigma1","03C2"},
#line 3508 "pdfdoc/glyphlist.txt"
    {"sheva","05B0"},
#line 2096 "pdfdoc/glyphlist.txt"
    {"heartsuitblack","2665"},
#line 1591 "pdfdoc/glyphlist.txt"
    {"dehihebrew","05AD"},
#line 3594 "pdfdoc/glyphlist.txt"
    {"sosothai","0E0B"},
#line 1218 "pdfdoc/glyphlist.txt"
    {"bahtthai","0E3F"},
#line 2237 "pdfdoc/glyphlist.txt"
    {"ideographiczero","3007"},
#line 3434 "pdfdoc/glyphlist.txt"
    {"seenmedialarabic","FEB4"},
#line 335 "pdfdoc/glyphlist.txt"
    {"Kappa","039A"},
#line 251 "pdfdoc/glyphlist.txt"
    {"H18533","25CF"},
#line 1922 "pdfdoc/glyphlist.txt"
    {"fourteenperiod","2495"},
#line 4122 "pdfdoc/glyphlist.txt"
    {"xcircle","24E7"},
#line 2989 "pdfdoc/glyphlist.txt"
    {"pakatakana","30D1"},
#line 3136 "pdfdoc/glyphlist.txt"
    {"pukatakana","30D7"},
#line 2097 "pdfdoc/glyphlist.txt"
    {"heartsuitwhite","2661"},
#line 1291 "pdfdoc/glyphlist.txt"
    {"braceleftmonospace","FF5B"},
#line 3555 "pdfdoc/glyphlist.txt"
    {"sixarabic","0666"},
#line 3114 "pdfdoc/glyphlist.txt"
    {"pokatakana","30DD"},
#line 3044 "pdfdoc/glyphlist.txt"
    {"pekatakana","30DA"},
#line 3096 "pdfdoc/glyphlist.txt"
    {"pikatakana","30D4"},
#line 2559 "pdfdoc/glyphlist.txt"
    {"ltshade","2591"},
#line 1130 "pdfdoc/glyphlist.txt"
    {"aringacute","01FB"},
#line 1288 "pdfdoc/glyphlist.txt"
    {"braceleft","007B"},
#line 3622 "pdfdoc/glyphlist.txt"
    {"ssabengali","09B7"},
#line 1289 "pdfdoc/glyphlist.txt"
    {"braceleftbt","F8F3"},
#line 2492 "pdfdoc/glyphlist.txt"
    {"lamhahinitialarabic","FCCA"},
#line 3509 "pdfdoc/glyphlist.txt"
    {"sheva115","05B0"},
#line 2564 "pdfdoc/glyphlist.txt"
    {"lvocalicvowelsigndeva","0962"},
#line 3392 "pdfdoc/glyphlist.txt"
    {"samekhdagesh","FB41"},
#line 2563 "pdfdoc/glyphlist.txt"
    {"lvocalicvowelsignbengali","09E2"},
#line 2511 "pdfdoc/glyphlist.txt"
    {"ldot","0140"},
#line 2090 "pdfdoc/glyphlist.txt"
    {"hcircumflex","0125"},
#line 3510 "pdfdoc/glyphlist.txt"
    {"sheva15","05B0"},
#line 422 "pdfdoc/glyphlist.txt"
    {"Ocircumflex","00D4"},
#line 1864 "pdfdoc/glyphlist.txt"
    {"finalpe","05E3"},
#line 3060 "pdfdoc/glyphlist.txt"
    {"perpendicular","22A5"},
#line 426 "pdfdoc/glyphlist.txt"
    {"Ocircumflexhookabove","1ED4"},
#line 1295 "pdfdoc/glyphlist.txt"
    {"braceright","007D"},
#line 552 "pdfdoc/glyphlist.txt"
    {"SF490000","2559"},
#line 423 "pdfdoc/glyphlist.txt"
    {"Ocircumflexacute","1ED0"},
#line 2111 "pdfdoc/glyphlist.txt"
    {"hehmedialaltonearabic","FBA9"},
#line 2154 "pdfdoc/glyphlist.txt"
    {"honokhukthai","0E2E"},
#line 584 "pdfdoc/glyphlist.txt"
    {"Smonospace","FF33"},
#line 1998 "pdfdoc/glyphlist.txt"
    {"gmonospace","FF47"},
#line 3423 "pdfdoc/glyphlist.txt"
    {"scommaaccent","0219"},
#line 749 "pdfdoc/glyphlist.txt"
    {"Zmonospace","FF3A"},
#line 2122 "pdfdoc/glyphlist.txt"
    {"hhooksuperior","02B1"},
#line 1094 "pdfdoc/glyphlist.txt"
    {"amonospace","FF41"},
#line 694 "pdfdoc/glyphlist.txt"
    {"Wmonospace","FF37"},
#line 1715 "pdfdoc/glyphlist.txt"
    {"eighteenperiod","2499"},
#line 658 "pdfdoc/glyphlist.txt"
    {"Umonospace","FF35"},
#line 3511 "pdfdoc/glyphlist.txt"
    {"sheva22","05B0"},
#line 2348 "pdfdoc/glyphlist.txt"
    {"jmonospace","FF4A"},
#line 1627 "pdfdoc/glyphlist.txt"
    {"dmonospace","FF44"},
#line 78 "pdfdoc/glyphlist.txt"
    {"Bmonospace","FF22"},
#line 135 "pdfdoc/glyphlist.txt"
    {"Dmonospace","FF24"},
#line 373 "pdfdoc/glyphlist.txt"
    {"Lmonospace","FF2C"},
#line 513 "pdfdoc/glyphlist.txt"
    {"Rmonospace","FF32"},
#line 3562 "pdfdoc/glyphlist.txt"
    {"sixhackarabic","0666"},
#line 405 "pdfdoc/glyphlist.txt"
    {"Nmonospace","FF2E"},
#line 1175 "pdfdoc/glyphlist.txt"
    {"asciitildemonospace","FF5E"},
#line 386 "pdfdoc/glyphlist.txt"
    {"Mmonospace","FF2D"},
#line 1296 "pdfdoc/glyphlist.txt"
    {"bracerightbt","F8FE"},
#line 428 "pdfdoc/glyphlist.txt"
    {"Ocircumflextilde","1ED6"},
#line 325 "pdfdoc/glyphlist.txt"
    {"Jmonospace","FF2A"},
#line 1167 "pdfdoc/glyphlist.txt"
    {"arrowupleft","2196"},
#line 1716 "pdfdoc/glyphlist.txt"
    {"eightgujarati","0AEE"},
#line 3438 "pdfdoc/glyphlist.txt"
    {"segol2c","05B6"},
#line 1894 "pdfdoc/glyphlist.txt"
    {"fmonospace","FF46"},
#line 494 "pdfdoc/glyphlist.txt"
    {"Qmonospace","FF31"},
#line 305 "pdfdoc/glyphlist.txt"
    {"Imonospace","FF29"},
#line 2773 "pdfdoc/glyphlist.txt"
    {"nineteenperiod","249A"},
#line 79 "pdfdoc/glyphlist.txt"
    {"Brevesmall","F6F4"},
#line 425 "pdfdoc/glyphlist.txt"
    {"Ocircumflexgrave","1ED2"},
#line 218 "pdfdoc/glyphlist.txt"
    {"Fmonospace","FF26"},
#line 318 "pdfdoc/glyphlist.txt"
    {"Izhitsadblgravecyrillic","0476"},
#line 722 "pdfdoc/glyphlist.txt"
    {"Ymonospace","FF39"},
#line 1096 "pdfdoc/glyphlist.txt"
    {"ampersandmonospace","FF06"},
#line 3580 "pdfdoc/glyphlist.txt"
    {"slong","017F"},
#line 267 "pdfdoc/glyphlist.txt"
    {"Hmonospace","FF28"},
#line 86 "pdfdoc/glyphlist.txt"
    {"Caronsmall","F6F5"},
#line 1751 "pdfdoc/glyphlist.txt"
    {"emonospace","FF45"},
#line 3388 "pdfdoc/glyphlist.txt"
    {"sakatakana","30B5"},
#line 3644 "pdfdoc/glyphlist.txt"
    {"sukatakana","30B9"},
#line 488 "pdfdoc/glyphlist.txt"
    {"Pmonospace","FF30"},
#line 3588 "pdfdoc/glyphlist.txt"
    {"sokatakana","30BD"},
#line 455 "pdfdoc/glyphlist.txt"
    {"Omegacyrillic","0460"},
#line 3446 "pdfdoc/glyphlist.txt"
    {"sekatakana","30BB"},
#line 3538 "pdfdoc/glyphlist.txt"
    {"sikatakana","30B7"},
#line 629 "pdfdoc/glyphlist.txt"
    {"Ucircumflexsmall","F7FB"},
#line 1889 "pdfdoc/glyphlist.txt"
    {"fiveroman","2174"},
#line 217 "pdfdoc/glyphlist.txt"
    {"Fiveroman","2164"},
#line 2486 "pdfdoc/glyphlist.txt"
    {"lamedhebrew","05DC"},
#line 1082 "pdfdoc/glyphlist.txt"
    {"alefmaddaabovefinalarabic","FE82"},
#line 1294 "pdfdoc/glyphlist.txt"
    {"braceleftvertical","FE37"},
#line 1081 "pdfdoc/glyphlist.txt"
    {"alefmaddaabovearabic","0622"},
#line 3029 "pdfdoc/glyphlist.txt"
    {"pcircle","24DF"},
#line 1260 "pdfdoc/glyphlist.txt"
    {"blackleftpointingtriangle","25C0"},
#line 1259 "pdfdoc/glyphlist.txt"
    {"blackleftpointingpointer","25C4"},
#line 3435 "pdfdoc/glyphlist.txt"
    {"segol","05B6"},
#line 1267 "pdfdoc/glyphlist.txt"
    {"blackrectangle","25AC"},
#line 284 "pdfdoc/glyphlist.txt"
    {"Icircumflexsmall","F7EE"},
#line 542 "pdfdoc/glyphlist.txt"
    {"SF390000","2554"},
#line 1301 "pdfdoc/glyphlist.txt"
    {"bracerightvertical","FE38"},
#line 2991 "pdfdoc/glyphlist.txt"
    {"palochkacyrillic","04C0"},
#line 680 "pdfdoc/glyphlist.txt"
    {"Vewarmenian","054E"},
#line 2781 "pdfdoc/glyphlist.txt"
    {"nmonospace","FF4E"},
#line 2796 "pdfdoc/glyphlist.txt"
    {"noonghunnaarabic","06BA"},
#line 3456 "pdfdoc/glyphlist.txt"
    {"seven","0037"},
#line 1269 "pdfdoc/glyphlist.txt"
    {"blackrightpointingtriangle","25B6"},
#line 2998 "pdfdoc/glyphlist.txt"
    {"parenleftex","F8EC"},
#line 2797 "pdfdoc/glyphlist.txt"
    {"noonghunnafinalarabic","FB9F"},
#line 1268 "pdfdoc/glyphlist.txt"
    {"blackrightpointingpointer","25BA"},
#line 2243 "pdfdoc/glyphlist.txt"
    {"ideographwoodcircle","328D"},
#line 3393 "pdfdoc/glyphlist.txt"
    {"samekhdageshhebrew","FB41"},
#line 1299 "pdfdoc/glyphlist.txt"
    {"bracerightsmall","FE5C"},
#line 108 "pdfdoc/glyphlist.txt"
    {"Cmonospace","FF23"},
#line 443 "pdfdoc/glyphlist.txt"
    {"Ohornacute","1EDA"},
#line 3000 "pdfdoc/glyphlist.txt"
    {"parenleftmonospace","FF08"},
#line 2252 "pdfdoc/glyphlist.txt"
    {"ieungaparenkorean","3215"},
#line 1862 "pdfdoc/glyphlist.txt"
    {"finalnun","05DF"},
#line 2333 "pdfdoc/glyphlist.txt"
    {"jcrossedtail","029D"},
#line 2995 "pdfdoc/glyphlist.txt"
    {"parenleft","0028"},
#line 2997 "pdfdoc/glyphlist.txt"
    {"parenleftbt","F8ED"},
#line 225 "pdfdoc/glyphlist.txt"
    {"Gammaafrican","0194"},
#line 1079 "pdfdoc/glyphlist.txt"
    {"alefhebrew","05D0"},
#line 1292 "pdfdoc/glyphlist.txt"
    {"braceleftsmall","FE5B"},
#line 2282 "pdfdoc/glyphlist.txt"
    {"imonospace","FF49"},
#line 2996 "pdfdoc/glyphlist.txt"
    {"parenleftaltonearabic","FD3E"},
#line 2322 "pdfdoc/glyphlist.txt"
    {"izhitsadblgravecyrillic","0477"},
#line 1172 "pdfdoc/glyphlist.txt"
    {"asciicircum","005E"},
#line 3407 "pdfdoc/glyphlist.txt"
    {"saraueeleftthai","F888"},
#line 1674 "pdfdoc/glyphlist.txt"
    {"ecandradeva","090D"},
#line 3008 "pdfdoc/glyphlist.txt"
    {"parenrightex","F8F7"},
#line 1618 "pdfdoc/glyphlist.txt"
    {"dittomark","3003"},
#line 350 "pdfdoc/glyphlist.txt"
    {"Kmonospace","FF2B"},
#line 244 "pdfdoc/glyphlist.txt"
    {"Gmonospace","FF27"},
#line 1740 "pdfdoc/glyphlist.txt"
    {"elevenparen","247E"},
#line 2499 "pdfdoc/glyphlist.txt"
    {"lammeeminitialarabic","FCCC"},
#line 3023 "pdfdoc/glyphlist.txt"
    {"patahhebrew","05B7"},
#line 3005 "pdfdoc/glyphlist.txt"
    {"parenright","0029"},
#line 2483 "pdfdoc/glyphlist.txt"
    {"lamed","05DC"},
#line 3512 "pdfdoc/glyphlist.txt"
    {"sheva2e","05B0"},
#line 3389 "pdfdoc/glyphlist.txt"
    {"sakatakanahalfwidth","FF7B"},
#line 3645 "pdfdoc/glyphlist.txt"
    {"sukatakanahalfwidth","FF7D"},
#line 3589 "pdfdoc/glyphlist.txt"
    {"sokatakanahalfwidth","FF7F"},
#line 3447 "pdfdoc/glyphlist.txt"
    {"sekatakanahalfwidth","FF7E"},
#line 246 "pdfdoc/glyphlist.txt"
    {"Gravesmall","F760"},
#line 3539 "pdfdoc/glyphlist.txt"
    {"sikatakanahalfwidth","FF7C"},
#line 2351 "pdfdoc/glyphlist.txt"
    {"k","006B"},
#line 1710 "pdfdoc/glyphlist.txt"
    {"eightcircle","2467"},
#line 3421 "pdfdoc/glyphlist.txt"
    {"scircle","24E2"},
#line 3506 "pdfdoc/glyphlist.txt"
    {"sheqel","20AA"},
#line 2498 "pdfdoc/glyphlist.txt"
    {"lammeemhahinitialarabic","FD88"},
#line 3007 "pdfdoc/glyphlist.txt"
    {"parenrightbt","F8F8"},
#line 2391 "pdfdoc/glyphlist.txt"
    {"kcaron","01E9"},
#line 1173 "pdfdoc/glyphlist.txt"
    {"asciicircummonospace","FF3E"},
#line 2425 "pdfdoc/glyphlist.txt"
    {"khook","0199"},
#line 1207 "pdfdoc/glyphlist.txt"
    {"ayin","05E2"},
#line 2408 "pdfdoc/glyphlist.txt"
    {"khaharabic","062E"},
#line 2140 "pdfdoc/glyphlist.txt"
    {"hmonospace","FF48"},
#line 56 "pdfdoc/glyphlist.txt"
    {"Alpha","0391"},
#line 1238 "pdfdoc/glyphlist.txt"
    {"benarmenian","0562"},
#line 2369 "pdfdoc/glyphlist.txt"
    {"kahiragana","304B"},
#line 2460 "pdfdoc/glyphlist.txt"
    {"kuhiragana","304F"},
#line 1330 "pdfdoc/glyphlist.txt"
    {"c","0063"},
#line 462 "pdfdoc/glyphlist.txt"
    {"Omonospace","FF2F"},
#line 2446 "pdfdoc/glyphlist.txt"
    {"kohiragana","3053"},
#line 3404 "pdfdoc/glyphlist.txt"
    {"saraileftthai","F885"},
#line 1097 "pdfdoc/glyphlist.txt"
    {"ampersandsmall","F726"},
#line 2397 "pdfdoc/glyphlist.txt"
    {"kehiragana","3051"},
#line 3571 "pdfdoc/glyphlist.txt"
    {"sixroman","2175"},
#line 4125 "pdfdoc/glyphlist.txt"
    {"xeharmenian","056D"},
#line 2428 "pdfdoc/glyphlist.txt"
    {"kihiragana","304D"},
#line 2484 "pdfdoc/glyphlist.txt"
    {"lameddagesh","FB3C"},
#line 1381 "pdfdoc/glyphlist.txt"
    {"chi","03C7"},
#line 2403 "pdfdoc/glyphlist.txt"
    {"khabengali","0996"},
#line 3004 "pdfdoc/glyphlist.txt"
    {"parenleftvertical","FE35"},
#line 2411 "pdfdoc/glyphlist.txt"
    {"khahmedialarabic","FEA8"},
#line 1344 "pdfdoc/glyphlist.txt"
    {"caron","02C7"},
#line 1863 "pdfdoc/glyphlist.txt"
    {"finalnunhebrew","05DF"},
#line 3014 "pdfdoc/glyphlist.txt"
    {"parenrightvertical","FE36"},
#line 1141 "pdfdoc/glyphlist.txt"
    {"arrowdblup","21D1"},
#line 1349 "pdfdoc/glyphlist.txt"
    {"ccaron","010D"},
#line 3021 "pdfdoc/glyphlist.txt"
    {"patah1d","05B7"},
#line 1391 "pdfdoc/glyphlist.txt"
    {"chook","0188"},
#line 2046 "pdfdoc/glyphlist.txt"
    {"halantgurmukhi","0A4D"},
#line 427 "pdfdoc/glyphlist.txt"
    {"Ocircumflexsmall","F7F4"},
#line 3011 "pdfdoc/glyphlist.txt"
    {"parenrightsmall","FE5A"},
#line 3006 "pdfdoc/glyphlist.txt"
    {"parenrightaltonearabic","FD3F"},
#line 1214 "pdfdoc/glyphlist.txt"
    {"badeva","092C"},
#line 1649 "pdfdoc/glyphlist.txt"
    {"dotmath","22C5"},
#line 2253 "pdfdoc/glyphlist.txt"
    {"ieungcirclekorean","3267"},
#line 1865 "pdfdoc/glyphlist.txt"
    {"finalpehebrew","05E3"},
#line 34 "pdfdoc/glyphlist.txt"
    {"Acircumflex","00C2"},
#line 2151 "pdfdoc/glyphlist.txt"
    {"holamnarrowhebrew","05B9"},
#line 1367 "pdfdoc/glyphlist.txt"
    {"chabengali","099B"},
#line 3436 "pdfdoc/glyphlist.txt"
    {"segol13","05B6"},
#line 38 "pdfdoc/glyphlist.txt"
    {"Acircumflexhookabove","1EA8"},
#line 3513 "pdfdoc/glyphlist.txt"
    {"shevahebrew","05B0"},
#line 2501 "pdfdoc/glyphlist.txt"
    {"lammeemkhahinitialarabic","FEDF FEE4 FEA8"},
#line 2994 "pdfdoc/glyphlist.txt"
    {"parallel","2225"},
#line 3001 "pdfdoc/glyphlist.txt"
    {"parenleftsmall","FE59"},
#line 35 "pdfdoc/glyphlist.txt"
    {"Acircumflexacute","1EA4"},
#line 1427 "pdfdoc/glyphlist.txt"
    {"comma","002C"},
#line 2542 "pdfdoc/glyphlist.txt"
    {"lmonospace","FF4C"},
#line 1120 "pdfdoc/glyphlist.txt"
    {"apple","F8FF"},
#line 2832 "pdfdoc/glyphlist.txt"
    {"nuktagujarati","0ABC"},
#line 1171 "pdfdoc/glyphlist.txt"
    {"arrowvertex","F8E6"},
#line 2798 "pdfdoc/glyphlist.txt"
    {"noonhehinitialarabic","FEE7 FEEC"},
#line 3442 "pdfdoc/glyphlist.txt"
    {"segoltahebrew","0592"},
#line 2846 "pdfdoc/glyphlist.txt"
    {"nyabengali","099E"},
#line 515 "pdfdoc/glyphlist.txt"
    {"Rsmallinverted","0281"},
#line 1285 "pdfdoc/glyphlist.txt"
    {"bparen","249D"},
#line 2394 "pdfdoc/glyphlist.txt"
    {"kcommaaccent","0137"},
#line 40 "pdfdoc/glyphlist.txt"
    {"Acircumflextilde","1EAA"},
#line 1961 "pdfdoc/glyphlist.txt"
    {"gershayimaccenthebrew","059E"},
#line 37 "pdfdoc/glyphlist.txt"
    {"Acircumflexgrave","1EA6"},
#line 3439 "pdfdoc/glyphlist.txt"
    {"segolhebrew","05B6"},
#line 1128 "pdfdoc/glyphlist.txt"
    {"arighthalfring","1E9A"},
#line 4128 "pdfdoc/glyphlist.txt"
    {"xparen","24B3"},
#line 1398 "pdfdoc/glyphlist.txt"
    {"circle","25CB"},
#line 1420 "pdfdoc/glyphlist.txt"
    {"colon","003A"},
#line 2209 "pdfdoc/glyphlist.txt"
    {"ideographichaveparen","3232"},
#line 3038 "pdfdoc/glyphlist.txt"
    {"peharmenian","057A"},
#line 2195 "pdfdoc/glyphlist.txt"
    {"ideographiccallparen","323A"},
#line 1787 "pdfdoc/glyphlist.txt"
    {"eshortdeva","090E"},
#line 1146 "pdfdoc/glyphlist.txt"
    {"arrowheaddownmod","02C5"},
#line 2281 "pdfdoc/glyphlist.txt"
    {"imatragurmukhi","0A3F"},
#line 2219 "pdfdoc/glyphlist.txt"
    {"ideographicnameparen","3234"},
#line 1730 "pdfdoc/glyphlist.txt"
    {"eightthai","0E58"},
#line 1430 "pdfdoc/glyphlist.txt"
    {"commaaccent","F6C3"},
#line 2485 "pdfdoc/glyphlist.txt"
    {"lameddageshhebrew","FB3C"},
#line 778 "pdfdoc/glyphlist.txt"
    {"acircumflexdotbelow","1EAD"},
#line 1408 "pdfdoc/glyphlist.txt"
    {"clear","2327"},
#line 2792 "pdfdoc/glyphlist.txt"
    {"nonenthai","0E13"},
#line 2221 "pdfdoc/glyphlist.txt"
    {"ideographicprintcircle","329E"},
#line 2500 "pdfdoc/glyphlist.txt"
    {"lammeemjeeminitialarabic","FEDF FEE4 FEA0"},
#line 2371 "pdfdoc/glyphlist.txt"
    {"kakatakana","30AB"},
#line 2461 "pdfdoc/glyphlist.txt"
    {"kukatakana","30AF"},
#line 2449 "pdfdoc/glyphlist.txt"
    {"kokatakana","30B3"},
#line 2398 "pdfdoc/glyphlist.txt"
    {"kekatakana","30B1"},
#line 2429 "pdfdoc/glyphlist.txt"
    {"kikatakana","30AD"},
#line 2164 "pdfdoc/glyphlist.txt"
    {"house","2302"},
#line 2218 "pdfdoc/glyphlist.txt"
    {"ideographicmoonparen","322A"},
#line 2229 "pdfdoc/glyphlist.txt"
    {"ideographicspace","3000"},
#line 3075 "pdfdoc/glyphlist.txt"
    {"philatin","0278"},
#line 3380 "pdfdoc/glyphlist.txt"
    {"sadarabic","0635"},
#line 1327 "pdfdoc/glyphlist.txt"
    {"bulletinverse","25D8"},
#line 2227 "pdfdoc/glyphlist.txt"
    {"ideographicselfparen","3242"},
#line 2502 "pdfdoc/glyphlist.txt"
    {"largecircle","25EF"},
#line 2230 "pdfdoc/glyphlist.txt"
    {"ideographicspecialparen","3235"},
#line 3466 "pdfdoc/glyphlist.txt"
    {"sevenhangzhou","3027"},
#line 1121 "pdfdoc/glyphlist.txt"
    {"approaches","2250"},
#line 1686 "pdfdoc/glyphlist.txt"
    {"ecircumflexdotbelow","1EC7"},
#line 3452 "pdfdoc/glyphlist.txt"
    {"semivoicedmarkkana","309C"},
#line 3453 "pdfdoc/glyphlist.txt"
    {"semivoicedmarkkanahalfwidth","FF9F"},
#line 1405 "pdfdoc/glyphlist.txt"
    {"circumflex","02C6"},
#line 2982 "pdfdoc/glyphlist.txt"
    {"padeva","092A"},
#line 3027 "pdfdoc/glyphlist.txt"
    {"pazerhebrew","05A1"},
#line 1911 "pdfdoc/glyphlist.txt"
    {"fourinferior","2084"},
#line 1645 "pdfdoc/glyphlist.txt"
    {"dotkatakana","30FB"},
#line 2977 "pdfdoc/glyphlist.txt"
    {"p","0070"},
#line 1354 "pdfdoc/glyphlist.txt"
    {"ccurl","0255"},
#line 3481 "pdfdoc/glyphlist.txt"
    {"shaarmenian","0577"},
#line 3444 "pdfdoc/glyphlist.txt"
    {"seharmenian","057D"},
#line 3632 "pdfdoc/glyphlist.txt"
    {"ssangtikeutkorean","3138"},
#line 1205 "pdfdoc/glyphlist.txt"
    {"avagrahadeva","093D"},
#line 2133 "pdfdoc/glyphlist.txt"
    {"hiriq21","05B4"},
#line 682 "pdfdoc/glyphlist.txt"
    {"Vmonospace","FF36"},
#line 3577 "pdfdoc/glyphlist.txt"
    {"sixthai","0E56"},
#line 62 "pdfdoc/glyphlist.txt"
    {"Aringacute","01FA"},
#line 3118 "pdfdoc/glyphlist.txt"
    {"pparen","24AB"},
#line 1869 "pdfdoc/glyphlist.txt"
    {"fisheye","25C9"},
#line 1095 "pdfdoc/glyphlist.txt"
    {"ampersand","0026"},
#line 2809 "pdfdoc/glyphlist.txt"
    {"notequal","2260"},
#line 2236 "pdfdoc/glyphlist.txt"
    {"ideographicwoodparen","322D"},
#line 2372 "pdfdoc/glyphlist.txt"
    {"kakatakanahalfwidth","FF76"},
#line 2462 "pdfdoc/glyphlist.txt"
    {"kukatakanahalfwidth","FF78"},
#line 2450 "pdfdoc/glyphlist.txt"
    {"kokatakanahalfwidth","FF7A"},
#line 577 "pdfdoc/glyphlist.txt"
    {"Shacyrillic","0428"},
#line 2399 "pdfdoc/glyphlist.txt"
    {"kekatakanahalfwidth","FF79"},
#line 2430 "pdfdoc/glyphlist.txt"
    {"kikatakanahalfwidth","FF77"},
#line 103 "pdfdoc/glyphlist.txt"
    {"Chekhakassiancyrillic","04CB"},
#line 745 "pdfdoc/glyphlist.txt"
    {"Zhecyrillic","0416"},
#line 2393 "pdfdoc/glyphlist.txt"
    {"kcircle","24DA"},
#line 1178 "pdfdoc/glyphlist.txt"
    {"asmallhiragana","3041"},
#line 1774 "pdfdoc/glyphlist.txt"
    {"equal","003D"},
#line 1056 "pdfdoc/glyphlist.txt"
    {"aiecyrillic","04D5"},
#line 64 "pdfdoc/glyphlist.txt"
    {"Aringsmall","F7E5"},
#line 2763 "pdfdoc/glyphlist.txt"
    {"nineinferior","2089"},
#line 59 "pdfdoc/glyphlist.txt"
    {"Amonospace","FF21"},
#line 1234 "pdfdoc/glyphlist.txt"
    {"behmeeminitialarabic","FC9F"},
#line 3381 "pdfdoc/glyphlist.txt"
    {"sadeva","0938"},
#line 1235 "pdfdoc/glyphlist.txt"
    {"behmeemisolatedarabic","FC08"},
#line 3462 "pdfdoc/glyphlist.txt"
    {"seveneighths","215E"},
#line 1791 "pdfdoc/glyphlist.txt"
    {"esmallhiragana","3047"},
#line 3596 "pdfdoc/glyphlist.txt"
    {"space","0020"},
#line 707 "pdfdoc/glyphlist.txt"
    {"Yatcyrillic","0462"},
#line 465 "pdfdoc/glyphlist.txt"
    {"Oogonekmacron","01EC"},
#line 1352 "pdfdoc/glyphlist.txt"
    {"ccircle","24D2"},
#line 1090 "pdfdoc/glyphlist.txt"
    {"allequal","224C"},
#line 2517 "pdfdoc/glyphlist.txt"
    {"less","003C"},
#line 3528 "pdfdoc/glyphlist.txt"
    {"shinshindot","FB2A"},
#line 1360 "pdfdoc/glyphlist.txt"
    {"cent","00A2"},
#line 39 "pdfdoc/glyphlist.txt"
    {"Acircumflexsmall","F7E2"},
#line 3601 "pdfdoc/glyphlist.txt"
    {"sparen","24AE"},
#line 2676 "pdfdoc/glyphlist.txt"
    {"mu","00B5"},
#line 2677 "pdfdoc/glyphlist.txt"
    {"mu1","00B5"},
#line 797 "pdfdoc/glyphlist.txt"
    {"adotmacron","01E1"},
#line 424 "pdfdoc/glyphlist.txt"
    {"Ocircumflexdotbelow","1ED8"},
#line 2803 "pdfdoc/glyphlist.txt"
    {"noonmeeminitialarabic","FCD5"},
#line 2132 "pdfdoc/glyphlist.txt"
    {"hiriq14","05B4"},
#line 1725 "pdfdoc/glyphlist.txt"
    {"eightparen","247B"},
#line 490 "pdfdoc/glyphlist.txt"
    {"Psicyrillic","0470"},
#line 3568 "pdfdoc/glyphlist.txt"
    {"sixparen","2479"},
#line 3563 "pdfdoc/glyphlist.txt"
    {"sixhangzhou","3026"},
#line 98 "pdfdoc/glyphlist.txt"
    {"Checyrillic","0427"},
#line 311 "pdfdoc/glyphlist.txt"
    {"Iotadieresis","03AA"},
#line 2566 "pdfdoc/glyphlist.txt"
    {"m","006D"},
#line 2568 "pdfdoc/glyphlist.txt"
    {"macron","00AF"},
#line 558 "pdfdoc/glyphlist.txt"
    {"Sacute","015A"},
#line 1930 "pdfdoc/glyphlist.txt"
    {"gacute","01F5"},
#line 731 "pdfdoc/glyphlist.txt"
    {"Zacute","0179"},
#line 754 "pdfdoc/glyphlist.txt"
    {"aacute","00E1"},
#line 2635 "pdfdoc/glyphlist.txt"
    {"mhook","0271"},
#line 687 "pdfdoc/glyphlist.txt"
    {"Wacute","1E82"},
#line 622 "pdfdoc/glyphlist.txt"
    {"Uacute","00DA"},
#line 2309 "pdfdoc/glyphlist.txt"
    {"issharbengali","09FA"},
#line 1293 "pdfdoc/glyphlist.txt"
    {"bracelefttp","F8F1"},
#line 2306 "pdfdoc/glyphlist.txt"
    {"ismallhiragana","3043"},
#line 358 "pdfdoc/glyphlist.txt"
    {"Lacute","0139"},
#line 1860 "pdfdoc/glyphlist.txt"
    {"finalmem","05DD"},
#line 4264 "pdfdoc/glyphlist.txt"
    {"zero","0030"},
#line 498 "pdfdoc/glyphlist.txt"
    {"Racute","0154"},
#line 392 "pdfdoc/glyphlist.txt"
    {"Nacute","0143"},
#line 2579 "pdfdoc/glyphlist.txt"
    {"mahiragana","307E"},
#line 1717 "pdfdoc/glyphlist.txt"
    {"eightgurmukhi","0A6E"},
#line 2684 "pdfdoc/glyphlist.txt"
    {"muhiragana","3080"},
#line 381 "pdfdoc/glyphlist.txt"
    {"Macute","1E3E"},
#line 2663 "pdfdoc/glyphlist.txt"
    {"mohiragana","3082"},
#line 345 "pdfdoc/glyphlist.txt"
    {"Khacyrillic","0425"},
#line 2622 "pdfdoc/glyphlist.txt"
    {"mehiragana","3081"},
#line 2647 "pdfdoc/glyphlist.txt"
    {"mihiragana","307F"},
#line 2817 "pdfdoc/glyphlist.txt"
    {"notprecedes","2280"},
#line 517 "pdfdoc/glyphlist.txt"
    {"S","0053"},
#line 562 "pdfdoc/glyphlist.txt"
    {"Scarondotaccent","1E66"},
#line 145 "pdfdoc/glyphlist.txt"
    {"E","0045"},
#line 278 "pdfdoc/glyphlist.txt"
    {"Iacute","00CD"},
#line 1883 "pdfdoc/glyphlist.txt"
    {"fiveinferior","2085"},
#line 2850 "pdfdoc/glyphlist.txt"
    {"o","006F"},
#line 2626 "pdfdoc/glyphlist.txt"
    {"mem","05DE"},
#line 705 "pdfdoc/glyphlist.txt"
    {"Yacute","00DD"},
#line 4252 "pdfdoc/glyphlist.txt"
    {"zcaron","017E"},
#line 565 "pdfdoc/glyphlist.txt"
    {"Schwa","018F"},
#line 2878 "pdfdoc/glyphlist.txt"
    {"oe","0153"},
#line 206 "pdfdoc/glyphlist.txt"
    {"Euro","20AC"},
#line 1052 "pdfdoc/glyphlist.txt"
    {"ahookabove","1EA3"},
#line 2894 "pdfdoc/glyphlist.txt"
    {"oi","01A3"},
#line 644 "pdfdoc/glyphlist.txt"
    {"Uhookabove","1EE6"},
#line 4265 "pdfdoc/glyphlist.txt"
    {"zeroarabic","0660"},
#line 3051 "pdfdoc/glyphlist.txt"
    {"period","002E"},
#line 1669 "pdfdoc/glyphlist.txt"
    {"eacute","00E9"},
#line 2615 "pdfdoc/glyphlist.txt"
    {"meemarabic","0645"},
#line 478 "pdfdoc/glyphlist.txt"
    {"Pacute","1E54"},
#line 2459 "pdfdoc/glyphlist.txt"
    {"kturned","029E"},
#line 2915 "pdfdoc/glyphlist.txt"
    {"one","0031"},
#line 4239 "pdfdoc/glyphlist.txt"
    {"zahiragana","3056"},
#line 1943 "pdfdoc/glyphlist.txt"
    {"gangiacoptic","03EB"},
#line 199 "pdfdoc/glyphlist.txt"
    {"Eta","0397"},
#line 4297 "pdfdoc/glyphlist.txt"
    {"zuhiragana","305A"},
#line 4276 "pdfdoc/glyphlist.txt"
    {"zerothai","0E50"},
#line 1158 "pdfdoc/glyphlist.txt"
    {"arrowrightheavy","279E"},
#line 3529 "pdfdoc/glyphlist.txt"
    {"shinshindothebrew","FB2A"},
#line 4292 "pdfdoc/glyphlist.txt"
    {"zohiragana","305E"},
#line 4262 "pdfdoc/glyphlist.txt"
    {"zehiragana","305C"},
#line 202 "pdfdoc/glyphlist.txt"
    {"Eth","00D0"},
#line 4287 "pdfdoc/glyphlist.txt"
    {"zihiragana","3058"},
#line 2255 "pdfdoc/glyphlist.txt"
    {"ieungparenkorean","3207"},
#line 4280 "pdfdoc/glyphlist.txt"
    {"zeta","03B6"},
#line 4241 "pdfdoc/glyphlist.txt"
    {"zainarabic","0632"},
#line 299 "pdfdoc/glyphlist.txt"
    {"Ihookabove","1EC8"},
#line 149 "pdfdoc/glyphlist.txt"
    {"Ecaron","011A"},
#line 2887 "pdfdoc/glyphlist.txt"
    {"ohorn","01A1"},
#line 353 "pdfdoc/glyphlist.txt"
    {"Ksicyrillic","046E"},
#line 1298 "pdfdoc/glyphlist.txt"
    {"bracerightmonospace","FF5D"},
#line 1163 "pdfdoc/glyphlist.txt"
    {"arrowup","2191"},
#line 718 "pdfdoc/glyphlist.txt"
    {"Yhookabove","1EF6"},
#line 2863 "pdfdoc/glyphlist.txt"
    {"ocaron","01D2"},
#line 1815 "pdfdoc/glyphlist.txt"
    {"exclamdown","00A1"},
#line 197 "pdfdoc/glyphlist.txt"
    {"Esh","01A9"},
#line 2618 "pdfdoc/glyphlist.txt"
    {"meemmedialarabic","FEE4"},
#line 2668 "pdfdoc/glyphlist.txt"
    {"momathai","0E21"},
#line 2603 "pdfdoc/glyphlist.txt"
    {"male","2642"},
#line 1849 "pdfdoc/glyphlist.txt"
    {"figuredash","2012"},
#line 1165 "pdfdoc/glyphlist.txt"
    {"arrowupdnbse","21A8"},
#line 1281 "pdfdoc/glyphlist.txt"
    {"bmonospace","FF42"},
#line 1906 "pdfdoc/glyphlist.txt"
    {"fourgujarati","0AEA"},
#line 1164 "pdfdoc/glyphlist.txt"
    {"arrowupdn","2195"},
#line 1705 "pdfdoc/glyphlist.txt"
    {"ehookabove","1EBB"},
#line 2300 "pdfdoc/glyphlist.txt"
    {"iotadieresis","03CA"},
#line 2706 "pdfdoc/glyphlist.txt"
    {"nacute","0144"},
#line 1606 "pdfdoc/glyphlist.txt"
    {"dialytikatonos","0385"},
#line 2524 "pdfdoc/glyphlist.txt"
    {"lesssmall","FE64"},
#line 4236 "pdfdoc/glyphlist.txt"
    {"zaharabic","0638"},
#line 4127 "pdfdoc/glyphlist.txt"
    {"xmonospace","FF58"},
#line 3422 "pdfdoc/glyphlist.txt"
    {"scircumflex","015D"},
#line 84 "pdfdoc/glyphlist.txt"
    {"Cacute","0106"},
#line 2793 "pdfdoc/glyphlist.txt"
    {"nonuthai","0E19"},
#line 1125 "pdfdoc/glyphlist.txt"
    {"araeaekorean","318E"},
#line 2918 "pdfdoc/glyphlist.txt"
    {"onecircle","2460"},
#line 2904 "pdfdoc/glyphlist.txt"
    {"omega","03C9"},
#line 185 "pdfdoc/glyphlist.txt"
    {"Eng","014A"},
#line 3500 "pdfdoc/glyphlist.txt"
    {"shchacyrillic","0449"},
#line 2905 "pdfdoc/glyphlist.txt"
    {"omega1","03D6"},
#line 1651 "pdfdoc/glyphlist.txt"
    {"doubleyodpatah","FB1F"},
#line 1968 "pdfdoc/glyphlist.txt"
    {"ghagurmukhi","0A18"},
#line 1861 "pdfdoc/glyphlist.txt"
    {"finalmemhebrew","05DD"},
#line 2301 "pdfdoc/glyphlist.txt"
    {"iotadieresistonos","0390"},
#line 2917 "pdfdoc/glyphlist.txt"
    {"onebengali","09E7"},
#line 2682 "pdfdoc/glyphlist.txt"
    {"mugreek","03BC"},
#line 2345 "pdfdoc/glyphlist.txt"
    {"jhagurmukhi","0A1D"},
#line 1630 "pdfdoc/glyphlist.txt"
    {"dodekthai","0E14"},
#line 1604 "pdfdoc/glyphlist.txt"
    {"dhagurmukhi","0A27"},
#line 1423 "pdfdoc/glyphlist.txt"
    {"colonsign","20A1"},
#line 42 "pdfdoc/glyphlist.txt"
    {"Acutesmall","F7B4"},
#line 2852 "pdfdoc/glyphlist.txt"
    {"oangthai","0E2D"},
#line 2182 "pdfdoc/glyphlist.txt"
    {"iacute","00ED"},
#line 2380 "pdfdoc/glyphlist.txt"
    {"kashidaautoarabic","0640"},
#line 2589 "pdfdoc/glyphlist.txt"
    {"maihanakatthai","0E31"},
#line 331 "pdfdoc/glyphlist.txt"
    {"Kacute","1E30"},
#line 2737 "pdfdoc/glyphlist.txt"
    {"nieunacirclekorean","326F"},
#line 223 "pdfdoc/glyphlist.txt"
    {"Gacute","01F4"},
#line 2880 "pdfdoc/glyphlist.txt"
    {"ogonek","02DB"},
#line 2916 "pdfdoc/glyphlist.txt"
    {"onearabic","0661"},
#line 2396 "pdfdoc/glyphlist.txt"
    {"keharmenian","0584"},
#line 3428 "pdfdoc/glyphlist.txt"
    {"second","2033"},
#line 589 "pdfdoc/glyphlist.txt"
    {"Tau","03A4"},
#line 1078 "pdfdoc/glyphlist.txt"
    {"alefhamzabelowfinalarabic","FE88"},
#line 1077 "pdfdoc/glyphlist.txt"
    {"alefhamzabelowarabic","0625"},
#line 2400 "pdfdoc/glyphlist.txt"
    {"kenarmenian","056F"},
#line 2388 "pdfdoc/glyphlist.txt"
    {"kaverticalstrokecyrillic","049D"},
#line 2260 "pdfdoc/glyphlist.txt"
    {"ihookabove","1EC9"},
#line 3398 "pdfdoc/glyphlist.txt"
    {"saraaimaimuanthai","0E43"},
#line 2601 "pdfdoc/glyphlist.txt"
    {"makatakana","30DE"},
#line 2685 "pdfdoc/glyphlist.txt"
    {"mukatakana","30E0"},
#line 3003 "pdfdoc/glyphlist.txt"
    {"parenlefttp","F8EB"},
#line 2758 "pdfdoc/glyphlist.txt"
    {"ninegujarati","0AEF"},
#line 2665 "pdfdoc/glyphlist.txt"
    {"mokatakana","30E2"},
#line 2624 "pdfdoc/glyphlist.txt"
    {"mekatakana","30E1"},
#line 2220 "pdfdoc/glyphlist.txt"
    {"ideographicperiod","3002"},
#line 2648 "pdfdoc/glyphlist.txt"
    {"mikatakana","30DF"},
#line 2135 "pdfdoc/glyphlist.txt"
    {"hiriqhebrew","05B4"},
#line 1727 "pdfdoc/glyphlist.txt"
    {"eightpersian","06F8"},
#line 1666 "pdfdoc/glyphlist.txt"
    {"dzecyrillic","0455"},
#line 2494 "pdfdoc/glyphlist.txt"
    {"lamjeeminitialarabic","FCC9"},
#line 143 "pdfdoc/glyphlist.txt"
    {"Dzecyrillic","0405"},
#line 3024 "pdfdoc/glyphlist.txt"
    {"patahnarrowhebrew","05B7"},
#line 588 "pdfdoc/glyphlist.txt"
    {"T","0054"},
#line 3002 "pdfdoc/glyphlist.txt"
    {"parenleftsuperior","207D"},
#line 2607 "pdfdoc/glyphlist.txt"
    {"masoracirclehebrew","05AF"},
#line 604 "pdfdoc/glyphlist.txt"
    {"Thorn","00DE"},
#line 188 "pdfdoc/glyphlist.txt"
    {"Eogonek","0118"},
#line 591 "pdfdoc/glyphlist.txt"
    {"Tcaron","0164"},
#line 226 "pdfdoc/glyphlist.txt"
    {"Gangiacoptic","03EA"},
#line 1442 "pdfdoc/glyphlist.txt"
    {"congruent","2245"},
#line 2942 "pdfdoc/glyphlist.txt"
    {"oogonek","01EB"},
#line 1816 "pdfdoc/glyphlist.txt"
    {"exclamdownsmall","F7A1"},
#line 351 "pdfdoc/glyphlist.txt"
    {"Koppacyrillic","0480"},
#line 1366 "pdfdoc/glyphlist.txt"
    {"chaarmenian","0579"},
#line 603 "pdfdoc/glyphlist.txt"
    {"Thook","01AC"},
#line 4255 "pdfdoc/glyphlist.txt"
    {"zcurl","0291"},
#line 1277 "pdfdoc/glyphlist.txt"
    {"blackuppointingtriangle","25B2"},
#line 4243 "pdfdoc/glyphlist.txt"
    {"zakatakana","30B6"},
#line 3055 "pdfdoc/glyphlist.txt"
    {"periodinferior","F6E7"},
#line 4298 "pdfdoc/glyphlist.txt"
    {"zukatakana","30BA"},
#line 414 "pdfdoc/glyphlist.txt"
    {"Oacute","00D3"},
#line 259 "pdfdoc/glyphlist.txt"
    {"Hbar","0126"},
#line 4293 "pdfdoc/glyphlist.txt"
    {"zokatakana","30BE"},
#line 2926 "pdfdoc/glyphlist.txt"
    {"onehackarabic","0661"},
#line 4263 "pdfdoc/glyphlist.txt"
    {"zekatakana","30BC"},
#line 4288 "pdfdoc/glyphlist.txt"
    {"zikatakana","30B8"},
#line 2786 "pdfdoc/glyphlist.txt"
    {"nnagurmukhi","0A23"},
#line 1275 "pdfdoc/glyphlist.txt"
    {"blackupperrighttriangle","25E5"},
#line 1290 "pdfdoc/glyphlist.txt"
    {"braceleftmid","F8F2"},
#line 3107 "pdfdoc/glyphlist.txt"
    {"pmonospace","FF50"},
#line 701 "pdfdoc/glyphlist.txt"
    {"Xi","039E"},
#line 2357 "pdfdoc/glyphlist.txt"
    {"kadeva","0915"},
#line 3504 "pdfdoc/glyphlist.txt"
    {"sheenmedialarabic","FEB8"},
#line 3012 "pdfdoc/glyphlist.txt"
    {"parenrightsuperior","207E"},
#line 1276 "pdfdoc/glyphlist.txt"
    {"blackuppointingsmalltriangle","25B4"},
#line 1491 "pdfdoc/glyphlist.txt"
    {"cstretched","0297"},
#line 2945 "pdfdoc/glyphlist.txt"
    {"oomatragurmukhi","0A4B"},
#line 3010 "pdfdoc/glyphlist.txt"
    {"parenrightmonospace","FF09"},
#line 696 "pdfdoc/glyphlist.txt"
    {"X","0058"},
#line 848 "pdfdoc/glyphlist.txt"
    {"afii10061","040C"},
#line 2732 "pdfdoc/glyphlist.txt"
    {"ngagurmukhi","0A19"},
#line 838 "pdfdoc/glyphlist.txt"
    {"afii10051","0402"},
#line 878 "pdfdoc/glyphlist.txt"
    {"afii10091","0449"},
#line 1825 "pdfdoc/glyphlist.txt"
    {"f","0066"},
#line 847 "pdfdoc/glyphlist.txt"
    {"afii10060","040B"},
#line 1786 "pdfdoc/glyphlist.txt"
    {"eshcurl","0286"},
#line 837 "pdfdoc/glyphlist.txt"
    {"afii10050","0490"},
#line 877 "pdfdoc/glyphlist.txt"
    {"afii10090","0448"},
#line 1652 "pdfdoc/glyphlist.txt"
    {"doubleyodpatahhebrew","FB1F"},
#line 441 "pdfdoc/glyphlist.txt"
    {"Ohookabove","1ECE"},
#line 1256 "pdfdoc/glyphlist.txt"
    {"blackcircle","25CF"},
#line 1929 "pdfdoc/glyphlist.txt"
    {"gabengali","0997"},
#line 849 "pdfdoc/glyphlist.txt"
    {"afii10062","040E"},
#line 902 "pdfdoc/glyphlist.txt"
    {"afii10192","F6C6"},
#line 753 "pdfdoc/glyphlist.txt"
    {"aabengali","0986"},
#line 2123 "pdfdoc/glyphlist.txt"
    {"hieuhacirclekorean","327B"},
#line 839 "pdfdoc/glyphlist.txt"
    {"afii10052","0403"},
#line 1195 "pdfdoc/glyphlist.txt"
    {"aubengali","0994"},
#line 1843 "pdfdoc/glyphlist.txt"
    {"ffi","FB03"},
#line 879 "pdfdoc/glyphlist.txt"
    {"afii10092","044A"},
#line 2705 "pdfdoc/glyphlist.txt"
    {"nabla","2207"},
#line 613 "pdfdoc/glyphlist.txt"
    {"Tonesix","0184"},
#line 2325 "pdfdoc/glyphlist.txt"
    {"jabengali","099C"},
#line 2305 "pdfdoc/glyphlist.txt"
    {"irigurmukhi","0A72"},
#line 1501 "pdfdoc/glyphlist.txt"
    {"dabengali","09A6"},
#line 3397 "pdfdoc/glyphlist.txt"
    {"saraaimaimalaithai","0E44"},
#line 36 "pdfdoc/glyphlist.txt"
    {"Acircumflexdotbelow","1EAC"},
#line 1053 "pdfdoc/glyphlist.txt"
    {"aibengali","0990"},
#line 852 "pdfdoc/glyphlist.txt"
    {"afii10065","0430"},
#line 905 "pdfdoc/glyphlist.txt"
    {"afii10195","0473"},
#line 842 "pdfdoc/glyphlist.txt"
    {"afii10055","0406"},
#line 882 "pdfdoc/glyphlist.txt"
    {"afii10095","044D"},
#line 854 "pdfdoc/glyphlist.txt"
    {"afii10067","0432"},
#line 1297 "pdfdoc/glyphlist.txt"
    {"bracerightmid","F8FD"},
#line 2955 "pdfdoc/glyphlist.txt"
    {"oslash","00F8"},
#line 1358 "pdfdoc/glyphlist.txt"
    {"cedilla","00B8"},
#line 1076 "pdfdoc/glyphlist.txt"
    {"alefhamzaabovefinalarabic","FE84"},
#line 844 "pdfdoc/glyphlist.txt"
    {"afii10057","0408"},
#line 1075 "pdfdoc/glyphlist.txt"
    {"alefhamzaabovearabic","0623"},
#line 884 "pdfdoc/glyphlist.txt"
    {"afii10097","044F"},
#line 1169 "pdfdoc/glyphlist.txt"
    {"arrowupright","2197"},
#line 2455 "pdfdoc/glyphlist.txt"
    {"kparen","24A6"},
#line 2679 "pdfdoc/glyphlist.txt"
    {"muchgreater","226B"},
#line 2602 "pdfdoc/glyphlist.txt"
    {"makatakanahalfwidth","FF8F"},
#line 2686 "pdfdoc/glyphlist.txt"
    {"mukatakanahalfwidth","FF91"},
#line 1334 "pdfdoc/glyphlist.txt"
    {"cadeva","091A"},
#line 3527 "pdfdoc/glyphlist.txt"
    {"shinhebrew","05E9"},
#line 2956 "pdfdoc/glyphlist.txt"
    {"oslashacute","01FF"},
#line 2666 "pdfdoc/glyphlist.txt"
    {"mokatakanahalfwidth","FF93"},
#line 858 "pdfdoc/glyphlist.txt"
    {"afii10071","0451"},
#line 2625 "pdfdoc/glyphlist.txt"
    {"mekatakanahalfwidth","FF92"},
#line 675 "pdfdoc/glyphlist.txt"
    {"Utildebelow","1E74"},
#line 2649 "pdfdoc/glyphlist.txt"
    {"mikatakanahalfwidth","FF90"},
#line 963 "pdfdoc/glyphlist.txt"
    {"afii57451","064B"},
#line 857 "pdfdoc/glyphlist.txt"
    {"afii10070","0435"},
#line 962 "pdfdoc/glyphlist.txt"
    {"afii57450","064A"},
#line 4231 "pdfdoc/glyphlist.txt"
    {"z","007A"},
#line 2611 "pdfdoc/glyphlist.txt"
    {"mcircle","24DC"},
#line 2833 "pdfdoc/glyphlist.txt"
    {"nuktagurmukhi","0A3C"},
#line 2134 "pdfdoc/glyphlist.txt"
    {"hiriq2d","05B4"},
#line 859 "pdfdoc/glyphlist.txt"
    {"afii10072","0436"},
#line 2467 "pdfdoc/glyphlist.txt"
    {"lacute","013A"},
#line 964 "pdfdoc/glyphlist.txt"
    {"afii57452","064C"},
#line 862 "pdfdoc/glyphlist.txt"
    {"afii10075","0439"},
#line 1628 "pdfdoc/glyphlist.txt"
    {"dnblock","2584"},
#line 967 "pdfdoc/glyphlist.txt"
    {"afii57455","064F"},
#line 1878 "pdfdoc/glyphlist.txt"
    {"fivegujarati","0AEB"},
#line 316 "pdfdoc/glyphlist.txt"
    {"Itildebelow","1E2C"},
#line 1718 "pdfdoc/glyphlist.txt"
    {"eighthackarabic","0668"},
#line 864 "pdfdoc/glyphlist.txt"
    {"afii10077","043B"},
#line 336 "pdfdoc/glyphlist.txt"
    {"Kastrokecyrillic","049E"},
#line 969 "pdfdoc/glyphlist.txt"
    {"afii57457","0651"},
#line 1932 "pdfdoc/glyphlist.txt"
    {"gafarabic","06AF"},
#line 4296 "pdfdoc/glyphlist.txt"
    {"zstroke","01B6"},
#line 868 "pdfdoc/glyphlist.txt"
    {"afii10081","043F"},
#line 2341 "pdfdoc/glyphlist.txt"
    {"jehfinalarabic","FB8B"},
#line 3514 "pdfdoc/glyphlist.txt"
    {"shevanarrowhebrew","05B0"},
#line 867 "pdfdoc/glyphlist.txt"
    {"afii10080","043E"},
#line 595 "pdfdoc/glyphlist.txt"
    {"Tcommaaccent","0162"},
#line 169 "pdfdoc/glyphlist.txt"
    {"Egrave","00C8"},
#line 1959 "pdfdoc/glyphlist.txt"
    {"gereshmuqdamhebrew","059D"},
#line 1061 "pdfdoc/glyphlist.txt"
    {"ainfinalarabic","FECA"},
#line 1801 "pdfdoc/glyphlist.txt"
    {"etildebelow","1E1B"},
#line 1489 "pdfdoc/glyphlist.txt"
    {"cparen","249E"},
#line 207 "pdfdoc/glyphlist.txt"
    {"Ezh","01B7"},
#line 3583 "pdfdoc/glyphlist.txt"
    {"smonospace","FF53"},
#line 2882 "pdfdoc/glyphlist.txt"
    {"ograve","00F2"},
#line 1897 "pdfdoc/glyphlist.txt"
    {"fofathai","0E1D"},
#line 869 "pdfdoc/glyphlist.txt"
    {"afii10082","0440"},
#line 4253 "pdfdoc/glyphlist.txt"
    {"zcircle","24E9"},
#line 971 "pdfdoc/glyphlist.txt"
    {"afii57470","0647"},
#line 872 "pdfdoc/glyphlist.txt"
    {"afii10085","0443"},
#line 2704 "pdfdoc/glyphlist.txt"
    {"nabengali","09A8"},
#line 1837 "pdfdoc/glyphlist.txt"
    {"fehfinalarabic","FED2"},
#line 3475 "pdfdoc/glyphlist.txt"
    {"sevensuperior","2077"},
#line 874 "pdfdoc/glyphlist.txt"
    {"afii10087","0445"},
#line 853 "pdfdoc/glyphlist.txt"
    {"afii10066","0431"},
#line 906 "pdfdoc/glyphlist.txt"
    {"afii10196","0475"},
#line 843 "pdfdoc/glyphlist.txt"
    {"afii10056","0407"},
#line 883 "pdfdoc/glyphlist.txt"
    {"afii10096","044E"},
#line 1823 "pdfdoc/glyphlist.txt"
    {"ezhreversed","01B9"},
#line 1193 "pdfdoc/glyphlist.txt"
    {"atsmall","FE6B"},
#line 2690 "pdfdoc/glyphlist.txt"
    {"munahhebrew","05A3"},
#line 152 "pdfdoc/glyphlist.txt"
    {"Ecircle","24BA"},
#line 1012 "pdfdoc/glyphlist.txt"
    {"afii57690","05EA"},
#line 3440 "pdfdoc/glyphlist.txt"
    {"segolnarrowhebrew","05B6"},
#line 2232 "pdfdoc/glyphlist.txt"
    {"ideographicstudyparen","323B"},
#line 2864 "pdfdoc/glyphlist.txt"
    {"ocircle","24DE"},
#line 2478 "pdfdoc/glyphlist.txt"
    {"lamalefmaddaabovefinalarabic","FEF6"},
#line 2479 "pdfdoc/glyphlist.txt"
    {"lamalefmaddaaboveisolatedarabic","FEF5"},
#line 851 "pdfdoc/glyphlist.txt"
    {"afii10064","F6C5"},
#line 904 "pdfdoc/glyphlist.txt"
    {"afii10194","0463"},
#line 1908 "pdfdoc/glyphlist.txt"
    {"fourhackarabic","0664"},
#line 841 "pdfdoc/glyphlist.txt"
    {"afii10054","0405"},
#line 881 "pdfdoc/glyphlist.txt"
    {"afii10094","044C"},
#line 915 "pdfdoc/glyphlist.txt"
    {"afii57392","0660"},
#line 4289 "pdfdoc/glyphlist.txt"
    {"zinorhebrew","05AE"},
#line 987 "pdfdoc/glyphlist.txt"
    {"afii57665","05D1"},
#line 2085 "pdfdoc/glyphlist.txt"
    {"hbar","0127"},
#line 1014 "pdfdoc/glyphlist.txt"
    {"afii57695","FB2B"},
#line 1355 "pdfdoc/glyphlist.txt"
    {"cdot","010B"},
#line 918 "pdfdoc/glyphlist.txt"
    {"afii57395","0663"},
#line 2261 "pdfdoc/glyphlist.txt"
    {"iibengali","0988"},
#line 989 "pdfdoc/glyphlist.txt"
    {"afii57667","05D3"},
#line 54 "pdfdoc/glyphlist.txt"
    {"Aiecyrillic","04D4"},
#line 2885 "pdfdoc/glyphlist.txt"
    {"ohiragana","304A"},
#line 2879 "pdfdoc/glyphlist.txt"
    {"oekorean","315A"},
#line 920 "pdfdoc/glyphlist.txt"
    {"afii57397","0665"},
#line 863 "pdfdoc/glyphlist.txt"
    {"afii10076","043A"},
#line 968 "pdfdoc/glyphlist.txt"
    {"afii57456","0650"},
#line 2960 "pdfdoc/glyphlist.txt"
    {"ostrokeacute","01FF"},
#line 2892 "pdfdoc/glyphlist.txt"
    {"ohorntilde","1EE1"},
#line 2591 "pdfdoc/glyphlist.txt"
    {"maitaikhuthai","0E47"},
#line 888 "pdfdoc/glyphlist.txt"
    {"afii10101","0454"},
#line 993 "pdfdoc/glyphlist.txt"
    {"afii57671","05D7"},
#line 1945 "pdfdoc/glyphlist.txt"
    {"gbreve","011F"},
#line 887 "pdfdoc/glyphlist.txt"
    {"afii10100","0453"},
#line 767 "pdfdoc/glyphlist.txt"
    {"abreve","0103"},
#line 992 "pdfdoc/glyphlist.txt"
    {"afii57670","05D6"},
#line 2315 "pdfdoc/glyphlist.txt"
    {"itildebelow","1E2D"},
#line 624 "pdfdoc/glyphlist.txt"
    {"Ubreve","016C"},
#line 1540 "pdfdoc/glyphlist.txt"
    {"dalfinalarabic","FEAA"},
#line 271 "pdfdoc/glyphlist.txt"
    {"Hungarumlaut","F6CF"},
#line 889 "pdfdoc/glyphlist.txt"
    {"afii10102","0455"},
#line 1320 "pdfdoc/glyphlist.txt"
    {"brokenbar","00A6"},
#line 994 "pdfdoc/glyphlist.txt"
    {"afii57672","05D8"},
#line 2938 "pdfdoc/glyphlist.txt"
    {"oneroman","2170"},
#line 861 "pdfdoc/glyphlist.txt"
    {"afii10074","0438"},
#line 571 "pdfdoc/glyphlist.txt"
    {"Sdotaccent","1E60"},
#line 966 "pdfdoc/glyphlist.txt"
    {"afii57454","064E"},
#line 768 "pdfdoc/glyphlist.txt"
    {"abreveacute","1EAF"},
#line 1952 "pdfdoc/glyphlist.txt"
    {"gdotaccent","0121"},
#line 1071 "pdfdoc/glyphlist.txt"
    {"alef","05D0"},
#line 737 "pdfdoc/glyphlist.txt"
    {"Zdotaccent","017B"},
#line 892 "pdfdoc/glyphlist.txt"
    {"afii10105","0458"},
#line 691 "pdfdoc/glyphlist.txt"
    {"Wdotaccent","1E86"},
#line 997 "pdfdoc/glyphlist.txt"
    {"afii57675","05DB"},
#line 873 "pdfdoc/glyphlist.txt"
    {"afii10086","0444"},
#line 1585 "pdfdoc/glyphlist.txt"
    {"ddotaccent","1E0B"},
#line 71 "pdfdoc/glyphlist.txt"
    {"Bdotaccent","1E02"},
#line 894 "pdfdoc/glyphlist.txt"
    {"afii10107","045A"},
#line 121 "pdfdoc/glyphlist.txt"
    {"Ddotaccent","1E0A"},
#line 366 "pdfdoc/glyphlist.txt"
    {"Ldotaccent","013F"},
#line 999 "pdfdoc/glyphlist.txt"
    {"afii57677","05DD"},
#line 504 "pdfdoc/glyphlist.txt"
    {"Rdotaccent","1E58"},
#line 1044 "pdfdoc/glyphlist.txt"
    {"afii61575","202E"},
#line 398 "pdfdoc/glyphlist.txt"
    {"Ndotaccent","1E44"},
#line 1041 "pdfdoc/glyphlist.txt"
    {"afii61352","2116"},
#line 280 "pdfdoc/glyphlist.txt"
    {"Ibreve","012C"},
#line 1852 "pdfdoc/glyphlist.txt"
    {"finalkaf","05DA"},
#line 383 "pdfdoc/glyphlist.txt"
    {"Mdotaccent","1E40"},
#line 1003 "pdfdoc/glyphlist.txt"
    {"afii57681","05E1"},
#line 913 "pdfdoc/glyphlist.txt"
    {"afii57381","066A"},
#line 1844 "pdfdoc/glyphlist.txt"
    {"ffl","FB04"},
#line 1002 "pdfdoc/glyphlist.txt"
    {"afii57680","05E0"},
#line 2373 "pdfdoc/glyphlist.txt"
    {"kappa","03BA"},
#line 1789 "pdfdoc/glyphlist.txt"
    {"eshreversedloop","01AA"},
#line 198 "pdfdoc/glyphlist.txt"
    {"Esmall","F765"},
#line 1834 "pdfdoc/glyphlist.txt"
    {"fdotaccent","1E1F"},
#line 924 "pdfdoc/glyphlist.txt"
    {"afii57401","0669"},
#line 1004 "pdfdoc/glyphlist.txt"
    {"afii57682","05E2"},
#line 292 "pdfdoc/glyphlist.txt"
    {"Idotaccent","0130"},
#line 871 "pdfdoc/glyphlist.txt"
    {"afii10084","0442"},
#line 1673 "pdfdoc/glyphlist.txt"
    {"ebreve","0115"},
#line 1721 "pdfdoc/glyphlist.txt"
    {"eightideographicparen","3227"},
#line 3117 "pdfdoc/glyphlist.txt"
    {"postalmarkface","3020"},
#line 212 "pdfdoc/glyphlist.txt"
    {"Fdotaccent","1E1E"},
#line 923 "pdfdoc/glyphlist.txt"
    {"afii57400","0668"},
#line 3052 "pdfdoc/glyphlist.txt"
    {"periodarmenian","0589"},
#line 712 "pdfdoc/glyphlist.txt"
    {"Ydotaccent","1E8E"},
#line 2033 "pdfdoc/glyphlist.txt"
    {"habengali","09B9"},
#line 912 "pdfdoc/glyphlist.txt"
    {"afii301","200D"},
#line 1007 "pdfdoc/glyphlist.txt"
    {"afii57685","05E5"},
#line 265 "pdfdoc/glyphlist.txt"
    {"Hdotaccent","1E22"},
#line 850 "pdfdoc/glyphlist.txt"
    {"afii10063","F6C4"},
#line 903 "pdfdoc/glyphlist.txt"
    {"afii10193","045F"},
#line 2760 "pdfdoc/glyphlist.txt"
    {"ninehackarabic","0669"},
#line 602 "pdfdoc/glyphlist.txt"
    {"Theta","0398"},
#line 3116 "pdfdoc/glyphlist.txt"
    {"postalmark","3012"},
#line 840 "pdfdoc/glyphlist.txt"
    {"afii10053","0404"},
#line 2675 "pdfdoc/glyphlist.txt"
    {"mturned","026F"},
#line 880 "pdfdoc/glyphlist.txt"
    {"afii10093","044B"},
#line 1329 "pdfdoc/glyphlist.txt"
    {"bullseye","25CE"},
#line 911 "pdfdoc/glyphlist.txt"
    {"afii300","200F"},
#line 50 "pdfdoc/glyphlist.txt"
    {"Adotmacron","01E0"},
#line 1009 "pdfdoc/glyphlist.txt"
    {"afii57687","05E7"},
#line 988 "pdfdoc/glyphlist.txt"
    {"afii57666","05D2"},
#line 1695 "pdfdoc/glyphlist.txt"
    {"edotaccent","0117"},
#line 3463 "pdfdoc/glyphlist.txt"
    {"sevengujarati","0AED"},
#line 2503 "pdfdoc/glyphlist.txt"
    {"lbar","019A"},
#line 480 "pdfdoc/glyphlist.txt"
    {"Pdotaccent","1E56"},
#line 919 "pdfdoc/glyphlist.txt"
    {"afii57396","0664"},
#line 1353 "pdfdoc/glyphlist.txt"
    {"ccircumflex","0109"},
#line 1664 "pdfdoc/glyphlist.txt"
    {"dzcurl","02A5"},
#line 926 "pdfdoc/glyphlist.txt"
    {"afii57407","061F"},
#line 2312 "pdfdoc/glyphlist.txt"
    {"iterationhiragana","309D"},
#line 2804 "pdfdoc/glyphlist.txt"
    {"noonmeemisolatedarabic","FC4E"},
#line 4295 "pdfdoc/glyphlist.txt"
    {"zretroflexhook","0290"},
#line 2175 "pdfdoc/glyphlist.txt"
    {"hyphen","002D"},
#line 4246 "pdfdoc/glyphlist.txt"
    {"zarqahebrew","0598"},
#line 3125 "pdfdoc/glyphlist.txt"
    {"prolongedkana","30FC"},
#line 986 "pdfdoc/glyphlist.txt"
    {"afii57664","05D0"},
#line 972 "pdfdoc/glyphlist.txt"
    {"afii57505","06A4"},
#line 2346 "pdfdoc/glyphlist.txt"
    {"jheharmenian","057B"},
#line 2958 "pdfdoc/glyphlist.txt"
    {"osmallkatakana","30A9"},
#line 593 "pdfdoc/glyphlist.txt"
    {"Tcircle","24C9"},
#line 1013 "pdfdoc/glyphlist.txt"
    {"afii57694","FB2A"},
#line 1822 "pdfdoc/glyphlist.txt"
    {"ezhcurl","0293"},
#line 917 "pdfdoc/glyphlist.txt"
    {"afii57394","0662"},
#line 2162 "pdfdoc/glyphlist.txt"
    {"horncmb","031B"},
#line 2313 "pdfdoc/glyphlist.txt"
    {"iterationkatakana","30FD"},
#line 2959 "pdfdoc/glyphlist.txt"
    {"osmallkatakanahalfwidth","FF6B"},
#line 974 "pdfdoc/glyphlist.txt"
    {"afii57507","0686"},
#line 860 "pdfdoc/glyphlist.txt"
    {"afii10073","0437"},
#line 4030 "pdfdoc/glyphlist.txt"
    {"vhook","028B"},
#line 23 "pdfdoc/glyphlist.txt"
    {"Aacute","00C1"},
#line 330 "pdfdoc/glyphlist.txt"
    {"Kabashkircyrillic","04A0"},
#line 965 "pdfdoc/glyphlist.txt"
    {"afii57453","064D"},
#line 2722 "pdfdoc/glyphlist.txt"
    {"ndotaccent","1E45"},
#line 893 "pdfdoc/glyphlist.txt"
    {"afii10106","0459"},
#line 324 "pdfdoc/glyphlist.txt"
    {"Jheharmenian","054B"},
#line 998 "pdfdoc/glyphlist.txt"
    {"afii57676","05DC"},
#line 2039 "pdfdoc/glyphlist.txt"
    {"hahfinalarabic","FEA2"},
#line 856 "pdfdoc/glyphlist.txt"
    {"afii10069","0434"},
#line 846 "pdfdoc/glyphlist.txt"
    {"afii10059","040A"},
#line 4048 "pdfdoc/glyphlist.txt"
    {"vuhiragana","3094"},
#line 886 "pdfdoc/glyphlist.txt"
    {"afii10099","0452"},
#line 2105 "pdfdoc/glyphlist.txt"
    {"hehfinalarabic","FEEA"},
#line 1913 "pdfdoc/glyphlist.txt"
    {"fournumeratorbengali","09F7"},
#line 3099 "pdfdoc/glyphlist.txt"
    {"plus","002B"},
#line 2142 "pdfdoc/glyphlist.txt"
    {"hohipthai","0E2B"},
#line 2504 "pdfdoc/glyphlist.txt"
    {"lbelt","026C"},
#line 94 "pdfdoc/glyphlist.txt"
    {"Cdotaccent","010A"},
#line 1532 "pdfdoc/glyphlist.txt"
    {"daletqubuts","05D3 05BB"},
#line 204 "pdfdoc/glyphlist.txt"
    {"Etilde","1EBC"},
#line 3627 "pdfdoc/glyphlist.txt"
    {"ssangieungkorean","3180"},
#line 1373 "pdfdoc/glyphlist.txt"
    {"checkmark","2713"},
#line 2186 "pdfdoc/glyphlist.txt"
    {"ibreve","012D"},
#line 891 "pdfdoc/glyphlist.txt"
    {"afii10104","0457"},
#line 2963 "pdfdoc/glyphlist.txt"
    {"otilde","00F5"},
#line 1188 "pdfdoc/glyphlist.txt"
    {"asuperior","F6E9"},
#line 996 "pdfdoc/glyphlist.txt"
    {"afii57674","05DA"},
#line 2350 "pdfdoc/glyphlist.txt"
    {"jsuperior","02B2"},
#line 870 "pdfdoc/glyphlist.txt"
    {"afii10083","0441"},
#line 1656 "pdfdoc/glyphlist.txt"
    {"dsuperior","F6EB"},
#line 1583 "pdfdoc/glyphlist.txt"
    {"ddhagujarati","0AA2"},
#line 600 "pdfdoc/glyphlist.txt"
    {"Tenroman","2169"},
#line 413 "pdfdoc/glyphlist.txt"
    {"OEsmall","F6FA"},
#line 53 "pdfdoc/glyphlist.txt"
    {"Ahookabove","1EA2"},
#line 1043 "pdfdoc/glyphlist.txt"
    {"afii61574","202D"},
#line 1008 "pdfdoc/glyphlist.txt"
    {"afii57686","05E6"},
#line 2466 "pdfdoc/glyphlist.txt"
    {"labengali","09B2"},
#line 2964 "pdfdoc/glyphlist.txt"
    {"otildeacute","1E4D"},
#line 227 "pdfdoc/glyphlist.txt"
    {"Gbreve","011E"},
#line 1045 "pdfdoc/glyphlist.txt"
    {"afii61664","200C"},
#line 697 "pdfdoc/glyphlist.txt"
    {"Xcircle","24CD"},
#line 1438 "pdfdoc/glyphlist.txt"
    {"commasuperior","F6E2"},
#line 1988 "pdfdoc/glyphlist.txt"
    {"glottalinvertedstroke","01BE"},
#line 2553 "pdfdoc/glyphlist.txt"
    {"lowlinedashed","FE4D"},
#line 866 "pdfdoc/glyphlist.txt"
    {"afii10079","043D"},
#line 2984 "pdfdoc/glyphlist.txt"
    {"pageup","21DE"},
#line 115 "pdfdoc/glyphlist.txt"
    {"Dafrican","0189"},
#line 4018 "pdfdoc/glyphlist.txt"
    {"veharabic","06A4"},
#line 234 "pdfdoc/glyphlist.txt"
    {"Gdotaccent","0120"},
#line 855 "pdfdoc/glyphlist.txt"
    {"afii10068","0433"},
#line 2746 "pdfdoc/glyphlist.txt"
    {"nieuntikeutkorean","3166"},
#line 1646 "pdfdoc/glyphlist.txt"
    {"dotlessi","0131"},
#line 845 "pdfdoc/glyphlist.txt"
    {"afii10058","0409"},
#line 885 "pdfdoc/glyphlist.txt"
    {"afii10098","0491"},
#line 1006 "pdfdoc/glyphlist.txt"
    {"afii57684","05E4"},
#line 1577 "pdfdoc/glyphlist.txt"
    {"ddagurmukhi","0A21"},
#line 2293 "pdfdoc/glyphlist.txt"
    {"intisquare","3305"},
#line 2630 "pdfdoc/glyphlist.txt"
    {"menarmenian","0574"},
#line 618 "pdfdoc/glyphlist.txt"
    {"Tsmall","F774"},
#line 2874 "pdfdoc/glyphlist.txt"
    {"odeva","0913"},
#line 1831 "pdfdoc/glyphlist.txt"
    {"fathatanarabic","064B"},
#line 2172 "pdfdoc/glyphlist.txt"
    {"hungarumlaut","02DD"},
#line 973 "pdfdoc/glyphlist.txt"
    {"afii57506","067E"},
#line 1795 "pdfdoc/glyphlist.txt"
    {"esuperior","F6EC"},
#line 3578 "pdfdoc/glyphlist.txt"
    {"slash","002F"},
#line 916 "pdfdoc/glyphlist.txt"
    {"afii57393","0661"},
#line 1131 "pdfdoc/glyphlist.txt"
    {"aringbelow","1E01"},
#line 2381 "pdfdoc/glyphlist.txt"
    {"kashidaautonosidebearingarabic","0640"},
#line 1046 "pdfdoc/glyphlist.txt"
    {"afii63167","066D"},
#line 102 "pdfdoc/glyphlist.txt"
    {"Cheharmenian","0543"},
#line 876 "pdfdoc/glyphlist.txt"
    {"afii10089","0447"},
#line 828 "pdfdoc/glyphlist.txt"
    {"afii10041","0427"},
#line 1880 "pdfdoc/glyphlist.txt"
    {"fivehackarabic","0665"},
#line 3400 "pdfdoc/glyphlist.txt"
    {"saraathai","0E30"},
#line 2860 "pdfdoc/glyphlist.txt"
    {"ocandragujarati","0A91"},
#line 3411 "pdfdoc/glyphlist.txt"
    {"sarauthai","0E38"},
#line 1209 "pdfdoc/glyphlist.txt"
    {"ayinhebrew","05E2"},
#line 1544 "pdfdoc/glyphlist.txt"
    {"dammatanarabic","064C"},
#line 827 "pdfdoc/glyphlist.txt"
    {"afii10040","0426"},
#line 416 "pdfdoc/glyphlist.txt"
    {"Obarredcyrillic","04E8"},
#line 3406 "pdfdoc/glyphlist.txt"
    {"saraothai","0E42"},
#line 3401 "pdfdoc/glyphlist.txt"
    {"saraethai","0E40"},
#line 3405 "pdfdoc/glyphlist.txt"
    {"saraithai","0E34"},
#line 4282 "pdfdoc/glyphlist.txt"
    {"zhearmenian","056A"},
#line 1726 "pdfdoc/glyphlist.txt"
    {"eightperiod","248F"},
#line 829 "pdfdoc/glyphlist.txt"
    {"afii10042","0428"},
#line 1850 "pdfdoc/glyphlist.txt"
    {"filledbox","25A0"},
#line 1484 "pdfdoc/glyphlist.txt"
    {"cornerbracketrighthalfwidth","FF63"},
#line 865 "pdfdoc/glyphlist.txt"
    {"afii10078","043C"},
#line 970 "pdfdoc/glyphlist.txt"
    {"afii57458","0652"},
#line 898 "pdfdoc/glyphlist.txt"
    {"afii10145","040F"},
#line 3459 "pdfdoc/glyphlist.txt"
    {"sevencircle","2466"},
#line 2834 "pdfdoc/glyphlist.txt"
    {"numbersign","0023"},
#line 418 "pdfdoc/glyphlist.txt"
    {"Obreve","014E"},
#line 832 "pdfdoc/glyphlist.txt"
    {"afii10045","042B"},
#line 900 "pdfdoc/glyphlist.txt"
    {"afii10147","0472"},
#line 2824 "pdfdoc/glyphlist.txt"
    {"nsuperior","207F"},
#line 1533 "pdfdoc/glyphlist.txt"
    {"daletqubutshebrew","05D3 05BB"},
#line 890 "pdfdoc/glyphlist.txt"
    {"afii10103","0456"},
#line 834 "pdfdoc/glyphlist.txt"
    {"afii10047","042D"},
#line 995 "pdfdoc/glyphlist.txt"
    {"afii57673","05D9"},
#line 3603 "pdfdoc/glyphlist.txt"
    {"squarecc","33C4"},
#line 2092 "pdfdoc/glyphlist.txt"
    {"hdotaccent","1E23"},
#line 272 "pdfdoc/glyphlist.txt"
    {"Hungarumlautsmall","F6F8"},
#line 1042 "pdfdoc/glyphlist.txt"
    {"afii61573","202C"},
#line 703 "pdfdoc/glyphlist.txt"
    {"Xsmall","F778"},
#line 991 "pdfdoc/glyphlist.txt"
    {"afii57669","05D5"},
#line 1483 "pdfdoc/glyphlist.txt"
    {"cornerbracketright","300D"},
#line 2574 "pdfdoc/glyphlist.txt"
    {"madeva","092E"},
#line 2965 "pdfdoc/glyphlist.txt"
    {"otildedieresis","1E4F"},
#line 151 "pdfdoc/glyphlist.txt"
    {"Echarmenian","0535"},
#line 2491 "pdfdoc/glyphlist.txt"
    {"lamfinalarabic","FEDE"},
#line 922 "pdfdoc/glyphlist.txt"
    {"afii57399","0667"},
#line 1192 "pdfdoc/glyphlist.txt"
    {"atmonospace","FF20"},
#line 954 "pdfdoc/glyphlist.txt"
    {"afii57441","0641"},
#line 369 "pdfdoc/glyphlist.txt"
    {"Liwnarmenian","053C"},
#line 2159 "pdfdoc/glyphlist.txt"
    {"hoonsquare","3342"},
#line 1919 "pdfdoc/glyphlist.txt"
    {"foursuperior","2074"},
#line 748 "pdfdoc/glyphlist.txt"
    {"Zlinebelow","1E94"},
#line 2444 "pdfdoc/glyphlist.txt"
    {"kmonospace","FF4B"},
#line 875 "pdfdoc/glyphlist.txt"
    {"afii10088","0446"},
#line 953 "pdfdoc/glyphlist.txt"
    {"afii57440","0640"},
#line 615 "pdfdoc/glyphlist.txt"
    {"Tretroflexhook","01AE"},
#line 1624 "pdfdoc/glyphlist.txt"
    {"dlinebelow","1E0F"},
#line 77 "pdfdoc/glyphlist.txt"
    {"Blinebelow","1E06"},
#line 1777 "pdfdoc/glyphlist.txt"
    {"equalsuperior","207C"},
#line 134 "pdfdoc/glyphlist.txt"
    {"Dlinebelow","1E0E"},
#line 2940 "pdfdoc/glyphlist.txt"
    {"onethai","0E51"},
#line 372 "pdfdoc/glyphlist.txt"
    {"Llinebelow","1E3A"},
#line 955 "pdfdoc/glyphlist.txt"
    {"afii57442","0642"},
#line 512 "pdfdoc/glyphlist.txt"
    {"Rlinebelow","1E5E"},
#line 404 "pdfdoc/glyphlist.txt"
    {"Nlinebelow","1E48"},
#line 620 "pdfdoc/glyphlist.txt"
    {"Tworoman","2161"},
#line 1005 "pdfdoc/glyphlist.txt"
    {"afii57683","05E3"},
#line 487 "pdfdoc/glyphlist.txt"
    {"Piwrarmenian","0553"},
#line 2311 "pdfdoc/glyphlist.txt"
    {"isuperior","F6ED"},
#line 958 "pdfdoc/glyphlist.txt"
    {"afii57445","0645"},
#line 4037 "pdfdoc/glyphlist.txt"
    {"visargagujarati","0A83"},
#line 4001 "pdfdoc/glyphlist.txt"
    {"v","0076"},
#line 1547 "pdfdoc/glyphlist.txt"
    {"dargalefthebrew","05A7"},
#line 1560 "pdfdoc/glyphlist.txt"
    {"dblintegral","222C"},
#line 721 "pdfdoc/glyphlist.txt"
    {"Yiwnarmenian","0552"},
#line 925 "pdfdoc/glyphlist.txt"
    {"afii57403","061B"},
#line 4005 "pdfdoc/glyphlist.txt"
    {"vakatakana","30F7"},
#line 4049 "pdfdoc/glyphlist.txt"
    {"vukatakana","30F4"},
#line 4234 "pdfdoc/glyphlist.txt"
    {"zadeva","095B"},
#line 4044 "pdfdoc/glyphlist.txt"
    {"vokatakana","30FA"},
#line 3105 "pdfdoc/glyphlist.txt"
    {"plussmall","FE62"},
#line 4022 "pdfdoc/glyphlist.txt"
    {"vekatakana","30F9"},
#line 896 "pdfdoc/glyphlist.txt"
    {"afii10109","045C"},
#line 4031 "pdfdoc/glyphlist.txt"
    {"vikatakana","30F8"},
#line 2896 "pdfdoc/glyphlist.txt"
    {"okatakana","30AA"},
#line 1001 "pdfdoc/glyphlist.txt"
    {"afii57679","05DF"},
#line 2671 "pdfdoc/glyphlist.txt"
    {"mparen","24A8"},
#line 990 "pdfdoc/glyphlist.txt"
    {"afii57668","05D4"},
#line 985 "pdfdoc/glyphlist.txt"
    {"afii57658","05C3"},
#line 2814 "pdfdoc/glyphlist.txt"
    {"notless","226E"},
#line 921 "pdfdoc/glyphlist.txt"
    {"afii57398","0666"},
#line 740 "pdfdoc/glyphlist.txt"
    {"Zedescendercyrillic","0498"},
#line 1417 "pdfdoc/glyphlist.txt"
    {"cmonospace","FF43"},
#line 3224 "pdfdoc/glyphlist.txt"
    {"r","0072"},
#line 899 "pdfdoc/glyphlist.txt"
    {"afii10146","0462"},
#line 3298 "pdfdoc/glyphlist.txt"
    {"rho","03C1"},
#line 833 "pdfdoc/glyphlist.txt"
    {"afii10046","042C"},
#line 1437 "pdfdoc/glyphlist.txt"
    {"commasmall","FE50"},
#line 2546 "pdfdoc/glyphlist.txt"
    {"logicalnot","00AC"},
#line 1485 "pdfdoc/glyphlist.txt"
    {"cornerbracketrightvertical","FE42"},
#line 2537 "pdfdoc/glyphlist.txt"
    {"llvocalicbengali","09E1"},
#line 1184 "pdfdoc/glyphlist.txt"
    {"asteriskmath","2217"},
#line 2807 "pdfdoc/glyphlist.txt"
    {"notelement","2209"},
#line 808 "pdfdoc/glyphlist.txt"
    {"afii10021","0414"},
#line 1011 "pdfdoc/glyphlist.txt"
    {"afii57689","05E9"},
#line 1866 "pdfdoc/glyphlist.txt"
    {"finaltsadi","05E5"},
#line 3605 "pdfdoc/glyphlist.txt"
    {"squarediagonalcrosshatchfill","25A9"},
#line 807 "pdfdoc/glyphlist.txt"
    {"afii10020","0413"},
#line 1401 "pdfdoc/glyphlist.txt"
    {"circleplus","2295"},
#line 2512 "pdfdoc/glyphlist.txt"
    {"ldotaccent","0140"},
#line 1859 "pdfdoc/glyphlist.txt"
    {"finalkafshevahebrew","05DA 05B0"},
#line 4035 "pdfdoc/glyphlist.txt"
    {"visargabengali","0983"},
#line 2716 "pdfdoc/glyphlist.txt"
    {"nbspace","00A0"},
#line 4294 "pdfdoc/glyphlist.txt"
    {"zparen","24B5"},
#line 1598 "pdfdoc/glyphlist.txt"
    {"deltaturned","018D"},
#line 809 "pdfdoc/glyphlist.txt"
    {"afii10022","0415"},
#line 1181 "pdfdoc/glyphlist.txt"
    {"asterisk","002A"},
#line 927 "pdfdoc/glyphlist.txt"
    {"afii57409","0621"},
#line 895 "pdfdoc/glyphlist.txt"
    {"afii10108","045B"},
#line 831 "pdfdoc/glyphlist.txt"
    {"afii10044","042A"},
#line 1000 "pdfdoc/glyphlist.txt"
    {"afii57678","05DE"},
#line 812 "pdfdoc/glyphlist.txt"
    {"afii10025","0417"},
#line 2780 "pdfdoc/glyphlist.txt"
    {"nlinebelow","1E49"},
#line 257 "pdfdoc/glyphlist.txt"
    {"Hadescendercyrillic","04B2"},
#line 2770 "pdfdoc/glyphlist.txt"
    {"ninesuperior","2079"},
#line 1424 "pdfdoc/glyphlist.txt"
    {"colonsmall","FE55"},
#line 3244 "pdfdoc/glyphlist.txt"
    {"ratio","2236"},
#line 984 "pdfdoc/glyphlist.txt"
    {"afii57645","05BE"},
#line 1182 "pdfdoc/glyphlist.txt"
    {"asteriskaltonearabic","066D"},
#line 3246 "pdfdoc/glyphlist.txt"
    {"rcaron","0159"},
#line 1300 "pdfdoc/glyphlist.txt"
    {"bracerighttp","F8FC"},
#line 814 "pdfdoc/glyphlist.txt"
    {"afii10027","0419"},
#line 2166 "pdfdoc/glyphlist.txt"
    {"hsuperior","02B0"},
#line 2836 "pdfdoc/glyphlist.txt"
    {"numbersignsmall","FE5F"},
#line 1040 "pdfdoc/glyphlist.txt"
    {"afii61289","2113"},
#line 3299 "pdfdoc/glyphlist.txt"
    {"rhook","027D"},
#line 976 "pdfdoc/glyphlist.txt"
    {"afii57509","06AF"},
#line 2903 "pdfdoc/glyphlist.txt"
    {"omdeva","0950"},
#line 3369 "pdfdoc/glyphlist.txt"
    {"ruthai","0E24"},
#line 959 "pdfdoc/glyphlist.txt"
    {"afii57446","0646"},
#line 1758 "pdfdoc/glyphlist.txt"
    {"endescendercyrillic","04A3"},
#line 3238 "pdfdoc/glyphlist.txt"
    {"rahiragana","3089"},
#line 3132 "pdfdoc/glyphlist.txt"
    {"psicyrillic","0471"},
#line 3363 "pdfdoc/glyphlist.txt"
    {"ruhiragana","308B"},
#line 939 "pdfdoc/glyphlist.txt"
    {"afii57421","062D"},
#line 3351 "pdfdoc/glyphlist.txt"
    {"rreharabic","0691"},
#line 3343 "pdfdoc/glyphlist.txt"
    {"rohiragana","308D"},
#line 2947 "pdfdoc/glyphlist.txt"
    {"oparen","24AA"},
#line 3263 "pdfdoc/glyphlist.txt"
    {"rehiragana","308C"},
#line 3324 "pdfdoc/glyphlist.txt"
    {"rihiragana","308A"},
#line 938 "pdfdoc/glyphlist.txt"
    {"afii57420","062C"},
#line 3607 "pdfdoc/glyphlist.txt"
    {"squarekg","338F"},
#line 3267 "pdfdoc/glyphlist.txt"
    {"resh","05E8"},
#line 1504 "pdfdoc/glyphlist.txt"
    {"dadfinalarabic","FEBE"},
#line 1010 "pdfdoc/glyphlist.txt"
    {"afii57688","05E8"},
#line 189 "pdfdoc/glyphlist.txt"
    {"Eopen","0190"},
#line 914 "pdfdoc/glyphlist.txt"
    {"afii57388","060C"},
#line 2522 "pdfdoc/glyphlist.txt"
    {"lessorgreater","2276"},
#line 1185 "pdfdoc/glyphlist.txt"
    {"asteriskmonospace","FF0A"},
#line 3296 "pdfdoc/glyphlist.txt"
    {"rhabengali","09DD"},
#line 940 "pdfdoc/glyphlist.txt"
    {"afii57422","062E"},
#line 2946 "pdfdoc/glyphlist.txt"
    {"oopen","0254"},
#line 3348 "pdfdoc/glyphlist.txt"
    {"rrabengali","09DC"},
#line 957 "pdfdoc/glyphlist.txt"
    {"afii57444","0644"},
#line 4256 "pdfdoc/glyphlist.txt"
    {"zdot","017C"},
#line 943 "pdfdoc/glyphlist.txt"
    {"afii57425","0631"},
#line 1157 "pdfdoc/glyphlist.txt"
    {"arrowrightdblstroke","21CF"},
#line 802 "pdfdoc/glyphlist.txt"
    {"afii00208","2015"},
#line 2949 "pdfdoc/glyphlist.txt"
    {"option","2325"},
#line 1824 "pdfdoc/glyphlist.txt"
    {"ezhtail","01BA"},
#line 945 "pdfdoc/glyphlist.txt"
    {"afii57427","0633"},
#line 2934 "pdfdoc/glyphlist.txt"
    {"oneparen","2474"},
#line 3327 "pdfdoc/glyphlist.txt"
    {"ring","02DA"},
#line 349 "pdfdoc/glyphlist.txt"
    {"Klinebelow","1E34"},
#line 1784 "pdfdoc/glyphlist.txt"
    {"esdescendercyrillic","04AB"},
#line 2540 "pdfdoc/glyphlist.txt"
    {"llvocalicvowelsigndeva","0963"},
#line 2928 "pdfdoc/glyphlist.txt"
    {"onehangzhou","3021"},
#line 1410 "pdfdoc/glyphlist.txt"
    {"clickdental","01C0"},
#line 4015 "pdfdoc/glyphlist.txt"
    {"vcircle","24E5"},
#line 2539 "pdfdoc/glyphlist.txt"
    {"llvocalicvowelsignbengali","09E3"},
#line 897 "pdfdoc/glyphlist.txt"
    {"afii10110","045E"},
#line 975 "pdfdoc/glyphlist.txt"
    {"afii57508","0698"},
#line 3479 "pdfdoc/glyphlist.txt"
    {"seventhai","0E57"},
#line 1257 "pdfdoc/glyphlist.txt"
    {"blackdiamond","25C6"},
#line 1776 "pdfdoc/glyphlist.txt"
    {"equalsmall","FE66"},
#line 3260 "pdfdoc/glyphlist.txt"
    {"reharabic","0631"},
#line 910 "pdfdoc/glyphlist.txt"
    {"afii299","200E"},
#line 4024 "pdfdoc/glyphlist.txt"
    {"verticalbar","007C"},
#line 2080 "pdfdoc/glyphlist.txt"
    {"hatafsegol30","05B1"},
#line 1249 "pdfdoc/glyphlist.txt"
    {"bhagurmukhi","0A2D"},
#line 2475 "pdfdoc/glyphlist.txt"
    {"lamalefhamzabelowfinalarabic","FEFA"},
#line 2476 "pdfdoc/glyphlist.txt"
    {"lamalefhamzabelowisolatedarabic","FEF9"},
#line 165 "pdfdoc/glyphlist.txt"
    {"Edot","0116"},
#line 1709 "pdfdoc/glyphlist.txt"
    {"eightbengali","09EE"},
#line 3483 "pdfdoc/glyphlist.txt"
    {"shacyrillic","0448"},
#line 3120 "pdfdoc/glyphlist.txt"
    {"prescription","211E"},
#line 830 "pdfdoc/glyphlist.txt"
    {"afii10043","0429"},
#line 1648 "pdfdoc/glyphlist.txt"
    {"dotlessjstrokehook","0284"},
#line 813 "pdfdoc/glyphlist.txt"
    {"afii10026","0418"},
#line 2113 "pdfdoc/glyphlist.txt"
    {"heiseierasquare","337B"},
#line 2136 "pdfdoc/glyphlist.txt"
    {"hiriqnarrowhebrew","05B4"},
#line 804 "pdfdoc/glyphlist.txt"
    {"afii10017","0410"},
#line 700 "pdfdoc/glyphlist.txt"
    {"Xeharmenian","053D"},
#line 2552 "pdfdoc/glyphlist.txt"
    {"lowlinecmb","0332"},
#line 2981 "pdfdoc/glyphlist.txt"
    {"pacute","1E55"},
#line 2558 "pdfdoc/glyphlist.txt"
    {"lsuperior","F6EE"},
#line 294 "pdfdoc/glyphlist.txt"
    {"Iebrevecyrillic","04D6"},
#line 333 "pdfdoc/glyphlist.txt"
    {"Kadescendercyrillic","049A"},
#line 22 "pdfdoc/glyphlist.txt"
    {"AEsmall","F7E6"},
#line 929 "pdfdoc/glyphlist.txt"
    {"afii57411","0623"},
#line 811 "pdfdoc/glyphlist.txt"
    {"afii10024","0416"},
#line 928 "pdfdoc/glyphlist.txt"
    {"afii57410","0622"},
#line 1210 "pdfdoc/glyphlist.txt"
    {"b","0062"},
#line 791 "pdfdoc/glyphlist.txt"
    {"addakgurmukhi","0A71"},
#line 2139 "pdfdoc/glyphlist.txt"
    {"hlinebelow","1E96"},
#line 2078 "pdfdoc/glyphlist.txt"
    {"hatafsegol17","05B1"},
#line 1970 "pdfdoc/glyphlist.txt"
    {"ghainfinalarabic","FECE"},
#line 930 "pdfdoc/glyphlist.txt"
    {"afii57412","0624"},
#line 581 "pdfdoc/glyphlist.txt"
    {"Shimacoptic","03EC"},
#line 3016 "pdfdoc/glyphlist.txt"
    {"paseqhebrew","05C0"},
#line 2538 "pdfdoc/glyphlist.txt"
    {"llvocalicdeva","0961"},
#line 3249 "pdfdoc/glyphlist.txt"
    {"rcommaaccent","0157"},
#line 933 "pdfdoc/glyphlist.txt"
    {"afii57415","0627"},
#line 977 "pdfdoc/glyphlist.txt"
    {"afii57511","0679"},
#line 956 "pdfdoc/glyphlist.txt"
    {"afii57443","0643"},
#line 944 "pdfdoc/glyphlist.txt"
    {"afii57426","0632"},
#line 4254 "pdfdoc/glyphlist.txt"
    {"zcircumflex","1E91"},
#line 1890 "pdfdoc/glyphlist.txt"
    {"fivesuperior","2075"},
#line 2545 "pdfdoc/glyphlist.txt"
    {"logicaland","2227"},
#line 935 "pdfdoc/glyphlist.txt"
    {"afii57417","0629"},
#line 4006 "pdfdoc/glyphlist.txt"
    {"vav","05D5"},
#line 836 "pdfdoc/glyphlist.txt"
    {"afii10049","042F"},
#line 978 "pdfdoc/glyphlist.txt"
    {"afii57512","0688"},
#line 2426 "pdfdoc/glyphlist.txt"
    {"khorakhangthai","0E06"},
#line 2472 "pdfdoc/glyphlist.txt"
    {"lamaleffinalarabic","FEFC"},
#line 2152 "pdfdoc/glyphlist.txt"
    {"holamquarterhebrew","05B9"},
#line 1937 "pdfdoc/glyphlist.txt"
    {"gagurmukhi","0A17"},
#line 757 "pdfdoc/glyphlist.txt"
    {"aagurmukhi","0A06"},
#line 2810 "pdfdoc/glyphlist.txt"
    {"notgreater","226F"},
#line 1199 "pdfdoc/glyphlist.txt"
    {"augurmukhi","0A14"},
#line 1535 "pdfdoc/glyphlist.txt"
    {"daletsegolhebrew","05D3 05B6"},
#line 2328 "pdfdoc/glyphlist.txt"
    {"jagurmukhi","0A1C"},
#line 1512 "pdfdoc/glyphlist.txt"
    {"dagurmukhi","0A26"},
#line 942 "pdfdoc/glyphlist.txt"
    {"afii57424","0630"},
#line 1058 "pdfdoc/glyphlist.txt"
    {"aigurmukhi","0A10"},
#line 1524 "pdfdoc/glyphlist.txt"
    {"dalethiriq","05D3 05B4"},
#line 2077 "pdfdoc/glyphlist.txt"
    {"hatafsegol","05B1"},
#line 1519 "pdfdoc/glyphlist.txt"
    {"dalethatafpatah","05D3 05B2"},
#line 153 "pdfdoc/glyphlist.txt"
    {"Ecircumflex","00CA"},
#line 2034 "pdfdoc/glyphlist.txt"
    {"hadescendercyrillic","04B3"},
#line 1526 "pdfdoc/glyphlist.txt"
    {"daletholam","05D3 05B9"},
#line 3013 "pdfdoc/glyphlist.txt"
    {"parenrighttp","F8F6"},
#line 566 "pdfdoc/glyphlist.txt"
    {"Schwacyrillic","04D8"},
#line 2865 "pdfdoc/glyphlist.txt"
    {"ocircumflex","00F4"},
#line 158 "pdfdoc/glyphlist.txt"
    {"Ecircumflexhookabove","1EC2"},
#line 154 "pdfdoc/glyphlist.txt"
    {"Ecircumflexacute","1EBE"},
#line 2869 "pdfdoc/glyphlist.txt"
    {"ocircumflexhookabove","1ED5"},
#line 3239 "pdfdoc/glyphlist.txt"
    {"rakatakana","30E9"},
#line 1827 "pdfdoc/glyphlist.txt"
    {"fagurmukhi","0A5E"},
#line 3364 "pdfdoc/glyphlist.txt"
    {"rukatakana","30EB"},
#line 25 "pdfdoc/glyphlist.txt"
    {"Abreve","0102"},
#line 2866 "pdfdoc/glyphlist.txt"
    {"ocircumflexacute","1ED1"},
#line 3344 "pdfdoc/glyphlist.txt"
    {"rokatakana","30ED"},
#line 3265 "pdfdoc/glyphlist.txt"
    {"rekatakana","30EC"},
#line 3325 "pdfdoc/glyphlist.txt"
    {"rikatakana","30EA"},
#line 961 "pdfdoc/glyphlist.txt"
    {"afii57449","0649"},
#line 901 "pdfdoc/glyphlist.txt"
    {"afii10148","0474"},
#line 835 "pdfdoc/glyphlist.txt"
    {"afii10048","042E"},
#line 2436 "pdfdoc/glyphlist.txt"
    {"kiyeokcirclekorean","3260"},
#line 26 "pdfdoc/glyphlist.txt"
    {"Abreveacute","1EAE"},
#line 2416 "pdfdoc/glyphlist.txt"
    {"khieukhaparenkorean","3218"},
#line 803 "pdfdoc/glyphlist.txt"
    {"afii08941","20A4"},
#line 2529 "pdfdoc/glyphlist.txt"
    {"liwnarmenian","056C"},
#line 2249 "pdfdoc/glyphlist.txt"
    {"iebrevecyrillic","04D7"},
#line 2083 "pdfdoc/glyphlist.txt"
    {"hatafsegolquarterhebrew","05B1"},
#line 810 "pdfdoc/glyphlist.txt"
    {"afii10023","0401"},
#line 1697 "pdfdoc/glyphlist.txt"
    {"eegurmukhi","0A0F"},
#line 3378 "pdfdoc/glyphlist.txt"
    {"sacute","015B"},
#line 2448 "pdfdoc/glyphlist.txt"
    {"kokaithai","0E01"},
#line 160 "pdfdoc/glyphlist.txt"
    {"Ecircumflextilde","1EC4"},
#line 1828 "pdfdoc/glyphlist.txt"
    {"fahrenheit","2109"},
#line 1211 "pdfdoc/glyphlist.txt"
    {"babengali","09AC"},
#line 2535 "pdfdoc/glyphlist.txt"
    {"llinebelow","1E3B"},
#line 2870 "pdfdoc/glyphlist.txt"
    {"ocircumflextilde","1ED7"},
#line 3067 "pdfdoc/glyphlist.txt"
    {"phagurmukhi","0A2B"},
#line 157 "pdfdoc/glyphlist.txt"
    {"Ecircumflexgrave","1EC0"},
#line 2577 "pdfdoc/glyphlist.txt"
    {"mahapakhhebrew","05A4"},
#line 934 "pdfdoc/glyphlist.txt"
    {"afii57416","0628"},
#line 2658 "pdfdoc/glyphlist.txt"
    {"mlonglegturned","0270"},
#line 2868 "pdfdoc/glyphlist.txt"
    {"ocircumflexgrave","1ED3"},
#line 1282 "pdfdoc/glyphlist.txt"
    {"bobaimaithai","0E1A"},
#line 186 "pdfdoc/glyphlist.txt"
    {"Enghecyrillic","04A4"},
#line 1347 "pdfdoc/glyphlist.txt"
    {"carriagereturn","21B5"},
#line 4046 "pdfdoc/glyphlist.txt"
    {"vtilde","1E7D"},
#line 3415 "pdfdoc/glyphlist.txt"
    {"scarondotaccent","1E67"},
#line 4047 "pdfdoc/glyphlist.txt"
    {"vturned","028C"},
#line 1724 "pdfdoc/glyphlist.txt"
    {"eightoldstyle","F738"},
#line 1383 "pdfdoc/glyphlist.txt"
    {"chieuchaparenkorean","3217"},
#line 1023 "pdfdoc/glyphlist.txt"
    {"afii57795","05B6"},
#line 960 "pdfdoc/glyphlist.txt"
    {"afii57448","0648"},
#line 3103 "pdfdoc/glyphlist.txt"
    {"plusmod","02D6"},
#line 2709 "pdfdoc/glyphlist.txt"
    {"nagurmukhi","0A28"},
#line 2205 "pdfdoc/glyphlist.txt"
    {"ideographicfestivalparen","3240"},
#line 1496 "pdfdoc/glyphlist.txt"
    {"cyrFlex","F6D2"},
#line 2206 "pdfdoc/glyphlist.txt"
    {"ideographicfinancialcircle","3296"},
#line 2906 "pdfdoc/glyphlist.txt"
    {"omegacyrillic","0461"},
#line 932 "pdfdoc/glyphlist.txt"
    {"afii57414","0626"},
#line 3417 "pdfdoc/glyphlist.txt"
    {"schwa","0259"},
#line 1025 "pdfdoc/glyphlist.txt"
    {"afii57797","05B8"},
#line 2578 "pdfdoc/glyphlist.txt"
    {"mahapakhlefthebrew","05A4"},
#line 2024 "pdfdoc/glyphlist.txt"
    {"guillemotright","00BB"},
#line 941 "pdfdoc/glyphlist.txt"
    {"afii57423","062F"},
#line 2417 "pdfdoc/glyphlist.txt"
    {"khieukhcirclekorean","326A"},
#line 2207 "pdfdoc/glyphlist.txt"
    {"ideographicfinancialparen","3236"},
#line 794 "pdfdoc/glyphlist.txt"
    {"adieresiscyrillic","04D3"},
#line 636 "pdfdoc/glyphlist.txt"
    {"Udieresiscaron","01D9"},
#line 795 "pdfdoc/glyphlist.txt"
    {"adieresismacron","01DF"},
#line 637 "pdfdoc/glyphlist.txt"
    {"Udieresiscyrillic","04F0"},
#line 639 "pdfdoc/glyphlist.txt"
    {"Udieresismacron","01D5"},
#line 2812 "pdfdoc/glyphlist.txt"
    {"notgreaternorless","2279"},
#line 818 "pdfdoc/glyphlist.txt"
    {"afii10031","041D"},
#line 2434 "pdfdoc/glyphlist.txt"
    {"kiyeokacirclekorean","326E"},
#line 816 "pdfdoc/glyphlist.txt"
    {"afii10029","041B"},
#line 3626 "pdfdoc/glyphlist.txt"
    {"ssanghieuhkorean","3185"},
#line 2811 "pdfdoc/glyphlist.txt"
    {"notgreaternorequal","2271"},
#line 817 "pdfdoc/glyphlist.txt"
    {"afii10030","041C"},
#line 2419 "pdfdoc/glyphlist.txt"
    {"khieukhparenkorean","320A"},
#line 634 "pdfdoc/glyphlist.txt"
    {"Udieresisacute","01D7"},
#line 3625 "pdfdoc/glyphlist.txt"
    {"ssangcieuckorean","3149"},
#line 585 "pdfdoc/glyphlist.txt"
    {"Softsigncyrillic","042C"},
#line 980 "pdfdoc/glyphlist.txt"
    {"afii57514","06BA"},
#line 819 "pdfdoc/glyphlist.txt"
    {"afii10032","041E"},
#line 2435 "pdfdoc/glyphlist.txt"
    {"kiyeokaparenkorean","320E"},
#line 3629 "pdfdoc/glyphlist.txt"
    {"ssangnieunkorean","3165"},
#line 1230 "pdfdoc/glyphlist.txt"
    {"behfinalarabic","FE90"},
#line 793 "pdfdoc/glyphlist.txt"
    {"adieresis","00E4"},
#line 1186 "pdfdoc/glyphlist.txt"
    {"asterisksmall","FE61"},
#line 690 "pdfdoc/glyphlist.txt"
    {"Wdieresis","1E84"},
#line 633 "pdfdoc/glyphlist.txt"
    {"Udieresis","00DC"},
#line 2418 "pdfdoc/glyphlist.txt"
    {"khieukhkorean","314B"},
#line 1521 "pdfdoc/glyphlist.txt"
    {"dalethatafsegol","05D3 05B1"},
#line 822 "pdfdoc/glyphlist.txt"
    {"afii10035","0421"},
#line 289 "pdfdoc/glyphlist.txt"
    {"Idieresiscyrillic","04E4"},
#line 2415 "pdfdoc/glyphlist.txt"
    {"khieukhacirclekorean","3278"},
#line 2423 "pdfdoc/glyphlist.txt"
    {"khokhwaithai","0E04"},
#line 824 "pdfdoc/glyphlist.txt"
    {"afii10037","0423"},
#line 2265 "pdfdoc/glyphlist.txt"
    {"iigurmukhi","0A08"},
#line 3471 "pdfdoc/glyphlist.txt"
    {"sevenparen","247A"},
#line 288 "pdfdoc/glyphlist.txt"
    {"Idieresisacute","1E2E"},
#line 3240 "pdfdoc/glyphlist.txt"
    {"rakatakanahalfwidth","FF97"},
#line 1384 "pdfdoc/glyphlist.txt"
    {"chieuchcirclekorean","3269"},
#line 3365 "pdfdoc/glyphlist.txt"
    {"rukatakanahalfwidth","FF99"},
#line 3345 "pdfdoc/glyphlist.txt"
    {"rokatakanahalfwidth","FF9B"},
#line 3266 "pdfdoc/glyphlist.txt"
    {"rekatakanahalfwidth","FF9A"},
#line 3326 "pdfdoc/glyphlist.txt"
    {"rikatakanahalfwidth","FF98"},
#line 1063 "pdfdoc/glyphlist.txt"
    {"ainmedialarabic","FECC"},
#line 2888 "pdfdoc/glyphlist.txt"
    {"ohornacute","1EDB"},
#line 1941 "pdfdoc/glyphlist.txt"
    {"gammalatinsmall","0263"},
#line 1520 "pdfdoc/glyphlist.txt"
    {"dalethatafpatahhebrew","05D3 05B2"},
#line 287 "pdfdoc/glyphlist.txt"
    {"Idieresis","00CF"},
#line 3248 "pdfdoc/glyphlist.txt"
    {"rcircle","24E1"},
#line 949 "pdfdoc/glyphlist.txt"
    {"afii57431","0637"},
#line 1386 "pdfdoc/glyphlist.txt"
    {"chieuchparenkorean","3209"},
#line 947 "pdfdoc/glyphlist.txt"
    {"afii57429","0635"},
#line 710 "pdfdoc/glyphlist.txt"
    {"Ydieresis","0178"},
#line 3520 "pdfdoc/glyphlist.txt"
    {"shindagesh","FB49"},
#line 1038 "pdfdoc/glyphlist.txt"
    {"afii57929","02BC"},
#line 948 "pdfdoc/glyphlist.txt"
    {"afii57430","0636"},
#line 815 "pdfdoc/glyphlist.txt"
    {"afii10028","041A"},
#line 264 "pdfdoc/glyphlist.txt"
    {"Hdieresis","1E26"},
#line 1522 "pdfdoc/glyphlist.txt"
    {"dalethatafsegolhebrew","05D3 05B1"},
#line 1839 "pdfdoc/glyphlist.txt"
    {"fehmedialarabic","FED4"},
#line 3476 "pdfdoc/glyphlist.txt"
    {"seventeencircle","2470"},
#line 950 "pdfdoc/glyphlist.txt"
    {"afii57432","0638"},
#line 1385 "pdfdoc/glyphlist.txt"
    {"chieuchkorean","314A"},
#line 1693 "pdfdoc/glyphlist.txt"
    {"edieresis","00EB"},
#line 3477 "pdfdoc/glyphlist.txt"
    {"seventeenparen","2484"},
#line 1382 "pdfdoc/glyphlist.txt"
    {"chieuchacirclekorean","3277"},
#line 3497 "pdfdoc/glyphlist.txt"
    {"shagurmukhi","0A36"},
#line 2661 "pdfdoc/glyphlist.txt"
    {"mmonospace","FF4D"},
#line 1024 "pdfdoc/glyphlist.txt"
    {"afii57796","05BB"},
#line 1536 "pdfdoc/glyphlist.txt"
    {"daletsheva","05D3 05B0"},
#line 1253 "pdfdoc/glyphlist.txt"
    {"bilabialclick","0298"},
#line 2819 "pdfdoc/glyphlist.txt"
    {"notsucceeds","2281"},
#line 3561 "pdfdoc/glyphlist.txt"
    {"sixgurmukhi","0A6C"},
#line 2079 "pdfdoc/glyphlist.txt"
    {"hatafsegol24","05B1"},
#line 931 "pdfdoc/glyphlist.txt"
    {"afii57413","0625"},
#line 2082 "pdfdoc/glyphlist.txt"
    {"hatafsegolnarrowhebrew","05B1"},
#line 1029 "pdfdoc/glyphlist.txt"
    {"afii57801","05B1"},
#line 2116 "pdfdoc/glyphlist.txt"
    {"hekutaarusquare","3336"},
#line 3464 "pdfdoc/glyphlist.txt"
    {"sevengurmukhi","0A6D"},
#line 1530 "pdfdoc/glyphlist.txt"
    {"daletqamats","05D3 05B8"},
#line 1028 "pdfdoc/glyphlist.txt"
    {"afii57800","05B2"},
#line 1039 "pdfdoc/glyphlist.txt"
    {"afii61248","2105"},
#line 1498 "pdfdoc/glyphlist.txt"
    {"cyrflex","F6D5"},
#line 806 "pdfdoc/glyphlist.txt"
    {"afii10019","0412"},
#line 1379 "pdfdoc/glyphlist.txt"
    {"chekhakassiancyrillic","04CC"},
#line 3522 "pdfdoc/glyphlist.txt"
    {"shindageshshindot","FB2C"},
#line 1030 "pdfdoc/glyphlist.txt"
    {"afii57802","05B3"},
#line 2980 "pdfdoc/glyphlist.txt"
    {"pabengali","09AA"},
#line 1022 "pdfdoc/glyphlist.txt"
    {"afii57794","05B5"},
#line 2738 "pdfdoc/glyphlist.txt"
    {"nieunaparenkorean","320F"},
#line 946 "pdfdoc/glyphlist.txt"
    {"afii57428","0634"},
#line 1926 "pdfdoc/glyphlist.txt"
    {"fraction","2044"},
#line 979 "pdfdoc/glyphlist.txt"
    {"afii57513","0691"},
#line 2830 "pdfdoc/glyphlist.txt"
    {"nuktabengali","09BC"},
#line 2037 "pdfdoc/glyphlist.txt"
    {"hagurmukhi","0A39"},
#line 2176 "pdfdoc/glyphlist.txt"
    {"hypheninferior","F6E5"},
#line 63 "pdfdoc/glyphlist.txt"
    {"Aringbelow","1E00"},
#line 1034 "pdfdoc/glyphlist.txt"
    {"afii57807","05BC"},
#line 4291 "pdfdoc/glyphlist.txt"
    {"zmonospace","FF5A"},
#line 823 "pdfdoc/glyphlist.txt"
    {"afii10036","0422"},
#line 2338 "pdfdoc/glyphlist.txt"
    {"jeeminitialarabic","FE9F"},
#line 801 "pdfdoc/glyphlist.txt"
    {"aemacron","01E3"},
#line 2247 "pdfdoc/glyphlist.txt"
    {"idieresiscyrillic","04E5"},
#line 1224 "pdfdoc/glyphlist.txt"
    {"bdotaccent","1E03"},
#line 2006 "pdfdoc/glyphlist.txt"
    {"gravecmb","0300"},
#line 3524 "pdfdoc/glyphlist.txt"
    {"shindageshsindot","FB2D"},
#line 1015 "pdfdoc/glyphlist.txt"
    {"afii57700","FB4B"},
#line 2117 "pdfdoc/glyphlist.txt"
    {"henghook","0267"},
#line 2246 "pdfdoc/glyphlist.txt"
    {"idieresisacute","1E2F"},
#line 937 "pdfdoc/glyphlist.txt"
    {"afii57419","062B"},
#line 821 "pdfdoc/glyphlist.txt"
    {"afii10034","0420"},
#line 805 "pdfdoc/glyphlist.txt"
    {"afii10018","0411"},
#line 2404 "pdfdoc/glyphlist.txt"
    {"khacyrillic","0445"},
#line 4124 "pdfdoc/glyphlist.txt"
    {"xdotaccent","1E8B"},
#line 182 "pdfdoc/glyphlist.txt"
    {"Emonospace","FF25"},
#line 2245 "pdfdoc/glyphlist.txt"
    {"idieresis","00EF"},
#line 2163 "pdfdoc/glyphlist.txt"
    {"hotsprings","2668"},
#line 1016 "pdfdoc/glyphlist.txt"
    {"afii57705","FB1F"},
#line 2544 "pdfdoc/glyphlist.txt"
    {"lochulathai","0E2C"},
#line 2914 "pdfdoc/glyphlist.txt"
    {"omonospace","FF4F"},
#line 2131 "pdfdoc/glyphlist.txt"
    {"hiriq","05B4"},
#line 4002 "pdfdoc/glyphlist.txt"
    {"vadeva","0935"},
#line 2751 "pdfdoc/glyphlist.txt"
    {"nikhahitthai","0E4D"},
#line 981 "pdfdoc/glyphlist.txt"
    {"afii57519","06D2"},
#line 3040 "pdfdoc/glyphlist.txt"
    {"pehfinalarabic","FB57"},
#line 2736 "pdfdoc/glyphlist.txt"
    {"nhookretroflex","0273"},
#line 2010 "pdfdoc/glyphlist.txt"
    {"gravemonospace","FF40"},
#line 417 "pdfdoc/glyphlist.txt"
    {"Obarreddieresiscyrillic","04EA"},
#line 3115 "pdfdoc/glyphlist.txt"
    {"poplathai","0E1B"},
#line 2743 "pdfdoc/glyphlist.txt"
    {"nieunpansioskorean","3168"},
#line 640 "pdfdoc/glyphlist.txt"
    {"Udieresissmall","F7FC"},
#line 2799 "pdfdoc/glyphlist.txt"
    {"nooninitialarabic","FEE7"},
#line 2323 "pdfdoc/glyphlist.txt"
    {"j","006A"},
#line 1531 "pdfdoc/glyphlist.txt"
    {"daletqamatshebrew","05D3 05B8"},
#line 952 "pdfdoc/glyphlist.txt"
    {"afii57434","063A"},
#line 936 "pdfdoc/glyphlist.txt"
    {"afii57418","062A"},
#line 1021 "pdfdoc/glyphlist.txt"
    {"afii57793","05B4"},
#line 638 "pdfdoc/glyphlist.txt"
    {"Udieresisgrave","01DB"},
#line 1033 "pdfdoc/glyphlist.txt"
    {"afii57806","05B9"},
#line 3071 "pdfdoc/glyphlist.txt"
    {"phieuphaparenkorean","321A"},
#line 1723 "pdfdoc/glyphlist.txt"
    {"eightmonospace","FF18"},
#line 2457 "pdfdoc/glyphlist.txt"
    {"ksicyrillic","046F"},
#line 1545 "pdfdoc/glyphlist.txt"
    {"danda","0964"},
#line 159 "pdfdoc/glyphlist.txt"
    {"Ecircumflexsmall","F7EA"},
#line 3523 "pdfdoc/glyphlist.txt"
    {"shindageshshindothebrew","FB2C"},
#line 2470 "pdfdoc/glyphlist.txt"
    {"lagurmukhi","0A32"},
#line 290 "pdfdoc/glyphlist.txt"
    {"Idieresissmall","F7EF"},
#line 3377 "pdfdoc/glyphlist.txt"
    {"sabengali","09B8"},
#line 4045 "pdfdoc/glyphlist.txt"
    {"vparen","24B1"},
#line 1374 "pdfdoc/glyphlist.txt"
    {"checyrillic","0447"},
#line 711 "pdfdoc/glyphlist.txt"
    {"Ydieresissmall","F7FF"},
#line 1620 "pdfdoc/glyphlist.txt"
    {"divides","2223"},
#line 982 "pdfdoc/glyphlist.txt"
    {"afii57534","06D5"},
#line 2124 "pdfdoc/glyphlist.txt"
    {"hieuhaparenkorean","321B"},
#line 635 "pdfdoc/glyphlist.txt"
    {"Udieresisbelow","1E72"},
#line 433 "pdfdoc/glyphlist.txt"
    {"Odieresiscyrillic","04E6"},
#line 1629 "pdfdoc/glyphlist.txt"
    {"dochadathai","0E0E"},
#line 4029 "pdfdoc/glyphlist.txt"
    {"vewarmenian","057E"},
#line 1032 "pdfdoc/glyphlist.txt"
    {"afii57804","05C1"},
#line 2750 "pdfdoc/glyphlist.txt"
    {"nikhahitleftthai","F899"},
#line 1958 "pdfdoc/glyphlist.txt"
    {"gereshhebrew","05F3"},
#line 605 "pdfdoc/glyphlist.txt"
    {"Thornsmall","F7FE"},
#line 3361 "pdfdoc/glyphlist.txt"
    {"rturned","0279"},
#line 2595 "pdfdoc/glyphlist.txt"
    {"maithoupperleftthai","F88D"},
#line 2091 "pdfdoc/glyphlist.txt"
    {"hdieresis","1E27"},
#line 820 "pdfdoc/glyphlist.txt"
    {"afii10033","041F"},
#line 432 "pdfdoc/glyphlist.txt"
    {"Odieresis","00D6"},
#line 2599 "pdfdoc/glyphlist.txt"
    {"maitriupperleftthai","F890"},
#line 3525 "pdfdoc/glyphlist.txt"
    {"shindageshsindothebrew","FB2D"},
#line 2495 "pdfdoc/glyphlist.txt"
    {"lamkhahinitialarabic","FCCB"},
#line 983 "pdfdoc/glyphlist.txt"
    {"afii57636","20AA"},
#line 2042 "pdfdoc/glyphlist.txt"
    {"hahmedialarabic","FEA4"},
#line 2112 "pdfdoc/glyphlist.txt"
    {"hehmedialarabic","FEEC"},
#line 1322 "pdfdoc/glyphlist.txt"
    {"bsuperior","F6EA"},
#line 3582 "pdfdoc/glyphlist.txt"
    {"smileface","263A"},
#line 1027 "pdfdoc/glyphlist.txt"
    {"afii57799","05B0"},
#line 2859 "pdfdoc/glyphlist.txt"
    {"ocandradeva","0911"},
#line 3072 "pdfdoc/glyphlist.txt"
    {"phieuphcirclekorean","326C"},
#line 1508 "pdfdoc/glyphlist.txt"
    {"dageshhebrew","05BC"},
#line 2098 "pdfdoc/glyphlist.txt"
    {"hedagesh","FB34"},
#line 3473 "pdfdoc/glyphlist.txt"
    {"sevenpersian","06F7"},
#line 1241 "pdfdoc/glyphlist.txt"
    {"betasymbolgreek","03D0"},
#line 2950 "pdfdoc/glyphlist.txt"
    {"ordfeminine","00AA"},
#line 4129 "pdfdoc/glyphlist.txt"
    {"xsuperior","02E3"},
#line 3074 "pdfdoc/glyphlist.txt"
    {"phieuphparenkorean","320C"},
#line 2740 "pdfdoc/glyphlist.txt"
    {"nieuncirclekorean","3261"},
#line 2805 "pdfdoc/glyphlist.txt"
    {"noonnoonfinalarabic","FC8D"},
#line 771 "pdfdoc/glyphlist.txt"
    {"abrevegrave","1EB1"},
#line 3030 "pdfdoc/glyphlist.txt"
    {"pdotaccent","1E57"},
#line 2354 "pdfdoc/glyphlist.txt"
    {"kacute","1E31"},
#line 3073 "pdfdoc/glyphlist.txt"
    {"phieuphkorean","314D"},
#line 951 "pdfdoc/glyphlist.txt"
    {"afii57433","0639"},
#line 3340 "pdfdoc/glyphlist.txt"
    {"rlongleg","027C"},
#line 1047 "pdfdoc/glyphlist.txt"
    {"afii64937","02BD"},
#line 1036 "pdfdoc/glyphlist.txt"
    {"afii57841","05BF"},
#line 610 "pdfdoc/glyphlist.txt"
    {"Tmonospace","FF34"},
#line 3070 "pdfdoc/glyphlist.txt"
    {"phieuphacirclekorean","327A"},
#line 2606 "pdfdoc/glyphlist.txt"
    {"mars","2642"},
#line 826 "pdfdoc/glyphlist.txt"
    {"afii10039","0425"},
#line 3291 "pdfdoc/glyphlist.txt"
    {"reviahebrew","0597"},
#line 1037 "pdfdoc/glyphlist.txt"
    {"afii57842","05C0"},
#line 1026 "pdfdoc/glyphlist.txt"
    {"afii57798","05B7"},
#line 4247 "pdfdoc/glyphlist.txt"
    {"zayin","05D6"},
#line 1031 "pdfdoc/glyphlist.txt"
    {"afii57803","05C2"},
#line 4028 "pdfdoc/glyphlist.txt"
    {"verticallinemod","02C8"},
#line 4036 "pdfdoc/glyphlist.txt"
    {"visargadeva","0903"},
#line 628 "pdfdoc/glyphlist.txt"
    {"Ucircumflexbelow","1E76"},
#line 1572 "pdfdoc/glyphlist.txt"
    {"dcircumflexbelow","1E13"},
#line 119 "pdfdoc/glyphlist.txt"
    {"Dcircumflexbelow","1E12"},
#line 363 "pdfdoc/glyphlist.txt"
    {"Lcircumflexbelow","1E3C"},
#line 396 "pdfdoc/glyphlist.txt"
    {"Ncircumflexbelow","1E4A"},
#line 3261 "pdfdoc/glyphlist.txt"
    {"reharmenian","0580"},
#line 1333 "pdfdoc/glyphlist.txt"
    {"cacute","0107"},
#line 2452 "pdfdoc/glyphlist.txt"
    {"koppacyrillic","0481"},
#line 825 "pdfdoc/glyphlist.txt"
    {"afii10038","0424"},
#line 702 "pdfdoc/glyphlist.txt"
    {"Xmonospace","FF38"},
#line 3371 "pdfdoc/glyphlist.txt"
    {"rvocalicdeva","090B"},
#line 2835 "pdfdoc/glyphlist.txt"
    {"numbersignmonospace","FF03"},
#line 3647 "pdfdoc/glyphlist.txt"
    {"summation","2211"},
#line 784 "pdfdoc/glyphlist.txt"
    {"acutecmb","0301"},
#line 3293 "pdfdoc/glyphlist.txt"
    {"revlogicalnot","2310"},
#line 909 "pdfdoc/glyphlist.txt"
    {"afii10846","04D9"},
#line 3390 "pdfdoc/glyphlist.txt"
    {"sallallahoualayhewasallamarabic","FDFA"},
#line 1621 "pdfdoc/glyphlist.txt"
    {"divisionslash","2215"},
#line 2586 "pdfdoc/glyphlist.txt"
    {"maiekthai","0E48"},
#line 1279 "pdfdoc/glyphlist.txt"
    {"blinebelow","1E07"},
#line 3372 "pdfdoc/glyphlist.txt"
    {"rvocalicgujarati","0A8B"},
#line 1685 "pdfdoc/glyphlist.txt"
    {"ecircumflexbelow","1E19"},
#line 2497 "pdfdoc/glyphlist.txt"
    {"lammedialarabic","FEE0"},
#line 3054 "pdfdoc/glyphlist.txt"
    {"periodhalfwidth","FF61"},
#line 1270 "pdfdoc/glyphlist.txt"
    {"blacksmallsquare","25AA"},
#line 2523 "pdfdoc/glyphlist.txt"
    {"lessoverequal","2266"},
#line 2527 "pdfdoc/glyphlist.txt"
    {"lhookretroflex","026D"},
#line 2125 "pdfdoc/glyphlist.txt"
    {"hieuhcirclekorean","326D"},
#line 2496 "pdfdoc/glyphlist.txt"
    {"lamlamhehisolatedarabic","FDF2"},
#line 3424 "pdfdoc/glyphlist.txt"
    {"sdotaccent","1E61"},
#line 1392 "pdfdoc/glyphlist.txt"
    {"cieucacirclekorean","3276"},
#line 3370 "pdfdoc/glyphlist.txt"
    {"rvocalicbengali","098B"},
#line 3465 "pdfdoc/glyphlist.txt"
    {"sevenhackarabic","0667"},
#line 434 "pdfdoc/glyphlist.txt"
    {"Odieresissmall","F7F6"},
#line 459 "pdfdoc/glyphlist.txt"
    {"Omegatonos","038F"},
#line 2407 "pdfdoc/glyphlist.txt"
    {"khagurmukhi","0A16"},
#line 1821 "pdfdoc/glyphlist.txt"
    {"ezhcaron","01EF"},
#line 2099 "pdfdoc/glyphlist.txt"
    {"hedageshhebrew","FB34"},
#line 3228 "pdfdoc/glyphlist.txt"
    {"radeva","0930"},
#line 2720 "pdfdoc/glyphlist.txt"
    {"ncircumflexbelow","1E4B"},
#line 3631 "pdfdoc/glyphlist.txt"
    {"ssangsioskorean","3146"},
#line 1966 "pdfdoc/glyphlist.txt"
    {"ghadeva","0918"},
#line 2343 "pdfdoc/glyphlist.txt"
    {"jhadeva","091D"},
#line 2084 "pdfdoc/glyphlist.txt"
    {"hatafsegolwidehebrew","05B1"},
#line 1602 "pdfdoc/glyphlist.txt"
    {"dhadeva","0927"},
#line 1362 "pdfdoc/glyphlist.txt"
    {"centinferior","F6DF"},
#line 4027 "pdfdoc/glyphlist.txt"
    {"verticallinelowmod","02CC"},
#line 2547 "pdfdoc/glyphlist.txt"
    {"logicalnotreversed","2310"},
#line 3081 "pdfdoc/glyphlist.txt"
    {"phosamphaothai","0E20"},
#line 3368 "pdfdoc/glyphlist.txt"
    {"rupiah","F6DD"},
#line 3025 "pdfdoc/glyphlist.txt"
    {"patahquarterhebrew","05B7"},
#line 3053 "pdfdoc/glyphlist.txt"
    {"periodcentered","00B7"},
#line 2695 "pdfdoc/glyphlist.txt"
    {"musicsharpsign","266F"},
#line 789 "pdfdoc/glyphlist.txt"
    {"acyrillic","0430"},
#line 630 "pdfdoc/glyphlist.txt"
    {"Ucyrillic","0423"},
#line 2402 "pdfdoc/glyphlist.txt"
    {"kgreenlandic","0138"},
#line 2386 "pdfdoc/glyphlist.txt"
    {"kastrokecyrillic","049F"},
#line 1069 "pdfdoc/glyphlist.txt"
    {"akatakanahalfwidth","FF71"},
#line 2999 "pdfdoc/glyphlist.txt"
    {"parenleftinferior","208D"},
#line 3347 "pdfdoc/glyphlist.txt"
    {"rparen","24AD"},
#line 3437 "pdfdoc/glyphlist.txt"
    {"segol1f","05B6"},
#line 1370 "pdfdoc/glyphlist.txt"
    {"chagurmukhi","0A1B"},
#line 2820 "pdfdoc/glyphlist.txt"
    {"notsuperset","2285"},
#line 2953 "pdfdoc/glyphlist.txt"
    {"oshortdeva","0912"},
#line 3098 "pdfdoc/glyphlist.txt"
    {"piwrarmenian","0583"},
#line 285 "pdfdoc/glyphlist.txt"
    {"Icyrillic","0406"},
#line 3558 "pdfdoc/glyphlist.txt"
    {"sixcircleinversesansserif","278F"},
#line 1245 "pdfdoc/glyphlist.txt"
    {"betrafehebrew","FB4C"},
#line 1049 "pdfdoc/glyphlist.txt"
    {"agujarati","0A85"},
#line 2849 "pdfdoc/glyphlist.txt"
    {"nyagurmukhi","0A1E"},
#line 1690 "pdfdoc/glyphlist.txt"
    {"ecyrillic","0454"},
#line 3374 "pdfdoc/glyphlist.txt"
    {"rvocalicvowelsigndeva","0943"},
#line 1168 "pdfdoc/glyphlist.txt"
    {"arrowupleftofdown","21C5"},
#line 2943 "pdfdoc/glyphlist.txt"
    {"oogonekmacron","01ED"},
#line 3373 "pdfdoc/glyphlist.txt"
    {"rvocalicvowelsignbengali","09C3"},
#line 3375 "pdfdoc/glyphlist.txt"
    {"rvocalicvowelsigngujarati","0AC3"},
#line 1506 "pdfdoc/glyphlist.txt"
    {"dadmedialarabic","FEC0"},
#line 1734 "pdfdoc/glyphlist.txt"
    {"ekatakanahalfwidth","FF74"},
#line 3633 "pdfdoc/glyphlist.txt"
    {"ssuperior","F6F2"},
#line 3009 "pdfdoc/glyphlist.txt"
    {"parenrightinferior","208E"},
#line 2784 "pdfdoc/glyphlist.txt"
    {"nnadeva","0923"},
#line 4271 "pdfdoc/glyphlist.txt"
    {"zeroinferior","2080"},
#line 156 "pdfdoc/glyphlist.txt"
    {"Ecircumflexdotbelow","1EC6"},
#line 46 "pdfdoc/glyphlist.txt"
    {"Adieresiscyrillic","04D2"},
#line 47 "pdfdoc/glyphlist.txt"
    {"Adieresismacron","01DE"},
#line 2867 "pdfdoc/glyphlist.txt"
    {"ocircumflexdotbelow","1ED9"},
#line 3478 "pdfdoc/glyphlist.txt"
    {"seventeenperiod","2498"},
#line 1701 "pdfdoc/glyphlist.txt"
    {"egujarati","0A8F"},
#line 1404 "pdfdoc/glyphlist.txt"
    {"circlewithrighthalfblack","25D1"},
#line 2353 "pdfdoc/glyphlist.txt"
    {"kabengali","0995"},
#line 3612 "pdfdoc/glyphlist.txt"
    {"squaremg","338E"},
#line 3467 "pdfdoc/glyphlist.txt"
    {"sevenideographicparen","3226"},
#line 2730 "pdfdoc/glyphlist.txt"
    {"ngadeva","0919"},
#line 45 "pdfdoc/glyphlist.txt"
    {"Adieresis","00C4"},
#line 2778 "pdfdoc/glyphlist.txt"
    {"nkatakanahalfwidth","FF9D"},
#line 1711 "pdfdoc/glyphlist.txt"
    {"eightcircleinversesansserif","2791"},
#line 3613 "pdfdoc/glyphlist.txt"
    {"squaremil","33D5"},
#line 4034 "pdfdoc/glyphlist.txt"
    {"viramagujarati","0ACD"},
#line 1018 "pdfdoc/glyphlist.txt"
    {"afii57717","05F1"},
#line 3515 "pdfdoc/glyphlist.txt"
    {"shevaquarterhebrew","05B0"},
#line 3618 "pdfdoc/glyphlist.txt"
    {"squareupperrighttolowerleftfill","25A8"},
#line 1595 "pdfdoc/glyphlist.txt"
    {"deleteleft","232B"},
#line 2190 "pdfdoc/glyphlist.txt"
    {"icyrillic","0456"},
#line 1638 "pdfdoc/glyphlist.txt"
    {"dollarsuperior","F6E4"},
#line 2274 "pdfdoc/glyphlist.txt"
    {"ikatakanahalfwidth","FF72"},
#line 1147 "pdfdoc/glyphlist.txt"
    {"arrowheadleftmod","02C2"},
#line 2487 "pdfdoc/glyphlist.txt"
    {"lamedholam","05DC 05B9"},
#line 1528 "pdfdoc/glyphlist.txt"
    {"daletpatah","05D3 05B7"},
#line 2488 "pdfdoc/glyphlist.txt"
    {"lamedholamdagesh","05DC 05B9 05BC"},
#line 1332 "pdfdoc/glyphlist.txt"
    {"cabengali","099A"},
#line 4038 "pdfdoc/glyphlist.txt"
    {"vmonospace","FF56"},
#line 2619 "pdfdoc/glyphlist.txt"
    {"meemmeeminitialarabic","FCD1"},
#line 2951 "pdfdoc/glyphlist.txt"
    {"ordmasculine","00BA"},
#line 3083 "pdfdoc/glyphlist.txt"
    {"pieupacirclekorean","3273"},
#line 2359 "pdfdoc/glyphlist.txt"
    {"kafarabic","0643"},
#line 1413 "pdfdoc/glyphlist.txt"
    {"club","2663"},
#line 715 "pdfdoc/glyphlist.txt"
    {"Yerudieresiscyrillic","04F8"},
#line 3165 "pdfdoc/glyphlist.txt"
    {"qhook","02A0"},
#line 1216 "pdfdoc/glyphlist.txt"
    {"bagurmukhi","0A2C"},
#line 1962 "pdfdoc/glyphlist.txt"
    {"gershayimhebrew","05F4"},
#line 1070 "pdfdoc/glyphlist.txt"
    {"akorean","314F"},
#line 3441 "pdfdoc/glyphlist.txt"
    {"segolquarterhebrew","05B6"},
#line 2257 "pdfdoc/glyphlist.txt"
    {"igujarati","0A87"},
#line 4284 "pdfdoc/glyphlist.txt"
    {"zhecyrillic","0436"},
#line 2509 "pdfdoc/glyphlist.txt"
    {"lcircumflexbelow","1E3D"},
#line 730 "pdfdoc/glyphlist.txt"
    {"Zaarmenian","0536"},
#line 1817 "pdfdoc/glyphlist.txt"
    {"exclammonospace","FF01"},
#line 1997 "pdfdoc/glyphlist.txt"
    {"gmacron","1E21"},
#line 2324 "pdfdoc/glyphlist.txt"
    {"jaarmenian","0571"},
#line 1093 "pdfdoc/glyphlist.txt"
    {"amacron","0101"},
#line 1500 "pdfdoc/glyphlist.txt"
    {"daarmenian","0564"},
#line 1126 "pdfdoc/glyphlist.txt"
    {"araeakorean","318D"},
#line 655 "pdfdoc/glyphlist.txt"
    {"Umacron","016A"},
#line 114 "pdfdoc/glyphlist.txt"
    {"Daarmenian","0534"},
#line 1626 "pdfdoc/glyphlist.txt"
    {"dmacron","0111"},
#line 497 "pdfdoc/glyphlist.txt"
    {"Raarmenian","054C"},
#line 907 "pdfdoc/glyphlist.txt"
    {"afii10831","F6C7"},
#line 21 "pdfdoc/glyphlist.txt"
    {"AEmacron","01E2"},
#line 1017 "pdfdoc/glyphlist.txt"
    {"afii57716","05F0"},
#line 320 "pdfdoc/glyphlist.txt"
    {"Jaarmenian","0541"},
#line 113 "pdfdoc/glyphlist.txt"
    {"DZcaron","01C4"},
#line 1635 "pdfdoc/glyphlist.txt"
    {"dollarmonospace","FF04"},
#line 2352 "pdfdoc/glyphlist.txt"
    {"kabashkircyrillic","04A1"},
#line 1909 "pdfdoc/glyphlist.txt"
    {"fourhangzhou","3024"},
#line 908 "pdfdoc/glyphlist.txt"
    {"afii10832","F6C8"},
#line 4250 "pdfdoc/glyphlist.txt"
    {"zayinhebrew","05D6"},
#line 1736 "pdfdoc/glyphlist.txt"
    {"ekorean","3154"},
#line 2957 "pdfdoc/glyphlist.txt"
    {"osmallhiragana","3049"},
#line 303 "pdfdoc/glyphlist.txt"
    {"Imacron","012A"},
#line 1896 "pdfdoc/glyphlist.txt"
    {"fofanthai","0E1F"},
#line 429 "pdfdoc/glyphlist.txt"
    {"Ocyrillic","041E"},
#line 3617 "pdfdoc/glyphlist.txt"
    {"squareupperlefttolowerrightfill","25A7"},
#line 719 "pdfdoc/glyphlist.txt"
    {"Yiarmenian","0545"},
#line 268 "pdfdoc/glyphlist.txt"
    {"Hoarmenian","0540"},
#line 2382 "pdfdoc/glyphlist.txt"
    {"kasmallkatakana","30F5"},
#line 1702 "pdfdoc/glyphlist.txt"
    {"eharmenian","0567"},
#line 3498 "pdfdoc/glyphlist.txt"
    {"shalshelethebrew","0593"},
#line 2401 "pdfdoc/glyphlist.txt"
    {"kesmallkatakana","30F6"},
#line 1745 "pdfdoc/glyphlist.txt"
    {"emacron","0113"},
#line 2744 "pdfdoc/glyphlist.txt"
    {"nieunparenkorean","3201"},
#line 1020 "pdfdoc/glyphlist.txt"
    {"afii57723","FB35"},
#line 3570 "pdfdoc/glyphlist.txt"
    {"sixpersian","06F6"},
#line 2983 "pdfdoc/glyphlist.txt"
    {"pagedown","21DF"},
#line 97 "pdfdoc/glyphlist.txt"
    {"Cheabkhasiancyrillic","04BC"},
#line 726 "pdfdoc/glyphlist.txt"
    {"Yusbigiotifiedcyrillic","046C"},
#line 2208 "pdfdoc/glyphlist.txt"
    {"ideographicfireparen","322B"},
#line 3472 "pdfdoc/glyphlist.txt"
    {"sevenperiod","248E"},
#line 579 "pdfdoc/glyphlist.txt"
    {"Sheicoptic","03E2"},
#line 48 "pdfdoc/glyphlist.txt"
    {"Adieresissmall","F7E4"},
#line 1123 "pdfdoc/glyphlist.txt"
    {"approxequalorimage","2252"},
#line 1328 "pdfdoc/glyphlist.txt"
    {"bulletoperator","2219"},
#line 2573 "pdfdoc/glyphlist.txt"
    {"macute","1E3F"},
#line 1797 "pdfdoc/glyphlist.txt"
    {"etarmenian","0568"},
#line 3544 "pdfdoc/glyphlist.txt"
    {"siosacirclekorean","3274"},
#line 2390 "pdfdoc/glyphlist.txt"
    {"kcalsquare","3389"},
#line 2433 "pdfdoc/glyphlist.txt"
    {"kirosquare","3314"},
#line 1446 "pdfdoc/glyphlist.txt"
    {"controlBEL","0007"},
#line 1445 "pdfdoc/glyphlist.txt"
    {"controlACK","0006"},
#line 1746 "pdfdoc/glyphlist.txt"
    {"emacronacute","1E17"},
#line 3546 "pdfdoc/glyphlist.txt"
    {"sioscieuckorean","317E"},
#line 2655 "pdfdoc/glyphlist.txt"
    {"minute","2032"},
#line 1454 "pdfdoc/glyphlist.txt"
    {"controlDEL","007F"},
#line 1914 "pdfdoc/glyphlist.txt"
    {"fouroldstyle","F734"},
#line 1450 "pdfdoc/glyphlist.txt"
    {"controlDC1","0011"},
#line 3630 "pdfdoc/glyphlist.txt"
    {"ssangpieupkorean","3143"},
#line 1455 "pdfdoc/glyphlist.txt"
    {"controlDLE","0010"},
#line 3550 "pdfdoc/glyphlist.txt"
    {"siosnieunkorean","317B"},
#line 3149 "pdfdoc/glyphlist.txt"
    {"qamats1c","05B8"},
#line 1747 "pdfdoc/glyphlist.txt"
    {"emacrongrave","1E15"},
#line 1467 "pdfdoc/glyphlist.txt"
    {"controlNAK","0015"},
#line 258 "pdfdoc/glyphlist.txt"
    {"Hardsigncyrillic","042A"},
#line 2489 "pdfdoc/glyphlist.txt"
    {"lamedholamdageshhebrew","05DC 05B9 05BC"},
#line 1722 "pdfdoc/glyphlist.txt"
    {"eightinferior","2088"},
#line 1451 "pdfdoc/glyphlist.txt"
    {"controlDC2","0012"},
#line 3341 "pdfdoc/glyphlist.txt"
    {"rlonglegturned","027A"},
#line 3382 "pdfdoc/glyphlist.txt"
    {"sadfinalarabic","FEBA"},
#line 83 "pdfdoc/glyphlist.txt"
    {"Caarmenian","053E"},
#line 1150 "pdfdoc/glyphlist.txt"
    {"arrowhorizex","F8E7"},
#line 248 "pdfdoc/glyphlist.txt"
    {"Gsmallhook","029B"},
#line 109 "pdfdoc/glyphlist.txt"
    {"Coarmenian","0551"},
#line 1473 "pdfdoc/glyphlist.txt"
    {"controlSUB","001A"},
#line 1474 "pdfdoc/glyphlist.txt"
    {"controlSYN","0016"},
#line 2275 "pdfdoc/glyphlist.txt"
    {"ikorean","3163"},
#line 559 "pdfdoc/glyphlist.txt"
    {"Sacutedotaccent","1E64"},
#line 1741 "pdfdoc/glyphlist.txt"
    {"elevenperiod","2492"},
#line 4233 "pdfdoc/glyphlist.txt"
    {"zacute","017A"},
#line 1233 "pdfdoc/glyphlist.txt"
    {"behmedialarabic","FE92"},
#line 1462 "pdfdoc/glyphlist.txt"
    {"controlFF","000C"},
#line 269 "pdfdoc/glyphlist.txt"
    {"Horicoptic","03E8"},
#line 2447 "pdfdoc/glyphlist.txt"
    {"kohmsquare","33C0"},
#line 2761 "pdfdoc/glyphlist.txt"
    {"ninehangzhou","3029"},
#line 4123 "pdfdoc/glyphlist.txt"
    {"xdieresis","1E8D"},
#line 2026 "pdfdoc/glyphlist.txt"
    {"guilsinglright","203A"},
#line 3148 "pdfdoc/glyphlist.txt"
    {"qamats1a","05B8"},
#line 2986 "pdfdoc/glyphlist.txt"
    {"pagurmukhi","0A2A"},
#line 1525 "pdfdoc/glyphlist.txt"
    {"dalethiriqhebrew","05D3 05B4"},
#line 1261 "pdfdoc/glyphlist.txt"
    {"blacklenticularbracketleft","3010"},
#line 1263 "pdfdoc/glyphlist.txt"
    {"blacklenticularbracketright","3011"},
#line 1466 "pdfdoc/glyphlist.txt"
    {"controlLF","000A"},
#line 2741 "pdfdoc/glyphlist.txt"
    {"nieunhieuhkorean","3136"},
#line 2278 "pdfdoc/glyphlist.txt"
    {"imacron","012B"},
#line 3146 "pdfdoc/glyphlist.txt"
    {"qamats","05B8"},
#line 3642 "pdfdoc/glyphlist.txt"
    {"suchthat","220B"},
#line 2739 "pdfdoc/glyphlist.txt"
    {"nieuncieuckorean","3135"},
#line 1472 "pdfdoc/glyphlist.txt"
    {"controlSTX","0001"},
#line 1356 "pdfdoc/glyphlist.txt"
    {"cdotaccent","010B"},
#line 1471 "pdfdoc/glyphlist.txt"
    {"controlSOT","0002"},
#line 2650 "pdfdoc/glyphlist.txt"
    {"minus","2212"},
#line 1599 "pdfdoc/glyphlist.txt"
    {"denominatorminusonenumeratorbengali","09F8"},
#line 146 "pdfdoc/glyphlist.txt"
    {"Eacute","00C9"},
#line 1465 "pdfdoc/glyphlist.txt"
    {"controlHT","0009"},
#line 243 "pdfdoc/glyphlist.txt"
    {"Gmacron","1E20"},
#line 2851 "pdfdoc/glyphlist.txt"
    {"oacute","00F3"},
#line 1226 "pdfdoc/glyphlist.txt"
    {"beamedsixteenthnotes","266C"},
#line 1122 "pdfdoc/glyphlist.txt"
    {"approxequal","2248"},
#line 2639 "pdfdoc/glyphlist.txt"
    {"mieumacirclekorean","3272"},
#line 1609 "pdfdoc/glyphlist.txt"
    {"diamondsuitwhite","2662"},
#line 2127 "pdfdoc/glyphlist.txt"
    {"hieuhparenkorean","320D"},
#line 29 "pdfdoc/glyphlist.txt"
    {"Abrevegrave","1EB0"},
#line 1440 "pdfdoc/glyphlist.txt"
    {"commaturnedmod","02BB"},
#line 3536 "pdfdoc/glyphlist.txt"
    {"sigmalunatesymbolgreek","03F2"},
#line 4268 "pdfdoc/glyphlist.txt"
    {"zerogujarati","0AE6"},
#line 2254 "pdfdoc/glyphlist.txt"
    {"ieungkorean","3147"},
#line 1444 "pdfdoc/glyphlist.txt"
    {"control","2303"},
#line 2765 "pdfdoc/glyphlist.txt"
    {"nineoldstyle","F739"},
#line 172 "pdfdoc/glyphlist.txt"
    {"Ehookabove","1EBA"},
#line 2156 "pdfdoc/glyphlist.txt"
    {"hookcmb","0309"},
#line 1406 "pdfdoc/glyphlist.txt"
    {"circumflexbelowcmb","032D"},
#line 1456 "pdfdoc/glyphlist.txt"
    {"controlEM","0019"},
#line 1460 "pdfdoc/glyphlist.txt"
    {"controlETB","0017"},
#line 4248 "pdfdoc/glyphlist.txt"
    {"zayindagesh","FB36"},
#line 2886 "pdfdoc/glyphlist.txt"
    {"ohookabove","1ECF"},
#line 2533 "pdfdoc/glyphlist.txt"
    {"lladeva","0933"},
#line 3273 "pdfdoc/glyphlist.txt"
    {"reshhebrew","05E8"},
#line 1262 "pdfdoc/glyphlist.txt"
    {"blacklenticularbracketleftvertical","FE3B"},
#line 1264 "pdfdoc/glyphlist.txt"
    {"blacklenticularbracketrightvertical","FE3C"},
#line 616 "pdfdoc/glyphlist.txt"
    {"Tsecyrillic","0426"},
#line 3518 "pdfdoc/glyphlist.txt"
    {"shimacoptic","03ED"},
#line 656 "pdfdoc/glyphlist.txt"
    {"Umacroncyrillic","04EE"},
#line 3150 "pdfdoc/glyphlist.txt"
    {"qamats27","05B8"},
#line 1378 "pdfdoc/glyphlist.txt"
    {"cheharmenian","0573"},
#line 3342 "pdfdoc/glyphlist.txt"
    {"rmonospace","FF52"},
#line 2141 "pdfdoc/glyphlist.txt"
    {"hoarmenian","0570"},
#line 1461 "pdfdoc/glyphlist.txt"
    {"controlETX","0003"},
#line 439 "pdfdoc/glyphlist.txt"
    {"Oharmenian","0555"},
#line 2153 "pdfdoc/glyphlist.txt"
    {"holamwidehebrew","05B9"},
#line 451 "pdfdoc/glyphlist.txt"
    {"Omacron","014C"},
#line 346 "pdfdoc/glyphlist.txt"
    {"Kheicoptic","03E6"},
#line 1314 "pdfdoc/glyphlist.txt"
    {"brevecmb","0306"},
#line 460 "pdfdoc/glyphlist.txt"
    {"Omicron","039F"},
#line 1458 "pdfdoc/glyphlist.txt"
    {"controlEOT","0004"},
#line 3502 "pdfdoc/glyphlist.txt"
    {"sheenfinalarabic","FEB6"},
#line 1453 "pdfdoc/glyphlist.txt"
    {"controlDC4","0014"},
#line 4042 "pdfdoc/glyphlist.txt"
    {"voicedmarkkana","309B"},
#line 2385 "pdfdoc/glyphlist.txt"
    {"kasratanarabic","064D"},
#line 3597 "pdfdoc/glyphlist.txt"
    {"spacehackarabic","0020"},
#line 4043 "pdfdoc/glyphlist.txt"
    {"voicedmarkkanahalfwidth","FF9E"},
#line 3386 "pdfdoc/glyphlist.txt"
    {"sagurmukhi","0A38"},
#line 304 "pdfdoc/glyphlist.txt"
    {"Imacroncyrillic","04E2"},
#line 1459 "pdfdoc/glyphlist.txt"
    {"controlESC","001B"},
#line 2294 "pdfdoc/glyphlist.txt"
    {"invbullet","25D8"},
#line 1342 "pdfdoc/glyphlist.txt"
    {"capslock","21EA"},
#line 1019 "pdfdoc/glyphlist.txt"
    {"afii57718","05F2"},
#line 2557 "pdfdoc/glyphlist.txt"
    {"lsquare","2113"},
#line 452 "pdfdoc/glyphlist.txt"
    {"Omacronacute","1E52"},
#line 1575 "pdfdoc/glyphlist.txt"
    {"ddadeva","0921"},
#line 3418 "pdfdoc/glyphlist.txt"
    {"schwacyrillic","04D9"},
#line 2374 "pdfdoc/glyphlist.txt"
    {"kappasymbolgreek","03F0"},
#line 563 "pdfdoc/glyphlist.txt"
    {"Scaronsmall","F6FD"},
#line 1881 "pdfdoc/glyphlist.txt"
    {"fivehangzhou","3025"},
#line 733 "pdfdoc/glyphlist.txt"
    {"Zcaronsmall","F6FF"},
#line 3043 "pdfdoc/glyphlist.txt"
    {"pehmedialarabic","FB59"},
#line 3147 "pdfdoc/glyphlist.txt"
    {"qamats10","05B8"},
#line 453 "pdfdoc/glyphlist.txt"
    {"Omacrongrave","1E50"},
#line 2055 "pdfdoc/glyphlist.txt"
    {"hamzasukunarabic","0621 0652"},
#line 1665 "pdfdoc/glyphlist.txt"
    {"dzeabkhasiancyrillic","04E1"},
#line 3292 "pdfdoc/glyphlist.txt"
    {"reviamugrashhebrew","0597"},
#line 142 "pdfdoc/glyphlist.txt"
    {"Dzeabkhasiancyrillic","04E0"},
#line 2057 "pdfdoc/glyphlist.txt"
    {"hardsigncyrillic","044A"},
#line 3033 "pdfdoc/glyphlist.txt"
    {"pedagesh","FB44"},
#line 4033 "pdfdoc/glyphlist.txt"
    {"viramadeva","094D"},
#line 380 "pdfdoc/glyphlist.txt"
    {"Macronsmall","F7AF"},
#line 3164 "pdfdoc/glyphlist.txt"
    {"qcircle","24E0"},
#line 3458 "pdfdoc/glyphlist.txt"
    {"sevenbengali","09ED"},
#line 2438 "pdfdoc/glyphlist.txt"
    {"kiyeokparenkorean","3200"},
#line 1187 "pdfdoc/glyphlist.txt"
    {"asterism","2042"},
#line 508 "pdfdoc/glyphlist.txt"
    {"Rfraktur","211C"},
#line 2925 "pdfdoc/glyphlist.txt"
    {"onegurmukhi","0A67"},
#line 3367 "pdfdoc/glyphlist.txt"
    {"rupeesignbengali","09F3"},
#line 2160 "pdfdoc/glyphlist.txt"
    {"horicoptic","03E9"},
#line 3548 "pdfdoc/glyphlist.txt"
    {"sioskiyeokkorean","317A"},
#line 3569 "pdfdoc/glyphlist.txt"
    {"sixperiod","248D"},
#line 1092 "pdfdoc/glyphlist.txt"
    {"alphatonos","03AC"},
#line 1083 "pdfdoc/glyphlist.txt"
    {"alefmaksuraarabic","0649"},
#line 1457 "pdfdoc/glyphlist.txt"
    {"controlENQ","0005"},
#line 3288 "pdfdoc/glyphlist.txt"
    {"reshtsere","05E8 05B5"},
#line 296 "pdfdoc/glyphlist.txt"
    {"Ifraktur","2111"},
#line 1085 "pdfdoc/glyphlist.txt"
    {"alefmaksurainitialarabic","FEF3"},
#line 2441 "pdfdoc/glyphlist.txt"
    {"klinebelow","1E35"},
#line 1663 "pdfdoc/glyphlist.txt"
    {"dzcaron","01C6"},
#line 3408 "pdfdoc/glyphlist.txt"
    {"saraueethai","0E37"},
#line 141 "pdfdoc/glyphlist.txt"
    {"Dzcaron","01C5"},
#line 1452 "pdfdoc/glyphlist.txt"
    {"controlDC3","0013"},
#line 1885 "pdfdoc/glyphlist.txt"
    {"fiveoldstyle","F735"},
#line 3604 "pdfdoc/glyphlist.txt"
    {"squarecm","339D"},
#line 1086 "pdfdoc/glyphlist.txt"
    {"alefmaksuramedialarabic","FEF4"},
#line 2567 "pdfdoc/glyphlist.txt"
    {"mabengali","09AE"},
#line 4249 "pdfdoc/glyphlist.txt"
    {"zayindageshhebrew","FB36"},
#line 2279 "pdfdoc/glyphlist.txt"
    {"imacroncyrillic","04E3"},
#line 1818 "pdfdoc/glyphlist.txt"
    {"exclamsmall","F721"},
#line 43 "pdfdoc/glyphlist.txt"
    {"Acyrillic","0410"},
#line 3915 "pdfdoc/glyphlist.txt"
    {"u","0075"},
#line 1035 "pdfdoc/glyphlist.txt"
    {"afii57839","05BD"},
#line 260 "pdfdoc/glyphlist.txt"
    {"Hbrevebelow","1E2A"},
#line 3586 "pdfdoc/glyphlist.txt"
    {"softsigncyrillic","044C"},
#line 3535 "pdfdoc/glyphlist.txt"
    {"sigmafinal","03C2"},
#line 1637 "pdfdoc/glyphlist.txt"
    {"dollarsmall","FE69"},
#line 1611 "pdfdoc/glyphlist.txt"
    {"dieresisacute","F6D7"},
#line 129 "pdfdoc/glyphlist.txt"
    {"DieresisAcute","F6CC"},
#line 1166 "pdfdoc/glyphlist.txt"
    {"arrowupdownbase","21A8"},
#line 2356 "pdfdoc/glyphlist.txt"
    {"kadescendercyrillic","049B"},
#line 1607 "pdfdoc/glyphlist.txt"
    {"dialytikatonoscmb","0344"},
#line 1610 "pdfdoc/glyphlist.txt"
    {"dieresis","00A8"},
#line 128 "pdfdoc/glyphlist.txt"
    {"Dieresis","F6CB"},
#line 3258 "pdfdoc/glyphlist.txt"
    {"registersans","F8E8"},
#line 1782 "pdfdoc/glyphlist.txt"
    {"ereversedcyrillic","044D"},
#line 1538 "pdfdoc/glyphlist.txt"
    {"dalettsere","05D3 05B5"},
#line 1271 "pdfdoc/glyphlist.txt"
    {"blacksmilingface","263B"},
#line 3943 "pdfdoc/glyphlist.txt"
    {"uhorn","01B0"},
#line 3553 "pdfdoc/glyphlist.txt"
    {"siostikeutkorean","317C"},
#line 3921 "pdfdoc/glyphlist.txt"
    {"ucaron","01D4"},
#line 3966 "pdfdoc/glyphlist.txt"
    {"union","222A"},
#line 3608 "pdfdoc/glyphlist.txt"
    {"squarekm","339E"},
#line 765 "pdfdoc/glyphlist.txt"
    {"abengali","0985"},
#line 1903 "pdfdoc/glyphlist.txt"
    {"fourcircle","2463"},
#line 3094 "pdfdoc/glyphlist.txt"
    {"pieuptikeutkorean","3173"},
#line 1969 "pdfdoc/glyphlist.txt"
    {"ghainarabic","063A"},
#line 3034 "pdfdoc/glyphlist.txt"
    {"pedageshhebrew","FB44"},
#line 1615 "pdfdoc/glyphlist.txt"
    {"dieresistonos","0385"},
#line 1979 "pdfdoc/glyphlist.txt"
    {"ghzsquare","3393"},
#line 3151 "pdfdoc/glyphlist.txt"
    {"qamats29","05B8"},
#line 4237 "pdfdoc/glyphlist.txt"
    {"zahfinalarabic","FEC6"},
#line 3433 "pdfdoc/glyphlist.txt"
    {"seeninitialarabic","FEB3"},
#line 205 "pdfdoc/glyphlist.txt"
    {"Etildebelow","1E1A"},
#line 2012 "pdfdoc/glyphlist.txt"
    {"greater","003E"},
#line 4032 "pdfdoc/glyphlist.txt"
    {"viramabengali","09CD"},
#line 2521 "pdfdoc/glyphlist.txt"
    {"lessorequivalent","2272"},
#line 1206 "pdfdoc/glyphlist.txt"
    {"aybarmenian","0561"},
#line 3470 "pdfdoc/glyphlist.txt"
    {"sevenoldstyle","F737"},
#line 1671 "pdfdoc/glyphlist.txt"
    {"ebengali","098F"},
#line 2137 "pdfdoc/glyphlist.txt"
    {"hiriqquarterhebrew","05B4"},
#line 648 "pdfdoc/glyphlist.txt"
    {"Uhorngrave","1EEA"},
#line 3017 "pdfdoc/glyphlist.txt"
    {"pashtahebrew","0599"},
#line 590 "pdfdoc/glyphlist.txt"
    {"Tbar","0166"},
#line 3980 "pdfdoc/glyphlist.txt"
    {"uring","016F"},
#line 1829 "pdfdoc/glyphlist.txt"
    {"fathaarabic","064E"},
#line 2519 "pdfdoc/glyphlist.txt"
    {"lessequalorgreater","22DA"},
#line 209 "pdfdoc/glyphlist.txt"
    {"Ezhreversed","01B8"},
#line 683 "pdfdoc/glyphlist.txt"
    {"Voarmenian","0548"},
#line 1967 "pdfdoc/glyphlist.txt"
    {"ghagujarati","0A98"},
#line 4270 "pdfdoc/glyphlist.txt"
    {"zerohackarabic","0660"},
#line 2548 "pdfdoc/glyphlist.txt"
    {"logicalor","2228"},
#line 2344 "pdfdoc/glyphlist.txt"
    {"jhagujarati","0A9D"},
#line 1603 "pdfdoc/glyphlist.txt"
    {"dhagujarati","0AA7"},
#line 2518 "pdfdoc/glyphlist.txt"
    {"lessequal","2264"},
#line 375 "pdfdoc/glyphlist.txt"
    {"Lslashsmall","F6F9"},
#line 2692 "pdfdoc/glyphlist.txt"
    {"musicalnote","266A"},
#line 3545 "pdfdoc/glyphlist.txt"
    {"siosaparenkorean","3214"},
#line 1541 "pdfdoc/glyphlist.txt"
    {"dammaarabic","064F"},
#line 1910 "pdfdoc/glyphlist.txt"
    {"fourideographicparen","3223"},
#line 2588 "pdfdoc/glyphlist.txt"
    {"maihanakatleftthai","F884"},
#line 3609 "pdfdoc/glyphlist.txt"
    {"squarekmcapital","33CE"},
#line 1247 "pdfdoc/glyphlist.txt"
    {"bhadeva","092D"},
#line 2755 "pdfdoc/glyphlist.txt"
    {"ninecircle","2468"},
#line 759 "pdfdoc/glyphlist.txt"
    {"aarusquare","3303"},
#line 3986 "pdfdoc/glyphlist.txt"
    {"ustraightstrokecyrillic","04B1"},
#line 2620 "pdfdoc/glyphlist.txt"
    {"meemmeemisolatedarabic","FC48"},
#line 3985 "pdfdoc/glyphlist.txt"
    {"ustraightcyrillic","04AF"},
#line 2657 "pdfdoc/glyphlist.txt"
    {"mirisquare","3349"},
#line 1274 "pdfdoc/glyphlist.txt"
    {"blackupperlefttriangle","25E4"},
#line 4011 "pdfdoc/glyphlist.txt"
    {"vavholam","FB4B"},
#line 1640 "pdfdoc/glyphlist.txt"
    {"dorusquare","3326"},
#line 2613 "pdfdoc/glyphlist.txt"
    {"mdotaccent","1E41"},
#line 3968 "pdfdoc/glyphlist.txt"
    {"uogonek","0173"},
#line 2087 "pdfdoc/glyphlist.txt"
    {"hbrevebelow","1E2B"},
#line 4111 "pdfdoc/glyphlist.txt"
    {"won","20A9"},
#line 58 "pdfdoc/glyphlist.txt"
    {"Amacron","0100"},
#line 1708 "pdfdoc/glyphlist.txt"
    {"eightarabic","0668"},
#line 1728 "pdfdoc/glyphlist.txt"
    {"eightroman","2177"},
#line 2184 "pdfdoc/glyphlist.txt"
    {"ibengali","0987"},
#line 3491 "pdfdoc/glyphlist.txt"
    {"shade","2592"},
#line 2745 "pdfdoc/glyphlist.txt"
    {"nieunsioskorean","3167"},
#line 643 "pdfdoc/glyphlist.txt"
    {"Ugravesmall","F7F9"},
#line 1441 "pdfdoc/glyphlist.txt"
    {"compass","263C"},
#line 2664 "pdfdoc/glyphlist.txt"
    {"mohmsquare","33C1"},
#line 1614 "pdfdoc/glyphlist.txt"
    {"dieresisgrave","F6D8"},
#line 436 "pdfdoc/glyphlist.txt"
    {"Ogoneksmall","F6FB"},
#line 130 "pdfdoc/glyphlist.txt"
    {"DieresisGrave","F6CD"},
#line 3994 "pdfdoc/glyphlist.txt"
    {"uumatragurmukhi","0A42"},
#line 1596 "pdfdoc/glyphlist.txt"
    {"deleteright","2326"},
#line 4257 "pdfdoc/glyphlist.txt"
    {"zdotaccent","017C"},
#line 1735 "pdfdoc/glyphlist.txt"
    {"ekonkargurmukhi","0A74"},
#line 4053 "pdfdoc/glyphlist.txt"
    {"wahiragana","308F"},
#line 2854 "pdfdoc/glyphlist.txt"
    {"obarredcyrillic","04E9"},
#line 4108 "pdfdoc/glyphlist.txt"
    {"wohiragana","3092"},
#line 3940 "pdfdoc/glyphlist.txt"
    {"ugurmukhi","0A09"},
#line 4072 "pdfdoc/glyphlist.txt"
    {"wehiragana","3091"},
#line 3394 "pdfdoc/glyphlist.txt"
    {"samekhhebrew","05E1"},
#line 4104 "pdfdoc/glyphlist.txt"
    {"wihiragana","3090"},
#line 2368 "pdfdoc/glyphlist.txt"
    {"kagurmukhi","0A15"},
#line 1062 "pdfdoc/glyphlist.txt"
    {"aininitialarabic","FECB"},
#line 298 "pdfdoc/glyphlist.txt"
    {"Igravesmall","F7EC"},
#line 1359 "pdfdoc/glyphlist.txt"
    {"cedillacmb","0327"},
#line 148 "pdfdoc/glyphlist.txt"
    {"Ebreve","0114"},
#line 2858 "pdfdoc/glyphlist.txt"
    {"obreve","014F"},
#line 2785 "pdfdoc/glyphlist.txt"
    {"nnagujarati","0AA3"},
#line 1838 "pdfdoc/glyphlist.txt"
    {"fehinitialarabic","FED3"},
#line 2762 "pdfdoc/glyphlist.txt"
    {"nineideographicparen","3228"},
#line 1974 "pdfdoc/glyphlist.txt"
    {"ghestrokecyrillic","0493"},
#line 1561 "pdfdoc/glyphlist.txt"
    {"dbllowline","2017"},
#line 166 "pdfdoc/glyphlist.txt"
    {"Edotaccent","0116"},
#line 1842 "pdfdoc/glyphlist.txt"
    {"ff","FB00"},
#line 2731 "pdfdoc/glyphlist.txt"
    {"ngagujarati","0A99"},
#line 567 "pdfdoc/glyphlist.txt"
    {"Schwadieresiscyrillic","04DA"},
#line 3216 "pdfdoc/glyphlist.txt"
    {"quoteleft","2018"},
#line 1448 "pdfdoc/glyphlist.txt"
    {"controlCAN","0018"},
#line 3564 "pdfdoc/glyphlist.txt"
    {"sixideographicparen","3225"},
#line 1963 "pdfdoc/glyphlist.txt"
    {"getamark","3013"},
#line 4115 "pdfdoc/glyphlist.txt"
    {"wring","1E98"},
#line 1449 "pdfdoc/glyphlist.txt"
    {"controlCR","000D"},
#line 4012 "pdfdoc/glyphlist.txt"
    {"vavholamhebrew","FB4B"},
#line 1636 "pdfdoc/glyphlist.txt"
    {"dollaroldstyle","F724"},
#line 1336 "pdfdoc/glyphlist.txt"
    {"cagurmukhi","0A1A"},
#line 2674 "pdfdoc/glyphlist.txt"
    {"msuperior","F6EF"},
#line 4050 "pdfdoc/glyphlist.txt"
    {"w","0077"},
#line 3220 "pdfdoc/glyphlist.txt"
    {"quoterightn","0149"},
#line 131 "pdfdoc/glyphlist.txt"
    {"Dieresissmall","F7A8"},
#line 1135 "pdfdoc/glyphlist.txt"
    {"arrowdashright","21E2"},
#line 3140 "pdfdoc/glyphlist.txt"
    {"qadeva","0958"},
#line 1470 "pdfdoc/glyphlist.txt"
    {"controlSO","000E"},
#line 1874 "pdfdoc/glyphlist.txt"
    {"fivecircle","2464"},
#line 1732 "pdfdoc/glyphlist.txt"
    {"eiotifiedcyrillic","0465"},
#line 3065 "pdfdoc/glyphlist.txt"
    {"phadeva","092B"},
#line 2927 "pdfdoc/glyphlist.txt"
    {"onehalf","00BD"},
#line 3219 "pdfdoc/glyphlist.txt"
    {"quoteright","2019"},
#line 575 "pdfdoc/glyphlist.txt"
    {"Sevenroman","2166"},
#line 3938 "pdfdoc/glyphlist.txt"
    {"ugrave","00F9"},
#line 3469 "pdfdoc/glyphlist.txt"
    {"sevenmonospace","FF17"},
#line 1933 "pdfdoc/glyphlist.txt"
    {"gaffinalarabic","FB93"},
#line 1365 "pdfdoc/glyphlist.txt"
    {"centsuperior","F6E0"},
#line 3565 "pdfdoc/glyphlist.txt"
    {"sixinferior","2086"},
#line 727 "pdfdoc/glyphlist.txt"
    {"Yuslittlecyrillic","0466"},
#line 3572 "pdfdoc/glyphlist.txt"
    {"sixsuperior","2076"},
#line 4023 "pdfdoc/glyphlist.txt"
    {"venus","2640"},
#line 1390 "pdfdoc/glyphlist.txt"
    {"chochoethai","0E0C"},
#line 445 "pdfdoc/glyphlist.txt"
    {"Ohorngrave","1EDC"},
#line 2919 "pdfdoc/glyphlist.txt"
    {"onecircleinversesansserif","278A"},
#line 3191 "pdfdoc/glyphlist.txt"
    {"qparen","24AC"},
#line 1975 "pdfdoc/glyphlist.txt"
    {"gheupturncyrillic","0491"},
#line 728 "pdfdoc/glyphlist.txt"
    {"Yuslittleiotifiedcyrillic","0468"},
#line 469 "pdfdoc/glyphlist.txt"
    {"Oslashsmall","F7F8"},
#line 3922 "pdfdoc/glyphlist.txt"
    {"ucircle","24E4"},
#line 3595 "pdfdoc/glyphlist.txt"
    {"sosuathai","0E2A"},
#line 2961 "pdfdoc/glyphlist.txt"
    {"osuperior","F6F0"},
#line 3941 "pdfdoc/glyphlist.txt"
    {"uhiragana","3046"},
#line 4054 "pdfdoc/glyphlist.txt"
    {"wakatakana","30EF"},
#line 596 "pdfdoc/glyphlist.txt"
    {"Tdotaccent","1E6A"},
#line 1882 "pdfdoc/glyphlist.txt"
    {"fiveideographicparen","3224"},
#line 4109 "pdfdoc/glyphlist.txt"
    {"wokatakana","30F2"},
#line 2280 "pdfdoc/glyphlist.txt"
    {"imageorapproximatelyequal","2253"},
#line 4074 "pdfdoc/glyphlist.txt"
    {"wekatakana","30F1"},
#line 3948 "pdfdoc/glyphlist.txt"
    {"uhorntilde","1EEF"},
#line 4105 "pdfdoc/glyphlist.txt"
    {"wikatakana","30F0"},
#line 1133 "pdfdoc/glyphlist.txt"
    {"arrowdashdown","21E3"},
#line 3507 "pdfdoc/glyphlist.txt"
    {"sheqelhebrew","20AA"},
#line 2028 "pdfdoc/glyphlist.txt"
    {"guramusquare","3318"},
#line 1393 "pdfdoc/glyphlist.txt"
    {"cieucaparenkorean","3216"},
#line 1397 "pdfdoc/glyphlist.txt"
    {"cieucuparenkorean","321C"},
#line 238 "pdfdoc/glyphlist.txt"
    {"Ghestrokecyrillic","0492"},
#line 4062 "pdfdoc/glyphlist.txt"
    {"wawarabic","0648"},
#line 1762 "pdfdoc/glyphlist.txt"
    {"enhookcyrillic","04C8"},
#line 2806 "pdfdoc/glyphlist.txt"
    {"notcontains","220C"},
#line 2733 "pdfdoc/glyphlist.txt"
    {"ngonguthai","0E07"},
#line 770 "pdfdoc/glyphlist.txt"
    {"abrevedotbelow","1EB7"},
#line 2410 "pdfdoc/glyphlist.txt"
    {"khahinitialarabic","FEA7"},
#line 669 "pdfdoc/glyphlist.txt"
    {"Ushortcyrillic","040E"},
#line 3257 "pdfdoc/glyphlist.txt"
    {"registered","00AE"},
#line 3076 "pdfdoc/glyphlist.txt"
    {"phinthuthai","0E3A"},
#line 601 "pdfdoc/glyphlist.txt"
    {"Tetsecyrillic","04B4"},
#line 1738 "pdfdoc/glyphlist.txt"
    {"element","2208"},
#line 3026 "pdfdoc/glyphlist.txt"
    {"patahwidehebrew","05B7"},
#line 1469 "pdfdoc/glyphlist.txt"
    {"controlSI","000F"},
#line 3495 "pdfdoc/glyphlist.txt"
    {"shadeva","0936"},
#line 438 "pdfdoc/glyphlist.txt"
    {"Ogravesmall","F7F2"},
#line 4275 "pdfdoc/glyphlist.txt"
    {"zerosuperior","2070"},
#line 2040 "pdfdoc/glyphlist.txt"
    {"hahinitialarabic","FEA3"},
#line 409 "pdfdoc/glyphlist.txt"
    {"Ntildesmall","F7F1"},
#line 3559 "pdfdoc/glyphlist.txt"
    {"sixdeva","096C"},
#line 2109 "pdfdoc/glyphlist.txt"
    {"hehinitialarabic","FEEB"},
#line 2691 "pdfdoc/glyphlist.txt"
    {"munahlefthebrew","05A3"},
#line 3409 "pdfdoc/glyphlist.txt"
    {"saraueleftthai","F887"},
#line 1346 "pdfdoc/glyphlist.txt"
    {"caroncmb","030C"},
#line 725 "pdfdoc/glyphlist.txt"
    {"Yusbigcyrillic","046A"},
#line 699 "pdfdoc/glyphlist.txt"
    {"Xdotaccent","1E8A"},
#line 3402 "pdfdoc/glyphlist.txt"
    {"saraiileftthai","F886"},
#line 2590 "pdfdoc/glyphlist.txt"
    {"maitaikhuleftthai","F889"},
#line 4290 "pdfdoc/glyphlist.txt"
    {"zlinebelow","1E95"},
#line 3210 "pdfdoc/glyphlist.txt"
    {"quotedblbase","201E"},
#line 3290 "pdfdoc/glyphlist.txt"
    {"reversedtilde","223D"},
#line 2815 "pdfdoc/glyphlist.txt"
    {"notlessnorequal","2270"},
#line 3366 "pdfdoc/glyphlist.txt"
    {"rupeemarkbengali","09F2"},
#line 3552 "pdfdoc/glyphlist.txt"
    {"siospieupkorean","317D"},
#line 3301 "pdfdoc/glyphlist.txt"
    {"rhookturnedsuperior","02B5"},
#line 3623 "pdfdoc/glyphlist.txt"
    {"ssadeva","0937"},
#line 4077 "pdfdoc/glyphlist.txt"
    {"wgrave","1E81"},
#line 2853 "pdfdoc/glyphlist.txt"
    {"obarred","0275"},
#line 657 "pdfdoc/glyphlist.txt"
    {"Umacrondieresis","1E7A"},
#line 3141 "pdfdoc/glyphlist.txt"
    {"qadmahebrew","05A8"},
#line 1868 "pdfdoc/glyphlist.txt"
    {"firsttonechinese","02C9"},
#line 2302 "pdfdoc/glyphlist.txt"
    {"iotalatin","0269"},
#line 1781 "pdfdoc/glyphlist.txt"
    {"ereversed","0258"},
#line 57 "pdfdoc/glyphlist.txt"
    {"Alphatonos","0386"},
#line 334 "pdfdoc/glyphlist.txt"
    {"Kahookcyrillic","04C3"},
#line 483 "pdfdoc/glyphlist.txt"
    {"Pemiddlehookcyrillic","04A6"},
#line 3213 "pdfdoc/glyphlist.txt"
    {"quotedblprime","301E"},
#line 3983 "pdfdoc/glyphlist.txt"
    {"usmallkatakana","30A5"},
#line 660 "pdfdoc/glyphlist.txt"
    {"Upsilon","03A5"},
#line 302 "pdfdoc/glyphlist.txt"
    {"Iishortcyrillic","0419"},
#line 3984 "pdfdoc/glyphlist.txt"
    {"usmallkatakanahalfwidth","FF69"},
#line 2002 "pdfdoc/glyphlist.txt"
    {"gpasquare","33AC"},
#line 4055 "pdfdoc/glyphlist.txt"
    {"wakatakanahalfwidth","FF9C"},
#line 3384 "pdfdoc/glyphlist.txt"
    {"sadmedialarabic","FEBC"},
#line 104 "pdfdoc/glyphlist.txt"
    {"Cheverticalstrokecyrillic","04B8"},
#line 239 "pdfdoc/glyphlist.txt"
    {"Gheupturncyrillic","0490"},
#line 4110 "pdfdoc/glyphlist.txt"
    {"wokatakanahalfwidth","FF66"},
#line 3211 "pdfdoc/glyphlist.txt"
    {"quotedblleft","201C"},
#line 1073 "pdfdoc/glyphlist.txt"
    {"alefdageshhebrew","FB30"},
#line 3215 "pdfdoc/glyphlist.txt"
    {"quotedblright","201D"},
#line 4260 "pdfdoc/glyphlist.txt"
    {"zedescendercyrillic","0499"},
#line 3212 "pdfdoc/glyphlist.txt"
    {"quotedblmonospace","FF02"},
#line 3227 "pdfdoc/glyphlist.txt"
    {"racute","0155"},
#line 4067 "pdfdoc/glyphlist.txt"
    {"wcircle","24E6"},
#line 3638 "pdfdoc/glyphlist.txt"
    {"subset","2282"},
#line 2173 "pdfdoc/glyphlist.txt"
    {"hungarumlautcmb","030B"},
#line 4056 "pdfdoc/glyphlist.txt"
    {"wakorean","3158"},
#line 3987 "pdfdoc/glyphlist.txt"
    {"utilde","0169"},
#line 4075 "pdfdoc/glyphlist.txt"
    {"wekorean","315E"},
#line 1772 "pdfdoc/glyphlist.txt"
    {"epsilon","03B5"},
#line 4106 "pdfdoc/glyphlist.txt"
    {"wikorean","315F"},
#line 663 "pdfdoc/glyphlist.txt"
    {"Upsilonafrican","01B1"},
#line 3209 "pdfdoc/glyphlist.txt"
    {"quotedbl","0022"},
#line 3988 "pdfdoc/glyphlist.txt"
    {"utildeacute","1E79"},
#line 184 "pdfdoc/glyphlist.txt"
    {"Endescendercyrillic","04A2"},
#line 2534 "pdfdoc/glyphlist.txt"
    {"llagujarati","0AB3"},
#line 1434 "pdfdoc/glyphlist.txt"
    {"commamonospace","FF0C"},
#line 1411 "pdfdoc/glyphlist.txt"
    {"clicklateral","01C1"},
#line 2493 "pdfdoc/glyphlist.txt"
    {"laminitialarabic","FEDF"},
#line 2108 "pdfdoc/glyphlist.txt"
    {"hehinitialaltonearabic","FBA8"},
#line 3516 "pdfdoc/glyphlist.txt"
    {"shevawidehebrew","05B0"},
#line 2936 "pdfdoc/glyphlist.txt"
    {"onepersian","06F1"},
#line 1394 "pdfdoc/glyphlist.txt"
    {"cieuccirclekorean","3268"},
#line 2169 "pdfdoc/glyphlist.txt"
    {"huiitosquare","3333"},
#line 662 "pdfdoc/glyphlist.txt"
    {"Upsilonacutehooksymbolgreek","03D3"},
#line 1412 "pdfdoc/glyphlist.txt"
    {"clickretroflex","01C3"},
#line 3929 "pdfdoc/glyphlist.txt"
    {"udeva","0909"},
#line 1422 "pdfdoc/glyphlist.txt"
    {"colonmonospace","FF1A"},
#line 196 "pdfdoc/glyphlist.txt"
    {"Esdescendercyrillic","04AA"},
#line 4019 "pdfdoc/glyphlist.txt"
    {"vehfinalarabic","FB6B"},
#line 3222 "pdfdoc/glyphlist.txt"
    {"quotesingle","0027"},
#line 2268 "pdfdoc/glyphlist.txt"
    {"iishortcyrillic","0439"},
#line 3443 "pdfdoc/glyphlist.txt"
    {"segolwidehebrew","05B6"},
#line 1415 "pdfdoc/glyphlist.txt"
    {"clubsuitwhite","2667"},
#line 1481 "pdfdoc/glyphlist.txt"
    {"cornerbracketlefthalfwidth","FF62"},
#line 95 "pdfdoc/glyphlist.txt"
    {"Cedillasmall","F7B8"},
#line 608 "pdfdoc/glyphlist.txt"
    {"Tiwnarmenian","054F"},
#line 3084 "pdfdoc/glyphlist.txt"
    {"pieupaparenkorean","3213"},
#line 1576 "pdfdoc/glyphlist.txt"
    {"ddagujarati","0AA1"},
#line 1414 "pdfdoc/glyphlist.txt"
    {"clubsuitblack","2663"},
#line 1402 "pdfdoc/glyphlist.txt"
    {"circlepostalmark","3036"},
#line 2526 "pdfdoc/glyphlist.txt"
    {"lfblock","258C"},
#line 609 "pdfdoc/glyphlist.txt"
    {"Tlinebelow","1E6E"},
#line 4064 "pdfdoc/glyphlist.txt"
    {"wawhamzaabovearabic","0624"},
#line 1653 "pdfdoc/glyphlist.txt"
    {"downtackbelowcmb","031E"},
#line 3127 "pdfdoc/glyphlist.txt"
    {"propersubset","2282"},
#line 68 "pdfdoc/glyphlist.txt"
    {"Aybarmenian","0531"},
#line 1480 "pdfdoc/glyphlist.txt"
    {"cornerbracketleft","300C"},
#line 476 "pdfdoc/glyphlist.txt"
    {"Otildesmall","F7F5"},
#line 3350 "pdfdoc/glyphlist.txt"
    {"rragurmukhi","0A5C"},
#line 4065 "pdfdoc/glyphlist.txt"
    {"wawhamzaabovefinalarabic","FE86"},
#line 3620 "pdfdoc/glyphlist.txt"
    {"squarewhitewithsmallblack","25A3"},
#line 3221 "pdfdoc/glyphlist.txt"
    {"quotesinglbase","201A"},
#line 3641 "pdfdoc/glyphlist.txt"
    {"succeeds","227B"},
#line 3112 "pdfdoc/glyphlist.txt"
    {"pointingindexrightwhite","261E"},
#line 1775 "pdfdoc/glyphlist.txt"
    {"equalmonospace","FF1D"},
#line 3128 "pdfdoc/glyphlist.txt"
    {"propersuperset","2283"},
#line 2576 "pdfdoc/glyphlist.txt"
    {"magurmukhi","0A2E"},
#line 3304 "pdfdoc/glyphlist.txt"
    {"rieulacirclekorean","3271"},
#line 3331 "pdfdoc/glyphlist.txt"
    {"ringhalfleftarmenian","0559"},
#line 2549 "pdfdoc/glyphlist.txt"
    {"lolingthai","0E25"},
#line 3330 "pdfdoc/glyphlist.txt"
    {"ringhalfleft","02BF"},
#line 4279 "pdfdoc/glyphlist.txt"
    {"zerowidthspace","200B"},
#line 599 "pdfdoc/glyphlist.txt"
    {"Tedescendercyrillic","04AC"},
#line 3334 "pdfdoc/glyphlist.txt"
    {"ringhalfright","02BE"},
#line 3460 "pdfdoc/glyphlist.txt"
    {"sevencircleinversesansserif","2790"},
#line 3952 "pdfdoc/glyphlist.txt"
    {"ukatakana","30A6"},
#line 3223 "pdfdoc/glyphlist.txt"
    {"quotesinglemonospace","FF07"},
#line 1505 "pdfdoc/glyphlist.txt"
    {"dadinitialarabic","FEBF"},
#line 4117 "pdfdoc/glyphlist.txt"
    {"wturned","028D"},
#line 3493 "pdfdoc/glyphlist.txt"
    {"shadelight","2591"},
#line 4277 "pdfdoc/glyphlist.txt"
    {"zerowidthjoiner","FEFF"},
#line 3276 "pdfdoc/glyphlist.txt"
    {"reshholam","05E8 05B9"},
#line 1183 "pdfdoc/glyphlist.txt"
    {"asteriskarabic","066D"},
#line 3284 "pdfdoc/glyphlist.txt"
    {"reshsegol","05E8 05B6"},
#line 4235 "pdfdoc/glyphlist.txt"
    {"zagurmukhi","0A5B"},
#line 746 "pdfdoc/glyphlist.txt"
    {"Zhedescendercyrillic","0496"},
#line 1341 "pdfdoc/glyphlist.txt"
    {"candrabindugujarati","0A81"},
#line 1482 "pdfdoc/glyphlist.txt"
    {"cornerbracketleftvertical","FE41"},
#line 3505 "pdfdoc/glyphlist.txt"
    {"sheicoptic","03E3"},
#line 3991 "pdfdoc/glyphlist.txt"
    {"uudeva","090A"},
#line 3485 "pdfdoc/glyphlist.txt"
    {"shaddadammaarabic","FC61"},
#line 649 "pdfdoc/glyphlist.txt"
    {"Uhornhookabove","1EEC"},
#line 52 "pdfdoc/glyphlist.txt"
    {"Agravesmall","F7E0"},
#line 1642 "pdfdoc/glyphlist.txt"
    {"dotaccentcmb","0307"},
#line 3166 "pdfdoc/glyphlist.txt"
    {"qmonospace","FF51"},
#line 3113 "pdfdoc/glyphlist.txt"
    {"pointingindexupwhite","261D"},
#line 2944 "pdfdoc/glyphlist.txt"
    {"oogurmukhi","0A13"},
#line 3110 "pdfdoc/glyphlist.txt"
    {"pointingindexdownwhite","261F"},
#line 2437 "pdfdoc/glyphlist.txt"
    {"kiyeokkorean","3131"},
#line 3080 "pdfdoc/glyphlist.txt"
    {"phophungthai","0E1C"},
#line 3486 "pdfdoc/glyphlist.txt"
    {"shaddadammatanarabic","FC5E"},
#line 2405 "pdfdoc/glyphlist.txt"
    {"khadeva","0916"},
#line 3379 "pdfdoc/glyphlist.txt"
    {"sacutedotaccent","1E65"},
#line 3610 "pdfdoc/glyphlist.txt"
    {"squareln","33D1"},
#line 3649 "pdfdoc/glyphlist.txt"
    {"superset","2283"},
#line 3234 "pdfdoc/glyphlist.txt"
    {"rafe","05BF"},
#line 4099 "pdfdoc/glyphlist.txt"
    {"whitetelephone","260F"},
#line 3969 "pdfdoc/glyphlist.txt"
    {"uparen","24B0"},
#line 3226 "pdfdoc/glyphlist.txt"
    {"rabengali","09B0"},
#line 764 "pdfdoc/glyphlist.txt"
    {"abbreviationsigndeva","0970"},
#line 3540 "pdfdoc/glyphlist.txt"
    {"siluqhebrew","05BD"},
#line 3086 "pdfdoc/glyphlist.txt"
    {"pieupcirclekorean","3265"},
#line 763 "pdfdoc/glyphlist.txt"
    {"abbreviationmarkarmenian","055F"},
#line 2049 "pdfdoc/glyphlist.txt"
    {"hamzadammatanarabic","0621 064C"},
#line 2048 "pdfdoc/glyphlist.txt"
    {"hamzadammaarabic","0621 064F"},
#line 2855 "pdfdoc/glyphlist.txt"
    {"obarreddieresiscyrillic","04EB"},
#line 2640 "pdfdoc/glyphlist.txt"
    {"mieumaparenkorean","3212"},
#line 99 "pdfdoc/glyphlist.txt"
    {"Chedescenderabkhasiancyrillic","04BE"},
#line 2935 "pdfdoc/glyphlist.txt"
    {"oneperiod","2488"},
#line 458 "pdfdoc/glyphlist.txt"
    {"Omegatitlocyrillic","047C"},
#line 2656 "pdfdoc/glyphlist.txt"
    {"miribaarusquare","334A"},
#line 1809 "pdfdoc/glyphlist.txt"
    {"evowelsignbengali","09C7"},
#line 3634 "pdfdoc/glyphlist.txt"
    {"sterling","00A3"},
#line 1368 "pdfdoc/glyphlist.txt"
    {"chadeva","091B"},
#line 100 "pdfdoc/glyphlist.txt"
    {"Chedescendercyrillic","04B6"},
#line 3489 "pdfdoc/glyphlist.txt"
    {"shaddakasraarabic","FC62"},
#line 1752 "pdfdoc/glyphlist.txt"
    {"emphasismarkarmenian","055B"},
#line 3448 "pdfdoc/glyphlist.txt"
    {"semicolon","003B"},
#line 1124 "pdfdoc/glyphlist.txt"
    {"approximatelyequal","2245"},
#line 1100 "pdfdoc/glyphlist.txt"
    {"angbopomofo","3124"},
#line 3329 "pdfdoc/glyphlist.txt"
    {"ringcmb","030A"},
#line 3614 "pdfdoc/glyphlist.txt"
    {"squaremm","339C"},
#line 3450 "pdfdoc/glyphlist.txt"
    {"semicolonmonospace","FF1B"},
#line 4240 "pdfdoc/glyphlist.txt"
    {"zahmedialarabic","FEC8"},
#line 3262 "pdfdoc/glyphlist.txt"
    {"rehfinalarabic","FEAE"},
#line 3058 "pdfdoc/glyphlist.txt"
    {"periodsuperior","F6E8"},
#line 3635 "pdfdoc/glyphlist.txt"
    {"sterlingmonospace","FFE1"},
#line 2876 "pdfdoc/glyphlist.txt"
    {"odieresiscyrillic","04E7"},
#line 3360 "pdfdoc/glyphlist.txt"
    {"rtblock","2590"},
#line 2992 "pdfdoc/glyphlist.txt"
    {"pansioskorean","317F"},
#line 2847 "pdfdoc/glyphlist.txt"
    {"nyadeva","091E"},
#line 3490 "pdfdoc/glyphlist.txt"
    {"shaddakasratanarabic","FC5F"},
#line 3353 "pdfdoc/glyphlist.txt"
    {"rrvocalicbengali","09E0"},
#line 3152 "pdfdoc/glyphlist.txt"
    {"qamats33","05B8"},
#line 163 "pdfdoc/glyphlist.txt"
    {"Edieresis","00CB"},
#line 1248 "pdfdoc/glyphlist.txt"
    {"bhagujarati","0AAD"},
#line 4090 "pdfdoc/glyphlist.txt"
    {"whiteleftpointingtriangle","25C1"},
#line 4089 "pdfdoc/glyphlist.txt"
    {"whiteleftpointingsmalltriangle","25C3"},
#line 3487 "pdfdoc/glyphlist.txt"
    {"shaddafathaarabic","FC60"},
#line 2875 "pdfdoc/glyphlist.txt"
    {"odieresis","00F6"},
#line 3468 "pdfdoc/glyphlist.txt"
    {"seveninferior","2087"},
#line 1987 "pdfdoc/glyphlist.txt"
    {"gjecyrillic","0453"},
#line 1080 "pdfdoc/glyphlist.txt"
    {"aleflamedhebrew","FB4F"},
#line 3300 "pdfdoc/glyphlist.txt"
    {"rhookturned","027B"},
#line 1760 "pdfdoc/glyphlist.txt"
    {"engbopomofo","3125"},
#line 1622 "pdfdoc/glyphlist.txt"
    {"djecyrillic","0452"},
#line 133 "pdfdoc/glyphlist.txt"
    {"Djecyrillic","0402"},
#line 371 "pdfdoc/glyphlist.txt"
    {"Ljecyrillic","0409"},
#line 2643 "pdfdoc/glyphlist.txt"
    {"mieumpansioskorean","3170"},
#line 403 "pdfdoc/glyphlist.txt"
    {"Njecyrillic","040A"},
#line 2617 "pdfdoc/glyphlist.txt"
    {"meeminitialarabic","FEE3"},
#line 4094 "pdfdoc/glyphlist.txt"
    {"whiterightpointingtriangle","25B7"},
#line 4093 "pdfdoc/glyphlist.txt"
    {"whiterightpointingsmalltriangle","25B9"},
#line 614 "pdfdoc/glyphlist.txt"
    {"Tonetwo","01A7"},
#line 3488 "pdfdoc/glyphlist.txt"
    {"shaddafathatanarabic","0651 064B"},
#line 1255 "pdfdoc/glyphlist.txt"
    {"birusquare","3331"},
#line 2277 "pdfdoc/glyphlist.txt"
    {"iluyhebrew","05AC"},
#line 2318 "pdfdoc/glyphlist.txt"
    {"ivowelsignbengali","09BF"},
#line 3121 "pdfdoc/glyphlist.txt"
    {"primemod","02B9"},
#line 1810 "pdfdoc/glyphlist.txt"
    {"evowelsigndeva","0947"},
#line 3056 "pdfdoc/glyphlist.txt"
    {"periodmonospace","FF0E"},
#line 3106 "pdfdoc/glyphlist.txt"
    {"plussuperior","207A"},
#line 3430 "pdfdoc/glyphlist.txt"
    {"section","00A7"},
#line 3598 "pdfdoc/glyphlist.txt"
    {"spade","2660"},
#line 2800 "pdfdoc/glyphlist.txt"
    {"noonjeeminitialarabic","FCD2"},
#line 1593 "pdfdoc/glyphlist.txt"
    {"deicoptic","03EF"},
#line 3923 "pdfdoc/glyphlist.txt"
    {"ucircumflex","00FB"},
#line 4114 "pdfdoc/glyphlist.txt"
    {"wparen","24B2"},
#line 124 "pdfdoc/glyphlist.txt"
    {"Deicoptic","03EE"},
#line 3357 "pdfdoc/glyphlist.txt"
    {"rrvocalicvowelsigndeva","0944"},
#line 28 "pdfdoc/glyphlist.txt"
    {"Abrevedotbelow","1EB6"},
#line 1088 "pdfdoc/glyphlist.txt"
    {"alefqamatshebrew","FB2F"},
#line 3356 "pdfdoc/glyphlist.txt"
    {"rrvocalicvowelsignbengali","09C4"},
#line 3358 "pdfdoc/glyphlist.txt"
    {"rrvocalicvowelsigngujarati","0AC4"},
#line 1231 "pdfdoc/glyphlist.txt"
    {"behinitialarabic","FE91"},
#line 3093 "pdfdoc/glyphlist.txt"
    {"pieupthieuthkorean","3177"},
#line 1840 "pdfdoc/glyphlist.txt"
    {"feicoptic","03E5"},
#line 3217 "pdfdoc/glyphlist.txt"
    {"quoteleftreversed","201B"},
#line 446 "pdfdoc/glyphlist.txt"
    {"Ohornhookabove","1EDE"},
#line 67 "pdfdoc/glyphlist.txt"
    {"Atildesmall","F7E3"},
#line 214 "pdfdoc/glyphlist.txt"
    {"Feicoptic","03E4"},
#line 2632 "pdfdoc/glyphlist.txt"
    {"merkhakefulahebrew","05A6"},
#line 3251 "pdfdoc/glyphlist.txt"
    {"rdotaccent","1E59"},
#line 1136 "pdfdoc/glyphlist.txt"
    {"arrowdashup","21E1"},
#line 1304 "pdfdoc/glyphlist.txt"
    {"bracketleftex","F8EF"},
#line 2652 "pdfdoc/glyphlist.txt"
    {"minuscircle","2296"},
#line 1944 "pdfdoc/glyphlist.txt"
    {"gbopomofo","310D"},
#line 3322 "pdfdoc/glyphlist.txt"
    {"righttackbelowcmb","0319"},
#line 3139 "pdfdoc/glyphlist.txt"
    {"q","0071"},
#line 766 "pdfdoc/glyphlist.txt"
    {"abopomofo","311A"},
#line 2776 "pdfdoc/glyphlist.txt"
    {"njecyrillic","045A"},
#line 2329 "pdfdoc/glyphlist.txt"
    {"jbopomofo","3110"},
#line 1567 "pdfdoc/glyphlist.txt"
    {"dbopomofo","3109"},
#line 1302 "pdfdoc/glyphlist.txt"
    {"bracketleft","005B"},
#line 1118 "pdfdoc/glyphlist.txt"
    {"apostrophearmenian","055A"},
#line 1867 "pdfdoc/glyphlist.txt"
    {"finaltsadihebrew","05E5"},
#line 2641 "pdfdoc/glyphlist.txt"
    {"mieumcirclekorean","3264"},
#line 1396 "pdfdoc/glyphlist.txt"
    {"cieucparenkorean","3208"},
#line 1372 "pdfdoc/glyphlist.txt"
    {"cheabkhasiancyrillic","04BD"},
#line 1832 "pdfdoc/glyphlist.txt"
    {"fbopomofo","3108"},
#line 2020 "pdfdoc/glyphlist.txt"
    {"gscript","0261"},
#line 1743 "pdfdoc/glyphlist.txt"
    {"ellipsis","2026"},
#line 1176 "pdfdoc/glyphlist.txt"
    {"ascript","0251"},
#line 3126 "pdfdoc/glyphlist.txt"
    {"propellor","2318"},
#line 2319 "pdfdoc/glyphlist.txt"
    {"ivowelsigndeva","093F"},
#line 3354 "pdfdoc/glyphlist.txt"
    {"rrvocalicdeva","0960"},
#line 1672 "pdfdoc/glyphlist.txt"
    {"ebopomofo","311C"},
#line 3066 "pdfdoc/glyphlist.txt"
    {"phagujarati","0AAB"},
#line 4025 "pdfdoc/glyphlist.txt"
    {"verticallineabovecmb","030D"},
#line 348 "pdfdoc/glyphlist.txt"
    {"Kjecyrillic","040C"},
#line 164 "pdfdoc/glyphlist.txt"
    {"Edieresissmall","F7EB"},
#line 3451 "pdfdoc/glyphlist.txt"
    {"semicolonsmall","FE54"},
#line 242 "pdfdoc/glyphlist.txt"
    {"Gjecyrillic","0403"},
#line 2023 "pdfdoc/glyphlist.txt"
    {"guillemotleft","00AB"},
#line 2910 "pdfdoc/glyphlist.txt"
    {"omegatonos","03CE"},
#line 3573 "pdfdoc/glyphlist.txt"
    {"sixteencircle","246F"},
#line 1331 "pdfdoc/glyphlist.txt"
    {"caarmenian","056E"},
#line 3575 "pdfdoc/glyphlist.txt"
    {"sixteenparen","2483"},
#line 1419 "pdfdoc/glyphlist.txt"
    {"coarmenian","0581"},
#line 1305 "pdfdoc/glyphlist.txt"
    {"bracketleftmonospace","FF3B"},
#line 1387 "pdfdoc/glyphlist.txt"
    {"chochangthai","0E0A"},
#line 2412 "pdfdoc/glyphlist.txt"
    {"kheicoptic","03E7"},
#line 1389 "pdfdoc/glyphlist.txt"
    {"chochingthai","0E09"},
#line 1778 "pdfdoc/glyphlist.txt"
    {"equivalence","2261"},
#line 2715 "pdfdoc/glyphlist.txt"
    {"nbopomofo","310B"},
#line 3944 "pdfdoc/glyphlist.txt"
    {"uhornacute","1EE9"},
#line 698 "pdfdoc/glyphlist.txt"
    {"Xdieresis","1E8C"},
#line 2952 "pdfdoc/glyphlist.txt"
    {"orthogonal","221F"},
#line 2081 "pdfdoc/glyphlist.txt"
    {"hatafsegolhebrew","05B1"},
#line 1935 "pdfdoc/glyphlist.txt"
    {"gafmedialarabic","FB95"},
#line 1767 "pdfdoc/glyphlist.txt"
    {"eopenclosed","029A"},
#line 661 "pdfdoc/glyphlist.txt"
    {"Upsilon1","03D2"},
#line 3359 "pdfdoc/glyphlist.txt"
    {"rsuperior","F6F1"},
#line 2633 "pdfdoc/glyphlist.txt"
    {"merkhakefulalefthebrew","05A6"},
#line 4068 "pdfdoc/glyphlist.txt"
    {"wcircumflex","0175"},
#line 3501 "pdfdoc/glyphlist.txt"
    {"sheenarabic","0634"},
#line 2138 "pdfdoc/glyphlist.txt"
    {"hiriqwidehebrew","05B4"},
#line 3041 "pdfdoc/glyphlist.txt"
    {"pehinitialarabic","FB58"},
#line 1433 "pdfdoc/glyphlist.txt"
    {"commainferior","F6E1"},
#line 2185 "pdfdoc/glyphlist.txt"
    {"ibopomofo","3127"},
#line 2515 "pdfdoc/glyphlist.txt"
    {"leftangleabovecmb","031A"},
#line 256 "pdfdoc/glyphlist.txt"
    {"Haabkhasiancyrillic","04A8"},
#line 3047 "pdfdoc/glyphlist.txt"
    {"percent","0025"},
#line 3319 "pdfdoc/glyphlist.txt"
    {"rieultikeutkorean","316A"},
#line 2587 "pdfdoc/glyphlist.txt"
    {"maiekupperleftthai","F88A"},
#line 1116 "pdfdoc/glyphlist.txt"
    {"apaatosquare","3300"},
#line 1273 "pdfdoc/glyphlist.txt"
    {"blackstar","2605"},
#line 3496 "pdfdoc/glyphlist.txt"
    {"shagujarati","0AB6"},
#line 652 "pdfdoc/glyphlist.txt"
    {"Uhungarumlautcyrillic","04F2"},
#line 2929 "pdfdoc/glyphlist.txt"
    {"oneideographicparen","3220"},
#line 3280 "pdfdoc/glyphlist.txt"
    {"reshqamats","05E8 05B8"},
#line 3153 "pdfdoc/glyphlist.txt"
    {"qamatsde","05B8"},
#line 3560 "pdfdoc/glyphlist.txt"
    {"sixgujarati","0AEC"},
#line 3048 "pdfdoc/glyphlist.txt"
    {"percentarabic","066A"},
#line 1340 "pdfdoc/glyphlist.txt"
    {"candrabindudeva","0901"},
#line 651 "pdfdoc/glyphlist.txt"
    {"Uhungarumlaut","0170"},
#line 1527 "pdfdoc/glyphlist.txt"
    {"daletholamhebrew","05D3 05B9"},
#line 3229 "pdfdoc/glyphlist.txt"
    {"radical","221A"},
#line 2296 "pdfdoc/glyphlist.txt"
    {"invsmileface","263B"},
#line 3336 "pdfdoc/glyphlist.txt"
    {"ringhalfrightcentered","02D2"},
#line 3542 "pdfdoc/glyphlist.txt"
    {"similar","223C"},
#line 3333 "pdfdoc/glyphlist.txt"
    {"ringhalfleftcentered","02D3"},
#line 1170 "pdfdoc/glyphlist.txt"
    {"arrowupwhite","21E7"},
#line 3960 "pdfdoc/glyphlist.txt"
    {"umonospace","FF55"},
#line 155 "pdfdoc/glyphlist.txt"
    {"Ecircumflexbelow","1E18"},
#line 1101 "pdfdoc/glyphlist.txt"
    {"angkhankhuthai","0E5A"},
#line 3624 "pdfdoc/glyphlist.txt"
    {"ssagujarati","0AB7"},
#line 2086 "pdfdoc/glyphlist.txt"
    {"hbopomofo","310F"},
#line 2930 "pdfdoc/glyphlist.txt"
    {"oneinferior","2081"},
#line 2531 "pdfdoc/glyphlist.txt"
    {"ljecyrillic","0459"},
#line 2939 "pdfdoc/glyphlist.txt"
    {"onesuperior","00B9"},
#line 3214 "pdfdoc/glyphlist.txt"
    {"quotedblprimereversed","301D"},
#line 1744 "pdfdoc/glyphlist.txt"
    {"ellipsisvertical","22EE"},
#line 3339 "pdfdoc/glyphlist.txt"
    {"rlinebelow","1E5F"},
#line 4004 "pdfdoc/glyphlist.txt"
    {"vagurmukhi","0A35"},
#line 564 "pdfdoc/glyphlist.txt"
    {"Scedilla","015E"},
#line 1947 "pdfdoc/glyphlist.txt"
    {"gcedilla","0123"},
#line 2439 "pdfdoc/glyphlist.txt"
    {"kiyeoksioskorean","3133"},
#line 208 "pdfdoc/glyphlist.txt"
    {"Ezhcaron","01EE"},
#line 3089 "pdfdoc/glyphlist.txt"
    {"pieupparenkorean","3205"},
#line 1570 "pdfdoc/glyphlist.txt"
    {"dcedilla","1E11"},
#line 117 "pdfdoc/glyphlist.txt"
    {"Dcedilla","1E10"},
#line 361 "pdfdoc/glyphlist.txt"
    {"Lcedilla","013B"},
#line 500 "pdfdoc/glyphlist.txt"
    {"Rcedilla","0156"},
#line 394 "pdfdoc/glyphlist.txt"
    {"Ncedilla","0145"},
#line 2932 "pdfdoc/glyphlist.txt"
    {"onenumeratorbengali","09F4"},
#line 3494 "pdfdoc/glyphlist.txt"
    {"shademedium","2592"},
#line 1564 "pdfdoc/glyphlist.txt"
    {"dblprimemod","02BA"},
#line 3395 "pdfdoc/glyphlist.txt"
    {"saraaathai","0E32"},
#line 3119 "pdfdoc/glyphlist.txt"
    {"precedes","227A"},
#line 3412 "pdfdoc/glyphlist.txt"
    {"sarauuthai","0E39"},
#line 3396 "pdfdoc/glyphlist.txt"
    {"saraaethai","0E41"},
#line 3410 "pdfdoc/glyphlist.txt"
    {"sarauethai","0E36"},
#line 261 "pdfdoc/glyphlist.txt"
    {"Hcedilla","1E28"},
#line 3403 "pdfdoc/glyphlist.txt"
    {"saraiithai","0E35"},
#line 3282 "pdfdoc/glyphlist.txt"
    {"reshqubuts","05E8 05BB"},
#line 3419 "pdfdoc/glyphlist.txt"
    {"schwadieresiscyrillic","04DB"},
#line 2069 "pdfdoc/glyphlist.txt"
    {"hatafqamats","05B3"},
#line 1337 "pdfdoc/glyphlist.txt"
    {"calsquare","3388"},
#line 4210 "pdfdoc/glyphlist.txt"
    {"yr","01A6"},
#line 1916 "pdfdoc/glyphlist.txt"
    {"fourperiod","248B"},
#line 3057 "pdfdoc/glyphlist.txt"
    {"periodsmall","FE52"},
#line 2379 "pdfdoc/glyphlist.txt"
    {"karoriisquare","330D"},
#line 1488 "pdfdoc/glyphlist.txt"
    {"coverkgsquare","33C6"},
#line 3399 "pdfdoc/glyphlist.txt"
    {"saraamthai","0E33"},
#line 4167 "pdfdoc/glyphlist.txt"
    {"yen","00A5"},
#line 2505 "pdfdoc/glyphlist.txt"
    {"lbopomofo","310C"},
#line 3427 "pdfdoc/glyphlist.txt"
    {"seagullbelowcmb","033C"},
#line 2031 "pdfdoc/glyphlist.txt"
    {"haabkhasiancyrillic","04A9"},
#line 2570 "pdfdoc/glyphlist.txt"
    {"macroncmb","0304"},
#line 2920 "pdfdoc/glyphlist.txt"
    {"onedeva","0967"},
#line 3085 "pdfdoc/glyphlist.txt"
    {"pieupcieuckorean","3176"},
#line 2718 "pdfdoc/glyphlist.txt"
    {"ncedilla","0146"},
#line 4180 "pdfdoc/glyphlist.txt"
    {"yhook","01B4"},
#line 161 "pdfdoc/glyphlist.txt"
    {"Ecyrillic","0404"},
#line 665 "pdfdoc/glyphlist.txt"
    {"Upsilondieresishooksymbolgreek","03D4"},
#line 3129 "pdfdoc/glyphlist.txt"
    {"proportion","2237"},
#line 2871 "pdfdoc/glyphlist.txt"
    {"ocyrillic","043E"},
#line 3457 "pdfdoc/glyphlist.txt"
    {"sevenarabic","0667"},
#line 4138 "pdfdoc/glyphlist.txt"
    {"yahiragana","3084"},
#line 3474 "pdfdoc/glyphlist.txt"
    {"sevenroman","2176"},
#line 4215 "pdfdoc/glyphlist.txt"
    {"yuhiragana","3086"},
#line 594 "pdfdoc/glyphlist.txt"
    {"Tcircumflexbelow","1E70"},
#line 4194 "pdfdoc/glyphlist.txt"
    {"yohiragana","3088"},
#line 2897 "pdfdoc/glyphlist.txt"
    {"okatakanahalfwidth","FF75"},
#line 88 "pdfdoc/glyphlist.txt"
    {"Ccedilla","00C7"},
#line 3045 "pdfdoc/glyphlist.txt"
    {"pemiddlehookcyrillic","04A7"},
#line 3521 "pdfdoc/glyphlist.txt"
    {"shindageshhebrew","FB49"},
#line 664 "pdfdoc/glyphlist.txt"
    {"Upsilondieresis","03AB"},
#line 4107 "pdfdoc/glyphlist.txt"
    {"wmonospace","FF57"},
#line 2572 "pdfdoc/glyphlist.txt"
    {"macronmonospace","FFE3"},
#line 4021 "pdfdoc/glyphlist.txt"
    {"vehmedialarabic","FB6D"},
#line 1557 "pdfdoc/glyphlist.txt"
    {"dbldanda","0965"},
#line 1662 "pdfdoc/glyphlist.txt"
    {"dzaltone","02A3"},
#line 2883 "pdfdoc/glyphlist.txt"
    {"ogujarati","0A93"},
#line 1537 "pdfdoc/glyphlist.txt"
    {"daletshevahebrew","05D3 05B0"},
#line 203 "pdfdoc/glyphlist.txt"
    {"Ethsmall","F7F0"},
#line 339 "pdfdoc/glyphlist.txt"
    {"Kcedilla","0136"},
#line 229 "pdfdoc/glyphlist.txt"
    {"Gcedilla","0122"},
#line 89 "pdfdoc/glyphlist.txt"
    {"Ccedillaacute","1E08"},
#line 4152 "pdfdoc/glyphlist.txt"
    {"yeharabic","064A"},
#line 2767 "pdfdoc/glyphlist.txt"
    {"nineperiod","2490"},
#line 2073 "pdfdoc/glyphlist.txt"
    {"hatafqamatshebrew","05B3"},
#line 448 "pdfdoc/glyphlist.txt"
    {"Ohungarumlaut","0150"},
#line 2074 "pdfdoc/glyphlist.txt"
    {"hatafqamatsnarrowhebrew","05B3"},
#line 4211 "pdfdoc/glyphlist.txt"
    {"yring","1E99"},
#line 3593 "pdfdoc/glyphlist.txt"
    {"sosalathai","0E28"},
#line 580 "pdfdoc/glyphlist.txt"
    {"Shhacyrillic","04BA"},
#line 2644 "pdfdoc/glyphlist.txt"
    {"mieumparenkorean","3204"},
#line 2471 "pdfdoc/glyphlist.txt"
    {"lakkhangyaothai","0E45"},
#line 3959 "pdfdoc/glyphlist.txt"
    {"umatragurmukhi","0A41"},
#line 714 "pdfdoc/glyphlist.txt"
    {"Yericyrillic","042B"},
#line 2100 "pdfdoc/glyphlist.txt"
    {"hehaltonearabic","06C1"},
#line 2569 "pdfdoc/glyphlist.txt"
    {"macronbelowcmb","0331"},
#line 2427 "pdfdoc/glyphlist.txt"
    {"khzsquare","3391"},
#line 2088 "pdfdoc/glyphlist.txt"
    {"hcedilla","1E29"},
#line 1364 "pdfdoc/glyphlist.txt"
    {"centoldstyle","F7A2"},
#line 3574 "pdfdoc/glyphlist.txt"
    {"sixteencurrencydenominatorbengali","09F9"},
#line 1907 "pdfdoc/glyphlist.txt"
    {"fourgurmukhi","0A6A"},
#line 1977 "pdfdoc/glyphlist.txt"
    {"ghhagurmukhi","0A5A"},
#line 3530 "pdfdoc/glyphlist.txt"
    {"shinsindot","FB2B"},
#line 2881 "pdfdoc/glyphlist.txt"
    {"ogonekcmb","0328"},
#line 2384 "pdfdoc/glyphlist.txt"
    {"kasraarabic","0650"},
#line 1912 "pdfdoc/glyphlist.txt"
    {"fourmonospace","FF14"},
#line 3237 "pdfdoc/glyphlist.txt"
    {"ragurmukhi","0A30"},
#line 2422 "pdfdoc/glyphlist.txt"
    {"khokhuatthai","0E03"},
#line 4232 "pdfdoc/glyphlist.txt"
    {"zaarmenian","0566"},
#line 1870 "pdfdoc/glyphlist.txt"
    {"fitacyrillic","0473"},
#line 2406 "pdfdoc/glyphlist.txt"
    {"khagujarati","0A96"},
#line 216 "pdfdoc/glyphlist.txt"
    {"Fitacyrillic","0472"},
#line 1953 "pdfdoc/glyphlist.txt"
    {"gecyrillic","0433"},
#line 457 "pdfdoc/glyphlist.txt"
    {"Omegaroundcyrillic","047A"},
#line 739 "pdfdoc/glyphlist.txt"
    {"Zecyrillic","0417"},
#line 2335 "pdfdoc/glyphlist.txt"
    {"jecyrillic","0458"},
#line 1589 "pdfdoc/glyphlist.txt"
    {"decyrillic","0434"},
#line 4139 "pdfdoc/glyphlist.txt"
    {"yakatakana","30E4"},
#line 1753 "pdfdoc/glyphlist.txt"
    {"emptyset","2205"},
#line 73 "pdfdoc/glyphlist.txt"
    {"Becyrillic","0411"},
#line 4217 "pdfdoc/glyphlist.txt"
    {"yukatakana","30E6"},
#line 2801 "pdfdoc/glyphlist.txt"
    {"noonjeemisolatedarabic","FC4B"},
#line 123 "pdfdoc/glyphlist.txt"
    {"Decyrillic","0414"},
#line 2898 "pdfdoc/glyphlist.txt"
    {"okorean","3157"},
#line 4196 "pdfdoc/glyphlist.txt"
    {"yokatakana","30E8"},
#line 1429 "pdfdoc/glyphlist.txt"
    {"commaaboverightcmb","0315"},
#line 1679 "pdfdoc/glyphlist.txt"
    {"ecedillabreve","1E1D"},
#line 654 "pdfdoc/glyphlist.txt"
    {"Ukcyrillic","0478"},
#line 171 "pdfdoc/glyphlist.txt"
    {"Eharmenian","0537"},
#line 323 "pdfdoc/glyphlist.txt"
    {"Jecyrillic","0408"},
#line 178 "pdfdoc/glyphlist.txt"
    {"Emacron","0112"},
#line 3653 "pdfdoc/glyphlist.txt"
    {"syouwaerasquare","337C"},
#line 2884 "pdfdoc/glyphlist.txt"
    {"oharmenian","0585"},
#line 1109 "pdfdoc/glyphlist.txt"
    {"angstrom","212B"},
#line 275 "pdfdoc/glyphlist.txt"
    {"IAcyrillic","042F"},
#line 2076 "pdfdoc/glyphlist.txt"
    {"hatafqamatswidehebrew","05B3"},
#line 2900 "pdfdoc/glyphlist.txt"
    {"omacron","014D"},
#line 307 "pdfdoc/glyphlist.txt"
    {"Iocyrillic","0401"},
#line 295 "pdfdoc/glyphlist.txt"
    {"Iecyrillic","0415"},
#line 3130 "pdfdoc/glyphlist.txt"
    {"proportional","221D"},
#line 300 "pdfdoc/glyphlist.txt"
    {"Iicyrillic","0418"},
#line 3579 "pdfdoc/glyphlist.txt"
    {"slashmonospace","FF0F"},
#line 2912 "pdfdoc/glyphlist.txt"
    {"omicron","03BF"},
#line 1965 "pdfdoc/glyphlist.txt"
    {"ghadarmenian","0572"},
#line 1887 "pdfdoc/glyphlist.txt"
    {"fiveperiod","248C"},
#line 720 "pdfdoc/glyphlist.txt"
    {"Yicyrillic","0407"},
#line 2742 "pdfdoc/glyphlist.txt"
    {"nieunkorean","3134"},
#line 2638 "pdfdoc/glyphlist.txt"
    {"middot","00B7"},
#line 1587 "pdfdoc/glyphlist.txt"
    {"decimalseparatorarabic","066B"},
#line 2507 "pdfdoc/glyphlist.txt"
    {"lcedilla","013C"},
#line 200 "pdfdoc/glyphlist.txt"
    {"Etarmenian","0538"},
#line 1780 "pdfdoc/glyphlist.txt"
    {"ercyrillic","0440"},
#line 481 "pdfdoc/glyphlist.txt"
    {"Pecyrillic","041F"},
#line 1369 "pdfdoc/glyphlist.txt"
    {"chagujarati","0A9B"},
#line 4273 "pdfdoc/glyphlist.txt"
    {"zerooldstyle","F730"},
#line 1588 "pdfdoc/glyphlist.txt"
    {"decimalseparatorpersian","066B"},
#line 2759 "pdfdoc/glyphlist.txt"
    {"ninegurmukhi","0A6F"},
#line 1755 "pdfdoc/glyphlist.txt"
    {"encyrillic","043D"},
#line 1196 "pdfdoc/glyphlist.txt"
    {"aubopomofo","3120"},
#line 179 "pdfdoc/glyphlist.txt"
    {"Emacronacute","1E16"},
#line 1054 "pdfdoc/glyphlist.txt"
    {"aibopomofo","311E"},
#line 2678 "pdfdoc/glyphlist.txt"
    {"muasquare","3382"},
#line 1431 "pdfdoc/glyphlist.txt"
    {"commaarabic","060C"},
#line 2901 "pdfdoc/glyphlist.txt"
    {"omacronacute","1E53"},
#line 312 "pdfdoc/glyphlist.txt"
    {"Iotatonos","038A"},
#line 1099 "pdfdoc/glyphlist.txt"
    {"anbopomofo","3122"},
#line 180 "pdfdoc/glyphlist.txt"
    {"Emacrongrave","1E14"},
#line 2764 "pdfdoc/glyphlist.txt"
    {"ninemonospace","FF19"},
#line 4118 "pdfdoc/glyphlist.txt"
    {"wynn","01BF"},
#line 2902 "pdfdoc/glyphlist.txt"
    {"omacrongrave","1E51"},
#line 1748 "pdfdoc/glyphlist.txt"
    {"emcyrillic","043C"},
#line 1403 "pdfdoc/glyphlist.txt"
    {"circlewithlefthalfblack","25D0"},
#line 2848 "pdfdoc/glyphlist.txt"
    {"nyagujarati","0A9E"},
#line 2358 "pdfdoc/glyphlist.txt"
    {"kaf","05DB"},
#line 1783 "pdfdoc/glyphlist.txt"
    {"escyrillic","0441"},
#line 4179 "pdfdoc/glyphlist.txt"
    {"ygrave","1EF3"},
#line 2683 "pdfdoc/glyphlist.txt"
    {"mugsquare","338D"},
#line 3484 "pdfdoc/glyphlist.txt"
    {"shaddaarabic","0651"},
#line 2689 "pdfdoc/glyphlist.txt"
    {"mumsquare","339B"},
#line 1703 "pdfdoc/glyphlist.txt"
    {"ehbopomofo","311D"},
#line 1475 "pdfdoc/glyphlist.txt"
    {"controlUS","001F"},
#line 1447 "pdfdoc/glyphlist.txt"
    {"controlBS","0008"},
#line 1706 "pdfdoc/glyphlist.txt"
    {"eibopomofo","311F"},
#line 1779 "pdfdoc/glyphlist.txt"
    {"erbopomofo","3126"},
#line 2696 "pdfdoc/glyphlist.txt"
    {"mussquare","33B2"},
#line 1754 "pdfdoc/glyphlist.txt"
    {"enbopomofo","3123"},
#line 1463 "pdfdoc/glyphlist.txt"
    {"controlFS","001C"},
#line 3492 "pdfdoc/glyphlist.txt"
    {"shadedark","2593"},
#line 4156 "pdfdoc/glyphlist.txt"
    {"yehhamzaabovearabic","0626"},
#line 3077 "pdfdoc/glyphlist.txt"
    {"phisymbolgreek","03D5"},
#line 4140 "pdfdoc/glyphlist.txt"
    {"yakatakanahalfwidth","FF94"},
#line 4218 "pdfdoc/glyphlist.txt"
    {"yukatakanahalfwidth","FF95"},
#line 4197 "pdfdoc/glyphlist.txt"
    {"yokatakanahalfwidth","FF96"},
#line 4158 "pdfdoc/glyphlist.txt"
    {"yehhamzaaboveinitialarabic","FE8B"},
#line 2183 "pdfdoc/glyphlist.txt"
    {"iacyrillic","044F"},
#line 2317 "pdfdoc/glyphlist.txt"
    {"iucyrillic","044E"},
#line 2297 "pdfdoc/glyphlist.txt"
    {"iocyrillic","0451"},
#line 2250 "pdfdoc/glyphlist.txt"
    {"iecyrillic","0435"},
#line 4147 "pdfdoc/glyphlist.txt"
    {"ycircle","24E8"},
#line 2262 "pdfdoc/glyphlist.txt"
    {"iicyrillic","0438"},
#line 4157 "pdfdoc/glyphlist.txt"
    {"yehhamzaabovefinalarabic","FE8A"},
#line 378 "pdfdoc/glyphlist.txt"
    {"MBsquare","3386"},
#line 2387 "pdfdoc/glyphlist.txt"
    {"katahiraprolongmarkhalfwidth","FF70"},
#line 1113 "pdfdoc/glyphlist.txt"
    {"anusvaradeva","0902"},
#line 332 "pdfdoc/glyphlist.txt"
    {"Kacyrillic","041A"},
#line 2424 "pdfdoc/glyphlist.txt"
    {"khomutthai","0E5B"},
#line 1737 "pdfdoc/glyphlist.txt"
    {"elcyrillic","043B"},
#line 235 "pdfdoc/glyphlist.txt"
    {"Gecyrillic","0413"},
#line 2126 "pdfdoc/glyphlist.txt"
    {"hieuhkorean","314E"},
#line 4141 "pdfdoc/glyphlist.txt"
    {"yakorean","3151"},
#line 4219 "pdfdoc/glyphlist.txt"
    {"yukorean","3160"},
#line 4198 "pdfdoc/glyphlist.txt"
    {"yokorean","315B"},
#line 4166 "pdfdoc/glyphlist.txt"
    {"yekorean","3156"},
#line 4184 "pdfdoc/glyphlist.txt"
    {"yikorean","3162"},
#line 1468 "pdfdoc/glyphlist.txt"
    {"controlRS","001E"},
#line 611 "pdfdoc/glyphlist.txt"
    {"Toarmenian","0539"},
#line 1098 "pdfdoc/glyphlist.txt"
    {"amsquare","33C2"},
#line 90 "pdfdoc/glyphlist.txt"
    {"Ccedillasmall","F7E7"},
#line 1114 "pdfdoc/glyphlist.txt"
    {"anusvaragujarati","0A82"},
#line 2687 "pdfdoc/glyphlist.txt"
    {"mulsquare","3395"},
#line 1254 "pdfdoc/glyphlist.txt"
    {"bindigurmukhi","0A02"},
#line 2667 "pdfdoc/glyphlist.txt"
    {"molsquare","33D6"},
#line 255 "pdfdoc/glyphlist.txt"
    {"HPsquare","33CB"},
#line 2303 "pdfdoc/glyphlist.txt"
    {"iotatonos","03AF"},
#line 1552 "pdfdoc/glyphlist.txt"
    {"dblanglebracketright","300B"},
#line 1956 "pdfdoc/glyphlist.txt"
    {"geometricallyequal","2251"},
#line 277 "pdfdoc/glyphlist.txt"
    {"IUcyrillic","042E"},
#line 2014 "pdfdoc/glyphlist.txt"
    {"greaterequalorless","22DB"},
#line 3628 "pdfdoc/glyphlist.txt"
    {"ssangkiyeokkorean","3132"},
#line 1343 "pdfdoc/glyphlist.txt"
    {"careof","2105"},
#line 2362 "pdfdoc/glyphlist.txt"
    {"kaffinalarabic","FEDA"},
#line 4103 "pdfdoc/glyphlist.txt"
    {"whiteuppointingtriangle","25B3"},
#line 236 "pdfdoc/glyphlist.txt"
    {"Ghadarmenian","0542"},
#line 1895 "pdfdoc/glyphlist.txt"
    {"fmsquare","3399"},
#line 1112 "pdfdoc/glyphlist.txt"
    {"anusvarabengali","0982"},
#line 2316 "pdfdoc/glyphlist.txt"
    {"iubopomofo","3129"},
#line 3305 "pdfdoc/glyphlist.txt"
    {"rieulaparenkorean","3211"},
#line 1902 "pdfdoc/glyphlist.txt"
    {"fourbengali","09EA"},
#line 1879 "pdfdoc/glyphlist.txt"
    {"fivegurmukhi","0A6B"},
#line 2370 "pdfdoc/glyphlist.txt"
    {"kahookcyrillic","04C4"},
#line 2698 "pdfdoc/glyphlist.txt"
    {"muwsquare","33BC"},
#line 4102 "pdfdoc/glyphlist.txt"
    {"whiteuppointingsmalltriangle","25B5"},
#line 3383 "pdfdoc/glyphlist.txt"
    {"sadinitialarabic","FEBB"},
#line 2714 "pdfdoc/glyphlist.txt"
    {"nasquare","3381"},
#line 1884 "pdfdoc/glyphlist.txt"
    {"fivemonospace","FF15"},
#line 2837 "pdfdoc/glyphlist.txt"
    {"numeralsigngreek","0374"},
#line 3982 "pdfdoc/glyphlist.txt"
    {"usmallhiragana","3045"},
#line 3170 "pdfdoc/glyphlist.txt"
    {"qofhatafpatah","05E7 05B2"},
#line 2013 "pdfdoc/glyphlist.txt"
    {"greaterequal","2265"},
#line 1222 "pdfdoc/glyphlist.txt"
    {"bbopomofo","3105"},
#line 623 "pdfdoc/glyphlist.txt"
    {"Uacutesmall","F7FA"},
#line 4079 "pdfdoc/glyphlist.txt"
    {"whitecircle","25CB"},
#line 1971 "pdfdoc/glyphlist.txt"
    {"ghaininitialarabic","FECF"},
#line 1625 "pdfdoc/glyphlist.txt"
    {"dlsquare","3397"},
#line 1667 "pdfdoc/glyphlist.txt"
    {"dzhecyrillic","045F"},
#line 3091 "pdfdoc/glyphlist.txt"
    {"pieupsioskorean","3144"},
#line 144 "pdfdoc/glyphlist.txt"
    {"Dzhecyrillic","040F"},
#line 4142 "pdfdoc/glyphlist.txt"
    {"yamakkanthai","0E4E"},
#line 4121 "pdfdoc/glyphlist.txt"
    {"xbopomofo","3112"},
#line 4202 "pdfdoc/glyphlist.txt"
    {"yotgreek","03F3"},
#line 1399 "pdfdoc/glyphlist.txt"
    {"circlemultiply","2297"},
#line 472 "pdfdoc/glyphlist.txt"
    {"Otcyrillic","047E"},
#line 1553 "pdfdoc/glyphlist.txt"
    {"dblanglebracketrightvertical","FE3E"},
#line 560 "pdfdoc/glyphlist.txt"
    {"Sampigreek","03E0"},
#line 2782 "pdfdoc/glyphlist.txt"
    {"nmsquare","339A"},
#line 3142 "pdfdoc/glyphlist.txt"
    {"qafarabic","0642"},
#line 2973 "pdfdoc/glyphlist.txt"
    {"overscore","00AF"},
#line 279 "pdfdoc/glyphlist.txt"
    {"Iacutesmall","F7ED"},
#line 4080 "pdfdoc/glyphlist.txt"
    {"whitecircleinverse","25D9"},
#line 706 "pdfdoc/glyphlist.txt"
    {"Yacutesmall","F7FD"},
#line 2072 "pdfdoc/glyphlist.txt"
    {"hatafqamats34","05B3"},
#line 2823 "pdfdoc/glyphlist.txt"
    {"nssquare","33B1"},
#line 2838 "pdfdoc/glyphlist.txt"
    {"numeralsignlowergreek","0375"},
#line 3312 "pdfdoc/glyphlist.txt"
    {"rieulpansioskorean","316C"},
#line 1550 "pdfdoc/glyphlist.txt"
    {"dblanglebracketleft","300A"},
#line 328 "pdfdoc/glyphlist.txt"
    {"KBsquare","3385"},
#line 3092 "pdfdoc/glyphlist.txt"
    {"pieupsiostikeutkorean","3175"},
#line 222 "pdfdoc/glyphlist.txt"
    {"GBsquare","3387"},
#line 329 "pdfdoc/glyphlist.txt"
    {"KKsquare","33CD"},
#line 1407 "pdfdoc/glyphlist.txt"
    {"circumflexcmb","0302"},
#line 1476 "pdfdoc/glyphlist.txt"
    {"controlVT","000B"},
#line 2420 "pdfdoc/glyphlist.txt"
    {"khokhaithai","0E02"},
#line 2697 "pdfdoc/glyphlist.txt"
    {"muvsquare","33B6"},
#line 741 "pdfdoc/glyphlist.txt"
    {"Zedieresiscyrillic","04DE"},
#line 3599 "pdfdoc/glyphlist.txt"
    {"spadesuitblack","2660"},
#line 2754 "pdfdoc/glyphlist.txt"
    {"ninebengali","09EF"},
#line 2605 "pdfdoc/glyphlist.txt"
    {"maqafhebrew","05BE"},
#line 456 "pdfdoc/glyphlist.txt"
    {"Omegagreek","03A9"},
#line 2432 "pdfdoc/glyphlist.txt"
    {"kiromeetorusquare","3316"},
#line 3600 "pdfdoc/glyphlist.txt"
    {"spadesuitwhite","2664"},
#line 2061 "pdfdoc/glyphlist.txt"
    {"hatafpatah","05B2"},
#line 2179 "pdfdoc/glyphlist.txt"
    {"hyphensuperior","F6E6"},
#line 1380 "pdfdoc/glyphlist.txt"
    {"cheverticalstrokecyrillic","04B9"},
#line 4213 "pdfdoc/glyphlist.txt"
    {"ytilde","1EF9"},
#line 4214 "pdfdoc/glyphlist.txt"
    {"yturned","028E"},
#line 1477 "pdfdoc/glyphlist.txt"
    {"copyright","00A9"},
#line 2454 "pdfdoc/glyphlist.txt"
    {"koroniscmb","0343"},
#line 1486 "pdfdoc/glyphlist.txt"
    {"corporationsquare","337F"},
#line 3124 "pdfdoc/glyphlist.txt"
    {"projective","2305"},
#line 2025 "pdfdoc/glyphlist.txt"
    {"guilsinglleft","2039"},
#line 2060 "pdfdoc/glyphlist.txt"
    {"hasquare","33CA"},
#line 1905 "pdfdoc/glyphlist.txt"
    {"fourdeva","096A"},
#line 1551 "pdfdoc/glyphlist.txt"
    {"dblanglebracketleftvertical","FE3D"},
#line 1976 "pdfdoc/glyphlist.txt"
    {"ghhadeva","095A"},
#line 3916 "pdfdoc/glyphlist.txt"
    {"uacute","00FA"},
#line 2907 "pdfdoc/glyphlist.txt"
    {"omegalatinclosed","0277"},
#line 1361 "pdfdoc/glyphlist.txt"
    {"centigrade","2103"},
#line 1647 "pdfdoc/glyphlist.txt"
    {"dotlessj","F6BE"},
#line 2845 "pdfdoc/glyphlist.txt"
    {"nwsquare","33BB"},
#line 2456 "pdfdoc/glyphlist.txt"
    {"kpasquare","33AA"},
#line 3306 "pdfdoc/glyphlist.txt"
    {"rieulcirclekorean","3263"},
#line 194 "pdfdoc/glyphlist.txt"
    {"Ereversedcyrillic","042D"},
#line 2490 "pdfdoc/glyphlist.txt"
    {"lamedholamhebrew","05DC 05B9"},
#line 4052 "pdfdoc/glyphlist.txt"
    {"waekorean","3159"},
#line 4076 "pdfdoc/glyphlist.txt"
    {"weokorean","315D"},
#line 3235 "pdfdoc/glyphlist.txt"
    {"rafehebrew","05BF"},
#line 3028 "pdfdoc/glyphlist.txt"
    {"pbopomofo","3106"},
#line 2482 "pdfdoc/glyphlist.txt"
    {"lambdastroke","019B"},
#line 2636 "pdfdoc/glyphlist.txt"
    {"mhzsquare","3392"},
#line 762 "pdfdoc/glyphlist.txt"
    {"aavowelsigngujarati","0ABE"},
#line 1204 "pdfdoc/glyphlist.txt"
    {"auvowelsigngujarati","0ACC"},
#line 2177 "pdfdoc/glyphlist.txt"
    {"hyphenmonospace","FF0D"},
#line 3942 "pdfdoc/glyphlist.txt"
    {"uhookabove","1EE7"},
#line 3637 "pdfdoc/glyphlist.txt"
    {"strokeshortoverlaycmb","0335"},
#line 1067 "pdfdoc/glyphlist.txt"
    {"aivowelsigngujarati","0AC8"},
#line 1309 "pdfdoc/glyphlist.txt"
    {"bracketrightex","F8FA"},
#line 4040 "pdfdoc/glyphlist.txt"
    {"voicediterationhiragana","309E"},
#line 1119 "pdfdoc/glyphlist.txt"
    {"apostrophemod","02BC"},
#line 1529 "pdfdoc/glyphlist.txt"
    {"daletpatahhebrew","05D3 05B7"},
#line 1478 "pdfdoc/glyphlist.txt"
    {"copyrightsans","F8E9"},
#line 1212 "pdfdoc/glyphlist.txt"
    {"backslash","005C"},
#line 3585 "pdfdoc/glyphlist.txt"
    {"softhyphen","00AD"},
#line 1307 "pdfdoc/glyphlist.txt"
    {"bracketright","005D"},
#line 4041 "pdfdoc/glyphlist.txt"
    {"voicediterationkatakana","30FE"},
#line 4178 "pdfdoc/glyphlist.txt"
    {"yetivhebrew","059A"},
#line 3346 "pdfdoc/glyphlist.txt"
    {"roruathai","0E23"},
#line 1443 "pdfdoc/glyphlist.txt"
    {"contourintegral","222E"},
#line 126 "pdfdoc/glyphlist.txt"
    {"Deltagreek","0394"},
#line 2646 "pdfdoc/glyphlist.txt"
    {"mieumsioskorean","316F"},
#line 1213 "pdfdoc/glyphlist.txt"
    {"backslashmonospace","FF3C"},
#line 1310 "pdfdoc/glyphlist.txt"
    {"bracketrightmonospace","FF3D"},
#line 3172 "pdfdoc/glyphlist.txt"
    {"qofhatafsegol","05E7 05B1"},
#line 1873 "pdfdoc/glyphlist.txt"
    {"fivebengali","09EB"},
#line 2844 "pdfdoc/glyphlist.txt"
    {"nvsquare","33B5"},
#line 2856 "pdfdoc/glyphlist.txt"
    {"obengali","0993"},
#line 2757 "pdfdoc/glyphlist.txt"
    {"ninedeva","096F"},
#line 2593 "pdfdoc/glyphlist.txt"
    {"maitholowrightthai","F88E"},
#line 2565 "pdfdoc/glyphlist.txt"
    {"lxsquare","33D3"},
#line 1064 "pdfdoc/glyphlist.txt"
    {"ainvertedbreve","0203"},
#line 3606 "pdfdoc/glyphlist.txt"
    {"squarehorizontalfill","25A4"},
#line 653 "pdfdoc/glyphlist.txt"
    {"Uinvertedbreve","0216"},
#line 1584 "pdfdoc/glyphlist.txt"
    {"ddhagurmukhi","0A22"},
#line 3179 "pdfdoc/glyphlist.txt"
    {"qofpatah","05E7 05B7"},
#line 2597 "pdfdoc/glyphlist.txt"
    {"maitrilowrightthai","F891"},
#line 415 "pdfdoc/glyphlist.txt"
    {"Oacutesmall","F7F3"},
#line 1994 "pdfdoc/glyphlist.txt"
    {"glottalstopreversedsuperior","02E4"},
#line 2067 "pdfdoc/glyphlist.txt"
    {"hatafpatahquarterhebrew","05B2"},
#line 511 "pdfdoc/glyphlist.txt"
    {"Rinvertedbreve","0212"},
#line 2071 "pdfdoc/glyphlist.txt"
    {"hatafqamats28","05B3"},
#line 2787 "pdfdoc/glyphlist.txt"
    {"nnnadeva","0929"},
#line 631 "pdfdoc/glyphlist.txt"
    {"Udblacute","0170"},
#line 301 "pdfdoc/glyphlist.txt"
    {"Iinvertedbreve","020A"},
#line 2543 "pdfdoc/glyphlist.txt"
    {"lmsquare","33D0"},
#line 679 "pdfdoc/glyphlist.txt"
    {"Vecyrillic","0412"},
#line 3979 "pdfdoc/glyphlist.txt"
    {"uragurmukhi","0A73"},
#line 273 "pdfdoc/glyphlist.txt"
    {"Hzsquare","3390"},
#line 4039 "pdfdoc/glyphlist.txt"
    {"voarmenian","0578"},
#line 3670 "pdfdoc/glyphlist.txt"
    {"tau","03C4"},
#line 3413 "pdfdoc/glyphlist.txt"
    {"sbopomofo","3119"},
#line 1613 "pdfdoc/glyphlist.txt"
    {"dieresiscmb","0308"},
#line 1731 "pdfdoc/glyphlist.txt"
    {"einvertedbreve","0207"},
#line 2890 "pdfdoc/glyphlist.txt"
    {"ohorngrave","1EDD"},
#line 2922 "pdfdoc/glyphlist.txt"
    {"oneeighth","215B"},
#line 4134 "pdfdoc/glyphlist.txt"
    {"yadeva","092F"},
#line 4051 "pdfdoc/glyphlist.txt"
    {"wacute","1E83"},
#line 2694 "pdfdoc/glyphlist.txt"
    {"musicflatsign","266D"},
#line 3576 "pdfdoc/glyphlist.txt"
    {"sixteenperiod","2497"},
#line 3654 "pdfdoc/glyphlist.txt"
    {"t","0074"},
#line 3297 "pdfdoc/glyphlist.txt"
    {"rhadeva","095D"},
#line 4013 "pdfdoc/glyphlist.txt"
    {"vavvavhebrew","05F0"},
#line 173 "pdfdoc/glyphlist.txt"
    {"Eightroman","2167"},
#line 3015 "pdfdoc/glyphlist.txt"
    {"partialdiff","2202"},
#line 3349 "pdfdoc/glyphlist.txt"
    {"rradeva","0931"},
#line 3526 "pdfdoc/glyphlist.txt"
    {"shindothebrew","05C1"},
#line 3757 "pdfdoc/glyphlist.txt"
    {"thorn","00FE"},
#line 3765 "pdfdoc/glyphlist.txt"
    {"three","0033"},
#line 3318 "pdfdoc/glyphlist.txt"
    {"rieulthieuthkorean","313E"},
#line 2271 "pdfdoc/glyphlist.txt"
    {"iivowelsigngujarati","0AC0"},
#line 3678 "pdfdoc/glyphlist.txt"
    {"tcaron","0165"},
#line 1995 "pdfdoc/glyphlist.txt"
    {"glottalstopstroke","02A1"},
#line 2924 "pdfdoc/glyphlist.txt"
    {"onegujarati","0AE7"},
#line 3731 "pdfdoc/glyphlist.txt"
    {"thalarabic","0630"},
#line 3917 "pdfdoc/glyphlist.txt"
    {"ubar","0289"},
#line 3755 "pdfdoc/glyphlist.txt"
    {"thook","01AD"},
#line 666 "pdfdoc/glyphlist.txt"
    {"Upsilonhooksymbol","03D2"},
#line 2016 "pdfdoc/glyphlist.txt"
    {"greaterorequivalent","2273"},
#line 3737 "pdfdoc/glyphlist.txt"
    {"theharabic","062B"},
#line 2062 "pdfdoc/glyphlist.txt"
    {"hatafpatah16","05B2"},
#line 3664 "pdfdoc/glyphlist.txt"
    {"tahiragana","305F"},
#line 3875 "pdfdoc/glyphlist.txt"
    {"tuhiragana","3064"},
#line 2017 "pdfdoc/glyphlist.txt"
    {"greaterorless","2277"},
#line 3720 "pdfdoc/glyphlist.txt"
    {"tet","05D8"},
#line 3815 "pdfdoc/glyphlist.txt"
    {"tohiragana","3068"},
#line 3699 "pdfdoc/glyphlist.txt"
    {"tehiragana","3066"},
#line 4238 "pdfdoc/glyphlist.txt"
    {"zahinitialarabic","FEC7"},
#line 3790 "pdfdoc/glyphlist.txt"
    {"tihiragana","3061"},
#line 4207 "pdfdoc/glyphlist.txt"
    {"yparen","24B4"},
#line 3719 "pdfdoc/glyphlist.txt"
    {"tesh","02A7"},
#line 3852 "pdfdoc/glyphlist.txt"
    {"tsere","05B5"},
#line 2978 "pdfdoc/glyphlist.txt"
    {"paampssquare","3380"},
#line 3727 "pdfdoc/glyphlist.txt"
    {"thabengali","09A5"},
#line 3741 "pdfdoc/glyphlist.txt"
    {"thereexists","2203"},
#line 3061 "pdfdoc/glyphlist.txt"
    {"perthousand","2030"},
#line 3714 "pdfdoc/glyphlist.txt"
    {"tencircle","2469"},
#line 3866 "pdfdoc/glyphlist.txt"
    {"tteharabic","0679"},
#line 170 "pdfdoc/glyphlist.txt"
    {"Egravesmall","F7E8"},
#line 3740 "pdfdoc/glyphlist.txt"
    {"thehmedialarabic","FE9C"},
#line 647 "pdfdoc/glyphlist.txt"
    {"Uhorndotbelow","1EF0"},
#line 2267 "pdfdoc/glyphlist.txt"
    {"iinvertedbreve","020B"},
#line 3846 "pdfdoc/glyphlist.txt"
    {"ts","02A6"},
#line 1876 "pdfdoc/glyphlist.txt"
    {"fivedeva","096B"},
#line 3824 "pdfdoc/glyphlist.txt"
    {"tonesix","0185"},
#line 3602 "pdfdoc/glyphlist.txt"
    {"squarebelowcmb","033B"},
#line 3862 "pdfdoc/glyphlist.txt"
    {"ttabengali","099F"},
#line 3661 "pdfdoc/glyphlist.txt"
    {"taharabic","0637"},
#line 1742 "pdfdoc/glyphlist.txt"
    {"elevenroman","217A"},
#line 1851 "pdfdoc/glyphlist.txt"
    {"filledrect","25AC"},
#line 3694 "pdfdoc/glyphlist.txt"
    {"teharabic","062A"},
#line 2066 "pdfdoc/glyphlist.txt"
    {"hatafpatahnarrowhebrew","05B2"},
#line 1924 "pdfdoc/glyphlist.txt"
    {"fourthtonechinese","02CB"},
#line 3180 "pdfdoc/glyphlist.txt"
    {"qofpatahhebrew","05E7 05B7"},
#line 3826 "pdfdoc/glyphlist.txt"
    {"tonos","0384"},
#line 3869 "pdfdoc/glyphlist.txt"
    {"ttehmedialarabic","FB69"},
#line 4159 "pdfdoc/glyphlist.txt"
    {"yehhamzaabovemedialarabic","FE8C"},
#line 606 "pdfdoc/glyphlist.txt"
    {"Threeroman","2162"},
#line 3853 "pdfdoc/glyphlist.txt"
    {"tsere12","05B5"},
#line 3990 "pdfdoc/glyphlist.txt"
    {"uubengali","098A"},
#line 3289 "pdfdoc/glyphlist.txt"
    {"reshtserehebrew","05E8 05B5"},
#line 1375 "pdfdoc/glyphlist.txt"
    {"chedescenderabkhasiancyrillic","04BF"},
#line 3889 "pdfdoc/glyphlist.txt"
    {"two","0032"},
#line 1376 "pdfdoc/glyphlist.txt"
    {"chedescendercyrillic","04B7"},
#line 1084 "pdfdoc/glyphlist.txt"
    {"alefmaksurafinalarabic","FEF0"},
#line 175 "pdfdoc/glyphlist.txt"
    {"Eiotifiedcyrillic","0464"},
#line 2366 "pdfdoc/glyphlist.txt"
    {"kafrafehebrew","FB4D"},
#line 1846 "pdfdoc/glyphlist.txt"
    {"fifteencircle","246E"},
#line 1847 "pdfdoc/glyphlist.txt"
    {"fifteenparen","2482"},
#line 3795 "pdfdoc/glyphlist.txt"
    {"tikeutcirclekorean","3262"},
#line 3989 "pdfdoc/glyphlist.txt"
    {"utildebelow","1E75"},
#line 2921 "pdfdoc/glyphlist.txt"
    {"onedotenleader","2024"},
#line 3688 "pdfdoc/glyphlist.txt"
    {"tcommaaccent","0163"},
#line 3046 "pdfdoc/glyphlist.txt"
    {"perafehebrew","FB4E"},
#line 2007 "pdfdoc/glyphlist.txt"
    {"gravecomb","0300"},
#line 450 "pdfdoc/glyphlist.txt"
    {"Oinvertedbreve","020E"},
#line 1425 "pdfdoc/glyphlist.txt"
    {"colontriangularhalfmod","02D1"},
#line 1581 "pdfdoc/glyphlist.txt"
    {"ddhabengali","09A2"},
#line 3892 "pdfdoc/glyphlist.txt"
    {"twocircle","2461"},
#line 430 "pdfdoc/glyphlist.txt"
    {"Odblacute","0150"},
#line 3891 "pdfdoc/glyphlist.txt"
    {"twobengali","09E8"},
#line 310 "pdfdoc/glyphlist.txt"
    {"Iotaafrican","0196"},
#line 1105 "pdfdoc/glyphlist.txt"
    {"anglebracketright","3009"},
#line 4148 "pdfdoc/glyphlist.txt"
    {"ycircumflex","0177"},
#line 3667 "pdfdoc/glyphlist.txt"
    {"takatakana","30BF"},
#line 3876 "pdfdoc/glyphlist.txt"
    {"tukatakana","30C4"},
#line 1426 "pdfdoc/glyphlist.txt"
    {"colontriangularmod","02D0"},
#line 3793 "pdfdoc/glyphlist.txt"
    {"tikeutacirclekorean","3270"},
#line 3816 "pdfdoc/glyphlist.txt"
    {"tokatakana","30C8"},
#line 3708 "pdfdoc/glyphlist.txt"
    {"tekatakana","30C6"},
#line 3791 "pdfdoc/glyphlist.txt"
    {"tikatakana","30C1"},
#line 1915 "pdfdoc/glyphlist.txt"
    {"fourparen","2477"},
#line 3794 "pdfdoc/glyphlist.txt"
    {"tikeutaparenkorean","3210"},
#line 187 "pdfdoc/glyphlist.txt"
    {"Enhookcyrillic","04C7"},
#line 3416 "pdfdoc/glyphlist.txt"
    {"scedilla","015F"},
#line 3890 "pdfdoc/glyphlist.txt"
    {"twoarabic","0662"},
#line 3225 "pdfdoc/glyphlist.txt"
    {"raarmenian","057C"},
#line 1228 "pdfdoc/glyphlist.txt"
    {"becyrillic","0431"},
#line 2178 "pdfdoc/glyphlist.txt"
    {"hyphensmall","FE63"},
#line 2440 "pdfdoc/glyphlist.txt"
    {"kjecyrillic","045C"},
#line 1794 "pdfdoc/glyphlist.txt"
    {"estimated","212E"},
#line 3735 "pdfdoc/glyphlist.txt"
    {"thanthakhatthai","0E4C"},
#line 4188 "pdfdoc/glyphlist.txt"
    {"yod","05D9"},
#line 3264 "pdfdoc/glyphlist.txt"
    {"rehyehaleflamarabic","0631 FEF3 FE8E 0644"},
#line 3584 "pdfdoc/glyphlist.txt"
    {"sofpasuqhebrew","05C3"},
#line 2645 "pdfdoc/glyphlist.txt"
    {"mieumpieupkorean","316E"},
#line 3362 "pdfdoc/glyphlist.txt"
    {"rturnedsuperior","02B4"},
#line 2015 "pdfdoc/glyphlist.txt"
    {"greatermonospace","FF1E"},
#line 3926 "pdfdoc/glyphlist.txt"
    {"udattadeva","0951"},
#line 4162 "pdfdoc/glyphlist.txt"
    {"yehmeeminitialarabic","FCDD"},
#line 3651 "pdfdoc/glyphlist.txt"
    {"supersetorequal","2287"},
#line 24 "pdfdoc/glyphlist.txt"
    {"Aacutesmall","F7E1"},
#line 3611 "pdfdoc/glyphlist.txt"
    {"squarelog","33D2"},
#line 4163 "pdfdoc/glyphlist.txt"
    {"yehmeemisolatedarabic","FC58"},
#line 370 "pdfdoc/glyphlist.txt"
    {"Lj","01C8"},
#line 3854 "pdfdoc/glyphlist.txt"
    {"tsere1e","05B5"},
#line 1106 "pdfdoc/glyphlist.txt"
    {"anglebracketrightvertical","FE40"},
#line 3920 "pdfdoc/glyphlist.txt"
    {"ubreve","016D"},
#line 402 "pdfdoc/glyphlist.txt"
    {"Nj","01CB"},
#line 1934 "pdfdoc/glyphlist.txt"
    {"gafinitialarabic","FB94"},
#line 3313 "pdfdoc/glyphlist.txt"
    {"rieulparenkorean","3203"},
#line 2063 "pdfdoc/glyphlist.txt"
    {"hatafpatah23","05B2"},
#line 1658 "pdfdoc/glyphlist.txt"
    {"dtopbar","018C"},
#line 81 "pdfdoc/glyphlist.txt"
    {"Btopbar","0182"},
#line 139 "pdfdoc/glyphlist.txt"
    {"Dtopbar","018B"},
#line 2672 "pdfdoc/glyphlist.txt"
    {"mpasquare","33AB"},
#line 1898 "pdfdoc/glyphlist.txt"
    {"fongmanthai","0E4F"},
#line 3900 "pdfdoc/glyphlist.txt"
    {"twohackarabic","0662"},
#line 444 "pdfdoc/glyphlist.txt"
    {"Ohorndotbelow","1EE2"},
#line 3743 "pdfdoc/glyphlist.txt"
    {"theta","03B8"},
#line 3744 "pdfdoc/glyphlist.txt"
    {"theta1","03D1"},
#line 3321 "pdfdoc/glyphlist.txt"
    {"rightangle","221F"},
#line 2766 "pdfdoc/glyphlist.txt"
    {"nineparen","247C"},
#line 3616 "pdfdoc/glyphlist.txt"
    {"squareorthogonalcrosshatchfill","25A6"},
#line 761 "pdfdoc/glyphlist.txt"
    {"aavowelsigndeva","093E"},
#line 1203 "pdfdoc/glyphlist.txt"
    {"auvowelsigndeva","094C"},
#line 193 "pdfdoc/glyphlist.txt"
    {"Ereversed","018E"},
#line 4057 "pdfdoc/glyphlist.txt"
    {"wasmallhiragana","308E"},
#line 4085 "pdfdoc/glyphlist.txt"
    {"whitediamond","25C7"},
#line 3733 "pdfdoc/glyphlist.txt"
    {"thanthakhatlowleftthai","F898"},
#line 1066 "pdfdoc/glyphlist.txt"
    {"aivowelsigndeva","0948"},
#line 3734 "pdfdoc/glyphlist.txt"
    {"thanthakhatlowrightthai","F897"},
#line 420 "pdfdoc/glyphlist.txt"
    {"Ocenteredtilde","019F"},
#line 2594 "pdfdoc/glyphlist.txt"
    {"maithothai","0E49"},
#line 2389 "pdfdoc/glyphlist.txt"
    {"kbopomofo","310E"},
#line 3668 "pdfdoc/glyphlist.txt"
    {"takatakanahalfwidth","FF80"},
#line 1103 "pdfdoc/glyphlist.txt"
    {"anglebracketleft","3008"},
#line 3877 "pdfdoc/glyphlist.txt"
    {"tukatakanahalfwidth","FF82"},
#line 3817 "pdfdoc/glyphlist.txt"
    {"tokatakanahalfwidth","FF84"},
#line 3709 "pdfdoc/glyphlist.txt"
    {"tekatakanahalfwidth","FF83"},
#line 3792 "pdfdoc/glyphlist.txt"
    {"tikatakanahalfwidth","FF81"},
#line 2598 "pdfdoc/glyphlist.txt"
    {"maitrithai","0E4A"},
#line 1539 "pdfdoc/glyphlist.txt"
    {"dalettserehebrew","05D3 05B5"},
#line 1582 "pdfdoc/glyphlist.txt"
    {"ddhadeva","0922"},
#line 3686 "pdfdoc/glyphlist.txt"
    {"tcircle","24E3"},
#line 2701 "pdfdoc/glyphlist.txt"
    {"mwmegasquare","33BF"},
#line 2631 "pdfdoc/glyphlist.txt"
    {"merkhahebrew","05A5"},
#line 3775 "pdfdoc/glyphlist.txt"
    {"threehangzhou","3023"},
#line 2775 "pdfdoc/glyphlist.txt"
    {"nj","01CC"},
#line 4086 "pdfdoc/glyphlist.txt"
    {"whitediamondcontainingblacksmalldiamond","25C8"},
#line 190 "pdfdoc/glyphlist.txt"
    {"Epsilon","0395"},
#line 1134 "pdfdoc/glyphlist.txt"
    {"arrowdashleft","21E0"},
#line 3307 "pdfdoc/glyphlist.txt"
    {"rieulhieuhkorean","3140"},
#line 2536 "pdfdoc/glyphlist.txt"
    {"llladeva","0934"},
#line 2118 "pdfdoc/glyphlist.txt"
    {"herutusquare","3339"},
#line 3650 "pdfdoc/glyphlist.txt"
    {"supersetnotequal","228B"},
#line 3101 "pdfdoc/glyphlist.txt"
    {"pluscircle","2295"},
#line 3032 "pdfdoc/glyphlist.txt"
    {"pecyrillic","043F"},
#line 785 "pdfdoc/glyphlist.txt"
    {"acutecomb","0301"},
#line 1348 "pdfdoc/glyphlist.txt"
    {"cbopomofo","3118"},
#line 3718 "pdfdoc/glyphlist.txt"
    {"tenroman","2179"},
#line 3590 "pdfdoc/glyphlist.txt"
    {"soliduslongoverlaycmb","0338"},
#line 607 "pdfdoc/glyphlist.txt"
    {"Tildesmall","F6FE"},
#line 2272 "pdfdoc/glyphlist.txt"
    {"ij","0133"},
#line 3881 "pdfdoc/glyphlist.txt"
    {"twelvecircle","246B"},
#line 1104 "pdfdoc/glyphlist.txt"
    {"anglebracketleftvertical","FE3F"},
#line 3311 "pdfdoc/glyphlist.txt"
    {"rieulmieumkorean","313B"},
#line 4058 "pdfdoc/glyphlist.txt"
    {"wasmallkatakana","30EE"},
#line 2990 "pdfdoc/glyphlist.txt"
    {"palatalizationcyrilliccmb","0484"},
#line 2669 "pdfdoc/glyphlist.txt"
    {"moverssquare","33A7"},
#line 3961 "pdfdoc/glyphlist.txt"
    {"underscore","005F"},
#line 1992 "pdfdoc/glyphlist.txt"
    {"glottalstopreversed","0295"},
#line 1993 "pdfdoc/glyphlist.txt"
    {"glottalstopreversedmod","02C1"},
#line 3671 "pdfdoc/glyphlist.txt"
    {"tav","05EA"},
#line 3517 "pdfdoc/glyphlist.txt"
    {"shhacyrillic","04BB"},
#line 3856 "pdfdoc/glyphlist.txt"
    {"tserehebrew","05B5"},
#line 2699 "pdfdoc/glyphlist.txt"
    {"mvmegasquare","33B9"},
#line 1904 "pdfdoc/glyphlist.txt"
    {"fourcircleinversesansserif","278D"},
#line 1990 "pdfdoc/glyphlist.txt"
    {"glottalstopinverted","0296"},
#line 3547 "pdfdoc/glyphlist.txt"
    {"sioscirclekorean","3266"},
#line 2365 "pdfdoc/glyphlist.txt"
    {"kafmedialarabic","FEDC"},
#line 773 "pdfdoc/glyphlist.txt"
    {"abrevetilde","1EB5"},
#line 2068 "pdfdoc/glyphlist.txt"
    {"hatafpatahwidehebrew","05B2"},
#line 1991 "pdfdoc/glyphlist.txt"
    {"glottalstopmod","02C0"},
#line 4187 "pdfdoc/glyphlist.txt"
    {"ymonospace","FF59"},
#line 4070 "pdfdoc/glyphlist.txt"
    {"wdotaccent","1E87"},
#line 1886 "pdfdoc/glyphlist.txt"
    {"fiveparen","2478"},
#line 2270 "pdfdoc/glyphlist.txt"
    {"iivowelsigndeva","0940"},
#line 1200 "pdfdoc/glyphlist.txt"
    {"aulengthmarkbengali","09D7"},
#line 4063 "pdfdoc/glyphlist.txt"
    {"wawfinalarabic","FEEE"},
#line 2909 "pdfdoc/glyphlist.txt"
    {"omegatitlocyrillic","047D"},
#line 3230 "pdfdoc/glyphlist.txt"
    {"radicalex","F8E5"},
#line 1306 "pdfdoc/glyphlist.txt"
    {"bracketlefttp","F8EE"},
#line 55 "pdfdoc/glyphlist.txt"
    {"Ainvertedbreve","0202"},
#line 4120 "pdfdoc/glyphlist.txt"
    {"xabovecmb","033D"},
#line 1720 "pdfdoc/glyphlist.txt"
    {"eighthnotebeamed","266B"},
#line 2621 "pdfdoc/glyphlist.txt"
    {"meetorusquare","334D"},
#line 1236 "pdfdoc/glyphlist.txt"
    {"behnoonfinalarabic","FC6D"},
#line 3771 "pdfdoc/glyphlist.txt"
    {"threeeighths","215C"},
#line 3841 "pdfdoc/glyphlist.txt"
    {"tretroflexhook","0288"},
#line 3018 "pdfdoc/glyphlist.txt"
    {"pasquare","33A9"},
#line 2005 "pdfdoc/glyphlist.txt"
    {"gravebelowcmb","0316"},
#line 1996 "pdfdoc/glyphlist.txt"
    {"glottalstopstrokereversed","02A2"},
#line 3910 "pdfdoc/glyphlist.txt"
    {"tworoman","2171"},
#line 3874 "pdfdoc/glyphlist.txt"
    {"tturned","0287"},
#line 2756 "pdfdoc/glyphlist.txt"
    {"ninecircleinversesansserif","2792"},
#line 3964 "pdfdoc/glyphlist.txt"
    {"underscorevertical","FE33"},
#line 1790 "pdfdoc/glyphlist.txt"
    {"eshsquatreversed","0285"},
#line 3108 "pdfdoc/glyphlist.txt"
    {"pmsquare","33D8"},
#line 4020 "pdfdoc/glyphlist.txt"
    {"vehinitialarabic","FB6C"},
#line 4285 "pdfdoc/glyphlist.txt"
    {"zhedescendercyrillic","0497"},
#line 3499 "pdfdoc/glyphlist.txt"
    {"shbopomofo","3115"},
#line 2571 "pdfdoc/glyphlist.txt"
    {"macronlowmod","02CD"},
#line 3134 "pdfdoc/glyphlist.txt"
    {"pssquare","33B0"},
#line 461 "pdfdoc/glyphlist.txt"
    {"Omicrontonos","038C"},
#line 2392 "pdfdoc/glyphlist.txt"
    {"kcedilla","0137"},
#line 4116 "pdfdoc/glyphlist.txt"
    {"wsuperior","02B7"},
#line 2530 "pdfdoc/glyphlist.txt"
    {"lj","01C9"},
#line 769 "pdfdoc/glyphlist.txt"
    {"abrevecyrillic","04D1"},
#line 3725 "pdfdoc/glyphlist.txt"
    {"tevirhebrew","059B"},
#line 352 "pdfdoc/glyphlist.txt"
    {"Koppagreek","03DE"},
#line 2612 "pdfdoc/glyphlist.txt"
    {"mcubedsquare","33A5"},
#line 3752 "pdfdoc/glyphlist.txt"
    {"thirteenparen","2480"},
#line 4130 "pdfdoc/glyphlist.txt"
    {"y","0079"},
#line 2891 "pdfdoc/glyphlist.txt"
    {"ohornhookabove","1EDF"},
#line 3967 "pdfdoc/glyphlist.txt"
    {"universal","2200"},
#line 1350 "pdfdoc/glyphlist.txt"
    {"ccedilla","00E7"},
#line 368 "pdfdoc/glyphlist.txt"
    {"Ldotbelowmacron","1E38"},
#line 3621 "pdfdoc/glyphlist.txt"
    {"srsquare","33DB"},
#line 506 "pdfdoc/glyphlist.txt"
    {"Rdotbelowmacron","1E5C"},
#line 1798 "pdfdoc/glyphlist.txt"
    {"etatonos","03AE"},
#line 3567 "pdfdoc/glyphlist.txt"
    {"sixoldstyle","F736"},
#line 2102 "pdfdoc/glyphlist.txt"
    {"hehebrew","05D4"},
#line 3138 "pdfdoc/glyphlist.txt"
    {"pwsquare","33BA"},
#line 2974 "pdfdoc/glyphlist.txt"
    {"ovowelsignbengali","09CB"},
#line 1311 "pdfdoc/glyphlist.txt"
    {"bracketrighttp","F8F9"},
#line 573 "pdfdoc/glyphlist.txt"
    {"Sdotbelowdotaccent","1E68"},
#line 1989 "pdfdoc/glyphlist.txt"
    {"glottalstop","0294"},
#line 1875 "pdfdoc/glyphlist.txt"
    {"fivecircleinversesansserif","278E"},
#line 1351 "pdfdoc/glyphlist.txt"
    {"ccedillaacute","1E09"},
#line 2948 "pdfdoc/glyphlist.txt"
    {"openbullet","25E6"},
#line 1319 "pdfdoc/glyphlist.txt"
    {"bridgeinvertedbelowcmb","033A"},
#line 1338 "pdfdoc/glyphlist.txt"
    {"candrabindubengali","0981"},
#line 4229 "pdfdoc/glyphlist.txt"
    {"yyabengali","09DF"},
#line 3111 "pdfdoc/glyphlist.txt"
    {"pointingindexleftwhite","261C"},
#line 4170 "pdfdoc/glyphlist.txt"
    {"yeorinhieuhkorean","3186"},
#line 3751 "pdfdoc/glyphlist.txt"
    {"thirteencircle","246C"},
#line 3658 "pdfdoc/glyphlist.txt"
    {"tadeva","0924"},
#line 1339 "pdfdoc/glyphlist.txt"
    {"candrabinducmb","0310"},
#line 572 "pdfdoc/glyphlist.txt"
    {"Sdotbelow","1E62"},
#line 2713 "pdfdoc/glyphlist.txt"
    {"napostrophe","0149"},
#line 738 "pdfdoc/glyphlist.txt"
    {"Zdotbelow","1E92"},
#line 796 "pdfdoc/glyphlist.txt"
    {"adotbelow","1EA1"},
#line 692 "pdfdoc/glyphlist.txt"
    {"Wdotbelow","1E88"},
#line 3137 "pdfdoc/glyphlist.txt"
    {"pvsquare","33B4"},
#line 641 "pdfdoc/glyphlist.txt"
    {"Udotbelow","1EE4"},
#line 783 "pdfdoc/glyphlist.txt"
    {"acutebelowcmb","0317"},
#line 3314 "pdfdoc/glyphlist.txt"
    {"rieulphieuphkorean","313F"},
#line 1586 "pdfdoc/glyphlist.txt"
    {"ddotbelow","1E0D"},
#line 72 "pdfdoc/glyphlist.txt"
    {"Bdotbelow","1E04"},
#line 122 "pdfdoc/glyphlist.txt"
    {"Ddotbelow","1E0C"},
#line 367 "pdfdoc/glyphlist.txt"
    {"Ldotbelow","1E36"},
#line 505 "pdfdoc/glyphlist.txt"
    {"Rdotbelow","1E5A"},
#line 399 "pdfdoc/glyphlist.txt"
    {"Ndotbelow","1E46"},
#line 384 "pdfdoc/glyphlist.txt"
    {"Mdotbelow","1E42"},
#line 2975 "pdfdoc/glyphlist.txt"
    {"ovowelsigndeva","094B"},
#line 2161 "pdfdoc/glyphlist.txt"
    {"horizontalbar","2015"},
#line 1676 "pdfdoc/glyphlist.txt"
    {"ecandravowelsigndeva","0945"},
#line 2693 "pdfdoc/glyphlist.txt"
    {"musicalnotedbl","266B"},
#line 1677 "pdfdoc/glyphlist.txt"
    {"ecandravowelsigngujarati","0AC5"},
#line 3503 "pdfdoc/glyphlist.txt"
    {"sheeninitialarabic","FEB7"},
#line 293 "pdfdoc/glyphlist.txt"
    {"Idotbelow","1ECA"},
#line 3696 "pdfdoc/glyphlist.txt"
    {"tehhahinitialarabic","FCA2"},
#line 3837 "pdfdoc/glyphlist.txt"
    {"tparen","24AF"},
#line 713 "pdfdoc/glyphlist.txt"
    {"Ydotbelow","1EF4"},
#line 2609 "pdfdoc/glyphlist.txt"
    {"mbopomofo","3107"},
#line 3285 "pdfdoc/glyphlist.txt"
    {"reshsegolhebrew","05E8 05B6"},
#line 266 "pdfdoc/glyphlist.txt"
    {"Hdotbelow","1E24"},
#line 3913 "pdfdoc/glyphlist.txt"
    {"twothai","0E52"},
#line 3154 "pdfdoc/glyphlist.txt"
    {"qamatshebrew","05B8"},
#line 1696 "pdfdoc/glyphlist.txt"
    {"edotbelow","1EB9"},
#line 3335 "pdfdoc/glyphlist.txt"
    {"ringhalfrightbelowcmb","0339"},
#line 3317 "pdfdoc/glyphlist.txt"
    {"rieulsioskorean","313D"},
#line 3716 "pdfdoc/glyphlist.txt"
    {"tenparen","247D"},
#line 1493 "pdfdoc/glyphlist.txt"
    {"curlyor","22CE"},
#line 3993 "pdfdoc/glyphlist.txt"
    {"uugurmukhi","0A0A"},
#line 2414 "pdfdoc/glyphlist.txt"
    {"khhagurmukhi","0A59"},
#line 2008 "pdfdoc/glyphlist.txt"
    {"gravedeva","0953"},
#line 2058 "pdfdoc/glyphlist.txt"
    {"harpoonleftbarbup","21BC"},
#line 2376 "pdfdoc/glyphlist.txt"
    {"kapyeounphieuphkorean","3184"},
#line 2808 "pdfdoc/glyphlist.txt"
    {"notelementof","2209"},
#line 4251 "pdfdoc/glyphlist.txt"
    {"zbopomofo","3117"},
#line 2075 "pdfdoc/glyphlist.txt"
    {"hatafqamatsquarterhebrew","05B3"},
#line 4026 "pdfdoc/glyphlist.txt"
    {"verticallinebelowcmb","0329"},
#line 2723 "pdfdoc/glyphlist.txt"
    {"ndotbelow","1E47"},
#line 3836 "pdfdoc/glyphlist.txt"
    {"tpalatalhook","01AB"},
#line 2375 "pdfdoc/glyphlist.txt"
    {"kapyeounmieumkorean","3171"},
#line 744 "pdfdoc/glyphlist.txt"
    {"Zhebrevecyrillic","04C1"},
#line 2355 "pdfdoc/glyphlist.txt"
    {"kacyrillic","043A"},
#line 1712 "pdfdoc/glyphlist.txt"
    {"eightdeva","096E"},
#line 3277 "pdfdoc/glyphlist.txt"
    {"reshholamhebrew","05E8 05B9"},
#line 1395 "pdfdoc/glyphlist.txt"
    {"cieuckorean","3148"},
#line 2378 "pdfdoc/glyphlist.txt"
    {"kapyeounssangpieupkorean","3179"},
#line 3323 "pdfdoc/glyphlist.txt"
    {"righttriangle","22BF"},
#line 3233 "pdfdoc/glyphlist.txt"
    {"radsquare","33AD"},
#line 3449 "pdfdoc/glyphlist.txt"
    {"semicolonarabic","061B"},
#line 3652 "pdfdoc/glyphlist.txt"
    {"svsquare","33DC"},
#line 1400 "pdfdoc/glyphlist.txt"
    {"circleot","2299"},
#line 2857 "pdfdoc/glyphlist.txt"
    {"obopomofo","311B"},
#line 2248 "pdfdoc/glyphlist.txt"
    {"idotbelow","1ECB"},
#line 2334 "pdfdoc/glyphlist.txt"
    {"jdotlessstroke","025F"},
#line 2431 "pdfdoc/glyphlist.txt"
    {"kiroguramusquare","3315"},
#line 342 "pdfdoc/glyphlist.txt"
    {"Kdotbelow","1E32"},
#line 1432 "pdfdoc/glyphlist.txt"
    {"commaarmenian","055D"},
#line 3646 "pdfdoc/glyphlist.txt"
    {"sukunarabic","0652"},
#line 3970 "pdfdoc/glyphlist.txt"
    {"upblock","2580"},
#line 3933 "pdfdoc/glyphlist.txt"
    {"udieresiscaron","01DA"},
#line 3934 "pdfdoc/glyphlist.txt"
    {"udieresiscyrillic","04F1"},
#line 3936 "pdfdoc/glyphlist.txt"
    {"udieresismacron","01D6"},
#line 3269 "pdfdoc/glyphlist.txt"
    {"reshhatafpatah","05E8 05B2"},
#line 2670 "pdfdoc/glyphlist.txt"
    {"moverssquaredsquare","33A8"},
#line 2047 "pdfdoc/glyphlist.txt"
    {"hamzaarabic","0621"},
#line 4095 "pdfdoc/glyphlist.txt"
    {"whitesmallsquare","25AB"},
#line 3931 "pdfdoc/glyphlist.txt"
    {"udieresisacute","01D8"},
#line 3907 "pdfdoc/glyphlist.txt"
    {"twoparen","2475"},
#line 3541 "pdfdoc/glyphlist.txt"
    {"siluqlefthebrew","05BD"},
#line 3930 "pdfdoc/glyphlist.txt"
    {"udieresis","00FC"},
#line 3901 "pdfdoc/glyphlist.txt"
    {"twohangzhou","3022"},
#line 2514 "pdfdoc/glyphlist.txt"
    {"ldotbelowmacron","1E39"},
#line 2093 "pdfdoc/glyphlist.txt"
    {"hdotbelow","1E25"},
#line 3787 "pdfdoc/glyphlist.txt"
    {"threesuperior","00B3"},
#line 3268 "pdfdoc/glyphlist.txt"
    {"reshdageshhebrew","FB48"},
#line 435 "pdfdoc/glyphlist.txt"
    {"Odotbelow","1ECC"},
#line 1371 "pdfdoc/glyphlist.txt"
    {"chbopomofo","3114"},
#line 3736 "pdfdoc/glyphlist.txt"
    {"thanthakhatupperleftthai","F896"},
#line 2383 "pdfdoc/glyphlist.txt"
    {"kasquare","3384"},
#line 2029 "pdfdoc/glyphlist.txt"
    {"gysquare","33C9"},
#line 2541 "pdfdoc/glyphlist.txt"
    {"lmiddletilde","026B"},
#line 3705 "pdfdoc/glyphlist.txt"
    {"tehmeeminitialarabic","FCA4"},
#line 4135 "pdfdoc/glyphlist.txt"
    {"yaekorean","3152"},
#line 4216 "pdfdoc/glyphlist.txt"
    {"yuikorean","318C"},
#line 4169 "pdfdoc/glyphlist.txt"
    {"yeokorean","3155"},
#line 4195 "pdfdoc/glyphlist.txt"
    {"yoikorean","3189"},
#line 3706 "pdfdoc/glyphlist.txt"
    {"tehmeemisolatedarabic","FC0E"},
#line 31 "pdfdoc/glyphlist.txt"
    {"Abrevetilde","1EB4"},
#line 1494 "pdfdoc/glyphlist.txt"
    {"currency","00A4"},
#line 2458 "pdfdoc/glyphlist.txt"
    {"ktsquare","33CF"},
#line 1221 "pdfdoc/glyphlist.txt"
    {"barmonospace","FF5C"},
#line 4146 "pdfdoc/glyphlist.txt"
    {"yatcyrillic","0463"},
#line 3581 "pdfdoc/glyphlist.txt"
    {"slongdotaccent","1E9B"},
#line 2445 "pdfdoc/glyphlist.txt"
    {"kmsquaredsquare","33A2"},
#line 2813 "pdfdoc/glyphlist.txt"
    {"notidentical","2262"},
#line 3271 "pdfdoc/glyphlist.txt"
    {"reshhatafsegol","05E8 05B1"},
#line 1487 "pdfdoc/glyphlist.txt"
    {"cosquare","33C7"},
#line 1323 "pdfdoc/glyphlist.txt"
    {"btopbar","0183"},
#line 2893 "pdfdoc/glyphlist.txt"
    {"ohungarumlaut","0151"},
#line 786 "pdfdoc/glyphlist.txt"
    {"acutedeva","0954"},
#line 1303 "pdfdoc/glyphlist.txt"
    {"bracketleftbt","F8F0"},
#line 3102 "pdfdoc/glyphlist.txt"
    {"plusminus","00B1"},
#line 2841 "pdfdoc/glyphlist.txt"
    {"nundagesh","FB40"},
#line 3270 "pdfdoc/glyphlist.txt"
    {"reshhatafpatahhebrew","05E8 05B2"},
#line 3684 "pdfdoc/glyphlist.txt"
    {"tchehmedialarabic","FB7D"},
#line 2513 "pdfdoc/glyphlist.txt"
    {"ldotbelow","1E37"},
#line 3272 "pdfdoc/glyphlist.txt"
    {"reshhatafsegolhebrew","05E8 05B1"},
#line 3088 "pdfdoc/glyphlist.txt"
    {"pieupkorean","3142"},
#line 1418 "pdfdoc/glyphlist.txt"
    {"cmsquaredsquare","33A0"},
#line 2442 "pdfdoc/glyphlist.txt"
    {"klsquare","3398"},
#line 3592 "pdfdoc/glyphlist.txt"
    {"sorusithai","0E29"},
#line 3753 "pdfdoc/glyphlist.txt"
    {"thirteenperiod","2494"},
#line 4069 "pdfdoc/glyphlist.txt"
    {"wdieresis","1E85"},
#line 3636 "pdfdoc/glyphlist.txt"
    {"strokelongoverlaycmb","0336"},
#line 3772 "pdfdoc/glyphlist.txt"
    {"threegujarati","0AE9"},
#line 1848 "pdfdoc/glyphlist.txt"
    {"fifteenperiod","2496"},
#line 3090 "pdfdoc/glyphlist.txt"
    {"pieupsioskiyeokkorean","3174"},
#line 3316 "pdfdoc/glyphlist.txt"
    {"rieulpieupsioskorean","316B"},
#line 3935 "pdfdoc/glyphlist.txt"
    {"udieresisgrave","01DC"},
#line 2464 "pdfdoc/glyphlist.txt"
    {"kwsquare","33BE"},
#line 4133 "pdfdoc/glyphlist.txt"
    {"yacute","00FD"},
#line 3315 "pdfdoc/glyphlist.txt"
    {"rieulpieupkorean","313C"},
#line 3857 "pdfdoc/glyphlist.txt"
    {"tserenarrowhebrew","05B5"},
#line 3932 "pdfdoc/glyphlist.txt"
    {"udieresisbelow","1E73"},
#line 3702 "pdfdoc/glyphlist.txt"
    {"tehmarbutaarabic","0629"},
#line 27 "pdfdoc/glyphlist.txt"
    {"Abrevecyrillic","04D0"},
#line 2831 "pdfdoc/glyphlist.txt"
    {"nuktadeva","093C"},
#line 2908 "pdfdoc/glyphlist.txt"
    {"omegaroundcyrillic","047B"},
#line 3703 "pdfdoc/glyphlist.txt"
    {"tehmarbutafinalarabic","FE94"},
#line 3303 "pdfdoc/glyphlist.txt"
    {"rhotichookmod","02DE"},
#line 3242 "pdfdoc/glyphlist.txt"
    {"ramiddlediagonalbengali","09F0"},
#line 4181 "pdfdoc/glyphlist.txt"
    {"yhookabove","1EF7"},
#line 2520 "pdfdoc/glyphlist.txt"
    {"lessmonospace","FF1C"},
#line 3797 "pdfdoc/glyphlist.txt"
    {"tikeutparenkorean","3202"},
#line 3813 "pdfdoc/glyphlist.txt"
    {"tmonospace","FF54"},
#line 2011 "pdfdoc/glyphlist.txt"
    {"gravetonecmb","0340"},
#line 3177 "pdfdoc/glyphlist.txt"
    {"qofholam","05E7 05B9"},
#line 1363 "pdfdoc/glyphlist.txt"
    {"centmonospace","FFE0"},
#line 2516 "pdfdoc/glyphlist.txt"
    {"lefttackbelowcmb","0318"},
#line 3963 "pdfdoc/glyphlist.txt"
    {"underscoremonospace","FF3F"},
#line 667 "pdfdoc/glyphlist.txt"
    {"Upsilontonos","038E"},
#line 2463 "pdfdoc/glyphlist.txt"
    {"kvsquare","33B8"},
#line 2413 "pdfdoc/glyphlist.txt"
    {"khhadeva","0959"},
#line 2967 "pdfdoc/glyphlist.txt"
    {"overline","203E"},
#line 678 "pdfdoc/glyphlist.txt"
    {"Vdotbelow","1E7E"},
#line 592 "pdfdoc/glyphlist.txt"
    {"Tcedilla","0162"},
#line 1773 "pdfdoc/glyphlist.txt"
    {"epsilontonos","03AD"},
#line 3924 "pdfdoc/glyphlist.txt"
    {"ucircumflexbelow","1E77"},
#line 3768 "pdfdoc/glyphlist.txt"
    {"threecircle","2462"},
#line 2642 "pdfdoc/glyphlist.txt"
    {"mieumkorean","3141"},
#line 3049 "pdfdoc/glyphlist.txt"
    {"percentmonospace","FF05"},
#line 1313 "pdfdoc/glyphlist.txt"
    {"brevebelowcmb","032E"},
#line 1142 "pdfdoc/glyphlist.txt"
    {"arrowdown","2193"},
#line 4269 "pdfdoc/glyphlist.txt"
    {"zerogurmukhi","0A66"},
#line 2968 "pdfdoc/glyphlist.txt"
    {"overlinecenterline","FE4A"},
#line 4060 "pdfdoc/glyphlist.txt"
    {"wavedash","301C"},
#line 3566 "pdfdoc/glyphlist.txt"
    {"sixmonospace","FF16"},
#line 49 "pdfdoc/glyphlist.txt"
    {"Adotbelow","1EA0"},
#line 2032 "pdfdoc/glyphlist.txt"
    {"haaltonearabic","06C1"},
#line 4272 "pdfdoc/glyphlist.txt"
    {"zeromonospace","FF10"},
#line 3543 "pdfdoc/glyphlist.txt"
    {"sindothebrew","05C2"},
#line 3178 "pdfdoc/glyphlist.txt"
    {"qofholamhebrew","05E7 05B9"},
#line 1145 "pdfdoc/glyphlist.txt"
    {"arrowdownwhite","21E9"},
#line 1421 "pdfdoc/glyphlist.txt"
    {"colonmonetary","20A1"},
#line 3079 "pdfdoc/glyphlist.txt"
    {"phophanthai","0E1E"},
#line 2009 "pdfdoc/glyphlist.txt"
    {"gravelowmod","02CE"},
#line 4091 "pdfdoc/glyphlist.txt"
    {"whitelenticularbracketleft","3016"},
#line 4092 "pdfdoc/glyphlist.txt"
    {"whitelenticularbracketright","3017"},
#line 3302 "pdfdoc/glyphlist.txt"
    {"rhosymbolgreek","03F1"},
#line 4078 "pdfdoc/glyphlist.txt"
    {"whitebullet","25E6"},
#line 3039 "pdfdoc/glyphlist.txt"
    {"pehebrew","05E4"},
#line 1439 "pdfdoc/glyphlist.txt"
    {"commaturnedabovecmb","0312"},
#line 3338 "pdfdoc/glyphlist.txt"
    {"rittorusquare","3351"},
#line 1144 "pdfdoc/glyphlist.txt"
    {"arrowdownright","2198"},
#line 4259 "pdfdoc/glyphlist.txt"
    {"zecyrillic","0437"},
#line 150 "pdfdoc/glyphlist.txt"
    {"Ecedillabreve","1E1C"},
#line 3806 "pdfdoc/glyphlist.txt"
    {"timescircle","2297"},
#line 1087 "pdfdoc/glyphlist.txt"
    {"alefpatahhebrew","FB2E"},
#line 1681 "pdfdoc/glyphlist.txt"
    {"echyiwnarmenian","0587"},
#line 1111 "pdfdoc/glyphlist.txt"
    {"anudattadeva","0952"},
#line 192 "pdfdoc/glyphlist.txt"
    {"Ercyrillic","0420"},
#line 2818 "pdfdoc/glyphlist.txt"
    {"notsubset","2284"},
#line 3925 "pdfdoc/glyphlist.txt"
    {"ucyrillic","0443"},
#line 183 "pdfdoc/glyphlist.txt"
    {"Encyrillic","041D"},
#line 3953 "pdfdoc/glyphlist.txt"
    {"ukatakanahalfwidth","FF73"},
#line 4132 "pdfdoc/glyphlist.txt"
    {"yabengali","09AF"},
#line 4281 "pdfdoc/glyphlist.txt"
    {"zhbopomofo","3113"},
#line 2962 "pdfdoc/glyphlist.txt"
    {"otcyrillic","047F"},
#line 3420 "pdfdoc/glyphlist.txt"
    {"schwahook","025A"},
#line 181 "pdfdoc/glyphlist.txt"
    {"Emcyrillic","041C"},
#line 788 "pdfdoc/glyphlist.txt"
    {"acutetonecmb","0341"},
#line 3281 "pdfdoc/glyphlist.txt"
    {"reshqamatshebrew","05E8 05B8"},
#line 3754 "pdfdoc/glyphlist.txt"
    {"thonangmonthothai","0E11"},
#line 3939 "pdfdoc/glyphlist.txt"
    {"ugujarati","0A89"},
#line 195 "pdfdoc/glyphlist.txt"
    {"Escyrillic","0421"},
#line 2608 "pdfdoc/glyphlist.txt"
    {"masquare","3383"},
#line 2966 "pdfdoc/glyphlist.txt"
    {"oubopomofo","3121"},
#line 4143 "pdfdoc/glyphlist.txt"
    {"yasmallhiragana","3083"},
#line 2637 "pdfdoc/glyphlist.txt"
    {"middledotkatakanahalfwidth","FF65"},
#line 4224 "pdfdoc/glyphlist.txt"
    {"yusmallhiragana","3085"},
#line 3882 "pdfdoc/glyphlist.txt"
    {"twelveparen","247F"},
#line 4199 "pdfdoc/glyphlist.txt"
    {"yosmallhiragana","3087"},
#line 2654 "pdfdoc/glyphlist.txt"
    {"minusplus","2213"},
#line 1757 "pdfdoc/glyphlist.txt"
    {"endashvertical","FE32"},
#line 4155 "pdfdoc/glyphlist.txt"
    {"yehfinalarabic","FEF2"},
#line 3615 "pdfdoc/glyphlist.txt"
    {"squaremsquared","33A1"},
#line 3788 "pdfdoc/glyphlist.txt"
    {"threethai","0E53"},
#line 1132 "pdfdoc/glyphlist.txt"
    {"arrowboth","2194"},
#line 2662 "pdfdoc/glyphlist.txt"
    {"mmsquaredsquare","339F"},
#line 2673 "pdfdoc/glyphlist.txt"
    {"mssquare","33B3"},
#line 2941 "pdfdoc/glyphlist.txt"
    {"onethird","2153"},
#line 176 "pdfdoc/glyphlist.txt"
    {"Elcyrillic","041B"},
#line 617 "pdfdoc/glyphlist.txt"
    {"Tshecyrillic","040B"},
#line 1750 "pdfdoc/glyphlist.txt"
    {"emdashvertical","FE31"},
#line 1464 "pdfdoc/glyphlist.txt"
    {"controlGS","001D"},
#line 1225 "pdfdoc/glyphlist.txt"
    {"bdotbelow","1E05"},
#line 3747 "pdfdoc/glyphlist.txt"
    {"thieuthaparenkorean","3219"},
#line 3835 "pdfdoc/glyphlist.txt"
    {"totaothai","0E15"},
#line 4266 "pdfdoc/glyphlist.txt"
    {"zerobengali","09E6"},
#line 598 "pdfdoc/glyphlist.txt"
    {"Tecyrillic","0422"},
#line 1318 "pdfdoc/glyphlist.txt"
    {"bridgebelowcmb","032A"},
#line 1428 "pdfdoc/glyphlist.txt"
    {"commaabovecmb","0313"},
#line 1357 "pdfdoc/glyphlist.txt"
    {"cdsquare","33C5"},
#line 2933 "pdfdoc/glyphlist.txt"
    {"oneoldstyle","F731"},
#line 3193 "pdfdoc/glyphlist.txt"
    {"qubuts","05BB"},
#line 2659 "pdfdoc/glyphlist.txt"
    {"mlsquare","3396"},
#line 4144 "pdfdoc/glyphlist.txt"
    {"yasmallkatakana","30E3"},
#line 4225 "pdfdoc/glyphlist.txt"
    {"yusmallkatakana","30E5"},
#line 2018 "pdfdoc/glyphlist.txt"
    {"greateroverequal","2267"},
#line 4200 "pdfdoc/glyphlist.txt"
    {"yosmallkatakana","30E7"},
#line 3283 "pdfdoc/glyphlist.txt"
    {"reshqubutshebrew","05E8 05BB"},
#line 4145 "pdfdoc/glyphlist.txt"
    {"yasmallkatakanahalfwidth","FF6C"},
#line 4226 "pdfdoc/glyphlist.txt"
    {"yusmallkatakanahalfwidth","FF6D"},
#line 4201 "pdfdoc/glyphlist.txt"
    {"yosmallkatakanahalfwidth","FF6E"},
#line 787 "pdfdoc/glyphlist.txt"
    {"acutelowmod","02CF"},
#line 772 "pdfdoc/glyphlist.txt"
    {"abrevehookabove","1EB3"},
#line 2377 "pdfdoc/glyphlist.txt"
    {"kapyeounpieupkorean","3178"},
#line 3748 "pdfdoc/glyphlist.txt"
    {"thieuthcirclekorean","326B"},
#line 3195 "pdfdoc/glyphlist.txt"
    {"qubuts25","05BB"},
#line 3955 "pdfdoc/glyphlist.txt"
    {"ukorean","315C"},
#line 3429 "pdfdoc/glyphlist.txt"
    {"secondtonechinese","02CA"},
#line 2702 "pdfdoc/glyphlist.txt"
    {"mwsquare","33BD"},
#line 3750 "pdfdoc/glyphlist.txt"
    {"thieuthparenkorean","320B"},
#line 3155 "pdfdoc/glyphlist.txt"
    {"qamatsnarrowhebrew","05B8"},
#line 3956 "pdfdoc/glyphlist.txt"
    {"umacron","016B"},
#line 4150 "pdfdoc/glyphlist.txt"
    {"ydotaccent","1E8F"},
#line 3749 "pdfdoc/glyphlist.txt"
    {"thieuthkorean","314C"},
#line 3746 "pdfdoc/glyphlist.txt"
    {"thieuthacirclekorean","3279"},
#line 3245 "pdfdoc/glyphlist.txt"
    {"rbopomofo","3116"},
#line 4096 "pdfdoc/glyphlist.txt"
    {"whitesmilingface","263A"},
#line 1770 "pdfdoc/glyphlist.txt"
    {"eopenreversedhook","025D"},
#line 3885 "pdfdoc/glyphlist.txt"
    {"twentycircle","2473"},
#line 1492 "pdfdoc/glyphlist.txt"
    {"curlyand","22CF"},
#line 147 "pdfdoc/glyphlist.txt"
    {"Eacutesmall","F7E9"},
#line 1388 "pdfdoc/glyphlist.txt"
    {"chochanthai","0E08"},
#line 2043 "pdfdoc/glyphlist.txt"
    {"haitusquare","332A"},
#line 1699 "pdfdoc/glyphlist.txt"
    {"efcyrillic","0444"},
#line 3278 "pdfdoc/glyphlist.txt"
    {"reshpatah","05E8 05B7"},
#line 2653 "pdfdoc/glyphlist.txt"
    {"minusmod","02D7"},
#line 4261 "pdfdoc/glyphlist.txt"
    {"zedieresiscyrillic","04DF"},
#line 2681 "pdfdoc/glyphlist.txt"
    {"mufsquare","338C"},
#line 2700 "pdfdoc/glyphlist.txt"
    {"mvsquare","33B7"},
#line 2364 "pdfdoc/glyphlist.txt"
    {"kafinitialarabic","FEDB"},
#line 1568 "pdfdoc/glyphlist.txt"
    {"dbsquare","33C8"},
#line 2051 "pdfdoc/glyphlist.txt"
    {"hamzafathatanarabic","0621 064B"},
#line 2050 "pdfdoc/glyphlist.txt"
    {"hamzafathaarabic","0621 064E"},
#line 4267 "pdfdoc/glyphlist.txt"
    {"zerodeva","0966"},
#line 3700 "pdfdoc/glyphlist.txt"
    {"tehjeeminitialarabic","FCA1"},
#line 3426 "pdfdoc/glyphlist.txt"
    {"sdotbelowdotaccent","1E69"},
#line 1266 "pdfdoc/glyphlist.txt"
    {"blacklowerrighttriangle","25E2"},
#line 3701 "pdfdoc/glyphlist.txt"
    {"tehjeemisolatedarabic","FC0B"},
#line 4212 "pdfdoc/glyphlist.txt"
    {"ysuperior","02B8"},
#line 3781 "pdfdoc/glyphlist.txt"
    {"threeparen","2476"},
#line 1580 "pdfdoc/glyphlist.txt"
    {"dddhadeva","095C"},
#line 1554 "pdfdoc/glyphlist.txt"
    {"dblarchinvertedbelowcmb","032B"},
#line 2843 "pdfdoc/glyphlist.txt"
    {"nunhebrew","05E0"},
#line 2970 "pdfdoc/glyphlist.txt"
    {"overlinedashed","FE49"},
#line 1242 "pdfdoc/glyphlist.txt"
    {"betdagesh","FB31"},
#line 3758 "pdfdoc/glyphlist.txt"
    {"thothahanthai","0E17"},
#line 3167 "pdfdoc/glyphlist.txt"
    {"qof","05E7"},
#line 3531 "pdfdoc/glyphlist.txt"
    {"shinsindothebrew","FB2B"},
#line 1819 "pdfdoc/glyphlist.txt"
    {"existential","2203"},
#line 3773 "pdfdoc/glyphlist.txt"
    {"threegurmukhi","0A69"},
#line 3425 "pdfdoc/glyphlist.txt"
    {"sdotbelow","1E63"},
#line 3851 "pdfdoc/glyphlist.txt"
    {"tsecyrillic","0446"},
#line 1788 "pdfdoc/glyphlist.txt"
    {"eshortvowelsigndeva","0946"},
#line 1286 "pdfdoc/glyphlist.txt"
    {"bqsquare","33C3"},
#line 3957 "pdfdoc/glyphlist.txt"
    {"umacroncyrillic","04EF"},
#line 2337 "pdfdoc/glyphlist.txt"
    {"jeemfinalarabic","FE9E"},
#line 3104 "pdfdoc/glyphlist.txt"
    {"plusmonospace","FF0B"},
#line 2728 "pdfdoc/glyphlist.txt"
    {"nfsquare","338B"},
#line 4186 "pdfdoc/glyphlist.txt"
    {"yiwnarmenian","0582"},
#line 2019 "pdfdoc/glyphlist.txt"
    {"greatersmall","FE65"},
#line 1811 "pdfdoc/glyphlist.txt"
    {"evowelsigngujarati","0AC7"},
#line 4278 "pdfdoc/glyphlist.txt"
    {"zerowidthnonjoiner","200C"},
#line 174 "pdfdoc/glyphlist.txt"
    {"Einvertedbreve","0206"},
#line 3247 "pdfdoc/glyphlist.txt"
    {"rcedilla","0157"},
#line 3745 "pdfdoc/glyphlist.txt"
    {"thetasymbolgreek","03D1"},
#line 3143 "pdfdoc/glyphlist.txt"
    {"qaffinalarabic","FED6"},
#line 2895 "pdfdoc/glyphlist.txt"
    {"oinvertedbreve","020F"},
#line 4017 "pdfdoc/glyphlist.txt"
    {"vecyrillic","0432"},
#line 3549 "pdfdoc/glyphlist.txt"
    {"sioskorean","3145"},
#line 3059 "pdfdoc/glyphlist.txt"
    {"perispomenigreekcmb","0342"},
#line 3845 "pdfdoc/glyphlist.txt"
    {"triagup","25B2"},
#line 1345 "pdfdoc/glyphlist.txt"
    {"caronbelowcmb","032C"},
#line 2872 "pdfdoc/glyphlist.txt"
    {"odblacute","0151"},
#line 3685 "pdfdoc/glyphlist.txt"
    {"tchehmeeminitialarabic","FB7C FEE4"},
#line 2120 "pdfdoc/glyphlist.txt"
    {"hethebrew","05D7"},
#line 2795 "pdfdoc/glyphlist.txt"
    {"noonfinalarabic","FEE6"},
#line 760 "pdfdoc/glyphlist.txt"
    {"aavowelsignbengali","09BE"},
#line 1548 "pdfdoc/glyphlist.txt"
    {"dasiapneumatacyrilliccmb","0485"},
#line 1202 "pdfdoc/glyphlist.txt"
    {"auvowelsignbengali","09CC"},
#line 1065 "pdfdoc/glyphlist.txt"
    {"aivowelsignbengali","09C8"},
#line 3192 "pdfdoc/glyphlist.txt"
    {"quarternote","2669"},
#line 3171 "pdfdoc/glyphlist.txt"
    {"qofhatafpatahhebrew","05E7 05B2"},
#line 3161 "pdfdoc/glyphlist.txt"
    {"qamatswidehebrew","05B8"},
#line 1479 "pdfdoc/glyphlist.txt"
    {"copyrightserif","F6D9"},
#line 2320 "pdfdoc/glyphlist.txt"
    {"ivowelsigngujarati","0ABF"},
#line 2453 "pdfdoc/glyphlist.txt"
    {"koreanstandardsymbol","327F"},
#line 2680 "pdfdoc/glyphlist.txt"
    {"muchless","226A"},
#line 3201 "pdfdoc/glyphlist.txt"
    {"question","003F"},
#line 3194 "pdfdoc/glyphlist.txt"
    {"qubuts18","05BB"},
#line 3204 "pdfdoc/glyphlist.txt"
    {"questiondown","00BF"},
#line 3036 "pdfdoc/glyphlist.txt"
    {"pefinaldageshhebrew","FB43"},
#line 177 "pdfdoc/glyphlist.txt"
    {"Elevenroman","216A"},
#line 3783 "pdfdoc/glyphlist.txt"
    {"threepersian","06F3"},
#line 1308 "pdfdoc/glyphlist.txt"
    {"bracketrightbt","F8FB"},
#line 1272 "pdfdoc/glyphlist.txt"
    {"blacksquare","25A0"},
#line 3355 "pdfdoc/glyphlist.txt"
    {"rrvocalicgujarati","0AE0"},
#line 3203 "pdfdoc/glyphlist.txt"
    {"questionarmenian","055E"},
#line 3206 "pdfdoc/glyphlist.txt"
    {"questiongreek","037E"},
#line 1074 "pdfdoc/glyphlist.txt"
    {"aleffinalarabic","FE8E"},
#line 3872 "pdfdoc/glyphlist.txt"
    {"tthagujarati","0AA0"},
#line 3730 "pdfdoc/glyphlist.txt"
    {"thagurmukhi","0A25"},
#line 2889 "pdfdoc/glyphlist.txt"
    {"ohorndotbelow","1EE3"},
#line 3207 "pdfdoc/glyphlist.txt"
    {"questionmonospace","FF1F"},
#line 3461 "pdfdoc/glyphlist.txt"
    {"sevendeva","096D"},
#line 3918 "pdfdoc/glyphlist.txt"
    {"ubengali","0989"},
#line 3865 "pdfdoc/glyphlist.txt"
    {"ttagurmukhi","0A1F"},
#line 3173 "pdfdoc/glyphlist.txt"
    {"qofhatafsegolhebrew","05E7 05B1"},
#line 3796 "pdfdoc/glyphlist.txt"
    {"tikeutkorean","3137"},
#line 3965 "pdfdoc/glyphlist.txt"
    {"underscorewavy","FE4F"},
#line 2269 "pdfdoc/glyphlist.txt"
    {"iivowelsignbengali","09C0"},
#line 3320 "pdfdoc/glyphlist.txt"
    {"rieulyeorinhieuhkorean","316D"},
#line 3087 "pdfdoc/glyphlist.txt"
    {"pieupkiyeokkorean","3172"},
#line 2592 "pdfdoc/glyphlist.txt"
    {"maitholowleftthai","F88F"},
#line 3676 "pdfdoc/glyphlist.txt"
    {"tbar","0167"},
#line 1258 "pdfdoc/glyphlist.txt"
    {"blackdownpointingtriangle","25BC"},
#line 2596 "pdfdoc/glyphlist.txt"
    {"maitrilowleftthai","F892"},
#line 3679 "pdfdoc/glyphlist.txt"
    {"tccurl","02A8"},
#line 3978 "pdfdoc/glyphlist.txt"
    {"uptackmod","02D4"},
#line 1768 "pdfdoc/glyphlist.txt"
    {"eopenreversed","025C"},
#line 3176 "pdfdoc/glyphlist.txt"
    {"qofhiriqhebrew","05E7 05B4"},
#line 3946 "pdfdoc/glyphlist.txt"
    {"uhorngrave","1EEB"},
#line 1769 "pdfdoc/glyphlist.txt"
    {"eopenreversedclosed","025E"},
#line 4171 "pdfdoc/glyphlist.txt"
    {"yerahbenyomohebrew","05AA"},
#line 3774 "pdfdoc/glyphlist.txt"
    {"threehackarabic","0663"},
#line 4137 "pdfdoc/glyphlist.txt"
    {"yagurmukhi","0A2F"},
#line 30 "pdfdoc/glyphlist.txt"
    {"Abrevehookabove","1EB2"},
#line 2395 "pdfdoc/glyphlist.txt"
    {"kdotbelow","1E33"},
#line 3259 "pdfdoc/glyphlist.txt"
    {"registerserif","F6DA"},
#line 3899 "pdfdoc/glyphlist.txt"
    {"twogurmukhi","0A68"},
#line 3274 "pdfdoc/glyphlist.txt"
    {"reshhiriq","05E8 05B4"},
#line 3480 "pdfdoc/glyphlist.txt"
    {"sfthyphen","00AD"},
#line 3655 "pdfdoc/glyphlist.txt"
    {"tabengali","09A4"},
#line 2923 "pdfdoc/glyphlist.txt"
    {"onefitted","F6DC"},
#line 2065 "pdfdoc/glyphlist.txt"
    {"hatafpatahhebrew","05B2"},
#line 4205 "pdfdoc/glyphlist.txt"
    {"yoyakthai","0E22"},
#line 4100 "pdfdoc/glyphlist.txt"
    {"whitetortoiseshellbracketleft","3018"},
#line 4101 "pdfdoc/glyphlist.txt"
    {"whitetortoiseshellbracketright","3019"},
#line 3310 "pdfdoc/glyphlist.txt"
    {"rieulkorean","3139"},
#line 3855 "pdfdoc/glyphlist.txt"
    {"tsere2b","05B5"},
#line 2931 "pdfdoc/glyphlist.txt"
    {"onemonospace","FF11"},
#line 3878 "pdfdoc/glyphlist.txt"
    {"tusmallhiragana","3063"},
#line 1612 "pdfdoc/glyphlist.txt"
    {"dieresisbelowcmb","0324"},
#line 3196 "pdfdoc/glyphlist.txt"
    {"qubuts31","05BB"},
#line 3662 "pdfdoc/glyphlist.txt"
    {"tahfinalarabic","FEC2"},
#line 3695 "pdfdoc/glyphlist.txt"
    {"tehfinalarabic","FE96"},
#line 2600 "pdfdoc/glyphlist.txt"
    {"maiyamokthai","0E46"},
#line 3122 "pdfdoc/glyphlist.txt"
    {"primereversed","2035"},
#line 3205 "pdfdoc/glyphlist.txt"
    {"questiondownsmall","F7BF"},
#line 4172 "pdfdoc/glyphlist.txt"
    {"yerahbenyomolefthebrew","05AA"},
#line 4149 "pdfdoc/glyphlist.txt"
    {"ydieresis","00FF"},
#line 3255 "pdfdoc/glyphlist.txt"
    {"reflexsubset","2286"},
#line 3779 "pdfdoc/glyphlist.txt"
    {"threenumeratorbengali","09F6"},
#line 3123 "pdfdoc/glyphlist.txt"
    {"product","220F"},
#line 4161 "pdfdoc/glyphlist.txt"
    {"yehmedialarabic","FEF4"},
#line 3640 "pdfdoc/glyphlist.txt"
    {"subsetorequal","2286"},
#line 3208 "pdfdoc/glyphlist.txt"
    {"questionsmall","F73F"},
#line 3776 "pdfdoc/glyphlist.txt"
    {"threeideographicparen","3222"},
#line 619 "pdfdoc/glyphlist.txt"
    {"Twelveroman","216B"},
#line 2913 "pdfdoc/glyphlist.txt"
    {"omicrontonos","03CC"},
#line 3256 "pdfdoc/glyphlist.txt"
    {"reflexsuperset","2287"},
#line 1579 "pdfdoc/glyphlist.txt"
    {"ddalfinalarabic","FB89"},
#line 3879 "pdfdoc/glyphlist.txt"
    {"tusmallkatakana","30C3"},
#line 2979 "pdfdoc/glyphlist.txt"
    {"paasentosquare","332B"},
#line 3880 "pdfdoc/glyphlist.txt"
    {"tusmallkatakanahalfwidth","FF6F"},
#line 3690 "pdfdoc/glyphlist.txt"
    {"tdotaccent","1E6B"},
#line 1917 "pdfdoc/glyphlist.txt"
    {"fourpersian","06F4"},
#line 3724 "pdfdoc/glyphlist.txt"
    {"tetsecyrillic","04B5"},
#line 1562 "pdfdoc/glyphlist.txt"
    {"dbllowlinecmb","0333"},
#line 3162 "pdfdoc/glyphlist.txt"
    {"qarneyparahebrew","059F"},
#line 3981 "pdfdoc/glyphlist.txt"
    {"ushortcyrillic","045E"},
#line 3243 "pdfdoc/glyphlist.txt"
    {"ramshorn","0264"},
#line 3254 "pdfdoc/glyphlist.txt"
    {"referencemark","203B"},
#line 3784 "pdfdoc/glyphlist.txt"
    {"threequarters","00BE"},
#line 1244 "pdfdoc/glyphlist.txt"
    {"bethebrew","05D1"},
#line 3977 "pdfdoc/glyphlist.txt"
    {"uptackbelowcmb","031D"},
#line 3782 "pdfdoc/glyphlist.txt"
    {"threeperiod","248A"},
#line 2768 "pdfdoc/glyphlist.txt"
    {"ninepersian","06F9"},
#line 3843 "pdfdoc/glyphlist.txt"
    {"triaglf","25C4"},
#line 3861 "pdfdoc/glyphlist.txt"
    {"tsuperior","F6F3"},
#line 3958 "pdfdoc/glyphlist.txt"
    {"umacrondieresis","1E7B"},
#line 3455 "pdfdoc/glyphlist.txt"
    {"sentosquare","3323"},
#line 3454 "pdfdoc/glyphlist.txt"
    {"sentisquare","3322"},
#line 3972 "pdfdoc/glyphlist.txt"
    {"upsilon","03C5"},
#line 1565 "pdfdoc/glyphlist.txt"
    {"dblverticalbar","2016"},
#line 3858 "pdfdoc/glyphlist.txt"
    {"tserequarterhebrew","05B5"},
#line 1563 "pdfdoc/glyphlist.txt"
    {"dbloverlinecmb","033F"},
#line 3975 "pdfdoc/glyphlist.txt"
    {"upsilonlatin","028A"},
#line 201 "pdfdoc/glyphlist.txt"
    {"Etatonos","0389"},
#line 3163 "pdfdoc/glyphlist.txt"
    {"qbopomofo","3111"},
#line 2623 "pdfdoc/glyphlist.txt"
    {"meizierasquare","337E"},
#line 3712 "pdfdoc/glyphlist.txt"
    {"telishagedolahebrew","05A0"},
#line 4113 "pdfdoc/glyphlist.txt"
    {"wowaenthai","0E27"},
#line 3181 "pdfdoc/glyphlist.txt"
    {"qofqamats","05E7 05B8"},
#line 3893 "pdfdoc/glyphlist.txt"
    {"twocircleinversesansserif","278B"},
#line 3811 "pdfdoc/glyphlist.txt"
    {"tiwnarmenian","057F"},
#line 3812 "pdfdoc/glyphlist.txt"
    {"tlinebelow","1E6F"},
#line 2614 "pdfdoc/glyphlist.txt"
    {"mdotbelow","1E43"},
#line 4244 "pdfdoc/glyphlist.txt"
    {"zaqefgadolhebrew","0595"},
#line 1566 "pdfdoc/glyphlist.txt"
    {"dblverticallineabovecmb","030E"},
#line 3337 "pdfdoc/glyphlist.txt"
    {"rinvertedbreve","0213"},
#line 1888 "pdfdoc/glyphlist.txt"
    {"fivepersian","06F5"},
#line 790 "pdfdoc/glyphlist.txt"
    {"adblgrave","0201"},
#line 1177 "pdfdoc/glyphlist.txt"
    {"ascriptturned","0252"},
#line 632 "pdfdoc/glyphlist.txt"
    {"Udblgrave","0214"},
#line 3551 "pdfdoc/glyphlist.txt"
    {"siosparenkorean","3206"},
#line 503 "pdfdoc/glyphlist.txt"
    {"Rdblgrave","0210"},
#line 4258 "pdfdoc/glyphlist.txt"
    {"zdotbelow","1E93"},
#line 3145 "pdfdoc/glyphlist.txt"
    {"qafmedialarabic","FED8"},
#line 3693 "pdfdoc/glyphlist.txt"
    {"tedescendercyrillic","04AD"},
#line 2861 "pdfdoc/glyphlist.txt"
    {"ocandravowelsigndeva","0949"},
#line 2862 "pdfdoc/glyphlist.txt"
    {"ocandravowelsigngujarati","0AC9"},
#line 3063 "pdfdoc/glyphlist.txt"
    {"pfsquare","338A"},
#line 286 "pdfdoc/glyphlist.txt"
    {"Idblgrave","0208"},
#line 3767 "pdfdoc/glyphlist.txt"
    {"threebengali","09E9"},
#line 2585 "pdfdoc/glyphlist.txt"
    {"maieklowrightthai","F88B"},
#line 167 "pdfdoc/glyphlist.txt"
    {"Edotbelow","1EB8"},
#line 1691 "pdfdoc/glyphlist.txt"
    {"edblgrave","0205"},
#line 3887 "pdfdoc/glyphlist.txt"
    {"twentyparen","2487"},
#line 2582 "pdfdoc/glyphlist.txt"
    {"maichattawathai","0E4B"},
#line 2877 "pdfdoc/glyphlist.txt"
    {"odotbelow","1ECD"},
#line 2584 "pdfdoc/glyphlist.txt"
    {"maieklowleftthai","F88C"},
#line 2451 "pdfdoc/glyphlist.txt"
    {"kooposquare","331E"},
#line 3962 "pdfdoc/glyphlist.txt"
    {"underscoredbl","2017"},
#line 2937 "pdfdoc/glyphlist.txt"
    {"onequarter","00BC"},
#line 3947 "pdfdoc/glyphlist.txt"
    {"uhornhookabove","1EED"},
#line 4283 "pdfdoc/glyphlist.txt"
    {"zhebrevecyrillic","04C2"},
#line 4098 "pdfdoc/glyphlist.txt"
    {"whitestar","2606"},
#line 3809 "pdfdoc/glyphlist.txt"
    {"tippigurmukhi","0A70"},
#line 2580 "pdfdoc/glyphlist.txt"
    {"maichattawalowleftthai","F895"},
#line 2581 "pdfdoc/glyphlist.txt"
    {"maichattawalowrightthai","F894"},
#line 2191 "pdfdoc/glyphlist.txt"
    {"idblgrave","0209"},
#line 3332 "pdfdoc/glyphlist.txt"
    {"ringhalfleftbelowcmb","031C"},
#line 3998 "pdfdoc/glyphlist.txt"
    {"uvowelsignbengali","09C1"},
#line 2971 "pdfdoc/glyphlist.txt"
    {"overlinedblwavy","FE4C"},
#line 3909 "pdfdoc/glyphlist.txt"
    {"twopersian","06F2"},
#line 3726 "pdfdoc/glyphlist.txt"
    {"tevirlefthebrew","059B"},
#line 597 "pdfdoc/glyphlist.txt"
    {"Tdotbelow","1E6C"},
#line 2157 "pdfdoc/glyphlist.txt"
    {"hookpalatalizedbelowcmb","0321"},
#line 3133 "pdfdoc/glyphlist.txt"
    {"psilipneumatacyrilliccmb","0486"},
#line 3682 "pdfdoc/glyphlist.txt"
    {"tchehfinalarabic","FB7B"},
#line 3780 "pdfdoc/glyphlist.txt"
    {"threeoldstyle","F733"},
#line 4174 "pdfdoc/glyphlist.txt"
    {"yerudieresiscyrillic","04F9"},
#line 3432 "pdfdoc/glyphlist.txt"
    {"seenfinalarabic","FEB2"},
#line 1643 "pdfdoc/glyphlist.txt"
    {"dotbelowcmb","0323"},
#line 2627 "pdfdoc/glyphlist.txt"
    {"memdagesh","FB3E"},
#line 3660 "pdfdoc/glyphlist.txt"
    {"tagurmukhi","0A24"},
#line 431 "pdfdoc/glyphlist.txt"
    {"Odblgrave","020C"},
#line 3785 "pdfdoc/glyphlist.txt"
    {"threequartersemdash","F6DE"},
#line 3825 "pdfdoc/glyphlist.txt"
    {"tonetwo","01A8"},
#line 3999 "pdfdoc/glyphlist.txt"
    {"uvowelsigndeva","0941"},
#line 3050 "pdfdoc/glyphlist.txt"
    {"percentsmall","FE6A"},
#line 2443 "pdfdoc/glyphlist.txt"
    {"kmcubedsquare","33A6"},
#line 1830 "pdfdoc/glyphlist.txt"
    {"fathalowarabic","064E"},
#line 1549 "pdfdoc/glyphlist.txt"
    {"dblGrave","F6D3"},
#line 4182 "pdfdoc/glyphlist.txt"
    {"yiarmenian","0575"},
#line 1542 "pdfdoc/glyphlist.txt"
    {"dammalowarabic","064F"},
#line 4185 "pdfdoc/glyphlist.txt"
    {"yinyang","262F"},
#line 3275 "pdfdoc/glyphlist.txt"
    {"reshhiriqhebrew","05E8 05B4"},
#line 3717 "pdfdoc/glyphlist.txt"
    {"tenperiod","2491"},
#line 1555 "pdfdoc/glyphlist.txt"
    {"dblarrowleft","21D4"},
#line 1556 "pdfdoc/glyphlist.txt"
    {"dblarrowright","21D2"},
#line 2158 "pdfdoc/glyphlist.txt"
    {"hookretroflexbelowcmb","0322"},
#line 4221 "pdfdoc/glyphlist.txt"
    {"yusbigiotifiedcyrillic","046D"},
#line 1558 "pdfdoc/glyphlist.txt"
    {"dblgrave","F6D6"},
#line 1416 "pdfdoc/glyphlist.txt"
    {"cmcubedsquare","33A4"},
#line 4175 "pdfdoc/glyphlist.txt"
    {"yesieungkorean","3181"},
#line 3919 "pdfdoc/glyphlist.txt"
    {"ubopomofo","3128"},
#line 2634 "pdfdoc/glyphlist.txt"
    {"merkhalefthebrew","05A5"},
#line 3689 "pdfdoc/glyphlist.txt"
    {"tdieresis","1E97"},
#line 3665 "pdfdoc/glyphlist.txt"
    {"tahmedialarabic","FEC4"},
#line 3704 "pdfdoc/glyphlist.txt"
    {"tehmedialarabic","FE98"},
#line 3286 "pdfdoc/glyphlist.txt"
    {"reshsheva","05E8 05B0"},
#line 3886 "pdfdoc/glyphlist.txt"
    {"twentyhangzhou","5344"},
#line 2421 "pdfdoc/glyphlist.txt"
    {"khokhonthai","0E05"},
#line 3739 "pdfdoc/glyphlist.txt"
    {"thehinitialarabic","FE9B"},
#line 4177 "pdfdoc/glyphlist.txt"
    {"yesieungsioskorean","3182"},
#line 3908 "pdfdoc/glyphlist.txt"
    {"twoperiod","2489"},
#line 4176 "pdfdoc/glyphlist.txt"
    {"yesieungpansioskorean","3183"},
#line 1936 "pdfdoc/glyphlist.txt"
    {"gagujarati","0A97"},
#line 756 "pdfdoc/glyphlist.txt"
    {"aagujarati","0A86"},
#line 1198 "pdfdoc/glyphlist.txt"
    {"augujarati","0A94"},
#line 2327 "pdfdoc/glyphlist.txt"
    {"jagujarati","0A9C"},
#line 1511 "pdfdoc/glyphlist.txt"
    {"dagujarati","0AA6"},
#line 1057 "pdfdoc/glyphlist.txt"
    {"aigujarati","0A90"},
#line 3778 "pdfdoc/glyphlist.txt"
    {"threemonospace","FF13"},
#line 3868 "pdfdoc/glyphlist.txt"
    {"ttehinitialarabic","FB68"},
#line 191 "pdfdoc/glyphlist.txt"
    {"Epsilontonos","0388"},
#line 3308 "pdfdoc/glyphlist.txt"
    {"rieulkiyeokkorean","313A"},
#line 3950 "pdfdoc/glyphlist.txt"
    {"uhungarumlautcyrillic","04F3"},
#line 2727 "pdfdoc/glyphlist.txt"
    {"newsheqelsign","20AA"},
#line 4016 "pdfdoc/glyphlist.txt"
    {"vdotbelow","1E7F"},
#line 3949 "pdfdoc/glyphlist.txt"
    {"uhungarumlaut","0171"},
#line 2708 "pdfdoc/glyphlist.txt"
    {"nagujarati","0AA8"},
#line 2409 "pdfdoc/glyphlist.txt"
    {"khahfinalarabic","FEA6"},
#line 44 "pdfdoc/glyphlist.txt"
    {"Adblgrave","0200"},
#line 3309 "pdfdoc/glyphlist.txt"
    {"rieulkiyeoksioskorean","3169"},
#line 2264 "pdfdoc/glyphlist.txt"
    {"iigujarati","0A88"},
#line 3847 "pdfdoc/glyphlist.txt"
    {"tsadi","05E6"},
#line 3715 "pdfdoc/glyphlist.txt"
    {"tenideographicparen","3229"},
#line 1436 "pdfdoc/glyphlist.txt"
    {"commareversedmod","02BD"},
#line 3798 "pdfdoc/glyphlist.txt"
    {"tilde","02DC"},
#line 2036 "pdfdoc/glyphlist.txt"
    {"hagujarati","0AB9"},
#line 2842 "pdfdoc/glyphlist.txt"
    {"nundageshhebrew","FB40"},
#line 3253 "pdfdoc/glyphlist.txt"
    {"rdotbelowmacron","1E5D"},
#line 3687 "pdfdoc/glyphlist.txt"
    {"tcircumflexbelow","1E71"},
#line 2969 "pdfdoc/glyphlist.txt"
    {"overlinecmb","0305"},
#line 3097 "pdfdoc/glyphlist.txt"
    {"pisymbolgreek","03D6"},
#line 1189 "pdfdoc/glyphlist.txt"
    {"asymptoticallyequal","2243"},
#line 2660 "pdfdoc/glyphlist.txt"
    {"mmcubedsquare","33A3"},
#line 3973 "pdfdoc/glyphlist.txt"
    {"upsilondieresis","03CB"},
#line 2070 "pdfdoc/glyphlist.txt"
    {"hatafqamats1b","05B3"},
#line 3619 "pdfdoc/glyphlist.txt"
    {"squareverticalfill","25A5"},
#line 4073 "pdfdoc/glyphlist.txt"
    {"weierstrass","2118"},
#line 3974 "pdfdoc/glyphlist.txt"
    {"upsilondieresistonos","03B0"},
#line 3175 "pdfdoc/glyphlist.txt"
    {"qofhiriq","05E7 05B4"},
#line 3902 "pdfdoc/glyphlist.txt"
    {"twoideographicparen","3221"},
#line 2469 "pdfdoc/glyphlist.txt"
    {"lagujarati","0AB2"},
#line 2003 "pdfdoc/glyphlist.txt"
    {"gradient","2207"},
#line 3728 "pdfdoc/glyphlist.txt"
    {"thadeva","0925"},
#line 3252 "pdfdoc/glyphlist.txt"
    {"rdotbelow","1E5B"},
#line 4165 "pdfdoc/glyphlist.txt"
    {"yehthreedotsbelowarabic","06D1"},
#line 2583 "pdfdoc/glyphlist.txt"
    {"maichattawaupperleftthai","F893"},
#line 3863 "pdfdoc/glyphlist.txt"
    {"ttadeva","091F"},
#line 3903 "pdfdoc/glyphlist.txt"
    {"twoinferior","2082"},
#line 3769 "pdfdoc/glyphlist.txt"
    {"threecircleinversesansserif","278C"},
#line 3912 "pdfdoc/glyphlist.txt"
    {"twosuperior","00B2"},
#line 1143 "pdfdoc/glyphlist.txt"
    {"arrowdownleft","2199"},
#line 3905 "pdfdoc/glyphlist.txt"
    {"twonumeratorbengali","09F5"},
#line 4160 "pdfdoc/glyphlist.txt"
    {"yehinitialarabic","FEF3"},
#line 3859 "pdfdoc/glyphlist.txt"
    {"tserewidehebrew","05B5"},
#line 2610 "pdfdoc/glyphlist.txt"
    {"mbsquare","33D4"},
#line 3954 "pdfdoc/glyphlist.txt"
    {"ukcyrillic","0479"},
#line 4061 "pdfdoc/glyphlist.txt"
    {"wavyunderscorevertical","FE34"},
#line 2629 "pdfdoc/glyphlist.txt"
    {"memhebrew","05DE"},
#line 168 "pdfdoc/glyphlist.txt"
    {"Efcyrillic","0424"},
#line 1409 "pdfdoc/glyphlist.txt"
    {"clickalveolar","01C2"},
#line 3894 "pdfdoc/glyphlist.txt"
    {"twodeva","0968"},
#line 1497 "pdfdoc/glyphlist.txt"
    {"cyrbreve","F6D4"},
#line 4222 "pdfdoc/glyphlist.txt"
    {"yuslittlecyrillic","0467"},
#line 4007 "pdfdoc/glyphlist.txt"
    {"vavdagesh","FB35"},
#line 3828 "pdfdoc/glyphlist.txt"
    {"topatakthai","0E0F"},
#line 4223 "pdfdoc/glyphlist.txt"
    {"yuslittleiotifiedcyrillic","0469"},
#line 3850 "pdfdoc/glyphlist.txt"
    {"tsadihebrew","05E6"},
#line 4008 "pdfdoc/glyphlist.txt"
    {"vavdagesh65","FB35"},
#line 3814 "pdfdoc/glyphlist.txt"
    {"toarmenian","0569"},
#line 3777 "pdfdoc/glyphlist.txt"
    {"threeinferior","2083"},
#line 2616 "pdfdoc/glyphlist.txt"
    {"meemfinalarabic","FEE2"},
#line 2899 "pdfdoc/glyphlist.txt"
    {"olehebrew","05AB"},
#line 2053 "pdfdoc/glyphlist.txt"
    {"hamzalowkasraarabic","0621 0650"},
#line 2954 "pdfdoc/glyphlist.txt"
    {"oshortvowelsigndeva","094A"},
#line 3591 "pdfdoc/glyphlist.txt"
    {"solidusshortoverlaycmb","0337"},
#line 4242 "pdfdoc/glyphlist.txt"
    {"zainfinalarabic","FEB0"},
#line 4220 "pdfdoc/glyphlist.txt"
    {"yusbigcyrillic","046B"},
#line 2054 "pdfdoc/glyphlist.txt"
    {"hamzalowkasratanarabic","0621 064D"},
#line 2976 "pdfdoc/glyphlist.txt"
    {"ovowelsigngujarati","0ACB"},
#line 3241 "pdfdoc/glyphlist.txt"
    {"ralowerdiagonalbengali","09F1"},
#line 4014 "pdfdoc/glyphlist.txt"
    {"vavyodhebrew","05F1"},
#line 3827 "pdfdoc/glyphlist.txt"
    {"tonsquare","3327"},
#line 3848 "pdfdoc/glyphlist.txt"
    {"tsadidagesh","FB46"},
#line 1265 "pdfdoc/glyphlist.txt"
    {"blacklowerlefttriangle","25E3"},
#line 1215 "pdfdoc/glyphlist.txt"
    {"bagujarati","0AAC"},
#line 2059 "pdfdoc/glyphlist.txt"
    {"harpoonrightbarbup","21C0"},
#line 3185 "pdfdoc/glyphlist.txt"
    {"qofsegol","05E7 05B6"},
#line 1208 "pdfdoc/glyphlist.txt"
    {"ayinaltonehebrew","FB20"},
#line 3883 "pdfdoc/glyphlist.txt"
    {"twelveperiod","2493"},
#line 3144 "pdfdoc/glyphlist.txt"
    {"qafinitialarabic","FED7"},
#line 3279 "pdfdoc/glyphlist.txt"
    {"reshpatahhebrew","05E8 05B7"},
#line 2988 "pdfdoc/glyphlist.txt"
    {"paiyannoithai","0E2F"},
#line 3710 "pdfdoc/glyphlist.txt"
    {"telephone","2121"},
#line 3997 "pdfdoc/glyphlist.txt"
    {"uuvowelsigngujarati","0AC2"},
#line 3186 "pdfdoc/glyphlist.txt"
    {"qofsegolhebrew","05E7 05B6"},
#line 3807 "pdfdoc/glyphlist.txt"
    {"tipehahebrew","0596"},
#line 3711 "pdfdoc/glyphlist.txt"
    {"telephoneblack","260E"},
#line 3156 "pdfdoc/glyphlist.txt"
    {"qamatsqatanhebrew","05B8"},
#line 1490 "pdfdoc/glyphlist.txt"
    {"cruzeiro","20A2"},
#line 3157 "pdfdoc/glyphlist.txt"
    {"qamatsqatannarrowhebrew","05B8"},
#line 3849 "pdfdoc/glyphlist.txt"
    {"tsadidageshhebrew","FB46"},
#line 3669 "pdfdoc/glyphlist.txt"
    {"tatweelarabic","0640"},
#line 3951 "pdfdoc/glyphlist.txt"
    {"uinvertedbreve","0217"},
#line 3761 "pdfdoc/glyphlist.txt"
    {"thothungthai","0E16"},
#line 3760 "pdfdoc/glyphlist.txt"
    {"thothongthai","0E18"},
#line 3697 "pdfdoc/glyphlist.txt"
    {"tehhahisolatedarabic","FC0C"},
#line 1243 "pdfdoc/glyphlist.txt"
    {"betdageshhebrew","FB31"},
#line 2985 "pdfdoc/glyphlist.txt"
    {"pagujarati","0AAA"},
#line 3927 "pdfdoc/glyphlist.txt"
    {"udblacute","0171"},
#line 3639 "pdfdoc/glyphlist.txt"
    {"subsetnotequal","228A"},
#line 3202 "pdfdoc/glyphlist.txt"
    {"questionarabic","061F"},
#line 2972 "pdfdoc/glyphlist.txt"
    {"overlinewavy","FE4B"},
#line 4230 "pdfdoc/glyphlist.txt"
    {"yyadeva","095F"},
#line 2064 "pdfdoc/glyphlist.txt"
    {"hatafpatah2f","05B2"},
#line 3159 "pdfdoc/glyphlist.txt"
    {"qamatsqatanwidehebrew","05B8"},
#line 3681 "pdfdoc/glyphlist.txt"
    {"tcheharabic","0686"},
#line 3789 "pdfdoc/glyphlist.txt"
    {"thzsquare","3394"},
#line 3766 "pdfdoc/glyphlist.txt"
    {"threearabic","0663"},
#line 3385 "pdfdoc/glyphlist.txt"
    {"sagujarati","0AB8"},
#line 3786 "pdfdoc/glyphlist.txt"
    {"threeroman","2172"},
#line 3945 "pdfdoc/glyphlist.txt"
    {"uhorndotbelow","1EF1"},
#line 747 "pdfdoc/glyphlist.txt"
    {"Zhedieresiscyrillic","04DC"},
#line 3729 "pdfdoc/glyphlist.txt"
    {"thagujarati","0AA5"},
#line 3838 "pdfdoc/glyphlist.txt"
    {"trademark","2122"},
#line 3864 "pdfdoc/glyphlist.txt"
    {"ttagujarati","0A9F"},
#line 2651 "pdfdoc/glyphlist.txt"
    {"minusbelowcmb","0320"},
#line 3842 "pdfdoc/glyphlist.txt"
    {"triagdn","25BC"},
#line 3656 "pdfdoc/glyphlist.txt"
    {"tackdown","22A4"},
#line 4081 "pdfdoc/glyphlist.txt"
    {"whitecornerbracketleft","300E"},
#line 4083 "pdfdoc/glyphlist.txt"
    {"whitecornerbracketright","300F"},
#line 4208 "pdfdoc/glyphlist.txt"
    {"ypogegrammeni","037A"},
#line 3663 "pdfdoc/glyphlist.txt"
    {"tahinitialarabic","FEC3"},
#line 4274 "pdfdoc/glyphlist.txt"
    {"zeropersian","06F0"},
#line 3698 "pdfdoc/glyphlist.txt"
    {"tehinitialarabic","FE97"},
#line 101 "pdfdoc/glyphlist.txt"
    {"Chedieresiscyrillic","04F4"},
#line 4010 "pdfdoc/glyphlist.txt"
    {"vavhebrew","05D5"},
#line 4082 "pdfdoc/glyphlist.txt"
    {"whitecornerbracketleftvertical","FE43"},
#line 4084 "pdfdoc/glyphlist.txt"
    {"whitecornerbracketrightvertical","FE44"},
#line 3839 "pdfdoc/glyphlist.txt"
    {"trademarksans","F8EA"},
#line 3898 "pdfdoc/glyphlist.txt"
    {"twogujarati","0AE8"},
#line 4228 "pdfdoc/glyphlist.txt"
    {"yuyeokorean","318A"},
#line 1495 "pdfdoc/glyphlist.txt"
    {"cyrBreve","F6D1"},
#line 3844 "pdfdoc/glyphlist.txt"
    {"triagrt","25BA"},
#line 4203 "pdfdoc/glyphlist.txt"
    {"yoyaekorean","3188"},
#line 3713 "pdfdoc/glyphlist.txt"
    {"telishaqetanahebrew","05A9"},
#line 3996 "pdfdoc/glyphlist.txt"
    {"uuvowelsigndeva","0942"},
#line 1435 "pdfdoc/glyphlist.txt"
    {"commareversedabovecmb","0314"},
#line 3911 "pdfdoc/glyphlist.txt"
    {"twostroke","01BB"},
#line 3657 "pdfdoc/glyphlist.txt"
    {"tackleft","22A3"},
#line 3895 "pdfdoc/glyphlist.txt"
    {"twodotenleader","2025"},
#line 3829 "pdfdoc/glyphlist.txt"
    {"tortoiseshellbracketleft","3014"},
#line 3832 "pdfdoc/glyphlist.txt"
    {"tortoiseshellbracketright","3015"},
#line 2367 "pdfdoc/glyphlist.txt"
    {"kagujarati","0A95"},
#line 3756 "pdfdoc/glyphlist.txt"
    {"thophuthaothai","0E12"},
#line 3352 "pdfdoc/glyphlist.txt"
    {"rrehfinalarabic","FB8D"},
#line 4112 "pdfdoc/glyphlist.txt"
    {"wonmonospace","FFE6"},
#line 2360 "pdfdoc/glyphlist.txt"
    {"kafdagesh","FB3B"},
#line 2688 "pdfdoc/glyphlist.txt"
    {"multiply","00D7"},
#line 1335 "pdfdoc/glyphlist.txt"
    {"cagujarati","0A9A"},
#line 3830 "pdfdoc/glyphlist.txt"
    {"tortoiseshellbracketleftsmall","FE5D"},
#line 3833 "pdfdoc/glyphlist.txt"
    {"tortoiseshellbracketrightsmall","FE5E"},
#line 3831 "pdfdoc/glyphlist.txt"
    {"tortoiseshellbracketleftvertical","FE39"},
#line 3834 "pdfdoc/glyphlist.txt"
    {"tortoiseshellbracketrightvertical","FE3A"},
#line 162 "pdfdoc/glyphlist.txt"
    {"Edblgrave","0204"},
#line 2873 "pdfdoc/glyphlist.txt"
    {"odblgrave","020D"},
#line 2180 "pdfdoc/glyphlist.txt"
    {"hyphentwo","2010"},
#line 3197 "pdfdoc/glyphlist.txt"
    {"qubutshebrew","05BB"},
#line 3294 "pdfdoc/glyphlist.txt"
    {"rfishhook","027E"},
#line 3035 "pdfdoc/glyphlist.txt"
    {"peezisquare","333B"},
#line 4173 "pdfdoc/glyphlist.txt"
    {"yericyrillic","044B"},
#line 3182 "pdfdoc/glyphlist.txt"
    {"qofqamatshebrew","05E7 05B8"},
#line 3937 "pdfdoc/glyphlist.txt"
    {"udotbelow","1EE5"},
#line 4154 "pdfdoc/glyphlist.txt"
    {"yehbarreefinalarabic","FBAF"},
#line 4183 "pdfdoc/glyphlist.txt"
    {"yicyrillic","0457"},
#line 2575 "pdfdoc/glyphlist.txt"
    {"magujarati","0AAE"},
#line 1644 "pdfdoc/glyphlist.txt"
    {"dotbelowcomb","0323"},
#line 4206 "pdfdoc/glyphlist.txt"
    {"yoyingthai","0E0D"},
#line 4071 "pdfdoc/glyphlist.txt"
    {"wdotbelow","1E89"},
#line 3231 "pdfdoc/glyphlist.txt"
    {"radoverssquare","33AE"},
#line 612 "pdfdoc/glyphlist.txt"
    {"Tonefive","01BC"},
#line 3232 "pdfdoc/glyphlist.txt"
    {"radoverssquaredsquare","33AF"},
#line 1559 "pdfdoc/glyphlist.txt"
    {"dblgravecmb","030F"},
#line 3677 "pdfdoc/glyphlist.txt"
    {"tbopomofo","310A"},
#line 2911 "pdfdoc/glyphlist.txt"
    {"omgujarati","0AD0"},
#line 2628 "pdfdoc/glyphlist.txt"
    {"memdageshhebrew","FB3E"},
#line 4164 "pdfdoc/glyphlist.txt"
    {"yehnoonfinalarabic","FC94"},
#line 3888 "pdfdoc/glyphlist.txt"
    {"twentyperiod","249B"},
#line 4193 "pdfdoc/glyphlist.txt"
    {"yodyodpatahhebrew","FB1F"},
#line 3810 "pdfdoc/glyphlist.txt"
    {"titlocyrilliccmb","0483"},
#line 3218 "pdfdoc/glyphlist.txt"
    {"quotereversed","201B"},
#line 2363 "pdfdoc/glyphlist.txt"
    {"kafhebrew","05DB"},
#line 3287 "pdfdoc/glyphlist.txt"
    {"reshshevahebrew","05E8 05B0"},
#line 3976 "pdfdoc/glyphlist.txt"
    {"upsilontonos","03CD"},
#line 3680 "pdfdoc/glyphlist.txt"
    {"tcedilla","0163"},
#line 3250 "pdfdoc/glyphlist.txt"
    {"rdblgrave","0211"},
#line 3914 "pdfdoc/glyphlist.txt"
    {"twothirds","2154"},
#line 3183 "pdfdoc/glyphlist.txt"
    {"qofqubuts","05E7 05BB"},
#line 3295 "pdfdoc/glyphlist.txt"
    {"rfishhookreversed","027F"},
#line 3158 "pdfdoc/glyphlist.txt"
    {"qamatsqatanquarterhebrew","05B8"},
#line 3198 "pdfdoc/glyphlist.txt"
    {"qubutsnarrowhebrew","05BB"},
#line 4003 "pdfdoc/glyphlist.txt"
    {"vagujarati","0AB5"},
#line 3860 "pdfdoc/glyphlist.txt"
    {"tshecyrillic","045B"},
#line 3971 "pdfdoc/glyphlist.txt"
    {"upperdothebrew","05C4"},
#line 3189 "pdfdoc/glyphlist.txt"
    {"qoftsere","05E7 05B5"},
#line 3873 "pdfdoc/glyphlist.txt"
    {"tthagurmukhi","0A20"},
#line 3692 "pdfdoc/glyphlist.txt"
    {"tecyrillic","0442"},
#line 1377 "pdfdoc/glyphlist.txt"
    {"chedieresiscyrillic","04F5"},
#line 4168 "pdfdoc/glyphlist.txt"
    {"yenmonospace","FFE5"},
#line 4097 "pdfdoc/glyphlist.txt"
    {"whitesquare","25A1"},
#line 4059 "pdfdoc/glyphlist.txt"
    {"wattosquare","3357"},
#line 3190 "pdfdoc/glyphlist.txt"
    {"qoftserehebrew","05E7 05B5"},
#line 4088 "pdfdoc/glyphlist.txt"
    {"whitedownpointingtriangle","25BD"},
#line 4087 "pdfdoc/glyphlist.txt"
    {"whitedownpointingsmalltriangle","25BF"},
#line 3236 "pdfdoc/glyphlist.txt"
    {"ragujarati","0AB0"},
#line 3742 "pdfdoc/glyphlist.txt"
    {"therefore","2234"},
#line 2052 "pdfdoc/glyphlist.txt"
    {"hamzalowarabic","0621"},
#line 2604 "pdfdoc/glyphlist.txt"
    {"mansyonsquare","3347"},
#line 3200 "pdfdoc/glyphlist.txt"
    {"qubutswidehebrew","05BB"},
#line 3870 "pdfdoc/glyphlist.txt"
    {"tthabengali","09A0"},
#line 3683 "pdfdoc/glyphlist.txt"
    {"tchehinitialarabic","FB7C"},
#line 3803 "pdfdoc/glyphlist.txt"
    {"tildeoperator","223C"},
#line 3707 "pdfdoc/glyphlist.txt"
    {"tehnoonfinalarabic","FC73"},
#line 4009 "pdfdoc/glyphlist.txt"
    {"vavdageshhebrew","FB35"},
#line 3906 "pdfdoc/glyphlist.txt"
    {"twooldstyle","F732"},
#line 4000 "pdfdoc/glyphlist.txt"
    {"uvowelsigngujarati","0AC1"},
#line 4066 "pdfdoc/glyphlist.txt"
    {"wbsquare","33DD"},
#line 4245 "pdfdoc/glyphlist.txt"
    {"zaqefqatanhebrew","0594"},
#line 3995 "pdfdoc/glyphlist.txt"
    {"uuvowelsignbengali","09C2"},
#line 3871 "pdfdoc/glyphlist.txt"
    {"tthadeva","0920"},
#line 4286 "pdfdoc/glyphlist.txt"
    {"zhedieresiscyrillic","04DD"},
#line 2284 "pdfdoc/glyphlist.txt"
    {"infinity","221E"},
#line 4151 "pdfdoc/glyphlist.txt"
    {"ydotbelow","1EF5"},
#line 4227 "pdfdoc/glyphlist.txt"
    {"yuyekorean","318B"},
#line 4204 "pdfdoc/glyphlist.txt"
    {"yoyakorean","3187"},
#line 3884 "pdfdoc/glyphlist.txt"
    {"twelveroman","217B"},
#line 4209 "pdfdoc/glyphlist.txt"
    {"ypogegrammenigreekcmb","0345"},
#line 3800 "pdfdoc/glyphlist.txt"
    {"tildecmb","0303"},
#line 3840 "pdfdoc/glyphlist.txt"
    {"trademarkserif","F6DB"},
#line 3100 "pdfdoc/glyphlist.txt"
    {"plusbelowcmb","031F"},
#line 3762 "pdfdoc/glyphlist.txt"
    {"thousandcyrillic","0482"},
#line 3187 "pdfdoc/glyphlist.txt"
    {"qofsheva","05E7 05B0"},
#line 3904 "pdfdoc/glyphlist.txt"
    {"twomonospace","FF12"},
#line 3666 "pdfdoc/glyphlist.txt"
    {"taisyouerasquare","337D"},
#line 3808 "pdfdoc/glyphlist.txt"
    {"tipehalefthebrew","0596"},
#line 3188 "pdfdoc/glyphlist.txt"
    {"qofshevahebrew","05E7 05B0"},
#line 3759 "pdfdoc/glyphlist.txt"
    {"thothanthai","0E10"},
#line 3328 "pdfdoc/glyphlist.txt"
    {"ringbelowcmb","0325"},
#line 3928 "pdfdoc/glyphlist.txt"
    {"udblgrave","0215"},
#line 3168 "pdfdoc/glyphlist.txt"
    {"qofdagesh","FB47"},
#line 3820 "pdfdoc/glyphlist.txt"
    {"tonebarhighmod","02E6"},
#line 2361 "pdfdoc/glyphlist.txt"
    {"kafdageshhebrew","FB3B"},
#line 3896 "pdfdoc/glyphlist.txt"
    {"twodotleader","2025"},
#line 4189 "pdfdoc/glyphlist.txt"
    {"yoddagesh","FB39"},
#line 3691 "pdfdoc/glyphlist.txt"
    {"tdotbelow","1E6D"},
#line 3770 "pdfdoc/glyphlist.txt"
    {"threedeva","0969"},
#line 4153 "pdfdoc/glyphlist.txt"
    {"yehbarreearabic","06D2"},
#line 4192 "pdfdoc/glyphlist.txt"
    {"yodyodhebrew","05F2"},
#line 3160 "pdfdoc/glyphlist.txt"
    {"qamatsquarterhebrew","05B8"},
#line 1317 "pdfdoc/glyphlist.txt"
    {"breveinverteddoublecmb","0361"},
#line 3763 "pdfdoc/glyphlist.txt"
    {"thousandsseparatorarabic","066C"},
#line 3764 "pdfdoc/glyphlist.txt"
    {"thousandsseparatorpersian","066C"},
#line 3721 "pdfdoc/glyphlist.txt"
    {"tetdagesh","FB38"},
#line 3992 "pdfdoc/glyphlist.txt"
    {"uugujarati","0A8A"},
#line 3897 "pdfdoc/glyphlist.txt"
    {"twodotleadervertical","FE30"},
#line 3821 "pdfdoc/glyphlist.txt"
    {"tonebarlowmod","02E8"},
#line 1315 "pdfdoc/glyphlist.txt"
    {"breveinvertedbelowcmb","032F"},
#line 3673 "pdfdoc/glyphlist.txt"
    {"tavdagesh","FB4A"},
#line 3672 "pdfdoc/glyphlist.txt"
    {"tavdages","FB4A"},
#line 3174 "pdfdoc/glyphlist.txt"
    {"qofhebrew","05E7"},
#line 4191 "pdfdoc/glyphlist.txt"
    {"yodhebrew","05D9"},
#line 3184 "pdfdoc/glyphlist.txt"
    {"qofqubutshebrew","05E7 05BB"},
#line 3723 "pdfdoc/glyphlist.txt"
    {"tethebrew","05D8"},
#line 3732 "pdfdoc/glyphlist.txt"
    {"thalfinalarabic","FEAC"},
#line 3738 "pdfdoc/glyphlist.txt"
    {"thehfinalarabic","FE9A"},
#line 3867 "pdfdoc/glyphlist.txt"
    {"ttehfinalarabic","FB67"},
#line 3675 "pdfdoc/glyphlist.txt"
    {"tavhebrew","05EA"},
#line 3818 "pdfdoc/glyphlist.txt"
    {"tonebarextrahighmod","02E5"},
#line 3819 "pdfdoc/glyphlist.txt"
    {"tonebarextralowmod","02E9"},
#line 4136 "pdfdoc/glyphlist.txt"
    {"yagujarati","0AAF"},
#line 3822 "pdfdoc/glyphlist.txt"
    {"tonebarmidmod","02E7"},
#line 3169 "pdfdoc/glyphlist.txt"
    {"qofdageshhebrew","FB47"},
#line 3805 "pdfdoc/glyphlist.txt"
    {"tildeverticalcmb","033E"},
#line 3823 "pdfdoc/glyphlist.txt"
    {"tonefive","01BD"},
#line 4190 "pdfdoc/glyphlist.txt"
    {"yoddageshhebrew","FB39"},
#line 1316 "pdfdoc/glyphlist.txt"
    {"breveinvertedcmb","0311"},
#line 3659 "pdfdoc/glyphlist.txt"
    {"tagujarati","0AA4"},
#line 3722 "pdfdoc/glyphlist.txt"
    {"tetdageshhebrew","FB38"},
#line 3801 "pdfdoc/glyphlist.txt"
    {"tildecomb","0303"},
#line 3674 "pdfdoc/glyphlist.txt"
    {"tavdageshhebrew","FB4A"},
#line 4131 "pdfdoc/glyphlist.txt"
    {"yaadosquare","334E"},
#line 3802 "pdfdoc/glyphlist.txt"
    {"tildedoublecmb","0360"},
#line 3799 "pdfdoc/glyphlist.txt"
    {"tildebelowcmb","0330"},
#line 2155 "pdfdoc/glyphlist.txt"
    {"hookabovecomb","0309"},
#line 3199 "pdfdoc/glyphlist.txt"
    {"qubutsquarterhebrew","05BB"},
#line 3804 "pdfdoc/glyphlist.txt"
    {"tildeoverlaycmb","0334"}
  };

static const short lookup[] =
  {
      -1,   -1,   -1,   -1,   -1,   -1,   -1,   -1,
      -1,   -1,   -1,   -1,   -1,   -1,   -1,   -1,
       0,   -1,   -1,   -1,   -1,   -1,   -1,   -1,
      -1,   -1,   -1,   -1,   -1,   -1,   -1,   -1,
      -1,   -1,   -1,   -1,   -1,   -1,   -1,   -1,
      -1,    1,   -1,   -1,   -1,   -1,   -1,   -1,
      -1,   -1,   -1,    2,    3,   -1,   -1,   -1,
      -1,    4,   -1,   -1,   -1,    5,   -1,   -1,
      -1,   -1,    6,   -1,   -1,   -1,   -1,   -1,
       7,   -1,   -1,   -1,    8,   -1,   -1,   -1,
      -1,   -1,   -1,   -1,   -1,   -1,   -1,    9,
      -1,   -1,   -1,   -1,   -1,   -1,   -1,   -1,
      -1,   -1,   10,   -1,   -1,   11,   12,   13,
      -1,   -1,   -1,   -1,   -1,   -1,   -1,   -1,
      14,   -1,   -1,   -1,   -1,   -1,   -1,   -1,
      -1,   -1,   -1,   -1,   -1,   -1,   -1,   -1,
      -1,   -1,   -1,   15,   -1,   -1,   -1,   -1,
      -1,   -1,   -1,   -1,   -1,   -1,   -1,   -1,
      -1,   -1,   -1,   16,   -1,   -1,   -1,   -1,
      -1,   -1,   -1,   -1,   17,   -1,   -1,   -1,
      -1,   18,   -1,   -1,   -1,   -1,   -1,   -1,
      -1,   -1,   -1,   -1,   -1,   -1,   -1,   -1,
      -1,   19,   -1,   -1,   -1,   -1,   -1,   -1,
      -1,   -1,   20,   21,   -1,   -1,   -1,   22,
      -1,   -1,   -1,   23,   24,   -1,   -1,   -1,
      -1,   25,   -1,   -1,   -1,   -1,   -1,   -1,
      -1,   -1,   -1,   26,   -1,   -1,   27,   -1,
      28,   -1,   -1,   -1,   29,   30,   -1,   -1,
      -1,   -1,   31,   -1,   -1,   -1,   -1,   32,
      -1,   -1,   -1,   -1,   33,   -1,   -1,   -1,
      -1,   34,   -1,   -1,   -1,   -1,   35,   -1,
      -1,   -1,   36,   -1,   -1,   -1,   -1,   37,
      38,   -1,   -1,   -1,   39,   40,   -1,   -1,
      -1,   41,   42,   43,   -1,   44,   45,   -1,
      -1,   -1,   -1,   -1,   -1,   46,   -1,   -1,
      47,   -1,   -1,   -1,   -1,   48,   -1,   -1,
      49,   -1,   50,   -1,   -1,   -1,   -1,   51,
      -1,   -1,   -1,   -1,   52,   -1,   -1,   -1,
      -1,   53,   54,   -1,   -1,   -1,   55,   -1,
      -1,   -1,   56,   57,   -1,   -1,   -1,   -1,
      58,   59,   -1,   -1,   -1,   60,   -1,   -1,
      -1,   -1,   -1,   -1,   -1,   61,   -1,   62,
      -1,   -1,   -1,   -1,   63,   -1,   -1,   -1,
      64,   -1,   -1,   -1,   -1,   -1,   65,   -1,
      -1,   66,   -1,   67,   68,   -1,   -1,   -1,
      69,   -1,   -1,   -1,   -1,   -1,   70,   -1,
      -1,   -1,   71,   -1,   -1,   -1,   -1,   72,
      -1,   -1,   -1,   -1,   -1,   -1,   -1,   73,
      -1,   -1,   74,   -1,   -1,   -1,   75,   76,
      -1,   -1,   -1,   -1,   -1,   77,   -1,   -1,
      -1,   -1,   -1,   -1,   -1,   -1,   -1,   -1,
      -1,   -1,   -1,   -1,   -1,   -1,   -1,   -1,
      -1,   -1,   -1,   -1,   -1,   -1,   -1,   -1,
      78,   -1,   -1,   -1,   -1,   -1,   -1,   -1,
      -1,   79,   80,   81,   -1,   -1,   -1,   -1,
      82,   83,   -1,   -1,   -1,   -1,   84,   -1,
      -1,   -1,   -1,   -1,   -1,   -1,   -1,   -1,
      -1,   -1,   -1,   -1,   -1,   -1,   -1,   -1,
      -1,   -1,   -1,   -1,   85,   -1,   86,   -1,
      -1,   -1,   -1,   -1,   -1,   -1,   -1,   -1,
      -1,   -1,   -1,   87,   -1,   -1,   -1,   -1,
      -1,   -1,   -1,   -1,   -1,   -1,   88,   -1,
      -1,   -1,   -1,   -1,   -1,   -1,   -1,   89,
      -1,   -1,   -1,   -1,   -1,   -1,   -1,   90,
      -1,   -1,   -1,   91,   -1,   -1,   -1,   -1,
      -1,   -1,   -1,   92,   -1,   93,   -1,   -1,
      -1,   94,   -1,   -1,   -1,   -1,   -1,   -1,
      -1,   -1,   -1,   -1,   -1,   -1,   -1,   -1,
      -1,   -1,   -1,   -1,   -1,   -1,   -1,   -1,
      -1,   -1,   -1,   -1,   -1,   -1,   -1,   -1,
      -1,   -1,   -1,   -1,   -1,   -1,   95,   -1,
      -1,   -1,   -1,   96,   -1,   97,   -1,   -1,
      -1,   -1,   -1,   98,   -1,   99,   -1,   -1,
      -1,   -1,  100,   -1,   -1,  101,   -1,  102,
      -1,   -1,   -1,  103,   -1,   -1,   -1,   -1,
      -1,   -1,   -1,   -1,   -1,   -1,   -1,   -1,
      -1,   -1,   -1,   -1,   -1,   -1,   -1,  104,
      -1,   -1,   -1,   -1,   -1,  105,   -1,   -1,
      -1,   -1,   -1,   -1,   -1,   -1,   -1,   -1,
      -1,   -1,   -1,   -1,   -1,   -1,   -1,   -1,
      -1,  106,   -1,   -1,   -1,  107,  108,   -1,
      -1,   -1,  109,  110,   -1,   -1,   -1,   -1,
     111,   -1,   -1,   -1,  112,   -1,   -1,   -1,
      -1,  113,   -1,   -1,   -1,   -1,  114,   -1,
      -1,   -1,   -1,  115,   -1,   -1,   -1,   -1,
      -1,   -1,   -1,   -1,   -1,   -1,   -1,   -1,
     116,   -1,   -1,   -1,  117,   -1,   -1,  118,
      -1,   -1,   -1,   -1,  119,   -1,   -1,   -1,
      -1,   -1,   -1,   -1,   -1,   -1,   -1,  120,
      -1,   -1,   -1,  121,   -1,  122,   -1,   -1,
      -1,   -1,  123,   -1,   -1,   -1,   -1,   -1,
      -1,   -1,   -1,   -1,   -1,   -1,   -1,   -1,
     124,   -1,   -1,   -1,   -1,  125,   -1,   -1,
      -1,   -1,   -1,  126,   -1,   -1,  127,   -1,
      -1,   -1,   -1,   -1,   -1,  128,   -1,   -1,
      -1,   -1,   -1,  129,   -1,   -1,   -1,  130,
      -1,   -1,   -1,   -1,  131,   -1,   -1,   -1,
     132,  133,   -1,   -1,   -1,   -1,   -1,   -1,
      -1,   -1,   -1,   -1,   -1,   -1,   -1,   -1,
      -1,   -1,   -1,   -1,   -1,   -1,   -1,   -1,
      -1,   -1,   -1,   -1,   -1,  134,  135,   -1,
      -1,   -1,   -1,  136,   -1,   -1,   -1,   -1,
      -1,   -1,   -1,   -1,   -1,   -1,   -1,   -1,
      -1,   -1,   -1,   -1,   -1,   -1,   -1,  137,
      -1,   -1,   -1,  138,   -1,   -1,   -1,   -1,
     139,   -1,   -1,   -1,   -1,   -1,   -1,   -1,
      -1,   -1,  140,   -1,   -1,   -1,  141,   -1,
      -1,   -1,   -1,   -1,   -1,   -1,   -1,   -1,
      -1,  142,   -1,  143,   -1,   -1,  144,   -1,
      -1,   -1,   -1,   -1,   -1,   -1,   -1,   -1,
      -1,   -1,   -1,   -1,   -1,   -1,   -1,   -1,
      -1,   -1,  145,   -1,   -1,   -1,  146,   -1,
      -1,   -1,   -1,  147,   -1,  148,   -1,   -1,
      -1,   -1,   -1,   -1,   -1,   -1,   -1,   -1,
      -1,   -1,  149,   -1,   -1,   -1,   -1,   -1,
      -1,   -1,   -1,   -1,   -1,   -1,   -1,   -1,
      -1,   -1,  150,  151,  152,  153,   -1,  154,
      -1,  155,   -1,   -1,   -1,   -1,  156,  157,
      -1,  158,   -1,   -1,   -1,  159,  160,   -1,
      -1,   -1,   -1,  161,  162,   -1,   -1,   -1,
     163,   -1,  164,   -1,   -1,  165,   -1,   -1,
     166,   -1,   -1,   -1,   -1,   -1,   -1,  167,
      -1,  168,  169,   -1,  170,   -1,   -1,   -1,
      -1,  171,   -1,   -1,   -1,   -1,   -1,   -1,
      -1,   -1,   -1,  172,   -1,   -1,   -1,   -1,
      -1,   -1,   -1,  173,   -1,   -1,   -1,   -1,
      -1,   -1,   -1,   -1,   -1,   -1,   -1,   -1,
      -1,   -1,   -1,   -1,   -1,   -1,   -1,   -1,
      -1,   -1,   -1,   -1,   -1,   -1,  174,   -1,
      -1,   -1,   -1,   -1,   -1,   -1,  175,   -1,
      -1,   -1,   -1,   -1,   -1,  176,   -1,   -1,
      -1,   -1,   -1,   -1,   -1,   -1,   -1,   -1,
      -1,   -1,  177,   -1,   -1,  178,   -1,   -1,
      -1,   -1,  179,   -1,   -1,   -1,   -1,   -1,
      -1,   -1,   -1,  180,   -1,   -1,   -1,   -1,
     181,   -1,   -1,   -1,   -1,   -1,   -1,   -1,
      -1,   -1,  182,   -1,   -1,  183,   -1,   -1,
     184,   -1,   -1,   -1,   -1,   -1,  185,   -1,
      -1,  186,   -1,  187,   -1,   -1,   -1,   -1,
      -1,   -1,   -1,   -1,   -1,   -1,   -1,   -1,
     188,   -1,  189,   -1,   -1,   -1,   -1,   -1,
     190,   -1,   -1,   -1,  191,  192,   -1,  193,
      -1,   -1,   -1,   -1,   -1,   -1,   -1,   -1,
      -1,   -1,   -1,   -1,   -1,   -1,  194,   -1,
      -1,   -1,  195,  196,   -1,   -1,  197,  198,
      -1,   -1,   -1,  199,   -1,  200,   -1,   -1,
      -1,   -1,  201,   -1,   -1,   -1,   -1,  202,
      -1,   -1,   -1,   -1,   -1,   -1,   -1,   -1,
      -1,   -1,   -1,   -1,   -1,   -1,   -1,   -1,
      -1,  203,  204,  205,   -1,   -1,   -1,   -1,
      -1,   -1,   -1,   -1,   -1,   -1,   -1,   -1,
      -1,   -1,   -1,   -1,   -1,   -1,   -1,  206,
      -1,   -1,   -1,   -1,   -1,   -1,   -1,   -1,
      -1,   -1,   -1,   -1,   -1,   -1,   -1,   -1,
      -1,   -1,   -1,   -1,   -1,   -1,   -1,   -1,
      -1,   -1,   -1,  207,   -1,   -1,   -1,   -1,
      -1,   -1,   -1,   -1,   -1,   -1,   -1,  208,
      -1,   -1,   -1,   -1,   -1,   -1,   -1,   -1,
      -1,   -1,   -1,   -1,   -1,   -1,   -1,   -1,
      -1,   -1,   -1,   -1,   -1,   -1,   -1,   -1,
      -1,   -1,   -1,   -1,   -1,   -1,   -1,  209,
      -1,  210,  211,   -1,  212,   -1,   -1,   -1,
     213,   -1,   -1,   -1,   -1,  214,   -1,   -1,
      -1,   -1,  215,   -1,   -1,   -1,  216,   -1,
      -1,   -1,   -1,  217,   -1,   -1,   -1,   -1,
      -1,   -1,   -1,   -1,   -1,  218,   -1,   -1,
      -1,   -1,  219,   -1,   -1,   -1,  220,  221,
      -1,  222,  223,   -1,   -1,   -1,  224,   -1,
      -1,   -1,   -1,   -1,   -1,   -1,   -1,   -1,
      -1,   -1,  225,   -1,   -1,   -1,   -1,   -1,
      -1,   -1,  226,   -1,   -1,  227,   -1,   -1,
      -1,   -1,   -1,   -1,   -1,  228,   -1,  229,
      -1,   -1,   -1,   -1,   -1,   -1,   -1,  230,
      -1,   -1,   -1,  231,   -1,   -1,   -1,   -1,
     232,   -1,  233,   -1,   -1,   -1,   -1,  234,
      -1,   -1,   -1,   -1,   -1,   -1,   -1,   -1,
      -1,   -1,   -1,   -1,   -1,   -1,   -1,   -1,
     235,   -1,   -1,   -1,   -1,   -1,   -1,   -1,
      -1,   -1,   -1,   -1,   -1,   -1,  236,   -1,
      -1,   -1,   -1,   -1,  237,   -1,  238,   -1,
      -1,   -1,   -1,   -1,   -1,   -1,   -1,  239,
      -1,   -1,   -1,   -1,  240,   -1,  241,   -1,
      -1,  242,   -1,   -1,   -1,  243,  244,   -1,
      -1,   -1,   -1,  245,   -1,   -1,   -1,   -1,
     246,  247,   -1,   -1,   -1,  248,   -1,   -1,
      -1,   -1,  249,  250,   -1,   -1,  251,  252,
      -1,   -1,   -1,   -1,  253,  254,  255,   -1,
      -1,  256,   -1,   -1,   -1,   -1,  257,  258,
      -1,   -1,   -1,  259,   -1,   -1,   -1,   -1,
      -1,  260,   -1,   -1,  261,  262,   -1,   -1,
      -1,   -1,  263,   -1,   -1,   -1,   -1,   -1,
      -1,   -1,   -1,   -1,   -1,   -1,   -1,   -1,
      -1,   -1,   -1,   -1,  264,   -1,   -1,   -1,
      -1,   -1,  265,   -1,   -1,   -1,   -1,   -1,
     266,   -1,  267,   -1,   -1,   -1,  268,   -1,
      -1,   -1,   -1,   -1,   -1,   -1,   -1,   -1,
      -1,  269,   -1,   -1,  270,   -1,   -1,   -1,
      -1,  271,   -1,   -1,   -1,   -1,  272,  273,
      -1,   -1,   -1,   -1,   -1,   -1,   -1,   -1,
     274,   -1,   -1,  275,   -1,   -1,   -1,   -1,
      -1,   -1,  276,   -1,   -1,   -1,   -1,   -1,
     277,   -1,   -1,  278,   -1,   -1,   -1,   -1,
      -1,   -1,   -1,   -1,   -1,   -1,  279,   -1,
      -1,   -1,   -1,   -1,   -1,   -1,   -1,   -1,
      -1,  280,   -1,   -1,   -1,   -1,  281,   -1,
     282,   -1,  283,   -1,   -1,   -1,   -1,   -1,
      -1,   -1,   -1,   -1,  284,   -1,   -1,   -1,
      -1,   -1,   -1,   -1,   -1,   -1,   -1,   -1,
     285,  286,   -1,   -1,   -1,   -1,   -1,   -1,
     287,  288,   -1,   -1,   -1,   -1,   -1,   -1,
      -1,   -1,   -1,   -1,   -1,   -1,   -1,   -1,
      -1,   -1,   -1,   -1,   -1,   -1,   -1,   -1,
      -1,   -1,   -1,   -1,   -1,  289,   -1,   -1,
      -1,   -1,  290,   -1,   -1,   -1,   -1,   -1,
      -1,   -1,   -1,   -1,   -1,   -1,   -1,   -1,
      -1,   -1,   -1,   -1,   -1,   -1,   -1,   -1,
      -1,   -1,   -1,   -1,   -1,  291,   -1,   -1,
      -1,   -1,   -1,   -1,   -1,   -1,   -1,  292,
     293,  294,   -1,   -1,   -1,   -1,   -1,  295,
      -1,   -1,   -1,   -1,   -1,   -1,   -1,   -1,
     296,   -1,   -1,   -1,  297,  298,   -1,   -1,
      -1,  299,  300,   -1,   -1,   -1,   -1,   -1,
      -1,   -1,   -1,  301,   -1,   -1,   -1,   -1,
     302,   -1,   -1,   -1,   -1,   -1,   -1,   -1,
      -1,   -1,  303,   -1,   -1,   -1,   -1,  304,
      -1,  305,   -1,   -1,  306,   -1,   -1,   -1,
      -1,   -1,  307,  308,   -1,   -1,   -1,  309,
      -1,   -1,   -1,   -1,  310,  311,   -1,   -1,
      -1,   -1,  312,   -1,   -1,   -1,  313,   -1,
     314,   -1,   -1,  315,  316,   -1,   -1,   -1,
     317,  318,   -1,   -1,   -1,   -1,  319,   -1,
     320,   -1,   -1,  321,   -1,   -1,   -1,   -1,
     322,   -1,   -1,   -1,   -1,  323,   -1,   -1,
      -1,   -1,   -1,   -1,   -1,  324,   -1,   -1,
      -1,   -1,   -1,   -1,  325,   -1,   -1,   -1,
      -1,   -1,  326,   -1,   -1,   -1,   -1,   -1,
      -1,   -1,   -1,   -1,   -1,   -1,   -1,  327,
      -1,   -1,   -1,   -1,   -1,   -1,   -1,   -1,
      -1,   -1,  328,  329,   -1,   -1,   -1,   -1,
      -1,   -1,   -1,   -1,   -1,   -1,   -1,   -1,
     330,   -1,   -1,  331,  332,   -1,  333,   -1,
      -1,   -1,  334,  335,   -1,   -1,   -1,   -1,
     336,  337,   -1,   -1,   -1,   -1,   -1,   -1,
      -1,   -1,  338,   -1,   -1,   -1,   -1,  339,
      -1,  340,   -1,   -1,  341,   -1,   -1,   -1,
      -1,   -1,   -1,   -1,   -1,   -1,  342,   -1,
      -1,   -1,   -1,   -1,   -1,   -1,   -1,   -1,
     343,   -1,  344,   -1,   -1,   -1,   -1,   -1,
      -1,  345,   -1,   -1,   -1,  346,   -1,  347,
     348,   -1,   -1,   -1,   -1,   -1,   -1,  349,
      -1,   -1,  350,   -1,   -1,   -1,   -1,  351,
      -1,   -1,   -1,   -1,   -1,   -1,   -1,   -1,
      -1,   -1,  352,   -1,   -1,   -1,   -1,   -1,
      -1,   -1,  353,   -1,   -1,   -1,   -1,   -1,
      -1,   -1,   -1,   -1,   -1,   -1,   -1,   -1,
      -1,   -1,   -1,   -1,   -1,   -1,   -1,   -1,
      -1,   -1,   -1,   -1,   -1,   -1,   -1,   -1,
      -1,   -1,   -1,   -1,   -1,   -1,   -1,   -1,
      -1,   -1,   -1,  354,   -1,   -1,   -1,   -1,
     355,   -1,   -1,   -1,   -1,   -1,   -1,   -1,
      -1,   -1,   -1,   -1,   -1,   -1,   -1,   -1,
      -1,   -1,   -1,   -1,  356,   -1,  357,   -1,
      -1,   -1,   -1,   -1,   -1,   -1,   -1,   -1,
      -1,   -1,  358,   -1,   -1,   -1,   -1,   -1,
      -1,   -1,   -1,   -1,   -1,   -1,   -1,   -1,
      -1,   -1,   -1,  359,   -1,   -1,   -1,  360,
      -1,  361,   -1,   -1,   -1,   -1,   -1,   -1,
      -1,   -1,   -1,   -1,   -1,   -1,   -1,   -1,
      -1,  362,   -1,   -1,   -1,   -1,   -1,   -1,
      -1,   -1,   -1,   -1,  363,   -1,  364,   -1,
     365,   -1,   -1,   -1,   -1,   -1,   -1,   -1,
      -1,   -1,   -1,   -1,   -1,   -1,   -1,   -1,
     366,  367,   -1,  368,   -1,  369,   -1,   -1,
      -1,   -1,  370,   -1,  371,  372,   -1,  373,
     374,  375,   -1,   -1,  376,   -1,   -1,   -1,
      -1,   -1,  377,   -1,   -1,   -1,   -1,   -1,
     378,   -1,   -1,   -1,   -1,   -1,   -1,   -1,
      -1,   -1,   -1,   -1,   -1,  379,   -1,   -1,
      -1,   -1,  380,   -1,   -1,   -1,  381,   -1,
      -1,   -1,   -1,   -1,   -1,   -1,   -1,   -1,
      -1,  382,   -1,   -1,   -1,   -1,   -1,   -1,
      -1,   -1,  383,   -1,  384,   -1,   -1,   -1,
      -1,   -1,   -1,   -1,   -1,  385,   -1,   -1,
      -1,   -1,   -1,   -1,   -1,   -1,   -1,   -1,
      -1,   -1,   -1,  386,   -1,  387,   -1,   -1,
      -1,   -1,   -1,   -1,  388,   -1,   -1,   -1,
      -1,  389,   -1,  390,   -1,   -1,   -1,  391,
     392,  393,   -1,  394,   -1,   -1,  395,   -1,
     396,   -1,   -1,   -1,   -1,  397,   -1,   -1,
      -1,   -1,   -1,   -1,  398,   -1,   -1,   -1,
      -1,   -1,   -1,   -1,   -1,   -1,   -1,   -1,
      -1,   -1,   -1,   -1,   -1,   -1,   -1,   -1,
      -1,  399,  400,  401,   -1,   -1,   -1,   -1,
      -1,   -1,   -1,   -1,  402,   -1,   -1,   -1,
      -1,   -1,   -1,  403,  404,  405,   -1,   -1,
      -1,   -1,   -1,   -1,   -1,   -1,  406,   -1,
      -1,   -1,   -1,   -1,   -1,  407,   -1,   -1,
      -1,   -1,   -1,   -1,   -1,   -1,  408,   -1,
      -1,   -1,   -1,   -1,   -1,   -1,   -1,   -1,
      -1,   -1,   -1,   -1,   -1,   -1,   -1,  409,
      -1,   -1,   -1,   -1,   -1,   -1,   -1,   -1,
     410,   -1,  411,   -1,   -1,   -1,   -1,   -1,
     412,   -1,   -1,   -1,   -1,  413,   -1,   -1,
      -1,   -1,  414,   -1,   -1,   -1,   -1,   -1,
      -1,   -1,   -1,   -1,   -1,   -1,   -1,   -1,
      -1,   -1,   -1,   -1,   -1,   -1,   -1,   -1,
      -1,   -1,   -1,   -1,   -1,   -1,   -1,   -1,
      -1,   -1,   -1,   -1,   -1,   -1,   -1,   -1,
      -1,   -1,   -1,   -1,   -1,   -1,   -1,   -1,
      -1,   -1,   -1,   -1,   -1,  415,   -1,   -1,
     416,   -1,   -1,   -1,   -1,   -1,   -1,   -1,
      -1,   -1,   -1,   -1,   -1,   -1,   -1,   -1,
      -1,   -1,   -1,   -1,   -1,   -1,   -1,   -1,
      -1,   -1,   -1,   -1,   -1,   -1,   -1,   -1,
     417,   -1,   -1,   -1,   -1,   -1,   -1,   -1,
      -1,   -1,   -1,   -1,   -1,   -1,   -1,   -1,
      -1,   -1,   -1,   -1,   -1,   -1,   -1,   -1,
      -1,   -1,   -1,  418,   -1,   -1,   -1,   -1,
      -1,  419,  420,   -1,   -1,   -1,   -1,   -1,
      -1,   -1,   -1,   -1,   -1,   -1,  421,   -1,
      -1,   -1,   -1,  422,   -1,   -1,   -1,   -1,
     423,   -1,   -1,   -1,   -1,   -1,   -1,   -1,
     424,   -1,   -1,   -1,   -1,   -1,   -1,   -1,
      -1,   -1,   -1,  425,   -1,   -1,   -1,  426,
      -1,   -1,   -1,   -1,   -1,  427,   -1,   -1,
      -1,   -1,   -1,   -1,   -1,   -1,   -1,   -1,
      -1,   -1,   -1,  428,   -1,   -1,   -1,   -1,
      -1,   -1,   -1,   -1,   -1,  429,   -1,   -1,
      -1,   -1,   -1,   -1,  430,   -1,   -1,   -1,
      -1,   -1,   -1,  431,   -1,   -1,   -1,  432,
      -1,   -1,   -1,   -1,   -1,   -1,   -1,   -1,
      -1,   -1,   -1,   -1,   -1,   -1,   -1,   -1,
      -1,   -1,   -1,   -1,   -1,   -1,   -1,   -1,
      -1,   -1,  433,   -1,   -1,   -1,  434,   -1,
     435,  436,   -1,   -1,   -1,   -1,  437,  438,
      -1,  439,   -1,   -1,   -1,   -1,   -1,   -1,
      -1,   -1,   -1,   -1,   -1,   -1,   -1,   -1,
     440,   -1,   -1,   -1,   -1,   -1,   -1,   -1,
      -1,  441,   -1,   -1,   -1,  442,   -1,  443,
      -1,   -1,   -1,   -1,  444,   -1,   -1,   -1,
      -1,   -1,  445,   -1,   -1,   -1,   -1,   -1,
      -1,   -1,   -1,  446,   -1,   -1,   -1,   -1,
     447,   -1,   -1,   -1,   -1,   -1,   -1,   -1,
      -1,   -1,   -1,   -1,   -1,   -1,   -1,   -1,
      -1,   -1,   -1,   -1,  448,   -1,   -1,   -1,
      -1,   -1,   -1,   -1,   -1,   -1,  449,   -1,
      -1,   -1,   -1,  450,   -1,   -1,   -1,   -1,
      -1,   -1,   -1,   -1,   -1,  451,   -1,   -1,
      -1,   -1,   -1,   -1,   -1,  452,   -1,   -1,
      -1,   -1,   -1,   -1,  453,   -1,   -1,   -1,
      -1,   -1,   -1,   -1,   -1,   -1,  454,   -1,
      -1,   -1,   -1,   -1,   -1,   -1,   -1,   -1,
      -1,   -1,   -1,   -1,   -1,  455,   -1,   -1,
      -1,   -1,   -1,   -1,   -1,   -1,   -1,   -1,
      -1,   -1,   -1,   -1,  456,   -1,   -1,   -1,
      -1,   -1,  457,   -1,   -1,   -1,   -1,   -1,
      -1,   -1,   -1,   -1,   -1,   -1,   -1,   -1,
      -1,  458,   -1,   -1,   -1,   -1,  459,   -1,
      -1,   -1,  460,   -1,   -1,   -1,   -1,   -1,
     461,   -1,   -1,   -1,   -1,   -1,   -1,   -1,
      -1,   -1,   -1,   -1,   -1,   -1,   -1,   -1,
     462,   -1,   -1,   -1,   -1,  463,   -1,  464,
     465,   -1,   -1,   -1,   -1,   -1,  466,   -1,
      -1,   -1,   -1,   -1,   -1,   -1,   -1,   -1,
      -1,   -1,   -1,   -1,   -1,   -1,   -1,   -1,
      -1,  467,   -1,   -1,   -1,   -1,   -1,   -1,
      -1,   -1,   -1,  468,  469,   -1,   -1,   -1,
     470,   -1,   -1,   -1,   -1,  471,   -1,   -1,
      -1,   -1,  472,   -1,   -1,   -1,   -1,  473,
      -1,  474,   -1,   -1,  475,   -1,   -1,   -1,
      -1,   -1,   -1,   -1,   -1,   -1,   -1,   -1,
      -1,  476,   -1,   -1,   -1,   -1,   -1,   -1,
      -1,   -1,   -1,  477,   -1,   -1,   -1,   -1,
      -1,   -1,   -1,   -1,  478,   -1,   -1,   -1,
      -1,   -1,   -1,   -1,   -1,   -1,   -1,   -1,
      -1,   -1,   -1,   -1,   -1,   -1,   -1,   -1,
     479,   -1,   -1,  480,  481,   -1,   -1,   -1,
      -1,   -1,   -1,   -1,   -1,   -1,   -1,  482,
     483,   -1,   -1,   -1,   -1,   -1,   -1,   -1,
      -1,   -1,   -1,   -1,  484,   -1,   -1,   -1,
      -1,  485,   -1,   -1,   -1,   -1,   -1,   -1,
      -1,   -1,   -1,  486,   -1,   -1,  487,   -1,
      -1,   -1,   -1,   -1,   -1,   -1,   -1,   -1,
      -1,   -1,   -1,  488,   -1,   -1,   -1,  489,
     490,   -1,   -1,  491,   -1,   -1,   -1,   -1,
      -1,  492,   -1,  493,   -1,   -1,   -1,  494,
      -1,   -1,   -1,   -1,   -1,   -1,   -1,   -1,
      -1,   -1,   -1,   -1,   -1,   -1,   -1,   -1,
      -1,   -1,   -1,   -1,   -1,   -1,   -1,   -1,
      -1,   -1,   -1,   -1,   -1,   -1,   -1,   -1,
      -1,  495,   -1,   -1,   -1,  496,  497,   -1,
      -1,   -1,   -1,  498,   -1,   -1,   -1,   -1,
      -1,   -1,   -1,   -1,   -1,   -1,   -1,   -1,
     499,   -1,  500,   -1,   -1,   -1,   -1,  501,
      -1,   -1,   -1,   -1,   -1,   -1,   -1,  502,
      -1,   -1,   -1,   -1,   -1,  503,  504,   -1,
      -1,   -1,   -1,   -1,   -1,   -1,   -1,   -1,
     505,   -1,   -1,   -1,   -1,   -1,   -1,   -1,
     506,   -1,   -1,   -1,   -1,   -1,   -1,   -1,
      -1,   -1,   -1,   -1,   -1,   -1,   -1,   -1,
      -1,   -1,   -1,   -1,   -1,   -1,   -1,   -1,
      -1,   -1,  507,  508,   -1,   -1,   -1,  509,
     510,   -1,   -1,   -1,   -1,  511,   -1,  512,
     513,  514,  515,   -1,   -1,   -1,  516,  517,
     518,  519,  520,  521,   -1,   -1,   -1,   -1,
      -1,  522,   -1,  523,   -1,   -1,   -1,   -1,
      -1,  524,   -1,   -1,   -1,   -1,  525,   -1,
      -1,  526,   -1,  527,   -1,  528,   -1,  529,
     530,   -1,   -1,   -1,   -1,   -1,  531,   -1,
      -1,   -1,   -1,  532,  533,   -1,   -1,  534,
     535,   -1,   -1,   -1,   -1,   -1,   -1,   -1,
      -1,   -1,   -1,   -1,   -1,   -1,   -1,   -1,
      -1,   -1,   -1,   -1,   -1,  536,   -1,   -1,
      -1,  537,   -1,   -1,   -1,   -1,  538,  539,
      -1,  540,   -1,   -1,   -1,   -1,   -1,   -1,
      -1,  541,   -1,   -1,   -1,   -1,   -1,   -1,
      -1,  542,  543,   -1,   -1,   -1,   -1,   -1,
      -1,   -1,   -1,   -1,   -1,   -1,   -1,   -1,
      -1,  544,   -1,  545,  546,  547,   -1,   -1,
      -1,   -1,  548,   -1,   -1,   -1,   -1,  549,
      -1,   -1,   -1,   -1,   -1,   -1,   -1,   -1,
      -1,   -1,  550,   -1,   -1,   -1,  551,  552,
      -1,  553,   -1,   -1,   -1,  554,   -1,   -1,
     555,   -1,   -1,   -1,   -1,   -1,   -1,  556,
      -1,   -1,   -1,   -1,   -1,   -1,   -1,  557,
      -1,   -1,   -1,   -1,  558,   -1,   -1,   -1,
     559,   -1,   -1,   -1,   -1,   -1,  560,   -1,
      -1,   -1,   -1,  561,   -1,   -1,   -1,   -1,
      -1,   -1,   -1,   -1,   -1,   -1,   -1,   -1,
      -1,   -1,   -1,  562,   -1,   -1,  563,   -1,
      -1,   -1,   -1,   -1,   -1,  564,   -1,   -1,
      -1,   -1,  565,  566,   -1,   -1,   -1,   -1,
      -1,   -1,   -1,   -1,   -1,   -1,   -1,   -1,
      -1,   -1,   -1,  567,   -1,   -1,   -1,   -1,
      -1,   -1,   -1,   -1,  568,   -1,   -1,   -1,
      -1,   -1,   -1,   -1,  569,   -1,   -1,   -1,
      -1,   -1,   -1,   -1,   -1,   -1,   -1,   -1,
     570,  571,   -1,   -1,   -1,  572,   -1,  573,
     574,   -1,   -1,   -1,   -1,   -1,   -1,   -1,
      -1,   -1,   -1,   -1,   -1,   -1,   -1,   -1,
     575,   -1,   -1,   -1,   -1,   -1,   -1,   -1,
      -1,   -1,   -1,   -1,   -1,   -1,   -1,   -1,
     576,   -1,   -1,   -1,   -1,   -1,   -1,   -1,
      -1,   -1,   -1,   -1,   -1,   -1,   -1,   -1,
      -1,   -1,  577,   -1,   -1,   -1,   -1,   -1,
      -1,   -1,   -1,   -1,   -1,   -1,   -1,   -1,
      -1,   -1,   -1,   -1,   -1,   -1,   -1,   -1,
      -1,   -1,   -1,   -1,   -1,   -1,  578,   -1,
      -1,   -1,   -1,   -1,   -1,   -1,   -1,   -1,
     579,   -1,   -1,   -1,   -1,   -1,   -1,   -1,
     580,   -1,  581,   -1,   -1,   -1,   -1,   -1,
      -1,   -1,   -1,   -1,   -1,  582,   -1,   -1,
     583,  584,   -1,   -1,   -1,   -1,  585,   -1,
     586,  587,  588,   -1,   -1,   -1,   -1,  589,
      -1,   -1,   -1,   -1,   -1,   -1,   -1,   -1,
      -1,  590,   -1,   -1,   -1,   -1,   -1,   -1,
      -1,   -1,   -1,   -1,   -1,   -1,   -1,   -1,
     591,   -1,  592,   -1,   -1,  593,   -1,   -1,
      -1,   -1,   -1,   -1,   -1,   -1,   -1,  594,
      -1,   -1,   -1,   -1,   -1,   -1,   -1,   -1,
      -1,   -1,   -1,   -1,   -1,  595,   -1,   -1,
      -1,   -1,   -1,  596,   -1,   -1,   -1,   -1,
      -1,   -1,   -1,   -1,   -1,   -1,   -1,   -1,
      -1,   -1,   -1,   -1,   -1,   -1,   -1,   -1,
      -1,   -1,   -1,   -1,   -1,   -1,   -1,  597,
      -1,   -1,   -1,   -1,   -1,   -1,   -1,   -1,
      -1,   -1,   -1,  598,   -1,   -1,   -1,   -1,
     599,   -1,   -1,   -1,   -1,  600,   -1,   -1,
      -1,   -1,  601,   -1,   -1,   -1,   -1,  602,
      -1,   -1,   -1,   -1,  603,   -1,   -1,   -1,
      -1,  604,   -1,   -1,   -1,  605,  606,   -1,
      -1,   -1,   -1,   -1,   -1,   -1,   -1,  607,
      -1,   -1,   -1,   -1,   -1,   -1,  608,  609,
      -1,   -1,  610,   -1,   -1,   -1,   -1,  611,
      -1,   -1,   -1,   -1,   -1,   -1,   -1,   -1,
      -1,  612,   -1,   -1,   -1,   -1,  613,   -1,
     614,  615,  616,   -1,   -1,   -1,   -1,  617,
      -1,   -1,   -1,   -1,   -1,   -1,   -1,   -1,
     618,  619,   -1,   -1,   -1,   -1,  620,   -1,
     621,   -1,   -1,  622,   -1,   -1,   -1,   -1,
      -1,  623,   -1,   -1,   -1,   -1,   -1,   -1,
      -1,   -1,   -1,   -1,   -1,   -1,   -1,  624,
      -1,  625,   -1,   -1,   -1,   -1,   -1,  626,
      -1,   -1,   -1,   -1,   -1,   -1,  627,  628,
      -1,   -1,   -1,  629,   -1,   -1,   -1,   -1,
     630,   -1,   -1,  631,   -1,   -1,   -1,   -1,
      -1,   -1,  632,  633,   -1,   -1,   -1,  634,
      -1,   -1,   -1,   -1,  635,   -1,   -1,   -1,
      -1,   -1,   -1,   -1,   -1,   -1,   -1,  636,
      -1,   -1,   -1,   -1,  637,   -1,   -1,   -1,
      -1,   -1,   -1,   -1,   -1,   -1,   -1,   -1,
      -1,   -1,   -1,   -1,  638,   -1,   -1,   -1,
      -1,   -1,   -1,   -1,   -1,  639,  640,   -1,
      -1,   -1,   -1,   -1,   -1,   -1,   -1,   -1,
      -1,   -1,   -1,   -1,  641,   -1,   -1,   -1,
      -1,   -1,   -1,   -1,   -1,  642,   -1,   -1,
      -1,   -1,   -1,  643,   -1,   -1,  644,   -1,
      -1,   -1,   -1,   -1,   -1,  645,   -1,   -1,
      -1,   -1,   -1,   -1,   -1,   -1,   -1,   -1,
      -1,   -1,   -1,   -1,  646,   -1,   -1,  647,
      -1,   -1,   -1,   -1,   -1,   -1,  648,   -1,
      -1,   -1,   -1,   -1,   -1,   -1,  649,   -1,
      -1,   -1,   -1,  650,   -1,   -1,   -1,   -1,
      -1,   -1,   -1,   -1,   -1,   -1,   -1,   -1,
      -1,   -1,   -1,   -1,   -1,   -1,   -1,   -1,
     651,  652,   -1,   -1,   -1,   -1,   -1,   -1,
      -1,   -1,   -1,   -1,   -1,   -1,  653,   -1,
      -1,   -1,   -1,   -1,   -1,   -1,   -1,   -1,
      -1,   -1,   -1,   -1,   -1,   -1,   -1,   -1,
      -1,   -1,   -1,   -1,   -1,   -1,   -1,   -1,
     654,  655,   -1,   -1,   -1,   -1,  656,   -1,
     657,   -1,   -1,  658,   -1,   -1,   -1,   -1,
      -1,   -1,   -1,   -1,   -1,   -1,   -1,   -1,
      -1,   -1,  659,   -1,   -1,   -1,   -1,   -1,
      -1,  660,   -1,  661,   -1,   -1,  662,   -1,
      -1,   -1,   -1,   -1,   -1,   -1,   -1,   -1,
      -1,   -1,   -1,   -1,   -1,  663,  664,   -1,
      -1,   -1,   -1,   -1,   -1,   -1,   -1,   -1,
      -1,   -1,  665,   -1,   -1,   -1,   -1,  666,
      -1,   -1,   -1,   -1,   -1,   -1,   -1,   -1,
      -1,   -1,   -1,   -1,   -1,   -1,   -1,   -1,
      -1,   -1,   -1,   -1,   -1,   -1,   -1,   -1,
      -1,   -1,   -1,   -1,   -1,   -1,  667,  668,
      -1,   -1,  669,  670,   -1,   -1,   -1,  671,
      -1,   -1,   -1,   -1,  672,   -1,   -1,   -1,
      -1,   -1,   -1,   -1,   -1,   -1,  673,   -1,
      -1,   -1,   -1,   -1,   -1,   -1,   -1,  674,
      -1,   -1,   -1,  675,   -1,   -1,   -1,   -1,
      -1,   -1,   -1,   -1,   -1,   -1,   -1,   -1,
      -1,   -1,   -1,   -1,   -1,   -1,   -1,   -1,
      -1,   -1,   -1,  676,   -1,   -1,   -1,   -1,
      -1,   -1,   -1,   -1,   -1,   -1,   -1,   -1,
      -1,   -1,   -1,   -1,  677,   -1,   -1,   -1,
      -1,  678,   -1,   -1,   -1,   -1,   -1,   -1,
      -1,   -1,   -1,  679,  680,  681,   -1,   -1,
     682,   -1,   -1,   -1,   -1,  683,   -1,   -1,
      -1,   -1,  684,  685,   -1,   -1,   -1,   -1,
      -1,   -1,   -1,   -1,   -1,   -1,   -1,   -1,
      -1,   -1,   -1,   -1,   -1,   -1,   -1,   -1,
      -1,   -1,   -1,   -1,   -1,   -1,   -1,   -1,
     686,  687,   -1,   -1,  688,  689,   -1,   -1,
      -1,   -1,   -1,  690,  691,   -1,   -1,   -1,
      -1,   -1,   -1,   -1,   -1,   -1,   -1,   -1,
      -1,   -1,   -1,   -1,   -1,   -1,   -1,   -1,
      -1,   -1,   -1,   -1,   -1,   -1,   -1,   -1,
      -1,  692,   -1,   -1,   -1,  693,  694,   -1,
      -1,  695,   -1,   -1,   -1,   -1,   -1,   -1,
      -1,   -1,   -1,  696,   -1,   -1,   -1,   -1,
      -1,   -1,   -1,   -1,   -1,   -1,  697,  698,
      -1,   -1,   -1,   -1,   -1,  699,   -1,   -1,
      -1,  700,   -1,   -1,   -1,   -1,   -1,   -1,
      -1,   -1,   -1,   -1,   -1,   -1,   -1,   -1,
      -1,   -1,   -1,   -1,  701,   -1,   -1,   -1,
      -1,   -1,   -1,  702,   -1,   -1,  703,   -1,
      -1,  704,   -1,   -1,   -1,   -1,   -1,   -1,
      -1,   -1,   -1,  705,   -1,  706,   -1,   -1,
      -1,   -1,   -1,   -1,   -1,   -1,   -1,   -1,
     707,   -1,   -1,   -1,   -1,   -1,   -1,   -1,
      -1,  708,  709,   -1,   -1,  710,  711,   -1,
      -1,   -1,   -1,  712,   -1,   -1,   -1,   -1,
     713,   -1,  714,   -1,   -1,   -1,   -1,   -1,
     715,  716,  717,   -1,   -1,   -1,   -1,  718,
      -1,   -1,   -1,   -1,  719,   -1,   -1,   -1,
      -1,   -1,   -1,  720,   -1,   -1,  721,   -1,
      -1,   -1,  722,  723,  724,   -1,   -1,  725,
      -1,   -1,   -1,   -1,   -1,   -1,   -1,   -1,
      -1,   -1,   -1,   -1,   -1,  726,   -1,   -1,
      -1,   -1,   -1,   -1,   -1,  727,   -1,   -1,
      -1,   -1,   -1,  728,   -1,   -1,   -1,   -1,
      -1,   -1,   -1,   -1,   -1,   -1,   -1,   -1,
      -1,   -1,   -1,   -1,   -1,   -1,   -1,   -1,
      -1,  729,   -1,   -1,   -1,   -1,   -1,   -1,
      -1,   -1,   -1,   -1,   -1,   -1,   -1,   -1,
      -1,   -1,   -1,   -1,   -1,   -1,   -1,   -1,
      -1,   -1,   -1,   -1,   -1,   -1,   -1,   -1,
      -1,   -1,   -1,   -1,   -1,   -1,   -1,   -1,
      -1,   -1,   -1,   -1,   -1,   -1,   -1,   -1,
      -1,   -1,   -1,   -1,   -1,   -1,   -1,   -1,
     730,   -1,  731,   -1,   -1,   -1,   -1,   -1,
     732,   -1,   -1,   -1,   -1,   -1,   -1,   -1,
      -1,   -1,   -1,   -1,   -1,   -1,  733,   -1,
      -1,   -1,   -1,   -1,  734,   -1,   -1,   -1,
      -1,   -1,   -1,   -1,   -1,   -1,   -1,  735,
      -1,   -1,   -1,   -1,   -1,   -1,  736,   -1,
      -1,   -1,   -1,   -1,   -1,   -1,   -1,   -1,
     737,   -1,   -1,  738,   -1,   -1,  739,   -1,
      -1,   -1,   -1,   -1,   -1,   -1,   -1,   -1,
     740,   -1,   -1,   -1,   -1,   -1,   -1,   -1,
      -1,  741,   -1,   -1,   -1,   -1,  742,   -1,
      -1,   -1,   -1,  743,   -1,  744,   -1,   -1,
     745,  746,   -1,   -1,   -1,  747,   -1,   -1,
      -1,   -1,  748,   -1,   -1,   -1,  749,  750,
      -1,  751,   -1,   -1,  752,   -1,   -1,   -1,
      -1,  753,   -1,   -1,   -1,   -1,  754,   -1,
      -1,   -1,   -1,  755,   -1,   -1,   -1,   -1,
     756,   -1,   -1,   -1,   -1,  757,   -1,   -1,
     758,   -1,  759,   -1,   -1,   -1,  760,   -1,
      -1,   -1,   -1,   -1,   -1,   -1,   -1,   -1,
      -1,  761,   -1,   -1,   -1,   -1,   -1,   -1,
      -1,   -1,   -1,   -1,   -1,   -1,   -1,   -1,
      -1,   -1,   -1,   -1,   -1,   -1,   -1,  762,
      -1,   -1,   -1,  763,   -1,   -1,   -1,  764,
     765,   -1,   -1,   -1,   -1,  766,  767,   -1,
      -1,   -1,   -1,   -1,   -1,   -1,   -1,   -1,
      -1,   -1,   -1,  768,   -1,   -1,   -1,   -1,
     769,   -1,   -1,   -1,   -1,  770,   -1,   -1,
      -1,  771,  772,  773,   -1,   -1,   -1,  774,
      -1,   -1,  775,   -1,   -1,   -1,   -1,   -1,
      -1,  776,   -1,   -1,   -1,   -1,   -1,   -1,
      -1,  777,   -1,   -1,   -1,   -1,   -1,   -1,
     778,   -1,   -1,   -1,   -1,  779,   -1,   -1,
      -1,   -1,   -1,   -1,   -1,   -1,   -1,   -1,
      -1,   -1,   -1,   -1,   -1,   -1,   -1,   -1,
      -1,  780,   -1,   -1,   -1,   -1,   -1,   -1,
      -1,   -1,   -1,  781,   -1,   -1,   -1,   -1,
      -1,   -1,   -1,   -1,   -1,  782,   -1,   -1,
      -1,   -1,  783,   -1,   -1,   -1,   -1,  784,
      -1,   -1,   -1,   -1,  785,   -1,   -1,  786,
      -1,  787,   -1,   -1,   -1,   -1,  788,  789,
      -1,   -1,  790,   -1,   -1,   -1,   -1,   -1,
      -1,   -1,   -1,   -1,   -1,   -1,   -1,   -1,
      -1,   -1,   -1,   -1,   -1,   -1,  791,   -1,
     792,   -1,   -1,   -1,  793,   -1,  794,   -1,
      -1,  795,   -1,   -1,   -1,   -1,   -1,   -1,
      -1,   -1,   -1,   -1,   -1,  796,   -1,   -1,
      -1,   -1,   -1,   -1,   -1,   -1,   -1,   -1,
      -1,   -1,   -1,   -1,   -1,   -1,   -1,   -1,
      -1,   -1,   -1,   -1,  797,   -1,   -1,   -1,
      -1,   -1,   -1,   -1,   -1,   -1,   -1,   -1,
      -1,   -1,  798,  799,   -1,   -1,   -1,   -1,
      -1,   -1,   -1,   -1,  800,   -1,   -1,   -1,
      -1,   -1,   -1,   -1,   -1,   -1,   -1,   -1,
      -1,   -1,   -1,   -1,   -1,  801,   -1,  802,
      -1,   -1,   -1,   -1,  803,   -1,   -1,   -1,
      -1,   -1,   -1,   -1,  804,   -1,   -1,   -1,
      -1,   -1,   -1,   -1,   -1,   -1,  805,   -1,
      -1,   -1,   -1,   -1,   -1,   -1,   -1,  806,
      -1,   -1,   -1,   -1,   -1,   -1,   -1,   -1,
     807,   -1,   -1,   -1,   -1,   -1,   -1,   -1,
      -1,   -1,   -1,  808,  809,   -1,   -1,   -1,
      -1,  810,   -1,   -1,   -1,   -1,   -1,   -1,
      -1,  811,  812,   -1,   -1,   -1,   -1,   -1,
      -1,   -1,   -1,  813,   -1,   -1,   -1,  814,
      -1,  815,   -1,   -1,   -1,   -1,   -1,   -1,
      -1,   -1,   -1,   -1,   -1,   -1,   -1,   -1,
      -1,   -1,   -1,   -1,   -1,   -1,   -1,   -1,
      -1,   -1,  816,   -1,   -1,   -1,   -1,  817,
      -1,   -1,   -1,   -1,   -1,   -1,   -1,   -1,
      -1,   -1,   -1,   -1,  818,   -1,   -1,   -1,
      -1,   -1,   -1,   -1,   -1,  819,   -1,   -1,
      -1,  820,   -1,   -1,   -1,   -1,   -1,  821,
      -1,   -1,   -1,   -1,   -1,   -1,  822,   -1,
     823,  824,   -1,   -1,   -1,   -1,   -1,   -1,
      -1,   -1,   -1,   -1,   -1,   -1,   -1,   -1,
      -1,   -1,   -1,  825,   -1,   -1,   -1,   -1,
      -1,   -1,   -1,   -1,  826,   -1,   -1,   -1,
      -1,   -1,   -1,   -1,   -1,   -1,   -1,   -1,
      -1,   -1,   -1,   -1,   -1,   -1,   -1,   -1,
      -1,  827,  828,   -1,   -1,   -1,   -1,   -1,
      -1,   -1,   -1,   -1,   -1,   -1,  829,   -1,
      -1,   -1,   -1,   -1,   -1,   -1,   -1,   -1,
      -1,   -1,   -1,   -1,   -1,   -1,   -1,   -1,
      -1,   -1,   -1,   -1,   -1,   -1,   -1,   -1,
      -1,   -1,  830,   -1,   -1,   -1,  831,   -1,
      -1,   -1,   -1,   -1,  832,  833,   -1,  834,
      -1,   -1,   -1,   -1,   -1,   -1,   -1,   -1,
      -1,   -1,  835,   -1,   -1,   -1,   -1,  836,
     837,   -1,   -1,   -1,  838,   -1,   -1,   -1,
      -1,   -1,   -1,   -1,   -1,   -1,   -1,   -1,
      -1,   -1,   -1,   -1,   -1,   -1,   -1,   -1,
      -1,  839,   -1,   -1,   -1,   -1,   -1,   -1,
      -1,   -1,   -1,   -1,   -1,   -1,   -1,   -1,
      -1,   -1,   -1,   -1,  840,   -1,   -1,   -1,
      -1,   -1,   -1,   -1,   -1,   -1,  841,   -1,
     842,   -1,  843,   -1,   -1,   -1,   -1,  844,
      -1,   -1,   -1,   -1,   -1,   -1,   -1,   -1,
      -1,  845,   -1,   -1,   -1,   -1,  846,  847,
      -1,   -1,   -1,  848,   -1,   -1,   -1,   -1,
      -1,   -1,   -1,   -1,   -1,   -1,   -1,   -1,
      -1,   -1,   -1,   -1,   -1,   -1,   -1,   -1,
      -1,  849,   -1,   -1,   -1,   -1,  850,  851,
      -1,   -1,   -1,   -1,   -1,   -1,   -1,   -1,
      -1,   -1,   -1,   -1,   -1,  852,   -1,   -1,
      -1,   -1,   -1,   -1,   -1,   -1,   -1,   -1,
      -1,   -1,   -1,   -1,   -1,   -1,   -1,   -1,
      -1,   -1,   -1,  853,   -1,   -1,   -1,   -1,
      -1,   -1,   -1,   -1,   -1,   -1,   -1,   -1,
      -1,   -1,   -1,   -1,   -1,   -1,   -1,   -1,
      -1,   -1,   -1,  854,   -1,   -1,   -1,   -1,
      -1,   -1,   -1,   -1,   -1,   -1,   -1,   -1,
      -1,   -1,   -1,   -1,   -1,   -1,   -1,   -1,
      -1,   -1,   -1,   -1,   -1,   -1,   -1,   -1,
     855,   -1,   -1,   -1,   -1,   -1,   -1,   -1,
      -1,   -1,   -1,   -1,   -1,   -1,   -1,   -1,
      -1,   -1,   -1,  856,   -1,   -1,   -1,   -1,
      -1,   -1,   -1,   -1,   -1,  857,   -1,   -1,
      -1,   -1,   -1,   -1,   -1,   -1,  858,  859,
      -1,   -1,   -1,   -1,   -1,   -1,   -1,   -1,
      -1,   -1,   -1,   -1,   -1,   -1,   -1,   -1,
      -1,   -1,   -1,   -1,   -1,   -1,   -1,   -1,
     860,   -1,   -1,   -1,   -1,  861,  862,   -1,
      -1,   -1,  863,   -1,   -1,   -1,   -1,  864,
     865,   -1,   -1,   -1,  866,   -1,   -1,   -1,
      -1,  867,   -1,   -1,  868,  869,  870,   -1,
      -1,  871,  872,  873,   -1,   -1,   -1,   -1,
      -1,   -1,   -1,   -1,   -1,   -1,  874,   -1,
      -1,   -1,   -1,   -1,   -1,  875,   -1,   -1,
      -1,   -1,   -1,   -1,   -1,   -1,   -1,   -1,
      -1,   -1,   -1,   -1,   -1,   -1,  876,   -1,
      -1,   -1,   -1,   -1,   -1,   -1,   -1,   -1,
      -1,   -1,  877,   -1,   -1,   -1,   -1,   -1,
      -1,   -1,   -1,   -1,   -1,   -1,   -1,   -1,
      -1,   -1,   -1,   -1,   -1,   -1,   -1,   -1,
      -1,   -1,  878,   -1,   -1,   -1,   -1,   -1,
      -1,   -1,   -1,   -1,   -1,   -1,   -1,   -1,
      -1,   -1,   -1,   -1,   -1,   -1,   -1,   -1,
      -1,   -1,   -1,   -1,   -1,   -1,   -1,   -1,
      -1,   -1,   -1,   -1,   -1,   -1,   -1,   -1,
      -1,  879,   -1,   -1,   -1,   -1,   -1,   -1,
      -1,   -1,   -1,   -1,   -1,   -1,   -1,   -1,
      -1,   -1,  880,   -1,   -1,   -1,   -1,   -1,
     881,   -1,  882,   -1,   -1,   -1,   -1,   -1,
     883,   -1,   -1,   -1,   -1,   -1,   -1,   -1,
      -1,   -1,   -1,  884,   -1,   -1,   -1,   -1,
      -1,   -1,   -1,   -1,   -1,   -1,   -1,   -1,
      -1,   -1,   -1,   -1,   -1,  885,   -1,   -1,
      -1,   -1,   -1,   -1,   -1,   -1,   -1,   -1,
      -1,   -1,   -1,  886,   -1,   -1,   -1,   -1,
      -1,   -1,   -1,   -1,   -1,   -1,   -1,   -1,
      -1,   -1,   -1,   -1,  887,   -1,   -1,   -1,
      -1,   -1,   -1,   -1,   -1,  888,   -1,   -1,
      -1,   -1,   -1,   -1,   -1,   -1,   -1,   -1,
      -1,   -1,   -1,   -1,   -1,   -1,  889,   -1,
      -1,   -1,  890,   -1,   -1,   -1,   -1,   -1,
     891,   -1,   -1,   -1,   -1,   -1,   -1,   -1,
      -1,   -1,   -1,   -1,   -1,   -1,   -1,  892,
      -1,   -1,   -1,   -1,   -1,  893,   -1,   -1,
      -1,   -1,   -1,   -1,   -1,   -1,   -1,   -1,
      -1,   -1,  894,  895,   -1,   -1,  896,   -1,
     897,   -1,   -1,   -1,   -1,   -1,   -1,   -1,
      -1,   -1,   -1,   -1,   -1,   -1,   -1,   -1,
      -1,   -1,  898,   -1,   -1,   -1,   -1,   -1,
     899,   -1,   -1,  900,   -1,   -1,   -1,  901,
     902,   -1,  903,   -1,   -1,   -1,   -1,   -1,
      -1,   -1,   -1,   -1,   -1,   -1,   -1,   -1,
      -1,   -1,   -1,   -1,   -1,   -1,   -1,   -1,
      -1,   -1,   -1,   -1,   -1,   -1,   -1,  904,
      -1,   -1,   -1,   -1,   -1,   -1,   -1,   -1,
      -1,  905,   -1,   -1,   -1,   -1,   -1,   -1,
      -1,   -1,   -1,  906,   -1,   -1,   -1,   -1,
      -1,   -1,   -1,   -1,   -1,   -1,   -1,   -1,
      -1,   -1,   -1,  907,   -1,   -1,   -1,   -1,
     908,   -1,   -1,   -1,   -1,   -1,   -1,   -1,
      -1,   -1,   -1,   -1,   -1,   -1,  909,   -1,
      -1,  910,   -1,   -1,   -1,   -1,   -1,   -1,
      -1,   -1,   -1,   -1,   -1,  911,   -1,   -1,
      -1,   -1,   -1,   -1,   -1,   -1,   -1,   -1,
      -1,   -1,   -1,   -1,   -1,   -1,   -1,   -1,
     912,   -1,  913,  914,   -1,   -1,   -1,  915,
      -1,   -1,   -1,   -1,   -1,   -1,   -1,   -1,
      -1,   -1,   -1,   -1,   -1,   -1,  916,   -1,
      -1,   -1,   -1,   -1,   -1,   -1,   -1,   -1,
      -1,   -1,   -1,   -1,   -1,   -1,   -1,   -1,
      -1,   -1,   -1,   -1,   -1,   -1,   -1,  917,
      -1,   -1,   -1,   -1,   -1,   -1,   -1,   -1,
      -1,   -1,   -1,   -1,   -1,   -1,  918,   -1,
      -1,  919,   -1,   -1,   -1,   -1,   -1,   -1,
      -1,   -1,   -1,  920,   -1,   -1,   -1,   -1,
      -1,   -1,  921,   -1,   -1,   -1,  922,   -1,
      -1,   -1,   -1,  923,   -1,   -1,   -1,   -1,
      -1,  924,   -1,   -1,   -1,   -1,   -1,   -1,
      -1,   -1,  925,   -1,   -1,   -1,   -1,   -1,
      -1,   -1,   -1,   -1,   -1,   -1,   -1,   -1,
      -1,   -1,   -1,   -1,   -1,   -1,  926,  927,
      -1,   -1,  928,   -1,   -1,   -1,   -1,   -1,
     929,   -1,   -1,   -1,   -1,   -1,   -1,   -1,
      -1,   -1,   -1,   -1,   -1,   -1,   -1,   -1,
      -1,   -1,   -1,   -1,   -1,   -1,   -1,   -1,
      -1,   -1,   -1,   -1,   -1,   -1,   -1,   -1,
      -1,   -1,  930,   -1,   -1,   -1,   -1,   -1,
      -1,   -1,   -1,   -1,   -1,   -1,  931,  932,
      -1,  933,   -1,   -1,   -1,   -1,   -1,   -1,
      -1,   -1,   -1,   -1,   -1,   -1,   -1,   -1,
      -1,  934,   -1,   -1,   -1,  935,   -1,   -1,
     936,   -1,  937,  938,   -1,   -1,   -1,   -1,
     939,   -1,   -1,   -1,   -1,   -1,   -1,   -1,
      -1,   -1,  940,   -1,   -1,   -1,   -1,  941,
      -1,   -1,   -1,   -1,  942,   -1,   -1,   -1,
      -1,  943,   -1,   -1,   -1,   -1,   -1,   -1,
      -1,   -1,   -1,   -1,   -1,   -1,   -1,   -1,
     944,   -1,   -1,   -1,   -1,   -1,   -1,   -1,
      -1,   -1,   -1,  945,   -1,   -1,   -1,   -1,
      -1,   -1,   -1,   -1,   -1,   -1,   -1,   -1,
      -1,   -1,   -1,   -1,   -1,   -1,   -1,   -1,
      -1,   -1,   -1,   -1,   -1,   -1,  946,   -1,
      -1,   -1,   -1,   -1,  947,   -1,   -1,   -1,
     948,   -1,  949,  950,   -1,   -1,   -1,   -1,
      -1,   -1,  951,   -1,   -1,   -1,   -1,   -1,
      -1,   -1,   -1,   -1,   -1,   -1,   -1,   -1,
      -1,   -1,   -1,   -1,   -1,   -1,   -1,   -1,
      -1,   -1,   -1,   -1,   -1,   -1,   -1,   -1,
      -1,   -1,   -1,   -1,   -1,  952,   -1,   -1,
      -1,   -1,   -1,   -1,   -1,   -1,   -1,   -1,
      -1,  953,   -1,   -1,   -1,   -1,   -1,   -1,
      -1,   -1,   -1,   -1,   -1,   -1,   -1,  954,
      -1,   -1,   -1,  955,   -1,   -1,   -1,   -1,
      -1,   -1,   -1,   -1,   -1,   -1,   -1,   -1,
      -1,   -1,   -1,   -1,   -1,   -1,  956,   -1,
      -1,  957,  958,   -1,   -1,   -1,   -1,  959,
      -1,   -1,   -1,   -1,   -1,   -1,   -1,   -1,
      -1,   -1,  960,   -1,   -1,   -1,   -1,   -1,
      -1,   -1,   -1,  961,   -1,   -1,   -1,   -1,
      -1,   -1,   -1,   -1,   -1,  962,   -1,   -1,
      -1,  963,   -1,   -1,   -1,   -1,   -1,   -1,
      -1,   -1,   -1,   -1,   -1,   -1,   -1,   -1,
      -1,   -1,   -1,   -1,   -1,   -1,   -1,   -1,
      -1,   -1,   -1,   -1,   -1,   -1,   -1,   -1,
      -1,   -1,   -1,   -1,   -1,   -1,   -1,   -1,
      -1,   -1,   -1,   -1,   -1,   -1,   -1,   -1,
      -1,   -1,   -1,   -1,   -1,   -1,   -1,   -1,
      -1,   -1,   -1,   -1,   -1,   -1,   -1,   -1,
      -1,   -1,   -1,   -1,   -1,   -1,   -1,   -1,
      -1,   -1,   -1,   -1,   -1,   -1,   -1,   -1,
      -1,   -1,   -1,   -1,   -1,   -1,   -1,  964,
      -1,   -1,   -1,   -1,   -1,   -1,   -1,   -1,
      -1,   -1,   -1,   -1,   -1,   -1,   -1,   -1,
      -1,   -1,   -1,  965,   -1,   -1,   -1,   -1,
      -1,  966,   -1,   -1,   -1,   -1,  967,   -1,
      -1,   -1,   -1,  968,   -1,   -1,   -1,   -1,
      -1,   -1,   -1,   -1,   -1,   -1,   -1,   -1,
     969,   -1,   -1,   -1,   -1,   -1,   -1,  970,
      -1,   -1,   -1,   -1,   -1,   -1,   -1,   -1,
      -1,   -1,   -1,   -1,   -1,   -1,   -1,   -1,
      -1,  971,  972,   -1,   -1,   -1,   -1,   -1,
      -1,   -1,   -1,   -1,   -1,   -1,   -1,   -1,
      -1,   -1,   -1,   -1,   -1,   -1,   -1,   -1,
      -1,   -1,   -1,   -1,   -1,   -1,   -1,   -1,
      -1,  973,   -1,   -1,   -1,   -1,   -1,   -1,
     974,   -1,   -1,   -1,  975,   -1,   -1,   -1,
      -1,   -1,   -1,  976,   -1,   -1,   -1,   -1,
      -1,   -1,   -1,   -1,   -1,   -1,   -1,   -1,
      -1,   -1,   -1,   -1,   -1,   -1,   -1,   -1,
      -1,   -1,   -1,   -1,   -1,   -1,   -1,   -1,
     977,   -1,   -1,   -1,   -1,  978,   -1,   -1,
      -1,   -1,   -1,   -1,   -1,   -1,   -1,  979,
      -1,  980,   -1,   -1,  981,   -1,   -1,   -1,
      -1,  982,   -1,  983,   -1,   -1,   -1,   -1,
      -1,   -1,   -1,   -1,   -1,   -1,   -1,   -1,
      -1,   -1,   -1,   -1,   -1,   -1,   -1,  984,
      -1,   -1,   -1,   -1,   -1,  985,   -1,   -1,
      -1,   -1,   -1,   -1,   -1,   -1,   -1,   -1,
      -1,  986,  987,  988,   -1,   -1,   -1,   -1,
      -1,   -1,   -1,   -1,   -1,   -1,   -1,   -1,
      -1,   -1,   -1,   -1,   -1,   -1,   -1,   -1,
      -1,   -1,   -1,   -1,   -1,   -1,   -1,   -1,
      -1,   -1,   -1,   -1,   -1,   -1,   -1,   -1,
      -1,   -1,   -1,   -1,   -1,   -1,   -1,   -1,
      -1,   -1,   -1,   -1,  989,   -1,  990,   -1,
      -1,   -1,   -1,   -1,   -1,   -1,   -1,   -1,
      -1,   -1,   -1,   -1,   -1,   -1,   -1,   -1,
     991,   -1,   -1,   -1,   -1,  992,   -1,   -1,
      -1,   -1,   -1,   -1,   -1,   -1,   -1,   -1,
      -1,   -1,   -1,   -1,   -1,   -1,   -1,   -1,
      -1,   -1,   -1,   -1,   -1,   -1,   -1,   -1,
      -1,   -1,   -1,   -1,  993,   -1,   -1,   -1,
      -1,   -1,   -1,   -1,   -1,   -1,   -1,   -1,
      -1,   -1,   -1,   -1,   -1,   -1,   -1,   -1,
      -1,   -1,   -1,   -1,   -1,   -1,   -1,   -1,
      -1,   -1,   -1,   -1,   -1,   -1,   -1,  994,
      -1,   -1,   -1,   -1,   -1,   -1,   -1,   -1,
      -1,   -1,   -1,   -1,   -1,   -1,   -1,   -1,
      -1,   -1,   -1,   -1,   -1,   -1,   -1,   -1,
      -1,  995,   -1,   -1,   -1,   -1,   -1,   -1,
      -1,   -1,   -1,   -1,   -1,   -1,   -1,   -1,
      -1,   -1,   -1,   -1,   -1,   -1,   -1,  996,
      -1,   -1,   -1,   -1,   -1,   -1,   -1,   -1,
      -1,   -1,   -1,   -1,   -1,   -1,   -1,   -1,
      -1,   -1,   -1,   -1,  997,   -1,   -1,   -1,
      -1,   -1,   -1,   -1,   -1,   -1,   -1,  998,
      -1,  999,   -1,   -1,   -1, 1000,   -1,   -1,
      -1,   -1,   -1,   -1,   -1,   -1,   -1,   -1,
    1001,   -1,   -1,   -1,   -1,   -1,   -1,   -1,
      -1,   -1,   -1, 1002,   -1, 1003,   -1,   -1,
      -1,   -1,   -1,   -1,   -1, 1004,   -1,   -1,
      -1,   -1,   -1,   -1,   -1,   -1,   -1,   -1,
      -1,   -1,   -1,   -1,   -1,   -1,   -1,   -1,
      -1,   -1,   -1,   -1,   -1,   -1,   -1,   -1,
    1005,   -1,   -1,   -1,   -1,   -1,   -1,   -1,
      -1,   -1,   -1,   -1,   -1,   -1,   -1,   -1,
      -1,   -1,   -1,   -1, 1006, 1007,   -1,   -1,
      -1,   -1,   -1, 1008,   -1,   -1,   -1,   -1,
      -1,   -1,   -1,   -1,   -1,   -1,   -1, 1009,
      -1,   -1,   -1,   -1,   -1,   -1,   -1,   -1,
    1010,   -1,   -1,   -1,   -1,   -1,   -1,   -1,
      -1,   -1,   -1,   -1, 1011, 1012,   -1,   -1,
      -1,   -1,   -1,   -1,   -1, 1013,   -1,   -1,
      -1,   -1,   -1,   -1,   -1,   -1,   -1,   -1,
      -1,   -1,   -1,   -1,   -1,   -1,   -1,   -1,
      -1,   -1,   -1,   -1,   -1,   -1,   -1,   -1,
      -1,   -1,   -1,   -1,   -1,   -1,   -1,   -1,
      -1,   -1,   -1,   -1,   -1,   -1, 1014,   -1,
    1015,   -1,   -1,   -1,   -1,   -1,   -1,   -1,
      -1,   -1,   -1,   -1,   -1,   -1,   -1,   -1,
      -1,   -1,   -1,   -1,   -1,   -1,   -1,   -1,
      -1,   -1, 1016,   -1,   -1,   -1,   -1,   -1,
      -1, 1017,   -1,   -1,   -1,   -1,   -1, 1018,
      -1,   -1,   -1,   -1,   -1,   -1,   -1,   -1,
      -1,   -1,   -1,   -1,   -1,   -1,   -1,   -1,
      -1,   -1, 1019,   -1,   -1,   -1,   -1,   -1,
      -1,   -1,   -1,   -1,   -1,   -1,   -1,   -1,
      -1,   -1,   -1,   -1,   -1,   -1,   -1,   -1,
      -1,   -1,   -1, 1020,   -1,   -1,   -1,   -1,
      -1,   -1,   -1,   -1,   -1, 1021,   -1,   -1,
      -1,   -1, 1022,   -1,   -1,   -1,   -1, 1023,
      -1,   -1,   -1,   -1, 1024,   -1,   -1,   -1,
    1025, 1026,   -1,   -1,   -1,   -1, 1027,   -1,
      -1,   -1,   -1,   -1,   -1,   -1,   -1,   -1,
      -1,   -1, 1028,   -1,   -1, 1029,   -1,   -1,
      -1,   -1,   -1,   -1,   -1, 1030,   -1, 1031,
      -1, 1032, 1033,   -1, 1034,   -1,   -1,   -1,
      -1, 1035,   -1,   -1,   -1, 1036, 1037,   -1,
      -1,   -1, 1038,   -1,   -1,   -1,   -1,   -1,
    1039,   -1,   -1,   -1, 1040, 1041,   -1,   -1,
      -1, 1042,   -1,   -1,   -1,   -1, 1043,   -1,
      -1,   -1,   -1,   -1,   -1,   -1,   -1,   -1,
      -1, 1044,   -1,   -1,   -1,   -1,   -1,   -1,
      -1,   -1,   -1, 1045,   -1,   -1,   -1,   -1,
      -1,   -1,   -1,   -1, 1046,   -1,   -1,   -1,
      -1,   -1, 1047,   -1,   -1,   -1,   -1,   -1,
      -1,   -1,   -1,   -1, 1048, 1049,   -1,   -1,
      -1,   -1,   -1,   -1,   -1,   -1, 1050,   -1,
    1051,   -1,   -1,   -1,   -1,   -1,   -1,   -1,
    1052,   -1,   -1,   -1,   -1, 1053,   -1,   -1,
      -1,   -1,   -1,   -1,   -1,   -1, 1054,   -1,
    1055,   -1, 1056, 1057,   -1,   -1,   -1,   -1,
      -1,   -1, 1058,   -1,   -1, 1059,   -1,   -1,
      -1,   -1,   -1,   -1,   -1,   -1,   -1, 1060,
      -1,   -1,   -1,   -1,   -1, 1061,   -1,   -1,
      -1,   -1, 1062,   -1,   -1,   -1, 1063,   -1,
      -1,   -1,   -1,   -1,   -1,   -1,   -1,   -1,
      -1,   -1,   -1,   -1,   -1,   -1, 1064, 1065,
    1066,   -1,   -1,   -1,   -1,   -1,   -1, 1067,
      -1, 1068, 1069,   -1, 1070,   -1,   -1, 1071,
      -1, 1072,   -1, 1073,   -1,   -1, 1074,   -1,
      -1,   -1,   -1, 1075,   -1,   -1, 1076,   -1,
    1077,   -1,   -1,   -1,   -1,   -1,   -1,   -1,
      -1,   -1,   -1, 1078,   -1,   -1,   -1,   -1,
      -1,   -1,   -1, 1079,   -1,   -1,   -1,   -1,
      -1, 1080,   -1,   -1,   -1,   -1,   -1,   -1,
      -1,   -1,   -1, 1081, 1082,   -1,   -1,   -1,
    1083, 1084,   -1,   -1, 1085,   -1,   -1, 1086,
      -1,   -1,   -1,   -1,   -1,   -1,   -1, 1087,
    1088,   -1,   -1,   -1,   -1,   -1,   -1,   -1,
      -1,   -1,   -1,   -1,   -1,   -1, 1089,   -1,
      -1,   -1,   -1,   -1,   -1,   -1, 1090,   -1,
      -1, 1091,   -1, 1092, 1093,   -1,   -1,   -1,
      -1,   -1, 1094,   -1, 1095,   -1,   -1,   -1,
      -1,   -1,   -1,   -1, 1096,   -1, 1097,   -1,
    1098, 1099,   -1, 1100,   -1,   -1,   -1,   -1,
      -1,   -1,   -1,   -1,   -1,   -1,   -1,   -1,
      -1,   -1,   -1,   -1,   -1,   -1, 1101,   -1,
      -1, 1102,   -1,   -1,   -1,   -1,   -1,   -1,
      -1,   -1,   -1,   -1,   -1,   -1,   -1,   -1,
      -1,   -1,   -1,   -1,   -1,   -1,   -1,   -1,
      -1,   -1, 1103,   -1,   -1,   -1,   -1, 1104,
      -1,   -1,   -1,   -1,   -1,   -1,   -1,   -1,
      -1,   -1,   -1,   -1,   -1, 1105,   -1,   -1,
    1106,   -1,   -1,   -1,   -1,   -1,   -1,   -1,
      -1,   -1,   -1,   -1,   -1,   -1,   -1,   -1,
      -1,   -1,   -1,   -1,   -1,   -1,   -1,   -1,
      -1, 1107,   -1,   -1,   -1,   -1,   -1,   -1,
    1108,   -1,   -1,   -1, 1109,   -1, 1110, 1111,
      -1,   -1, 1112,   -1,   -1,   -1,   -1, 1113,
      -1,   -1, 1114,   -1,   -1,   -1,   -1,   -1,
      -1,   -1, 1115,   -1,   -1,   -1,   -1,   -1,
      -1, 1116,   -1,   -1,   -1,   -1,   -1,   -1,
      -1, 1117,   -1,   -1, 1118,   -1,   -1, 1119,
      -1, 1120,   -1,   -1,   -1,   -1,   -1,   -1,
      -1,   -1, 1121,   -1,   -1, 1122,   -1, 1123,
      -1,   -1,   -1,   -1,   -1,   -1,   -1, 1124,
      -1,   -1,   -1,   -1,   -1, 1125,   -1,   -1,
      -1,   -1,   -1,   -1,   -1, 1126,   -1,   -1,
    1127,   -1,   -1,   -1,   -1,   -1, 1128,   -1,
      -1,   -1,   -1,   -1,   -1,   -1,   -1,   -1,
      -1,   -1,   -1,   -1,   -1,   -1,   -1, 1129,
      -1,   -1,   -1,   -1,   -1,   -1,   -1,   -1,
      -1,   -1,   -1,   -1,   -1,   -1,   -1,   -1,
      -1,   -1,   -1,   -1,   -1,   -1,   -1,   -1,
      -1,   -1,   -1,   -1,   -1,   -1,   -1,   -1,
      -1,   -1,   -1,   -1,   -1,   -1,   -1,   -1,
      -1, 1130,   -1, 1131,   -1,   -1, 1132,   -1,
      -1,   -1,   -1, 1133,   -1,   -1,   -1,   -1,
      -1,   -1,   -1, 1134,   -1,   -1,   -1,   -1,
      -1,   -1,   -1,   -1,   -1,   -1,   -1,   -1,
      -1,   -1,   -1,   -1,   -1,   -1,   -1,   -1,
      -1, 1135,   -1,   -1,   -1,   -1,   -1,   -1,
      -1,   -1,   -1, 1136,   -1,   -1,   -1,   -1,
      -1,   -1,   -1,   -1,   -1, 1137,   -1, 1138,
      -1,   -1,   -1,   -1, 1139,   -1,   -1,   -1,
      -1,   -1,   -1,   -1,   -1,   -1,   -1,   -1,
      -1,   -1,   -1,   -1,   -1,   -1, 1140,   -1,
      -1, 1141,   -1,   -1,   -1,   -1,   -1, 1142,
      -1,   -1,   -1,   -1,   -1,   -1, 1143,   -1,
      -1,   -1,   -1,   -1,   -1,   -1, 1144,   -1,
      -1,   -1,   -1, 1145,   -1,   -1,   -1,   -1,
      -1, 1146, 1147,   -1,   -1, 1148,   -1,   -1,
      -1,   -1, 1149,   -1, 1150,   -1,   -1, 1151,
      -1,   -1,   -1,   -1,   -1,   -1,   -1,   -1,
      -1,   -1,   -1,   -1,   -1,   -1,   -1,   -1,
      -1,   -1,   -1,   -1, 1152, 1153,   -1,   -1,
      -1, 1154,   -1,   -1,   -1, 1155,   -1,   -1,
      -1,   -1,   -1, 1156,   -1,   -1,   -1,   -1,
      -1,   -1,   -1,   -1,   -1,   -1, 1157,   -1,
      -1,   -1,   -1,   -1,   -1,   -1,   -1,   -1,
      -1,   -1, 1158,   -1,   -1, 1159, 1160,   -1,
      -1,   -1,   -1,   -1,   -1,   -1,   -1,   -1,
      -1,   -1,   -1,   -1,   -1,   -1,   -1,   -1,
      -1,   -1, 1161,   -1,   -1,   -1, 1162,   -1,
      -1,   -1,   -1,   -1,   -1,   -1,   -1,   -1,
      -1,   -1, 1163,   -1,   -1, 1164,   -1, 1165,
      -1,   -1, 1166,   -1,   -1, 1167,   -1,   -1,
    1168,   -1,   -1,   -1,   -1,   -1,   -1,   -1,
      -1,   -1,   -1,   -1,   -1, 1169,   -1, 1170,
      -1,   -1,   -1,   -1,   -1,   -1, 1171,   -1,
      -1,   -1,   -1,   -1,   -1,   -1, 1172,   -1,
    1173,   -1,   -1,   -1, 1174, 1175,   -1,   -1,
      -1,   -1,   -1, 1176, 1177,   -1,   -1, 1178,
      -1,   -1, 1179,   -1, 1180,   -1,   -1,   -1,
      -1, 1181, 1182,   -1, 1183,   -1,   -1,   -1,
      -1,   -1,   -1,   -1,   -1,   -1,   -1,   -1,
      -1,   -1,   -1,   -1,   -1,   -1,   -1,   -1,
      -1,   -1,   -1,   -1, 1184,   -1,   -1,   -1,
      -1,   -1,   -1,   -1, 1185,   -1,   -1,   -1,
    1186,   -1, 1187,   -1,   -1,   -1,   -1,   -1,
      -1,   -1,   -1,   -1,   -1, 1188, 1189,   -1,
      -1,   -1,   -1, 1190,   -1, 1191,   -1,   -1,
      -1,   -1,   -1,   -1,   -1,   -1,   -1, 1192,
      -1,   -1,   -1,   -1,   -1,   -1,   -1,   -1,
    1193,   -1,   -1,   -1,   -1,   -1,   -1,   -1,
      -1,   -1,   -1,   -1,   -1,   -1, 1194,   -1,
      -1, 1195,   -1,   -1,   -1,   -1, 1196,   -1,
      -1,   -1,   -1, 1197,   -1,   -1,   -1,   -1,
    1198,   -1, 1199,   -1,   -1, 1200,   -1,   -1,
      -1,   -1,   -1, 1201,   -1,   -1,   -1, 1202,
      -1,   -1,   -1,   -1, 1203,   -1,   -1,   -1,
      -1,   -1,   -1,   -1,   -1, 1204,   -1,   -1,
      -1,   -1, 1205, 1206, 1207,   -1,   -1,   -1,
    1208,   -1,   -1,   -1,   -1, 1209, 1210, 1211,
      -1,   -1, 1212, 1213,   -1,   -1, 1214, 1215,
      -1, 1216,   -1, 1217,   -1, 1218,   -1,   -1,
      -1, 1219, 1220, 1221, 1222,   -1,   -1, 1223,
      -1,   -1,   -1, 1224,   -1,   -1,   -1,   -1,
    1225,   -1,   -1,   -1,   -1, 1226,   -1,   -1,
      -1,   -1, 1227,   -1,   -1,   -1,   -1,   -1,
      -1,   -1,   -1,   -1,   -1,   -1,   -1,   -1,
      -1, 1228,   -1, 1229,   -1,   -1, 1230, 1231,
    1232,   -1,   -1, 1233,   -1, 1234,   -1,   -1,
    1235,   -1,   -1,   -1,   -1,   -1, 1236,   -1,
      -1,   -1, 1237,   -1,   -1,   -1,   -1,   -1,
      -1,   -1,   -1,   -1, 1238,   -1,   -1,   -1,
      -1,   -1,   -1,   -1,   -1,   -1,   -1,   -1,
      -1,   -1,   -1,   -1,   -1,   -1,   -1,   -1,
      -1,   -1,   -1, 1239,   -1,   -1,   -1,   -1,
    1240,   -1, 1241,   -1,   -1,   -1, 1242, 1243,
      -1,   -1, 1244,   -1, 1245,   -1,   -1, 1246,
      -1, 1247,   -1,   -1, 1248,   -1, 1249,   -1,
      -1,   -1,   -1,   -1,   -1,   -1,   -1,   -1,
    1250,   -1,   -1,   -1,   -1,   -1,   -1,   -1,
      -1,   -1, 1251,   -1,   -1,   -1,   -1, 1252,
    1253,   -1,   -1,   -1, 1254, 1255,   -1,   -1,
      -1,   -1,   -1,   -1,   -1,   -1,   -1,   -1,
      -1,   -1,   -1, 1256,   -1,   -1,   -1,   -1,
    1257,   -1,   -1,   -1,   -1, 1258,   -1,   -1,
      -1,   -1,   -1,   -1,   -1,   -1,   -1,   -1,
      -1,   -1,   -1,   -1,   -1,   -1,   -1,   -1,
      -1,   -1,   -1,   -1,   -1,   -1, 1259,   -1,
      -1,   -1,   -1,   -1,   -1,   -1,   -1, 1260,
    1261, 1262,   -1,   -1,   -1,   -1,   -1,   -1,
      -1,   -1,   -1,   -1,   -1,   -1,   -1, 1263,
      -1, 1264,   -1,   -1, 1265,   -1,   -1,   -1,
      -1, 1266,   -1,   -1,   -1,   -1, 1267,   -1,
      -1,   -1,   -1, 1268,   -1,   -1,   -1,   -1,
      -1, 1269,   -1,   -1,   -1, 1270, 1271,   -1,
      -1,   -1,   -1,   -1,   -1,   -1,   -1,   -1,
      -1,   -1,   -1,   -1,   -1, 1272,   -1,   -1,
      -1, 1273,   -1,   -1,   -1, 1274,   -1,   -1,
      -1,   -1,   -1, 1275,   -1, 1276,   -1,   -1,
      -1, 1277,   -1,   -1,   -1, 1278,   -1,   -1,
      -1,   -1, 1279,   -1, 1280,   -1, 1281, 1282,
      -1,   -1,   -1, 1283, 1284,   -1,   -1,   -1,
      -1,   -1, 1285,   -1,   -1,   -1,   -1,   -1,
      -1,   -1,   -1, 1286,   -1,   -1,   -1,   -1,
      -1,   -1,   -1,   -1,   -1,   -1,   -1,   -1,
      -1,   -1,   -1,   -1,   -1,   -1,   -1, 1287,
    1288,   -1,   -1,   -1,   -1, 1289,   -1,   -1,
      -1,   -1,   -1,   -1,   -1,   -1, 1290,   -1,
      -1,   -1,   -1,   -1,   -1,   -1,   -1,   -1,
      -1,   -1,   -1,   -1,   -1, 1291,   -1,   -1,
      -1,   -1, 1292,   -1,   -1,   -1,   -1, 1293,
      -1,   -1,   -1,   -1, 1294,   -1,   -1,   -1,
      -1, 1295,   -1,   -1,   -1,   -1,   -1,   -1,
      -1,   -1,   -1, 1296,   -1,   -1,   -1,   -1,
      -1,   -1,   -1,   -1,   -1,   -1,   -1,   -1,
      -1,   -1,   -1,   -1,   -1,   -1,   -1,   -1,
      -1,   -1,   -1,   -1,   -1, 1297,   -1,   -1,
      -1,   -1,   -1,   -1,   -1,   -1,   -1,   -1,
      -1,   -1,   -1, 1298,   -1,   -1,   -1,   -1,
      -1, 1299,   -1,   -1,   -1,   -1,   -1,   -1,
      -1,   -1, 1300, 1301,   -1,   -1,   -1,   -1,
      -1,   -1,   -1,   -1, 1302, 1303,   -1,   -1,
      -1,   -1,   -1, 1304,   -1,   -1, 1305,   -1,
      -1,   -1,   -1, 1306,   -1,   -1,   -1,   -1,
    1307, 1308,   -1,   -1,   -1, 1309,   -1,   -1,
      -1,   -1, 1310,   -1,   -1,   -1,   -1, 1311,
      -1,   -1,   -1,   -1, 1312,   -1,   -1,   -1,
      -1, 1313,   -1,   -1,   -1,   -1,   -1, 1314,
      -1,   -1,   -1,   -1,   -1,   -1,   -1,   -1,
    1315,   -1,   -1, 1316,   -1,   -1,   -1,   -1,
      -1,   -1, 1317, 1318,   -1,   -1,   -1, 1319,
      -1,   -1,   -1,   -1,   -1,   -1,   -1,   -1,
      -1,   -1,   -1,   -1,   -1,   -1, 1320,   -1,
      -1, 1321,   -1,   -1,   -1, 1322,   -1,   -1,
    1323,   -1,   -1,   -1,   -1, 1324,   -1,   -1,
      -1,   -1,   -1,   -1,   -1,   -1,   -1, 1325,
      -1,   -1,   -1,   -1,   -1, 1326,   -1,   -1,
    1327,   -1,   -1, 1328,   -1,   -1,   -1,   -1,
      -1,   -1,   -1,   -1,   -1,   -1,   -1,   -1,
    1329,   -1,   -1,   -1,   -1,   -1,   -1,   -1,
      -1,   -1, 1330,   -1,   -1,   -1,   -1,   -1,
      -1,   -1, 1331,   -1, 1332,   -1,   -1,   -1,
      -1,   -1,   -1,   -1, 1333,   -1, 1334,   -1,
      -1,   -1,   -1, 1335,   -1,   -1, 1336,   -1,
      -1,   -1,   -1,   -1,   -1,   -1, 1337,   -1,
      -1, 1338,   -1,   -1,   -1,   -1,   -1, 1339,
      -1,   -1, 1340,   -1,   -1,   -1,   -1,   -1,
      -1, 1341,   -1, 1342,   -1,   -1, 1343,   -1,
      -1,   -1,   -1,   -1,   -1,   -1,   -1, 1344,
    1345,   -1,   -1, 1346, 1347, 1348,   -1,   -1,
      -1, 1349, 1350,   -1,   -1,   -1,   -1,   -1,
      -1,   -1,   -1, 1351, 1352,   -1,   -1,   -1,
      -1,   -1,   -1,   -1,   -1,   -1, 1353,   -1,
      -1,   -1, 1354,   -1,   -1,   -1,   -1, 1355,
    1356,   -1,   -1,   -1, 1357,   -1,   -1,   -1,
      -1, 1358, 1359,   -1,   -1,   -1, 1360, 1361,
      -1,   -1,   -1, 1362,   -1,   -1,   -1,   -1,
      -1, 1363,   -1,   -1, 1364, 1365,   -1,   -1,
      -1,   -1, 1366, 1367,   -1,   -1,   -1,   -1,
      -1,   -1,   -1,   -1,   -1, 1368,   -1,   -1,
      -1,   -1,   -1,   -1,   -1,   -1, 1369, 1370,
      -1,   -1,   -1, 1371,   -1,   -1,   -1,   -1,
      -1,   -1,   -1,   -1,   -1, 1372,   -1,   -1,
      -1,   -1,   -1, 1373,   -1,   -1,   -1,   -1,
      -1,   -1,   -1,   -1, 1374, 1375,   -1,   -1,
      -1,   -1, 1376,   -1,   -1,   -1, 1377, 1378,
      -1,   -1, 1379,   -1, 1380,   -1,   -1, 1381,
    1382, 1383,   -1,   -1, 1384,   -1,   -1,   -1,
      -1,   -1, 1385,   -1,   -1,   -1,   -1,   -1,
      -1, 1386,   -1, 1387,   -1, 1388,   -1,   -1,
      -1,   -1,   -1,   -1,   -1,   -1, 1389, 1390,
      -1,   -1,   -1,   -1, 1391, 1392, 1393,   -1,
    1394, 1395, 1396,   -1,   -1,   -1, 1397,   -1,
    1398, 1399, 1400, 1401,   -1,   -1,   -1,   -1,
    1402,   -1,   -1,   -1, 1403,   -1,   -1,   -1,
      -1,   -1,   -1,   -1,   -1,   -1,   -1, 1404,
    1405,   -1,   -1,   -1,   -1,   -1,   -1,   -1,
    1406, 1407,   -1,   -1,   -1,   -1, 1408,   -1,
      -1,   -1,   -1, 1409,   -1,   -1,   -1,   -1,
      -1,   -1,   -1,   -1,   -1, 1410, 1411,   -1,
      -1,   -1,   -1,   -1,   -1,   -1,   -1,   -1,
      -1,   -1,   -1,   -1,   -1,   -1,   -1,   -1,
      -1,   -1, 1412,   -1,   -1,   -1,   -1,   -1,
      -1,   -1,   -1,   -1,   -1,   -1, 1413,   -1,
      -1,   -1,   -1,   -1,   -1, 1414,   -1,   -1,
      -1,   -1, 1415,   -1,   -1,   -1,   -1,   -1,
      -1, 1416,   -1,   -1,   -1,   -1,   -1,   -1,
      -1, 1417,   -1,   -1,   -1,   -1, 1418,   -1,
      -1,   -1,   -1,   -1, 1419,   -1, 1420, 1421,
    1422, 1423,   -1,   -1,   -1,   -1,   -1,   -1,
      -1,   -1, 1424,   -1,   -1,   -1, 1425,   -1,
    1426, 1427,   -1,   -1, 1428,   -1,   -1,   -1,
      -1,   -1,   -1,   -1,   -1,   -1,   -1,   -1,
      -1,   -1,   -1,   -1,   -1,   -1,   -1,   -1,
      -1,   -1,   -1,   -1,   -1,   -1,   -1,   -1,
      -1,   -1, 1429, 1430,   -1,   -1,   -1, 1431,
      -1,   -1,   -1, 1432, 1433,   -1,   -1,   -1,
    1434, 1435,   -1,   -1,   -1,   -1,   -1, 1436,
      -1,   -1,   -1, 1437,   -1,   -1,   -1,   -1,
      -1,   -1,   -1,   -1,   -1,   -1, 1438,   -1,
      -1,   -1, 1439,   -1,   -1,   -1,   -1,   -1,
      -1,   -1,   -1,   -1, 1440, 1441,   -1,   -1,
      -1, 1442, 1443,   -1,   -1, 1444,   -1,   -1,
      -1,   -1,   -1,   -1,   -1,   -1,   -1,   -1,
      -1,   -1,   -1, 1445,   -1,   -1,   -1,   -1,
      -1,   -1,   -1,   -1,   -1, 1446,   -1,   -1,
      -1, 1447,   -1, 1448,   -1,   -1,   -1, 1449,
      -1,   -1,   -1,   -1,   -1,   -1,   -1,   -1,
      -1,   -1,   -1, 1450,   -1,   -1,   -1,   -1,
    1451,   -1,   -1, 1452,   -1,   -1,   -1,   -1,
    1453,   -1, 1454,   -1,   -1,   -1,   -1, 1455,
      -1,   -1, 1456,   -1, 1457,   -1,   -1,   -1,
      -1,   -1,   -1,   -1,   -1,   -1,   -1,   -1,
      -1, 1458,   -1, 1459,   -1,   -1, 1460,   -1,
      -1, 1461,   -1,   -1,   -1, 1462, 1463,   -1,
      -1,   -1,   -1,   -1,   -1,   -1, 1464, 1465,
      -1,   -1,   -1,   -1, 1466,   -1,   -1,   -1,
      -1,   -1, 1467,   -1,   -1,   -1, 1468,   -1,
      -1,   -1,   -1,   -1,   -1,   -1, 1469,   -1,
    1470,   -1,   -1, 1471,   -1,   -1,   -1,   -1,
      -1,   -1,   -1,   -1,   -1,   -1,   -1,   -1,
      -1,   -1,   -1,   -1,   -1,   -1,   -1,   -1,
      -1, 1472,   -1,   -1,   -1,   -1, 1473,   -1,
      -1,   -1,   -1,   -1,   -1, 1474,   -1,   -1,
      -1,   -1,   -1,   -1,   -1, 1475,   -1,   -1,
      -1,   -1, 1476,   -1,   -1,   -1, 1477,   -1,
      -1,   -1,   -1,   -1, 1478,   -1,   -1,   -1,
    1479, 1480, 1481,   -1,   -1, 1482,   -1,   -1,
      -1,   -1,   -1, 1483,   -1,   -1,   -1,   -1,
    1484,   -1,   -1,   -1,   -1, 1485,   -1,   -1,
      -1,   -1,   -1,   -1,   -1,   -1,   -1, 1486,
      -1,   -1,   -1,   -1,   -1,   -1, 1487,   -1,
      -1, 1488,   -1,   -1,   -1,   -1,   -1,   -1,
      -1, 1489, 1490,   -1, 1491,   -1,   -1,   -1,
      -1,   -1,   -1,   -1, 1492, 1493,   -1,   -1,
    1494,   -1,   -1,   -1,   -1,   -1,   -1,   -1,
      -1,   -1,   -1,   -1,   -1,   -1,   -1,   -1,
    1495,   -1,   -1,   -1,   -1,   -1, 1496,   -1,
    1497,   -1,   -1,   -1,   -1,   -1,   -1, 1498,
      -1,   -1,   -1,   -1,   -1,   -1,   -1,   -1,
      -1,   -1, 1499,   -1,   -1,   -1,   -1,   -1,
      -1,   -1,   -1,   -1,   -1,   -1,   -1,   -1,
      -1,   -1, 1500,   -1,   -1,   -1, 1501,   -1,
      -1,   -1,   -1, 1502, 1503,   -1,   -1,   -1,
      -1,   -1,   -1, 1504, 1505,   -1,   -1,   -1,
    1506, 1507,   -1, 1508,   -1,   -1,   -1, 1509,
      -1, 1510, 1511,   -1,   -1,   -1,   -1, 1512,
      -1,   -1,   -1,   -1, 1513,   -1, 1514,   -1,
      -1,   -1,   -1,   -1,   -1,   -1,   -1,   -1,
    1515,   -1,   -1,   -1,   -1,   -1,   -1,   -1,
      -1,   -1, 1516,   -1,   -1, 1517,   -1,   -1,
    1518,   -1,   -1,   -1, 1519,   -1,   -1,   -1,
      -1,   -1,   -1,   -1,   -1,   -1, 1520,   -1,
      -1,   -1,   -1, 1521,   -1,   -1,   -1,   -1,
    1522, 1523,   -1, 1524,   -1, 1525,   -1,   -1,
      -1,   -1,   -1,   -1,   -1,   -1,   -1,   -1,
      -1,   -1,   -1,   -1,   -1,   -1,   -1,   -1,
      -1, 1526,   -1,   -1, 1527, 1528, 1529,   -1,
      -1,   -1,   -1, 1530,   -1,   -1,   -1,   -1,
    1531,   -1, 1532,   -1,   -1,   -1,   -1,   -1,
      -1, 1533,   -1,   -1,   -1,   -1,   -1,   -1,
      -1,   -1,   -1,   -1,   -1,   -1,   -1,   -1,
    1534,   -1,   -1,   -1,   -1,   -1,   -1,   -1,
      -1,   -1,   -1, 1535,   -1, 1536,   -1,   -1,
    1537,   -1, 1538,   -1,   -1, 1539,   -1,   -1,
    1540,   -1, 1541,   -1,   -1,   -1,   -1,   -1,
      -1,   -1,   -1,   -1,   -1, 1542,   -1,   -1,
      -1, 1543,   -1, 1544,   -1,   -1, 1545,   -1,
      -1,   -1,   -1,   -1, 1546, 1547,   -1,   -1,
      -1, 1548, 1549,   -1, 1550, 1551,   -1,   -1,
      -1,   -1, 1552, 1553,   -1,   -1,   -1,   -1,
      -1,   -1,   -1,   -1,   -1,   -1,   -1,   -1,
      -1,   -1,   -1, 1554,   -1,   -1,   -1,   -1,
    1555,   -1,   -1, 1556,   -1, 1557,   -1,   -1,
      -1, 1558, 1559,   -1,   -1, 1560,   -1, 1561,
      -1,   -1,   -1,   -1, 1562,   -1,   -1,   -1,
      -1,   -1,   -1,   -1, 1563,   -1,   -1,   -1,
      -1, 1564,   -1,   -1,   -1,   -1,   -1,   -1,
      -1,   -1,   -1,   -1, 1565,   -1, 1566,   -1,
    1567,   -1,   -1,   -1,   -1,   -1, 1568, 1569,
      -1,   -1,   -1,   -1,   -1,   -1,   -1,   -1,
      -1, 1570, 1571,   -1,   -1, 1572,   -1,   -1,
      -1,   -1,   -1,   -1,   -1,   -1,   -1,   -1,
      -1,   -1,   -1, 1573,   -1,   -1,   -1,   -1,
      -1, 1574,   -1,   -1,   -1,   -1, 1575,   -1,
      -1,   -1,   -1,   -1,   -1,   -1,   -1, 1576,
    1577,   -1, 1578,   -1,   -1, 1579,   -1,   -1,
      -1, 1580, 1581,   -1, 1582,   -1,   -1,   -1,
      -1,   -1,   -1, 1583,   -1,   -1,   -1,   -1,
      -1,   -1,   -1,   -1,   -1, 1584,   -1,   -1,
      -1,   -1,   -1,   -1,   -1,   -1,   -1, 1585,
      -1,   -1,   -1,   -1,   -1,   -1,   -1,   -1,
      -1, 1586,   -1,   -1,   -1,   -1,   -1,   -1,
      -1, 1587,   -1,   -1,   -1,   -1,   -1,   -1,
    1588,   -1,   -1,   -1,   -1,   -1,   -1,   -1,
      -1,   -1,   -1,   -1,   -1,   -1,   -1,   -1,
      -1,   -1,   -1,   -1,   -1,   -1,   -1,   -1,
      -1,   -1,   -1,   -1,   -1,   -1,   -1,   -1,
      -1, 1589,   -1,   -1,   -1,   -1,   -1,   -1,
      -1,   -1,   -1,   -1, 1590,   -1,   -1, 1591,
      -1,   -1, 1592,   -1,   -1,   -1, 1593,   -1,
      -1,   -1,   -1,   -1, 1594,   -1,   -1,   -1,
    1595,   -1,   -1,   -1,   -1, 1596, 1597,   -1,
      -1,   -1,   -1, 1598,   -1,   -1, 1599, 1600,
      -1,   -1,   -1,   -1,   -1, 1601,   -1,   -1,
      -1,   -1,   -1,   -1,   -1,   -1,   -1,   -1,
      -1,   -1,   -1,   -1, 1602, 1603, 1604,   -1,
      -1, 1605,   -1,   -1,   -1, 1606,   -1,   -1,
      -1,   -1, 1607,   -1,   -1,   -1,   -1,   -1,
      -1, 1608,   -1,   -1,   -1, 1609,   -1,   -1,
      -1,   -1,   -1,   -1,   -1,   -1, 1610, 1611,
      -1,   -1, 1612,   -1, 1613,   -1,   -1,   -1,
    1614,   -1,   -1,   -1,   -1,   -1, 1615,   -1,
      -1,   -1,   -1,   -1,   -1,   -1,   -1,   -1,
    1616,   -1,   -1,   -1,   -1, 1617,   -1,   -1,
      -1,   -1, 1618,   -1,   -1,   -1,   -1, 1619,
      -1, 1620, 1621,   -1,   -1, 1622,   -1,   -1,
    1623,   -1, 1624,   -1,   -1,   -1,   -1,   -1,
      -1,   -1,   -1, 1625, 1626, 1627,   -1,   -1,
      -1, 1628,   -1,   -1,   -1, 1629,   -1,   -1,
      -1,   -1,   -1,   -1,   -1, 1630,   -1,   -1,
    1631,   -1,   -1,   -1, 1632,   -1,   -1,   -1,
      -1,   -1, 1633,   -1,   -1,   -1,   -1,   -1,
      -1,   -1,   -1,   -1,   -1,   -1,   -1,   -1,
      -1,   -1,   -1,   -1,   -1, 1634,   -1,   -1,
      -1,   -1, 1635,   -1, 1636,   -1,   -1, 1637,
      -1,   -1,   -1,   -1,   -1,   -1,   -1, 1638,
      -1,   -1,   -1,   -1,   -1,   -1,   -1, 1639,
      -1,   -1,   -1, 1640, 1641,   -1,   -1,   -1,
    1642, 1643,   -1,   -1,   -1,   -1, 1644,   -1,
      -1,   -1, 1645, 1646,   -1,   -1,   -1,   -1,
    1647,   -1,   -1,   -1, 1648,   -1, 1649,   -1,
      -1, 1650,   -1,   -1,   -1,   -1,   -1, 1651,
      -1,   -1,   -1, 1652,   -1,   -1,   -1,   -1,
      -1,   -1,   -1,   -1, 1653, 1654,   -1, 1655,
    1656,   -1,   -1, 1657,   -1,   -1,   -1, 1658,
      -1,   -1,   -1,   -1,   -1,   -1,   -1,   -1,
    1659,   -1,   -1,   -1,   -1,   -1,   -1,   -1,
      -1,   -1,   -1,   -1, 1660,   -1,   -1,   -1,
    1661,   -1,   -1,   -1,   -1,   -1,   -1,   -1,
    1662,   -1, 1663, 1664,   -1,   -1,   -1, 1665,
      -1,   -1,   -1,   -1,   -1,   -1,   -1,   -1,
      -1,   -1,   -1,   -1,   -1,   -1,   -1,   -1,
      -1,   -1,   -1, 1666, 1667,   -1,   -1,   -1,
    1668,   -1, 1669,   -1,   -1,   -1,   -1,   -1,
      -1,   -1, 1670,   -1, 1671, 1672,   -1,   -1,
      -1,   -1,   -1,   -1,   -1, 1673,   -1,   -1,
      -1,   -1,   -1,   -1, 1674,   -1, 1675,   -1,
      -1,   -1,   -1,   -1,   -1,   -1,   -1,   -1,
      -1,   -1,   -1, 1676,   -1,   -1,   -1,   -1,
      -1, 1677,   -1,   -1,   -1,   -1,   -1, 1678,
      -1,   -1,   -1,   -1, 1679,   -1,   -1,   -1,
      -1,   -1,   -1,   -1, 1680,   -1,   -1, 1681,
      -1,   -1, 1682, 1683,   -1,   -1,   -1,   -1,
      -1,   -1,   -1, 1684,   -1,   -1,   -1, 1685,
    1686,   -1, 1687,   -1,   -1,   -1,   -1, 1688,
      -1,   -1, 1689,   -1,   -1,   -1,   -1, 1690,
    1691, 1692,   -1,   -1,   -1,   -1,   -1,   -1,
      -1,   -1,   -1,   -1,   -1,   -1,   -1,   -1,
      -1,   -1,   -1,   -1,   -1,   -1,   -1,   -1,
      -1,   -1,   -1,   -1,   -1,   -1,   -1,   -1,
      -1,   -1,   -1,   -1,   -1, 1693,   -1,   -1,
      -1, 1694,   -1,   -1,   -1, 1695, 1696,   -1,
      -1,   -1, 1697,   -1,   -1,   -1,   -1,   -1,
      -1, 1698,   -1,   -1,   -1, 1699,   -1, 1700,
      -1,   -1,   -1,   -1,   -1,   -1,   -1,   -1,
      -1,   -1,   -1,   -1,   -1,   -1,   -1,   -1,
      -1,   -1,   -1, 1701,   -1,   -1,   -1,   -1,
      -1,   -1,   -1, 1702,   -1,   -1, 1703,   -1,
      -1,   -1, 1704,   -1,   -1,   -1,   -1,   -1,
      -1,   -1,   -1,   -1,   -1,   -1,   -1,   -1,
      -1,   -1,   -1,   -1,   -1,   -1,   -1, 1705,
      -1,   -1, 1706,   -1,   -1,   -1,   -1,   -1,
      -1,   -1,   -1,   -1,   -1,   -1,   -1,   -1,
    1707,   -1,   -1,   -1,   -1,   -1,   -1,   -1,
      -1,   -1,   -1,   -1,   -1,   -1,   -1, 1708,
      -1,   -1,   -1,   -1, 1709,   -1,   -1, 1710,
      -1, 1711,   -1,   -1,   -1,   -1,   -1,   -1,
      -1,   -1,   -1,   -1,   -1,   -1,   -1,   -1,
      -1,   -1, 1712,   -1,   -1,   -1,   -1,   -1,
    1713,   -1,   -1,   -1, 1714,   -1,   -1, 1715,
      -1, 1716,   -1,   -1, 1717,   -1, 1718,   -1,
      -1,   -1,   -1,   -1,   -1,   -1,   -1,   -1,
      -1,   -1,   -1,   -1,   -1,   -1,   -1,   -1,
      -1,   -1,   -1,   -1,   -1,   -1,   -1,   -1,
    1719,   -1, 1720,   -1,   -1,   -1,   -1, 1721,
      -1,   -1,   -1,   -1, 1722,   -1,   -1,   -1,
      -1, 1723,   -1,   -1,   -1,   -1,   -1,   -1,
      -1,   -1,   -1, 1724, 1725,   -1,   -1, 1726,
    1727,   -1,   -1,   -1,   -1,   -1,   -1,   -1,
      -1,   -1,   -1,   -1,   -1,   -1,   -1,   -1,
      -1,   -1,   -1, 1728, 1729,   -1,   -1,   -1,
      -1,   -1,   -1,   -1,   -1,   -1, 1730,   -1,
      -1,   -1,   -1,   -1,   -1,   -1, 1731,   -1,
      -1,   -1,   -1,   -1,   -1, 1732,   -1,   -1,
      -1,   -1,   -1,   -1,   -1,   -1,   -1, 1733,
      -1, 1734,   -1,   -1,   -1,   -1,   -1,   -1,
      -1,   -1,   -1, 1735,   -1,   -1,   -1, 1736,
    1737, 1738,   -1,   -1,   -1,   -1,   -1,   -1,
      -1,   -1, 1739,   -1,   -1,   -1,   -1, 1740,
      -1,   -1, 1741,   -1, 1742,   -1, 1743,   -1,
      -1,   -1,   -1,   -1,   -1, 1744,   -1,   -1,
      -1,   -1,   -1,   -1,   -1,   -1,   -1,   -1,
      -1,   -1,   -1,   -1,   -1,   -1,   -1,   -1,
      -1, 1745,   -1,   -1,   -1,   -1,   -1,   -1,
      -1,   -1, 1746,   -1,   -1, 1747,   -1,   -1,
    1748,   -1,   -1,   -1,   -1, 1749, 1750,   -1,
      -1,   -1,   -1,   -1,   -1,   -1, 1751,   -1,
      -1,   -1, 1752,   -1,   -1,   -1,   -1,   -1,
      -1,   -1,   -1,   -1,   -1,   -1,   -1,   -1,
      -1,   -1, 1753,   -1,   -1,   -1, 1754,   -1,
    1755, 1756,   -1,   -1,   -1, 1757,   -1, 1758,
      -1,   -1,   -1,   -1,   -1,   -1, 1759, 1760,
      -1,   -1,   -1,   -1, 1761,   -1,   -1,   -1,
      -1, 1762,   -1,   -1,   -1,   -1,   -1,   -1,
      -1,   -1,   -1,   -1,   -1,   -1,   -1, 1763,
      -1,   -1,   -1,   -1,   -1,   -1,   -1,   -1,
      -1, 1764,   -1,   -1,   -1,   -1,   -1,   -1,
      -1,   -1,   -1, 1765,   -1, 1766, 1767,   -1,
      -1,   -1,   -1,   -1,   -1,   -1,   -1,   -1,
    1768,   -1, 1769,   -1,   -1,   -1,   -1,   -1,
      -1,   -1,   -1,   -1,   -1, 1770, 1771,   -1,
      -1,   -1,   -1,   -1,   -1, 1772,   -1,   -1,
      -1,   -1,   -1, 1773,   -1, 1774,   -1,   -1,
      -1,   -1,   -1,   -1,   -1, 1775,   -1,   -1,
    1776,   -1,   -1,   -1,   -1,   -1,   -1, 1777,
      -1,   -1,   -1, 1778,   -1, 1779,   -1,   -1,
      -1,   -1,   -1, 1780,   -1,   -1,   -1,   -1,
      -1,   -1,   -1, 1781,   -1,   -1,   -1,   -1,
      -1,   -1,   -1,   -1,   -1,   -1,   -1,   -1,
      -1,   -1, 1782,   -1,   -1,   -1,   -1, 1783,
      -1,   -1, 1784,   -1,   -1,   -1,   -1,   -1,
      -1, 1785,   -1,   -1, 1786,   -1,   -1,   -1,
      -1,   -1,   -1, 1787,   -1,   -1,   -1, 1788,
      -1,   -1,   -1,   -1,   -1,   -1,   -1,   -1,
      -1,   -1,   -1,   -1, 1789,   -1,   -1,   -1,
      -1,   -1,   -1,   -1,   -1,   -1,   -1,   -1,
      -1,   -1,   -1,   -1,   -1,   -1,   -1,   -1,
      -1, 1790,   -1,   -1,   -1, 1791,   -1,   -1,
      -1,   -1,   -1,   -1, 1792,   -1,   -1,   -1,
      -1,   -1,   -1,   -1,   -1, 1793,   -1,   -1,
      -1,   -1,   -1,   -1,   -1,   -1, 1794, 1795,
      -1, 1796,   -1,   -1,   -1,   -1, 1797, 1798,
      -1,   -1,   -1,   -1,   -1, 1799,   -1,   -1,
    1800, 1801, 1802,   -1,   -1,   -1,   -1, 1803,
      -1,   -1, 1804,   -1,   -1,   -1, 1805, 1806,
      -1, 1807, 1808,   -1,   -1,   -1,   -1,   -1,
      -1,   -1,   -1,   -1,   -1,   -1, 1809,   -1,
      -1, 1810,   -1,   -1, 1811,   -1,   -1,   -1,
      -1,   -1,   -1, 1812,   -1, 1813, 1814,   -1,
      -1,   -1,   -1,   -1,   -1, 1815,   -1,   -1,
    1816,   -1,   -1,   -1,   -1,   -1,   -1, 1817,
      -1, 1818,   -1,   -1, 1819,   -1, 1820,   -1,
      -1,   -1,   -1,   -1,   -1,   -1,   -1,   -1,
    1821,   -1,   -1,   -1, 1822, 1823,   -1, 1824,
      -1,   -1, 1825,   -1,   -1,   -1,   -1, 1826,
      -1, 1827,   -1,   -1,   -1,   -1,   -1,   -1,
      -1, 1828,   -1,   -1,   -1,   -1,   -1,   -1,
      -1,   -1,   -1,   -1,   -1,   -1,   -1,   -1,
    1829,   -1, 1830,   -1,   -1, 1831, 1832,   -1,
      -1,   -1, 1833,   -1,   -1,   -1, 1834, 1835,
      -1,   -1,   -1,   -1, 1836,   -1, 1837,   -1,
      -1,   -1, 1838,   -1,   -1,   -1,   -1,   -1,
      -1,   -1,   -1, 1839,   -1,   -1,   -1,   -1,
      -1,   -1,   -1, 1840, 1841,   -1,   -1,   -1,
      -1,   -1,   -1,   -1,   -1,   -1,   -1,   -1,
    1842,   -1,   -1,   -1,   -1,   -1,   -1,   -1,
      -1, 1843,   -1,   -1,   -1,   -1,   -1,   -1,
    1844,   -1,   -1,   -1,   -1,   -1,   -1, 1845,
    1846,   -1,   -1,   -1,   -1, 1847,   -1,   -1,
    1848,   -1, 1849,   -1,   -1,   -1,   -1,   -1,
      -1,   -1,   -1,   -1, 1850,   -1,   -1,   -1,
      -1, 1851,   -1,   -1,   -1,   -1, 1852,   -1,
      -1,   -1,   -1,   -1,   -1, 1853,   -1, 1854,
      -1, 1855, 1856,   -1,   -1,   -1,   -1,   -1,
      -1,   -1, 1857,   -1,   -1,   -1,   -1,   -1,
      -1,   -1, 1858,   -1, 1859,   -1, 1860,   -1,
      -1, 1861,   -1,   -1,   -1,   -1, 1862,   -1,
      -1,   -1, 1863, 1864,   -1,   -1,   -1,   -1,
    1865,   -1,   -1,   -1,   -1, 1866,   -1,   -1,
      -1,   -1, 1867,   -1, 1868,   -1,   -1,   -1,
      -1, 1869,   -1, 1870,   -1,   -1,   -1,   -1,
      -1,   -1,   -1,   -1,   -1,   -1,   -1,   -1,
      -1,   -1,   -1, 1871,   -1, 1872,   -1,   -1,
    1873,   -1,   -1,   -1,   -1,   -1,   -1,   -1,
    1874,   -1,   -1,   -1,   -1,   -1,   -1,   -1,
      -1,   -1,   -1, 1875, 1876,   -1,   -1,   -1,
      -1,   -1,   -1,   -1,   -1,   -1,   -1,   -1,
      -1,   -1,   -1,   -1,   -1,   -1,   -1, 1877,
    1878,   -1,   -1,   -1,   -1,   -1,   -1,   -1,
      -1,   -1,   -1,   -1,   -1,   -1, 1879, 1880,
      -1,   -1,   -1,   -1, 1881,   -1,   -1,   -1,
      -1, 1882,   -1,   -1, 1883,   -1, 1884,   -1,
      -1, 1885,   -1, 1886,   -1,   -1,   -1, 1887,
    1888,   -1,   -1,   -1,   -1,   -1,   -1,   -1,
      -1,   -1, 1889,   -1,   -1,   -1,   -1, 1890,
      -1,   -1,   -1,   -1,   -1,   -1,   -1,   -1,
      -1, 1891, 1892,   -1,   -1,   -1, 1893,   -1,
      -1,   -1,   -1,   -1,   -1,   -1,   -1,   -1,
      -1,   -1,   -1,   -1,   -1, 1894, 1895,   -1,
      -1,   -1, 1896,   -1,   -1,   -1,   -1,   -1,
      -1,   -1,   -1,   -1,   -1, 1897,   -1,   -1,
      -1, 1898,   -1,   -1,   -1,   -1,   -1, 1899,
      -1,   -1,   -1,   -1,   -1,   -1,   -1,   -1,
    1900,   -1,   -1,   -1, 1901, 1902,   -1,   -1,
      -1,   -1,   -1,   -1,   -1,   -1, 1903,   -1,
      -1,   -1,   -1,   -1,   -1,   -1, 1904, 1905,
      -1,   -1,   -1, 1906,   -1,   -1,   -1,   -1,
      -1,   -1,   -1, 1907,   -1,   -1,   -1,   -1,
      -1,   -1,   -1,   -1,   -1,   -1,   -1,   -1,
      -1, 1908, 1909,   -1,   -1,   -1,   -1,   -1,
      -1,   -1,   -1,   -1,   -1,   -1,   -1, 1910,
      -1,   -1,   -1,   -1,   -1,   -1,   -1,   -1,
      -1,   -1,   -1,   -1,   -1,   -1,   -1, 1911,
      -1,   -1,   -1,   -1,   -1,   -1,   -1,   -1,
      -1,   -1,   -1,   -1,   -1,   -1,   -1,   -1,
      -1,   -1,   -1,   -1,   -1,   -1,   -1, 1912,
      -1,   -1,   -1,   -1,   -1, 1913,   -1,   -1,
      -1,   -1,   -1, 1914,   -1,   -1,   -1,   -1,
    1915,   -1,   -1,   -1,   -1, 1916,   -1,   -1,
      -1,   -1,   -1,   -1,   -1,   -1, 1917,   -1,
      -1,   -1,   -1,   -1, 1918,   -1,   -1,   -1,
      -1, 1919,   -1,   -1,   -1,   -1,   -1,   -1,
      -1,   -1,   -1, 1920,   -1,   -1,   -1,   -1,
      -1,   -1,   -1,   -1,   -1, 1921,   -1,   -1,
      -1,   -1,   -1,   -1,   -1,   -1,   -1, 1922,
      -1,   -1,   -1,   -1,   -1,   -1, 1923,   -1,
    1924,   -1,   -1,   -1,   -1,   -1, 1925,   -1,
      -1,   -1, 1926, 1927,   -1,   -1,   -1,   -1,
      -1,   -1, 1928,   -1, 1929,   -1,   -1,   -1,
      -1,   -1,   -1,   -1,   -1,   -1, 1930,   -1,
      -1,   -1,   -1,   -1,   -1,   -1,   -1,   -1,
      -1,   -1,   -1,   -1,   -1,   -1,   -1,   -1,
    1931, 1932,   -1,   -1,   -1,   -1,   -1,   -1,
    1933,   -1,   -1,   -1,   -1,   -1, 1934,   -1,
      -1,   -1, 1935,   -1,   -1,   -1,   -1,   -1,
      -1,   -1,   -1,   -1,   -1,   -1,   -1,   -1,
      -1,   -1,   -1,   -1,   -1,   -1, 1936,   -1,
      -1,   -1,   -1,   -1,   -1,   -1,   -1,   -1,
    1937,   -1,   -1, 1938,   -1,   -1,   -1,   -1,
      -1,   -1,   -1,   -1,   -1,   -1,   -1,   -1,
      -1,   -1,   -1,   -1,   -1,   -1, 1939,   -1,
      -1,   -1,   -1,   -1,   -1,   -1, 1940,   -1,
      -1,   -1,   -1,   -1,   -1,   -1,   -1,   -1,
      -1,   -1,   -1,   -1,   -1,   -1,   -1,   -1,
    1941,   -1,   -1,   -1,   -1,   -1, 1942,   -1,
    1943,   -1,   -1,   -1,   -1,   -1,   -1,   -1,
      -1,   -1,   -1,   -1,   -1,   -1, 1944,   -1,
      -1,   -1,   -1,   -1,   -1,   -1,   -1,   -1,
    1945,   -1,   -1,   -1,   -1, 1946,   -1,   -1,
      -1,   -1, 1947,   -1,   -1,   -1,   -1,   -1,
      -1,   -1,   -1,   -1, 1948,   -1,   -1,   -1,
      -1,   -1,   -1,   -1, 1949,   -1, 1950,   -1,
      -1,   -1,   -1, 1951,   -1,   -1, 1952,   -1,
    1953,   -1, 1954,   -1,   -1,   -1,   -1, 1955,
      -1,   -1,   -1,   -1,   -1,   -1,   -1,   -1,
      -1,   -1,   -1,   -1, 1956,   -1,   -1,   -1,
      -1,   -1,   -1,   -1,   -1,   -1,   -1, 1957,
    1958,   -1,   -1, 1959,   -1,   -1,   -1,   -1,
    1960,   -1,   -1, 1961,   -1, 1962,   -1,   -1,
      -1,   -1,   -1, 1963,   -1,   -1,   -1, 1964,
      -1,   -1, 1965,   -1,   -1,   -1, 1966,   -1,
      -1,   -1,   -1,   -1,   -1,   -1,   -1,   -1,
    1967,   -1,   -1,   -1,   -1,   -1,   -1,   -1,
      -1,   -1,   -1,   -1,   -1, 1968,   -1, 1969,
      -1,   -1,   -1, 1970, 1971,   -1,   -1,   -1,
      -1,   -1,   -1,   -1,   -1,   -1,   -1,   -1,
      -1,   -1,   -1,   -1, 1972,   -1,   -1,   -1,
      -1,   -1,   -1,   -1, 1973,   -1,   -1,   -1,
      -1,   -1,   -1,   -1,   -1, 1974,   -1,   -1,
      -1,   -1,   -1,   -1,   -1,   -1,   -1, 1975,
      -1,   -1,   -1,   -1,   -1,   -1,   -1,   -1,
      -1, 1976,   -1,   -1,   -1,   -1,   -1, 1977,
      -1,   -1,   -1,   -1, 1978,   -1,   -1, 1979,
    1980,   -1, 1981,   -1,   -1,   -1,   -1,   -1,
      -1,   -1,   -1,   -1,   -1,   -1,   -1,   -1,
      -1,   -1,   -1,   -1,   -1,   -1, 1982,   -1,
      -1,   -1,   -1,   -1,   -1,   -1,   -1,   -1,
      -1, 1983,   -1, 1984,   -1,   -1,   -1,   -1,
    1985,   -1,   -1,   -1,   -1, 1986,   -1,   -1,
      -1,   -1,   -1,   -1,   -1, 1987,   -1,   -1,
      -1,   -1,   -1,   -1,   -1, 1988,   -1,   -1,
      -1,   -1,   -1,   -1,   -1, 1989,   -1, 1990,
      -1,   -1, 1991,   -1,   -1,   -1,   -1,   -1,
      -1,   -1,   -1,   -1,   -1, 1992,   -1,   -1,
      -1,   -1,   -1,   -1,   -1,   -1,   -1,   -1,
      -1,   -1,   -1,   -1,   -1,   -1,   -1,   -1,
      -1,   -1, 1993, 1994,   -1,   -1,   -1,   -1,
      -1,   -1,   -1,   -1,   -1,   -1,   -1,   -1,
      -1, 1995,   -1,   -1,   -1, 1996,   -1,   -1,
      -1,   -1,   -1,   -1,   -1, 1997,   -1,   -1,
      -1,   -1,   -1,   -1,   -1,   -1,   -1,   -1,
      -1,   -1,   -1,   -1,   -1, 1998,   -1,   -1,
      -1,   -1,   -1, 1999,   -1,   -1,   -1,   -1,
      -1,   -1, 2000,   -1,   -1,   -1,   -1,   -1,
      -1,   -1, 2001,   -1,   -1,   -1, 2002, 2003,
      -1,   -1,   -1,   -1, 2004,   -1, 2005,   -1,
    2006,   -1,   -1,   -1,   -1,   -1,   -1,   -1,
      -1,   -1,   -1,   -1,   -1,   -1,   -1,   -1,
      -1,   -1,   -1, 2007,   -1,   -1,   -1,   -1,
      -1,   -1, 2008,   -1,   -1,   -1,   -1,   -1,
      -1, 2009,   -1,   -1,   -1,   -1,   -1,   -1,
      -1,   -1,   -1,   -1,   -1,   -1,   -1,   -1,
      -1,   -1,   -1, 2010,   -1,   -1,   -1,   -1,
      -1,   -1,   -1,   -1,   -1,   -1,   -1,   -1,
      -1,   -1,   -1,   -1,   -1,   -1,   -1, 2011,
      -1,   -1,   -1, 2012,   -1,   -1,   -1,   -1,
      -1,   -1,   -1,   -1,   -1,   -1,   -1,   -1,
      -1,   -1,   -1,   -1,   -1,   -1,   -1,   -1,
      -1,   -1,   -1,   -1,   -1,   -1,   -1,   -1,
      -1,   -1,   -1,   -1,   -1,   -1,   -1,   -1,
      -1,   -1,   -1,   -1,   -1,   -1,   -1,   -1,
      -1, 2013,   -1,   -1,   -1,   -1,   -1,   -1,
      -1,   -1,   -1,   -1,   -1,   -1,   -1,   -1,
      -1,   -1,   -1,   -1,   -1,   -1, 2014, 2015,
      -1,   -1,   -1,   -1,   -1,   -1,   -1,   -1,
      -1,   -1, 2016,   -1,   -1,   -1,   -1,   -1,
      -1,   -1,   -1,   -1, 2017,   -1,   -1,   -1,
      -1,   -1,   -1,   -1,   -1,   -1, 2018,   -1,
      -1,   -1,   -1, 2019,   -1,   -1,   -1,   -1,
      -1,   -1,   -1,   -1,   -1, 2020,   -1,   -1,
      -1,   -1,   -1,   -1,   -1,   -1, 2021,   -1,
      -1,   -1,   -1,   -1,   -1,   -1,   -1,   -1,
      -1,   -1,   -1, 2022,   -1,   -1,   -1,   -1,
      -1,   -1, 2023,   -1,   -1,   -1,   -1,   -1,
      -1,   -1,   -1,   -1,   -1,   -1,   -1,   -1,
      -1,   -1,   -1,   -1,   -1,   -1,   -1,   -1,
      -1, 2024, 2025,   -1, 2026,   -1,   -1,   -1,
      -1,   -1,   -1, 2027,   -1,   -1,   -1,   -1,
      -1,   -1,   -1, 2028,   -1,   -1,   -1,   -1,
      -1,   -1, 2029,   -1,   -1,   -1, 2030, 2031,
      -1,   -1,   -1,   -1,   -1,   -1,   -1,   -1,
      -1,   -1,   -1,   -1,   -1,   -1, 2032,   -1,
      -1,   -1,   -1,   -1,   -1,   -1,   -1, 2033,
      -1,   -1,   -1, 2034,   -1,   -1,   -1,   -1,
      -1,   -1,   -1,   -1,   -1,   -1,   -1,   -1,
      -1,   -1,   -1,   -1,   -1,   -1, 2035,   -1,
      -1,   -1,   -1,   -1,   -1,   -1,   -1,   -1,
      -1,   -1,   -1,   -1,   -1, 2036, 2037,   -1,
      -1,   -1,   -1,   -1,   -1,   -1,   -1,   -1,
      -1,   -1,   -1,   -1,   -1,   -1,   -1,   -1,
      -1, 2038,   -1,   -1,   -1,   -1,   -1,   -1,
      -1,   -1,   -1,   -1,   -1,   -1,   -1,   -1,
      -1,   -1,   -1,   -1,   -1,   -1,   -1, 2039,
    2040,   -1, 2041,   -1,   -1,   -1,   -1,   -1,
      -1,   -1,   -1,   -1,   -1,   -1,   -1,   -1,
      -1,   -1,   -1,   -1, 2042, 2043, 2044,   -1,
      -1,   -1,   -1,   -1,   -1,   -1,   -1,   -1,
      -1,   -1,   -1,   -1,   -1,   -1,   -1, 2045,
      -1,   -1, 2046,   -1,   -1,   -1,   -1,   -1,
      -1,   -1,   -1, 2047,   -1,   -1,   -1,   -1,
      -1,   -1,   -1,   -1,   -1,   -1,   -1,   -1,
      -1,   -1,   -1, 2048,   -1,   -1,   -1,   -1,
      -1,   -1,   -1, 2049, 2050,   -1,   -1,   -1,
      -1,   -1,   -1,   -1,   -1,   -1,   -1,   -1,
      -1,   -1, 2051,   -1,   -1,   -1,   -1,   -1,
      -1,   -1,   -1, 2052,   -1,   -1,   -1,   -1,
      -1,   -1,   -1,   -1,   -1,   -1,   -1,   -1,
      -1,   -1,   -1, 2053,   -1,   -1,   -1,   -1,
      -1,   -1,   -1,   -1,   -1,   -1,   -1, 2054,
      -1,   -1,   -1,   -1,   -1,   -1,   -1,   -1,
      -1,   -1, 2055, 2056,   -1,   -1,   -1,   -1,
      -1,   -1,   -1,   -1,   -1,   -1, 2057,   -1,
      -1,   -1,   -1,   -1,   -1,   -1,   -1,   -1,
      -1,   -1,   -1,   -1,   -1,   -1,   -1,   -1,
      -1,   -1,   -1,   -1,   -1,   -1,   -1, 2058,
    2059,   -1,   -1,   -1, 2060,   -1,   -1,   -1,
      -1,   -1,   -1,   -1,   -1,   -1,   -1, 2061,
      -1,   -1, 2062,   -1,   -1, 2063,   -1,   -1,
      -1,   -1,   -1, 2064,   -1,   -1,   -1, 2065,
      -1,   -1, 2066,   -1,   -1,   -1,   -1,   -1,
      -1,   -1,   -1,   -1,   -1,   -1,   -1, 2067,
      -1,   -1,   -1,   -1,   -1,   -1,   -1,   -1,
      -1,   -1,   -1,   -1,   -1,   -1,   -1,   -1,
      -1,   -1,   -1,   -1,   -1,   -1,   -1,   -1,
      -1,   -1,   -1,   -1,   -1,   -1,   -1,   -1,
      -1,   -1,   -1,   -1,   -1,   -1,   -1, 2068,
      -1,   -1,   -1,   -1,   -1,   -1,   -1,   -1,
      -1,   -1,   -1,   -1,   -1,   -1,   -1,   -1,
      -1,   -1,   -1, 2069,   -1,   -1,   -1,   -1,
      -1,   -1,   -1,   -1,   -1, 2070,   -1,   -1,
      -1,   -1,   -1,   -1,   -1, 2071,   -1,   -1,
      -1,   -1,   -1,   -1,   -1,   -1,   -1,   -1,
      -1,   -1,   -1, 2072,   -1,   -1,   -1, 2073,
      -1,   -1,   -1, 2074,   -1,   -1,   -1, 2075,
    2076,   -1, 2077,   -1,   -1,   -1,   -1,   -1,
      -1,   -1,   -1,   -1,   -1,   -1,   -1,   -1,
      -1,   -1,   -1,   -1,   -1,   -1, 2078,   -1,
      -1,   -1,   -1,   -1,   -1,   -1,   -1, 2079,
      -1,   -1,   -1,   -1,   -1,   -1,   -1,   -1,
      -1,   -1,   -1,   -1,   -1,   -1,   -1,   -1,
      -1,   -1,   -1,   -1,   -1,   -1,   -1,   -1,
      -1,   -1,   -1,   -1,   -1,   -1,   -1,   -1,
      -1,   -1,   -1,   -1,   -1,   -1,   -1,   -1,
      -1, 2080,   -1, 2081,   -1,   -1, 2082,   -1,
      -1,   -1,   -1,   -1,   -1,   -1,   -1,   -1,
      -1,   -1,   -1,   -1,   -1,   -1,   -1,   -1,
      -1,   -1,   -1,   -1,   -1,   -1,   -1,   -1,
      -1,   -1,   -1,   -1,   -1,   -1,   -1, 2083,
    2084,   -1,   -1,   -1,   -1,   -1,   -1,   -1,
      -1,   -1,   -1,   -1,   -1,   -1,   -1,   -1,
      -1,   -1,   -1,   -1,   -1,   -1,   -1,   -1,
      -1, 2085,   -1,   -1,   -1,   -1,   -1,   -1,
      -1, 2086,   -1,   -1,   -1, 2087, 2088,   -1,
      -1,   -1,   -1,   -1,   -1,   -1,   -1,   -1,
      -1,   -1,   -1,   -1,   -1,   -1,   -1,   -1,
      -1, 2089,   -1,   -1,   -1,   -1,   -1,   -1,
      -1, 2090, 2091, 2092,   -1, 2093,   -1,   -1,
      -1,   -1,   -1,   -1,   -1,   -1,   -1,   -1,
      -1,   -1,   -1, 2094,   -1,   -1,   -1,   -1,
      -1,   -1,   -1,   -1,   -1,   -1, 2095,   -1,
      -1,   -1,   -1,   -1,   -1,   -1,   -1,   -1,
      -1,   -1,   -1,   -1,   -1,   -1,   -1,   -1,
      -1,   -1,   -1,   -1,   -1,   -1,   -1,   -1,
      -1,   -1,   -1,   -1,   -1,   -1,   -1,   -1,
      -1,   -1,   -1,   -1,   -1,   -1,   -1, 2096,
      -1,   -1,   -1,   -1,   -1,   -1,   -1,   -1,
      -1,   -1, 2097,   -1, 2098,   -1,   -1,   -1,
      -1,   -1,   -1,   -1,   -1,   -1, 2099,   -1,
      -1, 2100,   -1,   -1,   -1,   -1,   -1,   -1,
    2101, 2102,   -1,   -1,   -1,   -1,   -1,   -1,
      -1,   -1,   -1,   -1,   -1,   -1,   -1,   -1,
      -1,   -1,   -1,   -1,   -1,   -1, 2103,   -1,
      -1,   -1,   -1,   -1,   -1,   -1,   -1,   -1,
      -1,   -1,   -1,   -1,   -1,   -1,   -1,   -1,
    2104,   -1,   -1,   -1,   -1,   -1,   -1,   -1,
      -1,   -1,   -1,   -1,   -1, 2105,   -1,   -1,
      -1,   -1,   -1, 2106,   -1,   -1, 2107,   -1,
      -1,   -1,   -1, 2108,   -1,   -1,   -1,   -1,
      -1,   -1,   -1,   -1,   -1, 2109,   -1,   -1,
      -1, 2110,   -1,   -1,   -1,   -1,   -1,   -1,
      -1,   -1,   -1,   -1,   -1,   -1,   -1,   -1,
      -1,   -1,   -1,   -1,   -1,   -1,   -1,   -1,
      -1, 2111,   -1,   -1,   -1,   -1,   -1,   -1,
      -1,   -1,   -1,   -1,   -1,   -1,   -1,   -1,
      -1,   -1,   -1,   -1,   -1,   -1,   -1,   -1,
      -1,   -1, 2112,   -1,   -1,   -1,   -1,   -1,
      -1,   -1,   -1,   -1,   -1,   -1,   -1,   -1,
      -1,   -1,   -1,   -1,   -1,   -1,   -1,   -1,
      -1,   -1,   -1,   -1,   -1, 2113,   -1,   -1,
      -1,   -1,   -1,   -1,   -1,   -1,   -1,   -1,
      -1,   -1,   -1,   -1, 2114,   -1,   -1,   -1,
      -1, 2115,   -1,   -1,   -1,   -1,   -1,   -1,
      -1,   -1,   -1,   -1,   -1,   -1, 2116,   -1,
      -1,   -1,   -1,   -1,   -1,   -1,   -1,   -1,
      -1,   -1,   -1,   -1,   -1,   -1, 2117,   -1,
      -1,   -1,   -1,   -1,   -1,   -1,   -1, 2118,
      -1,   -1,   -1,   -1,   -1,   -1, 2119,   -1,
      -1,   -1,   -1,   -1,   -1,   -1,   -1,   -1,
      -1,   -1,   -1,   -1,   -1,   -1,   -1,   -1,
      -1,   -1,   -1,   -1,   -1,   -1,   -1,   -1,
      -1,   -1,   -1, 2120,   -1,   -1, 2121,   -1,
      -1,   -1,   -1,   -1,   -1,   -1,   -1,   -1,
      -1,   -1,   -1,   -1, 2122,   -1,   -1,   -1,
      -1,   -1,   -1,   -1,   -1,   -1,   -1,   -1,
      -1,   -1,   -1, 2123,   -1,   -1,   -1,   -1,
      -1, 2124,   -1,   -1,   -1, 2125,   -1,   -1,
      -1,   -1, 2126,   -1,   -1,   -1, 2127,   -1,
      -1,   -1,   -1,   -1,   -1,   -1,   -1,   -1,
      -1,   -1,   -1,   -1,   -1,   -1, 2128, 2129,
      -1,   -1,   -1,   -1,   -1,   -1,   -1,   -1,
      -1,   -1,   -1,   -1, 2130,   -1,   -1,   -1,
      -1,   -1, 2131,   -1,   -1,   -1,   -1,   -1,
      -1,   -1, 2132,   -1, 2133,   -1,   -1,   -1,
      -1,   -1, 2134,   -1,   -1,   -1,   -1,   -1,
      -1,   -1,   -1,   -1, 2135, 2136,   -1, 2137,
      -1,   -1,   -1,   -1, 2138,   -1,   -1,   -1,
      -1,   -1,   -1,   -1,   -1,   -1,   -1,   -1,
      -1,   -1,   -1,   -1,   -1,   -1,   -1,   -1,
    2139,   -1,   -1,   -1,   -1,   -1,   -1,   -1,
      -1,   -1,   -1,   -1,   -1,   -1,   -1,   -1,
      -1,   -1,   -1,   -1,   -1,   -1,   -1,   -1,
      -1,   -1,   -1,   -1, 2140,   -1,   -1, 2141,
      -1,   -1,   -1,   -1,   -1,   -1,   -1, 2142,
      -1,   -1,   -1, 2143,   -1,   -1,   -1,   -1,
      -1,   -1,   -1, 2144,   -1, 2145,   -1,   -1,
    2146, 2147,   -1,   -1,   -1,   -1,   -1, 2148,
      -1,   -1, 2149,   -1,   -1,   -1,   -1,   -1,
      -1, 2150,   -1,   -1, 2151,   -1,   -1,   -1,
      -1,   -1,   -1,   -1,   -1,   -1,   -1,   -1,
      -1,   -1,   -1,   -1,   -1,   -1,   -1,   -1,
      -1,   -1,   -1,   -1, 2152,   -1,   -1,   -1,
      -1,   -1,   -1,   -1,   -1, 2153,   -1,   -1,
      -1,   -1,   -1,   -1,   -1,   -1,   -1,   -1,
      -1,   -1,   -1,   -1,   -1, 2154, 2155,   -1,
    2156, 2157,   -1,   -1,   -1,   -1,   -1,   -1,
      -1,   -1,   -1,   -1,   -1,   -1,   -1,   -1,
      -1,   -1,   -1,   -1,   -1, 2158,   -1,   -1,
      -1, 2159,   -1, 2160,   -1,   -1,   -1,   -1,
    2161,   -1,   -1, 2162,   -1,   -1,   -1,   -1,
    2163,   -1,   -1,   -1,   -1, 2164,   -1, 2165,
      -1,   -1, 2166,   -1,   -1,   -1,   -1, 2167,
      -1,   -1,   -1,   -1,   -1,   -1,   -1,   -1,
      -1,   -1,   -1,   -1,   -1,   -1,   -1,   -1,
      -1, 2168,   -1,   -1,   -1,   -1,   -1,   -1,
      -1,   -1,   -1, 2169,   -1,   -1,   -1,   -1,
      -1,   -1,   -1, 2170,   -1,   -1,   -1,   -1,
      -1,   -1,   -1,   -1,   -1,   -1,   -1,   -1,
      -1,   -1,   -1,   -1, 2171,   -1, 2172, 2173,
      -1,   -1,   -1, 2174,   -1, 2175,   -1,   -1,
      -1,   -1, 2176,   -1,   -1,   -1,   -1,   -1,
      -1,   -1,   -1,   -1,   -1,   -1,   -1,   -1,
      -1,   -1, 2177,   -1,   -1,   -1,   -1,   -1,
      -1,   -1,   -1,   -1,   -1,   -1,   -1,   -1,
      -1,   -1,   -1,   -1,   -1,   -1,   -1,   -1,
      -1,   -1,   -1,   -1,   -1,   -1,   -1,   -1,
      -1, 2178,   -1,   -1,   -1,   -1,   -1,   -1,
      -1,   -1,   -1, 2179,   -1,   -1,   -1,   -1,
      -1,   -1,   -1,   -1,   -1,   -1,   -1,   -1,
      -1, 2180,   -1,   -1,   -1,   -1, 2181,   -1,
      -1,   -1, 2182, 2183,   -1,   -1,   -1, 2184,
      -1,   -1,   -1,   -1,   -1,   -1, 2185,   -1,
      -1, 2186,   -1,   -1,   -1,   -1, 2187, 2188,
      -1,   -1,   -1,   -1,   -1,   -1,   -1,   -1,
      -1, 2189, 2190,   -1,   -1,   -1,   -1, 2191,
      -1,   -1,   -1,   -1,   -1,   -1, 2192,   -1,
      -1,   -1,   -1,   -1,   -1,   -1,   -1,   -1,
      -1,   -1,   -1,   -1,   -1, 2193,   -1,   -1,
      -1, 2194,   -1,   -1,   -1,   -1,   -1, 2195,
      -1,   -1,   -1,   -1,   -1, 2196,   -1,   -1,
      -1, 2197,   -1,   -1,   -1, 2198, 2199,   -1,
      -1,   -1,   -1,   -1, 2200,   -1,   -1,   -1,
    2201,   -1,   -1,   -1,   -1, 2202,   -1,   -1,
      -1,   -1, 2203,   -1,   -1,   -1, 2204, 2205,
      -1,   -1,   -1,   -1, 2206,   -1,   -1,   -1,
    2207,   -1,   -1,   -1,   -1,   -1,   -1,   -1,
      -1,   -1,   -1,   -1,   -1,   -1,   -1,   -1,
    2208,   -1,   -1,   -1,   -1, 2209, 2210,   -1,
      -1,   -1,   -1,   -1, 2211,   -1,   -1,   -1,
      -1, 2212,   -1,   -1,   -1,   -1,   -1,   -1,
    2213,   -1,   -1,   -1,   -1,   -1, 2214,   -1,
    2215,   -1,   -1, 2216,   -1,   -1,   -1,   -1,
    2217,   -1,   -1,   -1,   -1,   -1,   -1,   -1,
      -1, 2218, 2219,   -1, 2220,   -1,   -1,   -1,
    2221,   -1, 2222, 2223,   -1,   -1, 2224,   -1,
      -1,   -1,   -1,   -1, 2225, 2226,   -1,   -1,
      -1,   -1, 2227,   -1,   -1,   -1,   -1,   -1,
      -1,   -1,   -1,   -1,   -1,   -1, 2228,   -1,
      -1,   -1, 2229,   -1,   -1,   -1,   -1,   -1,
      -1,   -1, 2230,   -1,   -1,   -1,   -1,   -1,
    2231,   -1,   -1,   -1,   -1, 2232, 2233,   -1,
      -1,   -1,   -1,   -1,   -1,   -1,   -1, 2234,
      -1, 2235,   -1,   -1,   -1,   -1,   -1,   -1,
      -1, 2236,   -1,   -1,   -1, 2237,   -1, 2238,
    2239,   -1,   -1,   -1, 2240,   -1,   -1,   -1,
      -1,   -1,   -1,   -1,   -1,   -1,   -1,   -1,
      -1,   -1,   -1,   -1,   -1,   -1,   -1,   -1,
      -1,   -1,   -1,   -1,   -1, 2241,   -1,   -1,
      -1,   -1,   -1,   -1,   -1,   -1,   -1,   -1,
      -1,   -1,   -1,   -1, 2242,   -1,   -1,   -1,
      -1, 2243,   -1, 2244,   -1,   -1,   -1, 2245,
      -1,   -1, 2246,   -1,   -1,   -1,   -1, 2247,
      -1,   -1,   -1,   -1,   -1,   -1,   -1,   -1,
      -1,   -1,   -1, 2248,   -1,   -1,   -1,   -1,
      -1, 2249,   -1,   -1,   -1,   -1,   -1,   -1,
      -1,   -1, 2250,   -1, 2251,   -1,   -1,   -1,
      -1,   -1,   -1,   -1,   -1,   -1, 2252,   -1,
      -1, 2253,   -1,   -1,   -1,   -1,   -1,   -1,
      -1,   -1,   -1,   -1,   -1,   -1,   -1,   -1,
      -1,   -1,   -1,   -1,   -1,   -1,   -1,   -1,
    2254,   -1,   -1, 2255,   -1,   -1, 2256,   -1,
      -1,   -1,   -1,   -1,   -1,   -1,   -1,   -1,
      -1,   -1,   -1,   -1,   -1,   -1,   -1,   -1,
      -1,   -1,   -1,   -1,   -1,   -1,   -1,   -1,
      -1,   -1,   -1,   -1,   -1,   -1, 2257,   -1,
      -1,   -1,   -1,   -1,   -1,   -1,   -1,   -1,
      -1, 2258,   -1,   -1,   -1,   -1,   -1,   -1,
      -1,   -1,   -1,   -1,   -1,   -1,   -1, 2259,
      -1, 2260,   -1,   -1,   -1,   -1,   -1,   -1,
      -1,   -1,   -1,   -1,   -1,   -1,   -1,   -1,
      -1,   -1,   -1,   -1,   -1,   -1, 2261,   -1,
      -1,   -1,   -1, 2262,   -1,   -1,   -1,   -1,
      -1, 2263,   -1,   -1, 2264, 2265, 2266,   -1,
      -1,   -1, 2267, 2268,   -1,   -1,   -1,   -1,
      -1, 2269,   -1,   -1,   -1,   -1,   -1,   -1,
      -1,   -1,   -1,   -1,   -1,   -1,   -1,   -1,
      -1,   -1,   -1,   -1,   -1,   -1,   -1,   -1,
      -1,   -1,   -1,   -1,   -1,   -1,   -1,   -1,
      -1,   -1,   -1,   -1,   -1,   -1,   -1,   -1,
      -1, 2270, 2271,   -1,   -1,   -1,   -1,   -1,
    2272,   -1,   -1,   -1,   -1,   -1,   -1,   -1,
      -1, 2273,   -1,   -1,   -1,   -1,   -1,   -1,
      -1,   -1, 2274,   -1,   -1, 2275,   -1,   -1,
      -1,   -1,   -1,   -1, 2276,   -1,   -1,   -1,
      -1, 2277,   -1,   -1,   -1,   -1, 2278,   -1,
      -1,   -1,   -1,   -1,   -1,   -1, 2279,   -1,
      -1,   -1,   -1,   -1,   -1, 2280, 2281,   -1,
      -1,   -1,   -1,   -1, 2282,   -1,   -1, 2283,
      -1,   -1,   -1,   -1,   -1,   -1,   -1,   -1,
    2284,   -1,   -1,   -1,   -1,   -1,   -1,   -1,
      -1,   -1,   -1,   -1,   -1, 2285, 2286,   -1,
      -1,   -1,   -1,   -1,   -1,   -1, 2287,   -1,
    2288,   -1,   -1,   -1,   -1,   -1, 2289,   -1,
      -1,   -1,   -1,   -1, 2290,   -1,   -1,   -1,
      -1,   -1,   -1,   -1,   -1,   -1,   -1, 2291,
      -1, 2292,   -1,   -1, 2293,   -1,   -1,   -1,
    2294,   -1,   -1,   -1,   -1,   -1,   -1,   -1,
    2295,   -1,   -1,   -1,   -1,   -1,   -1,   -1,
      -1,   -1,   -1,   -1,   -1,   -1, 2296,   -1,
      -1,   -1,   -1,   -1,   -1,   -1,   -1,   -1,
      -1,   -1,   -1,   -1, 2297,   -1,   -1,   -1,
      -1,   -1,   -1,   -1, 2298,   -1,   -1,   -1,
      -1,   -1,   -1,   -1,   -1,   -1,   -1, 2299,
      -1,   -1,   -1,   -1,   -1,   -1,   -1,   -1,
      -1,   -1,   -1,   -1,   -1,   -1,   -1,   -1,
      -1,   -1,   -1,   -1,   -1,   -1,   -1,   -1,
      -1,   -1, 2300,   -1, 2301,   -1, 2302,   -1,
      -1, 2303,   -1, 2304, 2305,   -1,   -1,   -1,
      -1,   -1,   -1,   -1,   -1, 2306,   -1,   -1,
      -1,   -1, 2307,   -1, 2308,   -1,   -1,   -1,
      -1,   -1,   -1,   -1,   -1,   -1,   -1,   -1,
      -1,   -1,   -1,   -1,   -1,   -1,   -1, 2309,
      -1, 2310,   -1, 2311,   -1,   -1,   -1,   -1,
    2312,   -1,   -1,   -1,   -1, 2313,   -1, 2314,
      -1,   -1,   -1,   -1,   -1,   -1,   -1,   -1,
      -1, 2315,   -1,   -1,   -1,   -1,   -1,   -1,
    2316,   -1,   -1,   -1,   -1,   -1, 2317,   -1,
      -1,   -1,   -1,   -1, 2318,   -1,   -1,   -1,
      -1,   -1, 2319,   -1,   -1,   -1,   -1,   -1,
      -1, 2320,   -1,   -1,   -1,   -1,   -1,   -1,
      -1, 2321,   -1,   -1,   -1,   -1,   -1,   -1,
      -1,   -1,   -1,   -1,   -1,   -1,   -1,   -1,
      -1,   -1,   -1,   -1,   -1,   -1,   -1,   -1,
    2322,   -1,   -1, 2323,   -1, 2324,   -1,   -1,
      -1, 2325,   -1,   -1,   -1, 2326,   -1,   -1,
      -1,   -1,   -1,   -1,   -1,   -1,   -1,   -1,
      -1,   -1,   -1,   -1,   -1,   -1,   -1, 2327,
      -1,   -1,   -1,   -1,   -1,   -1,   -1, 2328,
      -1, 2329,   -1,   -1,   -1,   -1,   -1,   -1,
      -1,   -1,   -1,   -1,   -1,   -1,   -1,   -1,
      -1, 2330, 2331,   -1,   -1,   -1,   -1,   -1,
      -1,   -1,   -1,   -1,   -1,   -1,   -1,   -1,
      -1,   -1,   -1,   -1,   -1,   -1,   -1,   -1,
    2332,   -1,   -1,   -1,   -1,   -1,   -1,   -1,
      -1,   -1,   -1,   -1,   -1, 2333,   -1,   -1,
      -1,   -1,   -1,   -1,   -1,   -1,   -1,   -1,
      -1,   -1,   -1,   -1,   -1,   -1, 2334, 2335,
      -1,   -1,   -1,   -1,   -1,   -1,   -1,   -1,
    2336, 2337,   -1,   -1,   -1,   -1,   -1,   -1,
      -1,   -1,   -1,   -1, 2338,   -1,   -1,   -1,
    2339,   -1,   -1,   -1,   -1,   -1,   -1,   -1,
      -1,   -1,   -1,   -1,   -1,   -1,   -1,   -1,
      -1,   -1,   -1,   -1,   -1,   -1,   -1,   -1,
    2340,   -1,   -1,   -1,   -1,   -1,   -1, 2341,
      -1,   -1,   -1,   -1,   -1,   -1,   -1,   -1,
      -1,   -1,   -1,   -1,   -1,   -1,   -1,   -1,
    2342,   -1,   -1,   -1,   -1,   -1,   -1,   -1,
      -1,   -1,   -1,   -1,   -1,   -1,   -1, 2343,
      -1,   -1,   -1,   -1, 2344, 2345, 2346,   -1,
      -1,   -1,   -1,   -1,   -1,   -1,   -1,   -1,
      -1,   -1,   -1,   -1,   -1,   -1,   -1,   -1,
      -1, 2347,   -1,   -1,   -1,   -1,   -1,   -1,
      -1,   -1,   -1,   -1,   -1,   -1,   -1,   -1,
      -1,   -1,   -1, 2348,   -1,   -1,   -1,   -1,
      -1,   -1,   -1, 2349,   -1,   -1,   -1,   -1,
      -1,   -1,   -1,   -1,   -1,   -1,   -1,   -1,
      -1, 2350,   -1,   -1,   -1,   -1,   -1,   -1,
      -1,   -1,   -1,   -1,   -1,   -1,   -1,   -1,
      -1,   -1,   -1,   -1,   -1,   -1,   -1,   -1,
      -1,   -1,   -1,   -1,   -1,   -1, 2351, 2352,
      -1, 2353,   -1,   -1,   -1,   -1,   -1,   -1,
      -1,   -1,   -1, 2354,   -1,   -1,   -1,   -1,
      -1,   -1,   -1, 2355,   -1,   -1,   -1,   -1,
      -1, 2356,   -1,   -1,   -1,   -1,   -1, 2357,
      -1,   -1,   -1,   -1, 2358,   -1,   -1,   -1,
      -1,   -1,   -1,   -1,   -1,   -1, 2359,   -1,
      -1,   -1,   -1,   -1,   -1,   -1,   -1,   -1,
      -1,   -1,   -1,   -1,   -1,   -1,   -1,   -1,
      -1, 2360,   -1,   -1,   -1,   -1,   -1,   -1,
      -1,   -1,   -1,   -1,   -1,   -1,   -1,   -1,
      -1,   -1,   -1,   -1,   -1, 2361,   -1,   -1,
    2362, 2363,   -1,   -1,   -1, 2364,   -1,   -1,
      -1,   -1,   -1,   -1,   -1,   -1,   -1,   -1,
      -1,   -1,   -1, 2365,   -1, 2366,   -1,   -1,
      -1,   -1,   -1,   -1,   -1,   -1,   -1,   -1,
      -1,   -1,   -1, 2367, 2368,   -1,   -1,   -1,
      -1,   -1,   -1,   -1,   -1,   -1,   -1,   -1,
      -1,   -1,   -1,   -1,   -1,   -1,   -1,   -1,
      -1,   -1,   -1,   -1,   -1,   -1,   -1,   -1,
      -1,   -1,   -1,   -1,   -1,   -1,   -1,   -1,
      -1,   -1,   -1,   -1,   -1,   -1,   -1, 2369,
      -1,   -1,   -1,   -1,   -1,   -1,   -1,   -1,
      -1,   -1,   -1,   -1,   -1,   -1,   -1,   -1,
      -1,   -1,   -1,   -1,   -1,   -1,   -1,   -1,
      -1, 2370,   -1,   -1,   -1,   -1, 2371,   -1,
      -1,   -1,   -1,   -1, 2372,   -1,   -1,   -1,
      -1,   -1,   -1,   -1,   -1,   -1,   -1,   -1,
      -1,   -1,   -1,   -1,   -1,   -1,   -1,   -1,
      -1,   -1,   -1,   -1,   -1,   -1,   -1,   -1,
      -1,   -1,   -1,   -1,   -1,   -1,   -1,   -1,
      -1,   -1,   -1,   -1,   -1,   -1,   -1, 2373,
      -1,   -1,   -1,   -1,   -1,   -1,   -1,   -1,
      -1,   -1,   -1,   -1,   -1, 2374,   -1,   -1,
      -1, 2375, 2376,   -1,   -1,   -1,   -1,   -1,
      -1,   -1,   -1,   -1,   -1,   -1,   -1,   -1,
      -1,   -1,   -1,   -1,   -1,   -1,   -1,   -1,
      -1,   -1,   -1,   -1,   -1,   -1,   -1,   -1,
      -1,   -1,   -1,   -1,   -1,   -1,   -1, 2377,
      -1, 2378,   -1,   -1,   -1,   -1,   -1,   -1,
      -1,   -1,   -1,   -1,   -1,   -1,   -1,   -1,
      -1,   -1, 2379,   -1,   -1, 2380, 2381, 2382,
      -1,   -1, 2383,   -1,   -1,   -1,   -1,   -1,
      -1,   -1,   -1,   -1,   -1,   -1,   -1,   -1,
    2384,   -1,   -1,   -1,   -1,   -1,   -1,   -1,
      -1,   -1,   -1,   -1,   -1, 2385,   -1,   -1,
      -1,   -1,   -1,   -1,   -1,   -1,   -1,   -1,
      -1,   -1,   -1,   -1,   -1,   -1,   -1,   -1,
      -1,   -1,   -1,   -1,   -1,   -1,   -1,   -1,
      -1,   -1,   -1,   -1,   -1,   -1,   -1,   -1,
      -1,   -1,   -1,   -1,   -1, 2386,   -1,   -1,
      -1,   -1,   -1, 2387,   -1,   -1,   -1,   -1,
      -1,   -1,   -1,   -1,   -1, 2388,   -1,   -1,
      -1,   -1,   -1,   -1,   -1, 2389,   -1, 2390,
    2391,   -1,   -1, 2392,   -1,   -1,   -1,   -1,
    2393,   -1,   -1,   -1,   -1,   -1, 2394,   -1,
      -1,   -1,   -1,   -1,   -1,   -1,   -1,   -1,
      -1,   -1,   -1,   -1,   -1,   -1,   -1,   -1,
    2395,   -1,   -1,   -1,   -1,   -1,   -1,   -1,
      -1,   -1,   -1,   -1,   -1,   -1,   -1,   -1,
      -1, 2396,   -1,   -1,   -1,   -1,   -1,   -1,
    2397, 2398,   -1,   -1,   -1,   -1, 2399,   -1,
      -1,   -1,   -1,   -1,   -1, 2400,   -1,   -1,
      -1,   -1,   -1,   -1,   -1,   -1,   -1,   -1,
    2401,   -1,   -1, 2402,   -1,   -1,   -1,   -1,
      -1,   -1,   -1,   -1,   -1, 2403,   -1, 2404,
      -1,   -1,   -1,   -1,   -1,   -1, 2405,   -1,
      -1,   -1,   -1, 2406,   -1,   -1,   -1,   -1,
      -1,   -1,   -1,   -1,   -1,   -1,   -1,   -1,
      -1,   -1, 2407,   -1,   -1,   -1,   -1,   -1,
      -1,   -1,   -1,   -1,   -1,   -1,   -1,   -1,
      -1,   -1,   -1,   -1,   -1,   -1,   -1, 2408,
      -1,   -1,   -1,   -1,   -1, 2409,   -1,   -1,
      -1,   -1,   -1, 2410,   -1,   -1,   -1,   -1,
      -1,   -1, 2411,   -1, 2412,   -1, 2413,   -1,
      -1,   -1,   -1,   -1,   -1,   -1,   -1,   -1,
      -1,   -1,   -1,   -1, 2414, 2415, 2416,   -1,
      -1,   -1,   -1,   -1,   -1,   -1, 2417,   -1,
    2418,   -1,   -1,   -1,   -1,   -1,   -1,   -1,
      -1,   -1,   -1,   -1,   -1,   -1,   -1,   -1,
      -1,   -1,   -1,   -1,   -1,   -1,   -1,   -1,
      -1,   -1,   -1,   -1,   -1,   -1,   -1,   -1,
      -1,   -1,   -1,   -1,   -1,   -1,   -1, 2419,
      -1,   -1,   -1,   -1,   -1,   -1,   -1,   -1,
      -1,   -1,   -1,   -1,   -1,   -1, 2420,   -1,
      -1, 2421,   -1,   -1,   -1,   -1,   -1,   -1,
    2422,   -1,   -1,   -1, 2423,   -1,   -1,   -1,
      -1,   -1,   -1,   -1,   -1,   -1,   -1,   -1,
      -1,   -1, 2424,   -1,   -1,   -1,   -1,   -1,
      -1,   -1,   -1, 2425,   -1,   -1, 2426,   -1,
      -1,   -1,   -1,   -1, 2427,   -1,   -1,   -1,
      -1,   -1,   -1,   -1,   -1,   -1,   -1,   -1,
      -1,   -1,   -1,   -1,   -1,   -1, 2428,   -1,
      -1,   -1,   -1,   -1, 2429,   -1,   -1,   -1,
      -1,   -1,   -1,   -1,   -1,   -1,   -1,   -1,
      -1,   -1,   -1,   -1,   -1,   -1,   -1, 2430,
      -1,   -1,   -1,   -1,   -1,   -1, 2431,   -1,
      -1, 2432,   -1,   -1,   -1,   -1,   -1,   -1,
    2433,   -1, 2434, 2435,   -1,   -1,   -1,   -1,
      -1,   -1, 2436,   -1, 2437,   -1,   -1,   -1,
      -1,   -1,   -1,   -1,   -1,   -1,   -1,   -1,
      -1,   -1,   -1,   -1,   -1, 2438,   -1,   -1,
      -1, 2439,   -1,   -1,   -1,   -1,   -1,   -1,
      -1,   -1,   -1,   -1, 2440,   -1, 2441,   -1,
      -1, 2442,   -1,   -1, 2443,   -1, 2444,   -1,
      -1,   -1, 2445,   -1,   -1,   -1,   -1,   -1,
      -1, 2446,   -1,   -1, 2447,   -1,   -1,   -1,
      -1, 2448,   -1,   -1,   -1,   -1,   -1, 2449,
      -1,   -1,   -1,   -1,   -1,   -1,   -1,   -1,
      -1,   -1,   -1,   -1,   -1,   -1,   -1,   -1,
      -1,   -1,   -1, 2450,   -1,   -1,   -1,   -1,
      -1, 2451,   -1,   -1,   -1,   -1,   -1,   -1,
      -1,   -1,   -1,   -1,   -1,   -1,   -1,   -1,
      -1,   -1,   -1,   -1,   -1, 2452,   -1,   -1,
      -1,   -1, 2453,   -1,   -1,   -1, 2454,   -1,
      -1,   -1, 2455,   -1,   -1,   -1,   -1,   -1,
      -1, 2456,   -1,   -1,   -1,   -1,   -1,   -1,
      -1,   -1,   -1,   -1,   -1,   -1,   -1,   -1,
      -1,   -1,   -1,   -1,   -1,   -1,   -1,   -1,
      -1,   -1,   -1,   -1,   -1,   -1,   -1,   -1,
      -1,   -1,   -1,   -1,   -1,   -1,   -1,   -1,
      -1,   -1,   -1,   -1,   -1,   -1,   -1, 2457,
      -1,   -1,   -1,   -1,   -1,   -1,   -1,   -1,
      -1,   -1,   -1,   -1,   -1, 2458,   -1,   -1,
      -1,   -1,   -1, 2459,   -1,   -1,   -1,   -1,
      -1,   -1,   -1,   -1,   -1,   -1,   -1,   -1,
      -1,   -1,   -1,   -1,   -1,   -1,   -1,   -1,
      -1,   -1,   -1,   -1, 2460,   -1,   -1,   -1,
    2461, 2462,   -1,   -1,   -1,   -1,   -1,   -1,
      -1,   -1,   -1,   -1,   -1,   -1,   -1,   -1,
      -1,   -1,   -1,   -1,   -1,   -1,   -1,   -1,
      -1, 2463,   -1,   -1,   -1, 2464,   -1,   -1,
      -1,   -1,   -1,   -1,   -1,   -1,   -1, 2465,
      -1,   -1,   -1,   -1,   -1,   -1, 2466,   -1,
      -1,   -1,   -1, 2467,   -1,   -1,   -1,   -1,
      -1,   -1, 2468,   -1,   -1,   -1,   -1,   -1,
      -1,   -1,   -1,   -1,   -1,   -1,   -1,   -1,
      -1,   -1,   -1,   -1,   -1,   -1,   -1,   -1,
      -1,   -1,   -1,   -1, 2469, 2470,   -1,   -1,
      -1,   -1,   -1,   -1,   -1, 2471,   -1,   -1,
      -1,   -1,   -1,   -1,   -1,   -1,   -1,   -1,
      -1, 2472,   -1,   -1,   -1,   -1,   -1, 2473,
      -1, 2474,   -1,   -1,   -1,   -1,   -1,   -1,
      -1,   -1,   -1,   -1, 2475,   -1,   -1,   -1,
      -1,   -1,   -1,   -1, 2476,   -1,   -1,   -1,
      -1,   -1,   -1,   -1,   -1,   -1,   -1,   -1,
      -1,   -1,   -1,   -1,   -1, 2477,   -1, 2478,
      -1,   -1,   -1,   -1,   -1,   -1,   -1, 2479,
      -1,   -1, 2480,   -1,   -1,   -1,   -1,   -1,
      -1,   -1,   -1,   -1, 2481,   -1,   -1,   -1,
      -1,   -1,   -1,   -1,   -1,   -1,   -1,   -1,
      -1,   -1,   -1,   -1, 2482,   -1,   -1,   -1,
      -1,   -1,   -1,   -1,   -1,   -1,   -1,   -1,
      -1,   -1,   -1,   -1,   -1,   -1,   -1,   -1,
      -1,   -1,   -1,   -1,   -1,   -1,   -1,   -1,
    2483,   -1,   -1, 2484,   -1,   -1, 2485, 2486,
      -1,   -1,   -1,   -1,   -1,   -1,   -1,   -1,
      -1,   -1,   -1,   -1, 2487,   -1,   -1,   -1,
      -1,   -1,   -1,   -1,   -1,   -1, 2488, 2489,
      -1,   -1,   -1,   -1,   -1,   -1,   -1,   -1,
      -1,   -1, 2490,   -1,   -1,   -1,   -1,   -1,
      -1,   -1,   -1,   -1,   -1,   -1,   -1,   -1,
    2491,   -1,   -1,   -1,   -1,   -1,   -1,   -1,
      -1,   -1,   -1,   -1,   -1,   -1,   -1,   -1,
      -1,   -1,   -1,   -1,   -1,   -1,   -1,   -1,
      -1,   -1,   -1,   -1,   -1,   -1,   -1,   -1,
      -1,   -1,   -1,   -1,   -1,   -1,   -1,   -1,
    2492, 2493,   -1, 2494,   -1,   -1,   -1,   -1,
      -1,   -1,   -1,   -1,   -1,   -1,   -1,   -1,
      -1, 2495,   -1,   -1,   -1,   -1,   -1,   -1,
      -1,   -1,   -1,   -1,   -1,   -1,   -1,   -1,
      -1,   -1,   -1,   -1, 2496,   -1,   -1,   -1,
      -1,   -1, 2497,   -1,   -1,   -1,   -1,   -1,
      -1,   -1,   -1,   -1,   -1,   -1,   -1,   -1,
      -1,   -1,   -1,   -1,   -1,   -1,   -1,   -1,
      -1,   -1,   -1,   -1,   -1,   -1,   -1,   -1,
      -1,   -1,   -1,   -1,   -1,   -1,   -1,   -1,
      -1,   -1, 2498,   -1,   -1,   -1,   -1,   -1,
      -1,   -1,   -1,   -1,   -1,   -1,   -1,   -1,
      -1, 2499,   -1,   -1,   -1,   -1,   -1,   -1,
      -1,   -1,   -1,   -1,   -1,   -1,   -1,   -1,
      -1,   -1,   -1,   -1,   -1,   -1,   -1,   -1,
      -1,   -1,   -1,   -1,   -1,   -1,   -1,   -1,
      -1,   -1,   -1,   -1,   -1,   -1, 2500,   -1,
      -1,   -1,   -1,   -1,   -1,   -1, 2501,   -1,
      -1,   -1,   -1,   -1,   -1,   -1,   -1, 2502,
      -1, 2503,   -1,   -1,   -1, 2504,   -1,   -1,
    2505,   -1, 2506,   -1,   -1, 2507,   -1, 2508,
      -1,   -1,   -1,   -1,   -1, 2509,   -1,   -1,
      -1,   -1,   -1,   -1, 2510,   -1,   -1,   -1,
      -1,   -1,   -1, 2511,   -1,   -1, 2512,   -1,
      -1,   -1,   -1, 2513,   -1,   -1,   -1,   -1,
      -1,   -1, 2514,   -1,   -1,   -1, 2515,   -1,
      -1,   -1,   -1, 2516,   -1, 2517,   -1,   -1,
      -1, 2518,   -1,   -1,   -1,   -1,   -1,   -1,
      -1, 2519,   -1, 2520,   -1,   -1,   -1,   -1,
      -1,   -1,   -1,   -1, 2521,   -1,   -1,   -1,
      -1,   -1,   -1,   -1,   -1,   -1,   -1,   -1,
      -1,   -1,   -1,   -1,   -1,   -1,   -1, 2522,
      -1,   -1,   -1, 2523,   -1,   -1,   -1,   -1,
    2524,   -1,   -1,   -1,   -1,   -1,   -1,   -1,
      -1,   -1,   -1,   -1,   -1,   -1,   -1, 2525,
      -1, 2526,   -1,   -1,   -1,   -1,   -1, 2527,
      -1, 2528,   -1, 2529,   -1,   -1,   -1,   -1,
      -1,   -1,   -1,   -1,   -1,   -1,   -1,   -1,
      -1, 2530,   -1,   -1,   -1,   -1,   -1,   -1,
      -1,   -1,   -1,   -1,   -1,   -1, 2531,   -1,
      -1, 2532,   -1,   -1,   -1,   -1,   -1,   -1,
      -1,   -1,   -1,   -1,   -1,   -1, 2533,   -1,
      -1,   -1, 2534,   -1,   -1, 2535,   -1,   -1,
      -1,   -1,   -1,   -1,   -1,   -1,   -1,   -1,
      -1,   -1,   -1,   -1,   -1,   -1,   -1,   -1,
      -1,   -1,   -1,   -1,   -1,   -1,   -1,   -1,
      -1,   -1,   -1,   -1, 2536,   -1,   -1,   -1,
      -1,   -1,   -1, 2537,   -1,   -1,   -1,   -1,
      -1,   -1, 2538,   -1,   -1,   -1,   -1,   -1,
      -1,   -1,   -1, 2539,   -1, 2540,   -1,   -1,
      -1,   -1,   -1,   -1,   -1,   -1,   -1, 2541,
      -1,   -1,   -1, 2542,   -1,   -1,   -1,   -1,
      -1, 2543, 2544,   -1,   -1,   -1,   -1,   -1,
      -1,   -1,   -1,   -1,   -1,   -1,   -1,   -1,
      -1,   -1,   -1, 2545,   -1,   -1,   -1,   -1,
      -1, 2546,   -1,   -1,   -1,   -1,   -1,   -1,
      -1,   -1,   -1,   -1,   -1,   -1,   -1,   -1,
      -1,   -1,   -1,   -1,   -1,   -1,   -1,   -1,
      -1,   -1,   -1,   -1, 2547,   -1,   -1,   -1,
    2548,   -1,   -1,   -1,   -1,   -1,   -1,   -1,
      -1,   -1,   -1,   -1, 2549,   -1,   -1,   -1,
      -1,   -1,   -1,   -1,   -1,   -1,   -1,   -1,
      -1,   -1, 2550,   -1,   -1,   -1,   -1,   -1,
      -1,   -1,   -1,   -1,   -1,   -1,   -1,   -1,
      -1, 2551,   -1,   -1,   -1,   -1,   -1,   -1,
      -1,   -1,   -1,   -1,   -1,   -1,   -1,   -1,
      -1,   -1,   -1,   -1,   -1,   -1,   -1,   -1,
      -1,   -1,   -1,   -1, 2552, 2553,   -1,   -1,
      -1,   -1,   -1,   -1,   -1,   -1,   -1, 2554,
      -1,   -1,   -1,   -1,   -1,   -1,   -1,   -1,
      -1, 2555,   -1,   -1,   -1,   -1,   -1,   -1,
      -1, 2556, 2557, 2558,   -1, 2559,   -1,   -1,
      -1,   -1, 2560, 2561,   -1,   -1, 2562,   -1,
      -1,   -1,   -1,   -1,   -1,   -1,   -1,   -1,
    2563,   -1,   -1,   -1,   -1,   -1, 2564,   -1,
      -1,   -1, 2565,   -1,   -1,   -1,   -1,   -1,
      -1,   -1,   -1, 2566,   -1,   -1,   -1,   -1,
    2567,   -1,   -1,   -1,   -1,   -1, 2568, 2569,
      -1,   -1, 2570, 2571,   -1,   -1,   -1,   -1,
      -1,   -1,   -1,   -1,   -1, 2572, 2573,   -1,
      -1,   -1, 2574,   -1,   -1,   -1,   -1, 2575,
      -1,   -1,   -1,   -1,   -1,   -1,   -1,   -1,
    2576,   -1,   -1,   -1,   -1,   -1,   -1,   -1,
    2577,   -1,   -1,   -1,   -1,   -1,   -1,   -1,
      -1,   -1,   -1,   -1,   -1,   -1,   -1,   -1,
      -1,   -1,   -1,   -1,   -1,   -1,   -1, 2578,
      -1,   -1,   -1,   -1,   -1,   -1,   -1,   -1,
      -1,   -1,   -1,   -1,   -1,   -1,   -1,   -1,
      -1,   -1,   -1,   -1,   -1,   -1,   -1,   -1,
      -1,   -1,   -1,   -1,   -1,   -1,   -1,   -1,
      -1,   -1,   -1,   -1,   -1,   -1,   -1,   -1,
      -1,   -1,   -1,   -1,   -1,   -1,   -1,   -1,
      -1,   -1,   -1, 2579, 2580,   -1,   -1,   -1,
      -1,   -1,   -1,   -1,   -1,   -1,   -1,   -1,
      -1,   -1,   -1,   -1, 2581,   -1,   -1,   -1,
    2582,   -1, 2583,   -1,   -1, 2584,   -1,   -1,
      -1,   -1,   -1,   -1,   -1,   -1, 2585,   -1,
      -1,   -1,   -1,   -1,   -1,   -1,   -1,   -1,
      -1,   -1,   -1,   -1,   -1,   -1,   -1,   -1,
      -1,   -1,   -1,   -1,   -1,   -1, 2586,   -1,
      -1,   -1,   -1,   -1,   -1,   -1,   -1,   -1,
      -1,   -1,   -1, 2587, 2588, 2589,   -1,   -1,
      -1,   -1,   -1, 2590,   -1,   -1,   -1,   -1,
      -1,   -1,   -1,   -1,   -1,   -1,   -1,   -1,
    2591,   -1,   -1,   -1,   -1,   -1,   -1,   -1,
      -1,   -1,   -1,   -1,   -1,   -1,   -1,   -1,
      -1,   -1,   -1,   -1,   -1, 2592, 2593,   -1,
    2594,   -1,   -1,   -1, 2595,   -1,   -1,   -1,
      -1,   -1,   -1,   -1,   -1,   -1,   -1,   -1,
      -1,   -1,   -1,   -1,   -1,   -1,   -1,   -1,
    2596,   -1,   -1,   -1,   -1,   -1,   -1,   -1,
      -1,   -1,   -1,   -1,   -1,   -1,   -1,   -1,
      -1, 2597,   -1,   -1,   -1,   -1,   -1,   -1,
      -1,   -1,   -1,   -1,   -1,   -1,   -1,   -1,
      -1,   -1,   -1,   -1,   -1, 2598,   -1,   -1,
      -1,   -1,   -1,   -1, 2599,   -1,   -1,   -1,
      -1,   -1,   -1,   -1,   -1,   -1,   -1, 2600,
      -1,   -1,   -1, 2601,   -1,   -1,   -1,   -1,
      -1,   -1,   -1,   -1,   -1,   -1,   -1,   -1,
      -1,   -1,   -1,   -1,   -1,   -1,   -1,   -1,
      -1,   -1, 2602,   -1,   -1,   -1,   -1,   -1,
      -1,   -1,   -1,   -1, 2603,   -1,   -1,   -1,
      -1,   -1,   -1,   -1,   -1,   -1,   -1,   -1,
      -1,   -1, 2604,   -1,   -1,   -1,   -1,   -1,
      -1,   -1,   -1,   -1,   -1,   -1,   -1,   -1,
      -1,   -1,   -1,   -1,   -1,   -1,   -1,   -1,
      -1,   -1,   -1,   -1, 2605,   -1,   -1,   -1,
      -1,   -1,   -1,   -1,   -1,   -1,   -1,   -1,
      -1,   -1,   -1,   -1,   -1,   -1,   -1,   -1,
      -1,   -1,   -1,   -1,   -1,   -1,   -1,   -1,
      -1,   -1,   -1,   -1,   -1,   -1, 2606,   -1,
    2607,   -1,   -1,   -1,   -1,   -1,   -1,   -1,
    2608, 2609, 2610,   -1,   -1,   -1,   -1,   -1,
      -1,   -1,   -1,   -1,   -1,   -1,   -1,   -1,
      -1,   -1,   -1, 2611,   -1,   -1, 2612,   -1,
      -1,   -1,   -1,   -1,   -1,   -1,   -1,   -1,
    2613,   -1,   -1,   -1,   -1,   -1, 2614,   -1,
      -1,   -1,   -1,   -1, 2615,   -1,   -1,   -1,
    2616,   -1,   -1,   -1,   -1,   -1,   -1,   -1,
      -1,   -1,   -1,   -1,   -1,   -1,   -1,   -1,
      -1,   -1,   -1,   -1,   -1,   -1,   -1,   -1,
      -1,   -1,   -1, 2617,   -1,   -1,   -1,   -1,
      -1,   -1,   -1,   -1,   -1,   -1,   -1,   -1,
      -1, 2618,   -1, 2619,   -1,   -1,   -1,   -1,
      -1,   -1,   -1,   -1,   -1, 2620,   -1,   -1,
      -1,   -1, 2621,   -1,   -1,   -1,   -1,   -1,
      -1,   -1,   -1, 2622,   -1,   -1,   -1,   -1,
    2623,   -1,   -1,   -1,   -1,   -1,   -1,   -1,
      -1,   -1,   -1,   -1,   -1,   -1,   -1, 2624,
      -1, 2625, 2626,   -1,   -1,   -1, 2627,   -1,
      -1,   -1,   -1, 2628,   -1,   -1,   -1,   -1,
      -1,   -1,   -1,   -1,   -1,   -1,   -1,   -1,
      -1,   -1,   -1,   -1,   -1,   -1,   -1,   -1,
      -1,   -1,   -1,   -1,   -1, 2629,   -1,   -1,
      -1,   -1,   -1,   -1,   -1,   -1,   -1,   -1,
      -1,   -1,   -1,   -1,   -1,   -1,   -1,   -1,
      -1, 2630,   -1,   -1,   -1,   -1,   -1,   -1,
      -1,   -1,   -1,   -1,   -1, 2631,   -1, 2632,
      -1,   -1,   -1,   -1,   -1,   -1,   -1,   -1,
      -1,   -1,   -1,   -1,   -1,   -1,   -1,   -1,
      -1,   -1,   -1,   -1,   -1,   -1,   -1,   -1,
      -1,   -1, 2633,   -1,   -1,   -1,   -1,   -1,
      -1,   -1,   -1,   -1,   -1,   -1,   -1,   -1,
      -1,   -1,   -1,   -1,   -1,   -1,   -1,   -1,
      -1,   -1,   -1,   -1,   -1, 2634,   -1,   -1,
      -1,   -1,   -1,   -1,   -1,   -1,   -1,   -1,
      -1,   -1,   -1,   -1, 2635,   -1, 2636, 2637,
      -1,   -1,   -1,   -1,   -1,   -1,   -1, 2638,
      -1,   -1,   -1, 2639,   -1,   -1,   -1,   -1,
      -1,   -1,   -1,   -1,   -1,   -1,   -1,   -1,
      -1,   -1,   -1,   -1,   -1,   -1,   -1,   -1,
      -1, 2640,   -1,   -1,   -1,   -1,   -1, 2641,
      -1,   -1,   -1,   -1,   -1,   -1,   -1, 2642,
      -1,   -1,   -1,   -1,   -1,   -1,   -1,   -1,
      -1,   -1, 2643,   -1,   -1, 2644,   -1,   -1,
      -1,   -1,   -1,   -1,   -1, 2645,   -1,   -1,
      -1,   -1,   -1,   -1,   -1,   -1,   -1,   -1,
      -1,   -1,   -1, 2646,   -1,   -1, 2647,   -1,
      -1,   -1,   -1,   -1,   -1, 2648,   -1, 2649,
      -1,   -1,   -1,   -1,   -1, 2650,   -1,   -1,
      -1,   -1,   -1,   -1,   -1,   -1,   -1,   -1,
      -1,   -1,   -1,   -1,   -1,   -1,   -1,   -1,
    2651,   -1,   -1,   -1,   -1,   -1,   -1,   -1,
      -1,   -1,   -1,   -1,   -1,   -1, 2652,   -1,
      -1,   -1,   -1, 2653,   -1,   -1,   -1,   -1,
      -1,   -1,   -1,   -1,   -1,   -1,   -1,   -1,
      -1,   -1,   -1,   -1,   -1,   -1,   -1,   -1,
      -1,   -1,   -1,   -1,   -1,   -1,   -1,   -1,
      -1,   -1,   -1,   -1,   -1,   -1,   -1,   -1,
      -1,   -1,   -1,   -1, 2654,   -1,   -1,   -1,
      -1,   -1,   -1,   -1,   -1,   -1,   -1,   -1,
      -1,   -1,   -1,   -1,   -1,   -1, 2655,   -1,
      -1,   -1,   -1,   -1,   -1,   -1,   -1,   -1,
    2656,   -1,   -1,   -1,   -1,   -1,   -1, 2657,
      -1,   -1,   -1,   -1,   -1,   -1,   -1,   -1,
      -1,   -1,   -1,   -1,   -1,   -1,   -1,   -1,
      -1,   -1,   -1,   -1,   -1,   -1,   -1,   -1,
      -1,   -1,   -1,   -1,   -1, 2658,   -1,   -1,
      -1,   -1,   -1,   -1,   -1,   -1,   -1,   -1,
      -1,   -1,   -1, 2659,   -1,   -1,   -1,   -1,
    2660, 2661, 2662,   -1,   -1,   -1,   -1,   -1,
      -1,   -1,   -1,   -1,   -1,   -1,   -1,   -1,
      -1,   -1,   -1,   -1, 2663,   -1,   -1,   -1,
      -1,   -1,   -1,   -1,   -1,   -1,   -1,   -1,
    2664,   -1,   -1,   -1,   -1, 2665,   -1, 2666,
      -1,   -1,   -1,   -1,   -1,   -1,   -1,   -1,
      -1,   -1,   -1,   -1,   -1,   -1,   -1,   -1,
      -1,   -1, 2667,   -1,   -1, 2668,   -1, 2669,
      -1,   -1,   -1,   -1,   -1,   -1,   -1,   -1,
      -1,   -1,   -1,   -1,   -1,   -1,   -1,   -1,
      -1, 2670,   -1,   -1,   -1,   -1,   -1,   -1,
      -1,   -1,   -1,   -1,   -1,   -1,   -1,   -1,
    2671,   -1,   -1,   -1,   -1,   -1,   -1,   -1,
      -1,   -1,   -1,   -1,   -1,   -1,   -1, 2672,
      -1,   -1,   -1,   -1,   -1,   -1,   -1,   -1,
      -1,   -1, 2673,   -1,   -1,   -1,   -1,   -1,
      -1,   -1,   -1,   -1,   -1,   -1,   -1,   -1,
      -1,   -1,   -1,   -1,   -1,   -1,   -1,   -1,
      -1,   -1,   -1,   -1,   -1, 2674,   -1,   -1,
      -1,   -1, 2675,   -1,   -1,   -1,   -1,   -1,
      -1,   -1,   -1,   -1,   -1, 2676,   -1,   -1,
      -1,   -1,   -1,   -1,   -1,   -1,   -1,   -1,
      -1,   -1,   -1,   -1,   -1,   -1,   -1,   -1,
      -1,   -1,   -1,   -1,   -1,   -1,   -1,   -1,
      -1,   -1,   -1,   -1,   -1,   -1, 2677,   -1,
      -1,   -1,   -1,   -1,   -1,   -1,   -1,   -1,
      -1,   -1,   -1,   -1,   -1,   -1,   -1,   -1,
      -1,   -1,   -1, 2678,   -1, 2679,   -1,   -1,
    2680,   -1,   -1,   -1,   -1,   -1,   -1,   -1,
      -1,   -1,   -1,   -1,   -1,   -1,   -1,   -1,
    2681,   -1,   -1,   -1,   -1,   -1,   -1,   -1,
      -1,   -1,   -1,   -1,   -1,   -1,   -1,   -1,
    2682, 2683, 2684,   -1,   -1, 2685,   -1,   -1,
      -1,   -1,   -1,   -1,   -1,   -1,   -1,   -1,
    2686,   -1,   -1,   -1,   -1,   -1, 2687, 2688,
      -1,   -1,   -1,   -1,   -1,   -1,   -1, 2689,
      -1,   -1,   -1,   -1,   -1,   -1,   -1,   -1,
      -1,   -1,   -1,   -1,   -1,   -1,   -1,   -1,
      -1,   -1,   -1,   -1,   -1,   -1,   -1,   -1,
      -1,   -1, 2690,   -1,   -1,   -1,   -1,   -1,
    2691,   -1, 2692,   -1,   -1,   -1, 2693,   -1,
      -1,   -1,   -1, 2694,   -1,   -1,   -1,   -1,
      -1,   -1,   -1,   -1,   -1,   -1,   -1,   -1,
      -1,   -1,   -1,   -1,   -1,   -1,   -1,   -1,
      -1,   -1,   -1,   -1,   -1,   -1,   -1,   -1,
    2695, 2696,   -1,   -1,   -1,   -1, 2697,   -1,
      -1,   -1,   -1, 2698,   -1,   -1,   -1,   -1,
      -1,   -1,   -1,   -1,   -1,   -1,   -1,   -1,
      -1,   -1,   -1, 2699,   -1,   -1,   -1,   -1,
      -1,   -1, 2700,   -1,   -1, 2701,   -1,   -1,
      -1,   -1, 2702,   -1,   -1, 2703,   -1,   -1,
      -1,   -1,   -1,   -1,   -1, 2704, 2705,   -1,
      -1, 2706,   -1,   -1,   -1, 2707,   -1,   -1,
      -1,   -1,   -1,   -1,   -1,   -1,   -1,   -1,
      -1, 2708,   -1,   -1,   -1,   -1,   -1,   -1,
      -1,   -1,   -1,   -1,   -1,   -1,   -1,   -1,
      -1,   -1,   -1,   -1,   -1,   -1,   -1,   -1,
      -1,   -1,   -1,   -1,   -1,   -1,   -1,   -1,
      -1,   -1,   -1,   -1,   -1, 2709,   -1,   -1,
      -1, 2710,   -1,   -1,   -1, 2711,   -1,   -1,
      -1,   -1, 2712,   -1, 2713,   -1,   -1,   -1,
      -1, 2714,   -1,   -1,   -1,   -1,   -1,   -1,
      -1,   -1, 2715,   -1,   -1,   -1,   -1, 2716,
      -1,   -1,   -1,   -1,   -1,   -1,   -1, 2717,
      -1,   -1, 2718,   -1,   -1,   -1,   -1,   -1,
      -1, 2719,   -1,   -1,   -1,   -1,   -1,   -1,
      -1,   -1,   -1,   -1,   -1, 2720,   -1,   -1,
      -1,   -1,   -1,   -1,   -1,   -1,   -1, 2721,
      -1,   -1,   -1,   -1, 2722,   -1,   -1, 2723,
      -1,   -1,   -1,   -1,   -1,   -1, 2724,   -1,
      -1,   -1, 2725,   -1,   -1,   -1,   -1,   -1,
      -1,   -1,   -1,   -1,   -1, 2726,   -1,   -1,
      -1,   -1, 2727,   -1,   -1,   -1,   -1,   -1,
      -1, 2728,   -1, 2729,   -1,   -1,   -1,   -1,
      -1,   -1,   -1,   -1,   -1,   -1,   -1,   -1,
      -1,   -1,   -1,   -1,   -1,   -1,   -1,   -1,
      -1,   -1,   -1, 2730,   -1,   -1,   -1,   -1,
      -1,   -1,   -1,   -1, 2731,   -1, 2732,   -1,
      -1,   -1,   -1,   -1,   -1,   -1,   -1,   -1,
      -1,   -1,   -1,   -1,   -1,   -1, 2733,   -1,
      -1,   -1,   -1,   -1,   -1,   -1,   -1,   -1,
      -1,   -1,   -1,   -1,   -1,   -1, 2734,   -1,
      -1,   -1,   -1,   -1,   -1,   -1,   -1,   -1,
      -1,   -1,   -1,   -1,   -1,   -1,   -1,   -1,
      -1,   -1,   -1,   -1,   -1,   -1,   -1,   -1,
      -1,   -1,   -1,   -1,   -1,   -1,   -1,   -1,
      -1,   -1,   -1,   -1,   -1, 2735,   -1,   -1,
      -1,   -1,   -1,   -1, 2736,   -1,   -1,   -1,
      -1,   -1,   -1, 2737,   -1,   -1,   -1,   -1,
      -1,   -1,   -1,   -1,   -1,   -1,   -1,   -1,
      -1,   -1, 2738, 2739,   -1,   -1, 2740,   -1,
      -1,   -1,   -1, 2741,   -1, 2742,   -1,   -1,
    2743,   -1,   -1,   -1,   -1,   -1,   -1,   -1,
      -1,   -1,   -1,   -1,   -1,   -1,   -1,   -1,
      -1,   -1,   -1,   -1,   -1,   -1,   -1,   -1,
      -1,   -1,   -1,   -1,   -1,   -1,   -1, 2744,
      -1,   -1,   -1,   -1,   -1,   -1,   -1,   -1,
      -1,   -1,   -1,   -1, 2745,   -1,   -1,   -1,
      -1,   -1,   -1, 2746,   -1,   -1,   -1,   -1,
      -1,   -1,   -1, 2747, 2748,   -1, 2749,   -1,
      -1,   -1,   -1,   -1,   -1,   -1,   -1,   -1,
      -1,   -1,   -1, 2750,   -1,   -1,   -1,   -1,
    2751,   -1,   -1,   -1,   -1,   -1,   -1,   -1,
      -1,   -1,   -1, 2752,   -1, 2753,   -1, 2754,
      -1,   -1,   -1,   -1, 2755,   -1,   -1,   -1,
      -1, 2756,   -1,   -1,   -1,   -1,   -1,   -1,
      -1,   -1, 2757,   -1,   -1,   -1,   -1,   -1,
    2758,   -1,   -1,   -1, 2759,   -1,   -1,   -1,
    2760,   -1,   -1, 2761,   -1,   -1,   -1,   -1,
      -1,   -1,   -1, 2762, 2763, 2764,   -1,   -1,
      -1,   -1,   -1, 2765,   -1,   -1,   -1,   -1,
      -1,   -1,   -1,   -1, 2766,   -1,   -1,   -1,
      -1, 2767,   -1,   -1,   -1,   -1,   -1, 2768,
      -1,   -1,   -1,   -1,   -1,   -1,   -1,   -1,
      -1,   -1,   -1,   -1,   -1,   -1,   -1,   -1,
      -1,   -1,   -1, 2769, 2770,   -1,   -1,   -1,
      -1,   -1, 2771,   -1,   -1,   -1,   -1,   -1,
      -1,   -1,   -1,   -1,   -1,   -1,   -1,   -1,
      -1,   -1,   -1,   -1,   -1,   -1,   -1,   -1,
      -1,   -1,   -1,   -1,   -1,   -1,   -1,   -1,
      -1,   -1,   -1,   -1, 2772,   -1,   -1,   -1,
      -1,   -1,   -1,   -1,   -1,   -1,   -1,   -1,
      -1,   -1,   -1,   -1,   -1, 2773,   -1,   -1,
      -1,   -1,   -1, 2774,   -1, 2775,   -1,   -1,
      -1,   -1,   -1,   -1,   -1,   -1, 2776, 2777,
      -1,   -1, 2778,   -1, 2779,   -1,   -1,   -1,
      -1,   -1,   -1,   -1,   -1,   -1,   -1,   -1,
      -1,   -1,   -1,   -1,   -1,   -1,   -1,   -1,
      -1,   -1,   -1,   -1,   -1,   -1,   -1,   -1,
      -1,   -1,   -1,   -1,   -1,   -1,   -1,   -1,
      -1,   -1,   -1,   -1,   -1,   -1,   -1,   -1,
    2780,   -1,   -1,   -1,   -1,   -1,   -1,   -1,
      -1,   -1,   -1,   -1,   -1,   -1,   -1,   -1,
      -1,   -1,   -1, 2781,   -1,   -1,   -1,   -1,
      -1, 2782,   -1,   -1,   -1,   -1,   -1,   -1,
      -1,   -1,   -1, 2783,   -1,   -1,   -1,   -1,
      -1,   -1,   -1,   -1,   -1,   -1,   -1,   -1,
      -1,   -1,   -1,   -1,   -1,   -1,   -1,   -1,
      -1,   -1,   -1,   -1,   -1,   -1,   -1,   -1,
      -1,   -1,   -1,   -1,   -1,   -1, 2784, 2785,
      -1,   -1, 2786, 2787,   -1,   -1,   -1,   -1,
      -1,   -1,   -1,   -1,   -1, 2788,   -1,   -1,
      -1,   -1,   -1,   -1, 2789,   -1,   -1,   -1,
      -1,   -1,   -1,   -1, 2790,   -1,   -1,   -1,
      -1,   -1,   -1, 2791,   -1,   -1,   -1,   -1,
      -1,   -1, 2792,   -1,   -1,   -1,   -1,   -1,
      -1,   -1, 2793,   -1,   -1,   -1,   -1,   -1,
      -1,   -1,   -1,   -1,   -1,   -1,   -1,   -1,
      -1,   -1,   -1, 2794,   -1,   -1,   -1,   -1,
      -1,   -1,   -1,   -1,   -1,   -1,   -1,   -1,
      -1,   -1, 2795,   -1,   -1,   -1,   -1,   -1,
      -1,   -1,   -1,   -1,   -1,   -1,   -1,   -1,
      -1,   -1,   -1,   -1,   -1,   -1,   -1,   -1,
      -1, 2796,   -1, 2797,   -1,   -1,   -1,   -1,
      -1,   -1,   -1,   -1,   -1,   -1,   -1,   -1,
      -1,   -1,   -1,   -1, 2798,   -1,   -1, 2799,
      -1,   -1,   -1,   -1,   -1,   -1,   -1,   -1,
      -1,   -1,   -1,   -1, 2800,   -1,   -1,   -1,
      -1,   -1,   -1,   -1,   -1,   -1,   -1, 2801,
      -1,   -1,   -1,   -1,   -1,   -1,   -1,   -1,
    2802,   -1,   -1,   -1, 2803,   -1,   -1,   -1,
      -1,   -1,   -1,   -1,   -1,   -1,   -1,   -1,
      -1,   -1,   -1,   -1,   -1,   -1,   -1, 2804,
    2805,   -1,   -1,   -1,   -1,   -1,   -1,   -1,
      -1, 2806,   -1,   -1,   -1,   -1,   -1,   -1,
      -1,   -1,   -1,   -1,   -1,   -1,   -1,   -1,
      -1,   -1,   -1,   -1,   -1,   -1, 2807,   -1,
      -1,   -1,   -1,   -1,   -1,   -1,   -1,   -1,
      -1,   -1,   -1,   -1,   -1,   -1, 2808,   -1,
      -1, 2809,   -1,   -1,   -1,   -1,   -1,   -1,
      -1,   -1,   -1,   -1,   -1,   -1, 2810,   -1,
      -1,   -1,   -1,   -1,   -1,   -1,   -1,   -1,
      -1,   -1,   -1,   -1,   -1,   -1,   -1,   -1,
      -1,   -1,   -1,   -1,   -1,   -1,   -1,   -1,
      -1,   -1,   -1,   -1, 2811,   -1, 2812,   -1,
      -1,   -1,   -1,   -1,   -1,   -1,   -1,   -1,
      -1,   -1,   -1,   -1,   -1, 2813,   -1,   -1,
      -1, 2814,   -1,   -1,   -1,   -1,   -1,   -1,
      -1,   -1,   -1,   -1,   -1,   -1,   -1,   -1,
      -1,   -1,   -1, 2815,   -1,   -1,   -1,   -1,
      -1,   -1,   -1,   -1,   -1,   -1,   -1,   -1,
      -1, 2816,   -1,   -1,   -1,   -1, 2817,   -1,
      -1,   -1,   -1,   -1,   -1,   -1, 2818,   -1,
      -1,   -1,   -1,   -1,   -1,   -1,   -1,   -1,
      -1, 2819,   -1,   -1,   -1,   -1,   -1,   -1,
      -1,   -1, 2820,   -1,   -1,   -1,   -1,   -1,
      -1,   -1,   -1,   -1,   -1,   -1,   -1,   -1,
      -1,   -1,   -1,   -1,   -1,   -1,   -1,   -1,
      -1,   -1,   -1,   -1,   -1,   -1,   -1,   -1,
      -1,   -1,   -1,   -1, 2821,   -1,   -1,   -1,
      -1,   -1,   -1, 2822,   -1,   -1, 2823,   -1,
      -1,   -1,   -1,   -1,   -1,   -1,   -1,   -1,
      -1,   -1,   -1, 2824,   -1,   -1,   -1,   -1,
      -1,   -1,   -1,   -1,   -1,   -1, 2825,   -1,
      -1, 2826,   -1,   -1,   -1,   -1,   -1,   -1,
      -1,   -1,   -1,   -1,   -1,   -1,   -1,   -1,
    2827,   -1, 2828,   -1,   -1,   -1,   -1,   -1,
      -1,   -1,   -1,   -1,   -1,   -1, 2829, 2830,
    2831,   -1,   -1, 2832,   -1,   -1,   -1,   -1,
      -1,   -1,   -1, 2833,   -1,   -1,   -1,   -1,
      -1,   -1,   -1,   -1,   -1,   -1,   -1,   -1,
      -1,   -1,   -1, 2834,   -1,   -1,   -1,   -1,
      -1,   -1,   -1,   -1,   -1,   -1,   -1,   -1,
      -1,   -1,   -1,   -1,   -1,   -1,   -1,   -1,
      -1,   -1,   -1,   -1,   -1,   -1,   -1,   -1,
      -1,   -1,   -1,   -1,   -1,   -1,   -1,   -1,
      -1,   -1,   -1,   -1,   -1,   -1,   -1,   -1,
      -1,   -1,   -1,   -1,   -1,   -1, 2835,   -1,
      -1,   -1,   -1,   -1,   -1,   -1,   -1,   -1,
      -1,   -1,   -1,   -1,   -1,   -1,   -1,   -1,
      -1,   -1,   -1,   -1,   -1,   -1,   -1,   -1,
      -1,   -1,   -1,   -1,   -1,   -1,   -1, 2836,
      -1, 2837,   -1,   -1,   -1,   -1,   -1,   -1,
      -1, 2838,   -1, 2839,   -1,   -1,   -1,   -1,
      -1,   -1, 2840,   -1,   -1,   -1, 2841,   -1,
      -1,   -1,   -1,   -1,   -1,   -1,   -1,   -1,
      -1,   -1,   -1,   -1,   -1,   -1,   -1,   -1,
      -1,   -1,   -1,   -1,   -1,   -1,   -1,   -1,
      -1,   -1,   -1,   -1,   -1,   -1,   -1,   -1,
    2842,   -1,   -1,   -1,   -1,   -1,   -1,   -1,
      -1, 2843,   -1,   -1,   -1,   -1,   -1,   -1,
      -1,   -1,   -1,   -1,   -1, 2844,   -1,   -1,
      -1,   -1,   -1,   -1,   -1,   -1,   -1,   -1,
    2845,   -1, 2846,   -1,   -1,   -1,   -1,   -1,
      -1,   -1,   -1,   -1,   -1,   -1,   -1,   -1,
      -1, 2847,   -1, 2848,   -1,   -1,   -1,   -1,
    2849,   -1,   -1,   -1,   -1,   -1,   -1,   -1,
      -1,   -1,   -1,   -1, 2850,   -1,   -1,   -1,
      -1, 2851,   -1,   -1,   -1,   -1,   -1,   -1,
      -1,   -1,   -1,   -1,   -1,   -1,   -1,   -1,
      -1, 2852,   -1,   -1,   -1,   -1,   -1,   -1,
    2853, 2854,   -1,   -1,   -1,   -1,   -1, 2855,
      -1,   -1,   -1,   -1,   -1,   -1,   -1,   -1,
      -1, 2856,   -1,   -1,   -1,   -1, 2857,   -1,
      -1,   -1,   -1, 2858,   -1,   -1,   -1,   -1,
    2859,   -1,   -1,   -1,   -1,   -1,   -1,   -1,
      -1,   -1,   -1,   -1,   -1,   -1,   -1,   -1,
      -1,   -1,   -1,   -1,   -1,   -1,   -1,   -1,
      -1,   -1,   -1,   -1,   -1,   -1,   -1,   -1,
      -1,   -1,   -1,   -1,   -1,   -1,   -1,   -1,
      -1,   -1,   -1,   -1,   -1, 2860,   -1,   -1,
    2861,   -1,   -1,   -1,   -1,   -1,   -1,   -1,
      -1,   -1,   -1,   -1,   -1,   -1,   -1,   -1,
      -1,   -1,   -1, 2862,   -1,   -1,   -1,   -1,
      -1,   -1,   -1,   -1,   -1,   -1,   -1,   -1,
      -1,   -1,   -1,   -1,   -1,   -1,   -1, 2863,
    2864,   -1,   -1,   -1,   -1,   -1,   -1,   -1,
      -1, 2865,   -1,   -1,   -1,   -1,   -1,   -1,
      -1,   -1,   -1, 2866,   -1,   -1,   -1,   -1,
    2867,   -1,   -1, 2868,   -1,   -1,   -1,   -1,
      -1,   -1,   -1,   -1,   -1,   -1,   -1,   -1,
      -1,   -1,   -1,   -1,   -1,   -1,   -1,   -1,
      -1, 2869,   -1,   -1,   -1,   -1,   -1,   -1,
      -1,   -1,   -1,   -1,   -1,   -1,   -1,   -1,
      -1,   -1,   -1,   -1,   -1,   -1,   -1,   -1,
      -1,   -1,   -1,   -1,   -1,   -1,   -1,   -1,
      -1,   -1, 2870,   -1,   -1,   -1,   -1,   -1,
      -1,   -1,   -1, 2871,   -1, 2872, 2873,   -1,
      -1,   -1,   -1,   -1,   -1, 2874,   -1,   -1,
      -1,   -1,   -1,   -1,   -1,   -1,   -1,   -1,
      -1,   -1,   -1,   -1,   -1, 2875,   -1,   -1,
      -1,   -1,   -1, 2876,   -1,   -1,   -1,   -1,
      -1,   -1, 2877,   -1,   -1,   -1,   -1,   -1,
      -1,   -1,   -1,   -1,   -1,   -1,   -1,   -1,
      -1, 2878,   -1,   -1,   -1,   -1,   -1,   -1,
      -1,   -1,   -1,   -1,   -1,   -1,   -1, 2879,
      -1,   -1, 2880,   -1,   -1,   -1,   -1,   -1,
      -1, 2881,   -1,   -1,   -1,   -1,   -1,   -1,
      -1,   -1, 2882,   -1,   -1,   -1,   -1,   -1,
      -1,   -1,   -1,   -1,   -1,   -1,   -1,   -1,
      -1,   -1,   -1,   -1, 2883,   -1,   -1,   -1,
      -1,   -1, 2884,   -1,   -1,   -1,   -1,   -1,
      -1,   -1,   -1,   -1,   -1,   -1,   -1,   -1,
    2885,   -1,   -1,   -1,   -1,   -1,   -1,   -1,
      -1,   -1,   -1,   -1,   -1,   -1,   -1,   -1,
      -1,   -1,   -1,   -1, 2886, 2887,   -1,   -1,
      -1,   -1,   -1,   -1, 2888,   -1,   -1,   -1,
      -1,   -1,   -1,   -1,   -1,   -1, 2889,   -1,
      -1, 2890,   -1, 2891,   -1,   -1,   -1,   -1,
      -1,   -1,   -1,   -1,   -1,   -1,   -1,   -1,
      -1,   -1, 2892,   -1,   -1,   -1, 2893,   -1,
      -1,   -1,   -1,   -1,   -1,   -1,   -1,   -1,
      -1, 2894,   -1,   -1, 2895,   -1, 2896,   -1,
      -1, 2897,   -1,   -1,   -1,   -1,   -1,   -1,
    2898,   -1,   -1,   -1,   -1,   -1, 2899,   -1,
    2900,   -1,   -1,   -1,   -1,   -1,   -1,   -1,
      -1,   -1,   -1,   -1,   -1,   -1,   -1,   -1,
      -1,   -1, 2901,   -1,   -1,   -1,   -1,   -1,
      -1,   -1,   -1,   -1,   -1,   -1,   -1,   -1,
    2902,   -1,   -1, 2903,   -1,   -1,   -1,   -1,
      -1,   -1,   -1,   -1,   -1,   -1,   -1, 2904,
      -1,   -1,   -1,   -1,   -1,   -1,   -1,   -1,
      -1,   -1,   -1,   -1,   -1,   -1,   -1,   -1,
      -1,   -1,   -1,   -1,   -1,   -1,   -1,   -1,
      -1,   -1,   -1,   -1,   -1,   -1, 2905,   -1,
      -1,   -1,   -1,   -1,   -1,   -1,   -1,   -1,
    2906,   -1,   -1,   -1,   -1,   -1,   -1,   -1,
      -1,   -1,   -1,   -1,   -1,   -1,   -1, 2907,
      -1,   -1,   -1,   -1, 2908,   -1,   -1,   -1,
      -1,   -1,   -1,   -1,   -1,   -1,   -1, 2909,
      -1,   -1,   -1,   -1,   -1,   -1,   -1,   -1,
      -1,   -1,   -1,   -1,   -1,   -1,   -1,   -1,
      -1,   -1,   -1,   -1,   -1,   -1, 2910,   -1,
      -1,   -1,   -1,   -1,   -1,   -1,   -1,   -1,
      -1,   -1,   -1,   -1, 2911,   -1,   -1,   -1,
    2912,   -1,   -1,   -1,   -1, 2913,   -1,   -1,
      -1,   -1, 2914,   -1,   -1,   -1,   -1,   -1,
      -1,   -1,   -1,   -1,   -1, 2915,   -1,   -1,
      -1, 2916,   -1, 2917, 2918,   -1,   -1,   -1,
      -1,   -1,   -1,   -1,   -1,   -1,   -1,   -1,
      -1,   -1,   -1,   -1,   -1,   -1,   -1,   -1,
      -1,   -1,   -1,   -1,   -1, 2919,   -1,   -1,
      -1, 2920,   -1,   -1,   -1,   -1,   -1,   -1,
      -1,   -1,   -1,   -1,   -1,   -1,   -1,   -1,
      -1,   -1,   -1,   -1,   -1,   -1,   -1,   -1,
      -1,   -1,   -1,   -1,   -1,   -1,   -1,   -1,
      -1,   -1,   -1,   -1,   -1,   -1,   -1,   -1,
      -1,   -1,   -1,   -1,   -1,   -1,   -1,   -1,
      -1,   -1,   -1,   -1,   -1,   -1,   -1,   -1,
      -1,   -1,   -1,   -1,   -1,   -1,   -1,   -1,
      -1,   -1,   -1,   -1,   -1,   -1,   -1,   -1,
      -1,   -1,   -1,   -1,   -1,   -1,   -1,   -1,
      -1, 2921,   -1,   -1,   -1,   -1,   -1,   -1,
      -1,   -1,   -1,   -1,   -1,   -1,   -1,   -1,
      -1,   -1,   -1,   -1,   -1,   -1,   -1,   -1,
      -1,   -1,   -1,   -1,   -1,   -1,   -1,   -1,
      -1,   -1,   -1,   -1, 2922,   -1, 2923,   -1,
      -1,   -1,   -1,   -1,   -1,   -1,   -1,   -1,
      -1,   -1,   -1,   -1,   -1,   -1, 2924,   -1,
      -1,   -1, 2925,   -1,   -1,   -1,   -1,   -1,
      -1,   -1,   -1,   -1,   -1,   -1,   -1,   -1,
      -1,   -1,   -1,   -1,   -1,   -1,   -1,   -1,
      -1,   -1,   -1,   -1,   -1,   -1, 2926, 2927,
      -1,   -1,   -1,   -1,   -1,   -1,   -1,   -1,
      -1,   -1,   -1,   -1,   -1,   -1,   -1,   -1,
    2928,   -1, 2929,   -1,   -1,   -1,   -1,   -1,
      -1,   -1,   -1,   -1,   -1,   -1,   -1,   -1,
      -1,   -1,   -1,   -1,   -1,   -1,   -1,   -1,
      -1,   -1,   -1,   -1,   -1,   -1, 2930,   -1,
      -1,   -1,   -1,   -1,   -1,   -1,   -1,   -1,
      -1,   -1, 2931,   -1,   -1,   -1,   -1,   -1,
      -1,   -1,   -1,   -1,   -1, 2932,   -1,   -1,
      -1,   -1,   -1,   -1,   -1,   -1, 2933,   -1,
      -1,   -1,   -1, 2934,   -1,   -1,   -1,   -1,
      -1,   -1,   -1,   -1,   -1,   -1,   -1,   -1,
    2935,   -1,   -1,   -1,   -1,   -1,   -1,   -1,
      -1,   -1,   -1,   -1,   -1,   -1,   -1, 2936,
    2937,   -1,   -1,   -1,   -1,   -1,   -1,   -1,
      -1,   -1,   -1,   -1,   -1,   -1,   -1,   -1,
      -1,   -1,   -1,   -1,   -1,   -1,   -1,   -1,
      -1,   -1,   -1,   -1,   -1,   -1,   -1,   -1,
      -1,   -1,   -1,   -1,   -1,   -1,   -1,   -1,
      -1,   -1, 2938,   -1,   -1,   -1,   -1, 2939,
      -1,   -1,   -1,   -1,   -1,   -1,   -1,   -1,
    2940,   -1,   -1,   -1,   -1,   -1,   -1,   -1,
    2941,   -1,   -1,   -1,   -1,   -1,   -1,   -1,
      -1,   -1,   -1,   -1,   -1,   -1,   -1,   -1,
      -1,   -1,   -1,   -1,   -1,   -1,   -1,   -1,
      -1,   -1,   -1, 2942,   -1,   -1,   -1,   -1,
      -1, 2943,   -1,   -1,   -1,   -1,   -1,   -1,
      -1,   -1,   -1,   -1,   -1,   -1,   -1, 2944,
      -1,   -1, 2945,   -1,   -1, 2946,   -1, 2947,
      -1,   -1,   -1,   -1,   -1,   -1,   -1,   -1,
      -1,   -1,   -1,   -1,   -1,   -1,   -1,   -1,
      -1,   -1,   -1, 2948,   -1,   -1,   -1,   -1,
    2949,   -1, 2950, 2951,   -1, 2952,   -1, 2953,
      -1, 2954, 2955,   -1, 2956,   -1,   -1,   -1,
      -1, 2957,   -1,   -1,   -1,   -1,   -1,   -1,
      -1,   -1,   -1,   -1,   -1,   -1,   -1,   -1,
      -1,   -1,   -1,   -1,   -1,   -1,   -1, 2958,
    2959,   -1,   -1,   -1,   -1,   -1,   -1,   -1,
      -1,   -1,   -1,   -1,   -1,   -1,   -1,   -1,
      -1,   -1,   -1,   -1, 2960,   -1,   -1,   -1,
      -1, 2961,   -1,   -1,   -1,   -1, 2962,   -1,
    2963, 2964,   -1,   -1,   -1,   -1,   -1,   -1,
      -1,   -1,   -1,   -1,   -1, 2965,   -1,   -1,
    2966,   -1, 2967, 2968, 2969,   -1,   -1, 2970,
      -1,   -1,   -1,   -1, 2971,   -1,   -1,   -1,
    2972, 2973,   -1,   -1,   -1,   -1,   -1,   -1,
      -1,   -1, 2974,   -1,   -1, 2975,   -1, 2976,
    2977,   -1,   -1,   -1,   -1, 2978,   -1,   -1,
      -1,   -1,   -1, 2979,   -1,   -1,   -1,   -1,
      -1,   -1, 2980,   -1,   -1,   -1,   -1,   -1,
      -1,   -1,   -1,   -1,   -1,   -1,   -1,   -1,
      -1,   -1,   -1,   -1,   -1,   -1,   -1,   -1,
      -1,   -1,   -1,   -1,   -1,   -1,   -1, 2981,
      -1,   -1,   -1,   -1,   -1,   -1,   -1, 2982,
      -1,   -1,   -1,   -1, 2983,   -1,   -1,   -1,
      -1, 2984,   -1,   -1,   -1,   -1, 2985,   -1,
      -1, 2986,   -1,   -1,   -1, 2987, 2988,   -1,
      -1,   -1, 2989,   -1,   -1, 2990, 2991,   -1,
      -1,   -1,   -1,   -1,   -1,   -1,   -1,   -1,
      -1,   -1,   -1,   -1,   -1,   -1, 2992,   -1,
      -1,   -1, 2993,   -1,   -1,   -1,   -1,   -1,
      -1,   -1,   -1,   -1,   -1, 2994,   -1,   -1,
      -1, 2995, 2996,   -1,   -1,   -1,   -1,   -1,
      -1,   -1,   -1,   -1,   -1,   -1, 2997,   -1,
    2998,   -1,   -1,   -1,   -1,   -1,   -1,   -1,
      -1,   -1,   -1, 2999,   -1,   -1,   -1,   -1,
      -1,   -1,   -1,   -1,   -1,   -1, 3000,   -1,
      -1,   -1,   -1,   -1,   -1,   -1, 3001, 3002,
      -1,   -1,   -1,   -1,   -1,   -1,   -1,   -1,
      -1,   -1,   -1,   -1,   -1,   -1,   -1,   -1,
      -1,   -1,   -1,   -1,   -1,   -1, 3003,   -1,
      -1, 3004,   -1,   -1,   -1,   -1,   -1,   -1,
      -1,   -1,   -1,   -1,   -1,   -1,   -1,   -1,
    3005,   -1,   -1,   -1,   -1,   -1,   -1,   -1,
      -1,   -1,   -1,   -1,   -1,   -1,   -1,   -1,
      -1, 3006,   -1,   -1,   -1,   -1,   -1,   -1,
      -1,   -1,   -1, 3007,   -1,   -1, 3008,   -1,
      -1,   -1,   -1,   -1,   -1,   -1,   -1,   -1,
      -1,   -1,   -1,   -1,   -1,   -1,   -1,   -1,
      -1,   -1,   -1,   -1,   -1,   -1,   -1,   -1,
      -1,   -1,   -1,   -1,   -1,   -1,   -1,   -1,
    3009,   -1, 3010,   -1,   -1, 3011,   -1,   -1,
      -1, 3012, 3013,   -1,   -1,   -1,   -1, 3014,
      -1,   -1,   -1,   -1,   -1,   -1,   -1,   -1,
    3015,   -1,   -1,   -1,   -1,   -1,   -1,   -1,
      -1,   -1, 3016,   -1,   -1,   -1,   -1,   -1,
      -1,   -1,   -1,   -1,   -1,   -1,   -1,   -1,
      -1,   -1, 3017,   -1,   -1,   -1, 3018, 3019,
      -1,   -1,   -1, 3020,   -1,   -1,   -1,   -1,
      -1,   -1,   -1,   -1,   -1,   -1,   -1,   -1,
      -1,   -1, 3021, 3022,   -1,   -1,   -1, 3023,
      -1,   -1,   -1,   -1, 3024,   -1,   -1,   -1,
      -1,   -1,   -1,   -1,   -1,   -1, 3025,   -1,
      -1,   -1,   -1,   -1,   -1,   -1,   -1,   -1,
      -1,   -1, 3026,   -1, 3027,   -1,   -1,   -1,
      -1, 3028,   -1,   -1,   -1,   -1,   -1,   -1,
      -1,   -1,   -1, 3029,   -1,   -1,   -1,   -1,
    3030,   -1,   -1,   -1, 3031, 3032, 3033,   -1,
      -1,   -1,   -1,   -1,   -1, 3034,   -1,   -1,
      -1,   -1, 3035,   -1,   -1,   -1,   -1,   -1,
      -1,   -1,   -1,   -1,   -1,   -1,   -1,   -1,
      -1,   -1,   -1,   -1,   -1,   -1,   -1,   -1,
      -1,   -1, 3036,   -1,   -1, 3037,   -1, 3038,
      -1,   -1,   -1,   -1,   -1,   -1,   -1, 3039,
      -1,   -1,   -1,   -1,   -1,   -1,   -1,   -1,
      -1,   -1,   -1,   -1,   -1,   -1, 3040, 3041,
      -1,   -1,   -1,   -1,   -1,   -1,   -1,   -1,
    3042,   -1,   -1,   -1,   -1, 3043,   -1,   -1,
      -1,   -1,   -1,   -1,   -1,   -1,   -1, 3044,
      -1,   -1,   -1,   -1, 3045,   -1,   -1,   -1,
      -1, 3046,   -1, 3047, 3048,   -1,   -1,   -1,
      -1, 3049,   -1,   -1,   -1,   -1,   -1,   -1,
    3050,   -1,   -1,   -1,   -1,   -1,   -1,   -1,
      -1,   -1,   -1, 3051,   -1,   -1,   -1,   -1,
      -1,   -1,   -1,   -1,   -1,   -1, 3052, 3053,
      -1,   -1,   -1,   -1,   -1,   -1,   -1,   -1,
    3054, 3055, 3056,   -1, 3057,   -1,   -1,   -1,
      -1,   -1,   -1,   -1,   -1,   -1,   -1,   -1,
      -1,   -1,   -1,   -1,   -1, 3058,   -1,   -1,
      -1,   -1,   -1,   -1,   -1,   -1,   -1,   -1,
      -1, 3059,   -1,   -1, 3060,   -1,   -1,   -1,
      -1,   -1,   -1,   -1,   -1,   -1,   -1,   -1,
      -1,   -1,   -1,   -1, 3061,   -1,   -1,   -1,
    3062,   -1,   -1,   -1, 3063,   -1,   -1, 3064,
      -1,   -1,   -1, 3065,   -1,   -1,   -1, 3066,
      -1, 3067, 3068, 3069,   -1,   -1,   -1,   -1,
      -1,   -1,   -1,   -1,   -1,   -1,   -1,   -1,
      -1,   -1,   -1,   -1,   -1,   -1,   -1,   -1,
      -1, 3070,   -1,   -1,   -1,   -1,   -1,   -1,
      -1, 3071,   -1,   -1,   -1, 3072,   -1,   -1,
      -1,   -1,   -1,   -1,   -1,   -1,   -1,   -1,
    3073,   -1,   -1,   -1,   -1,   -1,   -1,   -1,
      -1,   -1,   -1,   -1,   -1,   -1,   -1,   -1,
      -1,   -1,   -1,   -1,   -1,   -1,   -1,   -1,
      -1,   -1,   -1,   -1, 3074,   -1,   -1,   -1,
      -1,   -1,   -1,   -1, 3075,   -1,   -1,   -1,
      -1,   -1,   -1,   -1,   -1,   -1,   -1,   -1,
      -1,   -1,   -1, 3076,   -1,   -1,   -1,   -1,
      -1,   -1,   -1,   -1,   -1, 3077,   -1,   -1,
    3078,   -1,   -1,   -1,   -1,   -1,   -1,   -1,
      -1,   -1,   -1,   -1,   -1, 3079,   -1,   -1,
      -1,   -1,   -1, 3080,   -1,   -1,   -1,   -1,
      -1,   -1,   -1,   -1,   -1,   -1,   -1, 3081,
      -1,   -1,   -1,   -1, 3082,   -1,   -1,   -1,
      -1,   -1,   -1,   -1,   -1,   -1,   -1,   -1,
      -1,   -1, 3083,   -1, 3084,   -1,   -1,   -1,
      -1,   -1,   -1,   -1, 3085,   -1, 3086,   -1,
      -1,   -1,   -1,   -1,   -1,   -1,   -1, 3087,
    3088,   -1,   -1,   -1,   -1,   -1,   -1,   -1,
      -1, 3089,   -1,   -1,   -1,   -1,   -1,   -1,
    3090,   -1,   -1,   -1,   -1,   -1,   -1,   -1,
      -1,   -1,   -1,   -1,   -1,   -1,   -1,   -1,
      -1,   -1,   -1,   -1,   -1, 3091,   -1,   -1,
      -1,   -1,   -1,   -1,   -1,   -1,   -1, 3092,
      -1, 3093,   -1,   -1, 3094,   -1,   -1,   -1,
    3095,   -1,   -1,   -1,   -1,   -1,   -1,   -1,
      -1,   -1,   -1, 3096,   -1,   -1,   -1,   -1,
      -1,   -1,   -1, 3097,   -1,   -1,   -1,   -1,
      -1,   -1,   -1, 3098,   -1,   -1, 3099,   -1,
    3100,   -1,   -1,   -1,   -1,   -1,   -1,   -1,
      -1,   -1,   -1,   -1,   -1,   -1, 3101,   -1,
      -1,   -1,   -1,   -1, 3102,   -1,   -1,   -1,
      -1,   -1,   -1, 3103,   -1,   -1,   -1,   -1,
    3104,   -1,   -1,   -1,   -1,   -1,   -1,   -1,
    3105,   -1, 3106,   -1,   -1,   -1,   -1,   -1,
      -1, 3107,   -1,   -1,   -1,   -1,   -1,   -1,
      -1,   -1,   -1,   -1,   -1,   -1, 3108, 3109,
      -1,   -1,   -1, 3110,   -1,   -1,   -1,   -1,
      -1,   -1,   -1,   -1,   -1,   -1,   -1,   -1,
      -1,   -1, 3111,   -1,   -1,   -1, 3112,   -1,
      -1, 3113,   -1,   -1,   -1,   -1,   -1,   -1,
      -1,   -1,   -1,   -1,   -1,   -1,   -1,   -1,
      -1, 3114,   -1,   -1,   -1,   -1,   -1, 3115,
      -1,   -1,   -1,   -1,   -1,   -1,   -1,   -1,
      -1,   -1, 3116, 3117,   -1,   -1,   -1,   -1,
      -1,   -1,   -1,   -1,   -1, 3118,   -1, 3119,
      -1,   -1,   -1,   -1,   -1,   -1,   -1,   -1,
      -1,   -1,   -1,   -1,   -1,   -1,   -1,   -1,
      -1,   -1, 3120,   -1,   -1,   -1,   -1,   -1,
      -1,   -1,   -1,   -1,   -1,   -1,   -1,   -1,
      -1,   -1,   -1, 3121,   -1,   -1,   -1,   -1,
      -1,   -1, 3122,   -1,   -1,   -1,   -1,   -1,
      -1,   -1,   -1,   -1,   -1,   -1,   -1,   -1,
      -1,   -1,   -1,   -1,   -1,   -1,   -1,   -1,
      -1,   -1,   -1,   -1,   -1,   -1, 3123,   -1,
      -1,   -1,   -1,   -1,   -1, 3124,   -1,   -1,
    3125,   -1,   -1,   -1,   -1,   -1, 3126,   -1,
      -1,   -1,   -1,   -1,   -1,   -1,   -1,   -1,
      -1,   -1,   -1,   -1,   -1,   -1, 3127,   -1,
      -1,   -1,   -1,   -1,   -1,   -1,   -1,   -1,
      -1,   -1,   -1,   -1,   -1, 3128,   -1,   -1,
      -1,   -1,   -1,   -1,   -1,   -1,   -1,   -1,
      -1,   -1,   -1,   -1,   -1,   -1,   -1,   -1,
      -1,   -1,   -1,   -1,   -1,   -1,   -1,   -1,
      -1,   -1, 3129,   -1,   -1,   -1,   -1,   -1,
      -1,   -1,   -1,   -1,   -1,   -1,   -1,   -1,
      -1,   -1,   -1,   -1,   -1, 3130,   -1,   -1,
      -1,   -1,   -1,   -1,   -1,   -1,   -1, 3131,
      -1,   -1,   -1,   -1,   -1,   -1,   -1,   -1,
      -1,   -1,   -1,   -1,   -1,   -1,   -1,   -1,
      -1, 3132,   -1,   -1, 3133,   -1,   -1,   -1,
      -1,   -1,   -1,   -1,   -1,   -1,   -1,   -1,
      -1,   -1,   -1,   -1,   -1,   -1,   -1,   -1,
      -1,   -1, 3134,   -1,   -1, 3135,   -1, 3136,
    3137,   -1,   -1,   -1,   -1, 3138,   -1,   -1,
      -1, 3139,   -1,   -1,   -1,   -1,   -1,   -1,
    3140,   -1,   -1,   -1,   -1,   -1, 3141,   -1,
      -1,   -1,   -1,   -1,   -1,   -1,   -1,   -1,
      -1,   -1,   -1,   -1,   -1,   -1,   -1,   -1,
      -1,   -1,   -1,   -1,   -1,   -1,   -1,   -1,
      -1,   -1,   -1, 3142,   -1,   -1,   -1,   -1,
      -1,   -1,   -1,   -1,   -1, 3143,   -1,   -1,
      -1,   -1, 3144,   -1, 3145,   -1,   -1,   -1,
      -1,   -1,   -1,   -1,   -1,   -1,   -1,   -1,
      -1,   -1,   -1,   -1,   -1,   -1,   -1,   -1,
      -1,   -1,   -1,   -1,   -1,   -1,   -1, 3146,
      -1,   -1,   -1,   -1,   -1,   -1,   -1,   -1,
      -1,   -1,   -1,   -1,   -1,   -1, 3147, 3148,
      -1,   -1,   -1,   -1, 3149,   -1,   -1,   -1,
      -1,   -1,   -1,   -1,   -1,   -1,   -1,   -1,
      -1,   -1,   -1,   -1,   -1,   -1,   -1,   -1,
      -1,   -1, 3150,   -1,   -1, 3151,   -1, 3152,
      -1,   -1,   -1,   -1, 3153,   -1,   -1,   -1,
    3154,   -1,   -1,   -1,   -1,   -1,   -1, 3155,
      -1,   -1,   -1, 3156,   -1,   -1,   -1,   -1,
    3157,   -1,   -1,   -1,   -1,   -1,   -1,   -1,
      -1,   -1,   -1,   -1, 3158,   -1,   -1,   -1,
    3159,   -1,   -1,   -1,   -1,   -1,   -1,   -1,
      -1,   -1,   -1,   -1,   -1,   -1,   -1,   -1,
      -1,   -1,   -1,   -1,   -1,   -1,   -1,   -1,
      -1,   -1,   -1,   -1,   -1,   -1,   -1,   -1,
      -1,   -1,   -1,   -1,   -1,   -1, 3160,   -1,
      -1,   -1,   -1,   -1,   -1,   -1,   -1,   -1,
      -1, 3161,   -1,   -1,   -1, 3162, 3163,   -1,
      -1,   -1,   -1,   -1, 3164,   -1,   -1,   -1,
      -1,   -1,   -1,   -1,   -1, 3165,   -1,   -1,
      -1,   -1,   -1,   -1,   -1,   -1,   -1,   -1,
    3166,   -1,   -1,   -1,   -1,   -1,   -1,   -1,
    3167,   -1,   -1,   -1,   -1,   -1,   -1,   -1,
      -1,   -1,   -1, 3168,   -1,   -1,   -1,   -1,
      -1, 3169,   -1,   -1,   -1,   -1,   -1,   -1,
      -1,   -1,   -1,   -1,   -1,   -1,   -1,   -1,
      -1,   -1,   -1,   -1,   -1, 3170,   -1,   -1,
      -1,   -1,   -1,   -1,   -1, 3171,   -1,   -1,
      -1,   -1,   -1,   -1,   -1,   -1,   -1, 3172,
      -1,   -1,   -1,   -1, 3173,   -1,   -1,   -1,
      -1,   -1,   -1,   -1,   -1,   -1,   -1,   -1,
    3174,   -1,   -1,   -1, 3175,   -1,   -1,   -1,
      -1,   -1,   -1,   -1,   -1, 3176, 3177,   -1,
      -1,   -1,   -1,   -1,   -1,   -1,   -1,   -1,
      -1,   -1,   -1,   -1,   -1,   -1, 3178, 3179,
      -1,   -1,   -1,   -1,   -1,   -1,   -1,   -1,
      -1,   -1,   -1, 3180,   -1,   -1, 3181,   -1,
    3182,   -1,   -1,   -1,   -1,   -1,   -1,   -1,
    3183, 3184,   -1,   -1,   -1,   -1,   -1,   -1,
      -1, 3185, 3186,   -1,   -1,   -1,   -1, 3187,
    3188,   -1,   -1,   -1,   -1,   -1,   -1,   -1,
      -1,   -1,   -1,   -1,   -1, 3189, 3190,   -1,
    3191,   -1,   -1,   -1,   -1,   -1,   -1,   -1,
      -1,   -1,   -1,   -1,   -1,   -1,   -1,   -1,
      -1,   -1,   -1,   -1,   -1,   -1,   -1,   -1,
      -1,   -1,   -1,   -1,   -1,   -1,   -1,   -1,
      -1,   -1,   -1,   -1,   -1, 3192,   -1,   -1,
      -1,   -1,   -1,   -1,   -1,   -1,   -1,   -1,
      -1,   -1,   -1,   -1,   -1,   -1,   -1,   -1,
      -1,   -1,   -1,   -1,   -1,   -1, 3193,   -1,
      -1,   -1,   -1,   -1,   -1,   -1,   -1,   -1,
      -1,   -1,   -1,   -1,   -1,   -1, 3194,   -1,
      -1,   -1,   -1,   -1,   -1, 3195,   -1, 3196,
    3197,   -1,   -1,   -1,   -1,   -1,   -1,   -1,
      -1,   -1,   -1,   -1, 3198,   -1,   -1,   -1,
    3199,   -1,   -1, 3200,   -1,   -1,   -1,   -1,
      -1,   -1,   -1,   -1,   -1,   -1,   -1,   -1,
      -1,   -1,   -1,   -1,   -1,   -1,   -1,   -1,
      -1,   -1,   -1,   -1,   -1,   -1, 3201,   -1,
      -1,   -1,   -1,   -1,   -1,   -1,   -1,   -1,
      -1,   -1, 3202,   -1, 3203,   -1,   -1,   -1,
    3204,   -1,   -1,   -1,   -1,   -1,   -1,   -1,
      -1,   -1,   -1,   -1,   -1,   -1,   -1,   -1,
      -1,   -1,   -1, 3205,   -1,   -1,   -1,   -1,
      -1,   -1,   -1,   -1,   -1,   -1,   -1,   -1,
      -1, 3206,   -1,   -1,   -1,   -1, 3207,   -1,
      -1,   -1,   -1, 3208,   -1,   -1,   -1,   -1,
    3209,   -1,   -1,   -1,   -1,   -1,   -1,   -1,
      -1,   -1,   -1,   -1,   -1,   -1,   -1,   -1,
      -1,   -1,   -1,   -1, 3210,   -1,   -1,   -1,
      -1,   -1,   -1,   -1, 3211,   -1,   -1,   -1,
      -1,   -1,   -1,   -1,   -1,   -1,   -1, 3212,
      -1,   -1,   -1,   -1,   -1,   -1,   -1, 3213,
    3214,   -1,   -1,   -1,   -1, 3215,   -1,   -1,
      -1,   -1,   -1,   -1,   -1,   -1, 3216,   -1,
    3217,   -1,   -1,   -1,   -1,   -1,   -1,   -1,
      -1,   -1, 3218, 3219, 3220,   -1,   -1,   -1,
    3221,   -1,   -1,   -1,   -1,   -1,   -1,   -1,
      -1, 3222, 3223,   -1,   -1,   -1,   -1,   -1,
      -1,   -1,   -1, 3224,   -1,   -1,   -1,   -1,
    3225,   -1,   -1,   -1,   -1, 3226,   -1,   -1,
      -1,   -1,   -1,   -1,   -1,   -1,   -1,   -1,
      -1,   -1,   -1,   -1,   -1,   -1,   -1,   -1,
      -1, 3227,   -1, 3228,   -1,   -1,   -1,   -1,
      -1,   -1,   -1, 3229,   -1,   -1,   -1,   -1,
      -1,   -1, 3230,   -1,   -1,   -1,   -1,   -1,
      -1,   -1, 3231,   -1,   -1,   -1,   -1, 3232,
    3233,   -1,   -1,   -1,   -1,   -1,   -1, 3234,
      -1, 3235,   -1,   -1,   -1,   -1, 3236, 3237,
      -1,   -1,   -1, 3238,   -1,   -1,   -1,   -1,
      -1, 3239,   -1,   -1, 3240,   -1,   -1,   -1,
      -1,   -1, 3241,   -1,   -1,   -1,   -1,   -1,
      -1,   -1,   -1,   -1, 3242,   -1,   -1,   -1,
      -1,   -1,   -1,   -1,   -1,   -1, 3243, 3244,
      -1,   -1,   -1,   -1,   -1,   -1,   -1,   -1,
      -1,   -1, 3245,   -1,   -1,   -1,   -1,   -1,
      -1,   -1,   -1,   -1,   -1,   -1, 3246,   -1,
      -1,   -1,   -1,   -1,   -1,   -1,   -1,   -1,
      -1,   -1,   -1,   -1,   -1,   -1, 3247,   -1,
      -1,   -1,   -1,   -1,   -1,   -1,   -1, 3248,
      -1,   -1,   -1,   -1,   -1,   -1, 3249,   -1,
      -1,   -1,   -1,   -1,   -1,   -1,   -1,   -1,
      -1,   -1,   -1,   -1,   -1,   -1,   -1,   -1,
      -1,   -1,   -1,   -1,   -1,   -1,   -1,   -1,
      -1, 3250, 3251,   -1,   -1,   -1,   -1,   -1,
      -1,   -1, 3252,   -1,   -1,   -1,   -1,   -1,
      -1,   -1,   -1,   -1,   -1, 3253,   -1,   -1,
      -1, 3254,   -1,   -1,   -1,   -1,   -1, 3255,
      -1, 3256,   -1,   -1,   -1,   -1,   -1,   -1,
      -1,   -1, 3257,   -1,   -1,   -1,   -1,   -1,
      -1,   -1,   -1,   -1, 3258,   -1,   -1,   -1,
    3259,   -1,   -1,   -1,   -1,   -1, 3260,   -1,
      -1, 3261,   -1,   -1,   -1,   -1,   -1,   -1,
      -1,   -1,   -1,   -1,   -1,   -1,   -1,   -1,
      -1,   -1,   -1,   -1,   -1, 3262,   -1, 3263,
    3264, 3265,   -1,   -1,   -1,   -1,   -1,   -1,
      -1,   -1, 3266,   -1,   -1,   -1,   -1,   -1,
    3267,   -1,   -1,   -1,   -1,   -1,   -1,   -1,
      -1,   -1,   -1,   -1,   -1,   -1,   -1,   -1,
      -1,   -1,   -1,   -1,   -1,   -1,   -1,   -1,
      -1,   -1,   -1,   -1,   -1,   -1,   -1,   -1,
      -1,   -1,   -1,   -1, 3268,   -1,   -1, 3269,
      -1,   -1,   -1,   -1,   -1,   -1,   -1,   -1,
      -1,   -1, 3270,   -1,   -1,   -1,   -1,   -1,
      -1,   -1, 3271,   -1,   -1,   -1,   -1,   -1,
      -1,   -1,   -1,   -1,   -1,   -1,   -1,   -1,
      -1,   -1,   -1,   -1,   -1,   -1,   -1,   -1,
      -1,   -1, 3272,   -1,   -1,   -1,   -1,   -1,
      -1, 3273,   -1,   -1,   -1,   -1,   -1,   -1,
    3274,   -1,   -1,   -1,   -1,   -1,   -1,   -1,
      -1,   -1,   -1,   -1,   -1,   -1,   -1,   -1,
      -1,   -1, 3275,   -1,   -1,   -1,   -1,   -1,
      -1,   -1, 3276,   -1,   -1,   -1,   -1, 3277,
      -1,   -1,   -1,   -1,   -1,   -1,   -1,   -1,
      -1,   -1,   -1,   -1,   -1, 3278,   -1,   -1,
      -1,   -1,   -1,   -1,   -1,   -1,   -1,   -1,
      -1,   -1,   -1,   -1,   -1,   -1,   -1,   -1,
      -1,   -1, 3279, 3280,   -1,   -1,   -1,   -1,
      -1,   -1,   -1,   -1,   -1,   -1,   -1,   -1,
      -1,   -1,   -1,   -1,   -1,   -1,   -1,   -1,
      -1,   -1,   -1,   -1,   -1,   -1,   -1,   -1,
      -1,   -1,   -1,   -1,   -1,   -1,   -1,   -1,
      -1,   -1,   -1,   -1,   -1,   -1,   -1,   -1,
    3281,   -1,   -1, 3282,   -1,   -1, 3283,   -1,
      -1,   -1,   -1,   -1,   -1,   -1,   -1,   -1,
    3284,   -1,   -1,   -1,   -1,   -1,   -1,   -1,
      -1,   -1,   -1,   -1,   -1,   -1,   -1,   -1,
      -1,   -1,   -1,   -1,   -1,   -1,   -1,   -1,
      -1,   -1,   -1,   -1,   -1, 3285,   -1,   -1,
      -1,   -1,   -1,   -1,   -1,   -1,   -1,   -1,
      -1,   -1,   -1,   -1,   -1,   -1,   -1,   -1,
      -1,   -1,   -1,   -1,   -1,   -1,   -1, 3286,
      -1,   -1,   -1,   -1,   -1,   -1,   -1,   -1,
      -1,   -1,   -1,   -1,   -1,   -1,   -1,   -1,
      -1,   -1,   -1,   -1,   -1,   -1,   -1,   -1,
      -1,   -1,   -1,   -1,   -1,   -1,   -1,   -1,
      -1,   -1,   -1,   -1, 3287,   -1,   -1,   -1,
      -1,   -1,   -1,   -1,   -1,   -1,   -1,   -1,
      -1,   -1,   -1,   -1,   -1, 3288,   -1,   -1,
      -1,   -1,   -1,   -1,   -1,   -1,   -1,   -1,
      -1,   -1,   -1, 3289,   -1,   -1,   -1,   -1,
      -1,   -1,   -1,   -1,   -1,   -1,   -1,   -1,
      -1,   -1,   -1,   -1,   -1,   -1,   -1,   -1,
      -1,   -1,   -1,   -1,   -1,   -1, 3290,   -1,
      -1,   -1,   -1,   -1, 3291,   -1,   -1,   -1,
      -1,   -1,   -1, 3292,   -1,   -1,   -1,   -1,
      -1,   -1,   -1,   -1,   -1,   -1,   -1,   -1,
      -1,   -1,   -1,   -1,   -1, 3293,   -1,   -1,
      -1,   -1,   -1,   -1,   -1,   -1,   -1,   -1,
      -1,   -1,   -1, 3294,   -1,   -1,   -1,   -1,
    3295, 3296,   -1,   -1,   -1,   -1,   -1,   -1,
      -1, 3297, 3298,   -1,   -1,   -1,   -1, 3299,
      -1,   -1,   -1,   -1, 3300,   -1, 3301,   -1,
      -1,   -1,   -1,   -1,   -1,   -1,   -1,   -1,
      -1,   -1,   -1,   -1,   -1,   -1,   -1,   -1,
      -1,   -1,   -1,   -1,   -1,   -1,   -1,   -1,
      -1,   -1,   -1,   -1,   -1,   -1,   -1,   -1,
      -1,   -1,   -1,   -1,   -1,   -1,   -1, 3302,
    3303,   -1,   -1,   -1, 3304,   -1,   -1,   -1,
      -1,   -1, 3305,   -1,   -1,   -1,   -1,   -1,
    3306,   -1,   -1, 3307,   -1,   -1,   -1,   -1,
      -1,   -1,   -1,   -1,   -1,   -1, 3308,   -1,
    3309,   -1,   -1,   -1,   -1,   -1,   -1,   -1,
    3310, 3311,   -1,   -1,   -1,   -1,   -1,   -1,
      -1,   -1,   -1,   -1,   -1,   -1,   -1,   -1,
      -1,   -1,   -1, 3312,   -1,   -1,   -1,   -1,
      -1, 3313,   -1,   -1,   -1,   -1,   -1, 3314,
      -1,   -1,   -1,   -1,   -1,   -1, 3315,   -1,
      -1,   -1,   -1,   -1,   -1,   -1, 3316,   -1,
      -1,   -1,   -1,   -1,   -1,   -1,   -1,   -1,
      -1,   -1,   -1,   -1, 3317,   -1,   -1,   -1,
      -1,   -1,   -1,   -1,   -1,   -1,   -1,   -1,
      -1,   -1, 3318,   -1, 3319,   -1,   -1,   -1,
      -1,   -1,   -1,   -1,   -1,   -1,   -1,   -1,
      -1,   -1,   -1,   -1,   -1,   -1,   -1,   -1,
      -1,   -1,   -1,   -1,   -1,   -1,   -1,   -1,
      -1,   -1,   -1,   -1,   -1, 3320,   -1,   -1,
      -1,   -1,   -1, 3321,   -1,   -1,   -1,   -1,
      -1,   -1,   -1,   -1,   -1,   -1,   -1,   -1,
      -1,   -1,   -1,   -1,   -1,   -1,   -1,   -1,
    3322,   -1,   -1,   -1,   -1,   -1, 3323,   -1,
      -1,   -1,   -1,   -1,   -1,   -1,   -1,   -1,
      -1,   -1,   -1,   -1,   -1,   -1,   -1,   -1,
      -1,   -1, 3324, 3325,   -1,   -1,   -1, 3326,
    3327,   -1,   -1,   -1, 3328,   -1,   -1,   -1,
      -1,   -1,   -1, 3329,   -1,   -1,   -1,   -1,
      -1, 3330,   -1,   -1, 3331,   -1,   -1,   -1,
      -1,   -1,   -1,   -1,   -1,   -1,   -1,   -1,
      -1,   -1,   -1,   -1,   -1,   -1,   -1,   -1,
      -1,   -1,   -1,   -1,   -1,   -1, 3332,   -1,
      -1,   -1,   -1, 3333,   -1,   -1,   -1,   -1,
    3334,   -1,   -1,   -1,   -1,   -1,   -1,   -1,
      -1,   -1,   -1,   -1,   -1,   -1,   -1,   -1,
      -1,   -1,   -1,   -1,   -1,   -1, 3335, 3336,
      -1, 3337,   -1,   -1,   -1,   -1, 3338,   -1,
      -1,   -1,   -1,   -1,   -1,   -1,   -1,   -1,
      -1,   -1,   -1,   -1,   -1,   -1,   -1,   -1,
      -1,   -1,   -1,   -1, 3339,   -1,   -1,   -1,
      -1,   -1,   -1,   -1,   -1,   -1,   -1, 3340,
      -1,   -1,   -1, 3341,   -1,   -1,   -1,   -1,
      -1,   -1, 3342,   -1,   -1,   -1,   -1,   -1,
    3343,   -1,   -1,   -1,   -1, 3344,   -1,   -1,
      -1,   -1, 3345,   -1,   -1,   -1, 3346,   -1,
      -1, 3347,   -1,   -1,   -1,   -1,   -1,   -1,
    3348,   -1,   -1,   -1,   -1, 3349, 3350,   -1,
      -1,   -1,   -1, 3351,   -1,   -1,   -1, 3352,
      -1,   -1,   -1,   -1,   -1,   -1,   -1, 3353,
      -1,   -1,   -1,   -1, 3354,   -1,   -1,   -1,
    3355,   -1,   -1, 3356,   -1, 3357,   -1,   -1,
      -1,   -1,   -1,   -1,   -1,   -1,   -1, 3358,
      -1,   -1,   -1,   -1, 3359,   -1,   -1,   -1,
      -1, 3360, 3361,   -1, 3362, 3363,   -1,   -1,
      -1,   -1,   -1,   -1,   -1,   -1,   -1,   -1,
      -1,   -1,   -1,   -1,   -1,   -1,   -1,   -1,
      -1,   -1,   -1,   -1,   -1, 3364,   -1,   -1,
      -1,   -1,   -1,   -1,   -1,   -1,   -1,   -1,
      -1,   -1,   -1,   -1,   -1,   -1,   -1, 3365,
      -1,   -1,   -1,   -1,   -1,   -1,   -1,   -1,
      -1,   -1,   -1,   -1,   -1,   -1,   -1,   -1,
      -1,   -1,   -1,   -1,   -1,   -1, 3366,   -1,
      -1,   -1,   -1,   -1,   -1,   -1,   -1,   -1,
      -1,   -1,   -1,   -1,   -1,   -1,   -1,   -1,
      -1,   -1,   -1,   -1,   -1,   -1,   -1, 3367,
      -1,   -1,   -1,   -1,   -1,   -1,   -1,   -1,
      -1,   -1,   -1,   -1,   -1,   -1,   -1,   -1,
      -1, 3368,   -1,   -1,   -1,   -1,   -1,   -1,
      -1, 3369,   -1,   -1,   -1,   -1,   -1, 3370,
      -1,   -1, 3371,   -1,   -1,   -1,   -1,   -1,
      -1,   -1,   -1,   -1,   -1, 3372,   -1,   -1,
      -1,   -1,   -1,   -1,   -1,   -1,   -1,   -1,
      -1,   -1,   -1, 3373,   -1,   -1,   -1,   -1,
      -1,   -1, 3374,   -1,   -1,   -1, 3375,   -1,
      -1,   -1,   -1,   -1,   -1,   -1,   -1,   -1,
      -1,   -1,   -1,   -1, 3376,   -1,   -1,   -1,
      -1,   -1,   -1,   -1,   -1,   -1,   -1,   -1,
      -1,   -1,   -1, 3377,   -1,   -1,   -1,   -1,
      -1,   -1,   -1,   -1,   -1,   -1,   -1, 3378,
      -1,   -1,   -1,   -1, 3379,   -1,   -1,   -1,
      -1,   -1,   -1,   -1,   -1,   -1,   -1,   -1,
      -1,   -1,   -1,   -1,   -1,   -1,   -1,   -1,
      -1,   -1,   -1, 3380,   -1,   -1,   -1, 3381,
      -1,   -1,   -1,   -1,   -1,   -1,   -1,   -1,
      -1,   -1,   -1,   -1,   -1,   -1,   -1,   -1,
      -1,   -1,   -1,   -1,   -1,   -1,   -1,   -1,
      -1,   -1,   -1,   -1,   -1,   -1,   -1,   -1,
      -1,   -1,   -1, 3382,   -1,   -1,   -1,   -1,
      -1,   -1,   -1, 3383, 3384,   -1,   -1, 3385,
      -1,   -1,   -1, 3386,   -1,   -1,   -1,   -1,
      -1,   -1,   -1,   -1,   -1,   -1, 3387,   -1,
      -1,   -1,   -1,   -1,   -1,   -1,   -1,   -1,
      -1,   -1,   -1,   -1,   -1,   -1,   -1,   -1,
      -1, 3388, 3389,   -1,   -1,   -1,   -1,   -1,
      -1,   -1, 3390,   -1,   -1,   -1,   -1,   -1,
      -1,   -1,   -1,   -1,   -1,   -1,   -1,   -1,
      -1,   -1,   -1,   -1,   -1,   -1,   -1,   -1,
      -1,   -1,   -1,   -1,   -1,   -1,   -1, 3391,
      -1,   -1, 3392,   -1,   -1, 3393,   -1,   -1,
      -1,   -1,   -1,   -1, 3394,   -1,   -1,   -1,
      -1,   -1, 3395,   -1,   -1,   -1, 3396, 3397,
    3398,   -1, 3399,   -1,   -1,   -1,   -1,   -1,
      -1,   -1,   -1,   -1,   -1,   -1,   -1,   -1,
      -1,   -1,   -1,   -1,   -1,   -1,   -1,   -1,
    3400,   -1,   -1,   -1,   -1,   -1,   -1,   -1,
      -1,   -1,   -1,   -1,   -1,   -1,   -1,   -1,
      -1,   -1,   -1,   -1,   -1,   -1,   -1, 3401,
    3402,   -1,   -1,   -1,   -1,   -1,   -1, 3403,
      -1,   -1,   -1,   -1,   -1,   -1,   -1,   -1,
      -1,   -1,   -1,   -1,   -1,   -1,   -1,   -1,
      -1,   -1,   -1,   -1,   -1,   -1,   -1,   -1,
      -1,   -1,   -1, 3404,   -1,   -1,   -1,   -1,
    3405,   -1,   -1,   -1,   -1,   -1,   -1,   -1,
      -1,   -1,   -1,   -1,   -1,   -1,   -1,   -1,
      -1, 3406, 3407,   -1,   -1,   -1,   -1,   -1,
      -1,   -1,   -1,   -1,   -1,   -1,   -1,   -1,
    3408,   -1,   -1,   -1,   -1,   -1,   -1,   -1,
      -1,   -1,   -1,   -1,   -1,   -1,   -1,   -1,
      -1,   -1,   -1,   -1,   -1,   -1,   -1,   -1,
      -1,   -1,   -1,   -1,   -1,   -1, 3409,   -1,
      -1,   -1, 3410,   -1,   -1,   -1,   -1,   -1,
    3411,   -1,   -1,   -1,   -1,   -1,   -1,   -1,
      -1,   -1,   -1,   -1,   -1,   -1,   -1,   -1,
      -1,   -1,   -1,   -1,   -1, 3412,   -1,   -1,
      -1,   -1,   -1,   -1,   -1,   -1,   -1,   -1,
      -1,   -1,   -1,   -1,   -1,   -1,   -1,   -1,
      -1,   -1,   -1,   -1,   -1,   -1,   -1,   -1,
      -1,   -1,   -1,   -1,   -1,   -1,   -1,   -1,
      -1, 3413,   -1,   -1,   -1,   -1, 3414,   -1,
      -1,   -1,   -1,   -1,   -1,   -1,   -1,   -1,
      -1,   -1,   -1,   -1,   -1, 3415,   -1,   -1,
      -1,   -1, 3416,   -1,   -1,   -1,   -1,   -1,
      -1,   -1,   -1,   -1,   -1,   -1,   -1,   -1,
      -1,   -1,   -1,   -1,   -1,   -1,   -1,   -1,
      -1,   -1,   -1, 3417,   -1,   -1,   -1,   -1,
      -1,   -1,   -1, 3418,   -1,   -1,   -1,   -1,
      -1,   -1,   -1,   -1,   -1,   -1,   -1,   -1,
      -1,   -1,   -1,   -1,   -1,   -1,   -1,   -1,
      -1, 3419,   -1,   -1,   -1,   -1,   -1,   -1,
    3420,   -1, 3421,   -1,   -1,   -1,   -1, 3422,
      -1,   -1,   -1,   -1,   -1,   -1,   -1,   -1,
      -1,   -1,   -1,   -1,   -1,   -1,   -1,   -1,
      -1,   -1,   -1,   -1,   -1,   -1,   -1,   -1,
      -1,   -1,   -1,   -1,   -1,   -1,   -1,   -1,
      -1,   -1, 3423,   -1,   -1,   -1,   -1,   -1,
      -1,   -1,   -1,   -1,   -1,   -1,   -1,   -1,
      -1,   -1,   -1,   -1,   -1,   -1,   -1,   -1,
      -1,   -1,   -1,   -1,   -1,   -1,   -1, 3424,
      -1,   -1,   -1, 3425,   -1,   -1,   -1,   -1,
      -1,   -1,   -1,   -1,   -1,   -1,   -1,   -1,
      -1,   -1,   -1,   -1,   -1,   -1,   -1,   -1,
      -1,   -1,   -1,   -1,   -1,   -1,   -1,   -1,
      -1,   -1,   -1,   -1,   -1,   -1,   -1,   -1,
      -1,   -1,   -1,   -1,   -1,   -1,   -1,   -1,
      -1,   -1,   -1,   -1,   -1,   -1,   -1,   -1,
      -1,   -1,   -1,   -1,   -1,   -1,   -1, 3426,
      -1,   -1,   -1,   -1,   -1,   -1,   -1,   -1,
      -1,   -1,   -1,   -1,   -1,   -1,   -1,   -1,
      -1,   -1,   -1,   -1,   -1,   -1, 3427,   -1,
    3428,   -1,   -1,   -1,   -1,   -1,   -1,   -1,
      -1,   -1,   -1,   -1, 3429,   -1, 3430,   -1,
      -1,   -1,   -1,   -1,   -1,   -1,   -1,   -1,
      -1,   -1,   -1,   -1, 3431,   -1,   -1,   -1,
      -1,   -1,   -1,   -1,   -1, 3432,   -1,   -1,
      -1,   -1,   -1,   -1,   -1, 3433,   -1,   -1,
      -1,   -1,   -1,   -1,   -1,   -1,   -1,   -1,
    3434,   -1,   -1,   -1,   -1,   -1,   -1,   -1,
      -1,   -1,   -1,   -1,   -1,   -1,   -1,   -1,
      -1,   -1,   -1,   -1,   -1,   -1,   -1,   -1,
      -1,   -1, 3435,   -1,   -1,   -1,   -1,   -1,
      -1,   -1,   -1,   -1,   -1,   -1,   -1,   -1,
      -1,   -1,   -1,   -1,   -1,   -1,   -1,   -1,
      -1,   -1,   -1,   -1, 3436,   -1,   -1,   -1,
      -1,   -1,   -1,   -1,   -1,   -1,   -1,   -1,
      -1,   -1,   -1,   -1,   -1,   -1,   -1,   -1,
      -1,   -1,   -1,   -1,   -1,   -1,   -1,   -1,
      -1,   -1,   -1,   -1,   -1,   -1,   -1,   -1,
      -1,   -1,   -1,   -1,   -1,   -1,   -1,   -1,
      -1,   -1,   -1, 3437,   -1,   -1,   -1,   -1,
      -1, 3438,   -1,   -1,   -1,   -1,   -1,   -1,
      -1,   -1,   -1,   -1,   -1,   -1,   -1,   -1,
      -1,   -1,   -1,   -1,   -1,   -1,   -1,   -1,
      -1,   -1,   -1,   -1,   -1,   -1,   -1,   -1,
      -1,   -1,   -1,   -1,   -1,   -1,   -1,   -1,
      -1,   -1,   -1,   -1,   -1,   -1,   -1,   -1,
      -1,   -1,   -1,   -1,   -1,   -1,   -1, 3439,
      -1,   -1,   -1,   -1,   -1,   -1,   -1,   -1,
      -1,   -1,   -1, 3440,   -1, 3441,   -1,   -1,
      -1,   -1,   -1,   -1,   -1,   -1,   -1,   -1,
      -1,   -1,   -1,   -1,   -1,   -1,   -1,   -1,
      -1,   -1,   -1,   -1, 3442,   -1,   -1,   -1,
      -1,   -1,   -1,   -1, 3443, 3444,   -1,   -1,
      -1,   -1,   -1,   -1,   -1,   -1,   -1,   -1,
      -1, 3445,   -1,   -1,   -1,   -1,   -1,   -1,
      -1,   -1,   -1,   -1,   -1,   -1,   -1,   -1,
      -1,   -1,   -1,   -1,   -1,   -1,   -1,   -1,
      -1,   -1,   -1,   -1,   -1,   -1,   -1,   -1,
      -1,   -1,   -1,   -1,   -1,   -1,   -1,   -1,
      -1,   -1,   -1,   -1,   -1,   -1,   -1,   -1,
      -1,   -1, 3446, 3447,   -1, 3448,   -1,   -1,
    3449,   -1,   -1,   -1,   -1,   -1,   -1,   -1,
      -1,   -1,   -1,   -1,   -1,   -1,   -1,   -1,
      -1,   -1,   -1,   -1,   -1,   -1,   -1,   -1,
    3450,   -1,   -1,   -1,   -1,   -1,   -1,   -1,
      -1,   -1,   -1,   -1,   -1, 3451,   -1,   -1,
      -1,   -1,   -1,   -1,   -1, 3452,   -1,   -1,
      -1,   -1,   -1,   -1,   -1,   -1,   -1,   -1,
      -1,   -1,   -1,   -1,   -1,   -1,   -1,   -1,
      -1,   -1,   -1, 3453,   -1,   -1,   -1,   -1,
      -1,   -1,   -1,   -1,   -1,   -1,   -1,   -1,
      -1, 3454,   -1,   -1,   -1, 3455,   -1,   -1,
      -1,   -1,   -1,   -1,   -1,   -1,   -1,   -1,
      -1,   -1,   -1,   -1,   -1,   -1,   -1, 3456,
      -1, 3457,   -1,   -1,   -1,   -1,   -1,   -1,
      -1,   -1,   -1,   -1,   -1,   -1,   -1,   -1,
      -1,   -1,   -1,   -1,   -1,   -1,   -1,   -1,
      -1,   -1,   -1,   -1,   -1,   -1,   -1,   -1,
      -1,   -1,   -1,   -1,   -1,   -1,   -1,   -1,
      -1,   -1,   -1,   -1,   -1,   -1,   -1,   -1,
      -1,   -1,   -1,   -1,   -1,   -1,   -1,   -1,
      -1,   -1, 3458,   -1, 3459, 3460,   -1,   -1,
      -1,   -1,   -1,   -1,   -1,   -1,   -1,   -1,
      -1,   -1,   -1,   -1,   -1,   -1,   -1,   -1,
      -1,   -1,   -1,   -1,   -1,   -1,   -1,   -1,
      -1,   -1,   -1,   -1,   -1,   -1,   -1,   -1,
      -1, 3461,   -1,   -1,   -1,   -1,   -1,   -1,
      -1,   -1,   -1,   -1,   -1,   -1,   -1,   -1,
      -1,   -1,   -1,   -1,   -1,   -1,   -1,   -1,
      -1,   -1,   -1,   -1,   -1,   -1,   -1,   -1,
    3462,   -1,   -1,   -1,   -1,   -1,   -1,   -1,
      -1, 3463,   -1, 3464,   -1,   -1,   -1,   -1,
      -1,   -1,   -1,   -1,   -1,   -1,   -1,   -1,
      -1,   -1, 3465,   -1,   -1,   -1,   -1,   -1,
      -1, 3466,   -1,   -1,   -1,   -1,   -1,   -1,
      -1,   -1,   -1,   -1,   -1,   -1,   -1,   -1,
      -1,   -1,   -1,   -1,   -1,   -1,   -1,   -1,
      -1,   -1,   -1,   -1,   -1,   -1,   -1,   -1,
      -1,   -1,   -1,   -1,   -1,   -1,   -1,   -1,
      -1,   -1,   -1,   -1,   -1,   -1,   -1,   -1,
      -1,   -1,   -1,   -1,   -1,   -1,   -1,   -1,
      -1,   -1, 3467,   -1,   -1,   -1,   -1,   -1,
      -1,   -1,   -1,   -1,   -1,   -1,   -1,   -1,
      -1,   -1,   -1,   -1,   -1,   -1,   -1,   -1,
      -1,   -1,   -1,   -1,   -1,   -1,   -1,   -1,
      -1,   -1,   -1,   -1,   -1,   -1,   -1,   -1,
      -1,   -1,   -1,   -1,   -1,   -1,   -1,   -1,
    3468,   -1,   -1,   -1,   -1,   -1,   -1,   -1,
      -1,   -1,   -1, 3469,   -1,   -1,   -1,   -1,
      -1, 3470,   -1,   -1,   -1, 3471,   -1,   -1,
      -1,   -1, 3472,   -1,   -1,   -1,   -1, 3473,
      -1,   -1, 3474,   -1, 3475,   -1,   -1,   -1,
      -1, 3476,   -1,   -1, 3477,   -1, 3478,   -1,
      -1,   -1,   -1, 3479,   -1,   -1,   -1,   -1,
    3480,   -1,   -1,   -1,   -1, 3481,   -1,   -1,
      -1,   -1, 3482,   -1,   -1,   -1,   -1, 3483,
      -1,   -1,   -1,   -1,   -1,   -1,   -1,   -1,
      -1,   -1,   -1,   -1,   -1,   -1, 3484,   -1,
      -1,   -1,   -1,   -1,   -1,   -1,   -1, 3485,
    3486,   -1, 3487,   -1,   -1, 3488,   -1,   -1,
      -1,   -1,   -1,   -1,   -1,   -1,   -1,   -1,
      -1,   -1,   -1,   -1,   -1,   -1,   -1,   -1,
      -1,   -1,   -1,   -1,   -1,   -1,   -1, 3489,
      -1,   -1,   -1,   -1,   -1,   -1,   -1,   -1,
      -1,   -1,   -1,   -1,   -1,   -1, 3490,   -1,
      -1,   -1, 3491,   -1,   -1,   -1,   -1,   -1,
    3492,   -1, 3493,   -1,   -1,   -1,   -1,   -1,
      -1,   -1,   -1,   -1,   -1,   -1, 3494,   -1,
      -1,   -1,   -1,   -1,   -1,   -1,   -1,   -1,
      -1,   -1,   -1,   -1,   -1,   -1,   -1, 3495,
    3496,   -1, 3497,   -1,   -1,   -1,   -1,   -1,
      -1,   -1,   -1,   -1,   -1,   -1,   -1,   -1,
    3498,   -1,   -1,   -1,   -1,   -1,   -1,   -1,
    3499,   -1,   -1,   -1,   -1,   -1,   -1,   -1,
    3500,   -1,   -1,   -1,   -1,   -1,   -1,   -1,
      -1,   -1,   -1,   -1,   -1,   -1,   -1,   -1,
      -1,   -1,   -1, 3501,   -1,   -1,   -1,   -1,
      -1,   -1,   -1,   -1,   -1,   -1,   -1,   -1,
      -1,   -1,   -1,   -1,   -1,   -1,   -1,   -1,
    3502,   -1,   -1,   -1,   -1,   -1,   -1,   -1,
      -1,   -1, 3503,   -1,   -1,   -1,   -1,   -1,
      -1,   -1,   -1,   -1,   -1,   -1,   -1,   -1,
      -1,   -1,   -1, 3504, 3505,   -1,   -1,   -1,
      -1,   -1,   -1,   -1,   -1,   -1,   -1,   -1,
      -1,   -1,   -1,   -1,   -1,   -1,   -1,   -1,
      -1,   -1,   -1,   -1, 3506,   -1,   -1,   -1,
    3507,   -1,   -1,   -1, 3508,   -1,   -1,   -1,
      -1,   -1,   -1,   -1,   -1, 3509,   -1,   -1,
      -1,   -1,   -1,   -1,   -1,   -1,   -1,   -1,
      -1,   -1,   -1,   -1, 3510,   -1,   -1,   -1,
      -1,   -1,   -1,   -1,   -1,   -1,   -1,   -1,
      -1, 3511,   -1,   -1,   -1,   -1,   -1,   -1,
    3512,   -1,   -1,   -1,   -1,   -1,   -1,   -1,
      -1,   -1,   -1,   -1,   -1,   -1,   -1,   -1,
      -1,   -1,   -1,   -1,   -1,   -1,   -1,   -1,
      -1,   -1,   -1,   -1,   -1,   -1,   -1,   -1,
    3513,   -1,   -1,   -1, 3514,   -1,   -1,   -1,
      -1,   -1,   -1,   -1,   -1, 3515,   -1,   -1,
    3516,   -1,   -1,   -1,   -1,   -1,   -1,   -1,
      -1,   -1,   -1,   -1,   -1,   -1,   -1,   -1,
    3517,   -1,   -1,   -1,   -1,   -1,   -1, 3518,
    3519,   -1,   -1,   -1,   -1,   -1,   -1, 3520,
      -1,   -1, 3521, 3522,   -1,   -1, 3523,   -1,
      -1,   -1,   -1,   -1,   -1,   -1,   -1,   -1,
      -1,   -1,   -1,   -1, 3524,   -1,   -1,   -1,
      -1,   -1,   -1,   -1,   -1,   -1,   -1,   -1,
      -1,   -1,   -1,   -1,   -1,   -1,   -1,   -1,
      -1,   -1, 3525,   -1, 3526,   -1,   -1,   -1,
      -1,   -1,   -1, 3527,   -1,   -1,   -1,   -1,
      -1,   -1,   -1,   -1,   -1,   -1,   -1,   -1,
      -1,   -1,   -1,   -1, 3528,   -1,   -1,   -1,
      -1,   -1,   -1,   -1,   -1,   -1,   -1,   -1,
      -1,   -1,   -1,   -1,   -1,   -1,   -1,   -1,
      -1,   -1,   -1,   -1,   -1,   -1,   -1,   -1,
      -1,   -1,   -1,   -1,   -1,   -1,   -1,   -1,
      -1,   -1,   -1,   -1,   -1,   -1,   -1,   -1,
      -1,   -1,   -1,   -1,   -1,   -1,   -1,   -1,
      -1,   -1,   -1,   -1,   -1,   -1, 3529,   -1,
      -1,   -1,   -1,   -1,   -1,   -1,   -1,   -1,
      -1,   -1,   -1,   -1,   -1,   -1,   -1,   -1,
      -1,   -1,   -1, 3530,   -1,   -1,   -1,   -1,
      -1,   -1,   -1,   -1,   -1, 3531,   -1,   -1,
      -1,   -1,   -1,   -1,   -1,   -1,   -1,   -1,
      -1,   -1,   -1,   -1,   -1,   -1,   -1,   -1,
      -1,   -1,   -1,   -1,   -1,   -1,   -1,   -1,
      -1,   -1,   -1,   -1,   -1,   -1,   -1, 3532,
      -1,   -1,   -1,   -1,   -1,   -1,   -1,   -1,
      -1,   -1,   -1,   -1,   -1,   -1,   -1,   -1,
      -1,   -1,   -1,   -1,   -1,   -1, 3533,   -1,
      -1,   -1,   -1,   -1,   -1,   -1, 3534,   -1,
      -1,   -1,   -1,   -1,   -1,   -1,   -1,   -1,
      -1,   -1,   -1,   -1,   -1,   -1,   -1,   -1,
      -1,   -1,   -1,   -1,   -1,   -1, 3535, 3536,
      -1,   -1,   -1,   -1,   -1,   -1,   -1, 3537,
      -1,   -1, 3538, 3539,   -1,   -1,   -1,   -1,
      -1,   -1,   -1,   -1,   -1,   -1,   -1,   -1,
      -1,   -1,   -1,   -1,   -1,   -1,   -1,   -1,
    3540,   -1,   -1,   -1, 3541,   -1,   -1,   -1,
      -1, 3542,   -1,   -1, 3543,   -1,   -1,   -1,
      -1,   -1,   -1,   -1,   -1,   -1,   -1,   -1,
      -1,   -1,   -1,   -1,   -1,   -1,   -1,   -1,
      -1,   -1,   -1,   -1,   -1,   -1,   -1,   -1,
      -1, 3544,   -1,   -1,   -1,   -1,   -1,   -1,
      -1,   -1,   -1,   -1, 3545,   -1,   -1,   -1,
      -1,   -1,   -1,   -1,   -1,   -1, 3546,   -1,
      -1,   -1,   -1, 3547,   -1,   -1,   -1,   -1,
      -1,   -1,   -1,   -1,   -1,   -1,   -1,   -1,
      -1,   -1,   -1,   -1,   -1,   -1,   -1,   -1,
      -1,   -1,   -1,   -1,   -1,   -1,   -1,   -1,
      -1,   -1,   -1,   -1,   -1,   -1,   -1,   -1,
      -1,   -1,   -1,   -1,   -1,   -1,   -1,   -1,
      -1,   -1,   -1,   -1,   -1,   -1,   -1,   -1,
      -1,   -1,   -1,   -1,   -1,   -1,   -1,   -1,
      -1,   -1,   -1,   -1, 3548,   -1,   -1,   -1,
      -1,   -1,   -1,   -1,   -1,   -1,   -1,   -1,
      -1,   -1,   -1,   -1,   -1,   -1,   -1,   -1,
      -1,   -1,   -1,   -1,   -1,   -1,   -1,   -1,
      -1,   -1,   -1,   -1,   -1,   -1,   -1,   -1,
      -1,   -1,   -1,   -1,   -1,   -1,   -1,   -1,
      -1,   -1,   -1,   -1,   -1, 3549,   -1,   -1,
    3550,   -1,   -1,   -1,   -1,   -1,   -1,   -1,
      -1,   -1,   -1, 3551,   -1,   -1,   -1,   -1,
      -1, 3552, 3553,   -1,   -1,   -1,   -1,   -1,
      -1,   -1,   -1,   -1,   -1,   -1,   -1,   -1,
      -1, 3554,   -1,   -1,   -1,   -1,   -1,   -1,
    3555,   -1,   -1,   -1,   -1, 3556,   -1,   -1,
      -1,   -1,   -1,   -1,   -1,   -1,   -1,   -1,
      -1,   -1,   -1,   -1,   -1,   -1,   -1, 3557,
      -1,   -1,   -1,   -1,   -1, 3558,   -1,   -1,
      -1,   -1,   -1,   -1,   -1,   -1,   -1,   -1,
      -1,   -1,   -1, 3559,   -1,   -1,   -1,   -1,
      -1,   -1,   -1,   -1,   -1, 3560,   -1,   -1,
      -1,   -1, 3561,   -1,   -1,   -1,   -1, 3562,
      -1,   -1,   -1,   -1,   -1,   -1,   -1,   -1,
      -1,   -1,   -1,   -1,   -1,   -1,   -1,   -1,
      -1,   -1,   -1,   -1,   -1,   -1,   -1,   -1,
      -1,   -1,   -1,   -1,   -1,   -1,   -1, 3563,
      -1,   -1, 3564,   -1,   -1,   -1,   -1,   -1,
      -1,   -1,   -1, 3565,   -1,   -1,   -1,   -1,
      -1,   -1,   -1,   -1,   -1,   -1,   -1,   -1,
      -1,   -1,   -1,   -1,   -1, 3566,   -1,   -1,
      -1,   -1,   -1,   -1,   -1,   -1,   -1,   -1,
    3567,   -1,   -1,   -1,   -1,   -1,   -1,   -1,
      -1, 3568,   -1,   -1,   -1,   -1,   -1,   -1,
      -1,   -1,   -1,   -1,   -1,   -1, 3569,   -1,
      -1,   -1,   -1,   -1,   -1,   -1,   -1,   -1,
      -1,   -1,   -1,   -1, 3570,   -1,   -1,   -1,
    3571,   -1,   -1,   -1,   -1,   -1,   -1,   -1,
      -1,   -1,   -1,   -1,   -1,   -1,   -1,   -1,
      -1,   -1,   -1,   -1,   -1,   -1,   -1,   -1,
      -1,   -1,   -1,   -1,   -1,   -1,   -1,   -1,
      -1,   -1,   -1,   -1,   -1,   -1,   -1, 3572,
      -1,   -1,   -1,   -1,   -1,   -1,   -1,   -1,
      -1,   -1,   -1,   -1,   -1,   -1,   -1,   -1,
      -1,   -1,   -1,   -1,   -1,   -1,   -1,   -1,
      -1,   -1,   -1,   -1,   -1,   -1,   -1,   -1,
      -1,   -1,   -1,   -1,   -1,   -1,   -1, 3573,
      -1, 3574,   -1,   -1, 3575,   -1,   -1, 3576,
      -1,   -1,   -1,   -1,   -1,   -1, 3577,   -1,
      -1,   -1,   -1,   -1,   -1,   -1,   -1,   -1,
      -1,   -1,   -1,   -1,   -1,   -1, 3578,   -1,
      -1,   -1,   -1,   -1,   -1,   -1,   -1,   -1,
      -1,   -1,   -1,   -1,   -1,   -1,   -1,   -1,
      -1, 3579,   -1,   -1,   -1,   -1,   -1,   -1,
      -1,   -1,   -1,   -1,   -1,   -1,   -1,   -1,
      -1,   -1,   -1,   -1,   -1,   -1, 3580,   -1,
      -1,   -1,   -1, 3581,   -1,   -1,   -1,   -1,
      -1,   -1,   -1,   -1,   -1,   -1, 3582,   -1,
      -1,   -1,   -1,   -1,   -1,   -1,   -1,   -1,
      -1,   -1,   -1,   -1,   -1,   -1,   -1,   -1,
      -1,   -1,   -1,   -1,   -1,   -1,   -1,   -1,
      -1,   -1,   -1, 3583,   -1,   -1,   -1,   -1,
      -1,   -1,   -1,   -1,   -1,   -1,   -1, 3584,
      -1,   -1,   -1,   -1,   -1,   -1,   -1,   -1,
      -1,   -1,   -1,   -1,   -1,   -1,   -1,   -1,
      -1,   -1,   -1,   -1,   -1,   -1,   -1,   -1,
      -1,   -1,   -1,   -1, 3585,   -1,   -1,   -1,
      -1,   -1,   -1,   -1,   -1,   -1,   -1,   -1,
      -1, 3586,   -1,   -1,   -1,   -1,   -1,   -1,
      -1,   -1, 3587,   -1,   -1,   -1,   -1,   -1,
      -1,   -1,   -1,   -1,   -1,   -1,   -1,   -1,
      -1,   -1,   -1,   -1,   -1, 3588,   -1,   -1,
      -1,   -1,   -1,   -1, 3589,   -1,   -1,   -1,
      -1,   -1,   -1,   -1, 3590,   -1,   -1,   -1,
      -1,   -1,   -1,   -1,   -1,   -1,   -1,   -1,
      -1,   -1,   -1,   -1,   -1,   -1,   -1,   -1,
      -1,   -1,   -1,   -1,   -1,   -1,   -1,   -1,
      -1,   -1,   -1,   -1,   -1,   -1,   -1,   -1,
      -1, 3591,   -1, 3592,   -1,   -1,   -1,   -1,
      -1,   -1,   -1,   -1,   -1,   -1,   -1,   -1,
      -1,   -1,   -1,   -1,   -1,   -1,   -1,   -1,
      -1,   -1,   -1, 3593,   -1,   -1,   -1,   -1,
      -1,   -1,   -1,   -1,   -1,   -1,   -1,   -1,
      -1,   -1,   -1, 3594, 3595,   -1,   -1,   -1,
      -1,   -1,   -1, 3596,   -1,   -1,   -1,   -1,
      -1,   -1,   -1,   -1,   -1,   -1,   -1,   -1,
      -1,   -1, 3597,   -1,   -1,   -1,   -1,   -1,
      -1,   -1,   -1,   -1,   -1,   -1,   -1,   -1,
      -1,   -1,   -1,   -1,   -1,   -1,   -1,   -1,
      -1, 3598,   -1,   -1,   -1,   -1,   -1,   -1,
      -1,   -1,   -1,   -1,   -1,   -1,   -1,   -1,
      -1,   -1,   -1,   -1,   -1,   -1,   -1,   -1,
      -1,   -1,   -1,   -1,   -1,   -1,   -1,   -1,
      -1,   -1,   -1,   -1,   -1,   -1,   -1, 3599,
      -1, 3600,   -1,   -1,   -1,   -1,   -1,   -1,
      -1,   -1,   -1,   -1,   -1,   -1,   -1,   -1,
      -1,   -1,   -1,   -1,   -1,   -1,   -1,   -1,
      -1,   -1,   -1,   -1,   -1,   -1,   -1,   -1,
      -1,   -1,   -1,   -1,   -1,   -1, 3601,   -1,
      -1,   -1,   -1,   -1, 3602,   -1, 3603,   -1,
      -1,   -1,   -1,   -1,   -1, 3604,   -1,   -1,
      -1,   -1,   -1,   -1,   -1,   -1,   -1, 3605,
      -1,   -1,   -1,   -1,   -1,   -1,   -1,   -1,
      -1,   -1,   -1,   -1,   -1,   -1,   -1,   -1,
      -1,   -1,   -1,   -1,   -1,   -1,   -1,   -1,
    3606,   -1,   -1,   -1,   -1, 3607,   -1,   -1,
      -1, 3608,   -1,   -1,   -1,   -1,   -1,   -1,
      -1,   -1,   -1,   -1,   -1,   -1,   -1,   -1,
      -1,   -1,   -1,   -1,   -1,   -1,   -1,   -1,
      -1,   -1,   -1,   -1,   -1,   -1,   -1,   -1,
      -1,   -1,   -1,   -1,   -1, 3609, 3610,   -1,
      -1,   -1,   -1,   -1,   -1,   -1,   -1,   -1,
      -1,   -1,   -1,   -1,   -1,   -1,   -1,   -1,
      -1,   -1,   -1,   -1,   -1,   -1,   -1,   -1,
      -1,   -1,   -1,   -1,   -1,   -1,   -1,   -1,
      -1,   -1,   -1,   -1, 3611,   -1,   -1,   -1,
      -1,   -1,   -1,   -1,   -1,   -1,   -1,   -1,
      -1,   -1,   -1,   -1, 3612,   -1,   -1,   -1,
      -1,   -1,   -1,   -1,   -1,   -1,   -1,   -1,
    3613,   -1,   -1,   -1,   -1,   -1,   -1,   -1,
      -1,   -1,   -1,   -1,   -1,   -1,   -1,   -1,
      -1,   -1,   -1,   -1,   -1,   -1,   -1, 3614,
      -1,   -1,   -1,   -1,   -1,   -1,   -1,   -1,
      -1,   -1,   -1,   -1,   -1, 3615,   -1, 3616,
      -1,   -1,   -1,   -1,   -1,   -1,   -1,   -1,
      -1, 3617,   -1,   -1,   -1,   -1,   -1,   -1,
      -1,   -1, 3618,   -1,   -1,   -1,   -1,   -1,
      -1,   -1,   -1,   -1,   -1,   -1,   -1,   -1,
      -1,   -1,   -1,   -1,   -1,   -1,   -1,   -1,
    3619,   -1,   -1,   -1,   -1,   -1,   -1,   -1,
      -1,   -1,   -1,   -1,   -1,   -1,   -1,   -1,
      -1,   -1,   -1,   -1,   -1,   -1,   -1,   -1,
      -1,   -1,   -1,   -1,   -1,   -1,   -1,   -1,
      -1,   -1,   -1,   -1,   -1,   -1,   -1,   -1,
      -1,   -1,   -1,   -1,   -1,   -1,   -1,   -1,
      -1,   -1,   -1,   -1,   -1,   -1,   -1,   -1,
      -1,   -1,   -1,   -1,   -1,   -1,   -1,   -1,
      -1,   -1,   -1,   -1,   -1,   -1,   -1,   -1,
      -1,   -1,   -1,   -1,   -1,   -1,   -1,   -1,
      -1,   -1,   -1, 3620,   -1, 3621,   -1,   -1,
      -1,   -1,   -1,   -1,   -1,   -1,   -1,   -1,
      -1,   -1,   -1,   -1,   -1,   -1,   -1,   -1,
      -1,   -1,   -1,   -1,   -1,   -1,   -1,   -1,
      -1,   -1,   -1,   -1,   -1,   -1,   -1,   -1,
      -1,   -1,   -1,   -1,   -1,   -1,   -1,   -1,
      -1,   -1,   -1,   -1,   -1,   -1,   -1,   -1,
      -1,   -1,   -1,   -1,   -1,   -1,   -1,   -1,
      -1,   -1,   -1,   -1, 3622, 3623,   -1,   -1,
      -1,   -1,   -1,   -1,   -1,   -1,   -1,   -1,
      -1,   -1,   -1,   -1, 3624,   -1,   -1,   -1,
      -1,   -1,   -1,   -1,   -1,   -1,   -1,   -1,
      -1,   -1,   -1,   -1,   -1,   -1,   -1,   -1,
      -1,   -1,   -1,   -1,   -1,   -1,   -1,   -1,
      -1,   -1,   -1,   -1,   -1,   -1,   -1,   -1,
      -1,   -1,   -1,   -1,   -1,   -1,   -1,   -1,
      -1,   -1,   -1,   -1,   -1,   -1,   -1,   -1,
      -1,   -1, 3625,   -1,   -1,   -1,   -1,   -1,
      -1,   -1,   -1,   -1,   -1,   -1,   -1,   -1,
      -1,   -1,   -1,   -1, 3626,   -1,   -1,   -1,
      -1,   -1,   -1, 3627,   -1,   -1,   -1,   -1,
      -1,   -1,   -1,   -1,   -1,   -1,   -1, 3628,
      -1,   -1,   -1,   -1,   -1, 3629, 3630, 3631,
      -1,   -1,   -1,   -1,   -1,   -1,   -1,   -1,
      -1,   -1,   -1,   -1,   -1,   -1,   -1,   -1,
      -1,   -1, 3632,   -1,   -1,   -1,   -1,   -1,
      -1,   -1,   -1,   -1,   -1,   -1, 3633,   -1,
      -1,   -1,   -1,   -1,   -1,   -1,   -1,   -1,
      -1,   -1,   -1,   -1,   -1,   -1,   -1,   -1,
      -1,   -1,   -1,   -1,   -1,   -1,   -1,   -1,
      -1,   -1,   -1,   -1,   -1, 3634,   -1,   -1,
      -1,   -1,   -1,   -1, 3635,   -1,   -1,   -1,
      -1,   -1, 3636,   -1,   -1,   -1,   -1,   -1,
      -1,   -1,   -1,   -1,   -1,   -1,   -1,   -1,
      -1,   -1,   -1,   -1,   -1,   -1,   -1,   -1,
      -1,   -1,   -1,   -1,   -1,   -1,   -1,   -1,
      -1, 3637,   -1,   -1,   -1,   -1,   -1,   -1,
    3638,   -1,   -1,   -1,   -1, 3639,   -1,   -1,
      -1,   -1,   -1,   -1, 3640,   -1,   -1,   -1,
      -1,   -1,   -1,   -1,   -1,   -1,   -1,   -1,
      -1,   -1,   -1,   -1,   -1,   -1,   -1,   -1,
      -1,   -1,   -1,   -1,   -1,   -1,   -1,   -1,
      -1,   -1,   -1,   -1,   -1,   -1,   -1, 3641,
      -1,   -1,   -1,   -1,   -1,   -1,   -1,   -1,
      -1, 3642,   -1,   -1,   -1,   -1,   -1,   -1,
      -1,   -1,   -1,   -1,   -1,   -1, 3643, 3644,
      -1,   -1,   -1,   -1,   -1,   -1, 3645,   -1,
      -1,   -1,   -1,   -1,   -1,   -1,   -1,   -1,
    3646,   -1,   -1,   -1,   -1,   -1,   -1,   -1,
      -1,   -1,   -1,   -1,   -1,   -1,   -1,   -1,
      -1, 3647,   -1,   -1,   -1,   -1,   -1,   -1,
      -1,   -1,   -1, 3648,   -1,   -1,   -1,   -1,
      -1,   -1, 3649,   -1,   -1, 3650,   -1,   -1,
      -1,   -1,   -1,   -1,   -1,   -1,   -1,   -1,
      -1,   -1,   -1,   -1,   -1,   -1,   -1,   -1,
    3651,   -1,   -1,   -1,   -1, 3652,   -1,   -1,
      -1,   -1,   -1,   -1,   -1,   -1,   -1,   -1,
      -1,   -1,   -1,   -1,   -1,   -1,   -1, 3653,
      -1, 3654,   -1,   -1,   -1,   -1,   -1,   -1,
      -1,   -1,   -1,   -1,   -1,   -1,   -1,   -1,
      -1,   -1,   -1,   -1,   -1,   -1,   -1,   -1,
      -1,   -1,   -1,   -1, 3655,   -1,   -1,   -1,
      -1,   -1,   -1,   -1,   -1,   -1,   -1,   -1,
      -1,   -1,   -1,   -1, 3656,   -1,   -1,   -1,
      -1,   -1,   -1,   -1,   -1,   -1,   -1,   -1,
      -1,   -1,   -1,   -1,   -1,   -1,   -1,   -1,
      -1,   -1,   -1,   -1,   -1,   -1,   -1,   -1,
      -1,   -1,   -1,   -1,   -1,   -1,   -1,   -1,
      -1,   -1,   -1,   -1,   -1,   -1,   -1,   -1,
      -1,   -1,   -1,   -1,   -1,   -1,   -1,   -1,
      -1,   -1,   -1,   -1,   -1,   -1,   -1,   -1,
      -1,   -1,   -1,   -1,   -1,   -1,   -1,   -1,
      -1,   -1,   -1,   -1,   -1,   -1,   -1,   -1,
      -1,   -1,   -1,   -1,   -1,   -1, 3657,   -1,
    3658,   -1,   -1,   -1,   -1,   -1,   -1, 3659,
      -1,   -1,   -1,   -1,   -1,   -1,   -1,   -1,
      -1,   -1, 3660,   -1,   -1,   -1,   -1,   -1,
      -1,   -1,   -1,   -1,   -1,   -1,   -1,   -1,
      -1,   -1,   -1,   -1,   -1,   -1,   -1,   -1,
      -1,   -1,   -1, 3661,   -1,   -1,   -1,   -1,
      -1,   -1,   -1,   -1, 3662,   -1,   -1,   -1,
      -1,   -1,   -1,   -1,   -1,   -1,   -1,   -1,
      -1,   -1,   -1,   -1,   -1,   -1,   -1,   -1,
      -1,   -1,   -1,   -1,   -1,   -1,   -1, 3663,
      -1,   -1,   -1,   -1,   -1,   -1,   -1,   -1,
      -1,   -1,   -1,   -1,   -1,   -1,   -1,   -1,
      -1,   -1,   -1,   -1,   -1,   -1,   -1,   -1,
      -1,   -1,   -1,   -1, 3664,   -1,   -1,   -1,
      -1,   -1,   -1,   -1,   -1,   -1,   -1,   -1,
      -1,   -1, 3665, 3666,   -1,   -1,   -1,   -1,
      -1,   -1,   -1, 3667,   -1,   -1,   -1,   -1,
      -1, 3668,   -1,   -1,   -1,   -1,   -1,   -1,
      -1,   -1,   -1,   -1,   -1,   -1,   -1,   -1,
      -1,   -1,   -1,   -1,   -1,   -1,   -1,   -1,
      -1,   -1, 3669,   -1, 3670,   -1,   -1,   -1,
    3671,   -1,   -1, 3672,   -1,   -1,   -1,   -1,
      -1,   -1,   -1,   -1,   -1,   -1,   -1,   -1,
      -1,   -1,   -1,   -1,   -1,   -1,   -1,   -1,
      -1,   -1,   -1,   -1,   -1,   -1,   -1,   -1,
      -1,   -1,   -1,   -1,   -1,   -1,   -1,   -1,
      -1,   -1,   -1,   -1,   -1,   -1,   -1,   -1,
      -1,   -1,   -1,   -1,   -1,   -1,   -1,   -1,
      -1,   -1,   -1,   -1,   -1, 3673,   -1,   -1,
      -1,   -1,   -1,   -1,   -1,   -1,   -1,   -1,
      -1,   -1,   -1,   -1,   -1, 3674, 3675,   -1,
      -1,   -1, 3676,   -1,   -1,   -1,   -1,   -1,
    3677,   -1,   -1,   -1, 3678,   -1,   -1,   -1,
      -1, 3679,   -1,   -1,   -1,   -1,   -1,   -1,
      -1,   -1,   -1,   -1,   -1,   -1,   -1,   -1,
      -1,   -1,   -1,   -1,   -1,   -1,   -1,   -1,
      -1,   -1,   -1,   -1,   -1,   -1,   -1,   -1,
      -1,   -1,   -1, 3680,   -1,   -1,   -1,   -1,
      -1,   -1,   -1,   -1,   -1,   -1,   -1,   -1,
      -1,   -1,   -1,   -1,   -1, 3681,   -1,   -1,
      -1,   -1,   -1,   -1,   -1,   -1,   -1, 3682,
      -1,   -1,   -1,   -1,   -1,   -1, 3683,   -1,
      -1,   -1,   -1,   -1,   -1,   -1, 3684, 3685,
      -1,   -1,   -1,   -1,   -1,   -1,   -1,   -1,
      -1,   -1,   -1,   -1,   -1,   -1,   -1,   -1,
      -1,   -1,   -1,   -1,   -1,   -1,   -1,   -1,
      -1,   -1,   -1,   -1,   -1,   -1,   -1,   -1,
    3686,   -1,   -1,   -1,   -1,   -1,   -1,   -1,
      -1,   -1, 3687,   -1, 3688,   -1,   -1,   -1,
      -1,   -1,   -1,   -1,   -1,   -1, 3689,   -1,
      -1,   -1,   -1,   -1, 3690,   -1,   -1,   -1,
      -1,   -1,   -1,   -1,   -1,   -1,   -1,   -1,
      -1,   -1,   -1,   -1, 3691,   -1,   -1,   -1,
      -1,   -1,   -1,   -1,   -1,   -1,   -1,   -1,
      -1, 3692,   -1,   -1,   -1,   -1,   -1,   -1,
      -1,   -1,   -1,   -1,   -1,   -1,   -1,   -1,
      -1,   -1,   -1,   -1,   -1,   -1,   -1,   -1,
      -1,   -1,   -1, 3693,   -1,   -1,   -1,   -1,
      -1,   -1,   -1,   -1,   -1,   -1,   -1,   -1,
      -1,   -1,   -1,   -1,   -1,   -1,   -1,   -1,
      -1,   -1,   -1,   -1,   -1,   -1,   -1,   -1,
      -1, 3694,   -1,   -1,   -1,   -1,   -1,   -1,
      -1,   -1,   -1,   -1,   -1,   -1,   -1,   -1,
      -1,   -1,   -1,   -1,   -1,   -1,   -1,   -1,
      -1,   -1,   -1,   -1,   -1,   -1,   -1,   -1,
      -1,   -1,   -1,   -1,   -1,   -1,   -1,   -1,
      -1,   -1,   -1,   -1,   -1,   -1,   -1,   -1,
      -1, 3695,   -1,   -1,   -1, 3696,   -1,   -1,
      -1,   -1,   -1,   -1,   -1,   -1,   -1,   -1,
      -1,   -1,   -1,   -1,   -1,   -1,   -1,   -1,
      -1,   -1, 3697,   -1,   -1, 3698,   -1,   -1,
      -1,   -1,   -1,   -1,   -1,   -1,   -1,   -1,
      -1,   -1,   -1,   -1,   -1,   -1,   -1,   -1,
      -1,   -1, 3699,   -1,   -1,   -1,   -1, 3700,
    3701,   -1,   -1,   -1, 3702,   -1,   -1,   -1,
      -1,   -1,   -1,   -1,   -1,   -1,   -1,   -1,
      -1,   -1, 3703,   -1,   -1,   -1,   -1, 3704,
      -1,   -1,   -1,   -1,   -1,   -1,   -1,   -1,
    3705, 3706,   -1,   -1,   -1,   -1,   -1,   -1,
      -1,   -1,   -1,   -1,   -1, 3707,   -1, 3708,
      -1,   -1,   -1,   -1, 3709,   -1,   -1,   -1,
      -1,   -1,   -1,   -1,   -1,   -1, 3710,   -1,
    3711,   -1,   -1,   -1,   -1,   -1,   -1,   -1,
      -1,   -1,   -1, 3712,   -1,   -1, 3713,   -1,
      -1,   -1,   -1,   -1,   -1,   -1,   -1,   -1,
      -1,   -1,   -1,   -1, 3714,   -1,   -1,   -1,
      -1, 3715,   -1,   -1,   -1,   -1,   -1,   -1,
      -1, 3716,   -1,   -1,   -1,   -1,   -1,   -1,
      -1,   -1,   -1,   -1,   -1,   -1,   -1,   -1,
      -1,   -1,   -1,   -1,   -1,   -1,   -1,   -1,
      -1,   -1, 3717,   -1,   -1,   -1, 3718,   -1,
      -1,   -1,   -1,   -1,   -1,   -1,   -1,   -1,
      -1,   -1, 3719,   -1,   -1,   -1,   -1,   -1,
      -1,   -1,   -1,   -1, 3720,   -1,   -1,   -1,
      -1,   -1,   -1,   -1,   -1,   -1,   -1,   -1,
      -1,   -1,   -1,   -1,   -1,   -1,   -1,   -1,
      -1,   -1,   -1,   -1,   -1,   -1,   -1,   -1,
      -1, 3721,   -1,   -1, 3722,   -1,   -1,   -1,
      -1,   -1,   -1,   -1,   -1,   -1,   -1,   -1,
      -1, 3723,   -1,   -1,   -1,   -1,   -1,   -1,
      -1,   -1,   -1,   -1,   -1,   -1,   -1,   -1,
      -1,   -1,   -1,   -1,   -1,   -1,   -1, 3724,
      -1, 3725, 3726,   -1,   -1,   -1, 3727,   -1,
      -1,   -1,   -1,   -1,   -1,   -1,   -1,   -1,
      -1,   -1,   -1,   -1,   -1,   -1,   -1,   -1,
      -1,   -1,   -1,   -1,   -1,   -1,   -1,   -1,
      -1,   -1,   -1,   -1,   -1,   -1,   -1,   -1,
      -1,   -1,   -1,   -1,   -1,   -1,   -1,   -1,
      -1,   -1,   -1, 3728,   -1,   -1,   -1,   -1,
      -1,   -1,   -1,   -1, 3729,   -1,   -1,   -1,
      -1,   -1,   -1,   -1,   -1,   -1,   -1,   -1,
      -1,   -1,   -1,   -1,   -1,   -1,   -1,   -1,
      -1,   -1,   -1, 3730,   -1,   -1,   -1,   -1,
      -1,   -1,   -1,   -1,   -1,   -1,   -1,   -1,
      -1,   -1,   -1,   -1,   -1,   -1,   -1,   -1,
      -1,   -1,   -1,   -1,   -1,   -1, 3731,   -1,
      -1,   -1,   -1,   -1,   -1,   -1,   -1,   -1,
      -1,   -1,   -1,   -1,   -1, 3732,   -1,   -1,
      -1,   -1,   -1,   -1,   -1,   -1,   -1,   -1,
      -1,   -1,   -1,   -1,   -1,   -1,   -1,   -1,
      -1,   -1,   -1,   -1,   -1,   -1,   -1,   -1,
      -1,   -1, 3733,   -1,   -1,   -1,   -1,   -1,
      -1,   -1,   -1,   -1,   -1, 3734,   -1,   -1,
      -1,   -1, 3735,   -1,   -1,   -1,   -1,   -1,
      -1,   -1,   -1,   -1,   -1,   -1,   -1,   -1,
      -1,   -1,   -1,   -1,   -1,   -1,   -1,   -1,
      -1,   -1,   -1, 3736,   -1,   -1,   -1,   -1,
      -1,   -1,   -1,   -1,   -1,   -1,   -1,   -1,
      -1,   -1,   -1,   -1,   -1,   -1,   -1,   -1,
      -1,   -1,   -1,   -1,   -1,   -1,   -1,   -1,
      -1,   -1,   -1,   -1,   -1,   -1,   -1,   -1,
      -1,   -1,   -1,   -1,   -1,   -1,   -1,   -1,
      -1, 3737,   -1,   -1,   -1, 3738,   -1,   -1,
      -1,   -1,   -1,   -1, 3739, 3740,   -1,   -1,
      -1,   -1,   -1,   -1,   -1,   -1,   -1,   -1,
      -1,   -1,   -1,   -1,   -1,   -1,   -1,   -1,
      -1,   -1,   -1,   -1,   -1,   -1,   -1,   -1,
      -1,   -1,   -1,   -1,   -1,   -1,   -1,   -1,
      -1,   -1, 3741,   -1, 3742,   -1,   -1,   -1,
      -1,   -1,   -1,   -1,   -1,   -1,   -1,   -1,
      -1,   -1,   -1,   -1,   -1,   -1,   -1,   -1,
      -1,   -1,   -1,   -1,   -1,   -1,   -1,   -1,
      -1,   -1, 3743,   -1,   -1,   -1,   -1,   -1,
      -1,   -1,   -1,   -1,   -1,   -1,   -1,   -1,
      -1,   -1,   -1,   -1,   -1,   -1,   -1,   -1,
      -1,   -1,   -1,   -1,   -1,   -1,   -1,   -1,
      -1,   -1,   -1,   -1,   -1,   -1,   -1,   -1,
      -1,   -1,   -1,   -1,   -1,   -1,   -1,   -1,
      -1,   -1,   -1,   -1,   -1,   -1, 3744,   -1,
      -1,   -1,   -1,   -1,   -1,   -1,   -1,   -1,
      -1,   -1,   -1,   -1,   -1,   -1,   -1, 3745,
      -1,   -1,   -1,   -1,   -1, 3746,   -1,   -1,
      -1,   -1,   -1,   -1,   -1,   -1,   -1,   -1,
      -1,   -1,   -1,   -1,   -1,   -1,   -1,   -1,
      -1,   -1,   -1,   -1,   -1,   -1,   -1,   -1,
      -1,   -1,   -1,   -1,   -1,   -1,   -1,   -1,
      -1,   -1,   -1,   -1,   -1,   -1,   -1,   -1,
    3747,   -1,   -1,   -1,   -1,   -1,   -1,   -1,
    3748, 3749,   -1,   -1,   -1,   -1,   -1,   -1,
      -1,   -1,   -1,   -1,   -1,   -1,   -1,   -1,
      -1,   -1,   -1,   -1,   -1,   -1,   -1,   -1,
      -1, 3750,   -1,   -1,   -1, 3751,   -1,   -1,
      -1,   -1,   -1,   -1,   -1,   -1,   -1,   -1,
      -1,   -1,   -1,   -1,   -1,   -1,   -1,   -1,
      -1,   -1,   -1,   -1,   -1,   -1,   -1,   -1,
      -1,   -1,   -1,   -1,   -1, 3752,   -1,   -1,
      -1,   -1,   -1,   -1,   -1,   -1,   -1,   -1,
      -1,   -1,   -1,   -1,   -1,   -1,   -1,   -1,
      -1,   -1,   -1,   -1,   -1,   -1,   -1,   -1,
      -1,   -1,   -1,   -1,   -1, 3753,   -1,   -1,
      -1,   -1,   -1,   -1,   -1,   -1,   -1,   -1,
      -1,   -1,   -1, 3754,   -1,   -1,   -1,   -1,
      -1,   -1,   -1,   -1,   -1,   -1,   -1,   -1,
      -1,   -1,   -1,   -1,   -1,   -1,   -1,   -1,
      -1, 3755,   -1,   -1,   -1,   -1,   -1,   -1,
      -1,   -1,   -1,   -1,   -1,   -1,   -1,   -1,
      -1,   -1,   -1,   -1,   -1,   -1,   -1, 3756,
      -1,   -1,   -1,   -1,   -1,   -1,   -1,   -1,
      -1,   -1,   -1, 3757,   -1,   -1,   -1, 3758,
      -1,   -1,   -1,   -1,   -1,   -1,   -1,   -1,
      -1,   -1,   -1,   -1,   -1,   -1,   -1,   -1,
      -1,   -1,   -1,   -1,   -1,   -1,   -1,   -1,
      -1,   -1,   -1,   -1,   -1,   -1,   -1,   -1,
      -1,   -1, 3759,   -1,   -1,   -1,   -1,   -1,
      -1,   -1,   -1,   -1,   -1,   -1,   -1,   -1,
      -1,   -1,   -1, 3760,   -1,   -1, 3761,   -1,
      -1,   -1,   -1,   -1,   -1,   -1,   -1,   -1,
      -1,   -1,   -1,   -1,   -1,   -1,   -1,   -1,
      -1,   -1,   -1,   -1,   -1,   -1,   -1,   -1,
      -1,   -1,   -1,   -1,   -1,   -1,   -1,   -1,
      -1,   -1,   -1,   -1,   -1,   -1,   -1,   -1,
      -1,   -1,   -1,   -1,   -1,   -1,   -1,   -1,
      -1,   -1,   -1,   -1,   -1,   -1,   -1,   -1,
      -1,   -1,   -1,   -1,   -1,   -1,   -1,   -1,
      -1,   -1, 3762,   -1,   -1,   -1,   -1,   -1,
      -1,   -1,   -1,   -1,   -1,   -1,   -1,   -1,
      -1,   -1,   -1,   -1,   -1,   -1,   -1,   -1,
      -1,   -1,   -1,   -1,   -1,   -1,   -1,   -1,
      -1,   -1,   -1,   -1,   -1,   -1,   -1,   -1,
      -1,   -1,   -1,   -1,   -1,   -1,   -1,   -1,
      -1,   -1,   -1,   -1,   -1,   -1, 3763,   -1,
      -1,   -1,   -1,   -1,   -1,   -1,   -1,   -1,
      -1,   -1,   -1,   -1, 3764,   -1,   -1,   -1,
      -1,   -1,   -1,   -1,   -1,   -1,   -1,   -1,
      -1,   -1,   -1,   -1,   -1,   -1,   -1,   -1,
      -1,   -1,   -1,   -1,   -1,   -1,   -1,   -1,
      -1,   -1,   -1,   -1,   -1, 3765,   -1,   -1,
      -1,   -1,   -1,   -1,   -1, 3766,   -1, 3767,
      -1,   -1,   -1,   -1,   -1,   -1,   -1,   -1,
      -1,   -1,   -1,   -1,   -1,   -1,   -1,   -1,
      -1,   -1,   -1,   -1,   -1,   -1,   -1, 3768,
      -1,   -1,   -1,   -1,   -1,   -1,   -1,   -1,
      -1,   -1,   -1,   -1,   -1,   -1, 3769,   -1,
      -1, 3770,   -1,   -1,   -1,   -1,   -1,   -1,
      -1,   -1,   -1,   -1,   -1,   -1,   -1,   -1,
      -1,   -1,   -1,   -1,   -1,   -1,   -1,   -1,
      -1,   -1,   -1,   -1,   -1,   -1,   -1,   -1,
      -1,   -1,   -1,   -1,   -1,   -1,   -1,   -1,
      -1,   -1,   -1,   -1,   -1,   -1,   -1,   -1,
      -1,   -1,   -1,   -1,   -1,   -1,   -1,   -1,
      -1,   -1,   -1,   -1,   -1, 3771,   -1,   -1,
      -1, 3772,   -1,   -1,   -1,   -1,   -1, 3773,
      -1,   -1,   -1,   -1,   -1,   -1,   -1,   -1,
      -1,   -1, 3774, 3775,   -1, 3776,   -1,   -1,
      -1,   -1,   -1,   -1,   -1,   -1,   -1,   -1,
      -1,   -1,   -1,   -1,   -1,   -1,   -1,   -1,
      -1,   -1,   -1,   -1,   -1,   -1,   -1,   -1,
      -1,   -1,   -1,   -1,   -1,   -1,   -1,   -1,
      -1, 3777,   -1,   -1,   -1,   -1,   -1,   -1,
      -1, 3778,   -1, 3779,   -1,   -1,   -1,   -1,
      -1,   -1, 3780,   -1,   -1,   -1,   -1,   -1,
      -1,   -1,   -1,   -1,   -1,   -1,   -1,   -1,
      -1,   -1, 3781,   -1,   -1,   -1,   -1,   -1,
      -1,   -1,   -1,   -1,   -1,   -1,   -1,   -1,
      -1,   -1,   -1,   -1,   -1,   -1,   -1,   -1,
      -1,   -1,   -1, 3782,   -1,   -1,   -1,   -1,
      -1,   -1,   -1,   -1,   -1,   -1,   -1,   -1,
      -1,   -1,   -1,   -1,   -1,   -1,   -1,   -1,
      -1,   -1,   -1, 3783,   -1,   -1,   -1,   -1,
      -1,   -1,   -1, 3784,   -1,   -1, 3785, 3786,
    3787,   -1,   -1,   -1, 3788,   -1,   -1,   -1,
      -1,   -1,   -1,   -1,   -1,   -1,   -1,   -1,
      -1,   -1,   -1,   -1,   -1,   -1,   -1,   -1,
    3789,   -1,   -1,   -1,   -1,   -1,   -1,   -1,
      -1,   -1,   -1,   -1,   -1,   -1,   -1,   -1,
      -1,   -1,   -1,   -1,   -1,   -1, 3790,   -1,
      -1,   -1,   -1,   -1,   -1,   -1,   -1,   -1,
      -1,   -1,   -1,   -1,   -1,   -1,   -1,   -1,
      -1,   -1,   -1,   -1,   -1,   -1,   -1,   -1,
      -1,   -1,   -1,   -1,   -1,   -1,   -1,   -1,
      -1,   -1, 3791,   -1,   -1,   -1,   -1,   -1,
      -1,   -1,   -1,   -1, 3792,   -1,   -1,   -1,
      -1,   -1,   -1,   -1,   -1,   -1,   -1,   -1,
      -1,   -1,   -1,   -1,   -1, 3793,   -1,   -1,
      -1,   -1,   -1,   -1,   -1,   -1,   -1,   -1,
      -1,   -1,   -1,   -1,   -1,   -1,   -1,   -1,
      -1,   -1,   -1,   -1,   -1,   -1,   -1, 3794,
      -1,   -1,   -1,   -1,   -1,   -1,   -1,   -1,
      -1,   -1,   -1,   -1,   -1,   -1, 3795,   -1,
      -1, 3796,   -1,   -1,   -1,   -1,   -1,   -1,
      -1,   -1,   -1,   -1,   -1,   -1,   -1,   -1,
      -1,   -1,   -1,   -1,   -1,   -1,   -1,   -1,
      -1,   -1,   -1,   -1,   -1,   -1,   -1, 3797,
      -1,   -1,   -1,   -1,   -1,   -1,   -1,   -1,
      -1,   -1,   -1,   -1,   -1,   -1,   -1,   -1,
      -1,   -1,   -1,   -1,   -1,   -1,   -1,   -1,
      -1,   -1,   -1,   -1,   -1,   -1, 3798,   -1,
      -1,   -1,   -1,   -1,   -1,   -1,   -1,   -1,
      -1,   -1,   -1,   -1,   -1,   -1,   -1,   -1,
      -1,   -1,   -1,   -1,   -1,   -1,   -1,   -1,
      -1,   -1, 3799,   -1,   -1, 3800,   -1,   -1,
      -1, 3801,   -1,   -1,   -1,   -1,   -1,   -1,
      -1, 3802,   -1,   -1,   -1,   -1,   -1,   -1,
      -1,   -1,   -1,   -1,   -1,   -1,   -1,   -1,
      -1,   -1,   -1,   -1,   -1,   -1,   -1,   -1,
      -1,   -1,   -1,   -1,   -1,   -1,   -1, 3803,
      -1,   -1,   -1,   -1,   -1,   -1,   -1,   -1,
      -1,   -1,   -1,   -1,   -1,   -1,   -1,   -1,
      -1,   -1,   -1,   -1,   -1,   -1,   -1,   -1,
      -1,   -1,   -1,   -1, 3804,   -1,   -1, 3805,
      -1, 3806,   -1,   -1,   -1,   -1,   -1,   -1,
      -1,   -1,   -1,   -1,   -1, 3807,   -1,   -1,
      -1,   -1,   -1,   -1,   -1,   -1,   -1, 3808,
      -1,   -1,   -1,   -1,   -1,   -1,   -1,   -1,
      -1,   -1,   -1,   -1,   -1,   -1,   -1,   -1,
      -1,   -1,   -1,   -1,   -1,   -1,   -1, 3809,
      -1,   -1,   -1,   -1,   -1,   -1,   -1,   -1,
      -1,   -1,   -1,   -1,   -1,   -1,   -1,   -1,
      -1,   -1, 3810,   -1,   -1,   -1,   -1,   -1,
      -1,   -1,   -1,   -1,   -1,   -1, 3811,   -1,
      -1,   -1, 3812,   -1,   -1,   -1,   -1,   -1,
      -1,   -1,   -1,   -1,   -1,   -1,   -1,   -1,
      -1,   -1,   -1,   -1,   -1,   -1,   -1,   -1,
      -1,   -1,   -1,   -1,   -1,   -1,   -1,   -1,
      -1,   -1,   -1,   -1,   -1,   -1,   -1,   -1,
      -1,   -1,   -1,   -1,   -1,   -1,   -1,   -1,
      -1,   -1,   -1,   -1,   -1,   -1,   -1,   -1,
      -1,   -1,   -1,   -1,   -1,   -1,   -1,   -1,
      -1,   -1,   -1,   -1,   -1,   -1,   -1,   -1,
      -1,   -1, 3813,   -1,   -1,   -1,   -1,   -1,
      -1,   -1,   -1,   -1,   -1,   -1,   -1,   -1,
      -1,   -1,   -1,   -1,   -1,   -1,   -1,   -1,
      -1,   -1,   -1, 3814,   -1, 3815,   -1,   -1,
      -1,   -1,   -1,   -1,   -1,   -1,   -1,   -1,
    3816,   -1,   -1,   -1,   -1,   -1,   -1,   -1,
      -1,   -1,   -1,   -1,   -1,   -1,   -1,   -1,
      -1,   -1,   -1,   -1,   -1,   -1,   -1,   -1,
      -1, 3817,   -1,   -1,   -1,   -1,   -1,   -1,
      -1,   -1,   -1,   -1,   -1,   -1,   -1,   -1,
      -1,   -1,   -1,   -1,   -1,   -1,   -1,   -1,
      -1,   -1, 3818,   -1, 3819, 3820,   -1,   -1,
      -1,   -1,   -1,   -1,   -1,   -1,   -1,   -1,
      -1, 3821,   -1,   -1,   -1,   -1,   -1,   -1,
      -1,   -1,   -1,   -1,   -1,   -1,   -1,   -1,
      -1,   -1,   -1,   -1,   -1,   -1,   -1,   -1,
    3822,   -1,   -1,   -1,   -1,   -1,   -1,   -1,
      -1,   -1,   -1,   -1,   -1,   -1,   -1,   -1,
      -1,   -1,   -1,   -1,   -1,   -1,   -1,   -1,
      -1,   -1,   -1, 3823,   -1,   -1, 3824,   -1,
      -1,   -1,   -1, 3825, 3826,   -1,   -1,   -1,
      -1,   -1,   -1,   -1,   -1,   -1,   -1,   -1,
      -1,   -1,   -1,   -1,   -1,   -1,   -1,   -1,
      -1,   -1,   -1,   -1,   -1,   -1,   -1,   -1,
      -1,   -1,   -1,   -1,   -1,   -1,   -1,   -1,
      -1,   -1,   -1,   -1,   -1,   -1,   -1,   -1,
      -1,   -1,   -1,   -1,   -1,   -1,   -1,   -1,
      -1,   -1,   -1,   -1,   -1,   -1,   -1,   -1,
      -1,   -1,   -1,   -1,   -1,   -1, 3827,   -1,
      -1,   -1,   -1,   -1,   -1,   -1,   -1,   -1,
      -1,   -1,   -1,   -1,   -1,   -1,   -1,   -1,
      -1,   -1,   -1, 3828, 3829, 3830,   -1,   -1,
      -1,   -1,   -1,   -1,   -1,   -1,   -1,   -1,
      -1,   -1,   -1,   -1,   -1,   -1,   -1,   -1,
    3831,   -1,   -1,   -1,   -1,   -1,   -1, 3832,
      -1,   -1,   -1,   -1,   -1,   -1,   -1,   -1,
      -1,   -1,   -1,   -1,   -1,   -1,   -1,   -1,
      -1,   -1,   -1,   -1,   -1,   -1,   -1,   -1,
      -1,   -1,   -1,   -1,   -1,   -1,   -1,   -1,
      -1,   -1,   -1,   -1,   -1,   -1,   -1,   -1,
      -1,   -1,   -1,   -1,   -1,   -1,   -1,   -1,
      -1,   -1,   -1,   -1,   -1,   -1,   -1,   -1,
      -1,   -1,   -1,   -1,   -1, 3833,   -1,   -1,
      -1,   -1,   -1,   -1,   -1,   -1,   -1,   -1,
      -1,   -1,   -1,   -1,   -1,   -1,   -1,   -1,
      -1, 3834,   -1,   -1,   -1,   -1,   -1,   -1,
      -1,   -1,   -1,   -1,   -1,   -1,   -1,   -1,
      -1,   -1,   -1,   -1,   -1,   -1,   -1,   -1,
      -1,   -1,   -1,   -1,   -1,   -1,   -1,   -1,
      -1,   -1,   -1,   -1,   -1,   -1,   -1,   -1,
      -1,   -1,   -1,   -1,   -1,   -1,   -1,   -1,
      -1,   -1,   -1,   -1,   -1,   -1,   -1,   -1,
      -1,   -1,   -1,   -1,   -1,   -1,   -1,   -1,
      -1,   -1,   -1,   -1,   -1,   -1, 3835,   -1,
      -1,   -1,   -1,   -1,   -1,   -1,   -1,   -1,
      -1, 3836,   -1,   -1,   -1,   -1,   -1,   -1,
      -1,   -1,   -1,   -1,   -1,   -1,   -1,   -1,
      -1,   -1,   -1,   -1,   -1,   -1,   -1,   -1,
      -1,   -1,   -1,   -1,   -1,   -1,   -1,   -1,
      -1, 3837, 3838,   -1,   -1, 3839,   -1,   -1,
    3840,   -1,   -1,   -1,   -1, 3841,   -1,   -1,
      -1,   -1,   -1,   -1,   -1,   -1,   -1,   -1,
      -1,   -1,   -1,   -1,   -1,   -1,   -1,   -1,
      -1,   -1,   -1,   -1,   -1,   -1,   -1,   -1,
      -1,   -1,   -1,   -1,   -1,   -1,   -1,   -1,
      -1,   -1, 3842,   -1,   -1,   -1,   -1,   -1,
      -1,   -1,   -1,   -1, 3843,   -1,   -1,   -1,
      -1,   -1,   -1,   -1,   -1,   -1,   -1,   -1,
      -1,   -1,   -1,   -1,   -1,   -1,   -1,   -1,
      -1,   -1,   -1,   -1,   -1,   -1,   -1,   -1,
      -1,   -1,   -1,   -1,   -1,   -1,   -1,   -1,
      -1,   -1,   -1,   -1, 3844,   -1,   -1,   -1,
      -1,   -1,   -1,   -1,   -1,   -1,   -1,   -1,
    3845, 3846,   -1,   -1,   -1,   -1,   -1,   -1,
      -1,   -1,   -1,   -1,   -1,   -1,   -1, 3847,
      -1,   -1,   -1,   -1,   -1,   -1,   -1,   -1,
      -1,   -1,   -1,   -1,   -1,   -1,   -1,   -1,
      -1,   -1,   -1,   -1,   -1,   -1,   -1,   -1,
      -1,   -1,   -1,   -1,   -1,   -1,   -1,   -1,
      -1, 3848,   -1,   -1,   -1,   -1,   -1,   -1,
      -1,   -1,   -1,   -1,   -1,   -1,   -1,   -1,
      -1,   -1,   -1,   -1,   -1,   -1,   -1,   -1,
      -1,   -1,   -1,   -1,   -1,   -1,   -1,   -1,
      -1,   -1,   -1,   -1,   -1,   -1,   -1,   -1,
      -1,   -1,   -1,   -1,   -1,   -1,   -1,   -1,
    3849,   -1,   -1, 3850,   -1,   -1,   -1,   -1,
      -1,   -1,   -1,   -1,   -1,   -1,   -1,   -1,
      -1,   -1,   -1,   -1,   -1,   -1,   -1,   -1,
      -1,   -1,   -1,   -1,   -1,   -1,   -1,   -1,
      -1, 3851,   -1,   -1,   -1,   -1,   -1,   -1,
      -1,   -1, 3852,   -1,   -1,   -1,   -1,   -1,
      -1,   -1, 3853,   -1,   -1,   -1,   -1,   -1,
      -1,   -1,   -1,   -1,   -1,   -1,   -1,   -1,
      -1,   -1,   -1,   -1,   -1,   -1, 3854,   -1,
      -1,   -1,   -1, 3855,   -1,   -1,   -1,   -1,
      -1,   -1,   -1,   -1,   -1,   -1,   -1,   -1,
      -1,   -1,   -1, 3856,   -1,   -1,   -1, 3857,
      -1,   -1,   -1,   -1,   -1,   -1,   -1,   -1,
      -1,   -1,   -1,   -1, 3858,   -1,   -1,   -1,
      -1,   -1,   -1,   -1,   -1,   -1,   -1,   -1,
      -1,   -1,   -1,   -1,   -1,   -1,   -1,   -1,
      -1,   -1,   -1,   -1,   -1,   -1,   -1,   -1,
      -1,   -1,   -1,   -1,   -1,   -1,   -1,   -1,
      -1,   -1,   -1,   -1,   -1,   -1,   -1,   -1,
      -1,   -1,   -1,   -1,   -1,   -1,   -1,   -1,
      -1,   -1,   -1,   -1,   -1,   -1,   -1,   -1,
      -1,   -1,   -1,   -1,   -1,   -1,   -1,   -1,
      -1,   -1,   -1,   -1,   -1,   -1,   -1,   -1,
    3859,   -1,   -1,   -1,   -1,   -1,   -1,   -1,
      -1,   -1,   -1,   -1,   -1,   -1,   -1,   -1,
      -1,   -1, 3860,   -1,   -1,   -1,   -1,   -1,
      -1,   -1,   -1,   -1,   -1,   -1,   -1,   -1,
      -1,   -1,   -1,   -1,   -1,   -1,   -1,   -1,
      -1,   -1,   -1, 3861,   -1,   -1,   -1,   -1,
      -1,   -1, 3862,   -1,   -1,   -1,   -1,   -1,
      -1, 3863,   -1,   -1,   -1,   -1,   -1,   -1,
      -1,   -1,   -1,   -1, 3864,   -1,   -1,   -1,
    3865,   -1,   -1,   -1,   -1,   -1,   -1,   -1,
    3866,   -1,   -1,   -1,   -1,   -1, 3867,   -1,
      -1,   -1,   -1,   -1,   -1,   -1,   -1,   -1,
    3868,   -1,   -1,   -1,   -1,   -1,   -1,   -1,
      -1,   -1,   -1,   -1,   -1,   -1,   -1,   -1,
      -1,   -1,   -1,   -1,   -1,   -1,   -1,   -1,
    3869,   -1, 3870,   -1,   -1,   -1,   -1,   -1,
      -1,   -1,   -1,   -1,   -1,   -1,   -1,   -1,
      -1,   -1,   -1,   -1,   -1,   -1,   -1,   -1,
      -1,   -1,   -1,   -1,   -1,   -1,   -1,   -1,
      -1,   -1,   -1,   -1,   -1,   -1,   -1,   -1,
      -1,   -1,   -1,   -1,   -1,   -1,   -1,   -1,
      -1,   -1,   -1,   -1,   -1,   -1,   -1,   -1,
      -1,   -1,   -1,   -1,   -1,   -1,   -1,   -1,
    3871,   -1,   -1,   -1,   -1,   -1,   -1,   -1,
      -1,   -1,   -1,   -1,   -1,   -1, 3872,   -1,
      -1,   -1,   -1,   -1,   -1,   -1,   -1,   -1,
      -1,   -1,   -1,   -1,   -1, 3873,   -1,   -1,
      -1,   -1,   -1,   -1,   -1,   -1,   -1,   -1,
      -1,   -1,   -1,   -1,   -1,   -1,   -1,   -1,
      -1,   -1,   -1,   -1,   -1,   -1,   -1,   -1,
      -1,   -1,   -1,   -1,   -1,   -1,   -1,   -1,
      -1,   -1,   -1,   -1,   -1,   -1,   -1,   -1,
      -1,   -1,   -1,   -1,   -1,   -1,   -1,   -1,
      -1,   -1,   -1,   -1,   -1,   -1,   -1,   -1,
      -1,   -1,   -1,   -1,   -1,   -1,   -1,   -1,
      -1,   -1,   -1,   -1,   -1,   -1,   -1,   -1,
      -1,   -1,   -1,   -1,   -1,   -1,   -1,   -1,
      -1,   -1,   -1,   -1,   -1,   -1,   -1,   -1,
      -1,   -1,   -1,   -1,   -1,   -1,   -1,   -1,
      -1,   -1,   -1,   -1,   -1,   -1,   -1,   -1,
      -1,   -1,   -1,   -1,   -1,   -1,   -1,   -1,
      -1,   -1,   -1,   -1,   -1,   -1,   -1,   -1,
      -1,   -1,   -1,   -1,   -1,   -1,   -1,   -1,
      -1,   -1,   -1,   -1,   -1, 3874,   -1,   -1,
      -1,   -1,   -1,   -1,   -1,   -1,   -1,   -1,
      -1,   -1,   -1,   -1,   -1,   -1,   -1,   -1,
      -1,   -1,   -1,   -1,   -1,   -1,   -1,   -1,
      -1,   -1,   -1,   -1,   -1,   -1,   -1,   -1,
      -1,   -1,   -1,   -1,   -1,   -1,   -1,   -1,
      -1,   -1,   -1,   -1,   -1,   -1,   -1,   -1,
      -1,   -1,   -1,   -1,   -1,   -1,   -1,   -1,
      -1,   -1,   -1,   -1,   -1,   -1,   -1,   -1,
      -1,   -1,   -1,   -1,   -1,   -1,   -1,   -1,
      -1,   -1,   -1,   -1,   -1,   -1,   -1,   -1,
      -1,   -1,   -1, 3875,   -1,   -1,   -1,   -1,
      -1,   -1,   -1,   -1,   -1,   -1,   -1,   -1,
      -1,   -1,   -1,   -1,   -1,   -1,   -1,   -1,
      -1,   -1,   -1,   -1,   -1,   -1, 3876,   -1,
      -1,   -1,   -1,   -1,   -1,   -1,   -1,   -1,
      -1,   -1,   -1,   -1,   -1,   -1,   -1,   -1,
      -1,   -1,   -1,   -1,   -1,   -1,   -1,   -1,
      -1,   -1,   -1,   -1,   -1,   -1,   -1,   -1,
      -1, 3877,   -1,   -1,   -1,   -1,   -1,   -1,
      -1,   -1,   -1,   -1,   -1,   -1,   -1,   -1,
      -1,   -1,   -1,   -1,   -1,   -1,   -1,   -1,
      -1, 3878,   -1,   -1,   -1,   -1,   -1,   -1,
      -1,   -1,   -1,   -1,   -1,   -1,   -1,   -1,
      -1,   -1,   -1,   -1,   -1,   -1,   -1,   -1,
      -1,   -1,   -1,   -1,   -1,   -1, 3879,   -1,
      -1,   -1,   -1,   -1,   -1,   -1,   -1,   -1,
      -1,   -1,   -1,   -1,   -1,   -1,   -1, 3880,
      -1,   -1,   -1,   -1,   -1,   -1,   -1,   -1,
      -1,   -1,   -1,   -1,   -1,   -1,   -1,   -1,
      -1,   -1,   -1,   -1,   -1,   -1,   -1,   -1,
      -1,   -1,   -1,   -1,   -1,   -1,   -1,   -1,
      -1,   -1,   -1,   -1, 3881,   -1,   -1,   -1,
      -1,   -1,   -1,   -1,   -1,   -1,   -1,   -1,
      -1,   -1,   -1,   -1,   -1,   -1,   -1,   -1,
      -1,   -1,   -1,   -1,   -1,   -1,   -1,   -1,
      -1,   -1,   -1,   -1,   -1,   -1,   -1,   -1,
    3882,   -1,   -1,   -1,   -1,   -1,   -1,   -1,
      -1,   -1,   -1,   -1,   -1,   -1,   -1,   -1,
      -1,   -1,   -1,   -1,   -1,   -1,   -1,   -1,
      -1,   -1,   -1,   -1,   -1,   -1,   -1,   -1,
      -1,   -1,   -1,   -1,   -1,   -1,   -1,   -1,
      -1,   -1,   -1,   -1,   -1,   -1,   -1,   -1,
      -1,   -1,   -1,   -1,   -1,   -1,   -1,   -1,
      -1,   -1,   -1,   -1,   -1,   -1,   -1,   -1,
      -1,   -1,   -1,   -1,   -1,   -1,   -1,   -1,
      -1,   -1,   -1,   -1,   -1,   -1,   -1, 3883,
      -1,   -1,   -1,   -1,   -1,   -1,   -1,   -1,
      -1,   -1,   -1,   -1,   -1,   -1, 3884,   -1,
      -1,   -1,   -1,   -1, 3885,   -1,   -1,   -1,
      -1,   -1,   -1,   -1,   -1,   -1,   -1,   -1,
      -1,   -1,   -1,   -1,   -1,   -1,   -1,   -1,
      -1,   -1,   -1,   -1,   -1,   -1,   -1,   -1,
      -1,   -1,   -1,   -1,   -1,   -1,   -1,   -1,
      -1,   -1,   -1,   -1,   -1,   -1,   -1,   -1,
      -1,   -1,   -1,   -1,   -1,   -1,   -1,   -1,
      -1,   -1,   -1,   -1,   -1,   -1,   -1,   -1,
      -1,   -1,   -1,   -1,   -1,   -1,   -1,   -1,
      -1,   -1,   -1,   -1,   -1,   -1,   -1, 3886,
      -1,   -1,   -1,   -1,   -1,   -1,   -1, 3887,
      -1,   -1,   -1,   -1,   -1,   -1,   -1,   -1,
      -1, 3888,   -1,   -1,   -1,   -1,   -1,   -1,
      -1,   -1,   -1,   -1,   -1,   -1,   -1,   -1,
      -1,   -1,   -1,   -1,   -1,   -1, 3889, 3890,
      -1,   -1,   -1,   -1,   -1,   -1,   -1,   -1,
      -1, 3891,   -1,   -1,   -1,   -1,   -1,   -1,
      -1,   -1,   -1,   -1,   -1,   -1,   -1,   -1,
      -1,   -1,   -1,   -1,   -1,   -1,   -1,   -1,
      -1,   -1,   -1,   -1,   -1,   -1,   -1,   -1,
    3892,   -1,   -1,   -1,   -1,   -1,   -1,   -1,
      -1,   -1,   -1,   -1,   -1,   -1,   -1,   -1,
      -1,   -1,   -1,   -1,   -1,   -1,   -1,   -1,
      -1,   -1,   -1,   -1,   -1,   -1,   -1,   -1,
      -1,   -1,   -1,   -1,   -1,   -1,   -1,   -1,
      -1,   -1,   -1, 3893,   -1,   -1,   -1,   -1,
      -1,   -1,   -1,   -1,   -1,   -1,   -1,   -1,
      -1,   -1,   -1, 3894,   -1,   -1,   -1,   -1,
      -1,   -1,   -1,   -1,   -1,   -1,   -1, 3895,
      -1,   -1,   -1,   -1,   -1,   -1,   -1,   -1,
      -1,   -1,   -1,   -1,   -1,   -1,   -1,   -1,
      -1,   -1, 3896,   -1,   -1,   -1,   -1,   -1,
      -1,   -1,   -1,   -1,   -1,   -1,   -1,   -1,
      -1,   -1,   -1,   -1,   -1,   -1,   -1,   -1,
      -1,   -1,   -1,   -1,   -1,   -1,   -1,   -1,
      -1,   -1,   -1,   -1,   -1,   -1,   -1,   -1,
      -1,   -1,   -1,   -1,   -1,   -1,   -1,   -1,
      -1,   -1,   -1,   -1,   -1,   -1,   -1,   -1,
      -1,   -1,   -1,   -1,   -1,   -1,   -1,   -1,
      -1,   -1,   -1,   -1,   -1,   -1,   -1,   -1,
      -1,   -1,   -1,   -1,   -1,   -1,   -1,   -1,
      -1,   -1,   -1,   -1,   -1,   -1,   -1,   -1,
      -1,   -1,   -1,   -1,   -1, 3897,   -1,   -1,
      -1,   -1,   -1,   -1,   -1,   -1,   -1,   -1,
      -1,   -1,   -1, 3898,   -1,   -1,   -1,   -1,
      -1,   -1,   -1,   -1,   -1,   -1,   -1,   -1,
      -1,   -1,   -1,   -1,   -1,   -1,   -1,   -1,
      -1,   -1,   -1,   -1,   -1,   -1, 3899,   -1,
      -1,   -1,   -1,   -1,   -1,   -1,   -1,   -1,
      -1,   -1,   -1,   -1,   -1,   -1,   -1,   -1,
    3900,   -1, 3901,   -1,   -1,   -1,   -1,   -1,
      -1,   -1,   -1,   -1,   -1,   -1,   -1,   -1,
      -1,   -1,   -1,   -1,   -1,   -1,   -1,   -1,
      -1,   -1,   -1,   -1,   -1,   -1,   -1,   -1,
      -1,   -1,   -1,   -1,   -1,   -1,   -1, 3902,
      -1,   -1,   -1,   -1,   -1,   -1,   -1,   -1,
      -1,   -1,   -1,   -1,   -1,   -1,   -1,   -1,
      -1,   -1,   -1,   -1,   -1,   -1,   -1,   -1,
      -1,   -1,   -1,   -1,   -1,   -1,   -1,   -1,
      -1,   -1,   -1,   -1,   -1,   -1,   -1,   -1,
      -1,   -1,   -1,   -1,   -1,   -1,   -1,   -1,
      -1,   -1,   -1,   -1,   -1,   -1,   -1, 3903,
      -1,   -1,   -1,   -1,   -1,   -1,   -1,   -1,
      -1,   -1,   -1,   -1,   -1,   -1,   -1,   -1,
      -1,   -1,   -1,   -1,   -1,   -1,   -1,   -1,
    3904,   -1,   -1,   -1,   -1,   -1,   -1,   -1,
      -1,   -1,   -1,   -1,   -1,   -1,   -1,   -1,
      -1,   -1,   -1,   -1,   -1,   -1,   -1,   -1,
      -1,   -1,   -1,   -1,   -1,   -1,   -1,   -1,
      -1,   -1,   -1,   -1,   -1,   -1,   -1,   -1,
      -1,   -1,   -1,   -1,   -1,   -1, 3905,   -1,
      -1,   -1,   -1,   -1,   -1,   -1,   -1,   -1,
      -1,   -1,   -1,   -1,   -1,   -1,   -1,   -1,
      -1,   -1,   -1,   -1,   -1,   -1,   -1,   -1,
      -1,   -1,   -1,   -1, 3906,   -1,   -1,   -1,
      -1,   -1,   -1,   -1,   -1, 3907,   -1,   -1,
      -1,   -1,   -1,   -1,   -1,   -1,   -1,   -1,
      -1,   -1,   -1,   -1,   -1,   -1,   -1,   -1,
      -1,   -1,   -1, 3908,   -1,   -1,   -1,   -1,
      -1,   -1, 3909,   -1,   -1,   -1,   -1,   -1,
      -1,   -1,   -1,   -1,   -1,   -1,   -1,   -1,
      -1,   -1,   -1,   -1,   -1,   -1, 3910,   -1,
      -1,   -1,   -1,   -1,   -1,   -1,   -1,   -1,
      -1,   -1,   -1,   -1,   -1,   -1,   -1,   -1,
      -1,   -1,   -1,   -1,   -1,   -1,   -1,   -1,
      -1,   -1,   -1,   -1,   -1,   -1,   -1,   -1,
      -1,   -1,   -1,   -1,   -1,   -1,   -1,   -1,
      -1,   -1,   -1,   -1,   -1,   -1,   -1,   -1,
      -1,   -1,   -1,   -1,   -1,   -1,   -1,   -1,
      -1,   -1,   -1,   -1,   -1,   -1,   -1,   -1,
    3911,   -1,   -1, 3912,   -1,   -1,   -1,   -1,
      -1,   -1, 3913,   -1,   -1,   -1,   -1,   -1,
      -1,   -1,   -1,   -1,   -1,   -1,   -1,   -1,
      -1,   -1, 3914,   -1,   -1,   -1,   -1,   -1,
      -1,   -1,   -1,   -1,   -1,   -1,   -1,   -1,
    3915,   -1,   -1,   -1,   -1,   -1, 3916,   -1,
      -1,   -1,   -1,   -1,   -1,   -1,   -1,   -1,
      -1,   -1,   -1,   -1,   -1,   -1,   -1,   -1,
      -1,   -1,   -1,   -1,   -1,   -1,   -1, 3917,
      -1,   -1,   -1,   -1,   -1, 3918,   -1,   -1,
      -1,   -1,   -1, 3919,   -1,   -1,   -1,   -1,
      -1,   -1,   -1,   -1,   -1,   -1,   -1,   -1,
      -1,   -1,   -1,   -1,   -1,   -1,   -1,   -1,
      -1,   -1,   -1,   -1,   -1,   -1,   -1,   -1,
    3920,   -1,   -1,   -1, 3921,   -1,   -1,   -1,
    3922,   -1,   -1,   -1,   -1,   -1,   -1,   -1,
      -1,   -1,   -1,   -1,   -1,   -1,   -1,   -1,
      -1,   -1,   -1,   -1,   -1,   -1,   -1,   -1,
      -1,   -1,   -1,   -1, 3923,   -1, 3924,   -1,
      -1,   -1,   -1,   -1,   -1,   -1,   -1,   -1,
      -1,   -1,   -1,   -1,   -1,   -1,   -1,   -1,
      -1,   -1,   -1,   -1,   -1,   -1,   -1,   -1,
      -1,   -1,   -1,   -1,   -1, 3925,   -1,   -1,
      -1,   -1,   -1,   -1,   -1,   -1, 3926,   -1,
      -1,   -1,   -1,   -1,   -1,   -1,   -1, 3927,
    3928, 3929,   -1,   -1,   -1,   -1,   -1,   -1,
      -1,   -1,   -1,   -1,   -1,   -1,   -1,   -1,
      -1,   -1,   -1,   -1,   -1,   -1,   -1,   -1,
      -1,   -1,   -1,   -1,   -1,   -1,   -1,   -1,
      -1,   -1,   -1,   -1,   -1,   -1,   -1,   -1,
      -1,   -1,   -1,   -1,   -1,   -1,   -1,   -1,
      -1,   -1,   -1,   -1,   -1,   -1,   -1,   -1,
      -1,   -1,   -1,   -1,   -1,   -1,   -1,   -1,
      -1,   -1,   -1,   -1,   -1,   -1,   -1,   -1,
      -1,   -1,   -1,   -1,   -1,   -1,   -1,   -1,
      -1,   -1,   -1,   -1,   -1,   -1,   -1,   -1,
      -1, 3930,   -1,   -1,   -1,   -1,   -1,   -1,
      -1,   -1,   -1,   -1,   -1,   -1,   -1,   -1,
      -1,   -1,   -1,   -1,   -1,   -1,   -1,   -1,
      -1,   -1,   -1,   -1,   -1,   -1,   -1, 3931,
      -1,   -1,   -1,   -1,   -1,   -1,   -1,   -1,
      -1,   -1,   -1,   -1,   -1,   -1,   -1,   -1,
      -1,   -1,   -1,   -1,   -1,   -1,   -1,   -1,
      -1,   -1,   -1, 3932, 3933,   -1,   -1,   -1,
      -1,   -1,   -1,   -1,   -1,   -1,   -1,   -1,
      -1,   -1,   -1,   -1,   -1,   -1,   -1,   -1,
      -1,   -1,   -1,   -1,   -1,   -1,   -1,   -1,
      -1,   -1,   -1,   -1,   -1,   -1,   -1,   -1,
      -1,   -1,   -1,   -1,   -1,   -1,   -1,   -1,
      -1,   -1,   -1,   -1,   -1,   -1,   -1,   -1,
      -1,   -1, 3934,   -1,   -1,   -1,   -1,   -1,
      -1,   -1,   -1,   -1,   -1,   -1,   -1,   -1,
      -1,   -1,   -1,   -1,   -1,   -1,   -1,   -1,
      -1,   -1,   -1,   -1,   -1,   -1,   -1,   -1,
      -1,   -1,   -1,   -1,   -1,   -1,   -1,   -1,
      -1,   -1,   -1,   -1,   -1,   -1,   -1,   -1,
      -1, 3935,   -1,   -1,   -1,   -1,   -1,   -1,
      -1,   -1,   -1,   -1,   -1, 3936,   -1,   -1,
      -1,   -1,   -1,   -1,   -1,   -1,   -1,   -1,
      -1,   -1,   -1,   -1,   -1,   -1,   -1,   -1,
      -1,   -1,   -1,   -1,   -1,   -1,   -1,   -1,
      -1, 3937,   -1,   -1,   -1,   -1,   -1,   -1,
      -1,   -1,   -1,   -1,   -1,   -1,   -1,   -1,
      -1,   -1,   -1,   -1,   -1,   -1,   -1,   -1,
      -1,   -1,   -1,   -1,   -1,   -1,   -1,   -1,
      -1,   -1,   -1,   -1,   -1,   -1,   -1,   -1,
      -1,   -1,   -1,   -1, 3938,   -1,   -1,   -1,
      -1,   -1, 3939,   -1, 3940,   -1, 3941,   -1,
      -1,   -1,   -1,   -1,   -1,   -1, 3942,   -1,
      -1,   -1,   -1,   -1,   -1,   -1,   -1,   -1,
      -1,   -1,   -1,   -1,   -1,   -1,   -1,   -1,
      -1,   -1,   -1,   -1,   -1,   -1,   -1,   -1,
      -1,   -1,   -1,   -1,   -1,   -1,   -1,   -1,
      -1,   -1,   -1,   -1,   -1,   -1,   -1, 3943,
      -1,   -1,   -1,   -1,   -1,   -1,   -1,   -1,
      -1,   -1,   -1,   -1,   -1,   -1,   -1,   -1,
      -1,   -1,   -1,   -1,   -1,   -1,   -1,   -1,
      -1,   -1,   -1,   -1,   -1,   -1,   -1,   -1,
      -1,   -1,   -1,   -1,   -1,   -1,   -1,   -1,
      -1,   -1,   -1, 3944,   -1,   -1,   -1,   -1,
      -1,   -1,   -1,   -1,   -1,   -1,   -1,   -1,
      -1,   -1,   -1,   -1,   -1,   -1,   -1,   -1,
      -1,   -1,   -1,   -1,   -1,   -1,   -1,   -1,
      -1,   -1,   -1,   -1,   -1,   -1,   -1,   -1,
      -1,   -1,   -1,   -1,   -1,   -1,   -1,   -1,
      -1, 3945,   -1,   -1,   -1,   -1,   -1,   -1,
      -1,   -1,   -1,   -1,   -1,   -1,   -1,   -1,
      -1,   -1,   -1,   -1,   -1,   -1,   -1,   -1,
      -1,   -1,   -1,   -1,   -1,   -1,   -1,   -1,
      -1,   -1,   -1,   -1,   -1,   -1,   -1,   -1,
      -1,   -1,   -1,   -1,   -1,   -1,   -1,   -1,
      -1,   -1,   -1,   -1,   -1,   -1,   -1,   -1,
      -1,   -1,   -1, 3946,   -1,   -1,   -1,   -1,
      -1,   -1,   -1,   -1,   -1,   -1,   -1,   -1,
      -1,   -1,   -1,   -1,   -1,   -1,   -1,   -1,
      -1,   -1,   -1,   -1,   -1,   -1,   -1,   -1,
      -1,   -1,   -1,   -1,   -1, 3947,   -1,   -1,
      -1,   -1,   -1,   -1,   -1,   -1,   -1,   -1,
      -1,   -1,   -1,   -1,   -1,   -1,   -1,   -1,
      -1, 3948,   -1,   -1, 3949,   -1,   -1,   -1,
      -1,   -1,   -1,   -1,   -1,   -1,   -1,   -1,
      -1,   -1,   -1,   -1,   -1,   -1,   -1,   -1,
      -1,   -1,   -1,   -1,   -1,   -1,   -1,   -1,
      -1,   -1, 3950,   -1, 3951,   -1,   -1, 3952,
      -1,   -1,   -1,   -1,   -1,   -1,   -1,   -1,
      -1,   -1,   -1,   -1,   -1,   -1,   -1, 3953,
      -1, 3954,   -1,   -1,   -1,   -1,   -1,   -1,
      -1,   -1,   -1,   -1,   -1,   -1,   -1,   -1,
      -1,   -1, 3955,   -1,   -1,   -1,   -1,   -1,
      -1,   -1,   -1,   -1,   -1,   -1,   -1,   -1,
      -1,   -1,   -1,   -1,   -1,   -1,   -1,   -1,
      -1,   -1,   -1,   -1,   -1,   -1,   -1, 3956,
      -1,   -1,   -1,   -1,   -1,   -1,   -1,   -1,
      -1,   -1,   -1,   -1,   -1,   -1,   -1,   -1,
      -1,   -1,   -1,   -1,   -1,   -1,   -1,   -1,
      -1,   -1,   -1,   -1,   -1, 3957,   -1, 3958,
      -1,   -1,   -1,   -1, 3959,   -1,   -1,   -1,
      -1,   -1,   -1,   -1,   -1,   -1,   -1,   -1,
      -1,   -1,   -1,   -1,   -1,   -1,   -1,   -1,
      -1,   -1,   -1,   -1,   -1, 3960,   -1,   -1,
      -1,   -1,   -1,   -1,   -1,   -1,   -1,   -1,
      -1,   -1,   -1,   -1,   -1,   -1,   -1,   -1,
      -1,   -1,   -1,   -1,   -1,   -1, 3961,   -1,
      -1,   -1,   -1,   -1,   -1,   -1,   -1,   -1,
      -1,   -1,   -1,   -1,   -1,   -1,   -1,   -1,
    3962,   -1,   -1,   -1,   -1,   -1,   -1,   -1,
      -1,   -1,   -1,   -1,   -1,   -1,   -1,   -1,
      -1,   -1,   -1,   -1,   -1,   -1,   -1,   -1,
      -1,   -1,   -1,   -1,   -1,   -1,   -1,   -1,
      -1,   -1,   -1,   -1,   -1,   -1,   -1,   -1,
      -1,   -1,   -1,   -1,   -1,   -1,   -1,   -1,
      -1,   -1,   -1,   -1,   -1,   -1, 3963,   -1,
      -1,   -1,   -1,   -1,   -1,   -1,   -1,   -1,
      -1,   -1,   -1,   -1,   -1,   -1,   -1,   -1,
      -1,   -1,   -1, 3964,   -1,   -1,   -1,   -1,
      -1,   -1,   -1,   -1,   -1,   -1,   -1,   -1,
      -1,   -1,   -1,   -1,   -1,   -1,   -1, 3965,
      -1, 3966,   -1,   -1,   -1,   -1,   -1,   -1,
      -1,   -1,   -1,   -1,   -1,   -1,   -1,   -1,
      -1,   -1,   -1,   -1,   -1,   -1,   -1,   -1,
      -1,   -1,   -1,   -1,   -1,   -1,   -1,   -1,
      -1,   -1,   -1, 3967,   -1,   -1,   -1,   -1,
      -1, 3968,   -1,   -1,   -1,   -1,   -1,   -1,
      -1,   -1,   -1,   -1,   -1,   -1,   -1,   -1,
      -1, 3969,   -1,   -1,   -1,   -1,   -1,   -1,
      -1,   -1,   -1,   -1, 3970,   -1,   -1,   -1,
      -1,   -1,   -1,   -1, 3971,   -1,   -1,   -1,
      -1,   -1,   -1,   -1,   -1,   -1,   -1,   -1,
      -1,   -1,   -1,   -1,   -1,   -1,   -1,   -1,
      -1,   -1,   -1, 3972,   -1,   -1,   -1,   -1,
      -1,   -1,   -1,   -1,   -1,   -1,   -1,   -1,
      -1,   -1,   -1,   -1,   -1,   -1, 3973,   -1,
      -1,   -1,   -1,   -1,   -1,   -1, 3974,   -1,
      -1,   -1,   -1,   -1,   -1,   -1,   -1,   -1,
      -1,   -1,   -1,   -1,   -1,   -1,   -1,   -1,
      -1,   -1,   -1,   -1,   -1,   -1,   -1,   -1,
      -1,   -1,   -1,   -1,   -1,   -1,   -1,   -1,
      -1,   -1,   -1,   -1,   -1,   -1,   -1,   -1,
      -1,   -1,   -1,   -1,   -1,   -1,   -1,   -1,
      -1,   -1,   -1,   -1,   -1,   -1,   -1,   -1,
      -1,   -1,   -1,   -1,   -1,   -1,   -1,   -1,
      -1,   -1,   -1,   -1,   -1,   -1,   -1,   -1,
      -1,   -1,   -1,   -1,   -1,   -1,   -1,   -1,
      -1,   -1,   -1,   -1,   -1,   -1,   -1,   -1,
      -1,   -1,   -1,   -1,   -1,   -1,   -1,   -1,
      -1,   -1,   -1,   -1,   -1,   -1,   -1,   -1,
      -1, 3975,   -1,   -1,   -1,   -1,   -1,   -1,
      -1,   -1,   -1,   -1,   -1,   -1,   -1,   -1,
      -1, 3976,   -1,   -1,   -1,   -1,   -1,   -1,
      -1,   -1,   -1,   -1,   -1,   -1, 3977,   -1,
      -1,   -1,   -1,   -1,   -1,   -1,   -1,   -1,
      -1, 3978,   -1,   -1,   -1,   -1,   -1,   -1,
      -1,   -1,   -1,   -1,   -1,   -1,   -1,   -1,
      -1,   -1,   -1,   -1,   -1,   -1,   -1,   -1,
      -1,   -1,   -1,   -1,   -1,   -1,   -1,   -1,
      -1,   -1,   -1,   -1,   -1,   -1, 3979,   -1,
      -1,   -1,   -1,   -1,   -1,   -1,   -1,   -1,
      -1,   -1,   -1,   -1,   -1,   -1,   -1,   -1,
      -1,   -1, 3980,   -1,   -1,   -1,   -1,   -1,
      -1,   -1,   -1,   -1,   -1,   -1,   -1,   -1,
      -1,   -1,   -1,   -1,   -1,   -1,   -1,   -1,
      -1,   -1,   -1,   -1,   -1,   -1,   -1,   -1,
      -1,   -1,   -1, 3981,   -1,   -1,   -1,   -1,
      -1,   -1,   -1,   -1,   -1,   -1,   -1,   -1,
      -1,   -1,   -1,   -1,   -1,   -1,   -1,   -1,
      -1,   -1,   -1,   -1,   -1,   -1,   -1,   -1,
      -1,   -1,   -1,   -1,   -1,   -1,   -1,   -1,
      -1,   -1,   -1,   -1,   -1,   -1,   -1,   -1,
      -1,   -1,   -1,   -1,   -1,   -1,   -1,   -1,
      -1,   -1,   -1,   -1,   -1,   -1,   -1,   -1,
      -1,   -1,   -1,   -1,   -1,   -1,   -1, 3982,
      -1,   -1,   -1,   -1,   -1,   -1,   -1,   -1,
      -1,   -1,   -1,   -1,   -1,   -1,   -1,   -1,
      -1,   -1,   -1,   -1,   -1,   -1,   -1,   -1,
      -1,   -1, 3983,   -1,   -1,   -1,   -1,   -1,
      -1,   -1,   -1,   -1,   -1,   -1,   -1,   -1,
      -1,   -1,   -1,   -1,   -1,   -1,   -1,   -1,
      -1,   -1,   -1,   -1,   -1,   -1,   -1,   -1,
      -1,   -1,   -1,   -1,   -1,   -1,   -1,   -1,
      -1,   -1,   -1,   -1,   -1,   -1,   -1,   -1,
      -1,   -1,   -1,   -1,   -1,   -1,   -1, 3984,
      -1,   -1,   -1,   -1,   -1,   -1,   -1,   -1,
      -1,   -1,   -1,   -1,   -1,   -1,   -1,   -1,
      -1,   -1,   -1,   -1, 3985,   -1,   -1,   -1,
    3986,   -1,   -1,   -1, 3987,   -1,   -1,   -1,
      -1,   -1,   -1,   -1,   -1,   -1,   -1,   -1,
      -1,   -1,   -1,   -1,   -1,   -1,   -1,   -1,
      -1,   -1,   -1,   -1,   -1,   -1,   -1,   -1,
      -1,   -1,   -1,   -1,   -1,   -1, 3988,   -1,
      -1,   -1,   -1,   -1,   -1,   -1,   -1,   -1,
    3989,   -1,   -1,   -1,   -1, 3990,   -1,   -1,
      -1,   -1,   -1,   -1,   -1,   -1,   -1, 3991,
      -1,   -1,   -1,   -1, 3992,   -1,   -1,   -1,
      -1, 3993,   -1,   -1,   -1,   -1,   -1,   -1,
      -1,   -1, 3994,   -1,   -1,   -1,   -1,   -1,
      -1,   -1, 3995,   -1,   -1,   -1,   -1,   -1,
      -1,   -1,   -1,   -1,   -1,   -1,   -1,   -1,
      -1,   -1,   -1,   -1,   -1,   -1,   -1,   -1,
      -1,   -1,   -1,   -1,   -1,   -1,   -1,   -1,
      -1,   -1,   -1,   -1,   -1,   -1,   -1,   -1,
      -1,   -1,   -1,   -1,   -1,   -1,   -1,   -1,
      -1,   -1,   -1,   -1,   -1,   -1,   -1,   -1,
      -1,   -1,   -1,   -1,   -1,   -1,   -1,   -1,
      -1,   -1,   -1,   -1,   -1,   -1,   -1,   -1,
      -1,   -1,   -1,   -1,   -1,   -1,   -1,   -1,
      -1,   -1,   -1,   -1,   -1,   -1,   -1,   -1,
      -1,   -1,   -1,   -1,   -1,   -1,   -1,   -1,
      -1,   -1,   -1,   -1,   -1,   -1,   -1,   -1,
      -1,   -1,   -1,   -1,   -1,   -1,   -1,   -1,
      -1,   -1,   -1,   -1,   -1,   -1,   -1,   -1,
      -1,   -1,   -1,   -1,   -1,   -1,   -1,   -1,
      -1,   -1,   -1,   -1,   -1,   -1,   -1,   -1,
      -1,   -1,   -1,   -1,   -1,   -1,   -1,   -1,
      -1,   -1,   -1,   -1,   -1,   -1,   -1,   -1,
      -1,   -1,   -1,   -1,   -1,   -1,   -1,   -1,
      -1,   -1,   -1,   -1,   -1,   -1,   -1,   -1,
      -1,   -1,   -1,   -1,   -1,   -1,   -1,   -1,
      -1,   -1,   -1,   -1,   -1,   -1,   -1,   -1,
      -1,   -1,   -1,   -1,   -1,   -1,   -1,   -1,
      -1,   -1,   -1,   -1,   -1,   -1,   -1,   -1,
      -1,   -1,   -1,   -1,   -1,   -1,   -1,   -1,
      -1,   -1,   -1,   -1,   -1,   -1,   -1,   -1,
      -1,   -1,   -1,   -1,   -1,   -1,   -1,   -1,
      -1,   -1,   -1,   -1,   -1,   -1,   -1,   -1,
      -1,   -1,   -1,   -1,   -1,   -1,   -1,   -1,
      -1,   -1,   -1,   -1,   -1,   -1,   -1,   -1,
      -1,   -1, 3996,   -1,   -1,   -1,   -1,   -1,
      -1, 3997,   -1,   -1,   -1,   -1,   -1,   -1,
    3998,   -1,   -1,   -1,   -1,   -1,   -1,   -1,
      -1,   -1,   -1,   -1,   -1,   -1,   -1,   -1,
      -1,   -1,   -1,   -1,   -1,   -1, 3999,   -1,
      -1,   -1,   -1,   -1,   -1,   -1,   -1,   -1,
      -1,   -1,   -1,   -1,   -1,   -1,   -1, 4000,
      -1,   -1,   -1,   -1,   -1,   -1,   -1,   -1,
      -1,   -1,   -1,   -1,   -1,   -1,   -1,   -1,
      -1, 4001,   -1,   -1,   -1,   -1,   -1,   -1,
      -1,   -1, 4002,   -1,   -1,   -1,   -1,   -1,
      -1,   -1,   -1,   -1,   -1,   -1,   -1,   -1,
      -1,   -1,   -1,   -1,   -1,   -1,   -1,   -1,
      -1,   -1,   -1,   -1,   -1,   -1,   -1,   -1,
      -1, 4003,   -1,   -1,   -1,   -1,   -1,   -1,
      -1,   -1,   -1,   -1,   -1,   -1,   -1,   -1,
      -1,   -1,   -1,   -1,   -1,   -1,   -1,   -1,
      -1,   -1,   -1,   -1,   -1,   -1,   -1,   -1,
      -1,   -1,   -1,   -1,   -1,   -1,   -1,   -1,
      -1,   -1,   -1,   -1,   -1,   -1,   -1,   -1,
      -1,   -1,   -1,   -1,   -1,   -1,   -1,   -1,
      -1,   -1,   -1,   -1,   -1,   -1,   -1,   -1,
      -1,   -1,   -1,   -1,   -1,   -1,   -1,   -1,
      -1,   -1,   -1, 4004,   -1,   -1,   -1,   -1,
      -1,   -1,   -1,   -1,   -1,   -1,   -1,   -1,
      -1,   -1,   -1,   -1,   -1,   -1,   -1,   -1,
      -1,   -1,   -1,   -1,   -1,   -1,   -1,   -1,
      -1,   -1,   -1,   -1,   -1,   -1,   -1,   -1,
      -1,   -1,   -1,   -1, 4005,   -1,   -1,   -1,
      -1,   -1,   -1,   -1,   -1,   -1,   -1,   -1,
      -1,   -1,   -1,   -1,   -1,   -1,   -1,   -1,
      -1,   -1,   -1,   -1,   -1,   -1,   -1,   -1,
      -1,   -1,   -1,   -1,   -1,   -1,   -1,   -1,
      -1,   -1,   -1,   -1,   -1,   -1,   -1,   -1,
      -1,   -1,   -1,   -1,   -1, 4006,   -1,   -1,
      -1,   -1,   -1,   -1,   -1,   -1,   -1,   -1,
      -1,   -1,   -1,   -1,   -1,   -1,   -1,   -1,
      -1,   -1,   -1,   -1,   -1,   -1,   -1,   -1,
      -1,   -1,   -1,   -1,   -1,   -1,   -1,   -1,
      -1,   -1,   -1,   -1,   -1,   -1,   -1,   -1,
      -1,   -1,   -1,   -1,   -1,   -1,   -1,   -1,
      -1, 4007,   -1,   -1,   -1,   -1,   -1,   -1,
      -1,   -1,   -1,   -1,   -1,   -1,   -1,   -1,
      -1,   -1,   -1,   -1,   -1,   -1,   -1,   -1,
      -1,   -1,   -1,   -1,   -1,   -1,   -1,   -1,
      -1,   -1,   -1,   -1,   -1,   -1,   -1,   -1,
      -1,   -1,   -1,   -1,   -1,   -1,   -1,   -1,
      -1,   -1,   -1,   -1,   -1,   -1,   -1,   -1,
      -1,   -1,   -1,   -1,   -1,   -1,   -1,   -1,
      -1,   -1,   -1,   -1,   -1,   -1,   -1,   -1,
      -1,   -1,   -1,   -1,   -1,   -1,   -1,   -1,
      -1,   -1,   -1,   -1,   -1,   -1,   -1,   -1,
      -1,   -1,   -1,   -1,   -1,   -1,   -1,   -1,
      -1,   -1,   -1,   -1,   -1,   -1,   -1,   -1,
      -1,   -1,   -1,   -1,   -1,   -1,   -1,   -1,
      -1,   -1,   -1,   -1,   -1,   -1,   -1,   -1,
      -1,   -1,   -1, 4008,   -1,   -1,   -1,   -1,
      -1,   -1,   -1,   -1,   -1,   -1,   -1,   -1,
      -1,   -1,   -1,   -1,   -1,   -1,   -1,   -1,
      -1,   -1,   -1,   -1,   -1,   -1,   -1,   -1,
      -1,   -1,   -1,   -1,   -1,   -1,   -1,   -1,
      -1,   -1,   -1,   -1,   -1,   -1,   -1,   -1,
      -1,   -1,   -1,   -1,   -1,   -1,   -1,   -1,
      -1,   -1,   -1,   -1,   -1,   -1,   -1,   -1,
      -1,   -1,   -1,   -1,   -1,   -1,   -1,   -1,
      -1,   -1,   -1,   -1,   -1,   -1,   -1,   -1,
      -1,   -1,   -1,   -1,   -1,   -1,   -1,   -1,
      -1,   -1,   -1,   -1,   -1,   -1,   -1,   -1,
      -1,   -1,   -1,   -1,   -1,   -1,   -1, 4009,
      -1,   -1,   -1,   -1,   -1,   -1,   -1,   -1,
      -1,   -1,   -1,   -1, 4010,   -1,   -1,   -1,
      -1,   -1,   -1,   -1,   -1,   -1,   -1,   -1,
      -1,   -1,   -1,   -1,   -1,   -1,   -1,   -1,
      -1,   -1,   -1, 4011,   -1,   -1,   -1,   -1,
      -1,   -1,   -1, 4012,   -1,   -1,   -1,   -1,
      -1,   -1,   -1,   -1,   -1,   -1,   -1,   -1,
      -1,   -1,   -1,   -1,   -1,   -1,   -1,   -1,
      -1,   -1,   -1,   -1,   -1,   -1,   -1,   -1,
      -1,   -1,   -1,   -1,   -1,   -1,   -1,   -1,
      -1,   -1,   -1,   -1, 4013,   -1,   -1, 4014,
      -1,   -1,   -1,   -1,   -1,   -1,   -1,   -1,
      -1,   -1,   -1,   -1,   -1,   -1,   -1,   -1,
      -1,   -1,   -1,   -1,   -1,   -1,   -1,   -1,
      -1,   -1,   -1,   -1,   -1,   -1,   -1,   -1,
      -1,   -1,   -1,   -1,   -1,   -1,   -1,   -1,
      -1,   -1, 4015,   -1,   -1,   -1,   -1,   -1,
      -1,   -1,   -1,   -1,   -1,   -1,   -1,   -1,
      -1,   -1,   -1,   -1,   -1,   -1,   -1,   -1,
      -1,   -1,   -1,   -1,   -1,   -1,   -1, 4016,
      -1,   -1,   -1,   -1,   -1,   -1,   -1,   -1,
      -1,   -1,   -1,   -1,   -1,   -1,   -1,   -1,
      -1,   -1,   -1,   -1,   -1,   -1,   -1,   -1,
      -1,   -1,   -1,   -1,   -1,   -1,   -1,   -1,
      -1,   -1,   -1,   -1,   -1,   -1,   -1,   -1,
      -1,   -1,   -1,   -1,   -1,   -1,   -1,   -1,
      -1,   -1,   -1,   -1, 4017,   -1,   -1,   -1,
      -1, 4018,   -1,   -1,   -1,   -1,   -1,   -1,
      -1,   -1,   -1,   -1,   -1,   -1,   -1,   -1,
      -1,   -1,   -1,   -1,   -1,   -1,   -1,   -1,
      -1,   -1,   -1,   -1,   -1,   -1,   -1,   -1,
      -1,   -1,   -1,   -1,   -1, 4019,   -1, 4020,
      -1,   -1,   -1,   -1,   -1,   -1,   -1,   -1,
      -1,   -1,   -1,   -1,   -1,   -1,   -1,   -1,
      -1,   -1,   -1,   -1,   -1,   -1,   -1,   -1,
      -1,   -1,   -1,   -1,   -1,   -1,   -1,   -1,
      -1,   -1,   -1,   -1,   -1,   -1,   -1,   -1,
      -1,   -1,   -1,   -1,   -1,   -1,   -1,   -1,
      -1,   -1,   -1,   -1,   -1,   -1,   -1,   -1,
      -1,   -1,   -1,   -1,   -1,   -1,   -1,   -1,
      -1,   -1,   -1,   -1,   -1,   -1,   -1,   -1,
      -1,   -1,   -1,   -1,   -1,   -1,   -1,   -1,
      -1,   -1,   -1,   -1,   -1, 4021,   -1, 4022,
      -1,   -1,   -1,   -1,   -1,   -1,   -1,   -1,
      -1,   -1,   -1,   -1,   -1,   -1,   -1,   -1,
      -1,   -1,   -1,   -1,   -1,   -1,   -1,   -1,
      -1,   -1,   -1,   -1,   -1,   -1,   -1,   -1,
      -1,   -1,   -1,   -1,   -1,   -1,   -1, 4023,
      -1,   -1, 4024,   -1,   -1,   -1,   -1,   -1,
      -1,   -1, 4025,   -1,   -1,   -1,   -1,   -1,
      -1,   -1,   -1,   -1,   -1,   -1,   -1,   -1,
      -1,   -1,   -1,   -1,   -1,   -1,   -1,   -1,
      -1,   -1,   -1,   -1, 4026,   -1,   -1,   -1,
      -1,   -1,   -1,   -1,   -1,   -1,   -1,   -1,
      -1,   -1,   -1,   -1,   -1,   -1,   -1,   -1,
      -1,   -1,   -1,   -1,   -1,   -1,   -1,   -1,
      -1,   -1,   -1,   -1,   -1,   -1,   -1,   -1,
      -1,   -1,   -1,   -1,   -1,   -1,   -1,   -1,
      -1, 4027,   -1,   -1,   -1,   -1,   -1,   -1,
      -1,   -1,   -1,   -1,   -1,   -1,   -1, 4028,
      -1,   -1,   -1,   -1,   -1,   -1,   -1,   -1,
      -1,   -1,   -1,   -1,   -1,   -1,   -1,   -1,
      -1,   -1,   -1,   -1,   -1,   -1,   -1,   -1,
      -1,   -1,   -1,   -1,   -1,   -1,   -1,   -1,
      -1,   -1,   -1,   -1,   -1,   -1, 4029, 4030,
      -1,   -1,   -1,   -1,   -1,   -1,   -1,   -1,
      -1,   -1,   -1,   -1,   -1,   -1,   -1,   -1,
      -1,   -1,   -1,   -1,   -1,   -1,   -1,   -1,
    4031,   -1,   -1,   -1,   -1,   -1,   -1,   -1,
      -1,   -1,   -1,   -1,   -1,   -1,   -1,   -1,
      -1,   -1,   -1,   -1,   -1,   -1,   -1,   -1,
      -1,   -1,   -1,   -1,   -1,   -1,   -1,   -1,
      -1,   -1,   -1,   -1,   -1,   -1,   -1,   -1,
      -1,   -1,   -1,   -1,   -1,   -1,   -1,   -1,
      -1,   -1, 4032,   -1,   -1,   -1,   -1,   -1,
      -1,   -1,   -1,   -1,   -1,   -1,   -1,   -1,
      -1,   -1,   -1,   -1,   -1,   -1,   -1,   -1,
    4033,   -1,   -1,   -1,   -1,   -1,   -1,   -1,
      -1,   -1,   -1,   -1,   -1,   -1,   -1,   -1,
      -1,   -1,   -1,   -1,   -1, 4034,   -1, 4035,
      -1,   -1,   -1,   -1,   -1,   -1,   -1,   -1,
      -1,   -1,   -1,   -1,   -1,   -1,   -1,   -1,
      -1,   -1,   -1,   -1,   -1,   -1,   -1,   -1,
      -1,   -1,   -1,   -1,   -1,   -1,   -1,   -1,
      -1,   -1,   -1,   -1,   -1,   -1,   -1,   -1,
      -1,   -1,   -1,   -1,   -1,   -1,   -1,   -1,
      -1,   -1,   -1,   -1,   -1,   -1,   -1,   -1,
      -1,   -1,   -1,   -1,   -1,   -1,   -1,   -1,
      -1,   -1,   -1,   -1,   -1,   -1,   -1,   -1,
      -1,   -1,   -1,   -1,   -1,   -1,   -1,   -1,
      -1,   -1,   -1,   -1,   -1,   -1,   -1,   -1,
      -1,   -1,   -1,   -1,   -1,   -1,   -1,   -1,
      -1,   -1,   -1,   -1,   -1,   -1,   -1,   -1,
      -1,   -1,   -1,   -1,   -1,   -1,   -1,   -1,
      -1,   -1,   -1,   -1,   -1,   -1,   -1,   -1,
      -1,   -1,   -1,   -1,   -1,   -1,   -1,   -1,
    4036,   -1,   -1,   -1,   -1,   -1,   -1,   -1,
      -1,   -1,   -1,   -1, 4037,   -1,   -1,   -1,
      -1,   -1,   -1,   -1,   -1,   -1,   -1,   -1,
      -1,   -1,   -1,   -1,   -1,   -1,   -1,   -1,
      -1,   -1,   -1,   -1,   -1,   -1,   -1,   -1,
      -1,   -1,   -1,   -1,   -1, 4038,   -1,   -1,
      -1,   -1,   -1,   -1,   -1,   -1,   -1,   -1,
      -1,   -1,   -1,   -1,   -1,   -1,   -1,   -1,
      -1,   -1,   -1,   -1,   -1,   -1,   -1,   -1,
      -1,   -1,   -1,   -1,   -1,   -1,   -1,   -1,
      -1,   -1,   -1,   -1,   -1,   -1,   -1,   -1,
      -1,   -1,   -1,   -1,   -1,   -1,   -1,   -1,
      -1,   -1,   -1,   -1,   -1,   -1,   -1,   -1,
      -1,   -1,   -1,   -1,   -1,   -1,   -1,   -1,
      -1,   -1,   -1,   -1,   -1,   -1,   -1,   -1,
      -1,   -1,   -1,   -1,   -1,   -1,   -1,   -1,
      -1,   -1,   -1,   -1,   -1,   -1,   -1,   -1,
      -1,   -1, 4039, 4040,   -1,   -1,   -1,   -1,
      -1,   -1,   -1,   -1,   -1,   -1, 4041,   -1,
      -1,   -1,   -1,   -1,   -1,   -1,   -1,   -1,
      -1,   -1,   -1,   -1, 4042, 4043,   -1,   -1,
      -1,   -1,   -1,   -1,   -1,   -1,   -1, 4044,
      -1,   -1, 4045,   -1,   -1,   -1,   -1,   -1,
      -1,   -1,   -1,   -1,   -1,   -1,   -1,   -1,
      -1,   -1,   -1,   -1,   -1,   -1,   -1,   -1,
      -1,   -1,   -1,   -1,   -1,   -1,   -1,   -1,
      -1,   -1,   -1,   -1,   -1,   -1,   -1,   -1,
      -1,   -1,   -1,   -1,   -1,   -1,   -1,   -1,
      -1,   -1,   -1,   -1,   -1,   -1,   -1,   -1,
      -1,   -1,   -1,   -1,   -1,   -1,   -1,   -1,
      -1,   -1,   -1,   -1,   -1,   -1,   -1,   -1,
      -1,   -1,   -1,   -1,   -1,   -1,   -1,   -1,
      -1,   -1,   -1,   -1,   -1,   -1,   -1,   -1,
      -1,   -1,   -1,   -1,   -1,   -1,   -1, 4046,
      -1,   -1,   -1,   -1,   -1,   -1,   -1,   -1,
      -1,   -1,   -1,   -1,   -1,   -1,   -1,   -1,
      -1,   -1,   -1,   -1,   -1,   -1,   -1,   -1,
      -1,   -1,   -1,   -1,   -1,   -1,   -1,   -1,
      -1,   -1,   -1,   -1,   -1,   -1,   -1,   -1,
      -1,   -1,   -1,   -1,   -1,   -1,   -1,   -1,
      -1,   -1,   -1,   -1,   -1,   -1,   -1,   -1,
      -1,   -1,   -1,   -1,   -1,   -1,   -1,   -1,
      -1,   -1,   -1,   -1,   -1,   -1,   -1, 4047,
      -1,   -1,   -1,   -1,   -1,   -1,   -1,   -1,
      -1,   -1,   -1,   -1,   -1,   -1,   -1,   -1,
      -1,   -1,   -1,   -1,   -1,   -1, 4048,   -1,
      -1,   -1,   -1,   -1,   -1,   -1,   -1,   -1,
      -1,   -1,   -1,   -1,   -1,   -1,   -1,   -1,
      -1,   -1,   -1,   -1,   -1,   -1,   -1,   -1,
      -1,   -1,   -1,   -1,   -1,   -1,   -1,   -1,
      -1,   -1,   -1,   -1,   -1,   -1,   -1,   -1,
      -1,   -1,   -1,   -1,   -1,   -1,   -1,   -1,
      -1,   -1, 4049,   -1,   -1,   -1,   -1,   -1,
      -1,   -1,   -1,   -1,   -1,   -1,   -1,   -1,
      -1,   -1,   -1,   -1,   -1,   -1,   -1,   -1,
      -1,   -1,   -1, 4050,   -1,   -1,   -1,   -1,
      -1,   -1,   -1,   -1,   -1,   -1,   -1,   -1,
      -1,   -1,   -1, 4051,   -1,   -1,   -1,   -1,
      -1,   -1,   -1,   -1,   -1,   -1,   -1,   -1,
      -1,   -1,   -1,   -1,   -1,   -1,   -1,   -1,
      -1,   -1,   -1,   -1,   -1,   -1,   -1,   -1,
      -1,   -1,   -1,   -1,   -1,   -1,   -1,   -1,
      -1,   -1,   -1,   -1, 4052,   -1,   -1,   -1,
      -1, 4053,   -1,   -1,   -1,   -1,   -1,   -1,
      -1,   -1,   -1,   -1,   -1,   -1,   -1,   -1,
      -1,   -1,   -1,   -1,   -1,   -1,   -1,   -1,
      -1,   -1,   -1,   -1,   -1,   -1,   -1,   -1,
      -1,   -1,   -1,   -1,   -1,   -1,   -1,   -1,
      -1,   -1,   -1,   -1,   -1,   -1,   -1,   -1,
      -1,   -1,   -1,   -1,   -1,   -1,   -1,   -1,
      -1,   -1,   -1,   -1,   -1,   -1,   -1,   -1,
      -1,   -1,   -1,   -1,   -1,   -1,   -1,   -1,
      -1,   -1,   -1,   -1,   -1,   -1,   -1,   -1,
      -1,   -1,   -1,   -1,   -1,   -1,   -1,   -1,
      -1,   -1,   -1,   -1,   -1,   -1,   -1,   -1,
      -1,   -1, 4054,   -1,   -1,   -1,   -1,   -1,
      -1,   -1,   -1,   -1,   -1,   -1,   -1,   -1,
      -1,   -1,   -1,   -1, 4055,   -1,   -1,   -1,
      -1,   -1,   -1,   -1,   -1,   -1,   -1,   -1,
      -1,   -1,   -1,   -1,   -1,   -1,   -1,   -1,
      -1,   -1,   -1,   -1,   -1,   -1,   -1,   -1,
      -1,   -1,   -1,   -1,   -1,   -1,   -1,   -1,
      -1,   -1,   -1,   -1,   -1,   -1,   -1,   -1,
      -1,   -1,   -1,   -1,   -1,   -1,   -1,   -1,
      -1,   -1,   -1,   -1,   -1,   -1,   -1,   -1,
      -1,   -1,   -1,   -1,   -1,   -1,   -1,   -1,
      -1,   -1,   -1,   -1,   -1,   -1,   -1,   -1,
      -1,   -1,   -1,   -1,   -1,   -1,   -1,   -1,
      -1,   -1,   -1,   -1,   -1,   -1,   -1,   -1,
      -1,   -1,   -1,   -1,   -1,   -1,   -1,   -1,
      -1,   -1,   -1,   -1,   -1,   -1,   -1,   -1,
    4056,   -1,   -1,   -1,   -1,   -1,   -1,   -1,
      -1,   -1,   -1,   -1,   -1,   -1,   -1,   -1,
      -1,   -1,   -1,   -1,   -1,   -1,   -1,   -1,
      -1,   -1,   -1, 4057,   -1,   -1,   -1,   -1,
      -1,   -1,   -1,   -1,   -1,   -1,   -1,   -1,
      -1,   -1,   -1, 4058,   -1,   -1,   -1,   -1,
      -1,   -1,   -1, 4059, 4060,   -1,   -1,   -1,
      -1,   -1,   -1,   -1,   -1,   -1,   -1,   -1,
      -1,   -1,   -1,   -1,   -1,   -1,   -1,   -1,
      -1,   -1,   -1, 4061,   -1,   -1,   -1,   -1,
      -1,   -1,   -1,   -1,   -1,   -1,   -1,   -1,
      -1,   -1,   -1,   -1,   -1,   -1,   -1,   -1,
      -1,   -1,   -1,   -1, 4062, 4063,   -1,   -1,
      -1,   -1,   -1,   -1,   -1,   -1,   -1,   -1,
      -1,   -1,   -1,   -1,   -1,   -1,   -1,   -1,
      -1,   -1,   -1,   -1,   -1,   -1,   -1,   -1,
      -1,   -1,   -1,   -1,   -1,   -1,   -1,   -1,
      -1,   -1,   -1,   -1,   -1,   -1,   -1,   -1,
      -1,   -1,   -1,   -1,   -1,   -1,   -1,   -1,
      -1,   -1,   -1,   -1,   -1,   -1,   -1,   -1,
      -1,   -1,   -1,   -1,   -1,   -1,   -1,   -1,
      -1,   -1,   -1,   -1,   -1,   -1,   -1,   -1,
      -1,   -1,   -1,   -1,   -1,   -1,   -1,   -1,
      -1,   -1,   -1,   -1,   -1,   -1,   -1,   -1,
      -1,   -1,   -1,   -1,   -1,   -1,   -1,   -1,
      -1,   -1, 4064,   -1,   -1,   -1,   -1,   -1,
      -1,   -1,   -1,   -1,   -1,   -1,   -1,   -1,
      -1,   -1,   -1,   -1,   -1,   -1,   -1,   -1,
      -1,   -1,   -1,   -1,   -1,   -1,   -1,   -1,
      -1,   -1,   -1,   -1,   -1,   -1,   -1,   -1,
      -1,   -1,   -1,   -1,   -1,   -1,   -1,   -1,
      -1,   -1,   -1,   -1,   -1,   -1,   -1,   -1,
      -1,   -1,   -1,   -1,   -1,   -1, 4065,   -1,
      -1,   -1,   -1,   -1,   -1,   -1,   -1,   -1,
      -1,   -1,   -1,   -1,   -1,   -1,   -1,   -1,
      -1,   -1,   -1,   -1,   -1,   -1,   -1,   -1,
      -1,   -1,   -1,   -1,   -1,   -1,   -1,   -1,
      -1,   -1,   -1,   -1,   -1,   -1,   -1,   -1,
      -1,   -1,   -1,   -1,   -1,   -1,   -1,   -1,
      -1,   -1,   -1,   -1,   -1,   -1,   -1,   -1,
      -1,   -1,   -1,   -1,   -1,   -1,   -1,   -1,
      -1,   -1,   -1,   -1,   -1,   -1,   -1,   -1,
      -1,   -1,   -1,   -1,   -1,   -1,   -1,   -1,
      -1,   -1,   -1,   -1,   -1,   -1,   -1,   -1,
      -1,   -1,   -1,   -1,   -1,   -1,   -1,   -1,
      -1,   -1,   -1,   -1,   -1,   -1,   -1,   -1,
      -1,   -1,   -1,   -1,   -1,   -1,   -1,   -1,
      -1,   -1,   -1,   -1,   -1,   -1,   -1,   -1,
      -1,   -1,   -1,   -1,   -1,   -1,   -1,   -1,
      -1,   -1, 4066,   -1,   -1,   -1,   -1,   -1,
      -1,   -1,   -1,   -1,   -1,   -1,   -1,   -1,
      -1,   -1,   -1, 4067,   -1,   -1,   -1,   -1,
      -1,   -1,   -1,   -1,   -1,   -1,   -1,   -1,
      -1,   -1,   -1,   -1,   -1,   -1,   -1,   -1,
      -1,   -1,   -1,   -1,   -1,   -1,   -1,   -1,
      -1,   -1, 4068,   -1,   -1,   -1, 4069,   -1,
      -1,   -1,   -1,   -1,   -1,   -1,   -1,   -1,
      -1,   -1,   -1,   -1,   -1,   -1,   -1,   -1,
      -1,   -1,   -1,   -1,   -1,   -1,   -1,   -1,
      -1,   -1,   -1,   -1,   -1,   -1,   -1,   -1,
      -1,   -1,   -1,   -1,   -1,   -1,   -1,   -1,
      -1,   -1,   -1,   -1,   -1,   -1,   -1,   -1,
      -1,   -1,   -1,   -1,   -1,   -1,   -1,   -1,
      -1,   -1,   -1,   -1,   -1,   -1,   -1,   -1,
      -1,   -1,   -1,   -1,   -1,   -1,   -1,   -1,
      -1,   -1,   -1,   -1,   -1,   -1,   -1,   -1,
      -1,   -1,   -1,   -1,   -1,   -1,   -1,   -1,
      -1,   -1,   -1,   -1,   -1,   -1,   -1,   -1,
      -1,   -1,   -1,   -1,   -1,   -1,   -1,   -1,
      -1,   -1,   -1,   -1,   -1,   -1,   -1,   -1,
      -1,   -1,   -1,   -1,   -1,   -1,   -1,   -1,
      -1,   -1,   -1,   -1,   -1,   -1,   -1,   -1,
      -1,   -1,   -1,   -1,   -1,   -1,   -1,   -1,
      -1,   -1,   -1,   -1,   -1,   -1,   -1,   -1,
      -1,   -1,   -1,   -1,   -1,   -1,   -1, 4070,
      -1,   -1,   -1,   -1,   -1,   -1,   -1,   -1,
      -1,   -1,   -1,   -1,   -1,   -1,   -1,   -1,
      -1,   -1,   -1,   -1,   -1,   -1,   -1,   -1,
      -1,   -1,   -1,   -1,   -1,   -1,   -1,   -1,
      -1,   -1,   -1,   -1,   -1,   -1,   -1,   -1,
      -1,   -1,   -1,   -1,   -1,   -1,   -1,   -1,
      -1,   -1,   -1,   -1,   -1,   -1,   -1,   -1,
      -1,   -1,   -1,   -1,   -1,   -1,   -1,   -1,
      -1,   -1,   -1,   -1,   -1, 4071,   -1,   -1,
      -1,   -1,   -1,   -1,   -1,   -1,   -1,   -1,
      -1,   -1,   -1,   -1,   -1,   -1,   -1,   -1,
      -1,   -1,   -1,   -1,   -1,   -1,   -1,   -1,
      -1,   -1,   -1,   -1,   -1,   -1,   -1,   -1,
      -1,   -1,   -1,   -1,   -1,   -1,   -1,   -1,
      -1,   -1,   -1,   -1,   -1,   -1,   -1,   -1,
      -1,   -1,   -1,   -1,   -1,   -1,   -1, 4072,
      -1,   -1,   -1,   -1,   -1,   -1,   -1,   -1,
    4073,   -1,   -1,   -1,   -1,   -1,   -1,   -1,
      -1,   -1,   -1,   -1,   -1,   -1,   -1,   -1,
      -1,   -1,   -1,   -1,   -1,   -1,   -1,   -1,
      -1,   -1,   -1,   -1, 4074,   -1,   -1,   -1,
      -1,   -1,   -1,   -1,   -1,   -1,   -1,   -1,
      -1,   -1,   -1,   -1,   -1,   -1,   -1,   -1,
      -1,   -1,   -1, 4075,   -1,   -1,   -1,   -1,
      -1,   -1,   -1,   -1,   -1,   -1,   -1,   -1,
      -1,   -1,   -1,   -1,   -1,   -1,   -1, 4076,
      -1,   -1,   -1,   -1,   -1,   -1,   -1,   -1,
      -1,   -1,   -1,   -1,   -1,   -1,   -1,   -1,
      -1,   -1,   -1,   -1,   -1,   -1,   -1,   -1,
      -1,   -1,   -1,   -1,   -1,   -1,   -1,   -1,
    4077,   -1,   -1,   -1,   -1,   -1,   -1,   -1,
    4078,   -1,   -1,   -1,   -1,   -1,   -1,   -1,
      -1,   -1,   -1,   -1,   -1,   -1,   -1,   -1,
      -1,   -1,   -1,   -1,   -1,   -1,   -1,   -1,
      -1,   -1,   -1,   -1,   -1,   -1,   -1,   -1,
      -1,   -1,   -1,   -1,   -1,   -1,   -1,   -1,
      -1,   -1,   -1,   -1,   -1,   -1,   -1,   -1,
    4079,   -1,   -1,   -1,   -1,   -1,   -1,   -1,
      -1,   -1,   -1,   -1,   -1,   -1,   -1,   -1,
      -1,   -1,   -1,   -1,   -1,   -1, 4080, 4081,
      -1,   -1,   -1,   -1,   -1,   -1,   -1,   -1,
      -1,   -1,   -1,   -1,   -1,   -1,   -1,   -1,
      -1,   -1,   -1,   -1,   -1,   -1,   -1,   -1,
      -1,   -1,   -1,   -1, 4082,   -1,   -1,   -1,
      -1,   -1,   -1,   -1,   -1,   -1,   -1,   -1,
      -1,   -1,   -1,   -1,   -1,   -1,   -1,   -1,
      -1,   -1,   -1,   -1,   -1,   -1,   -1,   -1,
      -1,   -1,   -1,   -1,   -1,   -1,   -1,   -1,
      -1,   -1,   -1,   -1,   -1,   -1,   -1,   -1,
      -1,   -1,   -1,   -1,   -1,   -1,   -1,   -1,
      -1,   -1,   -1,   -1,   -1,   -1, 4083,   -1,
      -1,   -1,   -1,   -1,   -1,   -1,   -1,   -1,
      -1,   -1,   -1,   -1,   -1,   -1,   -1,   -1,
      -1, 4084,   -1,   -1,   -1,   -1,   -1,   -1,
    4085,   -1,   -1,   -1,   -1,   -1,   -1,   -1,
      -1,   -1,   -1, 4086,   -1,   -1,   -1,   -1,
      -1,   -1,   -1,   -1,   -1,   -1,   -1, 4087,
      -1,   -1,   -1,   -1,   -1,   -1,   -1,   -1,
      -1,   -1,   -1,   -1,   -1,   -1,   -1,   -1,
      -1,   -1,   -1,   -1,   -1,   -1,   -1,   -1,
      -1,   -1,   -1,   -1,   -1,   -1,   -1,   -1,
      -1,   -1,   -1,   -1,   -1,   -1,   -1,   -1,
      -1,   -1,   -1,   -1,   -1,   -1,   -1,   -1,
      -1,   -1,   -1,   -1,   -1,   -1,   -1,   -1,
      -1,   -1,   -1,   -1,   -1,   -1,   -1,   -1,
      -1,   -1,   -1,   -1,   -1,   -1,   -1,   -1,
      -1,   -1,   -1,   -1,   -1,   -1,   -1,   -1,
      -1,   -1, 4088,   -1,   -1,   -1,   -1,   -1,
      -1,   -1,   -1,   -1,   -1,   -1,   -1,   -1,
      -1,   -1,   -1,   -1,   -1,   -1,   -1,   -1,
      -1, 4089,   -1,   -1,   -1,   -1,   -1,   -1,
      -1,   -1,   -1, 4090,   -1,   -1, 4091,   -1,
      -1,   -1,   -1,   -1,   -1,   -1,   -1,   -1,
      -1,   -1,   -1,   -1,   -1,   -1,   -1,   -1,
      -1,   -1,   -1,   -1,   -1, 4092,   -1, 4093,
      -1,   -1,   -1,   -1,   -1,   -1,   -1,   -1,
      -1,   -1,   -1,   -1,   -1,   -1,   -1,   -1,
      -1,   -1,   -1,   -1,   -1,   -1,   -1,   -1,
      -1,   -1,   -1,   -1,   -1,   -1,   -1,   -1,
    4094,   -1,   -1,   -1,   -1,   -1,   -1,   -1,
      -1,   -1,   -1,   -1,   -1,   -1,   -1,   -1,
      -1,   -1,   -1,   -1,   -1,   -1,   -1,   -1,
      -1,   -1,   -1,   -1,   -1,   -1, 4095,   -1,
      -1,   -1,   -1,   -1,   -1,   -1,   -1,   -1,
      -1,   -1,   -1,   -1,   -1,   -1,   -1,   -1,
      -1,   -1,   -1,   -1,   -1,   -1,   -1,   -1,
      -1,   -1,   -1,   -1,   -1,   -1,   -1,   -1,
      -1,   -1,   -1,   -1,   -1,   -1,   -1,   -1,
      -1,   -1,   -1,   -1,   -1,   -1,   -1,   -1,
      -1,   -1,   -1,   -1,   -1,   -1,   -1,   -1,
      -1,   -1,   -1,   -1,   -1,   -1,   -1,   -1,
      -1,   -1,   -1,   -1,   -1,   -1,   -1,   -1,
      -1,   -1,   -1,   -1,   -1,   -1,   -1,   -1,
    4096,   -1,   -1,   -1,   -1,   -1,   -1,   -1,
      -1,   -1,   -1,   -1,   -1,   -1,   -1,   -1,
      -1,   -1,   -1,   -1,   -1,   -1,   -1, 4097,
      -1,   -1,   -1,   -1,   -1,   -1,   -1,   -1,
      -1,   -1,   -1,   -1,   -1,   -1,   -1,   -1,
      -1,   -1,   -1,   -1,   -1,   -1,   -1,   -1,
      -1,   -1,   -1,   -1,   -1,   -1,   -1,   -1,
      -1,   -1,   -1,   -1,   -1,   -1,   -1,   -1,
      -1,   -1,   -1,   -1,   -1,   -1,   -1,   -1,
      -1,   -1,   -1,   -1,   -1,   -1,   -1,   -1,
      -1,   -1,   -1,   -1,   -1,   -1,   -1,   -1,
      -1,   -1,   -1,   -1,   -1,   -1,   -1,   -1,
      -1,   -1,   -1,   -1,   -1,   -1,   -1,   -1,
      -1,   -1,   -1,   -1,   -1,   -1,   -1,   -1,
      -1,   -1,   -1,   -1,   -1,   -1,   -1,   -1,
      -1,   -1,   -1,   -1,   -1,   -1,   -1,   -1,
      -1,   -1,   -1,   -1,   -1,   -1,   -1,   -1,
      -1,   -1,   -1,   -1,   -1,   -1,   -1,   -1,
      -1,   -1,   -1,   -1,   -1,   -1,   -1,   -1,
      -1,   -1, 4098,   -1,   -1,   -1,   -1,   -1,
      -1,   -1,   -1,   -1,   -1,   -1,   -1,   -1,
      -1,   -1,   -1,   -1,   -1,   -1, 4099,   -1,
      -1,   -1,   -1,   -1,   -1,   -1,   -1,   -1,
      -1,   -1,   -1,   -1,   -1,   -1,   -1,   -1,
      -1,   -1,   -1,   -1,   -1,   -1,   -1,   -1,
      -1,   -1,   -1,   -1,   -1,   -1, 4100,   -1,
      -1,   -1,   -1,   -1,   -1,   -1,   -1,   -1,
      -1,   -1,   -1,   -1,   -1,   -1,   -1,   -1,
      -1,   -1,   -1,   -1,   -1,   -1,   -1,   -1,
      -1,   -1,   -1,   -1,   -1,   -1,   -1,   -1,
      -1,   -1,   -1,   -1,   -1,   -1,   -1,   -1,
      -1,   -1,   -1,   -1,   -1,   -1,   -1,   -1,
      -1,   -1,   -1,   -1,   -1,   -1,   -1,   -1,
      -1,   -1,   -1,   -1,   -1,   -1,   -1,   -1,
      -1,   -1,   -1,   -1, 4101,   -1,   -1,   -1,
      -1,   -1, 4102,   -1,   -1,   -1,   -1,   -1,
      -1,   -1,   -1,   -1,   -1,   -1,   -1,   -1,
    4103,   -1,   -1,   -1,   -1,   -1,   -1,   -1,
      -1, 4104,   -1,   -1,   -1,   -1, 4105,   -1,
      -1,   -1,   -1,   -1,   -1,   -1,   -1,   -1,
      -1,   -1,   -1, 4106,   -1,   -1,   -1,   -1,
      -1,   -1,   -1,   -1,   -1,   -1,   -1,   -1,
      -1,   -1,   -1,   -1,   -1,   -1,   -1,   -1,
      -1,   -1,   -1,   -1,   -1,   -1,   -1,   -1,
      -1,   -1,   -1,   -1,   -1,   -1,   -1,   -1,
      -1,   -1,   -1,   -1,   -1,   -1,   -1,   -1,
      -1, 4107,   -1,   -1,   -1,   -1,   -1,   -1,
      -1,   -1,   -1,   -1,   -1,   -1,   -1,   -1,
      -1,   -1,   -1,   -1,   -1,   -1,   -1,   -1,
      -1,   -1,   -1,   -1,   -1,   -1,   -1,   -1,
      -1,   -1,   -1,   -1,   -1,   -1,   -1,   -1,
      -1,   -1,   -1,   -1,   -1,   -1,   -1,   -1,
      -1,   -1,   -1,   -1,   -1,   -1,   -1,   -1,
      -1,   -1,   -1,   -1,   -1,   -1,   -1,   -1,
      -1,   -1,   -1,   -1,   -1,   -1,   -1,   -1,
      -1,   -1,   -1,   -1,   -1,   -1,   -1,   -1,
      -1,   -1,   -1,   -1,   -1,   -1,   -1,   -1,
      -1,   -1,   -1,   -1,   -1,   -1,   -1,   -1,
      -1,   -1,   -1,   -1,   -1,   -1,   -1,   -1,
      -1, 4108,   -1,   -1,   -1,   -1,   -1,   -1,
      -1,   -1,   -1,   -1,   -1,   -1,   -1,   -1,
      -1,   -1,   -1,   -1,   -1,   -1,   -1,   -1,
      -1,   -1,   -1,   -1,   -1,   -1,   -1,   -1,
      -1,   -1,   -1,   -1,   -1,   -1,   -1,   -1,
      -1,   -1,   -1,   -1,   -1,   -1,   -1,   -1,
      -1,   -1,   -1,   -1,   -1,   -1,   -1,   -1,
      -1,   -1,   -1,   -1,   -1,   -1,   -1,   -1,
      -1,   -1,   -1,   -1,   -1,   -1,   -1,   -1,
      -1,   -1,   -1,   -1,   -1,   -1,   -1,   -1,
      -1,   -1,   -1,   -1,   -1,   -1,   -1,   -1,
      -1,   -1,   -1,   -1,   -1,   -1,   -1,   -1,
      -1,   -1,   -1,   -1,   -1,   -1,   -1,   -1,
    4109,   -1,   -1,   -1,   -1,   -1,   -1,   -1,
      -1,   -1,   -1,   -1, 4110,   -1,   -1,   -1,
      -1,   -1,   -1,   -1, 4111, 4112,   -1,   -1,
      -1,   -1,   -1,   -1,   -1,   -1,   -1,   -1,
      -1,   -1,   -1, 4113,   -1,   -1,   -1,   -1,
      -1,   -1,   -1,   -1,   -1,   -1,   -1,   -1,
      -1,   -1,   -1,   -1,   -1,   -1,   -1,   -1,
      -1,   -1,   -1,   -1,   -1,   -1,   -1,   -1,
      -1,   -1,   -1,   -1,   -1, 4114, 4115,   -1,
      -1,   -1,   -1,   -1,   -1,   -1,   -1,   -1,
      -1,   -1,   -1,   -1,   -1,   -1,   -1,   -1,
      -1,   -1,   -1,   -1,   -1,   -1,   -1,   -1,
      -1,   -1,   -1,   -1,   -1,   -1,   -1,   -1,
      -1,   -1,   -1,   -1,   -1,   -1,   -1,   -1,
      -1,   -1,   -1,   -1,   -1,   -1,   -1,   -1,
      -1,   -1, 4116,   -1,   -1,   -1,   -1,   -1,
      -1,   -1,   -1,   -1,   -1,   -1,   -1,   -1,
      -1,   -1,   -1,   -1,   -1,   -1,   -1,   -1,
      -1,   -1,   -1,   -1,   -1,   -1,   -1,   -1,
      -1,   -1,   -1,   -1,   -1,   -1,   -1,   -1,
      -1,   -1,   -1,   -1,   -1,   -1,   -1,   -1,
      -1,   -1,   -1,   -1,   -1,   -1,   -1,   -1,
      -1,   -1,   -1,   -1,   -1,   -1,   -1,   -1,
      -1,   -1,   -1,   -1,   -1,   -1,   -1,   -1,
      -1,   -1,   -1,   -1,   -1,   -1,   -1,   -1,
      -1,   -1, 4117, 4118,   -1,   -1,   -1,   -1,
      -1,   -1,   -1,   -1,   -1,   -1,   -1,   -1,
      -1,   -1,   -1,   -1,   -1,   -1, 4119,   -1,
      -1,   -1,   -1,   -1,   -1,   -1,   -1,   -1,
      -1,   -1,   -1,   -1,   -1,   -1,   -1,   -1,
      -1,   -1,   -1, 4120,   -1,   -1,   -1,   -1,
      -1,   -1,   -1,   -1,   -1,   -1,   -1,   -1,
      -1,   -1,   -1,   -1,   -1,   -1,   -1,   -1,
      -1,   -1,   -1,   -1,   -1,   -1,   -1,   -1,
      -1,   -1,   -1,   -1,   -1,   -1,   -1,   -1,
      -1,   -1,   -1,   -1,   -1,   -1,   -1,   -1,
      -1,   -1,   -1,   -1,   -1,   -1,   -1,   -1,
      -1,   -1,   -1,   -1,   -1,   -1,   -1,   -1,
      -1,   -1,   -1,   -1,   -1,   -1,   -1,   -1,
      -1,   -1,   -1,   -1,   -1,   -1,   -1,   -1,
      -1,   -1,   -1,   -1,   -1,   -1,   -1,   -1,
      -1,   -1,   -1,   -1,   -1,   -1,   -1,   -1,
      -1,   -1,   -1,   -1,   -1,   -1,   -1,   -1,
      -1,   -1,   -1,   -1,   -1,   -1,   -1,   -1,
      -1,   -1,   -1,   -1,   -1,   -1,   -1,   -1,
      -1,   -1,   -1,   -1,   -1,   -1,   -1,   -1,
      -1,   -1,   -1,   -1,   -1,   -1, 4121,   -1,
      -1, 4122, 4123, 4124,   -1,   -1,   -1,   -1,
      -1,   -1,   -1,   -1,   -1,   -1,   -1,   -1,
      -1,   -1,   -1,   -1,   -1,   -1,   -1,   -1,
      -1,   -1,   -1,   -1,   -1,   -1,   -1,   -1,
      -1,   -1,   -1,   -1,   -1,   -1,   -1,   -1,
      -1,   -1,   -1,   -1,   -1,   -1,   -1,   -1,
      -1,   -1,   -1,   -1,   -1,   -1,   -1,   -1,
      -1,   -1,   -1,   -1,   -1,   -1,   -1,   -1,
      -1,   -1,   -1,   -1,   -1,   -1,   -1,   -1,
      -1,   -1,   -1,   -1,   -1,   -1,   -1,   -1,
      -1, 4125,   -1,   -1,   -1,   -1,   -1,   -1,
      -1,   -1,   -1,   -1,   -1,   -1, 4126,   -1,
      -1,   -1,   -1,   -1,   -1,   -1,   -1,   -1,
      -1,   -1,   -1,   -1,   -1,   -1,   -1,   -1,
      -1,   -1,   -1,   -1,   -1,   -1,   -1,   -1,
      -1,   -1,   -1,   -1,   -1,   -1,   -1,   -1,
      -1,   -1,   -1,   -1,   -1,   -1,   -1,   -1,
      -1,   -1,   -1,   -1,   -1,   -1,   -1,   -1,
    4127,   -1,   -1,   -1,   -1,   -1,   -1,   -1,
    4128,   -1,   -1,   -1,   -1,   -1,   -1,   -1,
      -1,   -1,   -1,   -1,   -1,   -1,   -1,   -1,
      -1,   -1,   -1,   -1,   -1,   -1, 4129,   -1,
      -1,   -1,   -1,   -1,   -1,   -1,   -1,   -1,
      -1,   -1,   -1,   -1,   -1,   -1,   -1,   -1,
      -1,   -1,   -1,   -1,   -1,   -1,   -1,   -1,
      -1,   -1,   -1,   -1,   -1,   -1,   -1,   -1,
      -1,   -1,   -1,   -1,   -1,   -1,   -1,   -1,
      -1,   -1,   -1,   -1,   -1,   -1,   -1, 4130,
      -1,   -1,   -1,   -1,   -1,   -1,   -1,   -1,
      -1,   -1,   -1,   -1,   -1,   -1,   -1,   -1,
      -1,   -1,   -1,   -1,   -1,   -1,   -1,   -1,
      -1,   -1,   -1,   -1,   -1,   -1,   -1,   -1,
      -1,   -1,   -1,   -1,   -1,   -1,   -1,   -1,
      -1,   -1,   -1,   -1,   -1,   -1,   -1,   -1,
      -1,   -1,   -1,   -1,   -1,   -1,   -1,   -1,
      -1,   -1,   -1,   -1,   -1,   -1,   -1,   -1,
      -1,   -1,   -1,   -1,   -1,   -1,   -1,   -1,
      -1,   -1,   -1,   -1,   -1,   -1,   -1,   -1,
      -1,   -1,   -1,   -1,   -1,   -1,   -1,   -1,
      -1,   -1,   -1,   -1,   -1,   -1,   -1,   -1,
      -1,   -1,   -1,   -1,   -1,   -1, 4131,   -1,
      -1,   -1,   -1,   -1,   -1,   -1,   -1, 4132,
      -1,   -1,   -1,   -1,   -1,   -1,   -1,   -1,
      -1,   -1,   -1,   -1,   -1,   -1,   -1,   -1,
      -1,   -1,   -1,   -1,   -1,   -1,   -1,   -1,
      -1,   -1,   -1,   -1,   -1,   -1,   -1,   -1,
      -1,   -1,   -1,   -1,   -1,   -1,   -1,   -1,
      -1,   -1,   -1,   -1,   -1,   -1,   -1,   -1,
      -1,   -1,   -1,   -1,   -1,   -1,   -1,   -1,
      -1,   -1,   -1,   -1,   -1,   -1,   -1,   -1,
      -1,   -1,   -1,   -1,   -1,   -1,   -1,   -1,
      -1,   -1,   -1,   -1,   -1,   -1,   -1,   -1,
      -1, 4133,   -1,   -1,   -1,   -1,   -1,   -1,
      -1,   -1,   -1,   -1,   -1,   -1,   -1,   -1,
      -1,   -1,   -1,   -1,   -1,   -1,   -1,   -1,
      -1,   -1,   -1,   -1,   -1,   -1,   -1,   -1,
      -1,   -1,   -1,   -1,   -1,   -1,   -1,   -1,
      -1,   -1,   -1,   -1,   -1,   -1,   -1,   -1,
      -1,   -1,   -1,   -1,   -1,   -1,   -1,   -1,
      -1,   -1,   -1,   -1,   -1,   -1,   -1,   -1,
      -1,   -1,   -1,   -1,   -1,   -1,   -1,   -1,
      -1,   -1,   -1,   -1,   -1,   -1,   -1,   -1,
      -1,   -1,   -1,   -1,   -1, 4134,   -1,   -1,
      -1,   -1,   -1,   -1,   -1,   -1,   -1,   -1,
      -1,   -1,   -1,   -1,   -1,   -1,   -1,   -1,
      -1,   -1,   -1,   -1,   -1,   -1,   -1,   -1,
      -1,   -1,   -1,   -1,   -1,   -1,   -1,   -1,
      -1,   -1,   -1,   -1,   -1,   -1,   -1,   -1,
      -1,   -1,   -1,   -1,   -1,   -1,   -1,   -1,
      -1,   -1,   -1,   -1,   -1,   -1,   -1,   -1,
      -1,   -1,   -1,   -1,   -1,   -1,   -1,   -1,
      -1,   -1,   -1,   -1,   -1,   -1,   -1,   -1,
      -1,   -1,   -1,   -1,   -1,   -1,   -1,   -1,
      -1,   -1,   -1,   -1,   -1,   -1,   -1,   -1,
      -1,   -1,   -1,   -1,   -1,   -1,   -1, 4135,
      -1,   -1,   -1,   -1,   -1,   -1,   -1,   -1,
      -1,   -1,   -1,   -1,   -1,   -1,   -1,   -1,
      -1,   -1,   -1,   -1,   -1,   -1,   -1,   -1,
      -1,   -1,   -1,   -1,   -1,   -1,   -1,   -1,
      -1,   -1,   -1,   -1,   -1,   -1,   -1,   -1,
      -1,   -1,   -1,   -1,   -1,   -1,   -1,   -1,
      -1,   -1,   -1,   -1,   -1,   -1,   -1,   -1,
      -1,   -1,   -1,   -1,   -1,   -1,   -1,   -1,
      -1,   -1,   -1,   -1,   -1,   -1,   -1,   -1,
      -1,   -1,   -1,   -1,   -1,   -1,   -1,   -1,
      -1,   -1,   -1,   -1,   -1,   -1,   -1,   -1,
      -1,   -1,   -1,   -1, 4136, 4137,   -1,   -1,
      -1,   -1,   -1,   -1,   -1,   -1,   -1, 4138,
      -1,   -1,   -1,   -1,   -1,   -1,   -1,   -1,
      -1,   -1,   -1,   -1,   -1,   -1,   -1, 4139,
      -1,   -1,   -1,   -1,   -1,   -1,   -1,   -1,
      -1,   -1,   -1, 4140,   -1,   -1,   -1,   -1,
      -1,   -1,   -1,   -1,   -1,   -1, 4141,   -1,
      -1,   -1,   -1,   -1,   -1,   -1,   -1,   -1,
      -1,   -1,   -1,   -1,   -1,   -1,   -1,   -1,
      -1,   -1,   -1,   -1,   -1,   -1,   -1,   -1,
      -1,   -1,   -1,   -1,   -1,   -1,   -1,   -1,
      -1,   -1,   -1,   -1,   -1,   -1,   -1,   -1,
      -1,   -1,   -1,   -1,   -1,   -1,   -1,   -1,
      -1,   -1,   -1,   -1,   -1,   -1,   -1,   -1,
      -1,   -1,   -1,   -1,   -1,   -1,   -1,   -1,
      -1,   -1,   -1,   -1,   -1,   -1, 4142,   -1,
      -1,   -1,   -1,   -1,   -1,   -1,   -1,   -1,
      -1,   -1,   -1,   -1,   -1,   -1,   -1,   -1,
      -1,   -1,   -1,   -1,   -1,   -1,   -1,   -1,
      -1,   -1,   -1,   -1,   -1,   -1,   -1,   -1,
      -1,   -1,   -1,   -1,   -1,   -1, 4143,   -1,
      -1,   -1,   -1,   -1,   -1,   -1,   -1,   -1,
      -1,   -1,   -1,   -1,   -1,   -1,   -1,   -1,
      -1,   -1,   -1,   -1,   -1,   -1,   -1,   -1,
      -1,   -1,   -1,   -1,   -1,   -1,   -1,   -1,
      -1,   -1,   -1,   -1,   -1,   -1,   -1,   -1,
      -1,   -1,   -1,   -1,   -1,   -1,   -1,   -1,
      -1,   -1,   -1,   -1,   -1,   -1,   -1,   -1,
      -1,   -1,   -1,   -1,   -1,   -1,   -1,   -1,
      -1,   -1,   -1,   -1,   -1,   -1,   -1,   -1,
      -1,   -1,   -1,   -1,   -1,   -1,   -1,   -1,
      -1,   -1,   -1,   -1,   -1,   -1,   -1, 4144,
      -1,   -1,   -1,   -1,   -1,   -1,   -1,   -1,
      -1,   -1,   -1,   -1,   -1,   -1,   -1,   -1,
      -1,   -1,   -1,   -1,   -1,   -1,   -1,   -1,
      -1,   -1,   -1,   -1,   -1,   -1,   -1,   -1,
      -1,   -1,   -1,   -1,   -1,   -1,   -1,   -1,
      -1,   -1,   -1,   -1,   -1,   -1,   -1,   -1,
      -1,   -1,   -1,   -1,   -1, 4145, 4146,   -1,
    4147, 4148,   -1,   -1,   -1,   -1,   -1,   -1,
      -1,   -1,   -1,   -1,   -1,   -1,   -1,   -1,
      -1,   -1,   -1,   -1,   -1,   -1,   -1,   -1,
      -1,   -1,   -1,   -1,   -1,   -1,   -1,   -1,
      -1,   -1,   -1,   -1,   -1,   -1,   -1,   -1,
      -1,   -1,   -1,   -1,   -1,   -1,   -1,   -1,
      -1,   -1,   -1,   -1,   -1,   -1,   -1,   -1,
      -1,   -1,   -1,   -1,   -1,   -1,   -1,   -1,
      -1,   -1,   -1,   -1,   -1,   -1,   -1,   -1,
      -1,   -1,   -1,   -1,   -1,   -1,   -1,   -1,
      -1,   -1,   -1, 4149,   -1,   -1,   -1,   -1,
      -1,   -1,   -1,   -1,   -1,   -1,   -1,   -1,
      -1,   -1,   -1,   -1,   -1,   -1,   -1, 4150,
      -1,   -1,   -1,   -1,   -1,   -1,   -1,   -1,
      -1,   -1,   -1,   -1,   -1,   -1,   -1,   -1,
      -1,   -1,   -1,   -1,   -1,   -1,   -1,   -1,
      -1,   -1,   -1,   -1, 4151,   -1,   -1,   -1,
      -1,   -1,   -1,   -1,   -1,   -1,   -1,   -1,
      -1,   -1,   -1,   -1,   -1,   -1,   -1,   -1,
      -1,   -1,   -1,   -1,   -1,   -1,   -1,   -1,
      -1,   -1,   -1,   -1,   -1,   -1,   -1,   -1,
      -1,   -1,   -1,   -1,   -1,   -1,   -1,   -1,
      -1,   -1,   -1,   -1,   -1,   -1,   -1,   -1,
      -1,   -1,   -1,   -1,   -1,   -1,   -1,   -1,
      -1,   -1,   -1,   -1,   -1,   -1,   -1,   -1,
      -1,   -1,   -1,   -1,   -1,   -1,   -1,   -1,
      -1,   -1,   -1,   -1,   -1,   -1,   -1,   -1,
      -1,   -1,   -1,   -1,   -1,   -1,   -1,   -1,
      -1,   -1,   -1,   -1,   -1,   -1,   -1,   -1,
      -1,   -1,   -1,   -1,   -1,   -1,   -1,   -1,
      -1,   -1,   -1,   -1,   -1,   -1,   -1,   -1,
      -1,   -1,   -1,   -1,   -1,   -1,   -1,   -1,
      -1,   -1,   -1,   -1,   -1,   -1,   -1,   -1,
      -1,   -1,   -1,   -1,   -1,   -1,   -1,   -1,
      -1,   -1,   -1,   -1,   -1,   -1,   -1,   -1,
      -1,   -1,   -1,   -1,   -1,   -1,   -1,   -1,
      -1,   -1,   -1,   -1,   -1,   -1,   -1,   -1,
      -1,   -1,   -1,   -1,   -1,   -1,   -1,   -1,
      -1,   -1,   -1,   -1,   -1,   -1,   -1,   -1,
      -1,   -1,   -1,   -1,   -1,   -1,   -1,   -1,
      -1,   -1,   -1,   -1,   -1,   -1,   -1,   -1,
      -1,   -1,   -1,   -1,   -1,   -1,   -1,   -1,
      -1,   -1,   -1,   -1,   -1,   -1,   -1,   -1,
      -1,   -1,   -1,   -1,   -1,   -1,   -1,   -1,
      -1,   -1,   -1,   -1,   -1,   -1,   -1,   -1,
      -1,   -1,   -1,   -1,   -1,   -1,   -1,   -1,
      -1,   -1,   -1,   -1,   -1,   -1,   -1,   -1,
      -1,   -1,   -1,   -1,   -1,   -1,   -1,   -1,
      -1,   -1,   -1,   -1,   -1,   -1,   -1,   -1,
      -1,   -1,   -1,   -1,   -1,   -1,   -1,   -1,
      -1,   -1,   -1,   -1,   -1,   -1,   -1,   -1,
      -1,   -1,   -1,   -1,   -1,   -1,   -1,   -1,
      -1,   -1,   -1, 4152,   -1,   -1,   -1,   -1,
      -1,   -1,   -1,   -1,   -1,   -1,   -1,   -1,
      -1,   -1,   -1,   -1,   -1,   -1,   -1,   -1,
      -1,   -1,   -1,   -1,   -1,   -1,   -1,   -1,
      -1,   -1,   -1,   -1,   -1,   -1,   -1,   -1,
      -1,   -1,   -1,   -1,   -1,   -1,   -1,   -1,
      -1,   -1,   -1,   -1,   -1,   -1,   -1,   -1,
      -1,   -1,   -1,   -1,   -1,   -1,   -1,   -1,
      -1,   -1,   -1,   -1,   -1,   -1,   -1,   -1,
      -1,   -1,   -1,   -1,   -1,   -1,   -1,   -1,
      -1, 4153,   -1,   -1,   -1,   -1,   -1,   -1,
      -1,   -1,   -1,   -1,   -1,   -1,   -1,   -1,
      -1,   -1,   -1,   -1,   -1,   -1,   -1,   -1,
      -1,   -1,   -1,   -1,   -1,   -1,   -1,   -1,
      -1,   -1,   -1,   -1,   -1,   -1,   -1,   -1,
      -1,   -1,   -1,   -1,   -1,   -1,   -1,   -1,
      -1,   -1,   -1,   -1,   -1,   -1,   -1,   -1,
      -1,   -1,   -1,   -1,   -1,   -1,   -1,   -1,
      -1,   -1,   -1,   -1,   -1,   -1,   -1,   -1,
      -1,   -1,   -1,   -1,   -1,   -1,   -1,   -1,
      -1,   -1,   -1,   -1,   -1,   -1,   -1,   -1,
      -1,   -1,   -1,   -1,   -1,   -1,   -1,   -1,
      -1,   -1,   -1,   -1,   -1,   -1,   -1,   -1,
      -1,   -1,   -1,   -1, 4154,   -1,   -1,   -1,
      -1,   -1,   -1,   -1,   -1,   -1,   -1,   -1,
      -1,   -1,   -1,   -1,   -1,   -1,   -1,   -1,
      -1,   -1,   -1,   -1,   -1,   -1,   -1,   -1,
      -1,   -1,   -1,   -1,   -1,   -1,   -1,   -1,
      -1,   -1,   -1,   -1,   -1,   -1,   -1,   -1,
      -1,   -1,   -1,   -1,   -1,   -1,   -1,   -1,
      -1,   -1,   -1,   -1,   -1,   -1,   -1,   -1,
      -1,   -1,   -1,   -1,   -1,   -1,   -1,   -1,
      -1,   -1,   -1,   -1,   -1,   -1,   -1,   -1,
    4155,   -1,   -1,   -1,   -1,   -1,   -1,   -1,
      -1,   -1,   -1,   -1,   -1,   -1,   -1,   -1,
      -1,   -1,   -1,   -1,   -1,   -1,   -1,   -1,
      -1,   -1,   -1,   -1,   -1,   -1,   -1,   -1,
      -1,   -1,   -1,   -1,   -1,   -1,   -1,   -1,
      -1,   -1,   -1,   -1,   -1,   -1,   -1,   -1,
      -1,   -1,   -1,   -1,   -1,   -1,   -1,   -1,
      -1,   -1,   -1,   -1,   -1,   -1,   -1,   -1,
      -1,   -1,   -1,   -1,   -1,   -1,   -1,   -1,
      -1,   -1,   -1,   -1,   -1,   -1,   -1,   -1,
      -1,   -1,   -1,   -1,   -1,   -1, 4156,   -1,
      -1,   -1,   -1,   -1,   -1,   -1,   -1,   -1,
      -1,   -1,   -1,   -1,   -1,   -1,   -1,   -1,
      -1,   -1,   -1,   -1,   -1,   -1,   -1,   -1,
      -1,   -1,   -1,   -1,   -1,   -1,   -1,   -1,
      -1,   -1,   -1,   -1,   -1,   -1,   -1,   -1,
      -1,   -1,   -1,   -1,   -1,   -1,   -1,   -1,
      -1,   -1,   -1,   -1,   -1,   -1,   -1,   -1,
      -1,   -1,   -1,   -1,   -1,   -1,   -1,   -1,
      -1,   -1,   -1,   -1,   -1,   -1,   -1,   -1,
      -1,   -1,   -1,   -1,   -1,   -1,   -1,   -1,
      -1,   -1,   -1,   -1,   -1,   -1,   -1,   -1,
      -1,   -1,   -1,   -1,   -1,   -1,   -1,   -1,
      -1,   -1,   -1,   -1,   -1,   -1,   -1,   -1,
      -1,   -1,   -1,   -1,   -1,   -1,   -1,   -1,
      -1,   -1,   -1,   -1,   -1,   -1,   -1,   -1,
      -1,   -1,   -1,   -1,   -1,   -1,   -1,   -1,
      -1,   -1,   -1,   -1,   -1,   -1,   -1,   -1,
      -1,   -1,   -1,   -1,   -1,   -1,   -1,   -1,
      -1,   -1,   -1,   -1,   -1,   -1,   -1,   -1,
      -1,   -1,   -1,   -1,   -1,   -1,   -1,   -1,
      -1,   -1,   -1,   -1,   -1,   -1,   -1,   -1,
      -1,   -1,   -1,   -1,   -1,   -1,   -1,   -1,
      -1,   -1,   -1,   -1,   -1,   -1,   -1,   -1,
      -1,   -1,   -1,   -1,   -1,   -1,   -1,   -1,
      -1,   -1,   -1,   -1,   -1,   -1, 4157,   -1,
    4158,   -1,   -1,   -1,   -1,   -1,   -1,   -1,
      -1,   -1,   -1,   -1,   -1,   -1,   -1,   -1,
      -1,   -1,   -1,   -1,   -1,   -1,   -1,   -1,
      -1,   -1,   -1,   -1,   -1,   -1,   -1,   -1,
      -1,   -1,   -1,   -1,   -1,   -1,   -1,   -1,
      -1,   -1,   -1,   -1,   -1,   -1,   -1,   -1,
      -1,   -1,   -1,   -1,   -1,   -1,   -1,   -1,
      -1,   -1,   -1,   -1,   -1,   -1,   -1,   -1,
      -1,   -1,   -1,   -1,   -1,   -1,   -1,   -1,
      -1,   -1,   -1,   -1,   -1,   -1,   -1,   -1,
      -1,   -1,   -1,   -1,   -1,   -1,   -1,   -1,
      -1,   -1,   -1,   -1,   -1,   -1,   -1, 4159,
      -1,   -1,   -1,   -1,   -1,   -1,   -1,   -1,
      -1,   -1,   -1,   -1,   -1,   -1,   -1,   -1,
      -1,   -1,   -1,   -1,   -1,   -1,   -1,   -1,
      -1,   -1,   -1,   -1,   -1,   -1,   -1,   -1,
      -1,   -1,   -1,   -1,   -1,   -1,   -1,   -1,
      -1,   -1,   -1,   -1,   -1,   -1,   -1,   -1,
      -1,   -1,   -1,   -1,   -1,   -1,   -1,   -1,
      -1,   -1,   -1,   -1,   -1,   -1,   -1,   -1,
      -1,   -1,   -1,   -1,   -1,   -1,   -1,   -1,
      -1,   -1,   -1,   -1,   -1,   -1,   -1,   -1,
      -1,   -1,   -1,   -1,   -1,   -1,   -1,   -1,
      -1,   -1,   -1,   -1,   -1,   -1,   -1,   -1,
      -1,   -1,   -1,   -1,   -1,   -1,   -1,   -1,
      -1,   -1,   -1,   -1,   -1,   -1,   -1,   -1,
      -1,   -1,   -1,   -1,   -1,   -1,   -1,   -1,
      -1,   -1,   -1,   -1,   -1,   -1,   -1,   -1,
      -1,   -1,   -1,   -1,   -1,   -1,   -1,   -1,
      -1,   -1,   -1,   -1,   -1,   -1,   -1,   -1,
      -1,   -1,   -1,   -1,   -1,   -1,   -1,   -1,
      -1,   -1,   -1,   -1,   -1,   -1,   -1,   -1,
      -1,   -1,   -1,   -1,   -1,   -1,   -1,   -1,
      -1,   -1,   -1,   -1,   -1,   -1,   -1,   -1,
      -1,   -1,   -1,   -1,   -1,   -1,   -1,   -1,
      -1,   -1,   -1,   -1,   -1,   -1,   -1,   -1,
      -1,   -1,   -1,   -1,   -1,   -1,   -1,   -1,
      -1,   -1,   -1,   -1,   -1,   -1,   -1,   -1,
      -1,   -1,   -1,   -1,   -1,   -1,   -1,   -1,
      -1,   -1,   -1,   -1,   -1,   -1,   -1,   -1,
      -1,   -1,   -1,   -1,   -1,   -1,   -1,   -1,
      -1,   -1,   -1,   -1,   -1,   -1,   -1,   -1,
      -1,   -1,   -1,   -1,   -1,   -1,   -1,   -1,
      -1,   -1,   -1,   -1,   -1,   -1,   -1,   -1,
      -1,   -1,   -1,   -1,   -1,   -1,   -1,   -1,
      -1,   -1,   -1,   -1,   -1,   -1,   -1,   -1,
      -1,   -1,   -1,   -1,   -1,   -1,   -1,   -1,
      -1,   -1,   -1,   -1,   -1,   -1,   -1,   -1,
      -1,   -1,   -1,   -1,   -1,   -1,   -1,   -1,
      -1,   -1,   -1,   -1,   -1,   -1,   -1,   -1,
      -1,   -1,   -1,   -1,   -1,   -1,   -1,   -1,
      -1,   -1,   -1,   -1,   -1,   -1,   -1,   -1,
      -1,   -1,   -1,   -1,   -1,   -1,   -1,   -1,
      -1,   -1,   -1,   -1,   -1,   -1,   -1,   -1,
      -1,   -1,   -1,   -1,   -1,   -1,   -1,   -1,
      -1,   -1,   -1,   -1,   -1,   -1,   -1,   -1,
      -1,   -1,   -1,   -1,   -1,   -1,   -1,   -1,
      -1,   -1,   -1,   -1,   -1,   -1,   -1,   -1,
      -1,   -1,   -1,   -1,   -1,   -1,   -1,   -1,
      -1,   -1,   -1,   -1,   -1,   -1,   -1,   -1,
      -1,   -1,   -1,   -1,   -1,   -1,   -1,   -1,
      -1,   -1, 4160,   -1,   -1,   -1,   -1,   -1,
      -1,   -1,   -1,   -1,   -1,   -1,   -1,   -1,
      -1,   -1,   -1,   -1,   -1,   -1,   -1,   -1,
      -1,   -1,   -1,   -1,   -1,   -1,   -1,   -1,
      -1,   -1,   -1,   -1,   -1,   -1,   -1,   -1,
      -1,   -1,   -1,   -1,   -1,   -1,   -1,   -1,
    4161,   -1,   -1,   -1,   -1,   -1,   -1,   -1,
      -1,   -1,   -1,   -1,   -1,   -1,   -1,   -1,
      -1,   -1,   -1,   -1,   -1,   -1,   -1,   -1,
      -1,   -1,   -1,   -1,   -1,   -1,   -1,   -1,
      -1,   -1,   -1,   -1, 4162,   -1,   -1,   -1,
      -1,   -1,   -1,   -1,   -1,   -1,   -1,   -1,
      -1,   -1,   -1,   -1,   -1,   -1,   -1,   -1,
      -1,   -1,   -1,   -1,   -1,   -1,   -1,   -1,
      -1,   -1,   -1,   -1,   -1,   -1,   -1,   -1,
      -1,   -1,   -1,   -1,   -1,   -1,   -1,   -1,
      -1,   -1,   -1,   -1, 4163,   -1,   -1,   -1,
      -1,   -1,   -1,   -1,   -1,   -1,   -1,   -1,
      -1,   -1,   -1,   -1,   -1,   -1,   -1,   -1,
      -1,   -1,   -1,   -1,   -1,   -1,   -1,   -1,
      -1,   -1,   -1,   -1,   -1,   -1,   -1,   -1,
      -1,   -1,   -1,   -1,   -1,   -1,   -1,   -1,
      -1,   -1,   -1,   -1,   -1, 4164,   -1,   -1,
      -1,   -1,   -1,   -1, 4165,   -1,   -1,   -1,
      -1,   -1,   -1,   -1,   -1,   -1,   -1,   -1,
      -1,   -1,   -1,   -1,   -1,   -1,   -1,   -1,
      -1,   -1,   -1,   -1,   -1,   -1,   -1,   -1,
      -1,   -1,   -1,   -1,   -1,   -1,   -1,   -1,
      -1,   -1,   -1,   -1,   -1,   -1,   -1,   -1,
      -1,   -1,   -1,   -1,   -1,   -1,   -1,   -1,
      -1,   -1,   -1,   -1,   -1,   -1,   -1,   -1,
      -1,   -1,   -1,   -1,   -1,   -1,   -1,   -1,
      -1,   -1,   -1,   -1,   -1,   -1,   -1,   -1,
      -1,   -1,   -1,   -1,   -1,   -1,   -1,   -1,
      -1,   -1,   -1,   -1,   -1,   -1,   -1,   -1,
      -1,   -1,   -1,   -1,   -1,   -1,   -1,   -1,
      -1,   -1,   -1,   -1,   -1,   -1,   -1,   -1,
      -1,   -1,   -1,   -1,   -1,   -1,   -1,   -1,
      -1,   -1,   -1,   -1,   -1,   -1,   -1,   -1,
      -1,   -1,   -1,   -1,   -1,   -1,   -1,   -1,
      -1,   -1,   -1,   -1,   -1,   -1,   -1,   -1,
      -1,   -1,   -1,   -1,   -1,   -1,   -1,   -1,
      -1,   -1,   -1,   -1,   -1,   -1,   -1,   -1,
      -1,   -1,   -1,   -1,   -1,   -1,   -1,   -1,
      -1,   -1,   -1,   -1,   -1,   -1,   -1,   -1,
      -1,   -1,   -1,   -1,   -1,   -1,   -1,   -1,
      -1,   -1,   -1,   -1,   -1,   -1,   -1,   -1,
      -1,   -1,   -1,   -1,   -1,   -1,   -1,   -1,
      -1,   -1,   -1,   -1,   -1,   -1,   -1,   -1,
      -1, 4166,   -1,   -1,   -1, 4167,   -1,   -1,
      -1,   -1,   -1,   -1, 4168,   -1,   -1,   -1,
      -1,   -1,   -1,   -1,   -1,   -1,   -1,   -1,
      -1,   -1,   -1,   -1,   -1,   -1,   -1,   -1,
      -1,   -1,   -1,   -1,   -1,   -1,   -1,   -1,
      -1,   -1,   -1,   -1,   -1,   -1,   -1,   -1,
      -1,   -1,   -1,   -1,   -1,   -1,   -1,   -1,
      -1,   -1,   -1,   -1,   -1,   -1,   -1,   -1,
      -1,   -1,   -1,   -1,   -1,   -1,   -1,   -1,
      -1,   -1,   -1,   -1,   -1,   -1,   -1,   -1,
      -1,   -1,   -1,   -1,   -1,   -1,   -1,   -1,
      -1,   -1,   -1,   -1,   -1,   -1,   -1, 4169,
      -1,   -1,   -1,   -1,   -1,   -1,   -1,   -1,
      -1,   -1,   -1,   -1,   -1,   -1,   -1,   -1,
      -1,   -1,   -1,   -1,   -1,   -1,   -1,   -1,
      -1,   -1,   -1,   -1,   -1,   -1,   -1,   -1,
      -1,   -1,   -1,   -1,   -1,   -1,   -1,   -1,
      -1,   -1,   -1,   -1,   -1,   -1,   -1,   -1,
      -1,   -1,   -1,   -1,   -1,   -1,   -1,   -1,
      -1,   -1,   -1,   -1,   -1,   -1,   -1,   -1,
      -1,   -1,   -1,   -1,   -1,   -1,   -1,   -1,
      -1,   -1,   -1,   -1,   -1,   -1,   -1,   -1,
      -1,   -1,   -1,   -1,   -1,   -1,   -1,   -1,
      -1,   -1,   -1,   -1,   -1,   -1,   -1,   -1,
      -1,   -1,   -1,   -1,   -1,   -1,   -1,   -1,
      -1,   -1,   -1,   -1,   -1,   -1,   -1,   -1,
      -1,   -1,   -1,   -1,   -1,   -1,   -1,   -1,
      -1,   -1,   -1,   -1,   -1,   -1,   -1,   -1,
      -1,   -1,   -1,   -1,   -1,   -1,   -1,   -1,
      -1,   -1,   -1,   -1,   -1,   -1,   -1,   -1,
      -1,   -1,   -1, 4170,   -1,   -1,   -1,   -1,
      -1,   -1,   -1,   -1,   -1,   -1,   -1,   -1,
      -1,   -1,   -1,   -1,   -1,   -1,   -1,   -1,
      -1,   -1, 4171,   -1,   -1,   -1,   -1,   -1,
      -1,   -1,   -1, 4172,   -1,   -1,   -1,   -1,
      -1,   -1, 4173,   -1,   -1,   -1,   -1,   -1,
      -1,   -1,   -1,   -1,   -1,   -1,   -1,   -1,
      -1,   -1,   -1,   -1,   -1,   -1,   -1,   -1,
      -1,   -1,   -1,   -1,   -1,   -1,   -1,   -1,
      -1,   -1,   -1,   -1,   -1,   -1,   -1,   -1,
      -1,   -1,   -1,   -1,   -1,   -1,   -1,   -1,
      -1,   -1,   -1,   -1,   -1,   -1,   -1,   -1,
      -1,   -1,   -1,   -1,   -1,   -1,   -1,   -1,
      -1,   -1,   -1,   -1,   -1,   -1,   -1,   -1,
      -1,   -1,   -1,   -1,   -1,   -1,   -1,   -1,
      -1,   -1,   -1,   -1,   -1,   -1,   -1,   -1,
      -1,   -1,   -1,   -1,   -1,   -1,   -1,   -1,
      -1,   -1,   -1,   -1,   -1,   -1,   -1,   -1,
      -1,   -1,   -1,   -1,   -1,   -1,   -1,   -1,
      -1,   -1,   -1,   -1,   -1,   -1,   -1,   -1,
      -1,   -1,   -1,   -1,   -1,   -1,   -1,   -1,
      -1,   -1,   -1,   -1,   -1,   -1,   -1,   -1,
      -1,   -1,   -1,   -1,   -1,   -1,   -1,   -1,
      -1,   -1,   -1,   -1,   -1,   -1,   -1,   -1,
      -1,   -1,   -1,   -1,   -1,   -1,   -1,   -1,
      -1,   -1,   -1,   -1,   -1, 4174,   -1,   -1,
      -1,   -1,   -1,   -1,   -1,   -1,   -1,   -1,
      -1,   -1,   -1,   -1,   -1,   -1,   -1,   -1,
      -1,   -1,   -1,   -1,   -1,   -1,   -1,   -1,
      -1,   -1,   -1,   -1,   -1,   -1,   -1,   -1,
      -1,   -1,   -1,   -1,   -1,   -1,   -1,   -1,
      -1,   -1,   -1,   -1,   -1,   -1,   -1,   -1,
      -1,   -1,   -1,   -1,   -1,   -1,   -1,   -1,
      -1,   -1,   -1,   -1,   -1,   -1,   -1,   -1,
      -1,   -1,   -1,   -1,   -1,   -1,   -1,   -1,
      -1,   -1,   -1,   -1,   -1,   -1,   -1,   -1,
      -1,   -1,   -1,   -1,   -1,   -1,   -1,   -1,
      -1,   -1,   -1,   -1,   -1,   -1,   -1,   -1,
      -1,   -1,   -1,   -1,   -1,   -1,   -1,   -1,
      -1,   -1,   -1,   -1,   -1,   -1,   -1,   -1,
      -1,   -1,   -1,   -1,   -1,   -1,   -1,   -1,
    4175,   -1, 4176,   -1,   -1,   -1,   -1,   -1,
      -1,   -1,   -1,   -1,   -1,   -1,   -1,   -1,
      -1,   -1,   -1,   -1,   -1,   -1,   -1,   -1,
      -1,   -1,   -1,   -1,   -1,   -1,   -1,   -1,
      -1,   -1,   -1,   -1,   -1,   -1,   -1,   -1,
      -1,   -1,   -1,   -1,   -1,   -1,   -1,   -1,
      -1,   -1,   -1,   -1,   -1,   -1,   -1,   -1,
      -1,   -1,   -1,   -1,   -1,   -1,   -1,   -1,
      -1,   -1,   -1,   -1,   -1,   -1,   -1,   -1,
      -1,   -1,   -1,   -1,   -1,   -1,   -1,   -1,
      -1,   -1,   -1,   -1,   -1,   -1,   -1,   -1,
      -1,   -1,   -1,   -1,   -1,   -1,   -1,   -1,
      -1,   -1,   -1,   -1,   -1,   -1,   -1,   -1,
      -1,   -1,   -1,   -1,   -1,   -1,   -1,   -1,
      -1,   -1,   -1,   -1,   -1,   -1,   -1,   -1,
      -1,   -1,   -1,   -1,   -1,   -1,   -1,   -1,
      -1,   -1,   -1,   -1,   -1,   -1,   -1,   -1,
      -1,   -1,   -1,   -1,   -1,   -1,   -1,   -1,
      -1,   -1,   -1,   -1,   -1,   -1,   -1,   -1,
      -1,   -1,   -1,   -1,   -1,   -1,   -1,   -1,
      -1,   -1,   -1,   -1,   -1,   -1,   -1,   -1,
      -1,   -1,   -1,   -1,   -1,   -1,   -1,   -1,
      -1,   -1,   -1,   -1,   -1,   -1,   -1,   -1,
      -1,   -1,   -1,   -1,   -1,   -1,   -1,   -1,
      -1,   -1,   -1,   -1,   -1,   -1,   -1,   -1,
      -1,   -1,   -1,   -1,   -1,   -1,   -1,   -1,
      -1,   -1,   -1,   -1,   -1,   -1,   -1,   -1,
      -1,   -1,   -1,   -1,   -1,   -1,   -1,   -1,
      -1,   -1,   -1,   -1,   -1,   -1,   -1,   -1,
      -1,   -1,   -1,   -1,   -1,   -1,   -1,   -1,
      -1,   -1,   -1,   -1,   -1,   -1,   -1,   -1,
      -1,   -1,   -1,   -1,   -1,   -1,   -1,   -1,
      -1,   -1,   -1,   -1,   -1,   -1,   -1,   -1,
      -1,   -1,   -1,   -1,   -1,   -1,   -1,   -1,
      -1,   -1,   -1,   -1,   -1,   -1,   -1,   -1,
      -1,   -1,   -1,   -1,   -1,   -1,   -1,   -1,
      -1,   -1,   -1,   -1,   -1,   -1,   -1, 4177,
      -1,   -1,   -1,   -1,   -1,   -1,   -1,   -1,
      -1,   -1,   -1,   -1,   -1,   -1,   -1,   -1,
      -1,   -1,   -1,   -1,   -1,   -1,   -1,   -1,
      -1,   -1,   -1,   -1,   -1,   -1,   -1,   -1,
      -1,   -1,   -1,   -1,   -1,   -1,   -1,   -1,
      -1,   -1,   -1, 4178,   -1,   -1,   -1,   -1,
      -1,   -1,   -1,   -1,   -1,   -1,   -1,   -1,
      -1,   -1,   -1,   -1,   -1,   -1,   -1,   -1,
      -1,   -1,   -1,   -1,   -1,   -1,   -1,   -1,
      -1,   -1,   -1,   -1,   -1,   -1,   -1,   -1,
      -1,   -1,   -1,   -1,   -1,   -1,   -1,   -1,
      -1,   -1,   -1,   -1,   -1,   -1,   -1,   -1,
      -1,   -1,   -1,   -1,   -1,   -1,   -1,   -1,
      -1,   -1, 4179,   -1,   -1,   -1,   -1,   -1,
      -1,   -1,   -1,   -1,   -1,   -1,   -1,   -1,
      -1,   -1,   -1,   -1,   -1,   -1,   -1,   -1,
      -1,   -1,   -1,   -1,   -1,   -1,   -1,   -1,
      -1,   -1,   -1,   -1,   -1,   -1,   -1,   -1,
      -1,   -1,   -1,   -1,   -1,   -1,   -1,   -1,
      -1,   -1,   -1,   -1,   -1,   -1,   -1,   -1,
      -1,   -1,   -1,   -1,   -1,   -1,   -1,   -1,
      -1,   -1,   -1,   -1,   -1,   -1,   -1,   -1,
      -1,   -1,   -1,   -1,   -1,   -1,   -1,   -1,
      -1,   -1,   -1,   -1,   -1,   -1,   -1,   -1,
      -1,   -1,   -1,   -1,   -1,   -1,   -1,   -1,
      -1,   -1,   -1,   -1,   -1,   -1,   -1,   -1,
      -1,   -1,   -1,   -1,   -1,   -1,   -1,   -1,
      -1,   -1,   -1,   -1,   -1,   -1,   -1,   -1,
      -1,   -1,   -1,   -1, 4180,   -1,   -1,   -1,
      -1,   -1,   -1,   -1,   -1,   -1,   -1,   -1,
      -1,   -1,   -1,   -1,   -1,   -1,   -1,   -1,
      -1,   -1,   -1,   -1,   -1,   -1,   -1,   -1,
      -1,   -1,   -1,   -1,   -1,   -1,   -1,   -1,
      -1,   -1,   -1,   -1,   -1,   -1,   -1,   -1,
      -1,   -1,   -1,   -1,   -1,   -1,   -1,   -1,
      -1,   -1,   -1,   -1,   -1,   -1,   -1,   -1,
      -1,   -1,   -1,   -1,   -1,   -1,   -1,   -1,
      -1,   -1,   -1,   -1,   -1,   -1,   -1,   -1,
      -1,   -1,   -1,   -1,   -1,   -1,   -1,   -1,
      -1,   -1,   -1,   -1,   -1,   -1,   -1,   -1,
      -1,   -1,   -1,   -1,   -1, 4181,   -1,   -1,
      -1,   -1,   -1,   -1,   -1,   -1,   -1,   -1,
      -1,   -1,   -1,   -1,   -1,   -1,   -1,   -1,
      -1,   -1,   -1,   -1,   -1,   -1,   -1,   -1,
      -1,   -1,   -1,   -1,   -1,   -1,   -1,   -1,
      -1,   -1,   -1,   -1,   -1,   -1,   -1,   -1,
      -1,   -1,   -1,   -1,   -1,   -1,   -1,   -1,
      -1,   -1,   -1,   -1,   -1,   -1,   -1,   -1,
      -1,   -1,   -1,   -1,   -1,   -1,   -1,   -1,
      -1,   -1,   -1,   -1,   -1,   -1,   -1,   -1,
      -1,   -1,   -1,   -1,   -1,   -1,   -1,   -1,
      -1,   -1,   -1,   -1,   -1,   -1,   -1,   -1,
      -1,   -1,   -1,   -1,   -1,   -1,   -1,   -1,
      -1,   -1,   -1,   -1,   -1,   -1,   -1,   -1,
      -1,   -1,   -1,   -1,   -1,   -1,   -1,   -1,
      -1,   -1,   -1,   -1,   -1,   -1,   -1,   -1,
      -1,   -1,   -1,   -1,   -1,   -1,   -1,   -1,
      -1,   -1,   -1,   -1,   -1,   -1,   -1,   -1,
      -1,   -1,   -1,   -1,   -1,   -1,   -1,   -1,
      -1,   -1,   -1,   -1,   -1,   -1,   -1,   -1,
      -1,   -1,   -1,   -1,   -1,   -1,   -1,   -1,
      -1,   -1,   -1,   -1,   -1,   -1,   -1,   -1,
    4182,   -1,   -1,   -1,   -1,   -1,   -1,   -1,
      -1,   -1,   -1,   -1,   -1,   -1,   -1,   -1,
      -1,   -1,   -1,   -1,   -1,   -1,   -1,   -1,
      -1,   -1,   -1,   -1,   -1,   -1,   -1,   -1,
      -1,   -1,   -1,   -1,   -1,   -1,   -1,   -1,
      -1,   -1,   -1,   -1,   -1,   -1,   -1,   -1,
      -1,   -1,   -1,   -1,   -1,   -1,   -1,   -1,
      -1,   -1,   -1,   -1,   -1,   -1,   -1,   -1,
      -1,   -1,   -1, 4183,   -1,   -1,   -1,   -1,
      -1,   -1,   -1,   -1,   -1,   -1,   -1,   -1,
      -1,   -1,   -1,   -1,   -1,   -1,   -1,   -1,
      -1,   -1,   -1,   -1,   -1,   -1,   -1,   -1,
      -1,   -1,   -1,   -1,   -1,   -1,   -1,   -1,
      -1,   -1,   -1,   -1,   -1,   -1,   -1,   -1,
      -1,   -1,   -1,   -1,   -1,   -1,   -1,   -1,
      -1,   -1,   -1,   -1,   -1,   -1,   -1,   -1,
      -1,   -1,   -1,   -1,   -1,   -1,   -1,   -1,
      -1,   -1,   -1,   -1,   -1,   -1,   -1,   -1,
      -1,   -1,   -1,   -1,   -1,   -1,   -1,   -1,
      -1,   -1,   -1,   -1,   -1,   -1,   -1,   -1,
      -1,   -1,   -1,   -1,   -1,   -1,   -1,   -1,
      -1,   -1,   -1,   -1,   -1,   -1,   -1,   -1,
      -1,   -1,   -1, 4184,   -1,   -1,   -1,   -1,
      -1,   -1,   -1,   -1,   -1,   -1,   -1,   -1,
      -1,   -1,   -1,   -1,   -1,   -1,   -1,   -1,
      -1,   -1,   -1,   -1,   -1,   -1,   -1,   -1,
      -1,   -1,   -1,   -1,   -1,   -1,   -1,   -1,
      -1,   -1,   -1,   -1,   -1,   -1,   -1,   -1,
      -1,   -1,   -1,   -1,   -1,   -1,   -1,   -1,
      -1,   -1,   -1,   -1,   -1,   -1,   -1,   -1,
      -1,   -1,   -1,   -1,   -1,   -1,   -1,   -1,
      -1,   -1,   -1,   -1,   -1,   -1,   -1,   -1,
      -1,   -1,   -1,   -1,   -1,   -1,   -1,   -1,
      -1,   -1,   -1,   -1,   -1,   -1,   -1,   -1,
      -1,   -1,   -1,   -1,   -1,   -1,   -1, 4185,
      -1,   -1,   -1,   -1,   -1,   -1,   -1,   -1,
      -1,   -1,   -1,   -1,   -1,   -1,   -1,   -1,
      -1,   -1,   -1,   -1,   -1,   -1,   -1,   -1,
      -1,   -1,   -1,   -1,   -1,   -1,   -1,   -1,
      -1,   -1,   -1,   -1,   -1,   -1,   -1,   -1,
      -1,   -1,   -1,   -1,   -1,   -1,   -1,   -1,
      -1,   -1,   -1,   -1,   -1,   -1,   -1,   -1,
      -1,   -1,   -1,   -1,   -1,   -1,   -1,   -1,
      -1,   -1,   -1,   -1,   -1,   -1,   -1,   -1,
      -1,   -1,   -1,   -1,   -1,   -1,   -1,   -1,
      -1,   -1,   -1,   -1,   -1,   -1,   -1,   -1,
      -1,   -1,   -1,   -1,   -1,   -1,   -1,   -1,
      -1,   -1,   -1,   -1,   -1,   -1,   -1,   -1,
      -1,   -1,   -1,   -1,   -1,   -1,   -1,   -1,
      -1,   -1,   -1,   -1,   -1, 4186,   -1,   -1,
      -1,   -1,   -1,   -1,   -1,   -1,   -1,   -1,
      -1,   -1,   -1,   -1,   -1,   -1,   -1,   -1,
      -1,   -1,   -1,   -1,   -1,   -1,   -1,   -1,
      -1,   -1,   -1,   -1,   -1,   -1,   -1,   -1,
      -1,   -1,   -1,   -1,   -1,   -1,   -1,   -1,
      -1,   -1,   -1,   -1,   -1,   -1,   -1,   -1,
      -1,   -1,   -1,   -1,   -1,   -1,   -1,   -1,
      -1,   -1,   -1,   -1,   -1,   -1,   -1,   -1,
      -1,   -1,   -1,   -1,   -1,   -1,   -1,   -1,
      -1,   -1,   -1,   -1,   -1,   -1,   -1,   -1,
      -1,   -1,   -1,   -1,   -1,   -1,   -1,   -1,
      -1,   -1,   -1,   -1,   -1,   -1,   -1,   -1,
      -1,   -1,   -1,   -1,   -1,   -1,   -1,   -1,
      -1,   -1,   -1,   -1,   -1,   -1,   -1,   -1,
      -1,   -1,   -1,   -1,   -1,   -1,   -1,   -1,
      -1,   -1,   -1,   -1,   -1,   -1,   -1,   -1,
      -1,   -1,   -1,   -1, 4187,   -1,   -1,   -1,
      -1,   -1,   -1,   -1,   -1,   -1,   -1,   -1,
      -1,   -1,   -1,   -1,   -1,   -1,   -1,   -1,
      -1,   -1,   -1,   -1,   -1,   -1,   -1,   -1,
      -1,   -1,   -1,   -1, 4188,   -1,   -1,   -1,
      -1,   -1,   -1,   -1,   -1,   -1,   -1,   -1,
      -1,   -1,   -1,   -1,   -1,   -1,   -1,   -1,
      -1,   -1,   -1,   -1,   -1,   -1,   -1,   -1,
      -1, 4189,   -1,   -1,   -1,   -1,   -1,   -1,
      -1,   -1,   -1,   -1,   -1,   -1,   -1,   -1,
      -1,   -1,   -1,   -1,   -1,   -1,   -1,   -1,
      -1,   -1,   -1,   -1,   -1,   -1,   -1,   -1,
      -1,   -1,   -1,   -1,   -1,   -1,   -1,   -1,
      -1,   -1,   -1,   -1,   -1,   -1,   -1,   -1,
      -1,   -1,   -1,   -1,   -1,   -1,   -1, 4190,
      -1,   -1,   -1,   -1,   -1,   -1,   -1,   -1,
      -1,   -1,   -1,   -1,   -1,   -1,   -1,   -1,
      -1,   -1,   -1,   -1,   -1,   -1,   -1,   -1,
      -1,   -1,   -1, 4191,   -1,   -1,   -1,   -1,
      -1,   -1,   -1,   -1,   -1,   -1,   -1,   -1,
      -1,   -1,   -1,   -1,   -1,   -1,   -1,   -1,
      -1,   -1,   -1,   -1,   -1,   -1,   -1,   -1,
      -1,   -1,   -1,   -1,   -1,   -1,   -1,   -1,
      -1,   -1,   -1,   -1,   -1,   -1,   -1,   -1,
      -1,   -1,   -1,   -1,   -1,   -1,   -1,   -1,
      -1,   -1,   -1,   -1,   -1,   -1,   -1,   -1,
      -1,   -1,   -1,   -1,   -1,   -1,   -1,   -1,
      -1,   -1,   -1,   -1,   -1,   -1,   -1,   -1,
      -1,   -1,   -1,   -1,   -1,   -1,   -1,   -1,
      -1,   -1,   -1,   -1,   -1,   -1,   -1,   -1,
      -1,   -1,   -1,   -1,   -1,   -1,   -1,   -1,
      -1,   -1,   -1,   -1,   -1,   -1,   -1,   -1,
      -1,   -1,   -1,   -1,   -1, 4192,   -1,   -1,
      -1,   -1,   -1,   -1,   -1,   -1,   -1,   -1,
      -1,   -1,   -1,   -1,   -1,   -1,   -1,   -1,
      -1,   -1,   -1,   -1,   -1,   -1,   -1,   -1,
      -1,   -1,   -1,   -1,   -1,   -1,   -1,   -1,
      -1,   -1,   -1,   -1,   -1,   -1,   -1,   -1,
      -1,   -1,   -1,   -1,   -1,   -1,   -1,   -1,
      -1,   -1,   -1,   -1,   -1,   -1,   -1,   -1,
      -1,   -1,   -1,   -1,   -1,   -1,   -1,   -1,
      -1,   -1,   -1,   -1,   -1,   -1,   -1,   -1,
      -1,   -1,   -1,   -1,   -1,   -1,   -1,   -1,
      -1,   -1,   -1,   -1,   -1,   -1,   -1,   -1,
      -1,   -1,   -1,   -1,   -1,   -1,   -1,   -1,
      -1,   -1,   -1,   -1,   -1,   -1,   -1,   -1,
      -1,   -1,   -1,   -1,   -1,   -1,   -1,   -1,
      -1,   -1,   -1,   -1,   -1,   -1,   -1,   -1,
      -1,   -1,   -1,   -1,   -1,   -1,   -1, 4193,
      -1,   -1,   -1,   -1,   -1,   -1,   -1,   -1,
      -1,   -1,   -1,   -1,   -1,   -1,   -1,   -1,
      -1,   -1,   -1,   -1,   -1,   -1,   -1,   -1,
      -1,   -1,   -1,   -1,   -1,   -1,   -1,   -1,
      -1,   -1,   -1,   -1,   -1,   -1,   -1,   -1,
      -1,   -1,   -1,   -1,   -1,   -1,   -1,   -1,
      -1,   -1,   -1,   -1,   -1, 4194,   -1,   -1,
      -1,   -1,   -1,   -1,   -1,   -1,   -1,   -1,
      -1,   -1,   -1,   -1,   -1,   -1,   -1,   -1,
      -1,   -1,   -1,   -1,   -1,   -1,   -1,   -1,
      -1,   -1,   -1,   -1,   -1,   -1,   -1,   -1,
      -1,   -1,   -1,   -1,   -1,   -1,   -1,   -1,
      -1,   -1,   -1,   -1,   -1,   -1,   -1,   -1,
      -1,   -1,   -1,   -1,   -1,   -1,   -1,   -1,
      -1,   -1,   -1,   -1,   -1,   -1,   -1,   -1,
      -1,   -1,   -1,   -1,   -1,   -1,   -1,   -1,
      -1,   -1,   -1,   -1,   -1,   -1,   -1,   -1,
      -1,   -1, 4195,   -1,   -1,   -1,   -1,   -1,
      -1,   -1,   -1,   -1,   -1,   -1,   -1,   -1,
      -1,   -1,   -1,   -1,   -1,   -1,   -1,   -1,
      -1,   -1,   -1,   -1,   -1,   -1,   -1,   -1,
      -1,   -1,   -1,   -1,   -1,   -1,   -1,   -1,
      -1,   -1,   -1,   -1,   -1,   -1,   -1,   -1,
      -1,   -1,   -1,   -1,   -1,   -1,   -1,   -1,
      -1,   -1,   -1,   -1,   -1,   -1,   -1,   -1,
      -1,   -1,   -1,   -1,   -1,   -1,   -1,   -1,
      -1,   -1,   -1,   -1,   -1,   -1,   -1,   -1,
      -1,   -1,   -1,   -1,   -1,   -1,   -1,   -1,
      -1,   -1,   -1,   -1,   -1,   -1,   -1,   -1,
      -1,   -1,   -1,   -1,   -1,   -1,   -1,   -1,
      -1,   -1,   -1,   -1,   -1,   -1,   -1,   -1,
      -1,   -1,   -1,   -1,   -1,   -1,   -1,   -1,
      -1,   -1,   -1,   -1,   -1,   -1,   -1,   -1,
      -1,   -1,   -1,   -1,   -1, 4196,   -1,   -1,
      -1,   -1,   -1,   -1,   -1,   -1,   -1,   -1,
      -1,   -1,   -1,   -1,   -1,   -1,   -1,   -1,
      -1,   -1,   -1,   -1,   -1,   -1,   -1,   -1,
      -1,   -1,   -1,   -1,   -1,   -1,   -1,   -1,
      -1,   -1,   -1,   -1,   -1,   -1,   -1,   -1,
      -1,   -1,   -1,   -1,   -1,   -1,   -1,   -1,
      -1,   -1,   -1,   -1,   -1,   -1,   -1,   -1,
      -1,   -1,   -1,   -1,   -1,   -1,   -1,   -1,
      -1,   -1,   -1,   -1,   -1,   -1,   -1,   -1,
      -1,   -1,   -1,   -1,   -1,   -1,   -1,   -1,
      -1,   -1,   -1,   -1,   -1,   -1,   -1,   -1,
      -1,   -1,   -1,   -1,   -1,   -1,   -1, 4197,
      -1,   -1,   -1,   -1, 4198,   -1,   -1,   -1,
      -1,   -1,   -1,   -1,   -1,   -1,   -1,   -1,
      -1,   -1,   -1,   -1,   -1,   -1,   -1,   -1,
      -1,   -1,   -1,   -1,   -1,   -1,   -1,   -1,
      -1,   -1,   -1,   -1,   -1,   -1,   -1,   -1,
      -1,   -1,   -1,   -1,   -1,   -1,   -1,   -1,
      -1,   -1,   -1,   -1,   -1,   -1,   -1,   -1,
      -1,   -1,   -1,   -1,   -1,   -1,   -1,   -1,
      -1,   -1,   -1,   -1,   -1,   -1,   -1,   -1,
      -1,   -1,   -1,   -1,   -1,   -1,   -1,   -1,
      -1,   -1,   -1,   -1,   -1,   -1,   -1,   -1,
      -1,   -1,   -1,   -1,   -1,   -1,   -1,   -1,
      -1,   -1,   -1,   -1,   -1,   -1,   -1,   -1,
      -1,   -1,   -1,   -1,   -1,   -1,   -1,   -1,
      -1,   -1,   -1,   -1,   -1,   -1,   -1,   -1,
      -1,   -1,   -1,   -1, 4199,   -1,   -1,   -1,
    4200,   -1,   -1,   -1,   -1,   -1,   -1,   -1,
      -1,   -1,   -1,   -1,   -1,   -1,   -1,   -1,
      -1,   -1,   -1,   -1,   -1,   -1,   -1,   -1,
      -1,   -1,   -1,   -1,   -1,   -1,   -1,   -1,
      -1,   -1,   -1,   -1,   -1,   -1,   -1,   -1,
      -1,   -1,   -1,   -1,   -1,   -1,   -1,   -1,
      -1,   -1,   -1,   -1,   -1,   -1,   -1,   -1,
      -1,   -1,   -1,   -1,   -1,   -1,   -1,   -1,
      -1,   -1,   -1,   -1,   -1,   -1,   -1,   -1,
      -1,   -1,   -1,   -1, 4201,   -1,   -1,   -1,
      -1,   -1,   -1,   -1,   -1, 4202,   -1,   -1,
      -1,   -1,   -1,   -1,   -1,   -1,   -1,   -1,
      -1,   -1,   -1,   -1,   -1,   -1,   -1,   -1,
      -1,   -1,   -1,   -1,   -1,   -1,   -1,   -1,
      -1,   -1,   -1,   -1,   -1,   -1,   -1,   -1,
      -1,   -1,   -1,   -1,   -1,   -1,   -1, 4203,
      -1,   -1,   -1,   -1,   -1,   -1,   -1,   -1,
      -1,   -1,   -1,   -1,   -1,   -1,   -1,   -1,
      -1,   -1,   -1,   -1,   -1,   -1,   -1,   -1,
      -1,   -1,   -1,   -1,   -1,   -1,   -1,   -1,
      -1,   -1,   -1,   -1,   -1,   -1,   -1,   -1,
      -1,   -1,   -1,   -1,   -1,   -1,   -1,   -1,
      -1,   -1, 4204,   -1,   -1,   -1,   -1,   -1,
      -1,   -1,   -1,   -1,   -1,   -1,   -1,   -1,
      -1,   -1,   -1,   -1,   -1,   -1,   -1,   -1,
      -1,   -1,   -1,   -1,   -1,   -1,   -1,   -1,
      -1,   -1,   -1,   -1,   -1,   -1,   -1,   -1,
      -1,   -1,   -1,   -1,   -1,   -1,   -1,   -1,
      -1,   -1,   -1,   -1,   -1,   -1,   -1,   -1,
      -1,   -1,   -1,   -1,   -1,   -1,   -1,   -1,
      -1,   -1,   -1,   -1,   -1,   -1,   -1,   -1,
      -1,   -1,   -1,   -1,   -1,   -1,   -1,   -1,
      -1,   -1,   -1,   -1, 4205,   -1,   -1,   -1,
      -1,   -1,   -1,   -1,   -1,   -1,   -1,   -1,
      -1,   -1, 4206,   -1,   -1,   -1,   -1,   -1,
      -1,   -1,   -1,   -1,   -1,   -1,   -1,   -1,
      -1,   -1,   -1,   -1,   -1,   -1,   -1,   -1,
      -1,   -1,   -1,   -1,   -1,   -1,   -1,   -1,
      -1,   -1,   -1,   -1,   -1,   -1,   -1,   -1,
      -1,   -1,   -1, 4207,   -1,   -1,   -1,   -1,
      -1,   -1,   -1,   -1, 4208,   -1,   -1,   -1,
      -1,   -1,   -1,   -1,   -1,   -1,   -1,   -1,
      -1,   -1,   -1,   -1,   -1,   -1, 4209,   -1,
      -1,   -1,   -1,   -1,   -1,   -1,   -1,   -1,
      -1,   -1,   -1,   -1,   -1,   -1,   -1, 4210,
      -1,   -1,   -1,   -1,   -1,   -1,   -1,   -1,
      -1,   -1,   -1,   -1,   -1,   -1,   -1,   -1,
      -1,   -1,   -1,   -1,   -1,   -1,   -1,   -1,
      -1,   -1,   -1,   -1,   -1,   -1,   -1,   -1,
      -1,   -1,   -1,   -1,   -1,   -1,   -1,   -1,
      -1,   -1,   -1,   -1,   -1,   -1,   -1,   -1,
      -1,   -1,   -1,   -1,   -1,   -1,   -1,   -1,
      -1,   -1,   -1,   -1,   -1,   -1,   -1,   -1,
      -1,   -1,   -1,   -1,   -1,   -1,   -1,   -1,
      -1,   -1,   -1,   -1,   -1,   -1,   -1,   -1,
      -1,   -1,   -1,   -1,   -1,   -1,   -1,   -1,
      -1,   -1,   -1,   -1,   -1,   -1,   -1,   -1,
      -1,   -1,   -1,   -1,   -1,   -1,   -1,   -1,
      -1,   -1,   -1,   -1,   -1,   -1,   -1,   -1,
      -1,   -1,   -1,   -1,   -1,   -1,   -1,   -1,
      -1,   -1,   -1,   -1,   -1,   -1,   -1,   -1,
      -1,   -1,   -1,   -1,   -1,   -1,   -1,   -1,
      -1,   -1,   -1,   -1,   -1,   -1,   -1,   -1,
      -1,   -1,   -1,   -1,   -1,   -1,   -1,   -1,
      -1,   -1,   -1, 4211,   -1,   -1,   -1,   -1,
      -1,   -1,   -1,   -1,   -1,   -1,   -1,   -1,
      -1,   -1,   -1,   -1,   -1,   -1,   -1,   -1,
      -1,   -1,   -1,   -1,   -1,   -1,   -1,   -1,
      -1,   -1,   -1,   -1,   -1,   -1,   -1,   -1,
      -1,   -1,   -1,   -1,   -1,   -1,   -1,   -1,
      -1,   -1,   -1,   -1,   -1,   -1,   -1,   -1,
      -1,   -1,   -1,   -1,   -1,   -1,   -1,   -1,
      -1,   -1,   -1,   -1,   -1,   -1,   -1,   -1,
      -1,   -1,   -1,   -1,   -1,   -1,   -1,   -1,
      -1,   -1,   -1,   -1,   -1,   -1,   -1,   -1,
      -1,   -1,   -1,   -1,   -1,   -1,   -1,   -1,
      -1,   -1,   -1,   -1,   -1,   -1,   -1,   -1,
      -1,   -1,   -1,   -1,   -1,   -1,   -1,   -1,
      -1,   -1,   -1,   -1,   -1,   -1,   -1,   -1,
      -1,   -1,   -1,   -1,   -1,   -1,   -1,   -1,
      -1,   -1,   -1,   -1,   -1,   -1,   -1,   -1,
      -1,   -1,   -1,   -1,   -1,   -1,   -1,   -1,
      -1,   -1,   -1,   -1,   -1,   -1,   -1,   -1,
      -1,   -1,   -1,   -1,   -1,   -1,   -1,   -1,
      -1,   -1,   -1,   -1,   -1,   -1,   -1,   -1,
      -1,   -1,   -1,   -1,   -1,   -1,   -1,   -1,
      -1,   -1,   -1,   -1,   -1,   -1,   -1,   -1,
      -1,   -1,   -1,   -1,   -1, 4212,   -1,   -1,
      -1,   -1,   -1,   -1,   -1,   -1,   -1,   -1,
      -1,   -1,   -1,   -1,   -1,   -1,   -1,   -1,
      -1,   -1,   -1,   -1,   -1,   -1,   -1,   -1,
      -1,   -1,   -1,   -1,   -1,   -1,   -1,   -1,
      -1,   -1,   -1,   -1,   -1,   -1,   -1,   -1,
      -1,   -1,   -1,   -1,   -1,   -1,   -1,   -1,
      -1,   -1,   -1,   -1,   -1,   -1,   -1,   -1,
      -1,   -1,   -1,   -1,   -1,   -1,   -1,   -1,
    4213,   -1,   -1,   -1,   -1,   -1,   -1,   -1,
      -1,   -1,   -1, 4214,   -1,   -1,   -1,   -1,
      -1,   -1,   -1,   -1,   -1,   -1,   -1,   -1,
      -1,   -1,   -1,   -1,   -1,   -1,   -1,   -1,
      -1,   -1,   -1,   -1,   -1,   -1,   -1,   -1,
      -1,   -1,   -1,   -1,   -1,   -1,   -1,   -1,
      -1,   -1,   -1,   -1,   -1,   -1,   -1,   -1,
      -1,   -1,   -1,   -1,   -1,   -1,   -1,   -1,
      -1,   -1,   -1,   -1,   -1,   -1,   -1,   -1,
      -1,   -1,   -1,   -1,   -1,   -1,   -1,   -1,
      -1,   -1,   -1,   -1,   -1,   -1,   -1,   -1,
      -1,   -1,   -1,   -1,   -1,   -1,   -1,   -1,
      -1,   -1,   -1,   -1,   -1,   -1,   -1,   -1,
      -1,   -1,   -1,   -1,   -1,   -1,   -1,   -1,
      -1,   -1,   -1,   -1,   -1,   -1,   -1,   -1,
      -1,   -1,   -1,   -1,   -1,   -1,   -1,   -1,
      -1,   -1,   -1,   -1,   -1,   -1,   -1,   -1,
      -1,   -1,   -1,   -1,   -1,   -1,   -1,   -1,
      -1,   -1,   -1,   -1,   -1,   -1,   -1,   -1,
      -1,   -1,   -1,   -1,   -1,   -1,   -1,   -1,
      -1,   -1,   -1,   -1,   -1,   -1,   -1,   -1,
      -1,   -1,   -1,   -1,   -1,   -1,   -1,   -1,
      -1,   -1,   -1,   -1,   -1,   -1,   -1,   -1,
      -1,   -1,   -1,   -1,   -1,   -1,   -1,   -1,
      -1,   -1,   -1,   -1,   -1,   -1,   -1,   -1,
      -1,   -1,   -1,   -1,   -1,   -1,   -1,   -1,
      -1,   -1,   -1,   -1,   -1,   -1,   -1,   -1,
      -1,   -1,   -1,   -1,   -1,   -1,   -1,   -1,
      -1,   -1,   -1,   -1,   -1,   -1,   -1,   -1,
      -1,   -1,   -1,   -1,   -1,   -1,   -1,   -1,
      -1,   -1,   -1,   -1,   -1,   -1,   -1,   -1,
      -1,   -1,   -1,   -1,   -1,   -1,   -1,   -1,
      -1,   -1,   -1,   -1,   -1,   -1,   -1,   -1,
      -1,   -1,   -1,   -1,   -1,   -1,   -1,   -1,
      -1,   -1,   -1,   -1,   -1,   -1,   -1,   -1,
      -1,   -1,   -1,   -1,   -1,   -1,   -1,   -1,
      -1,   -1, 4215,   -1,   -1, 4216,   -1,   -1,
      -1,   -1,   -1,   -1,   -1,   -1,   -1,   -1,
      -1,   -1,   -1,   -1,   -1,   -1,   -1,   -1,
      -1,   -1,   -1,   -1,   -1,   -1,   -1,   -1,
      -1,   -1,   -1,   -1,   -1,   -1,   -1,   -1,
      -1,   -1,   -1,   -1,   -1,   -1,   -1,   -1,
      -1,   -1,   -1,   -1,   -1,   -1,   -1,   -1,
      -1,   -1,   -1,   -1,   -1,   -1,   -1,   -1,
      -1,   -1,   -1,   -1,   -1,   -1,   -1,   -1,
      -1,   -1,   -1,   -1,   -1,   -1,   -1,   -1,
      -1,   -1,   -1,   -1,   -1,   -1,   -1,   -1,
      -1,   -1,   -1,   -1,   -1,   -1,   -1,   -1,
      -1,   -1,   -1,   -1,   -1,   -1,   -1,   -1,
      -1,   -1,   -1,   -1,   -1,   -1,   -1,   -1,
      -1,   -1,   -1,   -1,   -1,   -1,   -1,   -1,
      -1,   -1,   -1,   -1,   -1,   -1,   -1,   -1,
      -1,   -1,   -1,   -1,   -1,   -1,   -1,   -1,
      -1,   -1,   -1,   -1,   -1,   -1,   -1,   -1,
      -1,   -1,   -1,   -1,   -1,   -1,   -1,   -1,
      -1,   -1,   -1,   -1,   -1,   -1,   -1,   -1,
      -1,   -1,   -1,   -1,   -1,   -1,   -1,   -1,
      -1,   -1,   -1,   -1,   -1,   -1,   -1,   -1,
      -1,   -1,   -1,   -1,   -1,   -1,   -1,   -1,
      -1,   -1,   -1,   -1,   -1,   -1,   -1,   -1,
      -1,   -1,   -1,   -1,   -1,   -1,   -1,   -1,
      -1,   -1,   -1,   -1,   -1,   -1,   -1,   -1,
      -1,   -1,   -1,   -1,   -1,   -1,   -1,   -1,
      -1,   -1,   -1,   -1,   -1,   -1,   -1,   -1,
      -1,   -1,   -1,   -1,   -1,   -1,   -1,   -1,
      -1,   -1,   -1,   -1,   -1,   -1,   -1,   -1,
      -1,   -1,   -1,   -1,   -1,   -1,   -1,   -1,
      -1,   -1,   -1,   -1,   -1,   -1,   -1,   -1,
      -1,   -1,   -1,   -1,   -1,   -1,   -1,   -1,
      -1,   -1,   -1,   -1,   -1,   -1,   -1,   -1,
      -1,   -1,   -1,   -1,   -1,   -1,   -1,   -1,
      -1,   -1,   -1,   -1,   -1,   -1,   -1,   -1,
    4217,   -1,   -1,   -1,   -1,   -1,   -1,   -1,
      -1,   -1,   -1,   -1,   -1,   -1,   -1,   -1,
      -1,   -1,   -1,   -1,   -1,   -1,   -1,   -1,
      -1,   -1,   -1,   -1,   -1,   -1,   -1,   -1,
      -1,   -1,   -1,   -1,   -1,   -1,   -1,   -1,
      -1,   -1,   -1,   -1,   -1,   -1,   -1,   -1,
      -1,   -1,   -1,   -1,   -1,   -1,   -1,   -1,
      -1,   -1,   -1,   -1,   -1,   -1,   -1,   -1,
      -1,   -1,   -1,   -1,   -1,   -1,   -1,   -1,
      -1,   -1,   -1,   -1,   -1,   -1,   -1,   -1,
      -1,   -1,   -1,   -1,   -1,   -1,   -1,   -1,
      -1,   -1,   -1,   -1,   -1,   -1,   -1,   -1,
      -1,   -1,   -1,   -1,   -1,   -1,   -1,   -1,
      -1,   -1,   -1,   -1,   -1,   -1,   -1,   -1,
      -1,   -1,   -1,   -1,   -1,   -1,   -1,   -1,
      -1,   -1,   -1,   -1,   -1,   -1,   -1,   -1,
      -1,   -1,   -1,   -1,   -1,   -1,   -1,   -1,
      -1,   -1,   -1,   -1,   -1,   -1,   -1,   -1,
      -1,   -1,   -1,   -1,   -1,   -1,   -1,   -1,
      -1,   -1,   -1,   -1,   -1,   -1,   -1,   -1,
      -1,   -1,   -1,   -1,   -1,   -1,   -1,   -1,
      -1,   -1,   -1,   -1,   -1,   -1,   -1,   -1,
      -1,   -1,   -1,   -1,   -1,   -1,   -1,   -1,
      -1,   -1,   -1,   -1,   -1,   -1,   -1,   -1,
      -1,   -1,   -1,   -1,   -1,   -1,   -1,   -1,
      -1,   -1,   -1,   -1,   -1,   -1,   -1,   -1,
      -1,   -1,   -1,   -1,   -1,   -1,   -1,   -1,
      -1,   -1,   -1,   -1,   -1,   -1,   -1,   -1,
      -1,   -1,   -1,   -1,   -1,   -1,   -1,   -1,
      -1,   -1,   -1,   -1,   -1,   -1,   -1,   -1,
      -1,   -1,   -1,   -1,   -1,   -1,   -1,   -1,
      -1,   -1,   -1,   -1,   -1,   -1,   -1,   -1,
      -1,   -1,   -1,   -1,   -1,   -1,   -1,   -1,
      -1,   -1,   -1,   -1,   -1,   -1,   -1,   -1,
      -1,   -1,   -1,   -1,   -1,   -1,   -1,   -1,
      -1,   -1,   -1,   -1,   -1,   -1,   -1,   -1,
      -1,   -1,   -1,   -1,   -1,   -1,   -1,   -1,
      -1,   -1,   -1,   -1,   -1,   -1,   -1,   -1,
      -1,   -1,   -1,   -1,   -1,   -1,   -1,   -1,
      -1,   -1,   -1,   -1,   -1,   -1,   -1,   -1,
      -1,   -1,   -1,   -1,   -1,   -1,   -1,   -1,
      -1,   -1,   -1,   -1,   -1,   -1,   -1,   -1,
      -1,   -1,   -1,   -1,   -1,   -1,   -1,   -1,
      -1,   -1,   -1,   -1,   -1,   -1,   -1,   -1,
      -1,   -1,   -1,   -1,   -1,   -1,   -1,   -1,
      -1,   -1,   -1,   -1,   -1,   -1,   -1,   -1,
      -1,   -1,   -1,   -1,   -1,   -1,   -1,   -1,
      -1,   -1,   -1,   -1,   -1,   -1,   -1,   -1,
      -1,   -1,   -1,   -1,   -1,   -1,   -1,   -1,
      -1,   -1,   -1,   -1,   -1,   -1,   -1,   -1,
      -1,   -1,   -1,   -1,   -1, 4218,   -1,   -1,
      -1,   -1,   -1,   -1,   -1,   -1,   -1,   -1,
      -1,   -1,   -1,   -1,   -1,   -1,   -1,   -1,
      -1,   -1,   -1,   -1,   -1,   -1,   -1,   -1,
      -1,   -1,   -1,   -1,   -1,   -1,   -1,   -1,
      -1,   -1,   -1,   -1,   -1,   -1,   -1,   -1,
      -1,   -1,   -1,   -1,   -1,   -1,   -1,   -1,
      -1,   -1,   -1,   -1,   -1,   -1,   -1,   -1,
      -1,   -1,   -1,   -1,   -1,   -1,   -1,   -1,
      -1,   -1,   -1,   -1,   -1,   -1,   -1,   -1,
    4219,   -1,   -1,   -1,   -1,   -1,   -1,   -1,
      -1,   -1,   -1,   -1,   -1,   -1,   -1,   -1,
      -1,   -1,   -1,   -1,   -1,   -1,   -1,   -1,
      -1,   -1,   -1,   -1,   -1,   -1,   -1,   -1,
      -1,   -1,   -1,   -1,   -1,   -1,   -1,   -1,
      -1,   -1,   -1,   -1,   -1,   -1,   -1,   -1,
      -1,   -1,   -1,   -1,   -1,   -1,   -1,   -1,
      -1,   -1,   -1,   -1,   -1,   -1,   -1,   -1,
      -1,   -1,   -1,   -1,   -1,   -1,   -1,   -1,
      -1,   -1,   -1,   -1,   -1,   -1,   -1,   -1,
      -1,   -1,   -1,   -1,   -1,   -1,   -1,   -1,
      -1,   -1,   -1,   -1,   -1,   -1,   -1,   -1,
      -1,   -1,   -1,   -1,   -1,   -1,   -1,   -1,
      -1,   -1,   -1,   -1,   -1,   -1,   -1,   -1,
      -1,   -1,   -1,   -1,   -1,   -1,   -1,   -1,
      -1,   -1,   -1,   -1,   -1,   -1,   -1,   -1,
      -1,   -1,   -1,   -1,   -1,   -1,   -1,   -1,
      -1,   -1,   -1,   -1,   -1,   -1,   -1,   -1,
      -1,   -1,   -1,   -1,   -1,   -1,   -1,   -1,
      -1,   -1,   -1,   -1,   -1,   -1,   -1,   -1,
      -1,   -1,   -1,   -1,   -1,   -1,   -1,   -1,
      -1,   -1,   -1,   -1,   -1,   -1,   -1,   -1,
      -1,   -1,   -1,   -1,   -1,   -1,   -1,   -1,
      -1,   -1,   -1,   -1,   -1,   -1,   -1,   -1,
      -1,   -1,   -1,   -1,   -1,   -1,   -1,   -1,
      -1,   -1,   -1,   -1,   -1,   -1,   -1,   -1,
      -1,   -1,   -1,   -1,   -1,   -1,   -1,   -1,
      -1,   -1,   -1,   -1,   -1,   -1,   -1,   -1,
      -1,   -1,   -1,   -1,   -1,   -1,   -1,   -1,
      -1,   -1,   -1,   -1, 4220,   -1,   -1,   -1,
      -1,   -1,   -1,   -1,   -1,   -1,   -1,   -1,
      -1,   -1,   -1,   -1,   -1,   -1,   -1,   -1,
      -1,   -1,   -1,   -1,   -1,   -1,   -1,   -1,
      -1,   -1,   -1,   -1,   -1, 4221,   -1,   -1,
      -1,   -1,   -1,   -1,   -1,   -1,   -1,   -1,
      -1,   -1,   -1,   -1,   -1,   -1,   -1,   -1,
      -1,   -1,   -1,   -1,   -1,   -1,   -1,   -1,
      -1,   -1,   -1,   -1,   -1,   -1,   -1,   -1,
      -1,   -1,   -1,   -1,   -1,   -1,   -1,   -1,
      -1,   -1,   -1,   -1,   -1,   -1,   -1,   -1,
      -1,   -1,   -1,   -1,   -1,   -1,   -1,   -1,
      -1,   -1,   -1,   -1,   -1,   -1,   -1,   -1,
      -1,   -1,   -1,   -1,   -1,   -1,   -1,   -1,
      -1,   -1,   -1,   -1,   -1,   -1,   -1,   -1,
      -1, 4222,   -1,   -1,   -1,   -1,   -1,   -1,
      -1,   -1,   -1, 4223,   -1,   -1,   -1,   -1,
      -1,   -1,   -1,   -1,   -1,   -1,   -1,   -1,
      -1,   -1,   -1,   -1,   -1,   -1,   -1,   -1,
      -1,   -1,   -1,   -1,   -1,   -1,   -1,   -1,
      -1,   -1,   -1,   -1,   -1,   -1,   -1,   -1,
      -1,   -1,   -1,   -1,   -1,   -1,   -1,   -1,
      -1,   -1,   -1,   -1,   -1,   -1,   -1,   -1,
      -1,   -1,   -1,   -1,   -1,   -1,   -1,   -1,
      -1,   -1,   -1,   -1,   -1,   -1,   -1,   -1,
      -1,   -1,   -1,   -1,   -1,   -1,   -1,   -1,
      -1,   -1,   -1,   -1,   -1,   -1,   -1,   -1,
      -1,   -1,   -1,   -1,   -1,   -1,   -1,   -1,
      -1,   -1,   -1,   -1,   -1,   -1,   -1,   -1,
      -1,   -1,   -1,   -1,   -1,   -1,   -1,   -1,
      -1,   -1,   -1,   -1,   -1,   -1,   -1,   -1,
      -1,   -1,   -1,   -1,   -1,   -1,   -1,   -1,
      -1,   -1,   -1,   -1,   -1,   -1,   -1,   -1,
      -1,   -1,   -1,   -1,   -1,   -1,   -1,   -1,
      -1, 4224,   -1,   -1,   -1,   -1,   -1,   -1,
      -1,   -1,   -1,   -1,   -1,   -1,   -1,   -1,
      -1,   -1,   -1,   -1,   -1,   -1,   -1,   -1,
      -1,   -1,   -1,   -1,   -1,   -1,   -1,   -1,
      -1,   -1,   -1,   -1,   -1,   -1,   -1,   -1,
      -1,   -1,   -1,   -1,   -1,   -1,   -1,   -1,
      -1,   -1,   -1,   -1,   -1,   -1,   -1,   -1,
      -1,   -1,   -1,   -1,   -1,   -1,   -1,   -1,
      -1,   -1,   -1,   -1,   -1,   -1,   -1,   -1,
      -1,   -1,   -1,   -1,   -1,   -1,   -1,   -1,
      -1,   -1,   -1,   -1,   -1,   -1,   -1,   -1,
      -1,   -1,   -1,   -1,   -1,   -1,   -1,   -1,
      -1,   -1,   -1,   -1,   -1,   -1,   -1,   -1,
      -1,   -1,   -1,   -1,   -1,   -1,   -1,   -1,
      -1,   -1,   -1,   -1,   -1,   -1,   -1,   -1,
      -1,   -1,   -1,   -1,   -1,   -1,   -1,   -1,
      -1,   -1,   -1,   -1, 4225,   -1,   -1,   -1,
      -1,   -1,   -1,   -1,   -1,   -1,   -1,   -1,
      -1,   -1,   -1,   -1,   -1,   -1,   -1,   -1,
      -1,   -1,   -1,   -1,   -1,   -1,   -1,   -1,
      -1,   -1,   -1,   -1,   -1,   -1,   -1,   -1,
      -1,   -1,   -1,   -1,   -1,   -1,   -1,   -1,
      -1,   -1,   -1,   -1,   -1,   -1,   -1,   -1,
      -1,   -1,   -1,   -1,   -1,   -1,   -1,   -1,
      -1,   -1,   -1,   -1,   -1,   -1,   -1,   -1,
      -1,   -1,   -1,   -1,   -1,   -1,   -1,   -1,
      -1,   -1,   -1,   -1,   -1,   -1,   -1,   -1,
      -1,   -1,   -1,   -1,   -1,   -1,   -1,   -1,
      -1,   -1,   -1,   -1,   -1,   -1,   -1,   -1,
      -1,   -1,   -1,   -1,   -1,   -1,   -1,   -1,
      -1,   -1,   -1,   -1,   -1,   -1,   -1,   -1,
      -1,   -1,   -1,   -1,   -1,   -1,   -1,   -1,
      -1,   -1,   -1,   -1,   -1,   -1,   -1,   -1,
      -1,   -1,   -1,   -1,   -1,   -1,   -1,   -1,
      -1,   -1,   -1,   -1,   -1,   -1,   -1,   -1,
      -1, 4226,   -1,   -1,   -1,   -1,   -1,   -1,
      -1,   -1,   -1,   -1,   -1,   -1,   -1,   -1,
      -1,   -1,   -1,   -1,   -1,   -1,   -1,   -1,
      -1,   -1,   -1,   -1,   -1,   -1,   -1,   -1,
      -1,   -1,   -1,   -1,   -1,   -1,   -1,   -1,
      -1,   -1,   -1,   -1,   -1,   -1,   -1,   -1,
      -1,   -1,   -1,   -1,   -1,   -1,   -1,   -1,
      -1,   -1,   -1,   -1,   -1,   -1,   -1,   -1,
      -1,   -1,   -1,   -1,   -1,   -1,   -1,   -1,
      -1,   -1,   -1,   -1,   -1,   -1,   -1,   -1,
      -1,   -1,   -1,   -1,   -1,   -1,   -1,   -1,
      -1,   -1,   -1,   -1,   -1,   -1,   -1,   -1,
      -1,   -1,   -1,   -1,   -1,   -1,   -1,   -1,
      -1,   -1,   -1,   -1,   -1,   -1,   -1,   -1,
      -1,   -1,   -1,   -1,   -1,   -1,   -1,   -1,
      -1,   -1,   -1,   -1,   -1,   -1,   -1,   -1,
      -1,   -1,   -1,   -1,   -1,   -1,   -1,   -1,
      -1,   -1,   -1,   -1,   -1,   -1,   -1,   -1,
      -1,   -1,   -1,   -1,   -1,   -1,   -1,   -1,
      -1,   -1,   -1,   -1,   -1,   -1,   -1,   -1,
      -1,   -1,   -1,   -1,   -1,   -1,   -1,   -1,
      -1,   -1,   -1,   -1,   -1,   -1,   -1,   -1,
      -1,   -1,   -1,   -1,   -1,   -1,   -1,   -1,
      -1,   -1,   -1,   -1,   -1,   -1,   -1,   -1,
      -1,   -1,   -1,   -1,   -1,   -1,   -1,   -1,
      -1,   -1,   -1,   -1,   -1,   -1,   -1,   -1,
      -1,   -1,   -1,   -1,   -1,   -1,   -1, 4227,
      -1,   -1,   -1,   -1,   -1,   -1,   -1,   -1,
      -1,   -1,   -1,   -1,   -1,   -1,   -1,   -1,
      -1,   -1,   -1,   -1,   -1,   -1,   -1,   -1,
      -1,   -1,   -1,   -1,   -1,   -1,   -1,   -1,
      -1,   -1,   -1,   -1,   -1,   -1,   -1,   -1,
      -1,   -1, 4228,   -1,   -1,   -1,   -1,   -1,
      -1,   -1,   -1,   -1,   -1,   -1,   -1,   -1,
      -1,   -1,   -1,   -1,   -1,   -1,   -1,   -1,
      -1,   -1,   -1,   -1,   -1,   -1,   -1,   -1,
      -1,   -1,   -1,   -1,   -1,   -1,   -1,   -1,
      -1,   -1,   -1,   -1,   -1,   -1,   -1,   -1,
      -1,   -1,   -1,   -1,   -1,   -1,   -1,   -1,
      -1,   -1,   -1,   -1,   -1,   -1,   -1,   -1,
      -1,   -1,   -1,   -1,   -1,   -1,   -1,   -1,
      -1,   -1,   -1,   -1,   -1,   -1,   -1,   -1,
      -1,   -1,   -1,   -1,   -1,   -1,   -1,   -1,
      -1,   -1,   -1,   -1,   -1,   -1,   -1,   -1,
      -1,   -1,   -1,   -1,   -1,   -1,   -1,   -1,
      -1,   -1,   -1,   -1,   -1,   -1,   -1,   -1,
      -1,   -1,   -1,   -1,   -1,   -1,   -1,   -1,
      -1,   -1,   -1,   -1,   -1,   -1,   -1,   -1,
      -1,   -1,   -1,   -1,   -1,   -1,   -1,   -1,
      -1,   -1,   -1,   -1,   -1,   -1,   -1,   -1,
      -1,   -1,   -1,   -1,   -1,   -1,   -1,   -1,
      -1,   -1,   -1,   -1,   -1,   -1,   -1,   -1,
      -1,   -1,   -1,   -1,   -1,   -1,   -1,   -1,
      -1,   -1,   -1,   -1,   -1,   -1,   -1,   -1,
      -1,   -1,   -1,   -1,   -1,   -1,   -1,   -1,
      -1,   -1,   -1,   -1,   -1,   -1,   -1,   -1,
      -1,   -1,   -1,   -1,   -1,   -1,   -1,   -1,
      -1,   -1,   -1,   -1,   -1,   -1,   -1, 4229,
      -1,   -1,   -1,   -1,   -1,   -1,   -1,   -1,
      -1,   -1,   -1,   -1,   -1,   -1,   -1,   -1,
      -1,   -1,   -1,   -1,   -1,   -1,   -1,   -1,
      -1,   -1,   -1,   -1,   -1,   -1,   -1,   -1,
      -1,   -1,   -1,   -1,   -1,   -1,   -1,   -1,
      -1,   -1,   -1,   -1,   -1,   -1,   -1,   -1,
      -1,   -1,   -1,   -1,   -1,   -1,   -1,   -1,
      -1,   -1,   -1,   -1,   -1,   -1,   -1,   -1,
      -1,   -1,   -1,   -1,   -1,   -1,   -1,   -1,
      -1,   -1,   -1,   -1,   -1,   -1,   -1,   -1,
      -1,   -1,   -1,   -1,   -1,   -1,   -1,   -1,
      -1,   -1,   -1,   -1,   -1,   -1,   -1,   -1,
      -1,   -1,   -1,   -1,   -1,   -1,   -1,   -1,
      -1,   -1,   -1,   -1,   -1,   -1,   -1,   -1,
      -1,   -1,   -1,   -1,   -1,   -1,   -1,   -1,
      -1,   -1,   -1,   -1,   -1,   -1,   -1,   -1,
      -1,   -1,   -1,   -1,   -1,   -1,   -1,   -1,
      -1,   -1,   -1,   -1,   -1,   -1,   -1,   -1,
      -1,   -1,   -1,   -1,   -1,   -1,   -1,   -1,
      -1, 4230,   -1,   -1,   -1,   -1,   -1,   -1,
      -1,   -1,   -1,   -1,   -1,   -1,   -1,   -1,
      -1,   -1,   -1,   -1,   -1,   -1,   -1,   -1,
      -1,   -1,   -1,   -1,   -1,   -1,   -1,   -1,
      -1,   -1,   -1,   -1,   -1,   -1,   -1,   -1,
      -1,   -1,   -1,   -1,   -1,   -1,   -1,   -1,
    4231,   -1,   -1,   -1,   -1,   -1,   -1,   -1,
      -1,   -1,   -1,   -1,   -1,   -1,   -1,   -1,
      -1,   -1,   -1,   -1,   -1,   -1,   -1,   -1,
      -1,   -1,   -1,   -1,   -1,   -1,   -1,   -1,
      -1,   -1,   -1,   -1,   -1,   -1,   -1,   -1,
      -1,   -1,   -1,   -1,   -1,   -1,   -1,   -1,
      -1,   -1,   -1,   -1,   -1,   -1,   -1,   -1,
      -1,   -1,   -1,   -1,   -1,   -1,   -1,   -1,
      -1,   -1,   -1,   -1,   -1,   -1,   -1,   -1,
      -1,   -1,   -1,   -1,   -1,   -1,   -1,   -1,
      -1,   -1,   -1,   -1,   -1,   -1,   -1,   -1,
      -1,   -1,   -1,   -1,   -1,   -1,   -1,   -1,
      -1,   -1,   -1,   -1,   -1,   -1,   -1,   -1,
      -1,   -1,   -1,   -1,   -1,   -1,   -1,   -1,
      -1,   -1,   -1,   -1,   -1,   -1,   -1,   -1,
      -1,   -1,   -1,   -1,   -1,   -1,   -1,   -1,
      -1,   -1,   -1,   -1,   -1,   -1,   -1,   -1,
      -1,   -1,   -1,   -1,   -1,   -1,   -1,   -1,
      -1,   -1,   -1,   -1,   -1,   -1,   -1,   -1,
      -1,   -1,   -1,   -1,   -1,   -1,   -1,   -1,
      -1,   -1,   -1,   -1,   -1,   -1,   -1,   -1,
      -1,   -1,   -1,   -1,   -1,   -1,   -1,   -1,
      -1,   -1,   -1,   -1,   -1,   -1,   -1,   -1,
      -1,   -1,   -1,   -1,   -1,   -1,   -1,   -1,
      -1,   -1,   -1,   -1,   -1,   -1,   -1,   -1,
      -1,   -1,   -1,   -1,   -1,   -1,   -1,   -1,
      -1,   -1,   -1,   -1,   -1,   -1,   -1,   -1,
      -1,   -1,   -1,   -1,   -1,   -1,   -1,   -1,
      -1,   -1,   -1,   -1,   -1,   -1,   -1,   -1,
      -1,   -1, 4232,   -1,   -1,   -1,   -1,   -1,
      -1,   -1,   -1,   -1,   -1,   -1,   -1,   -1,
      -1,   -1,   -1,   -1,   -1,   -1,   -1,   -1,
      -1,   -1,   -1,   -1,   -1,   -1,   -1,   -1,
      -1,   -1,   -1,   -1,   -1,   -1,   -1,   -1,
      -1,   -1,   -1,   -1,   -1,   -1,   -1,   -1,
      -1,   -1,   -1,   -1, 4233,   -1,   -1,   -1,
      -1,   -1,   -1,   -1,   -1,   -1,   -1,   -1,
      -1,   -1,   -1,   -1,   -1,   -1,   -1,   -1,
      -1,   -1,   -1,   -1,   -1,   -1,   -1,   -1,
      -1,   -1,   -1,   -1,   -1,   -1,   -1,   -1,
      -1,   -1,   -1,   -1,   -1,   -1,   -1,   -1,
      -1,   -1,   -1,   -1,   -1,   -1,   -1,   -1,
      -1,   -1,   -1,   -1,   -1,   -1,   -1,   -1,
      -1,   -1,   -1,   -1,   -1,   -1,   -1,   -1,
      -1,   -1,   -1,   -1,   -1,   -1,   -1,   -1,
      -1,   -1,   -1,   -1,   -1,   -1,   -1,   -1,
      -1,   -1,   -1,   -1,   -1,   -1,   -1,   -1,
      -1,   -1,   -1,   -1, 4234,   -1,   -1,   -1,
      -1,   -1,   -1,   -1,   -1,   -1,   -1,   -1,
      -1,   -1,   -1,   -1,   -1,   -1,   -1,   -1,
      -1,   -1,   -1,   -1,   -1,   -1,   -1,   -1,
      -1,   -1,   -1,   -1,   -1,   -1,   -1,   -1,
      -1,   -1,   -1,   -1,   -1,   -1,   -1,   -1,
      -1,   -1,   -1,   -1,   -1,   -1,   -1,   -1,
      -1,   -1,   -1,   -1,   -1,   -1,   -1,   -1,
      -1,   -1,   -1,   -1,   -1,   -1,   -1,   -1,
      -1,   -1,   -1,   -1,   -1,   -1,   -1,   -1,
      -1,   -1,   -1,   -1,   -1,   -1,   -1,   -1,
      -1,   -1,   -1,   -1,   -1, 4235,   -1,   -1,
    4236,   -1,   -1,   -1,   -1,   -1,   -1,   -1,
      -1,   -1,   -1,   -1,   -1,   -1,   -1,   -1,
      -1,   -1,   -1,   -1,   -1,   -1,   -1,   -1,
      -1,   -1,   -1,   -1,   -1,   -1,   -1,   -1,
      -1,   -1,   -1,   -1,   -1,   -1,   -1,   -1,
      -1,   -1,   -1,   -1,   -1,   -1,   -1,   -1,
      -1,   -1,   -1,   -1,   -1,   -1,   -1,   -1,
      -1,   -1,   -1,   -1,   -1,   -1,   -1,   -1,
      -1,   -1,   -1,   -1,   -1,   -1,   -1,   -1,
      -1,   -1,   -1,   -1,   -1,   -1,   -1,   -1,
      -1,   -1,   -1,   -1,   -1,   -1,   -1,   -1,
      -1,   -1,   -1,   -1,   -1,   -1,   -1,   -1,
      -1,   -1,   -1,   -1,   -1,   -1,   -1,   -1,
      -1,   -1,   -1,   -1,   -1,   -1,   -1,   -1,
      -1,   -1,   -1,   -1,   -1,   -1,   -1,   -1,
      -1,   -1,   -1,   -1,   -1,   -1,   -1,   -1,
      -1,   -1,   -1,   -1,   -1,   -1,   -1,   -1,
      -1,   -1,   -1,   -1,   -1,   -1,   -1,   -1,
      -1,   -1,   -1,   -1,   -1,   -1,   -1,   -1,
      -1,   -1,   -1,   -1,   -1,   -1,   -1,   -1,
      -1,   -1,   -1,   -1,   -1,   -1,   -1,   -1,
      -1, 4237,   -1,   -1,   -1,   -1,   -1,   -1,
      -1,   -1,   -1,   -1,   -1,   -1,   -1,   -1,
      -1,   -1,   -1,   -1,   -1,   -1,   -1,   -1,
      -1,   -1,   -1,   -1,   -1,   -1,   -1,   -1,
      -1,   -1,   -1,   -1,   -1,   -1,   -1,   -1,
      -1,   -1,   -1,   -1,   -1,   -1,   -1,   -1,
      -1,   -1,   -1,   -1,   -1,   -1,   -1,   -1,
      -1,   -1,   -1,   -1,   -1,   -1,   -1,   -1,
      -1,   -1,   -1,   -1,   -1,   -1,   -1,   -1,
      -1,   -1,   -1,   -1,   -1,   -1,   -1,   -1,
      -1,   -1,   -1,   -1,   -1,   -1,   -1,   -1,
      -1,   -1,   -1,   -1,   -1,   -1,   -1,   -1,
      -1,   -1,   -1,   -1,   -1,   -1,   -1,   -1,
      -1,   -1,   -1,   -1,   -1,   -1,   -1,   -1,
      -1,   -1,   -1,   -1,   -1,   -1,   -1,   -1,
      -1,   -1,   -1,   -1,   -1,   -1,   -1,   -1,
      -1,   -1,   -1,   -1,   -1,   -1,   -1,   -1,
      -1,   -1,   -1,   -1,   -1,   -1,   -1,   -1,
      -1,   -1,   -1,   -1,   -1,   -1,   -1,   -1,
      -1,   -1,   -1,   -1,   -1,   -1,   -1,   -1,
      -1,   -1,   -1,   -1,   -1,   -1,   -1,   -1,
      -1,   -1, 4238,   -1,   -1,   -1,   -1,   -1,
      -1,   -1,   -1,   -1,   -1,   -1,   -1,   -1,
      -1,   -1,   -1,   -1,   -1,   -1,   -1,   -1,
      -1,   -1,   -1,   -1,   -1,   -1,   -1,   -1,
      -1,   -1,   -1,   -1,   -1,   -1,   -1,   -1,
      -1,   -1,   -1,   -1,   -1,   -1,   -1,   -1,
      -1,   -1,   -1,   -1,   -1,   -1,   -1,   -1,
      -1,   -1,   -1,   -1,   -1,   -1,   -1,   -1,
      -1,   -1,   -1,   -1,   -1,   -1,   -1,   -1,
      -1,   -1,   -1,   -1,   -1,   -1,   -1,   -1,
      -1,   -1,   -1,   -1,   -1,   -1,   -1,   -1,
      -1, 4239,   -1,   -1,   -1,   -1,   -1,   -1,
      -1,   -1,   -1,   -1, 4240,   -1,   -1,   -1,
      -1,   -1,   -1,   -1,   -1,   -1,   -1,   -1,
      -1,   -1,   -1,   -1,   -1,   -1,   -1,   -1,
      -1,   -1,   -1,   -1,   -1,   -1,   -1,   -1,
      -1,   -1,   -1,   -1,   -1,   -1,   -1,   -1,
      -1, 4241,   -1,   -1,   -1,   -1,   -1,   -1,
      -1,   -1,   -1,   -1,   -1,   -1,   -1,   -1,
      -1,   -1,   -1,   -1,   -1,   -1,   -1,   -1,
      -1,   -1,   -1,   -1,   -1,   -1,   -1,   -1,
      -1,   -1,   -1,   -1,   -1,   -1,   -1,   -1,
      -1,   -1,   -1,   -1,   -1,   -1,   -1,   -1,
      -1,   -1,   -1,   -1,   -1,   -1,   -1,   -1,
      -1,   -1,   -1,   -1,   -1,   -1,   -1,   -1,
      -1,   -1,   -1,   -1,   -1,   -1,   -1,   -1,
      -1,   -1,   -1,   -1,   -1,   -1,   -1,   -1,
      -1,   -1,   -1,   -1,   -1,   -1,   -1,   -1,
      -1,   -1,   -1,   -1,   -1,   -1,   -1,   -1,
      -1,   -1,   -1,   -1,   -1,   -1,   -1,   -1,
      -1,   -1,   -1,   -1,   -1,   -1,   -1,   -1,
      -1,   -1,   -1,   -1,   -1,   -1,   -1,   -1,
      -1,   -1,   -1,   -1,   -1,   -1,   -1,   -1,
      -1,   -1,   -1,   -1,   -1,   -1,   -1,   -1,
      -1,   -1,   -1,   -1,   -1,   -1,   -1,   -1,
      -1,   -1,   -1,   -1,   -1,   -1,   -1,   -1,
      -1,   -1,   -1,   -1,   -1,   -1,   -1,   -1,
      -1,   -1,   -1,   -1,   -1,   -1,   -1,   -1,
      -1,   -1,   -1,   -1,   -1,   -1,   -1,   -1,
      -1,   -1,   -1,   -1,   -1,   -1,   -1,   -1,
      -1,   -1,   -1,   -1,   -1,   -1,   -1,   -1,
      -1,   -1,   -1,   -1,   -1,   -1,   -1,   -1,
      -1,   -1,   -1,   -1,   -1,   -1,   -1,   -1,
      -1,   -1,   -1,   -1,   -1,   -1,   -1,   -1,
      -1,   -1,   -1,   -1,   -1,   -1,   -1,   -1,
      -1,   -1,   -1,   -1,   -1,   -1,   -1,   -1,
      -1,   -1,   -1,   -1,   -1,   -1,   -1,   -1,
      -1,   -1,   -1,   -1,   -1,   -1,   -1,   -1,
      -1,   -1,   -1,   -1,   -1,   -1,   -1,   -1,
      -1,   -1,   -1,   -1,   -1,   -1,   -1,   -1,
      -1,   -1,   -1,   -1,   -1,   -1,   -1,   -1,
      -1,   -1,   -1,   -1,   -1,   -1,   -1,   -1,
      -1,   -1,   -1,   -1,   -1,   -1,   -1,   -1,
      -1,   -1,   -1,   -1,   -1,   -1,   -1,   -1,
      -1,   -1,   -1,   -1,   -1,   -1,   -1,   -1,
      -1,   -1,   -1,   -1,   -1,   -1,   -1,   -1,
      -1,   -1,   -1,   -1,   -1,   -1,   -1,   -1,
      -1,   -1,   -1,   -1,   -1,   -1,   -1,   -1,
      -1,   -1,   -1,   -1,   -1,   -1,   -1,   -1,
      -1,   -1,   -1,   -1,   -1,   -1,   -1,   -1,
      -1,   -1,   -1,   -1,   -1,   -1,   -1,   -1,
      -1,   -1,   -1,   -1,   -1,   -1,   -1,   -1,
      -1,   -1,   -1,   -1,   -1,   -1,   -1,   -1,
      -1,   -1,   -1,   -1,   -1,   -1,   -1,   -1,
      -1,   -1,   -1,   -1,   -1,   -1,   -1,   -1,
      -1,   -1,   -1,   -1,   -1,   -1,   -1,   -1,
      -1,   -1,   -1,   -1,   -1,   -1,   -1,   -1,
      -1,   -1,   -1,   -1,   -1,   -1,   -1,   -1,
      -1,   -1,   -1,   -1,   -1,   -1,   -1,   -1,
      -1,   -1,   -1,   -1,   -1,   -1,   -1,   -1,
      -1,   -1,   -1,   -1,   -1,   -1,   -1,   -1,
      -1,   -1,   -1,   -1,   -1,   -1,   -1,   -1,
      -1,   -1,   -1,   -1,   -1,   -1,   -1,   -1,
      -1,   -1,   -1,   -1,   -1,   -1,   -1,   -1,
      -1,   -1,   -1,   -1,   -1,   -1,   -1,   -1,
      -1,   -1,   -1,   -1,   -1,   -1,   -1,   -1,
      -1,   -1,   -1,   -1,   -1,   -1,   -1,   -1,
      -1,   -1,   -1,   -1,   -1,   -1,   -1,   -1,
      -1,   -1,   -1,   -1,   -1,   -1,   -1,   -1,
      -1,   -1,   -1,   -1,   -1,   -1,   -1,   -1,
      -1,   -1,   -1,   -1,   -1,   -1,   -1,   -1,
      -1,   -1,   -1,   -1,   -1,   -1,   -1,   -1,
      -1,   -1,   -1,   -1,   -1,   -1,   -1,   -1,
      -1,   -1,   -1,   -1,   -1,   -1,   -1,   -1,
      -1,   -1,   -1,   -1,   -1,   -1,   -1,   -1,
      -1,   -1,   -1,   -1,   -1,   -1,   -1,   -1,
      -1,   -1,   -1,   -1,   -1,   -1,   -1,   -1,
      -1,   -1,   -1,   -1,   -1,   -1,   -1,   -1,
      -1,   -1, 4242,   -1,   -1,   -1,   -1,   -1,
      -1,   -1,   -1,   -1,   -1,   -1,   -1,   -1,
      -1,   -1,   -1,   -1,   -1,   -1,   -1,   -1,
      -1,   -1,   -1,   -1,   -1,   -1,   -1,   -1,
      -1,   -1,   -1,   -1,   -1,   -1,   -1,   -1,
      -1,   -1,   -1,   -1,   -1,   -1,   -1,   -1,
      -1,   -1,   -1,   -1,   -1,   -1,   -1,   -1,
      -1,   -1,   -1,   -1,   -1,   -1,   -1,   -1,
      -1,   -1,   -1,   -1,   -1,   -1,   -1,   -1,
      -1,   -1,   -1,   -1,   -1,   -1,   -1,   -1,
      -1,   -1,   -1,   -1,   -1,   -1,   -1,   -1,
      -1,   -1,   -1,   -1,   -1,   -1,   -1,   -1,
      -1,   -1,   -1,   -1,   -1,   -1,   -1,   -1,
      -1,   -1,   -1,   -1,   -1,   -1,   -1,   -1,
      -1,   -1,   -1,   -1,   -1, 4243,   -1,   -1,
      -1,   -1,   -1,   -1,   -1,   -1,   -1,   -1,
      -1,   -1,   -1,   -1,   -1,   -1,   -1,   -1,
      -1,   -1,   -1,   -1,   -1,   -1,   -1,   -1,
      -1,   -1,   -1,   -1,   -1,   -1,   -1,   -1,
      -1,   -1,   -1,   -1,   -1,   -1,   -1,   -1,
      -1,   -1,   -1,   -1,   -1,   -1,   -1,   -1,
      -1,   -1,   -1,   -1,   -1,   -1,   -1,   -1,
      -1,   -1,   -1,   -1,   -1,   -1,   -1,   -1,
      -1,   -1,   -1,   -1,   -1,   -1,   -1,   -1,
      -1,   -1,   -1,   -1,   -1,   -1,   -1,   -1,
      -1,   -1,   -1,   -1,   -1,   -1,   -1,   -1,
      -1,   -1,   -1,   -1,   -1,   -1,   -1,   -1,
      -1,   -1,   -1,   -1,   -1,   -1,   -1,   -1,
      -1,   -1,   -1,   -1,   -1,   -1,   -1,   -1,
      -1,   -1,   -1,   -1,   -1,   -1,   -1,   -1,
      -1,   -1,   -1,   -1,   -1,   -1,   -1,   -1,
      -1,   -1,   -1,   -1,   -1,   -1,   -1, 4244,
      -1,   -1,   -1,   -1,   -1,   -1,   -1,   -1,
      -1,   -1,   -1,   -1,   -1,   -1,   -1,   -1,
      -1,   -1,   -1,   -1,   -1,   -1,   -1,   -1,
      -1,   -1,   -1,   -1, 4245,   -1,   -1,   -1,
      -1,   -1,   -1,   -1,   -1,   -1,   -1,   -1,
      -1,   -1,   -1,   -1,   -1,   -1,   -1,   -1,
      -1,   -1,   -1,   -1,   -1,   -1,   -1,   -1,
      -1,   -1,   -1, 4246,   -1,   -1,   -1,   -1,
      -1,   -1,   -1, 4247,   -1,   -1,   -1,   -1,
      -1,   -1,   -1,   -1,   -1,   -1,   -1,   -1,
      -1,   -1,   -1,   -1,   -1,   -1,   -1,   -1,
      -1,   -1,   -1,   -1,   -1,   -1,   -1,   -1,
      -1,   -1,   -1,   -1,   -1,   -1,   -1,   -1,
      -1,   -1,   -1,   -1,   -1,   -1,   -1,   -1,
      -1,   -1,   -1,   -1,   -1,   -1,   -1,   -1,
      -1,   -1,   -1,   -1,   -1,   -1,   -1,   -1,
      -1,   -1,   -1,   -1,   -1,   -1,   -1,   -1,
      -1,   -1,   -1,   -1,   -1,   -1,   -1,   -1,
      -1,   -1,   -1,   -1,   -1,   -1,   -1,   -1,
      -1,   -1,   -1,   -1,   -1,   -1,   -1,   -1,
      -1,   -1,   -1,   -1,   -1,   -1,   -1,   -1,
      -1,   -1,   -1,   -1,   -1,   -1,   -1,   -1,
      -1,   -1,   -1,   -1,   -1,   -1,   -1,   -1,
      -1,   -1,   -1,   -1,   -1,   -1,   -1,   -1,
      -1,   -1,   -1,   -1,   -1,   -1,   -1,   -1,
      -1, 4248,   -1,   -1,   -1,   -1,   -1,   -1,
      -1,   -1,   -1,   -1,   -1,   -1,   -1,   -1,
      -1,   -1,   -1,   -1,   -1,   -1,   -1,   -1,
      -1,   -1,   -1,   -1,   -1,   -1,   -1,   -1,
      -1,   -1,   -1,   -1,   -1,   -1,   -1,   -1,
      -1,   -1,   -1,   -1,   -1,   -1,   -1,   -1,
      -1,   -1,   -1,   -1,   -1,   -1,   -1,   -1,
      -1,   -1,   -1,   -1,   -1,   -1,   -1,   -1,
      -1,   -1,   -1,   -1,   -1,   -1,   -1,   -1,
      -1,   -1,   -1,   -1,   -1,   -1,   -1,   -1,
      -1,   -1,   -1,   -1,   -1,   -1, 4249,   -1,
      -1,   -1,   -1,   -1,   -1,   -1,   -1,   -1,
      -1,   -1,   -1,   -1,   -1,   -1,   -1,   -1,
      -1,   -1,   -1,   -1,   -1,   -1,   -1,   -1,
      -1,   -1,   -1,   -1,   -1,   -1,   -1,   -1,
      -1,   -1,   -1,   -1,   -1,   -1,   -1,   -1,
      -1,   -1,   -1,   -1,   -1,   -1,   -1,   -1,
      -1,   -1,   -1,   -1,   -1,   -1,   -1,   -1,
      -1,   -1,   -1,   -1,   -1,   -1,   -1,   -1,
      -1,   -1,   -1,   -1,   -1,   -1,   -1,   -1,
      -1,   -1,   -1,   -1,   -1,   -1,   -1,   -1,
      -1,   -1,   -1,   -1,   -1,   -1,   -1, 4250,
      -1,   -1,   -1,   -1,   -1,   -1,   -1,   -1,
      -1,   -1,   -1,   -1,   -1,   -1,   -1,   -1,
      -1,   -1,   -1,   -1,   -1,   -1,   -1,   -1,
      -1,   -1,   -1,   -1,   -1,   -1,   -1,   -1,
      -1,   -1,   -1,   -1,   -1,   -1,   -1,   -1,
      -1,   -1, 4251,   -1,   -1,   -1,   -1,   -1,
      -1,   -1,   -1,   -1,   -1,   -1,   -1,   -1,
      -1,   -1,   -1,   -1,   -1,   -1,   -1,   -1,
      -1,   -1,   -1,   -1,   -1,   -1,   -1,   -1,
      -1,   -1,   -1,   -1,   -1,   -1,   -1,   -1,
      -1,   -1,   -1,   -1,   -1,   -1,   -1,   -1,
      -1,   -1,   -1,   -1,   -1,   -1,   -1,   -1,
      -1,   -1,   -1,   -1,   -1,   -1,   -1,   -1,
      -1,   -1,   -1,   -1,   -1,   -1,   -1,   -1,
      -1,   -1,   -1,   -1,   -1,   -1,   -1,   -1,
      -1,   -1,   -1,   -1,   -1,   -1,   -1,   -1,
      -1,   -1,   -1,   -1,   -1,   -1,   -1,   -1,
      -1,   -1,   -1,   -1,   -1,   -1,   -1,   -1,
      -1,   -1,   -1,   -1,   -1,   -1,   -1,   -1,
      -1,   -1,   -1,   -1,   -1,   -1,   -1,   -1,
      -1,   -1,   -1,   -1,   -1,   -1,   -1,   -1,
      -1,   -1,   -1,   -1,   -1,   -1,   -1,   -1,
      -1,   -1,   -1,   -1,   -1,   -1,   -1,   -1,
      -1,   -1,   -1,   -1,   -1,   -1,   -1,   -1,
      -1,   -1,   -1,   -1,   -1,   -1,   -1,   -1,
      -1,   -1,   -1,   -1,   -1,   -1,   -1,   -1,
      -1,   -1,   -1,   -1,   -1,   -1,   -1,   -1,
      -1,   -1,   -1,   -1,   -1,   -1,   -1,   -1,
      -1,   -1,   -1,   -1,   -1,   -1,   -1,   -1,
      -1,   -1,   -1,   -1,   -1,   -1,   -1,   -1,
      -1,   -1,   -1,   -1,   -1,   -1,   -1,   -1,
      -1,   -1,   -1,   -1,   -1,   -1,   -1,   -1,
      -1,   -1,   -1,   -1,   -1,   -1,   -1,   -1,
      -1,   -1,   -1,   -1,   -1,   -1,   -1,   -1,
      -1,   -1,   -1,   -1,   -1,   -1,   -1,   -1,
      -1,   -1,   -1,   -1,   -1,   -1,   -1,   -1,
      -1,   -1,   -1,   -1,   -1,   -1,   -1,   -1,
      -1,   -1,   -1,   -1,   -1,   -1,   -1,   -1,
      -1,   -1,   -1,   -1,   -1,   -1,   -1,   -1,
      -1,   -1,   -1,   -1,   -1,   -1,   -1,   -1,
      -1,   -1,   -1,   -1,   -1,   -1,   -1,   -1,
      -1,   -1,   -1,   -1,   -1,   -1,   -1,   -1,
      -1,   -1,   -1,   -1,   -1,   -1,   -1,   -1,
      -1,   -1,   -1,   -1,   -1,   -1,   -1,   -1,
      -1,   -1,   -1,   -1,   -1,   -1,   -1,   -1,
      -1,   -1,   -1,   -1,   -1,   -1,   -1,   -1,
      -1,   -1,   -1,   -1,   -1,   -1,   -1,   -1,
      -1,   -1,   -1,   -1,   -1,   -1,   -1,   -1,
      -1,   -1,   -1,   -1,   -1,   -1,   -1,   -1,
      -1,   -1,   -1,   -1,   -1,   -1,   -1,   -1,
      -1,   -1,   -1,   -1,   -1,   -1,   -1,   -1,
      -1,   -1,   -1,   -1,   -1,   -1,   -1,   -1,
      -1,   -1,   -1,   -1,   -1,   -1,   -1,   -1,
      -1,   -1,   -1,   -1,   -1,   -1,   -1,   -1,
      -1,   -1,   -1,   -1, 4252,   -1,   -1,   -1,
      -1,   -1,   -1,   -1,   -1,   -1,   -1,   -1,
      -1,   -1,   -1,   -1,   -1,   -1,   -1,   -1,
      -1,   -1,   -1,   -1,   -1,   -1,   -1,   -1,
      -1,   -1,   -1,   -1,   -1,   -1,   -1,   -1,
      -1,   -1,   -1,   -1,   -1,   -1,   -1,   -1,
      -1,   -1,   -1,   -1,   -1,   -1,   -1,   -1,
      -1,   -1,   -1,   -1,   -1,   -1,   -1,   -1,
      -1,   -1,   -1,   -1,   -1,   -1,   -1,   -1,
      -1,   -1,   -1,   -1,   -1,   -1,   -1,   -1,
      -1,   -1,   -1,   -1,   -1,   -1,   -1,   -1,
      -1,   -1,   -1,   -1,   -1,   -1,   -1,   -1,
      -1,   -1,   -1,   -1,   -1,   -1,   -1,   -1,
      -1,   -1,   -1,   -1,   -1,   -1,   -1,   -1,
      -1,   -1,   -1,   -1,   -1,   -1,   -1,   -1,
      -1,   -1,   -1,   -1,   -1,   -1,   -1,   -1,
      -1,   -1,   -1,   -1,   -1,   -1,   -1,   -1,
      -1,   -1,   -1,   -1,   -1,   -1,   -1,   -1,
      -1,   -1,   -1,   -1,   -1,   -1,   -1,   -1,
      -1,   -1,   -1,   -1,   -1,   -1,   -1,   -1,
      -1,   -1,   -1,   -1,   -1,   -1,   -1,   -1,
      -1,   -1,   -1,   -1,   -1,   -1,   -1,   -1,
      -1,   -1,   -1,   -1,   -1,   -1,   -1,   -1,
      -1,   -1,   -1,   -1,   -1,   -1,   -1,   -1,
      -1,   -1,   -1,   -1,   -1,   -1, 4253,   -1,
      -1,   -1,   -1,   -1,   -1,   -1,   -1,   -1,
      -1,   -1,   -1,   -1,   -1,   -1,   -1,   -1,
      -1,   -1,   -1,   -1,   -1,   -1,   -1,   -1,
      -1,   -1,   -1,   -1,   -1,   -1,   -1,   -1,
      -1,   -1,   -1,   -1,   -1,   -1,   -1,   -1,
      -1,   -1,   -1,   -1,   -1,   -1,   -1,   -1,
      -1,   -1,   -1,   -1,   -1,   -1,   -1,   -1,
      -1,   -1,   -1,   -1,   -1,   -1,   -1,   -1,
      -1,   -1,   -1,   -1,   -1,   -1,   -1,   -1,
      -1,   -1,   -1,   -1,   -1,   -1,   -1,   -1,
      -1,   -1,   -1,   -1,   -1,   -1,   -1,   -1,
      -1,   -1,   -1,   -1,   -1,   -1,   -1,   -1,
      -1,   -1,   -1,   -1,   -1,   -1,   -1,   -1,
      -1,   -1,   -1,   -1,   -1,   -1,   -1,   -1,
      -1,   -1,   -1,   -1,   -1,   -1,   -1,   -1,
      -1,   -1,   -1,   -1,   -1,   -1,   -1,   -1,
      -1,   -1,   -1,   -1,   -1,   -1,   -1,   -1,
      -1,   -1,   -1,   -1,   -1,   -1,   -1,   -1,
      -1,   -1,   -1,   -1,   -1,   -1,   -1,   -1,
      -1,   -1,   -1,   -1,   -1,   -1,   -1,   -1,
      -1,   -1,   -1,   -1,   -1,   -1,   -1,   -1,
      -1,   -1,   -1,   -1,   -1,   -1,   -1,   -1,
      -1,   -1,   -1,   -1,   -1,   -1,   -1,   -1,
      -1,   -1,   -1,   -1,   -1,   -1,   -1,   -1,
      -1,   -1,   -1,   -1,   -1,   -1,   -1,   -1,
      -1,   -1,   -1,   -1,   -1,   -1,   -1,   -1,
    4254,   -1,   -1,   -1,   -1,   -1,   -1,   -1,
      -1,   -1,   -1,   -1,   -1,   -1,   -1,   -1,
      -1,   -1,   -1,   -1,   -1,   -1,   -1,   -1,
      -1,   -1,   -1,   -1,   -1,   -1,   -1,   -1,
      -1,   -1,   -1,   -1,   -1,   -1,   -1,   -1,
      -1,   -1,   -1,   -1,   -1,   -1,   -1,   -1,
      -1,   -1,   -1,   -1,   -1,   -1,   -1,   -1,
      -1,   -1,   -1,   -1,   -1,   -1,   -1,   -1,
      -1,   -1,   -1,   -1,   -1,   -1,   -1,   -1,
      -1,   -1,   -1,   -1,   -1,   -1,   -1,   -1,
      -1,   -1,   -1,   -1,   -1,   -1,   -1,   -1,
      -1,   -1,   -1,   -1,   -1,   -1,   -1,   -1,
      -1,   -1,   -1,   -1,   -1,   -1,   -1,   -1,
      -1,   -1,   -1,   -1,   -1,   -1,   -1,   -1,
      -1,   -1,   -1,   -1,   -1,   -1,   -1,   -1,
      -1,   -1,   -1,   -1,   -1,   -1,   -1,   -1,
      -1,   -1,   -1,   -1,   -1,   -1,   -1,   -1,
      -1,   -1,   -1,   -1,   -1,   -1,   -1,   -1,
      -1,   -1,   -1,   -1,   -1,   -1,   -1,   -1,
      -1,   -1,   -1,   -1,   -1,   -1,   -1,   -1,
      -1,   -1,   -1,   -1,   -1,   -1,   -1,   -1,
      -1,   -1,   -1,   -1,   -1,   -1,   -1,   -1,
      -1,   -1,   -1,   -1,   -1,   -1,   -1,   -1,
      -1,   -1,   -1,   -1,   -1,   -1,   -1,   -1,
      -1,   -1,   -1,   -1,   -1,   -1,   -1,   -1,
      -1,   -1,   -1,   -1,   -1,   -1,   -1,   -1,
      -1,   -1,   -1,   -1,   -1,   -1,   -1,   -1,
      -1,   -1,   -1,   -1,   -1,   -1,   -1,   -1,
      -1,   -1,   -1,   -1,   -1,   -1,   -1,   -1,
      -1,   -1,   -1,   -1,   -1,   -1,   -1,   -1,
      -1,   -1,   -1,   -1,   -1,   -1,   -1,   -1,
      -1,   -1,   -1,   -1,   -1,   -1,   -1,   -1,
      -1,   -1,   -1,   -1,   -1,   -1,   -1,   -1,
      -1,   -1,   -1,   -1,   -1,   -1,   -1,   -1,
      -1,   -1,   -1,   -1,   -1,   -1,   -1,   -1,
      -1,   -1,   -1,   -1,   -1,   -1,   -1,   -1,
      -1,   -1,   -1,   -1,   -1,   -1,   -1,   -1,
      -1,   -1,   -1,   -1,   -1,   -1,   -1,   -1,
      -1,   -1,   -1,   -1,   -1,   -1,   -1,   -1,
      -1,   -1,   -1,   -1,   -1,   -1,   -1,   -1,
      -1,   -1,   -1,   -1,   -1,   -1,   -1,   -1,
      -1,   -1,   -1,   -1,   -1,   -1,   -1,   -1,
      -1,   -1,   -1,   -1,   -1,   -1,   -1,   -1,
      -1,   -1,   -1,   -1,   -1,   -1,   -1,   -1,
      -1,   -1,   -1,   -1,   -1,   -1,   -1,   -1,
      -1,   -1,   -1,   -1,   -1,   -1,   -1,   -1,
      -1,   -1,   -1,   -1,   -1,   -1,   -1,   -1,
      -1,   -1,   -1,   -1,   -1,   -1,   -1,   -1,
      -1,   -1,   -1,   -1,   -1,   -1,   -1,   -1,
      -1,   -1,   -1,   -1,   -1,   -1,   -1,   -1,
      -1,   -1,   -1,   -1,   -1,   -1,   -1,   -1,
      -1,   -1,   -1,   -1,   -1,   -1,   -1,   -1,
      -1,   -1,   -1,   -1,   -1,   -1,   -1,   -1,
      -1,   -1,   -1,   -1,   -1,   -1, 4255,   -1,
      -1,   -1,   -1,   -1,   -1,   -1,   -1,   -1,
      -1,   -1,   -1,   -1,   -1,   -1,   -1,   -1,
      -1,   -1,   -1,   -1,   -1,   -1,   -1,   -1,
      -1,   -1,   -1,   -1,   -1,   -1,   -1,   -1,
      -1,   -1,   -1,   -1,   -1,   -1,   -1,   -1,
      -1,   -1,   -1,   -1,   -1,   -1,   -1,   -1,
      -1,   -1,   -1,   -1,   -1,   -1,   -1,   -1,
      -1,   -1,   -1,   -1,   -1,   -1,   -1,   -1,
      -1,   -1,   -1,   -1,   -1,   -1,   -1,   -1,
      -1,   -1,   -1,   -1,   -1,   -1,   -1,   -1,
      -1,   -1,   -1,   -1,   -1,   -1,   -1,   -1,
      -1,   -1,   -1,   -1,   -1,   -1,   -1,   -1,
      -1,   -1,   -1,   -1,   -1,   -1,   -1,   -1,
      -1,   -1,   -1,   -1,   -1,   -1,   -1,   -1,
      -1,   -1,   -1,   -1,   -1,   -1,   -1,   -1,
      -1,   -1,   -1,   -1,   -1,   -1,   -1,   -1,
      -1,   -1,   -1,   -1,   -1,   -1,   -1,   -1,
      -1,   -1,   -1,   -1,   -1,   -1,   -1,   -1,
      -1,   -1,   -1,   -1,   -1,   -1,   -1,   -1,
      -1,   -1,   -1,   -1,   -1,   -1,   -1,   -1,
      -1,   -1,   -1,   -1,   -1,   -1,   -1,   -1,
      -1,   -1,   -1,   -1,   -1,   -1,   -1,   -1,
      -1,   -1,   -1,   -1,   -1,   -1,   -1,   -1,
      -1,   -1,   -1,   -1,   -1,   -1,   -1,   -1,
      -1,   -1,   -1,   -1,   -1,   -1,   -1,   -1,
      -1,   -1,   -1,   -1,   -1,   -1,   -1,   -1,
      -1,   -1,   -1,   -1,   -1,   -1,   -1,   -1,
      -1,   -1,   -1,   -1,   -1,   -1,   -1,   -1,
      -1,   -1,   -1,   -1,   -1,   -1,   -1,   -1,
      -1,   -1,   -1,   -1,   -1,   -1,   -1,   -1,
      -1,   -1,   -1,   -1,   -1,   -1,   -1,   -1,
      -1,   -1,   -1,   -1,   -1,   -1,   -1, 4256,
      -1,   -1,   -1,   -1,   -1,   -1,   -1,   -1,
      -1,   -1,   -1,   -1,   -1,   -1,   -1,   -1,
      -1,   -1,   -1,   -1,   -1,   -1,   -1,   -1,
      -1,   -1,   -1,   -1,   -1,   -1,   -1,   -1,
      -1,   -1,   -1,   -1,   -1,   -1,   -1,   -1,
      -1,   -1,   -1,   -1,   -1,   -1,   -1,   -1,
      -1,   -1,   -1,   -1,   -1,   -1,   -1,   -1,
      -1,   -1,   -1,   -1,   -1,   -1,   -1,   -1,
      -1,   -1,   -1,   -1,   -1,   -1,   -1,   -1,
      -1,   -1,   -1,   -1,   -1,   -1,   -1,   -1,
      -1,   -1,   -1,   -1,   -1,   -1,   -1,   -1,
      -1,   -1,   -1,   -1,   -1,   -1,   -1,   -1,
      -1,   -1,   -1,   -1,   -1,   -1,   -1,   -1,
      -1,   -1,   -1,   -1,   -1,   -1,   -1,   -1,
      -1,   -1,   -1,   -1,   -1,   -1,   -1,   -1,
      -1,   -1,   -1,   -1,   -1,   -1,   -1,   -1,
      -1,   -1,   -1,   -1,   -1,   -1,   -1,   -1,
      -1,   -1,   -1,   -1,   -1,   -1,   -1,   -1,
      -1,   -1,   -1,   -1,   -1,   -1,   -1,   -1,
      -1,   -1,   -1,   -1,   -1,   -1,   -1,   -1,
      -1,   -1,   -1,   -1,   -1,   -1,   -1,   -1,
      -1,   -1,   -1,   -1,   -1,   -1,   -1,   -1,
      -1,   -1,   -1,   -1,   -1,   -1,   -1,   -1,
      -1,   -1,   -1,   -1,   -1,   -1,   -1,   -1,
      -1,   -1,   -1,   -1,   -1,   -1,   -1,   -1,
      -1,   -1,   -1,   -1,   -1,   -1,   -1,   -1,
      -1,   -1,   -1,   -1,   -1,   -1,   -1,   -1,
      -1,   -1,   -1,   -1,   -1,   -1,   -1,   -1,
      -1,   -1,   -1,   -1,   -1,   -1,   -1,   -1,
      -1,   -1,   -1,   -1,   -1,   -1,   -1,   -1,
      -1,   -1,   -1,   -1,   -1,   -1,   -1,   -1,
      -1,   -1,   -1,   -1,   -1,   -1,   -1,   -1,
      -1,   -1,   -1,   -1,   -1,   -1,   -1,   -1,
      -1,   -1,   -1,   -1,   -1,   -1,   -1,   -1,
      -1,   -1,   -1,   -1,   -1,   -1,   -1,   -1,
      -1,   -1,   -1,   -1,   -1,   -1,   -1,   -1,
      -1,   -1,   -1,   -1,   -1,   -1,   -1,   -1,
      -1,   -1,   -1,   -1,   -1,   -1,   -1,   -1,
      -1,   -1,   -1,   -1,   -1,   -1,   -1,   -1,
      -1,   -1,   -1,   -1,   -1,   -1,   -1,   -1,
      -1,   -1,   -1,   -1,   -1,   -1,   -1,   -1,
      -1,   -1,   -1,   -1,   -1,   -1,   -1,   -1,
      -1,   -1,   -1,   -1,   -1,   -1,   -1,   -1,
      -1,   -1,   -1,   -1,   -1,   -1,   -1,   -1,
      -1,   -1,   -1,   -1,   -1,   -1,   -1,   -1,
      -1,   -1,   -1,   -1,   -1,   -1,   -1,   -1,
      -1,   -1,   -1,   -1,   -1,   -1,   -1,   -1,
      -1,   -1,   -1,   -1,   -1,   -1,   -1,   -1,
      -1,   -1,   -1,   -1,   -1,   -1,   -1,   -1,
      -1,   -1,   -1,   -1,   -1,   -1,   -1,   -1,
      -1,   -1,   -1,   -1,   -1,   -1,   -1,   -1,
      -1,   -1,   -1,   -1,   -1,   -1,   -1,   -1,
      -1,   -1,   -1,   -1,   -1,   -1,   -1,   -1,
      -1,   -1,   -1,   -1,   -1,   -1,   -1,   -1,
      -1,   -1,   -1,   -1,   -1,   -1,   -1,   -1,
      -1,   -1,   -1,   -1,   -1,   -1,   -1,   -1,
      -1,   -1,   -1,   -1,   -1,   -1,   -1,   -1,
      -1,   -1,   -1,   -1,   -1,   -1,   -1,   -1,
      -1,   -1,   -1,   -1,   -1,   -1,   -1,   -1,
      -1,   -1,   -1,   -1,   -1,   -1,   -1,   -1,
      -1,   -1,   -1,   -1,   -1,   -1,   -1,   -1,
      -1,   -1,   -1,   -1,   -1,   -1,   -1,   -1,
      -1,   -1,   -1,   -1,   -1,   -1,   -1,   -1,
      -1,   -1,   -1,   -1,   -1,   -1,   -1,   -1,
      -1,   -1,   -1,   -1,   -1,   -1,   -1,   -1,
      -1,   -1,   -1,   -1,   -1,   -1,   -1,   -1,
      -1,   -1,   -1,   -1,   -1,   -1,   -1,   -1,
      -1,   -1,   -1,   -1,   -1,   -1,   -1,   -1,
      -1,   -1,   -1,   -1,   -1,   -1,   -1,   -1,
      -1,   -1,   -1,   -1,   -1,   -1,   -1,   -1,
      -1,   -1,   -1,   -1,   -1,   -1,   -1,   -1,
      -1,   -1,   -1,   -1,   -1,   -1,   -1,   -1,
      -1,   -1,   -1,   -1,   -1,   -1,   -1,   -1,
      -1,   -1,   -1,   -1,   -1,   -1,   -1,   -1,
      -1,   -1,   -1,   -1,   -1,   -1,   -1,   -1,
      -1,   -1,   -1,   -1,   -1,   -1,   -1,   -1,
      -1,   -1,   -1,   -1,   -1,   -1,   -1,   -1,
      -1,   -1,   -1,   -1,   -1,   -1,   -1,   -1,
      -1,   -1,   -1,   -1,   -1,   -1,   -1,   -1,
      -1,   -1,   -1,   -1,   -1,   -1,   -1,   -1,
      -1,   -1,   -1,   -1,   -1,   -1,   -1,   -1,
      -1,   -1,   -1,   -1,   -1,   -1,   -1,   -1,
      -1,   -1,   -1,   -1,   -1,   -1,   -1,   -1,
      -1,   -1,   -1,   -1,   -1,   -1,   -1,   -1,
      -1,   -1,   -1,   -1,   -1,   -1,   -1,   -1,
      -1,   -1,   -1,   -1,   -1,   -1,   -1,   -1,
      -1,   -1,   -1,   -1,   -1,   -1,   -1,   -1,
      -1,   -1,   -1,   -1,   -1,   -1,   -1,   -1,
      -1,   -1,   -1,   -1,   -1,   -1,   -1,   -1,
      -1,   -1,   -1,   -1,   -1,   -1,   -1,   -1,
      -1,   -1,   -1,   -1,   -1,   -1,   -1,   -1,
      -1,   -1,   -1,   -1,   -1,   -1,   -1,   -1,
      -1,   -1,   -1,   -1,   -1,   -1,   -1,   -1,
      -1,   -1,   -1,   -1,   -1,   -1,   -1,   -1,
      -1,   -1,   -1,   -1,   -1,   -1,   -1,   -1,
      -1,   -1,   -1,   -1,   -1,   -1,   -1, 4257,
      -1,   -1,   -1,   -1,   -1,   -1,   -1,   -1,
      -1,   -1,   -1,   -1,   -1,   -1,   -1,   -1,
      -1,   -1,   -1,   -1,   -1,   -1,   -1,   -1,
      -1,   -1,   -1,   -1,   -1,   -1,   -1,   -1,
      -1,   -1,   -1,   -1,   -1,   -1,   -1,   -1,
      -1,   -1,   -1,   -1,   -1,   -1,   -1,   -1,
      -1,   -1,   -1,   -1,   -1,   -1,   -1,   -1,
      -1,   -1,   -1,   -1,   -1,   -1,   -1,   -1,
      -1,   -1,   -1,   -1,   -1,   -1,   -1,   -1,
      -1,   -1,   -1,   -1,   -1,   -1,   -1,   -1,
      -1,   -1,   -1,   -1,   -1,   -1,   -1,   -1,
      -1,   -1,   -1,   -1,   -1,   -1,   -1,   -1,
      -1,   -1,   -1,   -1,   -1,   -1,   -1,   -1,
      -1,   -1,   -1,   -1,   -1,   -1,   -1,   -1,
      -1,   -1,   -1,   -1,   -1,   -1,   -1,   -1,
      -1,   -1,   -1,   -1,   -1,   -1,   -1,   -1,
      -1,   -1,   -1,   -1,   -1,   -1,   -1,   -1,
      -1,   -1,   -1,   -1,   -1,   -1,   -1,   -1,
      -1,   -1,   -1,   -1,   -1,   -1,   -1,   -1,
      -1,   -1,   -1,   -1,   -1,   -1,   -1,   -1,
      -1,   -1,   -1,   -1,   -1,   -1,   -1,   -1,
      -1,   -1,   -1,   -1,   -1,   -1,   -1,   -1,
      -1,   -1,   -1,   -1,   -1,   -1,   -1,   -1,
      -1,   -1,   -1,   -1,   -1,   -1,   -1,   -1,
      -1,   -1,   -1,   -1,   -1,   -1,   -1,   -1,
      -1,   -1,   -1,   -1,   -1,   -1,   -1,   -1,
      -1,   -1,   -1,   -1,   -1,   -1,   -1,   -1,
      -1,   -1,   -1,   -1,   -1,   -1,   -1,   -1,
      -1,   -1,   -1,   -1,   -1,   -1,   -1,   -1,
      -1,   -1,   -1,   -1,   -1,   -1,   -1,   -1,
      -1,   -1,   -1,   -1,   -1,   -1,   -1,   -1,
      -1,   -1,   -1,   -1,   -1,   -1,   -1,   -1,
      -1,   -1,   -1,   -1,   -1,   -1,   -1,   -1,
      -1,   -1,   -1,   -1,   -1,   -1,   -1,   -1,
      -1,   -1,   -1,   -1,   -1,   -1,   -1,   -1,
      -1,   -1,   -1,   -1,   -1,   -1,   -1,   -1,
      -1,   -1,   -1,   -1,   -1,   -1,   -1,   -1,
      -1,   -1,   -1,   -1,   -1,   -1,   -1,   -1,
      -1,   -1,   -1,   -1,   -1,   -1,   -1,   -1,
      -1,   -1,   -1,   -1,   -1,   -1,   -1,   -1,
      -1,   -1,   -1,   -1,   -1,   -1,   -1,   -1,
      -1,   -1,   -1,   -1,   -1,   -1,   -1,   -1,
      -1,   -1,   -1,   -1,   -1,   -1,   -1,   -1,
      -1,   -1,   -1,   -1,   -1,   -1,   -1,   -1,
      -1,   -1,   -1,   -1,   -1,   -1,   -1,   -1,
      -1,   -1,   -1,   -1,   -1,   -1,   -1,   -1,
      -1,   -1,   -1,   -1,   -1,   -1,   -1,   -1,
      -1,   -1,   -1,   -1,   -1,   -1,   -1,   -1,
      -1,   -1,   -1,   -1,   -1,   -1,   -1,   -1,
      -1,   -1,   -1,   -1,   -1, 4258,   -1,   -1,
      -1,   -1,   -1,   -1,   -1,   -1,   -1,   -1,
      -1,   -1,   -1,   -1,   -1,   -1,   -1,   -1,
      -1,   -1,   -1,   -1,   -1,   -1,   -1,   -1,
      -1,   -1,   -1,   -1,   -1,   -1,   -1,   -1,
      -1,   -1,   -1,   -1,   -1, 4259,   -1,   -1,
      -1,   -1,   -1,   -1,   -1,   -1,   -1,   -1,
      -1,   -1,   -1,   -1,   -1,   -1,   -1,   -1,
      -1,   -1,   -1,   -1,   -1,   -1,   -1,   -1,
      -1,   -1,   -1,   -1,   -1,   -1,   -1,   -1,
      -1,   -1,   -1,   -1,   -1,   -1,   -1,   -1,
      -1,   -1,   -1,   -1,   -1,   -1,   -1,   -1,
      -1,   -1,   -1,   -1,   -1,   -1,   -1,   -1,
      -1,   -1,   -1,   -1,   -1,   -1,   -1,   -1,
      -1,   -1,   -1,   -1,   -1,   -1,   -1,   -1,
      -1,   -1,   -1,   -1,   -1,   -1,   -1,   -1,
      -1,   -1,   -1,   -1,   -1,   -1,   -1,   -1,
      -1,   -1,   -1,   -1,   -1,   -1,   -1,   -1,
      -1,   -1,   -1,   -1,   -1,   -1,   -1,   -1,
      -1,   -1,   -1,   -1,   -1,   -1,   -1,   -1,
    4260,   -1,   -1,   -1,   -1,   -1,   -1,   -1,
      -1,   -1,   -1,   -1,   -1,   -1,   -1,   -1,
      -1,   -1,   -1,   -1,   -1,   -1,   -1,   -1,
      -1,   -1,   -1,   -1,   -1,   -1,   -1,   -1,
      -1,   -1,   -1,   -1,   -1,   -1,   -1,   -1,
      -1,   -1,   -1,   -1,   -1,   -1,   -1,   -1,
      -1,   -1,   -1,   -1,   -1,   -1,   -1,   -1,
      -1,   -1,   -1,   -1,   -1,   -1,   -1,   -1,
      -1,   -1,   -1,   -1,   -1,   -1,   -1,   -1,
      -1,   -1,   -1,   -1,   -1,   -1,   -1,   -1,
      -1,   -1,   -1,   -1,   -1,   -1,   -1,   -1,
      -1,   -1,   -1,   -1,   -1,   -1,   -1,   -1,
      -1,   -1,   -1,   -1,   -1,   -1,   -1,   -1,
      -1,   -1,   -1,   -1,   -1,   -1,   -1,   -1,
      -1,   -1,   -1,   -1,   -1,   -1,   -1,   -1,
      -1,   -1,   -1,   -1,   -1,   -1,   -1,   -1,
      -1,   -1,   -1,   -1,   -1,   -1,   -1,   -1,
      -1,   -1,   -1,   -1,   -1,   -1,   -1,   -1,
      -1,   -1,   -1,   -1,   -1,   -1,   -1,   -1,
      -1,   -1,   -1,   -1,   -1,   -1,   -1,   -1,
      -1,   -1,   -1,   -1,   -1,   -1,   -1,   -1,
      -1,   -1,   -1,   -1,   -1,   -1,   -1,   -1,
      -1,   -1,   -1,   -1,   -1,   -1,   -1,   -1,
      -1,   -1,   -1,   -1,   -1,   -1,   -1,   -1,
    4261,   -1,   -1,   -1,   -1,   -1,   -1,   -1,
      -1,   -1,   -1,   -1,   -1,   -1,   -1,   -1,
      -1,   -1,   -1,   -1,   -1,   -1,   -1,   -1,
      -1,   -1,   -1,   -1,   -1,   -1,   -1,   -1,
      -1,   -1,   -1,   -1,   -1,   -1,   -1,   -1,
      -1,   -1,   -1,   -1,   -1,   -1,   -1,   -1,
      -1,   -1,   -1,   -1,   -1,   -1,   -1,   -1,
      -1,   -1,   -1,   -1,   -1,   -1,   -1,   -1,
      -1,   -1,   -1,   -1,   -1,   -1,   -1,   -1,
      -1,   -1,   -1,   -1,   -1,   -1,   -1,   -1,
      -1,   -1,   -1,   -1,   -1,   -1,   -1,   -1,
      -1,   -1,   -1,   -1,   -1,   -1,   -1,   -1,
      -1,   -1,   -1,   -1,   -1,   -1,   -1,   -1,
      -1,   -1,   -1,   -1,   -1,   -1,   -1,   -1,
      -1,   -1,   -1,   -1,   -1,   -1,   -1,   -1,
      -1,   -1,   -1,   -1,   -1,   -1,   -1,   -1,
      -1,   -1,   -1,   -1,   -1,   -1,   -1,   -1,
      -1,   -1,   -1,   -1,   -1,   -1,   -1,   -1,
      -1,   -1,   -1,   -1,   -1,   -1,   -1,   -1,
      -1,   -1,   -1,   -1,   -1,   -1,   -1,   -1,
      -1,   -1,   -1,   -1,   -1,   -1,   -1,   -1,
      -1,   -1,   -1,   -1,   -1,   -1,   -1,   -1,
      -1,   -1,   -1,   -1,   -1,   -1,   -1,   -1,
      -1,   -1,   -1,   -1,   -1,   -1,   -1,   -1,
      -1,   -1,   -1,   -1,   -1,   -1,   -1,   -1,
      -1,   -1,   -1,   -1,   -1,   -1,   -1,   -1,
      -1,   -1,   -1,   -1,   -1,   -1,   -1,   -1,
      -1,   -1,   -1,   -1,   -1,   -1,   -1,   -1,
      -1,   -1,   -1,   -1,   -1,   -1,   -1,   -1,
      -1,   -1,   -1,   -1,   -1,   -1,   -1,   -1,
      -1,   -1,   -1,   -1,   -1,   -1,   -1,   -1,
      -1,   -1,   -1,   -1,   -1,   -1,   -1,   -1,
      -1,   -1,   -1,   -1,   -1,   -1,   -1,   -1,
      -1,   -1,   -1,   -1,   -1,   -1,   -1,   -1,
      -1,   -1,   -1,   -1,   -1,   -1,   -1,   -1,
      -1,   -1,   -1,   -1,   -1,   -1,   -1,   -1,
      -1,   -1,   -1,   -1,   -1,   -1,   -1,   -1,
      -1,   -1,   -1,   -1,   -1,   -1,   -1,   -1,
      -1,   -1,   -1,   -1,   -1,   -1,   -1,   -1,
      -1,   -1,   -1,   -1,   -1,   -1,   -1,   -1,
      -1,   -1,   -1,   -1,   -1,   -1,   -1,   -1,
      -1,   -1,   -1,   -1,   -1,   -1,   -1,   -1,
      -1,   -1,   -1,   -1,   -1,   -1,   -1,   -1,
      -1,   -1,   -1,   -1,   -1,   -1,   -1,   -1,
      -1,   -1,   -1,   -1,   -1,   -1,   -1,   -1,
      -1,   -1,   -1,   -1,   -1,   -1,   -1,   -1,
      -1,   -1,   -1,   -1,   -1,   -1,   -1,   -1,
      -1,   -1,   -1,   -1,   -1,   -1,   -1,   -1,
      -1,   -1,   -1,   -1,   -1,   -1,   -1,   -1,
      -1,   -1,   -1,   -1,   -1,   -1,   -1,   -1,
      -1,   -1,   -1,   -1,   -1,   -1,   -1,   -1,
      -1,   -1,   -1,   -1,   -1,   -1,   -1,   -1,
      -1,   -1,   -1,   -1,   -1,   -1,   -1,   -1,
      -1,   -1,   -1,   -1,   -1,   -1,   -1,   -1,
      -1,   -1,   -1,   -1,   -1,   -1,   -1,   -1,
      -1,   -1,   -1,   -1,   -1,   -1,   -1,   -1,
      -1,   -1,   -1,   -1,   -1,   -1,   -1,   -1,
      -1,   -1,   -1,   -1,   -1,   -1,   -1,   -1,
      -1,   -1,   -1,   -1,   -1,   -1,   -1,   -1,
      -1,   -1,   -1,   -1,   -1,   -1,   -1,   -1,
      -1,   -1,   -1,   -1,   -1,   -1,   -1,   -1,
      -1,   -1,   -1,   -1,   -1,   -1,   -1,   -1,
      -1,   -1,   -1,   -1,   -1,   -1,   -1,   -1,
      -1,   -1,   -1,   -1,   -1,   -1,   -1,   -1,
      -1,   -1,   -1,   -1,   -1,   -1,   -1,   -1,
      -1,   -1,   -1,   -1,   -1,   -1,   -1,   -1,
      -1,   -1,   -1,   -1,   -1,   -1,   -1,   -1,
      -1,   -1,   -1,   -1,   -1,   -1,   -1,   -1,
      -1,   -1,   -1,   -1,   -1,   -1,   -1,   -1,
      -1,   -1,   -1,   -1,   -1,   -1,   -1,   -1,
      -1,   -1,   -1,   -1,   -1,   -1,   -1,   -1,
      -1,   -1,   -1,   -1,   -1,   -1,   -1,   -1,
      -1,   -1,   -1,   -1,   -1,   -1,   -1,   -1,
      -1,   -1,   -1,   -1,   -1,   -1,   -1,   -1,
      -1,   -1,   -1,   -1,   -1,   -1,   -1,   -1,
    4262,   -1,   -1,   -1,   -1,   -1,   -1,   -1,
      -1,   -1,   -1,   -1,   -1,   -1,   -1,   -1,
      -1,   -1,   -1,   -1,   -1,   -1,   -1,   -1,
      -1,   -1,   -1,   -1,   -1,   -1,   -1,   -1,
      -1,   -1,   -1,   -1,   -1,   -1,   -1,   -1,
      -1,   -1,   -1,   -1,   -1,   -1,   -1,   -1,
      -1,   -1,   -1,   -1,   -1,   -1,   -1,   -1,
      -1,   -1,   -1,   -1,   -1,   -1,   -1,   -1,
      -1,   -1,   -1,   -1,   -1,   -1,   -1,   -1,
      -1,   -1,   -1,   -1,   -1,   -1,   -1,   -1,
      -1,   -1,   -1,   -1,   -1,   -1,   -1,   -1,
      -1,   -1,   -1,   -1,   -1,   -1,   -1,   -1,
      -1,   -1,   -1,   -1,   -1,   -1,   -1,   -1,
      -1,   -1,   -1,   -1,   -1,   -1,   -1,   -1,
      -1,   -1,   -1,   -1,   -1,   -1,   -1,   -1,
      -1,   -1,   -1,   -1,   -1,   -1,   -1,   -1,
      -1,   -1,   -1,   -1,   -1,   -1,   -1,   -1,
      -1,   -1,   -1,   -1,   -1,   -1,   -1,   -1,
      -1,   -1,   -1,   -1,   -1,   -1,   -1,   -1,
      -1,   -1,   -1,   -1,   -1,   -1,   -1,   -1,
      -1,   -1,   -1,   -1,   -1,   -1,   -1,   -1,
      -1,   -1,   -1,   -1,   -1,   -1,   -1,   -1,
      -1,   -1,   -1,   -1,   -1,   -1,   -1,   -1,
      -1,   -1,   -1,   -1,   -1,   -1,   -1,   -1,
      -1,   -1,   -1,   -1,   -1,   -1,   -1,   -1,
      -1,   -1,   -1,   -1,   -1,   -1,   -1,   -1,
      -1,   -1,   -1,   -1,   -1,   -1,   -1,   -1,
      -1,   -1,   -1,   -1,   -1,   -1,   -1,   -1,
      -1,   -1,   -1,   -1,   -1,   -1,   -1,   -1,
      -1,   -1,   -1,   -1,   -1,   -1,   -1,   -1,
      -1,   -1,   -1,   -1,   -1,   -1,   -1,   -1,
      -1,   -1,   -1,   -1,   -1,   -1,   -1,   -1,
      -1,   -1,   -1,   -1,   -1,   -1,   -1,   -1,
      -1,   -1,   -1,   -1,   -1,   -1,   -1,   -1,
      -1,   -1,   -1,   -1,   -1,   -1,   -1,   -1,
      -1,   -1,   -1,   -1,   -1,   -1,   -1,   -1,
      -1,   -1,   -1,   -1,   -1,   -1,   -1,   -1,
      -1,   -1,   -1,   -1,   -1,   -1,   -1,   -1,
      -1,   -1,   -1,   -1,   -1,   -1,   -1,   -1,
      -1,   -1,   -1,   -1,   -1,   -1,   -1,   -1,
      -1,   -1,   -1,   -1,   -1,   -1,   -1,   -1,
      -1,   -1,   -1,   -1,   -1,   -1,   -1,   -1,
      -1,   -1,   -1,   -1,   -1,   -1,   -1,   -1,
      -1,   -1,   -1,   -1,   -1,   -1,   -1,   -1,
      -1,   -1,   -1,   -1,   -1,   -1,   -1,   -1,
      -1,   -1,   -1,   -1,   -1,   -1,   -1,   -1,
      -1,   -1,   -1,   -1,   -1,   -1,   -1,   -1,
      -1,   -1,   -1,   -1,   -1,   -1,   -1,   -1,
      -1,   -1,   -1,   -1,   -1,   -1,   -1,   -1,
      -1,   -1,   -1,   -1,   -1,   -1,   -1,   -1,
      -1,   -1,   -1,   -1,   -1,   -1,   -1,   -1,
      -1,   -1,   -1,   -1,   -1,   -1,   -1,   -1,
      -1,   -1,   -1,   -1,   -1,   -1,   -1,   -1,
      -1,   -1,   -1,   -1,   -1,   -1,   -1,   -1,
      -1,   -1,   -1,   -1,   -1,   -1,   -1,   -1,
      -1,   -1,   -1,   -1,   -1,   -1,   -1,   -1,
      -1,   -1,   -1,   -1,   -1,   -1,   -1,   -1,
      -1,   -1,   -1,   -1,   -1,   -1,   -1,   -1,
      -1,   -1,   -1,   -1,   -1,   -1,   -1,   -1,
      -1,   -1,   -1,   -1,   -1,   -1,   -1,   -1,
      -1,   -1,   -1,   -1,   -1,   -1,   -1,   -1,
      -1,   -1,   -1,   -1,   -1,   -1,   -1,   -1,
      -1,   -1,   -1,   -1,   -1,   -1,   -1,   -1,
      -1,   -1,   -1,   -1,   -1,   -1,   -1,   -1,
      -1,   -1,   -1,   -1,   -1,   -1,   -1,   -1,
      -1,   -1,   -1,   -1,   -1,   -1,   -1,   -1,
      -1,   -1,   -1,   -1,   -1,   -1,   -1,   -1,
      -1,   -1,   -1,   -1,   -1,   -1,   -1,   -1,
      -1,   -1,   -1,   -1,   -1,   -1,   -1,   -1,
      -1,   -1,   -1,   -1,   -1,   -1,   -1,   -1,
      -1,   -1,   -1,   -1, 4263,   -1,   -1,   -1,
      -1,   -1,   -1,   -1,   -1,   -1,   -1,   -1,
      -1,   -1,   -1,   -1,   -1,   -1,   -1,   -1,
      -1,   -1,   -1,   -1,   -1,   -1,   -1,   -1,
      -1,   -1,   -1,   -1,   -1,   -1,   -1,   -1,
      -1,   -1,   -1,   -1,   -1,   -1,   -1,   -1,
      -1,   -1,   -1,   -1,   -1,   -1,   -1,   -1,
      -1,   -1,   -1,   -1,   -1,   -1,   -1,   -1,
      -1,   -1,   -1,   -1,   -1,   -1,   -1,   -1,
      -1,   -1,   -1,   -1,   -1,   -1,   -1,   -1,
      -1,   -1,   -1,   -1,   -1,   -1,   -1,   -1,
      -1,   -1,   -1,   -1,   -1,   -1,   -1,   -1,
      -1,   -1,   -1,   -1,   -1,   -1,   -1,   -1,
      -1,   -1,   -1,   -1,   -1,   -1,   -1,   -1,
      -1,   -1,   -1,   -1,   -1,   -1,   -1,   -1,
      -1,   -1,   -1,   -1,   -1,   -1,   -1,   -1,
      -1,   -1,   -1,   -1,   -1,   -1,   -1,   -1,
      -1,   -1,   -1,   -1,   -1,   -1,   -1,   -1,
      -1,   -1,   -1,   -1,   -1,   -1,   -1,   -1,
      -1,   -1,   -1,   -1,   -1,   -1,   -1,   -1,
      -1,   -1,   -1,   -1,   -1,   -1,   -1,   -1,
      -1,   -1,   -1,   -1,   -1,   -1,   -1,   -1,
      -1,   -1,   -1,   -1,   -1,   -1,   -1,   -1,
      -1,   -1,   -1,   -1,   -1,   -1,   -1,   -1,
      -1,   -1,   -1,   -1,   -1,   -1,   -1,   -1,
      -1,   -1,   -1,   -1,   -1,   -1,   -1,   -1,
      -1,   -1,   -1,   -1,   -1,   -1,   -1,   -1,
      -1,   -1,   -1,   -1,   -1,   -1,   -1,   -1,
      -1,   -1,   -1,   -1,   -1,   -1,   -1,   -1,
      -1,   -1,   -1,   -1,   -1,   -1,   -1,   -1,
      -1,   -1,   -1,   -1,   -1,   -1,   -1,   -1,
      -1,   -1,   -1,   -1,   -1,   -1,   -1,   -1,
      -1,   -1,   -1,   -1,   -1,   -1,   -1,   -1,
      -1,   -1,   -1,   -1,   -1,   -1,   -1,   -1,
      -1,   -1,   -1,   -1,   -1,   -1,   -1,   -1,
      -1,   -1,   -1,   -1,   -1,   -1,   -1,   -1,
      -1,   -1,   -1,   -1,   -1,   -1,   -1,   -1,
      -1,   -1,   -1,   -1,   -1,   -1,   -1,   -1,
      -1,   -1,   -1,   -1,   -1,   -1,   -1,   -1,
      -1,   -1,   -1,   -1,   -1,   -1,   -1,   -1,
      -1,   -1,   -1,   -1,   -1,   -1,   -1,   -1,
      -1,   -1,   -1,   -1,   -1,   -1,   -1,   -1,
      -1,   -1,   -1,   -1,   -1,   -1,   -1,   -1,
      -1,   -1,   -1,   -1,   -1,   -1,   -1,   -1,
      -1,   -1,   -1,   -1,   -1,   -1,   -1,   -1,
      -1,   -1,   -1,   -1,   -1,   -1,   -1,   -1,
      -1,   -1,   -1,   -1,   -1,   -1,   -1,   -1,
      -1,   -1,   -1,   -1,   -1,   -1,   -1,   -1,
      -1,   -1,   -1,   -1,   -1,   -1,   -1,   -1,
      -1,   -1,   -1,   -1,   -1,   -1,   -1,   -1,
      -1,   -1,   -1,   -1,   -1,   -1,   -1,   -1,
      -1,   -1,   -1,   -1,   -1,   -1,   -1,   -1,
      -1,   -1,   -1,   -1,   -1,   -1,   -1,   -1,
      -1,   -1,   -1,   -1,   -1,   -1,   -1,   -1,
      -1,   -1,   -1,   -1,   -1,   -1,   -1,   -1,
      -1,   -1,   -1,   -1,   -1,   -1,   -1,   -1,
      -1,   -1,   -1,   -1,   -1,   -1,   -1,   -1,
      -1,   -1,   -1,   -1,   -1,   -1,   -1,   -1,
      -1,   -1,   -1,   -1,   -1,   -1,   -1,   -1,
      -1,   -1,   -1,   -1,   -1,   -1,   -1,   -1,
      -1,   -1,   -1,   -1,   -1,   -1,   -1,   -1,
      -1,   -1,   -1,   -1,   -1,   -1,   -1,   -1,
      -1,   -1,   -1,   -1,   -1,   -1,   -1,   -1,
      -1,   -1,   -1,   -1,   -1,   -1,   -1,   -1,
      -1,   -1,   -1,   -1,   -1,   -1,   -1,   -1,
      -1,   -1,   -1,   -1,   -1,   -1,   -1,   -1,
      -1,   -1,   -1,   -1,   -1,   -1,   -1,   -1,
      -1,   -1,   -1,   -1,   -1,   -1,   -1,   -1,
      -1,   -1,   -1,   -1,   -1,   -1,   -1,   -1,
      -1,   -1,   -1,   -1,   -1,   -1,   -1,   -1,
      -1,   -1,   -1,   -1,   -1,   -1,   -1,   -1,
      -1,   -1,   -1,   -1,   -1,   -1,   -1,   -1,
      -1,   -1,   -1,   -1,   -1,   -1,   -1,   -1,
      -1,   -1,   -1,   -1,   -1,   -1,   -1,   -1,
      -1,   -1,   -1,   -1,   -1,   -1,   -1,   -1,
      -1,   -1,   -1,   -1,   -1,   -1,   -1,   -1,
      -1,   -1,   -1,   -1,   -1,   -1,   -1,   -1,
      -1,   -1,   -1,   -1,   -1,   -1, 4264,   -1,
      -1,   -1,   -1,   -1,   -1,   -1,   -1,   -1,
      -1,   -1,   -1,   -1,   -1,   -1,   -1,   -1,
      -1,   -1,   -1,   -1,   -1,   -1,   -1,   -1,
      -1,   -1,   -1,   -1,   -1,   -1,   -1,   -1,
      -1,   -1,   -1,   -1,   -1,   -1,   -1,   -1,
      -1,   -1,   -1,   -1,   -1,   -1,   -1,   -1,
      -1,   -1,   -1,   -1,   -1,   -1,   -1,   -1,
      -1,   -1,   -1,   -1,   -1,   -1,   -1,   -1,
      -1,   -1,   -1,   -1,   -1,   -1,   -1,   -1,
      -1,   -1,   -1,   -1,   -1,   -1,   -1,   -1,
      -1,   -1,   -1,   -1,   -1,   -1,   -1,   -1,
      -1,   -1,   -1,   -1,   -1,   -1,   -1,   -1,
      -1,   -1,   -1,   -1,   -1,   -1,   -1,   -1,
      -1,   -1,   -1,   -1,   -1,   -1,   -1,   -1,
      -1,   -1,   -1,   -1,   -1,   -1,   -1,   -1,
      -1,   -1,   -1,   -1,   -1,   -1,   -1,   -1,
      -1,   -1,   -1,   -1,   -1,   -1,   -1,   -1,
      -1,   -1,   -1,   -1,   -1,   -1,   -1,   -1,
      -1,   -1,   -1,   -1,   -1,   -1,   -1,   -1,
      -1,   -1,   -1,   -1,   -1,   -1,   -1,   -1,
      -1,   -1,   -1,   -1,   -1,   -1,   -1,   -1,
      -1,   -1,   -1,   -1,   -1,   -1,   -1,   -1,
      -1,   -1,   -1,   -1,   -1,   -1,   -1,   -1,
      -1,   -1,   -1,   -1,   -1,   -1,   -1,   -1,
      -1,   -1,   -1,   -1,   -1,   -1,   -1,   -1,
      -1,   -1,   -1,   -1,   -1,   -1,   -1,   -1,
      -1,   -1,   -1,   -1,   -1,   -1,   -1,   -1,
      -1,   -1,   -1,   -1,   -1,   -1,   -1,   -1,
      -1,   -1,   -1,   -1,   -1,   -1,   -1,   -1,
      -1,   -1,   -1,   -1,   -1,   -1,   -1,   -1,
      -1,   -1,   -1,   -1,   -1,   -1,   -1,   -1,
      -1,   -1,   -1,   -1,   -1,   -1,   -1,   -1,
      -1,   -1,   -1,   -1,   -1,   -1,   -1,   -1,
      -1,   -1,   -1,   -1,   -1,   -1,   -1,   -1,
      -1,   -1,   -1,   -1,   -1,   -1,   -1,   -1,
      -1,   -1,   -1,   -1,   -1,   -1,   -1,   -1,
      -1,   -1,   -1,   -1,   -1,   -1,   -1,   -1,
      -1,   -1,   -1,   -1,   -1,   -1,   -1,   -1,
      -1,   -1,   -1,   -1,   -1,   -1,   -1,   -1,
      -1,   -1,   -1,   -1,   -1,   -1,   -1,   -1,
      -1,   -1,   -1,   -1,   -1,   -1,   -1,   -1,
      -1,   -1,   -1,   -1,   -1,   -1,   -1,   -1,
      -1,   -1,   -1,   -1,   -1,   -1,   -1,   -1,
      -1,   -1,   -1,   -1,   -1,   -1,   -1,   -1,
      -1,   -1,   -1,   -1,   -1,   -1,   -1,   -1,
      -1,   -1,   -1,   -1,   -1,   -1,   -1,   -1,
      -1,   -1,   -1,   -1,   -1,   -1,   -1,   -1,
      -1,   -1,   -1,   -1,   -1,   -1,   -1,   -1,
      -1,   -1,   -1,   -1,   -1,   -1,   -1,   -1,
      -1,   -1,   -1,   -1,   -1,   -1,   -1,   -1,
      -1,   -1,   -1,   -1,   -1,   -1,   -1,   -1,
      -1,   -1,   -1,   -1,   -1,   -1,   -1,   -1,
      -1,   -1,   -1,   -1,   -1,   -1,   -1,   -1,
      -1,   -1,   -1,   -1,   -1,   -1,   -1,   -1,
      -1,   -1,   -1,   -1,   -1,   -1,   -1,   -1,
      -1,   -1,   -1,   -1,   -1,   -1,   -1,   -1,
      -1,   -1,   -1,   -1,   -1,   -1,   -1,   -1,
      -1,   -1,   -1,   -1,   -1,   -1,   -1,   -1,
      -1,   -1,   -1,   -1,   -1,   -1,   -1,   -1,
      -1,   -1,   -1,   -1,   -1,   -1,   -1,   -1,
      -1,   -1,   -1,   -1,   -1,   -1,   -1,   -1,
      -1,   -1,   -1,   -1,   -1,   -1,   -1, 4265,
      -1,   -1,   -1,   -1,   -1,   -1,   -1,   -1,
      -1,   -1,   -1,   -1,   -1,   -1,   -1,   -1,
      -1,   -1,   -1,   -1,   -1,   -1,   -1,   -1,
      -1,   -1,   -1,   -1,   -1,   -1,   -1,   -1,
      -1,   -1,   -1,   -1,   -1,   -1,   -1,   -1,
      -1,   -1,   -1,   -1,   -1,   -1,   -1,   -1,
      -1,   -1,   -1,   -1,   -1,   -1,   -1,   -1,
      -1,   -1,   -1,   -1,   -1,   -1,   -1,   -1,
      -1,   -1,   -1,   -1,   -1,   -1,   -1,   -1,
      -1,   -1,   -1,   -1,   -1,   -1,   -1,   -1,
      -1,   -1,   -1,   -1,   -1,   -1,   -1,   -1,
      -1,   -1,   -1,   -1,   -1,   -1,   -1,   -1,
      -1,   -1,   -1,   -1,   -1,   -1,   -1,   -1,
      -1,   -1,   -1,   -1,   -1,   -1,   -1,   -1,
      -1,   -1,   -1,   -1,   -1,   -1,   -1,   -1,
      -1,   -1,   -1,   -1,   -1,   -1,   -1,   -1,
      -1,   -1,   -1,   -1,   -1,   -1,   -1,   -1,
      -1,   -1,   -1,   -1,   -1,   -1,   -1,   -1,
      -1,   -1,   -1,   -1,   -1,   -1,   -1,   -1,
      -1,   -1,   -1,   -1,   -1,   -1,   -1,   -1,
      -1,   -1,   -1,   -1,   -1,   -1,   -1,   -1,
      -1,   -1,   -1,   -1,   -1,   -1,   -1,   -1,
      -1,   -1,   -1,   -1,   -1,   -1,   -1,   -1,
      -1,   -1,   -1,   -1,   -1,   -1,   -1,   -1,
      -1,   -1,   -1,   -1,   -1,   -1,   -1,   -1,
      -1,   -1,   -1,   -1,   -1,   -1,   -1,   -1,
      -1,   -1,   -1,   -1,   -1,   -1,   -1,   -1,
      -1,   -1,   -1,   -1,   -1,   -1,   -1,   -1,
      -1,   -1,   -1,   -1,   -1,   -1,   -1,   -1,
      -1,   -1,   -1,   -1,   -1,   -1,   -1,   -1,
      -1,   -1,   -1,   -1,   -1,   -1,   -1,   -1,
      -1,   -1,   -1,   -1,   -1,   -1,   -1,   -1,
      -1,   -1,   -1,   -1,   -1,   -1,   -1,   -1,
      -1,   -1,   -1,   -1,   -1,   -1,   -1,   -1,
      -1,   -1,   -1,   -1,   -1,   -1,   -1,   -1,
      -1,   -1,   -1,   -1,   -1,   -1,   -1,   -1,
      -1,   -1,   -1,   -1,   -1,   -1,   -1,   -1,
      -1,   -1,   -1,   -1,   -1,   -1,   -1,   -1,
      -1,   -1,   -1,   -1,   -1,   -1,   -1,   -1,
      -1,   -1,   -1,   -1,   -1,   -1,   -1,   -1,
      -1,   -1,   -1,   -1,   -1,   -1,   -1,   -1,
      -1,   -1,   -1,   -1,   -1,   -1,   -1,   -1,
      -1,   -1,   -1,   -1,   -1,   -1,   -1,   -1,
      -1,   -1,   -1,   -1,   -1,   -1,   -1,   -1,
      -1,   -1,   -1,   -1,   -1,   -1,   -1,   -1,
      -1,   -1,   -1,   -1,   -1,   -1,   -1,   -1,
      -1,   -1,   -1,   -1,   -1,   -1,   -1,   -1,
      -1,   -1,   -1,   -1,   -1,   -1,   -1,   -1,
      -1,   -1,   -1,   -1,   -1,   -1,   -1,   -1,
      -1,   -1,   -1,   -1,   -1,   -1,   -1,   -1,
      -1,   -1,   -1,   -1,   -1,   -1,   -1,   -1,
      -1,   -1,   -1,   -1,   -1,   -1,   -1,   -1,
      -1,   -1,   -1,   -1,   -1,   -1,   -1,   -1,
      -1,   -1,   -1,   -1,   -1,   -1,   -1,   -1,
      -1,   -1,   -1,   -1,   -1,   -1,   -1,   -1,
      -1,   -1,   -1,   -1,   -1,   -1,   -1,   -1,
      -1,   -1,   -1,   -1,   -1,   -1,   -1,   -1,
      -1,   -1,   -1,   -1,   -1,   -1,   -1,   -1,
      -1,   -1,   -1,   -1,   -1,   -1,   -1,   -1,
      -1,   -1,   -1,   -1,   -1,   -1,   -1,   -1,
      -1,   -1,   -1,   -1,   -1,   -1,   -1,   -1,
      -1,   -1,   -1,   -1,   -1,   -1,   -1,   -1,
      -1,   -1,   -1,   -1,   -1,   -1,   -1,   -1,
      -1,   -1,   -1,   -1,   -1,   -1,   -1,   -1,
      -1,   -1,   -1,   -1,   -1,   -1,   -1,   -1,
      -1,   -1,   -1,   -1,   -1,   -1,   -1,   -1,
      -1,   -1,   -1,   -1,   -1,   -1,   -1,   -1,
      -1,   -1,   -1,   -1,   -1,   -1,   -1,   -1,
      -1,   -1,   -1,   -1,   -1,   -1,   -1,   -1,
      -1,   -1,   -1,   -1,   -1,   -1,   -1,   -1,
      -1,   -1,   -1,   -1,   -1,   -1,   -1,   -1,
      -1,   -1,   -1,   -1,   -1,   -1,   -1,   -1,
      -1,   -1,   -1,   -1,   -1,   -1,   -1,   -1,
      -1,   -1,   -1,   -1,   -1,   -1,   -1,   -1,
      -1,   -1,   -1,   -1,   -1,   -1,   -1,   -1,
      -1,   -1,   -1,   -1,   -1,   -1,   -1,   -1,
      -1,   -1,   -1,   -1,   -1,   -1,   -1,   -1,
      -1,   -1,   -1,   -1,   -1,   -1,   -1,   -1,
      -1,   -1,   -1,   -1,   -1,   -1,   -1,   -1,
      -1,   -1,   -1,   -1,   -1,   -1,   -1,   -1,
      -1,   -1,   -1,   -1,   -1,   -1,   -1,   -1,
      -1,   -1,   -1,   -1,   -1,   -1,   -1,   -1,
      -1,   -1,   -1,   -1,   -1,   -1,   -1,   -1,
      -1,   -1,   -1,   -1,   -1,   -1,   -1,   -1,
      -1,   -1,   -1,   -1,   -1,   -1,   -1,   -1,
      -1,   -1,   -1,   -1,   -1,   -1,   -1,   -1,
      -1,   -1,   -1,   -1,   -1,   -1,   -1,   -1,
      -1,   -1,   -1,   -1,   -1,   -1,   -1,   -1,
      -1,   -1,   -1,   -1,   -1,   -1,   -1,   -1,
      -1,   -1,   -1,   -1,   -1,   -1,   -1,   -1,
      -1,   -1,   -1,   -1,   -1,   -1,   -1,   -1,
      -1,   -1,   -1,   -1,   -1,   -1,   -1,   -1,
      -1,   -1,   -1,   -1,   -1,   -1,   -1,   -1,
      -1,   -1,   -1,   -1,   -1,   -1,   -1,   -1,
      -1,   -1,   -1,   -1,   -1,   -1,   -1,   -1,
      -1,   -1,   -1,   -1,   -1,   -1,   -1,   -1,
      -1,   -1,   -1,   -1,   -1,   -1,   -1,   -1,
      -1,   -1,   -1,   -1,   -1,   -1,   -1,   -1,
      -1,   -1,   -1,   -1,   -1,   -1,   -1,   -1,
      -1,   -1,   -1,   -1,   -1,   -1,   -1,   -1,
      -1,   -1,   -1,   -1,   -1,   -1,   -1,   -1,
      -1,   -1,   -1,   -1,   -1,   -1,   -1,   -1,
      -1,   -1,   -1,   -1,   -1,   -1,   -1,   -1,
      -1,   -1,   -1,   -1,   -1,   -1,   -1,   -1,
      -1,   -1,   -1,   -1,   -1,   -1,   -1,   -1,
      -1,   -1,   -1,   -1,   -1,   -1,   -1,   -1,
      -1,   -1,   -1,   -1,   -1,   -1,   -1,   -1,
      -1,   -1,   -1,   -1,   -1,   -1,   -1,   -1,
      -1,   -1,   -1,   -1,   -1,   -1,   -1,   -1,
      -1,   -1,   -1,   -1,   -1,   -1,   -1,   -1,
      -1,   -1,   -1,   -1,   -1,   -1,   -1,   -1,
      -1,   -1,   -1,   -1,   -1,   -1,   -1,   -1,
      -1,   -1,   -1,   -1,   -1,   -1,   -1,   -1,
      -1,   -1,   -1,   -1,   -1,   -1,   -1,   -1,
      -1,   -1,   -1,   -1,   -1,   -1,   -1,   -1,
      -1,   -1,   -1,   -1,   -1,   -1,   -1,   -1,
      -1,   -1,   -1,   -1,   -1,   -1,   -1,   -1,
      -1,   -1,   -1,   -1,   -1,   -1,   -1,   -1,
      -1,   -1,   -1,   -1,   -1,   -1,   -1,   -1,
      -1,   -1,   -1,   -1,   -1,   -1,   -1,   -1,
      -1,   -1,   -1,   -1,   -1,   -1,   -1,   -1,
      -1,   -1,   -1,   -1,   -1,   -1,   -1,   -1,
      -1,   -1,   -1,   -1,   -1,   -1,   -1,   -1,
      -1,   -1,   -1,   -1,   -1,   -1,   -1,   -1,
      -1,   -1,   -1,   -1,   -1,   -1,   -1,   -1,
      -1,   -1,   -1,   -1,   -1,   -1,   -1,   -1,
      -1,   -1,   -1,   -1,   -1,   -1,   -1,   -1,
      -1,   -1,   -1,   -1,   -1,   -1,   -1,   -1,
      -1,   -1,   -1,   -1,   -1,   -1,   -1,   -1,
      -1,   -1,   -1,   -1,   -1,   -1,   -1,   -1,
      -1,   -1,   -1,   -1,   -1,   -1,   -1,   -1,
      -1,   -1,   -1,   -1,   -1,   -1,   -1,   -1,
      -1,   -1,   -1,   -1,   -1,   -1,   -1,   -1,
      -1,   -1,   -1,   -1,   -1,   -1,   -1,   -1,
      -1,   -1,   -1,   -1,   -1,   -1,   -1,   -1,
      -1,   -1,   -1,   -1,   -1,   -1,   -1,   -1,
      -1,   -1,   -1,   -1,   -1,   -1,   -1,   -1,
      -1,   -1,   -1,   -1,   -1,   -1,   -1,   -1,
      -1,   -1,   -1,   -1,   -1,   -1,   -1,   -1,
      -1,   -1,   -1,   -1,   -1,   -1,   -1,   -1,
      -1,   -1,   -1,   -1,   -1,   -1,   -1,   -1,
      -1,   -1,   -1,   -1,   -1,   -1,   -1,   -1,
      -1,   -1,   -1,   -1,   -1,   -1,   -1,   -1,
      -1,   -1,   -1,   -1,   -1,   -1,   -1,   -1,
      -1,   -1,   -1,   -1,   -1,   -1,   -1,   -1,
      -1,   -1,   -1,   -1,   -1,   -1,   -1,   -1,
      -1,   -1,   -1,   -1,   -1,   -1,   -1,   -1,
      -1,   -1,   -1,   -1,   -1,   -1,   -1,   -1,
      -1,   -1,   -1,   -1,   -1,   -1,   -1,   -1,
      -1,   -1,   -1,   -1,   -1,   -1,   -1,   -1,
      -1,   -1,   -1,   -1,   -1,   -1,   -1,   -1,
      -1,   -1,   -1,   -1,   -1,   -1,   -1,   -1,
      -1,   -1,   -1,   -1,   -1,   -1,   -1,   -1,
      -1,   -1,   -1,   -1,   -1,   -1,   -1,   -1,
      -1,   -1,   -1,   -1,   -1,   -1,   -1,   -1,
      -1,   -1,   -1,   -1,   -1,   -1,   -1,   -1,
      -1,   -1,   -1,   -1,   -1,   -1,   -1,   -1,
      -1,   -1,   -1,   -1,   -1,   -1,   -1,   -1,
      -1,   -1,   -1,   -1,   -1,   -1,   -1,   -1,
      -1,   -1,   -1,   -1,   -1,   -1,   -1,   -1,
      -1,   -1,   -1,   -1,   -1,   -1,   -1,   -1,
      -1,   -1,   -1,   -1,   -1,   -1,   -1,   -1,
      -1,   -1,   -1,   -1,   -1,   -1,   -1,   -1,
      -1,   -1,   -1,   -1,   -1,   -1,   -1,   -1,
      -1,   -1,   -1,   -1,   -1,   -1,   -1,   -1,
      -1,   -1,   -1,   -1,   -1,   -1,   -1,   -1,
      -1,   -1,   -1,   -1,   -1,   -1,   -1,   -1,
      -1,   -1,   -1,   -1,   -1,   -1,   -1,   -1,
      -1,   -1,   -1,   -1,   -1,   -1,   -1,   -1,
      -1,   -1,   -1,   -1,   -1,   -1,   -1,   -1,
      -1,   -1,   -1,   -1,   -1,   -1,   -1,   -1,
      -1,   -1,   -1,   -1,   -1,   -1,   -1,   -1,
      -1,   -1,   -1,   -1,   -1,   -1,   -1,   -1,
      -1,   -1,   -1,   -1,   -1,   -1,   -1,   -1,
      -1,   -1,   -1,   -1,   -1,   -1,   -1,   -1,
      -1,   -1,   -1,   -1,   -1,   -1,   -1,   -1,
      -1,   -1,   -1,   -1,   -1,   -1,   -1,   -1,
      -1,   -1,   -1,   -1,   -1,   -1,   -1,   -1,
      -1,   -1,   -1,   -1,   -1,   -1,   -1,   -1,
      -1,   -1,   -1,   -1,   -1,   -1,   -1,   -1,
      -1,   -1,   -1,   -1,   -1,   -1,   -1,   -1,
      -1,   -1,   -1,   -1,   -1,   -1,   -1,   -1,
      -1,   -1,   -1,   -1,   -1,   -1,   -1,   -1,
      -1,   -1,   -1,   -1,   -1,   -1, 4266,   -1,
      -1,   -1,   -1,   -1,   -1,   -1,   -1,   -1,
      -1,   -1,   -1,   -1,   -1,   -1,   -1,   -1,
      -1,   -1,   -1,   -1,   -1,   -1,   -1,   -1,
      -1,   -1,   -1,   -1,   -1,   -1,   -1,   -1,
      -1,   -1,   -1,   -1,   -1,   -1,   -1,   -1,
      -1,   -1,   -1,   -1,   -1,   -1,   -1,   -1,
      -1,   -1,   -1,   -1,   -1,   -1,   -1,   -1,
      -1,   -1,   -1,   -1,   -1,   -1,   -1,   -1,
      -1,   -1,   -1,   -1,   -1,   -1, 4267,   -1,
      -1,   -1,   -1,   -1,   -1,   -1,   -1,   -1,
      -1,   -1,   -1,   -1,   -1,   -1,   -1,   -1,
      -1,   -1,   -1,   -1,   -1,   -1,   -1,   -1,
      -1,   -1,   -1,   -1,   -1,   -1,   -1,   -1,
      -1,   -1,   -1,   -1,   -1,   -1,   -1,   -1,
      -1,   -1,   -1,   -1,   -1,   -1,   -1,   -1,
      -1,   -1,   -1,   -1,   -1,   -1,   -1,   -1,
      -1,   -1,   -1,   -1,   -1,   -1,   -1,   -1,
      -1,   -1,   -1,   -1,   -1,   -1,   -1,   -1,
      -1,   -1,   -1,   -1,   -1,   -1,   -1,   -1,
      -1,   -1,   -1,   -1,   -1,   -1,   -1,   -1,
      -1,   -1,   -1,   -1,   -1,   -1,   -1,   -1,
      -1,   -1,   -1,   -1,   -1,   -1,   -1,   -1,
      -1,   -1, 4268,   -1,   -1,   -1,   -1,   -1,
      -1,   -1,   -1,   -1,   -1,   -1,   -1,   -1,
      -1,   -1,   -1,   -1,   -1,   -1,   -1,   -1,
      -1,   -1,   -1,   -1,   -1,   -1,   -1,   -1,
      -1,   -1,   -1,   -1,   -1,   -1,   -1,   -1,
      -1,   -1,   -1,   -1,   -1,   -1,   -1,   -1,
      -1,   -1,   -1,   -1,   -1,   -1,   -1,   -1,
      -1,   -1,   -1,   -1,   -1,   -1,   -1,   -1,
      -1,   -1,   -1,   -1,   -1,   -1,   -1,   -1,
      -1,   -1,   -1,   -1,   -1,   -1,   -1,   -1,
      -1,   -1,   -1,   -1,   -1,   -1,   -1,   -1,
      -1,   -1,   -1,   -1,   -1,   -1,   -1,   -1,
      -1,   -1,   -1,   -1,   -1,   -1,   -1,   -1,
      -1,   -1,   -1,   -1,   -1,   -1,   -1,   -1,
      -1,   -1,   -1,   -1,   -1,   -1,   -1,   -1,
      -1,   -1,   -1,   -1,   -1,   -1,   -1,   -1,
      -1,   -1,   -1,   -1,   -1,   -1,   -1,   -1,
      -1,   -1,   -1,   -1,   -1,   -1,   -1,   -1,
      -1,   -1,   -1,   -1,   -1,   -1,   -1,   -1,
      -1,   -1,   -1,   -1,   -1,   -1,   -1,   -1,
      -1,   -1,   -1,   -1,   -1,   -1,   -1,   -1,
      -1,   -1,   -1,   -1,   -1,   -1,   -1,   -1,
      -1,   -1,   -1,   -1,   -1,   -1,   -1,   -1,
      -1,   -1,   -1,   -1,   -1,   -1,   -1,   -1,
      -1,   -1,   -1,   -1,   -1,   -1,   -1,   -1,
      -1,   -1,   -1,   -1,   -1,   -1,   -1,   -1,
      -1,   -1,   -1,   -1,   -1,   -1,   -1,   -1,
      -1,   -1,   -1,   -1,   -1,   -1,   -1,   -1,
      -1,   -1,   -1,   -1,   -1,   -1,   -1,   -1,
      -1,   -1,   -1,   -1,   -1,   -1,   -1,   -1,
      -1,   -1,   -1,   -1,   -1,   -1,   -1,   -1,
      -1,   -1,   -1,   -1, 4269,   -1,   -1,   -1,
      -1,   -1,   -1,   -1,   -1,   -1,   -1,   -1,
      -1,   -1,   -1,   -1,   -1,   -1,   -1,   -1,
      -1,   -1,   -1,   -1,   -1,   -1,   -1,   -1,
      -1,   -1,   -1,   -1,   -1,   -1,   -1,   -1,
      -1,   -1,   -1,   -1,   -1,   -1,   -1,   -1,
      -1,   -1,   -1,   -1,   -1,   -1,   -1,   -1,
      -1,   -1,   -1,   -1,   -1,   -1,   -1,   -1,
      -1,   -1,   -1,   -1,   -1,   -1,   -1,   -1,
      -1,   -1,   -1,   -1,   -1,   -1,   -1,   -1,
      -1,   -1,   -1,   -1,   -1,   -1,   -1,   -1,
      -1,   -1,   -1,   -1,   -1,   -1,   -1,   -1,
      -1,   -1,   -1,   -1,   -1,   -1,   -1,   -1,
      -1,   -1,   -1,   -1,   -1,   -1,   -1,   -1,
      -1,   -1,   -1,   -1,   -1,   -1,   -1,   -1,
      -1,   -1,   -1,   -1,   -1,   -1,   -1,   -1,
      -1,   -1,   -1,   -1,   -1,   -1,   -1,   -1,
      -1,   -1,   -1,   -1,   -1,   -1,   -1,   -1,
      -1,   -1,   -1,   -1,   -1,   -1,   -1,   -1,
      -1,   -1,   -1,   -1,   -1,   -1,   -1,   -1,
      -1,   -1,   -1,   -1,   -1,   -1,   -1,   -1,
      -1,   -1,   -1,   -1,   -1,   -1,   -1,   -1,
      -1,   -1,   -1,   -1,   -1,   -1,   -1,   -1,
      -1,   -1,   -1,   -1,   -1,   -1,   -1,   -1,
      -1,   -1,   -1,   -1,   -1,   -1,   -1,   -1,
      -1,   -1,   -1,   -1,   -1,   -1,   -1,   -1,
      -1,   -1,   -1,   -1,   -1,   -1,   -1,   -1,
      -1,   -1,   -1,   -1,   -1,   -1,   -1,   -1,
      -1,   -1,   -1,   -1,   -1,   -1,   -1,   -1,
      -1,   -1,   -1,   -1,   -1,   -1,   -1,   -1,
      -1,   -1,   -1,   -1,   -1,   -1,   -1,   -1,
      -1,   -1,   -1,   -1,   -1,   -1,   -1,   -1,
      -1,   -1,   -1,   -1,   -1,   -1,   -1,   -1,
      -1,   -1,   -1,   -1,   -1,   -1,   -1,   -1,
      -1,   -1,   -1,   -1,   -1,   -1,   -1,   -1,
      -1,   -1,   -1,   -1,   -1,   -1,   -1,   -1,
      -1,   -1,   -1,   -1,   -1,   -1,   -1,   -1,
      -1,   -1,   -1,   -1,   -1,   -1,   -1,   -1,
      -1,   -1,   -1,   -1,   -1,   -1,   -1,   -1,
      -1,   -1,   -1,   -1,   -1,   -1,   -1,   -1,
      -1,   -1,   -1,   -1,   -1,   -1,   -1,   -1,
      -1,   -1,   -1,   -1,   -1,   -1,   -1,   -1,
      -1,   -1,   -1,   -1,   -1,   -1,   -1,   -1,
      -1,   -1,   -1,   -1,   -1,   -1,   -1,   -1,
      -1,   -1,   -1,   -1,   -1,   -1,   -1,   -1,
      -1,   -1,   -1,   -1, 4270,   -1,   -1,   -1,
      -1,   -1,   -1,   -1,   -1,   -1,   -1,   -1,
      -1,   -1,   -1,   -1,   -1,   -1,   -1,   -1,
      -1,   -1,   -1,   -1,   -1,   -1,   -1,   -1,
      -1,   -1,   -1,   -1,   -1,   -1,   -1,   -1,
      -1,   -1,   -1,   -1,   -1,   -1,   -1,   -1,
      -1,   -1,   -1,   -1,   -1,   -1,   -1,   -1,
      -1,   -1,   -1,   -1,   -1,   -1,   -1,   -1,
      -1,   -1,   -1,   -1,   -1,   -1,   -1, 4271,
      -1,   -1,   -1,   -1,   -1,   -1,   -1,   -1,
      -1,   -1,   -1,   -1,   -1,   -1,   -1,   -1,
      -1,   -1,   -1,   -1,   -1,   -1,   -1,   -1,
      -1,   -1,   -1,   -1,   -1,   -1,   -1,   -1,
      -1,   -1,   -1,   -1,   -1,   -1,   -1,   -1,
      -1,   -1,   -1,   -1,   -1,   -1,   -1,   -1,
      -1,   -1,   -1,   -1,   -1,   -1,   -1,   -1,
      -1,   -1,   -1,   -1,   -1,   -1,   -1,   -1,
      -1,   -1,   -1,   -1,   -1,   -1,   -1,   -1,
      -1,   -1,   -1,   -1,   -1,   -1,   -1,   -1,
      -1,   -1,   -1,   -1,   -1,   -1,   -1,   -1,
      -1,   -1,   -1,   -1,   -1,   -1,   -1,   -1,
      -1,   -1,   -1,   -1,   -1,   -1,   -1,   -1,
      -1,   -1,   -1,   -1,   -1,   -1,   -1,   -1,
      -1,   -1,   -1,   -1,   -1,   -1,   -1,   -1,
      -1,   -1,   -1,   -1,   -1,   -1,   -1,   -1,
      -1,   -1,   -1,   -1,   -1,   -1,   -1,   -1,
      -1,   -1,   -1,   -1,   -1,   -1,   -1,   -1,
      -1,   -1,   -1,   -1,   -1,   -1,   -1,   -1,
      -1,   -1,   -1,   -1,   -1,   -1,   -1,   -1,
      -1,   -1,   -1,   -1,   -1,   -1,   -1,   -1,
      -1,   -1,   -1,   -1,   -1,   -1,   -1,   -1,
      -1,   -1,   -1,   -1,   -1,   -1,   -1,   -1,
      -1,   -1,   -1,   -1,   -1,   -1,   -1,   -1,
      -1,   -1,   -1,   -1,   -1,   -1,   -1,   -1,
      -1,   -1,   -1,   -1,   -1,   -1,   -1,   -1,
      -1,   -1,   -1,   -1,   -1,   -1,   -1,   -1,
      -1,   -1,   -1,   -1,   -1,   -1,   -1,   -1,
      -1,   -1,   -1,   -1,   -1,   -1,   -1,   -1,
      -1,   -1,   -1,   -1,   -1,   -1,   -1,   -1,
      -1,   -1,   -1,   -1,   -1,   -1,   -1,   -1,
      -1,   -1,   -1,   -1,   -1,   -1,   -1,   -1,
      -1,   -1,   -1,   -1,   -1,   -1,   -1,   -1,
      -1,   -1,   -1,   -1,   -1,   -1,   -1,   -1,
      -1,   -1,   -1,   -1,   -1,   -1,   -1,   -1,
      -1,   -1,   -1,   -1,   -1,   -1,   -1,   -1,
      -1,   -1,   -1,   -1,   -1,   -1,   -1,   -1,
      -1,   -1,   -1,   -1,   -1,   -1,   -1,   -1,
      -1,   -1,   -1,   -1,   -1,   -1,   -1,   -1,
      -1,   -1,   -1,   -1,   -1,   -1,   -1,   -1,
      -1,   -1,   -1,   -1,   -1,   -1,   -1,   -1,
      -1,   -1,   -1,   -1,   -1,   -1,   -1,   -1,
      -1,   -1,   -1,   -1,   -1,   -1,   -1,   -1,
      -1,   -1,   -1,   -1,   -1,   -1,   -1,   -1,
      -1,   -1,   -1,   -1,   -1,   -1,   -1,   -1,
      -1,   -1,   -1,   -1,   -1,   -1,   -1,   -1,
      -1,   -1,   -1,   -1,   -1,   -1,   -1,   -1,
      -1,   -1,   -1,   -1,   -1,   -1,   -1,   -1,
      -1,   -1,   -1,   -1,   -1,   -1,   -1,   -1,
      -1,   -1,   -1,   -1,   -1,   -1,   -1,   -1,
      -1,   -1,   -1,   -1,   -1,   -1,   -1,   -1,
      -1,   -1,   -1,   -1,   -1,   -1,   -1,   -1,
      -1,   -1,   -1,   -1,   -1,   -1,   -1,   -1,
      -1,   -1,   -1,   -1,   -1,   -1,   -1,   -1,
      -1,   -1,   -1,   -1,   -1,   -1,   -1,   -1,
      -1,   -1,   -1,   -1,   -1,   -1,   -1,   -1,
      -1,   -1,   -1,   -1,   -1,   -1,   -1,   -1,
      -1,   -1,   -1,   -1,   -1,   -1,   -1,   -1,
      -1,   -1,   -1,   -1,   -1,   -1,   -1,   -1,
      -1,   -1,   -1,   -1,   -1,   -1,   -1,   -1,
      -1,   -1,   -1,   -1,   -1,   -1,   -1,   -1,
      -1,   -1,   -1,   -1,   -1,   -1,   -1,   -1,
      -1,   -1,   -1,   -1,   -1,   -1,   -1,   -1,
      -1,   -1,   -1,   -1,   -1,   -1,   -1,   -1,
      -1,   -1,   -1,   -1,   -1,   -1,   -1,   -1,
      -1,   -1,   -1,   -1,   -1,   -1,   -1,   -1,
      -1,   -1,   -1,   -1,   -1,   -1,   -1,   -1,
      -1,   -1,   -1,   -1,   -1,   -1,   -1,   -1,
      -1,   -1,   -1,   -1,   -1,   -1,   -1,   -1,
      -1,   -1,   -1,   -1,   -1,   -1,   -1,   -1,
      -1,   -1,   -1,   -1,   -1,   -1,   -1,   -1,
      -1,   -1,   -1,   -1,   -1,   -1,   -1,   -1,
      -1,   -1,   -1,   -1,   -1,   -1,   -1,   -1,
      -1,   -1,   -1,   -1,   -1,   -1,   -1,   -1,
      -1,   -1,   -1,   -1,   -1, 4272,   -1,   -1,
      -1,   -1,   -1,   -1,   -1,   -1,   -1,   -1,
      -1,   -1,   -1,   -1,   -1,   -1,   -1,   -1,
      -1,   -1,   -1,   -1,   -1,   -1,   -1,   -1,
      -1,   -1,   -1,   -1,   -1,   -1,   -1,   -1,
      -1,   -1,   -1,   -1,   -1,   -1,   -1,   -1,
      -1,   -1,   -1,   -1,   -1,   -1,   -1,   -1,
      -1,   -1,   -1,   -1,   -1,   -1,   -1,   -1,
      -1,   -1,   -1,   -1,   -1,   -1,   -1,   -1,
      -1,   -1,   -1,   -1,   -1,   -1,   -1,   -1,
      -1,   -1,   -1,   -1,   -1,   -1,   -1,   -1,
      -1,   -1,   -1,   -1,   -1,   -1,   -1,   -1,
      -1,   -1,   -1,   -1,   -1,   -1,   -1,   -1,
      -1,   -1,   -1,   -1,   -1,   -1,   -1,   -1,
      -1,   -1,   -1,   -1,   -1,   -1,   -1,   -1,
      -1,   -1,   -1,   -1,   -1,   -1,   -1,   -1,
      -1,   -1,   -1,   -1,   -1,   -1,   -1,   -1,
      -1,   -1,   -1,   -1,   -1,   -1,   -1,   -1,
      -1,   -1,   -1,   -1,   -1,   -1,   -1,   -1,
      -1,   -1,   -1,   -1,   -1,   -1,   -1,   -1,
      -1,   -1,   -1,   -1,   -1,   -1,   -1,   -1,
      -1,   -1,   -1,   -1,   -1,   -1,   -1,   -1,
      -1,   -1,   -1,   -1,   -1,   -1,   -1,   -1,
      -1,   -1,   -1,   -1,   -1,   -1,   -1,   -1,
      -1,   -1,   -1,   -1,   -1,   -1,   -1,   -1,
      -1,   -1,   -1,   -1,   -1,   -1,   -1,   -1,
      -1,   -1,   -1,   -1,   -1,   -1,   -1,   -1,
      -1,   -1,   -1,   -1,   -1,   -1,   -1,   -1,
      -1,   -1,   -1,   -1,   -1,   -1,   -1,   -1,
      -1,   -1,   -1,   -1,   -1,   -1,   -1,   -1,
      -1,   -1,   -1,   -1,   -1,   -1,   -1,   -1,
      -1,   -1,   -1,   -1,   -1,   -1,   -1,   -1,
      -1,   -1,   -1,   -1,   -1,   -1,   -1,   -1,
      -1,   -1,   -1,   -1,   -1,   -1,   -1,   -1,
      -1,   -1,   -1,   -1,   -1,   -1,   -1,   -1,
      -1,   -1,   -1,   -1,   -1,   -1,   -1,   -1,
      -1,   -1,   -1,   -1,   -1,   -1,   -1,   -1,
      -1,   -1,   -1,   -1,   -1,   -1,   -1,   -1,
      -1,   -1,   -1,   -1,   -1,   -1,   -1,   -1,
      -1,   -1,   -1,   -1,   -1,   -1,   -1,   -1,
      -1,   -1,   -1,   -1,   -1,   -1,   -1,   -1,
      -1,   -1,   -1,   -1,   -1,   -1,   -1,   -1,
      -1,   -1,   -1,   -1,   -1,   -1,   -1,   -1,
      -1,   -1,   -1,   -1,   -1,   -1,   -1,   -1,
      -1,   -1,   -1,   -1,   -1,   -1,   -1,   -1,
      -1,   -1,   -1,   -1,   -1,   -1,   -1,   -1,
      -1,   -1,   -1,   -1,   -1,   -1,   -1,   -1,
      -1,   -1,   -1,   -1,   -1,   -1,   -1,   -1,
      -1,   -1,   -1,   -1,   -1,   -1,   -1,   -1,
      -1,   -1,   -1,   -1,   -1,   -1,   -1,   -1,
      -1,   -1,   -1,   -1,   -1,   -1,   -1,   -1,
      -1,   -1,   -1,   -1,   -1,   -1,   -1,   -1,
      -1,   -1,   -1,   -1,   -1,   -1,   -1,   -1,
      -1,   -1,   -1,   -1,   -1,   -1,   -1,   -1,
      -1,   -1,   -1,   -1,   -1,   -1,   -1,   -1,
      -1,   -1,   -1,   -1,   -1,   -1,   -1,   -1,
      -1,   -1,   -1,   -1,   -1,   -1,   -1,   -1,
      -1,   -1,   -1,   -1,   -1,   -1,   -1,   -1,
      -1,   -1,   -1,   -1,   -1,   -1,   -1,   -1,
      -1,   -1,   -1,   -1,   -1,   -1,   -1,   -1,
      -1,   -1,   -1,   -1,   -1,   -1,   -1,   -1,
      -1,   -1,   -1,   -1,   -1,   -1,   -1,   -1,
      -1,   -1,   -1,   -1,   -1,   -1,   -1,   -1,
      -1,   -1,   -1,   -1,   -1,   -1,   -1,   -1,
      -1,   -1,   -1,   -1,   -1,   -1,   -1,   -1,
      -1,   -1,   -1,   -1,   -1,   -1,   -1,   -1,
      -1,   -1,   -1,   -1,   -1,   -1, 4273,   -1,
      -1,   -1,   -1,   -1,   -1,   -1,   -1,   -1,
      -1,   -1,   -1,   -1,   -1,   -1,   -1,   -1,
      -1,   -1,   -1,   -1,   -1,   -1,   -1,   -1,
      -1,   -1,   -1,   -1,   -1,   -1,   -1,   -1,
      -1,   -1,   -1,   -1,   -1,   -1,   -1,   -1,
      -1,   -1,   -1,   -1,   -1,   -1,   -1,   -1,
      -1,   -1,   -1,   -1,   -1,   -1,   -1,   -1,
      -1,   -1,   -1,   -1,   -1,   -1,   -1,   -1,
      -1,   -1,   -1,   -1,   -1,   -1,   -1,   -1,
      -1,   -1,   -1,   -1,   -1,   -1,   -1,   -1,
      -1,   -1,   -1,   -1,   -1,   -1,   -1,   -1,
      -1,   -1,   -1,   -1,   -1,   -1,   -1,   -1,
      -1,   -1,   -1,   -1,   -1,   -1,   -1,   -1,
      -1,   -1,   -1,   -1,   -1,   -1,   -1,   -1,
      -1,   -1,   -1,   -1,   -1,   -1,   -1,   -1,
      -1,   -1,   -1,   -1,   -1,   -1,   -1,   -1,
      -1,   -1,   -1,   -1,   -1,   -1,   -1,   -1,
      -1,   -1,   -1,   -1,   -1,   -1,   -1,   -1,
      -1,   -1,   -1,   -1,   -1,   -1,   -1,   -1,
      -1,   -1,   -1,   -1,   -1,   -1,   -1,   -1,
      -1,   -1,   -1,   -1,   -1,   -1,   -1,   -1,
      -1,   -1,   -1,   -1,   -1,   -1,   -1,   -1,
      -1,   -1,   -1,   -1,   -1,   -1,   -1,   -1,
      -1,   -1,   -1,   -1,   -1,   -1,   -1,   -1,
      -1,   -1,   -1,   -1,   -1,   -1,   -1,   -1,
      -1,   -1,   -1,   -1,   -1,   -1,   -1,   -1,
      -1,   -1,   -1,   -1,   -1,   -1, 4274,   -1,
      -1,   -1,   -1,   -1,   -1,   -1,   -1,   -1,
      -1,   -1,   -1,   -1,   -1,   -1,   -1,   -1,
      -1,   -1,   -1,   -1,   -1,   -1,   -1,   -1,
      -1,   -1,   -1,   -1,   -1,   -1,   -1,   -1,
      -1,   -1,   -1,   -1,   -1,   -1,   -1,   -1,
      -1,   -1,   -1,   -1,   -1,   -1,   -1,   -1,
      -1,   -1,   -1,   -1,   -1,   -1,   -1,   -1,
      -1,   -1,   -1,   -1,   -1,   -1,   -1,   -1,
      -1,   -1,   -1,   -1,   -1,   -1,   -1,   -1,
      -1,   -1,   -1,   -1,   -1,   -1,   -1,   -1,
      -1,   -1,   -1,   -1,   -1,   -1,   -1,   -1,
      -1,   -1,   -1,   -1,   -1,   -1,   -1,   -1,
      -1,   -1,   -1,   -1,   -1,   -1,   -1,   -1,
      -1,   -1,   -1,   -1,   -1,   -1,   -1,   -1,
      -1,   -1,   -1,   -1,   -1,   -1,   -1,   -1,
      -1,   -1,   -1,   -1,   -1,   -1,   -1,   -1,
      -1,   -1,   -1,   -1,   -1,   -1,   -1,   -1,
      -1,   -1,   -1,   -1,   -1,   -1,   -1,   -1,
      -1,   -1,   -1,   -1,   -1,   -1,   -1,   -1,
      -1,   -1,   -1,   -1,   -1,   -1,   -1,   -1,
      -1,   -1,   -1,   -1,   -1,   -1,   -1,   -1,
      -1,   -1,   -1,   -1,   -1,   -1,   -1,   -1,
      -1,   -1,   -1,   -1,   -1,   -1,   -1,   -1,
      -1,   -1,   -1,   -1,   -1,   -1,   -1,   -1,
      -1,   -1,   -1,   -1,   -1,   -1,   -1,   -1,
      -1,   -1,   -1,   -1,   -1,   -1,   -1,   -1,
      -1,   -1,   -1,   -1,   -1,   -1,   -1,   -1,
      -1,   -1,   -1,   -1,   -1,   -1,   -1,   -1,
      -1,   -1,   -1,   -1,   -1,   -1,   -1,   -1,
      -1,   -1,   -1,   -1,   -1,   -1,   -1,   -1,
      -1,   -1,   -1,   -1,   -1,   -1,   -1,   -1,
      -1,   -1,   -1,   -1,   -1,   -1,   -1,   -1,
      -1,   -1,   -1,   -1,   -1,   -1,   -1,   -1,
      -1,   -1,   -1,   -1,   -1,   -1,   -1,   -1,
      -1,   -1,   -1,   -1,   -1,   -1,   -1,   -1,
      -1,   -1,   -1,   -1,   -1,   -1,   -1,   -1,
      -1,   -1,   -1,   -1,   -1,   -1,   -1,   -1,
      -1,   -1,   -1,   -1,   -1,   -1,   -1,   -1,
      -1,   -1,   -1,   -1,   -1,   -1,   -1,   -1,
      -1,   -1,   -1,   -1,   -1,   -1,   -1,   -1,
      -1,   -1,   -1,   -1,   -1,   -1,   -1,   -1,
      -1,   -1,   -1,   -1,   -1,   -1,   -1,   -1,
      -1,   -1,   -1,   -1,   -1,   -1,   -1,   -1,
      -1,   -1,   -1,   -1,   -1,   -1,   -1,   -1,
      -1,   -1,   -1,   -1,   -1,   -1,   -1,   -1,
      -1,   -1,   -1,   -1,   -1,   -1,   -1,   -1,
      -1,   -1,   -1,   -1,   -1,   -1,   -1,   -1,
      -1,   -1,   -1,   -1,   -1,   -1,   -1,   -1,
      -1,   -1,   -1,   -1,   -1,   -1,   -1,   -1,
      -1,   -1,   -1,   -1,   -1,   -1,   -1,   -1,
      -1,   -1,   -1,   -1,   -1,   -1,   -1,   -1,
      -1,   -1,   -1,   -1,   -1,   -1,   -1,   -1,
      -1,   -1,   -1,   -1,   -1,   -1,   -1,   -1,
      -1,   -1,   -1,   -1,   -1,   -1,   -1,   -1,
      -1,   -1,   -1,   -1,   -1,   -1,   -1,   -1,
      -1,   -1,   -1,   -1,   -1,   -1,   -1,   -1,
      -1,   -1,   -1,   -1,   -1, 4275,   -1,   -1,
      -1,   -1,   -1,   -1,   -1,   -1,   -1,   -1,
      -1,   -1,   -1,   -1,   -1,   -1,   -1,   -1,
      -1,   -1,   -1,   -1,   -1,   -1,   -1,   -1,
      -1,   -1,   -1,   -1,   -1,   -1,   -1,   -1,
      -1,   -1,   -1,   -1,   -1,   -1,   -1,   -1,
      -1,   -1,   -1,   -1,   -1,   -1,   -1,   -1,
      -1,   -1,   -1,   -1,   -1,   -1,   -1,   -1,
      -1,   -1,   -1,   -1,   -1,   -1,   -1,   -1,
      -1,   -1,   -1,   -1,   -1,   -1,   -1, 4276,
      -1,   -1,   -1,   -1,   -1,   -1,   -1,   -1,
      -1,   -1,   -1,   -1,   -1,   -1,   -1,   -1,
      -1,   -1,   -1,   -1,   -1,   -1,   -1,   -1,
      -1,   -1,   -1,   -1,   -1,   -1,   -1,   -1,
      -1,   -1,   -1,   -1,   -1,   -1,   -1,   -1,
      -1,   -1,   -1,   -1,   -1,   -1,   -1,   -1,
      -1,   -1,   -1,   -1,   -1,   -1,   -1,   -1,
      -1,   -1,   -1,   -1,   -1,   -1,   -1,   -1,
      -1,   -1,   -1,   -1,   -1,   -1,   -1,   -1,
      -1,   -1,   -1,   -1,   -1,   -1,   -1,   -1,
      -1,   -1,   -1,   -1,   -1,   -1,   -1,   -1,
      -1,   -1,   -1,   -1,   -1,   -1,   -1,   -1,
      -1,   -1,   -1,   -1,   -1,   -1,   -1,   -1,
      -1,   -1,   -1,   -1,   -1,   -1,   -1,   -1,
      -1,   -1,   -1,   -1,   -1,   -1,   -1,   -1,
      -1,   -1,   -1,   -1,   -1,   -1,   -1,   -1,
      -1,   -1,   -1,   -1,   -1,   -1,   -1,   -1,
      -1,   -1,   -1,   -1,   -1,   -1,   -1,   -1,
      -1,   -1,   -1,   -1,   -1,   -1,   -1,   -1,
      -1,   -1,   -1,   -1,   -1,   -1,   -1,   -1,
      -1,   -1,   -1,   -1,   -1,   -1,   -1,   -1,
      -1,   -1,   -1,   -1,   -1,   -1,   -1,   -1,
      -1,   -1,   -1,   -1,   -1,   -1,   -1,   -1,
      -1,   -1,   -1,   -1,   -1,   -1,   -1,   -1,
      -1,   -1,   -1,   -1,   -1,   -1,   -1,   -1,
      -1,   -1,   -1,   -1,   -1,   -1,   -1,   -1,
      -1,   -1,   -1,   -1,   -1,   -1,   -1,   -1,
      -1,   -1,   -1,   -1,   -1,   -1,   -1,   -1,
      -1,   -1,   -1,   -1,   -1,   -1,   -1,   -1,
      -1,   -1,   -1,   -1,   -1,   -1,   -1,   -1,
      -1,   -1,   -1,   -1,   -1,   -1,   -1,   -1,
      -1,   -1,   -1,   -1,   -1,   -1,   -1,   -1,
      -1,   -1,   -1,   -1,   -1,   -1,   -1,   -1,
      -1,   -1,   -1,   -1,   -1,   -1,   -1,   -1,
      -1,   -1,   -1,   -1,   -1,   -1,   -1,   -1,
      -1,   -1,   -1,   -1,   -1,   -1,   -1,   -1,
      -1,   -1,   -1,   -1,   -1,   -1,   -1,   -1,
      -1,   -1,   -1,   -1,   -1,   -1,   -1,   -1,
      -1,   -1,   -1,   -1,   -1,   -1,   -1,   -1,
      -1,   -1,   -1,   -1,   -1,   -1,   -1,   -1,
      -1,   -1,   -1,   -1,   -1,   -1,   -1,   -1,
      -1,   -1,   -1,   -1,   -1,   -1,   -1,   -1,
      -1,   -1,   -1,   -1,   -1,   -1,   -1,   -1,
      -1,   -1,   -1,   -1,   -1,   -1,   -1,   -1,
      -1,   -1,   -1,   -1,   -1,   -1,   -1,   -1,
      -1,   -1,   -1,   -1,   -1,   -1,   -1,   -1,
      -1,   -1,   -1,   -1,   -1,   -1,   -1,   -1,
      -1,   -1,   -1,   -1,   -1,   -1,   -1,   -1,
      -1,   -1,   -1,   -1,   -1,   -1,   -1,   -1,
      -1,   -1,   -1,   -1,   -1,   -1,   -1,   -1,
      -1,   -1,   -1,   -1,   -1,   -1,   -1,   -1,
      -1,   -1,   -1,   -1,   -1,   -1,   -1,   -1,
      -1,   -1,   -1,   -1,   -1,   -1,   -1,   -1,
      -1,   -1,   -1,   -1,   -1,   -1,   -1,   -1,
      -1,   -1,   -1,   -1,   -1,   -1,   -1,   -1,
      -1,   -1,   -1,   -1,   -1,   -1,   -1,   -1,
      -1,   -1,   -1,   -1,   -1,   -1,   -1,   -1,
      -1,   -1,   -1,   -1,   -1,   -1,   -1,   -1,
      -1,   -1,   -1,   -1,   -1,   -1,   -1,   -1,
      -1,   -1,   -1,   -1,   -1,   -1,   -1,   -1,
      -1,   -1,   -1,   -1,   -1,   -1,   -1,   -1,
      -1,   -1,   -1,   -1,   -1,   -1,   -1,   -1,
      -1,   -1,   -1,   -1,   -1,   -1,   -1,   -1,
      -1,   -1,   -1,   -1,   -1,   -1,   -1,   -1,
      -1,   -1,   -1,   -1,   -1,   -1,   -1,   -1,
      -1,   -1,   -1,   -1,   -1,   -1,   -1,   -1,
      -1,   -1,   -1,   -1,   -1,   -1,   -1,   -1,
      -1,   -1,   -1,   -1,   -1,   -1,   -1,   -1,
      -1,   -1,   -1,   -1,   -1,   -1,   -1,   -1,
      -1,   -1,   -1,   -1,   -1,   -1,   -1,   -1,
      -1,   -1,   -1,   -1,   -1,   -1,   -1,   -1,
      -1,   -1,   -1,   -1,   -1,   -1,   -1,   -1,
      -1,   -1,   -1,   -1,   -1,   -1,   -1,   -1,
      -1,   -1,   -1,   -1,   -1,   -1,   -1,   -1,
      -1,   -1,   -1,   -1,   -1,   -1,   -1,   -1,
      -1,   -1,   -1,   -1,   -1,   -1,   -1,   -1,
      -1,   -1,   -1,   -1,   -1,   -1,   -1,   -1,
      -1,   -1,   -1,   -1,   -1,   -1,   -1,   -1,
      -1,   -1,   -1,   -1,   -1,   -1,   -1,   -1,
    4277,   -1,   -1,   -1,   -1,   -1,   -1,   -1,
      -1,   -1,   -1,   -1,   -1,   -1,   -1,   -1,
      -1,   -1,   -1,   -1,   -1,   -1,   -1,   -1,
      -1,   -1,   -1,   -1,   -1,   -1,   -1,   -1,
      -1,   -1,   -1,   -1,   -1,   -1,   -1,   -1,
      -1,   -1,   -1,   -1,   -1,   -1,   -1,   -1,
      -1,   -1,   -1,   -1,   -1,   -1,   -1,   -1,
      -1,   -1,   -1,   -1,   -1,   -1,   -1,   -1,
      -1,   -1,   -1,   -1,   -1,   -1,   -1,   -1,
      -1,   -1,   -1,   -1,   -1,   -1,   -1,   -1,
      -1,   -1,   -1,   -1,   -1,   -1,   -1,   -1,
      -1,   -1,   -1,   -1,   -1,   -1,   -1,   -1,
      -1,   -1,   -1,   -1,   -1,   -1,   -1,   -1,
      -1,   -1,   -1,   -1,   -1,   -1,   -1,   -1,
      -1,   -1,   -1,   -1,   -1,   -1,   -1,   -1,
      -1,   -1,   -1,   -1,   -1,   -1,   -1,   -1,
      -1,   -1,   -1,   -1,   -1,   -1,   -1,   -1,
      -1,   -1,   -1,   -1,   -1,   -1,   -1,   -1,
      -1,   -1,   -1,   -1,   -1,   -1,   -1,   -1,
      -1,   -1,   -1,   -1,   -1,   -1,   -1,   -1,
      -1,   -1,   -1,   -1,   -1,   -1,   -1,   -1,
      -1,   -1,   -1,   -1,   -1,   -1,   -1,   -1,
      -1,   -1,   -1,   -1,   -1,   -1,   -1,   -1,
      -1,   -1,   -1,   -1,   -1,   -1,   -1,   -1,
      -1,   -1,   -1,   -1,   -1,   -1,   -1,   -1,
      -1,   -1,   -1,   -1,   -1,   -1,   -1,   -1,
      -1,   -1,   -1,   -1,   -1,   -1,   -1,   -1,
      -1,   -1,   -1,   -1,   -1,   -1,   -1,   -1,
      -1,   -1,   -1,   -1,   -1,   -1,   -1,   -1,
      -1,   -1,   -1,   -1,   -1,   -1,   -1,   -1,
      -1,   -1,   -1,   -1,   -1,   -1,   -1,   -1,
      -1,   -1,   -1,   -1,   -1,   -1,   -1,   -1,
      -1,   -1,   -1,   -1,   -1,   -1,   -1,   -1,
      -1,   -1,   -1,   -1,   -1,   -1,   -1,   -1,
      -1,   -1,   -1,   -1,   -1,   -1,   -1,   -1,
      -1,   -1,   -1,   -1,   -1,   -1,   -1,   -1,
      -1,   -1,   -1,   -1,   -1,   -1,   -1,   -1,
      -1,   -1,   -1,   -1,   -1,   -1,   -1,   -1,
      -1,   -1,   -1,   -1,   -1,   -1,   -1,   -1,
      -1,   -1,   -1,   -1,   -1,   -1,   -1,   -1,
      -1,   -1,   -1,   -1,   -1,   -1,   -1,   -1,
      -1,   -1,   -1,   -1,   -1,   -1,   -1,   -1,
      -1,   -1,   -1,   -1,   -1,   -1,   -1,   -1,
      -1,   -1,   -1,   -1,   -1,   -1,   -1,   -1,
      -1,   -1,   -1,   -1,   -1,   -1,   -1,   -1,
      -1,   -1,   -1,   -1,   -1,   -1,   -1,   -1,
      -1,   -1,   -1,   -1,   -1,   -1,   -1,   -1,
      -1,   -1,   -1,   -1,   -1,   -1,   -1,   -1,
      -1,   -1,   -1,   -1,   -1,   -1,   -1,   -1,
      -1,   -1,   -1,   -1,   -1,   -1,   -1,   -1,
      -1,   -1,   -1,   -1,   -1,   -1,   -1,   -1,
      -1,   -1,   -1,   -1,   -1,   -1,   -1,   -1,
      -1,   -1,   -1,   -1,   -1,   -1,   -1,   -1,
      -1,   -1,   -1,   -1,   -1,   -1,   -1,   -1,
      -1,   -1,   -1,   -1,   -1,   -1,   -1,   -1,
      -1,   -1,   -1,   -1,   -1,   -1,   -1,   -1,
      -1,   -1,   -1,   -1,   -1,   -1,   -1,   -1,
      -1,   -1,   -1,   -1,   -1,   -1,   -1,   -1,
      -1,   -1,   -1,   -1,   -1,   -1,   -1,   -1,
      -1,   -1,   -1,   -1,   -1,   -1,   -1,   -1,
      -1,   -1,   -1,   -1,   -1,   -1,   -1,   -1,
      -1,   -1,   -1,   -1,   -1,   -1,   -1,   -1,
      -1,   -1,   -1,   -1,   -1,   -1,   -1,   -1,
      -1,   -1,   -1,   -1,   -1,   -1,   -1,   -1,
      -1,   -1,   -1,   -1,   -1,   -1,   -1,   -1,
      -1,   -1,   -1,   -1,   -1,   -1,   -1,   -1,
      -1,   -1,   -1,   -1,   -1,   -1,   -1,   -1,
      -1,   -1,   -1,   -1,   -1,   -1,   -1,   -1,
      -1,   -1,   -1,   -1,   -1,   -1,   -1,   -1,
      -1,   -1,   -1,   -1,   -1,   -1,   -1,   -1,
      -1,   -1,   -1,   -1,   -1,   -1,   -1,   -1,
      -1,   -1,   -1,   -1,   -1,   -1,   -1,   -1,
      -1,   -1,   -1,   -1,   -1,   -1,   -1,   -1,
      -1,   -1,   -1,   -1,   -1,   -1,   -1,   -1,
      -1,   -1,   -1,   -1,   -1,   -1,   -1,   -1,
      -1,   -1,   -1,   -1,   -1,   -1,   -1,   -1,
      -1,   -1,   -1,   -1,   -1,   -1,   -1,   -1,
      -1,   -1,   -1,   -1,   -1,   -1,   -1,   -1,
      -1,   -1,   -1,   -1,   -1,   -1,   -1,   -1,
      -1,   -1,   -1,   -1,   -1,   -1,   -1,   -1,
      -1,   -1,   -1,   -1,   -1,   -1,   -1,   -1,
      -1,   -1,   -1,   -1,   -1,   -1,   -1,   -1,
      -1,   -1,   -1,   -1,   -1,   -1,   -1,   -1,
      -1,   -1,   -1,   -1,   -1,   -1,   -1,   -1,
      -1,   -1,   -1,   -1,   -1,   -1,   -1,   -1,
      -1,   -1,   -1,   -1,   -1,   -1,   -1,   -1,
      -1,   -1,   -1,   -1,   -1,   -1,   -1,   -1,
      -1,   -1,   -1,   -1,   -1,   -1,   -1,   -1,
      -1,   -1,   -1,   -1,   -1,   -1,   -1,   -1,
      -1,   -1,   -1,   -1,   -1,   -1,   -1,   -1,
      -1,   -1,   -1,   -1,   -1,   -1,   -1,   -1,
      -1,   -1,   -1,   -1,   -1,   -1,   -1,   -1,
      -1,   -1,   -1,   -1,   -1,   -1,   -1,   -1,
      -1,   -1,   -1,   -1,   -1,   -1,   -1,   -1,
      -1,   -1,   -1,   -1,   -1,   -1,   -1,   -1,
      -1,   -1,   -1,   -1,   -1,   -1,   -1,   -1,
      -1,   -1,   -1,   -1,   -1,   -1,   -1,   -1,
      -1,   -1,   -1,   -1,   -1,   -1,   -1,   -1,
      -1,   -1,   -1,   -1,   -1,   -1,   -1,   -1,
      -1,   -1,   -1,   -1,   -1,   -1,   -1,   -1,
      -1,   -1,   -1,   -1,   -1,   -1,   -1,   -1,
      -1,   -1,   -1,   -1,   -1,   -1,   -1,   -1,
      -1,   -1,   -1,   -1,   -1,   -1,   -1,   -1,
      -1,   -1,   -1,   -1,   -1,   -1,   -1,   -1,
      -1,   -1,   -1,   -1,   -1,   -1,   -1,   -1,
      -1,   -1,   -1,   -1,   -1,   -1,   -1,   -1,
      -1,   -1,   -1,   -1,   -1,   -1,   -1,   -1,
      -1,   -1,   -1,   -1,   -1,   -1,   -1,   -1,
      -1,   -1,   -1,   -1,   -1,   -1,   -1,   -1,
      -1,   -1,   -1,   -1,   -1,   -1,   -1,   -1,
      -1,   -1,   -1,   -1,   -1,   -1,   -1,   -1,
      -1,   -1,   -1,   -1,   -1,   -1,   -1,   -1,
      -1,   -1,   -1,   -1,   -1,   -1,   -1,   -1,
      -1,   -1,   -1,   -1,   -1,   -1,   -1,   -1,
      -1,   -1,   -1,   -1,   -1,   -1,   -1,   -1,
      -1,   -1,   -1,   -1,   -1,   -1,   -1,   -1,
      -1,   -1,   -1,   -1,   -1,   -1,   -1,   -1,
      -1,   -1,   -1,   -1,   -1,   -1,   -1,   -1,
      -1,   -1,   -1,   -1,   -1,   -1,   -1,   -1,
      -1,   -1,   -1,   -1,   -1,   -1,   -1,   -1,
      -1,   -1,   -1,   -1,   -1,   -1,   -1,   -1,
      -1,   -1,   -1,   -1,   -1,   -1,   -1,   -1,
      -1,   -1,   -1,   -1,   -1,   -1,   -1,   -1,
      -1,   -1,   -1,   -1,   -1,   -1,   -1,   -1,
      -1,   -1,   -1,   -1,   -1,   -1,   -1,   -1,
      -1,   -1,   -1,   -1,   -1,   -1,   -1,   -1,
      -1,   -1,   -1,   -1,   -1,   -1,   -1,   -1,
      -1,   -1,   -1,   -1,   -1,   -1,   -1,   -1,
      -1,   -1,   -1,   -1,   -1,   -1,   -1,   -1,
      -1,   -1,   -1,   -1,   -1,   -1,   -1,   -1,
      -1,   -1,   -1,   -1,   -1,   -1,   -1,   -1,
      -1,   -1,   -1,   -1,   -1,   -1,   -1,   -1,
      -1,   -1,   -1,   -1,   -1,   -1,   -1,   -1,
      -1,   -1,   -1,   -1,   -1,   -1,   -1,   -1,
      -1,   -1,   -1,   -1,   -1,   -1,   -1,   -1,
      -1,   -1,   -1,   -1,   -1,   -1,   -1,   -1,
      -1,   -1,   -1,   -1,   -1,   -1,   -1,   -1,
      -1,   -1,   -1,   -1,   -1,   -1,   -1,   -1,
      -1,   -1,   -1,   -1,   -1,   -1,   -1,   -1,
      -1,   -1,   -1,   -1,   -1,   -1,   -1,   -1,
      -1,   -1,   -1,   -1,   -1,   -1,   -1,   -1,
      -1,   -1,   -1,   -1,   -1,   -1,   -1,   -1,
      -1,   -1,   -1,   -1,   -1,   -1,   -1,   -1,
      -1,   -1,   -1,   -1,   -1,   -1,   -1,   -1,
      -1,   -1,   -1,   -1,   -1,   -1,   -1,   -1,
      -1,   -1,   -1,   -1,   -1,   -1,   -1,   -1,
      -1,   -1,   -1,   -1,   -1,   -1,   -1,   -1,
      -1,   -1,   -1,   -1,   -1,   -1,   -1,   -1,
      -1,   -1,   -1,   -1,   -1,   -1,   -1,   -1,
      -1,   -1,   -1,   -1,   -1,   -1,   -1,   -1,
      -1,   -1,   -1,   -1,   -1,   -1,   -1,   -1,
      -1,   -1,   -1,   -1,   -1,   -1,   -1,   -1,
      -1,   -1,   -1,   -1,   -1,   -1,   -1,   -1,
      -1,   -1,   -1,   -1,   -1,   -1,   -1,   -1,
      -1,   -1,   -1,   -1,   -1,   -1,   -1,   -1,
      -1,   -1,   -1,   -1,   -1,   -1,   -1,   -1,
      -1,   -1,   -1,   -1,   -1,   -1,   -1,   -1,
      -1,   -1,   -1,   -1,   -1,   -1,   -1,   -1,
      -1,   -1,   -1,   -1,   -1,   -1,   -1,   -1,
      -1,   -1,   -1,   -1,   -1,   -1,   -1,   -1,
      -1,   -1,   -1,   -1,   -1,   -1,   -1,   -1,
      -1,   -1,   -1,   -1,   -1,   -1,   -1,   -1,
      -1,   -1,   -1,   -1,   -1,   -1,   -1,   -1,
      -1,   -1,   -1,   -1,   -1,   -1,   -1,   -1,
      -1,   -1,   -1,   -1,   -1,   -1,   -1,   -1,
      -1,   -1,   -1,   -1,   -1,   -1,   -1,   -1,
      -1,   -1,   -1,   -1,   -1,   -1,   -1,   -1,
      -1,   -1,   -1,   -1,   -1,   -1,   -1,   -1,
      -1,   -1,   -1,   -1,   -1,   -1,   -1,   -1,
      -1,   -1,   -1,   -1,   -1,   -1,   -1,   -1,
      -1,   -1,   -1,   -1,   -1,   -1,   -1,   -1,
      -1,   -1,   -1,   -1,   -1,   -1,   -1,   -1,
      -1,   -1,   -1,   -1,   -1,   -1,   -1,   -1,
      -1,   -1,   -1,   -1,   -1,   -1,   -1,   -1,
      -1,   -1,   -1,   -1,   -1,   -1,   -1,   -1,
      -1,   -1,   -1,   -1,   -1,   -1,   -1,   -1,
      -1,   -1,   -1,   -1,   -1,   -1,   -1,   -1,
      -1,   -1,   -1,   -1,   -1,   -1,   -1,   -1,
      -1,   -1,   -1,   -1,   -1,   -1,   -1,   -1,
      -1,   -1,   -1,   -1,   -1,   -1,   -1,   -1,
      -1,   -1,   -1,   -1,   -1,   -1,   -1,   -1,
      -1,   -1,   -1,   -1,   -1,   -1,   -1,   -1,
      -1,   -1,   -1,   -1,   -1,   -1,   -1,   -1,
      -1,   -1,   -1,   -1,   -1,   -1,   -1,   -1,
      -1,   -1,   -1,   -1,   -1,   -1,   -1,   -1,
      -1,   -1,   -1,   -1,   -1,   -1,   -1,   -1,
      -1,   -1,   -1,   -1,   -1,   -1,   -1,   -1,
      -1,   -1,   -1,   -1,   -1,   -1,   -1,   -1,
      -1,   -1,   -1,   -1,   -1,   -1,   -1,   -1,
      -1,   -1,   -1,   -1,   -1,   -1,   -1,   -1,
      -1,   -1,   -1,   -1,   -1,   -1,   -1,   -1,
      -1,   -1,   -1,   -1,   -1,   -1,   -1,   -1,
      -1,   -1,   -1,   -1,   -1,   -1,   -1,   -1,
      -1,   -1,   -1,   -1,   -1,   -1,   -1,   -1,
      -1,   -1,   -1,   -1,   -1,   -1,   -1,   -1,
      -1,   -1,   -1,   -1,   -1,   -1,   -1,   -1,
      -1,   -1,   -1,   -1,   -1,   -1,   -1,   -1,
      -1,   -1,   -1,   -1,   -1,   -1,   -1,   -1,
      -1,   -1,   -1,   -1,   -1,   -1,   -1,   -1,
      -1,   -1,   -1,   -1,   -1,   -1,   -1,   -1,
      -1,   -1,   -1,   -1,   -1,   -1,   -1,   -1,
      -1,   -1,   -1,   -1,   -1,   -1,   -1,   -1,
      -1,   -1,   -1,   -1,   -1,   -1,   -1,   -1,
      -1,   -1,   -1,   -1,   -1,   -1,   -1,   -1,
      -1,   -1,   -1,   -1,   -1,   -1,   -1,   -1,
      -1,   -1,   -1,   -1,   -1,   -1,   -1,   -1,
      -1,   -1,   -1,   -1,   -1,   -1,   -1,   -1,
      -1,   -1,   -1,   -1,   -1,   -1,   -1,   -1,
      -1,   -1,   -1,   -1,   -1,   -1,   -1,   -1,
      -1,   -1,   -1,   -1,   -1,   -1,   -1,   -1,
      -1,   -1,   -1,   -1,   -1,   -1,   -1,   -1,
      -1,   -1,   -1,   -1,   -1,   -1,   -1,   -1,
      -1,   -1,   -1,   -1,   -1,   -1,   -1,   -1,
      -1,   -1,   -1,   -1,   -1,   -1,   -1,   -1,
      -1,   -1,   -1,   -1,   -1,   -1,   -1,   -1,
      -1,   -1,   -1,   -1,   -1,   -1,   -1,   -1,
      -1,   -1,   -1,   -1,   -1,   -1,   -1,   -1,
      -1,   -1,   -1,   -1,   -1,   -1,   -1,   -1,
      -1,   -1,   -1,   -1,   -1,   -1,   -1,   -1,
      -1,   -1,   -1,   -1,   -1,   -1,   -1,   -1,
      -1,   -1,   -1,   -1,   -1,   -1,   -1,   -1,
      -1,   -1,   -1,   -1,   -1,   -1,   -1,   -1,
      -1,   -1,   -1,   -1,   -1,   -1,   -1,   -1,
      -1,   -1,   -1,   -1,   -1,   -1,   -1,   -1,
      -1,   -1,   -1,   -1,   -1,   -1,   -1,   -1,
      -1,   -1,   -1,   -1,   -1,   -1,   -1,   -1,
      -1,   -1,   -1,   -1,   -1,   -1,   -1,   -1,
      -1,   -1,   -1,   -1,   -1,   -1,   -1,   -1,
      -1,   -1,   -1,   -1,   -1,   -1,   -1,   -1,
      -1,   -1,   -1,   -1,   -1,   -1,   -1,   -1,
      -1,   -1,   -1,   -1,   -1,   -1,   -1,   -1,
      -1,   -1,   -1,   -1,   -1,   -1,   -1,   -1,
      -1,   -1,   -1,   -1,   -1,   -1,   -1,   -1,
      -1,   -1,   -1,   -1,   -1,   -1,   -1,   -1,
      -1,   -1,   -1,   -1,   -1,   -1,   -1,   -1,
      -1,   -1,   -1,   -1,   -1,   -1,   -1,   -1,
      -1,   -1,   -1,   -1,   -1,   -1,   -1,   -1,
      -1,   -1,   -1,   -1,   -1,   -1,   -1,   -1,
      -1,   -1,   -1,   -1,   -1,   -1,   -1,   -1,
      -1,   -1,   -1,   -1,   -1,   -1,   -1,   -1,
      -1,   -1,   -1,   -1,   -1,   -1,   -1,   -1,
      -1,   -1,   -1,   -1,   -1,   -1,   -1,   -1,
      -1,   -1,   -1,   -1,   -1,   -1,   -1,   -1,
      -1,   -1,   -1,   -1,   -1,   -1,   -1,   -1,
      -1,   -1,   -1,   -1,   -1,   -1,   -1,   -1,
      -1,   -1,   -1,   -1,   -1,   -1,   -1,   -1,
      -1,   -1,   -1,   -1,   -1,   -1,   -1,   -1,
      -1,   -1,   -1,   -1,   -1,   -1,   -1,   -1,
      -1,   -1,   -1,   -1,   -1,   -1,   -1,   -1,
      -1,   -1,   -1,   -1,   -1,   -1,   -1,   -1,
      -1,   -1,   -1,   -1,   -1,   -1,   -1,   -1,
      -1,   -1,   -1,   -1,   -1,   -1,   -1,   -1,
      -1,   -1,   -1,   -1,   -1,   -1,   -1,   -1,
      -1,   -1,   -1,   -1,   -1,   -1,   -1,   -1,
      -1,   -1,   -1,   -1,   -1,   -1,   -1,   -1,
      -1,   -1,   -1,   -1,   -1,   -1,   -1,   -1,
      -1,   -1,   -1,   -1,   -1,   -1,   -1,   -1,
      -1,   -1,   -1,   -1,   -1,   -1,   -1,   -1,
      -1,   -1,   -1,   -1,   -1,   -1,   -1,   -1,
      -1,   -1,   -1,   -1,   -1,   -1,   -1,   -1,
      -1,   -1,   -1,   -1,   -1,   -1,   -1,   -1,
      -1,   -1,   -1,   -1,   -1,   -1,   -1,   -1,
      -1,   -1,   -1,   -1,   -1,   -1,   -1,   -1,
      -1,   -1,   -1,   -1,   -1,   -1,   -1,   -1,
      -1,   -1,   -1,   -1,   -1,   -1,   -1,   -1,
      -1,   -1,   -1,   -1,   -1,   -1,   -1,   -1,
      -1,   -1,   -1,   -1,   -1,   -1,   -1,   -1,
      -1,   -1,   -1,   -1,   -1,   -1,   -1,   -1,
      -1,   -1,   -1,   -1,   -1,   -1,   -1,   -1,
      -1,   -1,   -1,   -1,   -1,   -1,   -1,   -1,
      -1,   -1,   -1,   -1,   -1,   -1,   -1,   -1,
      -1,   -1,   -1,   -1,   -1,   -1,   -1,   -1,
      -1,   -1,   -1,   -1,   -1,   -1,   -1,   -1,
      -1,   -1,   -1,   -1,   -1,   -1,   -1,   -1,
      -1,   -1,   -1,   -1,   -1,   -1,   -1,   -1,
      -1,   -1,   -1,   -1,   -1,   -1,   -1,   -1,
      -1,   -1,   -1,   -1,   -1,   -1,   -1,   -1,
      -1,   -1,   -1,   -1,   -1,   -1,   -1,   -1,
      -1,   -1,   -1,   -1,   -1,   -1,   -1,   -1,
      -1,   -1,   -1,   -1,   -1,   -1,   -1,   -1,
      -1,   -1,   -1,   -1,   -1,   -1,   -1,   -1,
      -1,   -1,   -1,   -1,   -1,   -1,   -1,   -1,
      -1,   -1,   -1,   -1,   -1,   -1,   -1,   -1,
      -1,   -1,   -1,   -1,   -1,   -1,   -1,   -1,
      -1,   -1,   -1,   -1,   -1,   -1,   -1,   -1,
      -1,   -1,   -1,   -1,   -1,   -1,   -1,   -1,
      -1,   -1,   -1,   -1,   -1,   -1,   -1,   -1,
      -1,   -1,   -1,   -1,   -1,   -1,   -1,   -1,
      -1,   -1,   -1,   -1,   -1,   -1,   -1,   -1,
      -1,   -1,   -1,   -1,   -1,   -1,   -1,   -1,
      -1,   -1,   -1,   -1,   -1,   -1,   -1,   -1,
      -1,   -1,   -1,   -1,   -1,   -1,   -1,   -1,
      -1,   -1,   -1,   -1,   -1,   -1,   -1,   -1,
      -1,   -1,   -1,   -1,   -1,   -1,   -1,   -1,
      -1,   -1,   -1,   -1,   -1,   -1,   -1,   -1,
      -1,   -1,   -1,   -1,   -1,   -1,   -1,   -1,
      -1,   -1,   -1,   -1,   -1,   -1,   -1,   -1,
      -1,   -1,   -1,   -1,   -1,   -1,   -1,   -1,
      -1,   -1,   -1,   -1,   -1,   -1,   -1,   -1,
      -1,   -1,   -1,   -1,   -1,   -1,   -1,   -1,
      -1,   -1,   -1,   -1,   -1,   -1,   -1,   -1,
      -1,   -1,   -1,   -1,   -1,   -1,   -1,   -1,
      -1,   -1,   -1,   -1,   -1,   -1,   -1,   -1,
      -1,   -1,   -1,   -1,   -1,   -1,   -1,   -1,
      -1,   -1,   -1,   -1,   -1,   -1,   -1,   -1,
      -1,   -1,   -1,   -1,   -1,   -1,   -1,   -1,
      -1,   -1,   -1,   -1,   -1,   -1,   -1,   -1,
      -1,   -1,   -1,   -1,   -1,   -1,   -1,   -1,
      -1,   -1,   -1,   -1,   -1,   -1,   -1,   -1,
      -1,   -1,   -1,   -1,   -1,   -1,   -1,   -1,
      -1,   -1,   -1,   -1,   -1,   -1,   -1,   -1,
      -1,   -1,   -1,   -1,   -1,   -1,   -1,   -1,
      -1,   -1,   -1,   -1,   -1,   -1,   -1,   -1,
      -1,   -1,   -1,   -1,   -1,   -1,   -1,   -1,
      -1,   -1,   -1,   -1,   -1,   -1,   -1,   -1,
      -1,   -1,   -1,   -1,   -1,   -1,   -1,   -1,
      -1,   -1,   -1,   -1,   -1,   -1,   -1,   -1,
      -1,   -1,   -1,   -1,   -1,   -1,   -1,   -1,
      -1,   -1,   -1,   -1,   -1,   -1,   -1,   -1,
      -1,   -1,   -1,   -1,   -1,   -1,   -1,   -1,
      -1,   -1,   -1,   -1,   -1,   -1,   -1,   -1,
      -1,   -1,   -1,   -1,   -1,   -1,   -1,   -1,
      -1,   -1,   -1,   -1,   -1,   -1,   -1,   -1,
      -1,   -1,   -1,   -1,   -1,   -1,   -1,   -1,
      -1,   -1,   -1,   -1,   -1,   -1,   -1,   -1,
      -1,   -1,   -1,   -1,   -1,   -1,   -1,   -1,
      -1,   -1,   -1,   -1,   -1,   -1,   -1,   -1,
      -1,   -1,   -1,   -1,   -1,   -1,   -1,   -1,
      -1,   -1,   -1,   -1,   -1,   -1,   -1,   -1,
      -1,   -1,   -1,   -1,   -1,   -1,   -1,   -1,
      -1,   -1,   -1,   -1,   -1,   -1,   -1,   -1,
      -1,   -1,   -1,   -1,   -1,   -1,   -1,   -1,
      -1,   -1,   -1,   -1,   -1,   -1,   -1,   -1,
      -1,   -1,   -1,   -1,   -1,   -1,   -1,   -1,
      -1,   -1,   -1,   -1,   -1,   -1,   -1,   -1,
      -1,   -1,   -1,   -1,   -1,   -1,   -1,   -1,
      -1,   -1,   -1,   -1,   -1,   -1,   -1,   -1,
      -1,   -1,   -1,   -1,   -1,   -1,   -1,   -1,
      -1,   -1,   -1,   -1,   -1,   -1,   -1,   -1,
      -1,   -1,   -1,   -1,   -1,   -1,   -1,   -1,
      -1,   -1,   -1,   -1,   -1,   -1,   -1,   -1,
      -1,   -1,   -1,   -1,   -1,   -1,   -1,   -1,
      -1,   -1,   -1,   -1,   -1,   -1,   -1,   -1,
      -1,   -1,   -1,   -1,   -1,   -1,   -1,   -1,
      -1,   -1,   -1,   -1,   -1,   -1,   -1,   -1,
      -1,   -1,   -1,   -1,   -1,   -1,   -1,   -1,
      -1,   -1,   -1,   -1,   -1,   -1,   -1,   -1,
      -1,   -1,   -1,   -1,   -1,   -1,   -1,   -1,
      -1,   -1,   -1,   -1,   -1,   -1,   -1,   -1,
      -1,   -1,   -1,   -1,   -1,   -1,   -1,   -1,
      -1,   -1,   -1,   -1,   -1,   -1,   -1,   -1,
      -1,   -1,   -1,   -1,   -1,   -1,   -1,   -1,
      -1,   -1,   -1,   -1,   -1,   -1,   -1,   -1,
      -1,   -1,   -1,   -1,   -1,   -1,   -1,   -1,
      -1,   -1,   -1,   -1,   -1,   -1,   -1,   -1,
      -1,   -1,   -1,   -1,   -1,   -1,   -1,   -1,
      -1,   -1,   -1,   -1,   -1,   -1,   -1,   -1,
      -1,   -1,   -1,   -1,   -1,   -1,   -1,   -1,
      -1,   -1,   -1,   -1,   -1,   -1,   -1,   -1,
      -1,   -1,   -1,   -1,   -1,   -1,   -1,   -1,
      -1,   -1,   -1,   -1,   -1,   -1,   -1,   -1,
      -1,   -1,   -1,   -1,   -1,   -1,   -1,   -1,
      -1,   -1,   -1,   -1,   -1,   -1,   -1,   -1,
      -1,   -1,   -1,   -1,   -1,   -1,   -1,   -1,
      -1,   -1,   -1,   -1,   -1,   -1,   -1,   -1,
      -1,   -1,   -1,   -1,   -1,   -1,   -1,   -1,
      -1,   -1,   -1,   -1,   -1,   -1,   -1,   -1,
      -1,   -1,   -1,   -1,   -1,   -1,   -1,   -1,
      -1,   -1,   -1,   -1,   -1,   -1,   -1,   -1,
      -1,   -1,   -1,   -1,   -1,   -1,   -1,   -1,
      -1,   -1,   -1,   -1,   -1,   -1,   -1,   -1,
      -1,   -1,   -1,   -1,   -1,   -1,   -1,   -1,
      -1,   -1,   -1,   -1,   -1,   -1,   -1,   -1,
      -1,   -1,   -1,   -1,   -1,   -1,   -1,   -1,
      -1,   -1,   -1,   -1,   -1,   -1,   -1,   -1,
      -1,   -1,   -1,   -1,   -1,   -1,   -1,   -1,
      -1,   -1,   -1,   -1,   -1,   -1,   -1,   -1,
      -1,   -1,   -1,   -1,   -1,   -1,   -1,   -1,
      -1,   -1,   -1,   -1,   -1,   -1,   -1,   -1,
      -1,   -1,   -1,   -1,   -1,   -1,   -1,   -1,
      -1,   -1,   -1,   -1,   -1,   -1,   -1,   -1,
      -1,   -1,   -1,   -1,   -1,   -1,   -1,   -1,
      -1,   -1,   -1,   -1,   -1,   -1,   -1,   -1,
      -1,   -1,   -1,   -1,   -1,   -1,   -1,   -1,
      -1,   -1,   -1,   -1,   -1,   -1,   -1,   -1,
      -1,   -1,   -1,   -1,   -1,   -1,   -1,   -1,
      -1,   -1,   -1,   -1,   -1,   -1,   -1,   -1,
      -1,   -1,   -1,   -1,   -1,   -1,   -1,   -1,
      -1,   -1,   -1,   -1,   -1,   -1,   -1,   -1,
      -1,   -1,   -1,   -1,   -1,   -1,   -1,   -1,
      -1,   -1,   -1,   -1,   -1,   -1,   -1,   -1,
      -1,   -1,   -1,   -1,   -1,   -1,   -1,   -1,
      -1,   -1,   -1,   -1,   -1,   -1,   -1,   -1,
      -1,   -1,   -1,   -1, 4278,   -1,   -1,   -1,
      -1,   -1,   -1,   -1,   -1,   -1,   -1,   -1,
      -1,   -1,   -1,   -1,   -1,   -1,   -1,   -1,
      -1,   -1,   -1,   -1,   -1,   -1,   -1,   -1,
      -1,   -1,   -1,   -1,   -1,   -1,   -1,   -1,
      -1,   -1,   -1,   -1,   -1,   -1,   -1,   -1,
      -1,   -1,   -1,   -1,   -1,   -1,   -1,   -1,
      -1,   -1,   -1,   -1,   -1,   -1,   -1,   -1,
      -1,   -1,   -1,   -1,   -1,   -1,   -1,   -1,
      -1,   -1,   -1,   -1,   -1,   -1,   -1,   -1,
      -1,   -1,   -1,   -1,   -1,   -1,   -1,   -1,
      -1,   -1,   -1,   -1,   -1,   -1,   -1,   -1,
      -1,   -1,   -1,   -1,   -1,   -1,   -1,   -1,
      -1,   -1,   -1,   -1,   -1,   -1,   -1,   -1,
      -1,   -1,   -1,   -1,   -1,   -1,   -1,   -1,
      -1,   -1,   -1,   -1,   -1,   -1,   -1,   -1,
      -1,   -1,   -1,   -1,   -1,   -1,   -1,   -1,
      -1,   -1,   -1,   -1,   -1,   -1,   -1,   -1,
      -1,   -1,   -1,   -1,   -1,   -1,   -1,   -1,
      -1,   -1,   -1,   -1,   -1,   -1,   -1,   -1,
      -1,   -1,   -1,   -1,   -1,   -1,   -1,   -1,
      -1,   -1,   -1,   -1,   -1,   -1,   -1,   -1,
      -1,   -1,   -1,   -1,   -1,   -1,   -1,   -1,
      -1,   -1,   -1,   -1,   -1,   -1,   -1,   -1,
      -1,   -1,   -1,   -1,   -1,   -1,   -1,   -1,
      -1,   -1,   -1,   -1,   -1,   -1,   -1,   -1,
      -1,   -1,   -1,   -1,   -1,   -1,   -1,   -1,
      -1,   -1,   -1,   -1,   -1,   -1,   -1,   -1,
      -1,   -1,   -1,   -1,   -1,   -1,   -1,   -1,
      -1,   -1,   -1,   -1,   -1,   -1,   -1,   -1,
      -1,   -1,   -1,   -1,   -1,   -1,   -1,   -1,
      -1,   -1,   -1,   -1,   -1,   -1,   -1,   -1,
      -1,   -1,   -1,   -1,   -1,   -1,   -1,   -1,
      -1,   -1,   -1,   -1,   -1,   -1,   -1,   -1,
      -1,   -1,   -1,   -1,   -1,   -1,   -1,   -1,
      -1,   -1,   -1,   -1,   -1,   -1,   -1,   -1,
      -1,   -1,   -1,   -1,   -1,   -1,   -1,   -1,
      -1,   -1,   -1,   -1,   -1,   -1,   -1,   -1,
      -1,   -1,   -1,   -1,   -1,   -1,   -1,   -1,
      -1,   -1,   -1,   -1,   -1,   -1,   -1,   -1,
      -1,   -1,   -1,   -1,   -1,   -1,   -1,   -1,
      -1,   -1,   -1,   -1,   -1,   -1,   -1,   -1,
      -1,   -1,   -1,   -1,   -1,   -1,   -1,   -1,
      -1,   -1,   -1,   -1,   -1,   -1,   -1,   -1,
      -1,   -1,   -1,   -1,   -1,   -1,   -1,   -1,
      -1,   -1,   -1,   -1,   -1,   -1,   -1,   -1,
      -1,   -1,   -1,   -1,   -1,   -1,   -1,   -1,
      -1,   -1,   -1,   -1,   -1,   -1,   -1,   -1,
      -1,   -1,   -1,   -1,   -1,   -1,   -1,   -1,
      -1,   -1,   -1,   -1,   -1,   -1,   -1,   -1,
      -1,   -1,   -1,   -1,   -1,   -1,   -1,   -1,
      -1,   -1,   -1,   -1,   -1,   -1,   -1,   -1,
      -1,   -1,   -1,   -1,   -1,   -1,   -1,   -1,
      -1,   -1,   -1,   -1,   -1,   -1,   -1,   -1,
      -1,   -1,   -1,   -1,   -1,   -1,   -1,   -1,
      -1,   -1,   -1,   -1,   -1,   -1,   -1,   -1,
      -1,   -1,   -1,   -1,   -1,   -1,   -1,   -1,
      -1,   -1,   -1,   -1,   -1,   -1,   -1,   -1,
      -1,   -1,   -1,   -1,   -1,   -1,   -1,   -1,
      -1,   -1,   -1,   -1,   -1,   -1,   -1,   -1,
      -1,   -1,   -1,   -1,   -1,   -1,   -1,   -1,
      -1,   -1,   -1,   -1,   -1,   -1,   -1,   -1,
      -1,   -1,   -1,   -1,   -1,   -1,   -1,   -1,
      -1,   -1,   -1,   -1,   -1,   -1,   -1,   -1,
      -1,   -1,   -1,   -1,   -1,   -1,   -1,   -1,
      -1,   -1,   -1,   -1,   -1,   -1,   -1,   -1,
      -1,   -1,   -1,   -1,   -1,   -1,   -1,   -1,
      -1,   -1,   -1,   -1,   -1,   -1,   -1,   -1,
      -1,   -1,   -1,   -1,   -1,   -1,   -1,   -1,
      -1,   -1,   -1,   -1,   -1,   -1,   -1,   -1,
      -1,   -1,   -1,   -1,   -1,   -1,   -1,   -1,
      -1,   -1,   -1,   -1,   -1,   -1,   -1,   -1,
      -1,   -1,   -1,   -1,   -1,   -1,   -1,   -1,
      -1,   -1,   -1,   -1,   -1,   -1,   -1,   -1,
      -1,   -1,   -1,   -1,   -1,   -1,   -1,   -1,
      -1,   -1,   -1,   -1,   -1,   -1,   -1,   -1,
      -1,   -1,   -1,   -1,   -1,   -1,   -1,   -1,
      -1,   -1,   -1,   -1,   -1,   -1,   -1,   -1,
      -1,   -1,   -1,   -1,   -1,   -1,   -1,   -1,
      -1,   -1,   -1,   -1,   -1,   -1,   -1,   -1,
      -1,   -1,   -1,   -1,   -1,   -1,   -1,   -1,
      -1,   -1,   -1,   -1,   -1,   -1,   -1,   -1,
      -1,   -1,   -1,   -1,   -1,   -1,   -1,   -1,
      -1,   -1,   -1,   -1,   -1,   -1,   -1,   -1,
      -1,   -1,   -1,   -1,   -1,   -1,   -1,   -1,
      -1,   -1,   -1,   -1,   -1,   -1,   -1,   -1,
      -1,   -1,   -1,   -1,   -1,   -1,   -1,   -1,
      -1,   -1,   -1,   -1,   -1,   -1,   -1,   -1,
      -1,   -1,   -1,   -1,   -1,   -1,   -1,   -1,
      -1,   -1,   -1,   -1,   -1,   -1,   -1,   -1,
      -1,   -1,   -1,   -1,   -1,   -1,   -1,   -1,
      -1,   -1,   -1,   -1,   -1,   -1,   -1,   -1,
      -1,   -1,   -1,   -1,   -1,   -1,   -1,   -1,
      -1,   -1,   -1,   -1,   -1,   -1,   -1,   -1,
      -1,   -1,   -1,   -1,   -1,   -1,   -1,   -1,
      -1,   -1,   -1,   -1,   -1,   -1,   -1,   -1,
      -1,   -1,   -1,   -1,   -1,   -1,   -1,   -1,
      -1,   -1,   -1,   -1,   -1,   -1,   -1,   -1,
      -1,   -1,   -1,   -1,   -1,   -1,   -1,   -1,
      -1,   -1,   -1,   -1,   -1,   -1,   -1,   -1,
      -1,   -1,   -1,   -1,   -1,   -1,   -1,   -1,
      -1,   -1,   -1,   -1,   -1,   -1,   -1,   -1,
      -1,   -1,   -1,   -1,   -1,   -1,   -1,   -1,
      -1,   -1,   -1,   -1,   -1,   -1,   -1,   -1,
      -1,   -1,   -1,   -1,   -1,   -1,   -1,   -1,
      -1,   -1,   -1,   -1,   -1,   -1,   -1,   -1,
      -1,   -1,   -1,   -1,   -1,   -1,   -1,   -1,
      -1,   -1,   -1,   -1,   -1,   -1,   -1,   -1,
      -1,   -1,   -1,   -1,   -1,   -1,   -1,   -1,
      -1,   -1,   -1,   -1,   -1,   -1,   -1,   -1,
      -1,   -1,   -1,   -1,   -1,   -1,   -1,   -1,
      -1,   -1,   -1,   -1,   -1,   -1,   -1,   -1,
      -1,   -1,   -1,   -1,   -1,   -1,   -1,   -1,
      -1,   -1,   -1,   -1,   -1,   -1,   -1,   -1,
      -1,   -1,   -1,   -1,   -1,   -1,   -1,   -1,
      -1,   -1,   -1,   -1,   -1,   -1,   -1,   -1,
      -1,   -1,   -1,   -1,   -1,   -1,   -1,   -1,
      -1,   -1,   -1,   -1,   -1,   -1,   -1,   -1,
      -1,   -1,   -1,   -1,   -1,   -1,   -1,   -1,
    4279,   -1,   -1,   -1,   -1,   -1,   -1,   -1,
      -1,   -1,   -1,   -1,   -1,   -1,   -1,   -1,
      -1,   -1,   -1,   -1,   -1,   -1,   -1,   -1,
      -1,   -1,   -1,   -1,   -1,   -1,   -1,   -1,
      -1,   -1,   -1,   -1,   -1,   -1,   -1,   -1,
      -1,   -1,   -1,   -1,   -1,   -1,   -1,   -1,
      -1,   -1,   -1,   -1,   -1,   -1,   -1,   -1,
      -1,   -1,   -1,   -1,   -1,   -1,   -1,   -1,
      -1,   -1,   -1,   -1,   -1,   -1,   -1,   -1,
      -1,   -1,   -1,   -1,   -1,   -1,   -1,   -1,
      -1,   -1,   -1,   -1,   -1,   -1,   -1,   -1,
      -1,   -1,   -1,   -1,   -1,   -1,   -1,   -1,
      -1,   -1,   -1,   -1,   -1,   -1,   -1,   -1,
      -1,   -1,   -1,   -1,   -1,   -1,   -1,   -1,
      -1,   -1,   -1,   -1,   -1,   -1,   -1,   -1,
      -1,   -1,   -1,   -1,   -1,   -1,   -1,   -1,
      -1,   -1,   -1,   -1,   -1,   -1,   -1,   -1,
      -1,   -1,   -1,   -1,   -1,   -1,   -1,   -1,
      -1,   -1,   -1,   -1,   -1,   -1,   -1,   -1,
      -1,   -1,   -1,   -1,   -1,   -1,   -1,   -1,
      -1,   -1,   -1,   -1,   -1,   -1,   -1,   -1,
      -1,   -1,   -1,   -1,   -1,   -1,   -1,   -1,
      -1,   -1,   -1,   -1,   -1,   -1,   -1,   -1,
      -1,   -1,   -1,   -1,   -1,   -1,   -1,   -1,
      -1,   -1,   -1,   -1,   -1,   -1,   -1,   -1,
      -1,   -1,   -1,   -1,   -1,   -1,   -1,   -1,
      -1,   -1,   -1,   -1,   -1,   -1,   -1,   -1,
      -1,   -1,   -1,   -1,   -1,   -1,   -1,   -1,
      -1,   -1,   -1,   -1,   -1,   -1,   -1,   -1,
      -1,   -1,   -1,   -1,   -1,   -1,   -1,   -1,
      -1,   -1,   -1,   -1,   -1,   -1,   -1,   -1,
      -1,   -1,   -1,   -1,   -1,   -1,   -1,   -1,
      -1,   -1,   -1,   -1,   -1,   -1,   -1,   -1,
      -1,   -1,   -1,   -1,   -1,   -1,   -1,   -1,
      -1,   -1,   -1,   -1,   -1,   -1,   -1,   -1,
      -1,   -1,   -1,   -1,   -1,   -1,   -1,   -1,
      -1,   -1,   -1,   -1,   -1,   -1,   -1,   -1,
      -1,   -1,   -1,   -1,   -1,   -1,   -1,   -1,
      -1,   -1,   -1,   -1,   -1,   -1,   -1,   -1,
      -1,   -1,   -1,   -1,   -1,   -1,   -1,   -1,
      -1,   -1,   -1,   -1,   -1,   -1,   -1,   -1,
      -1,   -1,   -1,   -1,   -1,   -1,   -1,   -1,
      -1,   -1,   -1,   -1,   -1,   -1,   -1,   -1,
      -1,   -1,   -1,   -1,   -1,   -1,   -1,   -1,
      -1,   -1,   -1,   -1,   -1,   -1,   -1,   -1,
      -1,   -1,   -1,   -1,   -1,   -1,   -1,   -1,
      -1,   -1,   -1,   -1,   -1,   -1,   -1,   -1,
      -1,   -1,   -1,   -1,   -1,   -1,   -1,   -1,
      -1,   -1,   -1,   -1,   -1,   -1,   -1,   -1,
      -1,   -1,   -1,   -1,   -1,   -1,   -1,   -1,
      -1,   -1,   -1,   -1,   -1,   -1,   -1,   -1,
      -1,   -1,   -1,   -1,   -1,   -1,   -1,   -1,
      -1,   -1,   -1,   -1,   -1,   -1,   -1,   -1,
      -1,   -1,   -1,   -1,   -1,   -1,   -1,   -1,
      -1,   -1,   -1,   -1,   -1,   -1,   -1,   -1,
      -1,   -1,   -1,   -1,   -1,   -1,   -1,   -1,
      -1,   -1,   -1,   -1,   -1,   -1,   -1,   -1,
      -1,   -1,   -1,   -1,   -1,   -1,   -1,   -1,
      -1,   -1,   -1,   -1,   -1,   -1,   -1,   -1,
      -1,   -1,   -1,   -1,   -1,   -1,   -1,   -1,
      -1,   -1,   -1,   -1,   -1,   -1,   -1,   -1,
      -1,   -1,   -1,   -1,   -1,   -1,   -1,   -1,
      -1,   -1,   -1,   -1,   -1,   -1,   -1,   -1,
      -1,   -1,   -1,   -1,   -1,   -1,   -1,   -1,
      -1,   -1,   -1,   -1,   -1,   -1,   -1,   -1,
      -1,   -1,   -1,   -1,   -1,   -1,   -1,   -1,
      -1,   -1,   -1,   -1,   -1,   -1,   -1,   -1,
      -1,   -1,   -1,   -1,   -1,   -1,   -1,   -1,
      -1,   -1,   -1,   -1,   -1,   -1,   -1,   -1,
      -1,   -1,   -1,   -1,   -1,   -1,   -1,   -1,
      -1,   -1,   -1,   -1,   -1,   -1,   -1,   -1,
      -1,   -1,   -1,   -1,   -1,   -1,   -1,   -1,
      -1,   -1,   -1,   -1,   -1,   -1,   -1,   -1,
      -1,   -1,   -1,   -1,   -1,   -1,   -1,   -1,
      -1,   -1,   -1,   -1,   -1,   -1,   -1,   -1,
      -1,   -1,   -1,   -1,   -1,   -1,   -1,   -1,
      -1,   -1,   -1,   -1,   -1,   -1,   -1,   -1,
      -1,   -1,   -1,   -1,   -1,   -1,   -1,   -1,
      -1,   -1,   -1,   -1,   -1,   -1,   -1,   -1,
      -1,   -1,   -1,   -1,   -1,   -1,   -1,   -1,
      -1,   -1,   -1,   -1,   -1,   -1,   -1,   -1,
      -1,   -1,   -1,   -1,   -1,   -1,   -1,   -1,
      -1,   -1,   -1,   -1,   -1,   -1,   -1,   -1,
      -1,   -1,   -1,   -1,   -1,   -1,   -1,   -1,
      -1,   -1,   -1,   -1,   -1,   -1,   -1,   -1,
      -1,   -1,   -1,   -1,   -1,   -1,   -1,   -1,
      -1,   -1,   -1,   -1,   -1,   -1,   -1,   -1,
      -1,   -1,   -1,   -1,   -1,   -1,   -1,   -1,
      -1,   -1,   -1,   -1,   -1,   -1,   -1,   -1,
      -1,   -1,   -1,   -1,   -1,   -1,   -1,   -1,
      -1,   -1,   -1,   -1,   -1,   -1,   -1,   -1,
      -1,   -1,   -1,   -1,   -1,   -1,   -1,   -1,
      -1,   -1,   -1,   -1,   -1,   -1,   -1,   -1,
      -1,   -1,   -1,   -1,   -1,   -1,   -1,   -1,
      -1,   -1,   -1,   -1,   -1,   -1,   -1,   -1,
      -1,   -1,   -1,   -1,   -1,   -1,   -1,   -1,
      -1,   -1,   -1,   -1,   -1,   -1,   -1,   -1,
      -1,   -1,   -1,   -1,   -1,   -1,   -1,   -1,
      -1,   -1,   -1,   -1,   -1,   -1,   -1,   -1,
      -1,   -1,   -1,   -1,   -1,   -1,   -1,   -1,
      -1,   -1,   -1,   -1,   -1,   -1,   -1,   -1,
      -1,   -1,   -1,   -1,   -1,   -1,   -1,   -1,
      -1,   -1,   -1,   -1,   -1,   -1,   -1,   -1,
      -1,   -1,   -1,   -1,   -1,   -1,   -1,   -1,
      -1,   -1,   -1,   -1,   -1,   -1,   -1,   -1,
      -1,   -1,   -1,   -1,   -1,   -1,   -1,   -1,
      -1,   -1,   -1,   -1,   -1,   -1,   -1,   -1,
      -1,   -1,   -1,   -1,   -1,   -1,   -1,   -1,
      -1,   -1,   -1,   -1,   -1,   -1,   -1,   -1,
      -1,   -1,   -1,   -1,   -1,   -1,   -1,   -1,
      -1,   -1,   -1,   -1,   -1,   -1,   -1,   -1,
      -1,   -1,   -1,   -1,   -1,   -1,   -1,   -1,
      -1,   -1,   -1,   -1,   -1,   -1,   -1,   -1,
      -1,   -1,   -1,   -1,   -1,   -1,   -1,   -1,
      -1,   -1,   -1,   -1,   -1,   -1,   -1,   -1,
      -1,   -1,   -1,   -1,   -1,   -1,   -1,   -1,
      -1,   -1,   -1,   -1,   -1,   -1,   -1,   -1,
      -1,   -1,   -1,   -1,   -1,   -1,   -1,   -1,
      -1,   -1,   -1,   -1,   -1,   -1,   -1,   -1,
      -1,   -1,   -1,   -1,   -1,   -1,   -1,   -1,
      -1,   -1,   -1,   -1,   -1,   -1,   -1,   -1,
      -1,   -1,   -1,   -1,   -1,   -1,   -1,   -1,
      -1,   -1,   -1,   -1,   -1,   -1,   -1,   -1,
      -1,   -1,   -1,   -1,   -1,   -1,   -1,   -1,
      -1,   -1,   -1,   -1,   -1,   -1,   -1,   -1,
      -1,   -1,   -1,   -1,   -1,   -1,   -1,   -1,
      -1,   -1,   -1,   -1,   -1,   -1,   -1,   -1,
      -1,   -1,   -1,   -1,   -1,   -1,   -1,   -1,
      -1,   -1,   -1,   -1,   -1,   -1,   -1,   -1,
      -1,   -1,   -1,   -1,   -1,   -1,   -1,   -1,
      -1,   -1,   -1,   -1,   -1,   -1,   -1,   -1,
      -1,   -1,   -1,   -1,   -1,   -1,   -1,   -1,
      -1,   -1,   -1,   -1,   -1,   -1,   -1,   -1,
      -1,   -1,   -1,   -1,   -1,   -1,   -1,   -1,
      -1,   -1,   -1,   -1,   -1,   -1,   -1,   -1,
      -1,   -1,   -1,   -1,   -1,   -1,   -1,   -1,
      -1,   -1,   -1,   -1,   -1,   -1,   -1,   -1,
      -1,   -1,   -1,   -1,   -1,   -1,   -1,   -1,
      -1,   -1,   -1,   -1,   -1,   -1,   -1,   -1,
      -1,   -1,   -1,   -1,   -1,   -1,   -1,   -1,
      -1,   -1,   -1,   -1,   -1,   -1,   -1,   -1,
      -1,   -1,   -1,   -1,   -1,   -1,   -1,   -1,
      -1,   -1,   -1,   -1,   -1,   -1,   -1,   -1,
      -1,   -1,   -1,   -1,   -1,   -1,   -1,   -1,
      -1,   -1,   -1,   -1,   -1,   -1,   -1,   -1,
      -1,   -1,   -1,   -1,   -1,   -1,   -1,   -1,
      -1,   -1,   -1,   -1,   -1,   -1,   -1,   -1,
      -1,   -1,   -1,   -1,   -1,   -1,   -1,   -1,
      -1,   -1,   -1,   -1,   -1,   -1,   -1,   -1,
      -1,   -1,   -1,   -1,   -1,   -1,   -1,   -1,
      -1,   -1,   -1,   -1,   -1,   -1,   -1,   -1,
      -1,   -1,   -1,   -1,   -1,   -1,   -1,   -1,
      -1,   -1,   -1,   -1,   -1,   -1,   -1,   -1,
      -1,   -1,   -1,   -1,   -1,   -1,   -1,   -1,
      -1,   -1,   -1,   -1,   -1,   -1,   -1,   -1,
      -1,   -1,   -1,   -1,   -1,   -1,   -1,   -1,
      -1,   -1,   -1,   -1,   -1,   -1,   -1,   -1,
      -1,   -1,   -1,   -1,   -1,   -1,   -1,   -1,
      -1,   -1,   -1,   -1,   -1,   -1,   -1,   -1,
      -1,   -1,   -1,   -1,   -1,   -1,   -1,   -1,
      -1,   -1,   -1,   -1,   -1,   -1,   -1,   -1,
      -1,   -1,   -1,   -1,   -1,   -1,   -1,   -1,
      -1,   -1,   -1,   -1,   -1,   -1,   -1,   -1,
      -1,   -1,   -1,   -1,   -1,   -1,   -1,   -1,
      -1,   -1,   -1,   -1,   -1,   -1,   -1,   -1,
      -1,   -1,   -1,   -1,   -1,   -1,   -1,   -1,
      -1,   -1,   -1,   -1,   -1,   -1,   -1,   -1,
      -1,   -1,   -1,   -1,   -1,   -1,   -1,   -1,
      -1,   -1,   -1,   -1,   -1,   -1,   -1,   -1,
      -1,   -1,   -1,   -1,   -1,   -1,   -1,   -1,
      -1,   -1,   -1,   -1,   -1,   -1,   -1,   -1,
      -1,   -1,   -1,   -1,   -1,   -1,   -1,   -1,
      -1,   -1,   -1,   -1,   -1,   -1,   -1,   -1,
      -1,   -1,   -1,   -1,   -1,   -1,   -1,   -1,
      -1,   -1,   -1,   -1,   -1,   -1,   -1,   -1,
      -1,   -1,   -1,   -1,   -1,   -1,   -1,   -1,
      -1,   -1,   -1,   -1,   -1,   -1,   -1,   -1,
      -1,   -1,   -1,   -1,   -1,   -1,   -1,   -1,
      -1,   -1,   -1,   -1,   -1,   -1,   -1,   -1,
      -1,   -1,   -1,   -1,   -1,   -1,   -1,   -1,
      -1,   -1,   -1,   -1,   -1,   -1,   -1,   -1,
      -1,   -1,   -1,   -1,   -1,   -1,   -1,   -1,
      -1,   -1,   -1,   -1,   -1,   -1,   -1,   -1,
      -1,   -1,   -1,   -1,   -1,   -1,   -1,   -1,
      -1,   -1,   -1,   -1,   -1,   -1,   -1,   -1,
      -1,   -1,   -1,   -1,   -1,   -1,   -1,   -1,
      -1,   -1,   -1,   -1,   -1,   -1,   -1,   -1,
      -1,   -1,   -1,   -1,   -1,   -1,   -1,   -1,
      -1,   -1,   -1,   -1,   -1,   -1,   -1,   -1,
      -1,   -1,   -1,   -1,   -1,   -1,   -1,   -1,
      -1,   -1,   -1,   -1,   -1,   -1,   -1,   -1,
      -1,   -1,   -1,   -1,   -1,   -1,   -1,   -1,
      -1,   -1,   -1,   -1,   -1,   -1,   -1,   -1,
      -1,   -1,   -1,   -1,   -1,   -1,   -1,   -1,
      -1,   -1,   -1,   -1,   -1,   -1,   -1,   -1,
      -1,   -1,   -1,   -1,   -1,   -1,   -1,   -1,
      -1,   -1,   -1,   -1,   -1,   -1,   -1,   -1,
      -1,   -1,   -1,   -1,   -1,   -1,   -1,   -1,
      -1,   -1,   -1,   -1,   -1,   -1,   -1,   -1,
      -1,   -1,   -1,   -1,   -1,   -1,   -1,   -1,
      -1,   -1,   -1,   -1,   -1,   -1,   -1,   -1,
      -1,   -1,   -1,   -1,   -1,   -1,   -1,   -1,
      -1,   -1,   -1,   -1,   -1,   -1,   -1,   -1,
      -1,   -1,   -1,   -1,   -1,   -1,   -1,   -1,
      -1,   -1,   -1,   -1,   -1,   -1,   -1,   -1,
      -1,   -1,   -1,   -1,   -1,   -1,   -1,   -1,
      -1,   -1,   -1,   -1,   -1,   -1,   -1,   -1,
      -1,   -1,   -1,   -1,   -1,   -1,   -1,   -1,
      -1,   -1,   -1,   -1,   -1,   -1,   -1,   -1,
      -1,   -1,   -1,   -1,   -1,   -1,   -1,   -1,
      -1,   -1,   -1,   -1,   -1,   -1,   -1,   -1,
      -1,   -1,   -1,   -1,   -1,   -1,   -1,   -1,
      -1,   -1,   -1,   -1,   -1,   -1,   -1,   -1,
      -1,   -1,   -1,   -1,   -1,   -1,   -1,   -1,
      -1,   -1,   -1,   -1,   -1,   -1,   -1,   -1,
      -1,   -1,   -1,   -1,   -1,   -1,   -1,   -1,
      -1,   -1,   -1,   -1,   -1,   -1,   -1,   -1,
      -1,   -1,   -1,   -1,   -1,   -1,   -1,   -1,
      -1,   -1,   -1,   -1,   -1,   -1,   -1,   -1,
      -1,   -1,   -1,   -1,   -1,   -1,   -1,   -1,
      -1,   -1,   -1,   -1,   -1,   -1,   -1,   -1,
      -1,   -1,   -1,   -1,   -1,   -1,   -1,   -1,
      -1,   -1,   -1,   -1,   -1,   -1,   -1,   -1,
      -1,   -1,   -1,   -1,   -1,   -1,   -1,   -1,
      -1,   -1,   -1,   -1,   -1,   -1,   -1,   -1,
      -1,   -1,   -1,   -1,   -1,   -1,   -1,   -1,
      -1,   -1,   -1,   -1,   -1,   -1,   -1,   -1,
      -1,   -1,   -1,   -1,   -1,   -1,   -1,   -1,
      -1,   -1,   -1,   -1,   -1,   -1,   -1,   -1,
      -1,   -1,   -1,   -1,   -1,   -1,   -1,   -1,
      -1,   -1,   -1,   -1,   -1,   -1,   -1,   -1,
      -1,   -1,   -1,   -1,   -1,   -1,   -1,   -1,
      -1,   -1,   -1,   -1,   -1,   -1,   -1,   -1,
      -1,   -1,   -1,   -1,   -1,   -1,   -1,   -1,
      -1,   -1,   -1,   -1,   -1,   -1,   -1,   -1,
      -1,   -1,   -1,   -1,   -1,   -1,   -1,   -1,
      -1,   -1,   -1,   -1,   -1,   -1,   -1,   -1,
      -1,   -1,   -1,   -1,   -1,   -1,   -1,   -1,
      -1,   -1,   -1,   -1,   -1,   -1,   -1,   -1,
      -1,   -1,   -1,   -1,   -1,   -1,   -1,   -1,
      -1,   -1,   -1,   -1,   -1,   -1,   -1,   -1,
      -1,   -1,   -1,   -1,   -1,   -1,   -1,   -1,
      -1,   -1,   -1,   -1,   -1,   -1,   -1,   -1,
      -1,   -1,   -1,   -1,   -1,   -1,   -1,   -1,
      -1,   -1,   -1,   -1,   -1,   -1,   -1,   -1,
      -1,   -1,   -1,   -1,   -1,   -1,   -1,   -1,
      -1,   -1,   -1,   -1,   -1,   -1,   -1,   -1,
      -1,   -1,   -1,   -1,   -1,   -1,   -1,   -1,
      -1,   -1,   -1,   -1,   -1,   -1,   -1,   -1,
      -1,   -1,   -1,   -1,   -1,   -1,   -1,   -1,
      -1,   -1,   -1,   -1,   -1,   -1,   -1,   -1,
      -1,   -1,   -1,   -1,   -1,   -1,   -1,   -1,
      -1,   -1,   -1,   -1,   -1,   -1,   -1,   -1,
      -1,   -1,   -1,   -1,   -1,   -1,   -1,   -1,
      -1,   -1,   -1,   -1,   -1,   -1,   -1,   -1,
      -1,   -1,   -1,   -1,   -1,   -1,   -1,   -1,
      -1,   -1,   -1,   -1,   -1,   -1,   -1,   -1,
      -1,   -1,   -1,   -1,   -1,   -1,   -1,   -1,
      -1,   -1,   -1,   -1,   -1,   -1,   -1,   -1,
      -1,   -1,   -1,   -1,   -1,   -1,   -1,   -1,
      -1,   -1,   -1,   -1,   -1,   -1,   -1,   -1,
      -1,   -1,   -1,   -1,   -1,   -1,   -1,   -1,
      -1,   -1,   -1,   -1,   -1,   -1,   -1,   -1,
      -1,   -1,   -1,   -1,   -1,   -1,   -1,   -1,
      -1,   -1,   -1,   -1,   -1,   -1,   -1,   -1,
      -1,   -1,   -1,   -1,   -1,   -1,   -1,   -1,
      -1,   -1,   -1,   -1,   -1,   -1,   -1,   -1,
      -1,   -1,   -1,   -1,   -1,   -1,   -1,   -1,
      -1,   -1,   -1,   -1,   -1,   -1,   -1,   -1,
      -1,   -1,   -1,   -1,   -1,   -1,   -1,   -1,
      -1,   -1,   -1,   -1,   -1,   -1,   -1,   -1,
      -1,   -1,   -1,   -1,   -1,   -1,   -1,   -1,
      -1,   -1,   -1,   -1,   -1,   -1,   -1,   -1,
      -1,   -1,   -1,   -1,   -1,   -1,   -1,   -1,
      -1,   -1,   -1,   -1,   -1,   -1,   -1,   -1,
      -1,   -1,   -1,   -1,   -1,   -1,   -1,   -1,
      -1,   -1,   -1,   -1,   -1,   -1,   -1,   -1,
      -1,   -1,   -1,   -1,   -1,   -1,   -1,   -1,
      -1,   -1,   -1,   -1,   -1,   -1,   -1,   -1,
      -1,   -1,   -1,   -1,   -1,   -1,   -1,   -1,
      -1,   -1,   -1,   -1,   -1,   -1,   -1,   -1,
      -1,   -1,   -1,   -1,   -1,   -1,   -1,   -1,
      -1,   -1,   -1,   -1,   -1,   -1,   -1,   -1,
      -1,   -1,   -1,   -1,   -1,   -1,   -1,   -1,
      -1,   -1,   -1,   -1,   -1,   -1,   -1,   -1,
      -1,   -1,   -1,   -1,   -1,   -1,   -1,   -1,
      -1,   -1,   -1,   -1,   -1,   -1,   -1,   -1,
      -1,   -1,   -1,   -1,   -1,   -1,   -1,   -1,
      -1,   -1,   -1,   -1,   -1,   -1,   -1,   -1,
      -1,   -1,   -1,   -1,   -1,   -1,   -1,   -1,
      -1,   -1,   -1,   -1,   -1,   -1,   -1,   -1,
      -1,   -1,   -1,   -1,   -1,   -1,   -1,   -1,
      -1,   -1,   -1,   -1,   -1,   -1,   -1,   -1,
      -1,   -1,   -1,   -1,   -1,   -1,   -1,   -1,
      -1,   -1,   -1,   -1,   -1,   -1,   -1,   -1,
      -1,   -1,   -1,   -1,   -1,   -1,   -1,   -1,
      -1,   -1,   -1,   -1,   -1,   -1,   -1,   -1,
      -1,   -1,   -1,   -1,   -1,   -1,   -1,   -1,
      -1,   -1,   -1,   -1,   -1,   -1,   -1,   -1,
      -1,   -1,   -1,   -1,   -1,   -1,   -1,   -1,
      -1,   -1,   -1,   -1,   -1,   -1,   -1,   -1,
      -1,   -1,   -1,   -1,   -1,   -1,   -1,   -1,
      -1,   -1,   -1,   -1,   -1,   -1,   -1,   -1,
      -1,   -1,   -1,   -1,   -1,   -1,   -1,   -1,
      -1,   -1,   -1,   -1,   -1,   -1,   -1,   -1,
      -1,   -1,   -1,   -1,   -1,   -1,   -1,   -1,
      -1,   -1,   -1,   -1,   -1,   -1,   -1,   -1,
      -1,   -1,   -1,   -1,   -1,   -1,   -1,   -1,
      -1,   -1,   -1,   -1,   -1,   -1,   -1,   -1,
      -1,   -1,   -1,   -1,   -1,   -1,   -1,   -1,
      -1,   -1,   -1,   -1,   -1,   -1,   -1,   -1,
      -1,   -1,   -1,   -1,   -1,   -1,   -1,   -1,
      -1,   -1,   -1,   -1,   -1,   -1,   -1,   -1,
      -1,   -1,   -1,   -1,   -1,   -1,   -1,   -1,
      -1,   -1,   -1,   -1,   -1,   -1,   -1,   -1,
      -1,   -1,   -1,   -1,   -1,   -1,   -1,   -1,
      -1,   -1,   -1,   -1,   -1,   -1,   -1,   -1,
      -1,   -1,   -1,   -1,   -1,   -1,   -1,   -1,
      -1,   -1,   -1,   -1,   -1,   -1,   -1,   -1,
      -1,   -1,   -1,   -1,   -1,   -1,   -1,   -1,
      -1,   -1,   -1,   -1,   -1,   -1,   -1,   -1,
      -1,   -1,   -1,   -1,   -1,   -1,   -1,   -1,
      -1,   -1,   -1,   -1,   -1,   -1,   -1,   -1,
      -1,   -1,   -1,   -1,   -1,   -1,   -1,   -1,
      -1,   -1,   -1,   -1,   -1,   -1,   -1,   -1,
      -1,   -1,   -1,   -1,   -1,   -1,   -1,   -1,
      -1,   -1,   -1,   -1,   -1,   -1,   -1,   -1,
      -1,   -1,   -1,   -1,   -1,   -1,   -1,   -1,
      -1,   -1,   -1,   -1,   -1,   -1,   -1,   -1,
      -1,   -1,   -1,   -1,   -1,   -1,   -1,   -1,
      -1,   -1,   -1,   -1,   -1,   -1,   -1,   -1,
      -1,   -1,   -1,   -1,   -1,   -1,   -1,   -1,
      -1,   -1,   -1,   -1,   -1,   -1,   -1,   -1,
      -1,   -1,   -1,   -1,   -1,   -1,   -1,   -1,
      -1,   -1,   -1,   -1,   -1,   -1,   -1,   -1,
      -1,   -1,   -1,   -1,   -1,   -1,   -1,   -1,
      -1,   -1,   -1,   -1,   -1,   -1,   -1,   -1,
      -1,   -1,   -1,   -1,   -1,   -1,   -1,   -1,
      -1,   -1,   -1,   -1,   -1,   -1,   -1,   -1,
      -1,   -1,   -1,   -1,   -1,   -1,   -1,   -1,
      -1,   -1,   -1,   -1,   -1,   -1,   -1,   -1,
      -1,   -1,   -1,   -1,   -1,   -1,   -1,   -1,
      -1,   -1,   -1,   -1,   -1,   -1,   -1,   -1,
      -1,   -1,   -1,   -1,   -1,   -1,   -1,   -1,
      -1,   -1,   -1,   -1,   -1,   -1,   -1,   -1,
      -1,   -1,   -1,   -1,   -1,   -1,   -1,   -1,
      -1,   -1,   -1,   -1,   -1,   -1,   -1,   -1,
      -1,   -1,   -1,   -1,   -1,   -1,   -1,   -1,
      -1,   -1,   -1,   -1,   -1,   -1,   -1,   -1,
      -1,   -1,   -1,   -1,   -1,   -1,   -1,   -1,
      -1,   -1,   -1,   -1,   -1,   -1,   -1,   -1,
      -1,   -1,   -1,   -1,   -1,   -1,   -1,   -1,
      -1,   -1,   -1,   -1,   -1,   -1,   -1,   -1,
      -1,   -1,   -1,   -1,   -1,   -1,   -1,   -1,
      -1,   -1,   -1,   -1,   -1,   -1,   -1,   -1,
      -1,   -1,   -1,   -1,   -1,   -1,   -1,   -1,
      -1,   -1,   -1,   -1,   -1,   -1,   -1,   -1,
      -1,   -1,   -1,   -1,   -1,   -1,   -1,   -1,
      -1,   -1,   -1,   -1,   -1,   -1,   -1,   -1,
      -1,   -1,   -1,   -1,   -1,   -1,   -1,   -1,
      -1,   -1,   -1,   -1,   -1,   -1,   -1,   -1,
      -1,   -1,   -1,   -1,   -1,   -1,   -1,   -1,
      -1,   -1,   -1,   -1,   -1,   -1,   -1,   -1,
      -1,   -1,   -1,   -1,   -1,   -1,   -1,   -1,
      -1,   -1,   -1,   -1,   -1,   -1,   -1,   -1,
      -1,   -1,   -1,   -1,   -1,   -1,   -1,   -1,
      -1,   -1,   -1,   -1,   -1,   -1,   -1,   -1,
      -1,   -1,   -1,   -1,   -1,   -1,   -1,   -1,
      -1,   -1,   -1,   -1,   -1,   -1,   -1,   -1,
      -1,   -1,   -1,   -1,   -1,   -1,   -1,   -1,
      -1,   -1,   -1,   -1,   -1,   -1,   -1,   -1,
      -1,   -1,   -1,   -1,   -1,   -1,   -1,   -1,
      -1,   -1,   -1,   -1,   -1,   -1,   -1,   -1,
      -1,   -1,   -1,   -1,   -1,   -1,   -1,   -1,
      -1,   -1,   -1,   -1,   -1,   -1,   -1,   -1,
      -1,   -1,   -1,   -1,   -1,   -1,   -1,   -1,
      -1,   -1,   -1,   -1,   -1,   -1,   -1,   -1,
      -1,   -1,   -1,   -1,   -1,   -1,   -1,   -1,
      -1,   -1,   -1,   -1,   -1,   -1,   -1,   -1,
      -1,   -1,   -1,   -1,   -1,   -1,   -1,   -1,
      -1,   -1,   -1,   -1,   -1,   -1,   -1,   -1,
      -1,   -1,   -1,   -1,   -1,   -1,   -1,   -1,
      -1,   -1,   -1,   -1,   -1,   -1,   -1,   -1,
      -1,   -1,   -1,   -1,   -1,   -1,   -1,   -1,
      -1,   -1,   -1,   -1,   -1,   -1,   -1,   -1,
      -1,   -1,   -1,   -1,   -1,   -1,   -1,   -1,
      -1,   -1,   -1,   -1,   -1,   -1,   -1,   -1,
      -1,   -1,   -1,   -1,   -1,   -1,   -1,   -1,
      -1,   -1,   -1,   -1,   -1,   -1,   -1,   -1,
      -1,   -1,   -1,   -1,   -1,   -1,   -1,   -1,
      -1,   -1,   -1,   -1,   -1,   -1,   -1,   -1,
      -1,   -1,   -1,   -1,   -1,   -1,   -1,   -1,
      -1,   -1,   -1,   -1,   -1,   -1,   -1,   -1,
      -1,   -1,   -1,   -1,   -1,   -1,   -1,   -1,
      -1,   -1,   -1,   -1,   -1,   -1,   -1,   -1,
      -1,   -1,   -1,   -1,   -1,   -1,   -1,   -1,
      -1,   -1,   -1,   -1,   -1,   -1,   -1,   -1,
      -1,   -1,   -1,   -1,   -1,   -1,   -1,   -1,
      -1,   -1,   -1,   -1,   -1,   -1,   -1,   -1,
      -1,   -1,   -1,   -1,   -1,   -1,   -1,   -1,
      -1,   -1,   -1,   -1,   -1,   -1,   -1,   -1,
      -1,   -1,   -1,   -1,   -1,   -1,   -1,   -1,
      -1,   -1,   -1,   -1,   -1,   -1,   -1,   -1,
      -1,   -1,   -1,   -1,   -1,   -1,   -1,   -1,
      -1,   -1,   -1,   -1,   -1,   -1,   -1,   -1,
      -1,   -1,   -1,   -1,   -1,   -1,   -1,   -1,
      -1,   -1,   -1,   -1,   -1,   -1,   -1,   -1,
      -1,   -1,   -1,   -1,   -1,   -1,   -1,   -1,
      -1,   -1,   -1,   -1,   -1,   -1,   -1,   -1,
      -1,   -1,   -1,   -1,   -1,   -1,   -1,   -1,
      -1,   -1,   -1,   -1,   -1,   -1,   -1,   -1,
      -1,   -1,   -1,   -1,   -1,   -1,   -1,   -1,
      -1,   -1,   -1,   -1,   -1,   -1,   -1,   -1,
      -1,   -1,   -1,   -1,   -1,   -1,   -1,   -1,
      -1,   -1,   -1,   -1,   -1,   -1,   -1,   -1,
      -1,   -1,   -1,   -1,   -1,   -1,   -1,   -1,
      -1,   -1,   -1,   -1,   -1,   -1,   -1,   -1,
      -1,   -1,   -1,   -1,   -1,   -1,   -1,   -1,
      -1,   -1,   -1,   -1,   -1,   -1,   -1,   -1,
      -1,   -1,   -1,   -1,   -1,   -1,   -1,   -1,
      -1,   -1,   -1,   -1,   -1,   -1,   -1,   -1,
      -1,   -1,   -1,   -1,   -1,   -1,   -1,   -1,
      -1,   -1,   -1,   -1,   -1,   -1,   -1,   -1,
      -1,   -1,   -1,   -1,   -1,   -1,   -1,   -1,
      -1,   -1,   -1,   -1,   -1,   -1,   -1,   -1,
      -1,   -1,   -1,   -1,   -1,   -1,   -1,   -1,
      -1,   -1,   -1,   -1,   -1,   -1,   -1,   -1,
      -1,   -1,   -1,   -1,   -1,   -1,   -1,   -1,
      -1,   -1,   -1,   -1,   -1,   -1,   -1,   -1,
      -1,   -1,   -1,   -1,   -1,   -1,   -1,   -1,
      -1,   -1,   -1,   -1,   -1,   -1,   -1,   -1,
      -1,   -1,   -1,   -1,   -1,   -1,   -1,   -1,
      -1,   -1,   -1,   -1,   -1,   -1,   -1,   -1,
      -1,   -1,   -1,   -1,   -1,   -1,   -1,   -1,
      -1,   -1,   -1,   -1,   -1,   -1,   -1,   -1,
      -1,   -1,   -1,   -1,   -1,   -1,   -1,   -1,
      -1,   -1,   -1,   -1,   -1,   -1,   -1,   -1,
      -1,   -1,   -1,   -1,   -1,   -1,   -1,   -1,
      -1,   -1,   -1,   -1,   -1,   -1,   -1,   -1,
      -1,   -1,   -1,   -1,   -1,   -1,   -1,   -1,
      -1,   -1,   -1,   -1,   -1,   -1,   -1,   -1,
      -1,   -1,   -1,   -1,   -1,   -1,   -1,   -1,
      -1,   -1,   -1,   -1,   -1,   -1,   -1,   -1,
      -1,   -1,   -1,   -1,   -1,   -1,   -1,   -1,
      -1,   -1,   -1,   -1,   -1,   -1,   -1,   -1,
      -1,   -1,   -1,   -1,   -1,   -1,   -1,   -1,
      -1,   -1,   -1,   -1,   -1,   -1,   -1,   -1,
      -1,   -1,   -1,   -1,   -1,   -1,   -1,   -1,
      -1,   -1,   -1,   -1,   -1,   -1,   -1,   -1,
      -1,   -1,   -1,   -1,   -1,   -1,   -1,   -1,
      -1,   -1,   -1,   -1,   -1,   -1,   -1,   -1,
      -1,   -1,   -1,   -1,   -1,   -1,   -1,   -1,
      -1,   -1,   -1,   -1,   -1,   -1,   -1,   -1,
      -1,   -1,   -1,   -1,   -1,   -1,   -1,   -1,
      -1,   -1,   -1,   -1,   -1,   -1,   -1,   -1,
      -1,   -1,   -1,   -1,   -1,   -1,   -1,   -1,
      -1,   -1,   -1,   -1,   -1,   -1,   -1,   -1,
      -1,   -1,   -1,   -1,   -1,   -1,   -1,   -1,
      -1,   -1,   -1,   -1,   -1,   -1,   -1,   -1,
      -1,   -1,   -1,   -1,   -1,   -1,   -1,   -1,
      -1,   -1,   -1,   -1,   -1,   -1,   -1,   -1,
      -1,   -1,   -1,   -1,   -1,   -1,   -1,   -1,
      -1,   -1,   -1,   -1,   -1,   -1,   -1,   -1,
      -1,   -1,   -1,   -1,   -1,   -1,   -1,   -1,
      -1,   -1,   -1,   -1,   -1,   -1,   -1,   -1,
      -1,   -1,   -1,   -1,   -1,   -1,   -1,   -1,
      -1,   -1,   -1,   -1,   -1,   -1,   -1,   -1,
      -1,   -1,   -1,   -1,   -1,   -1,   -1,   -1,
      -1,   -1,   -1,   -1,   -1,   -1,   -1,   -1,
      -1,   -1,   -1,   -1,   -1,   -1,   -1,   -1,
      -1,   -1,   -1,   -1,   -1,   -1,   -1,   -1,
      -1,   -1,   -1,   -1,   -1,   -1,   -1,   -1,
      -1,   -1,   -1,   -1,   -1,   -1,   -1,   -1,
      -1,   -1,   -1,   -1,   -1,   -1,   -1,   -1,
      -1,   -1,   -1,   -1,   -1,   -1,   -1,   -1,
      -1,   -1,   -1,   -1,   -1,   -1,   -1,   -1,
      -1,   -1,   -1,   -1,   -1,   -1,   -1,   -1,
      -1,   -1,   -1,   -1,   -1,   -1,   -1,   -1,
      -1,   -1,   -1,   -1,   -1,   -1,   -1,   -1,
      -1,   -1,   -1,   -1,   -1,   -1,   -1,   -1,
      -1,   -1,   -1,   -1,   -1,   -1,   -1,   -1,
      -1,   -1,   -1,   -1,   -1,   -1,   -1,   -1,
      -1,   -1,   -1,   -1,   -1,   -1,   -1,   -1,
      -1,   -1,   -1,   -1,   -1,   -1,   -1,   -1,
      -1,   -1,   -1,   -1,   -1,   -1,   -1,   -1,
      -1,   -1,   -1,   -1,   -1,   -1,   -1,   -1,
      -1,   -1,   -1,   -1,   -1,   -1,   -1,   -1,
      -1,   -1,   -1,   -1,   -1,   -1,   -1,   -1,
      -1,   -1,   -1,   -1,   -1,   -1,   -1,   -1,
      -1,   -1,   -1,   -1,   -1,   -1,   -1,   -1,
      -1,   -1,   -1,   -1,   -1,   -1,   -1,   -1,
      -1,   -1,   -1,   -1,   -1,   -1,   -1,   -1,
      -1,   -1,   -1,   -1,   -1,   -1,   -1,   -1,
      -1,   -1,   -1,   -1,   -1,   -1,   -1,   -1,
      -1,   -1,   -1,   -1,   -1,   -1,   -1,   -1,
      -1,   -1,   -1,   -1,   -1,   -1,   -1,   -1,
      -1,   -1,   -1,   -1,   -1,   -1,   -1,   -1,
      -1,   -1,   -1,   -1,   -1,   -1,   -1,   -1,
      -1,   -1,   -1,   -1,   -1,   -1,   -1,   -1,
      -1,   -1,   -1,   -1,   -1,   -1,   -1,   -1,
      -1,   -1,   -1,   -1,   -1,   -1,   -1,   -1,
      -1,   -1,   -1,   -1,   -1,   -1,   -1,   -1,
      -1,   -1,   -1,   -1,   -1,   -1,   -1,   -1,
      -1,   -1,   -1,   -1,   -1,   -1,   -1,   -1,
      -1,   -1,   -1,   -1,   -1,   -1,   -1,   -1,
      -1,   -1,   -1,   -1,   -1,   -1,   -1,   -1,
      -1,   -1,   -1,   -1,   -1,   -1,   -1,   -1,
      -1,   -1,   -1,   -1,   -1,   -1,   -1,   -1,
      -1,   -1,   -1,   -1,   -1,   -1,   -1,   -1,
      -1,   -1,   -1,   -1,   -1,   -1,   -1,   -1,
      -1,   -1,   -1,   -1,   -1,   -1,   -1,   -1,
      -1,   -1,   -1,   -1,   -1,   -1,   -1,   -1,
      -1,   -1,   -1,   -1,   -1,   -1,   -1,   -1,
      -1,   -1,   -1,   -1,   -1,   -1,   -1,   -1,
      -1,   -1,   -1,   -1,   -1,   -1,   -1,   -1,
      -1,   -1,   -1,   -1,   -1,   -1,   -1,   -1,
      -1,   -1,   -1,   -1,   -1,   -1,   -1,   -1,
      -1,   -1,   -1,   -1,   -1,   -1,   -1,   -1,
      -1,   -1,   -1,   -1,   -1,   -1,   -1,   -1,
      -1,   -1,   -1,   -1,   -1,   -1,   -1,   -1,
      -1,   -1,   -1,   -1,   -1,   -1,   -1,   -1,
      -1,   -1,   -1,   -1,   -1,   -1,   -1,   -1,
      -1,   -1,   -1,   -1,   -1,   -1,   -1,   -1,
      -1,   -1,   -1,   -1,   -1,   -1,   -1,   -1,
      -1,   -1,   -1,   -1,   -1,   -1,   -1,   -1,
      -1,   -1,   -1,   -1,   -1,   -1,   -1,   -1,
      -1,   -1,   -1,   -1,   -1,   -1,   -1,   -1,
      -1,   -1,   -1,   -1,   -1,   -1,   -1,   -1,
      -1,   -1,   -1,   -1,   -1,   -1,   -1,   -1,
      -1,   -1,   -1,   -1,   -1,   -1,   -1,   -1,
      -1,   -1,   -1,   -1,   -1,   -1,   -1,   -1,
      -1,   -1,   -1,   -1,   -1,   -1,   -1,   -1,
      -1,   -1,   -1,   -1,   -1,   -1,   -1,   -1,
      -1,   -1,   -1,   -1,   -1,   -1,   -1,   -1,
      -1,   -1,   -1,   -1,   -1,   -1,   -1,   -1,
      -1,   -1,   -1,   -1,   -1,   -1,   -1,   -1,
      -1,   -1,   -1,   -1,   -1,   -1,   -1,   -1,
      -1,   -1,   -1,   -1,   -1,   -1,   -1,   -1,
      -1,   -1,   -1,   -1,   -1,   -1,   -1,   -1,
      -1,   -1,   -1,   -1,   -1,   -1,   -1,   -1,
      -1,   -1,   -1,   -1,   -1,   -1,   -1,   -1,
      -1,   -1,   -1,   -1,   -1,   -1,   -1,   -1,
      -1,   -1,   -1,   -1,   -1,   -1,   -1,   -1,
      -1,   -1,   -1,   -1,   -1,   -1,   -1,   -1,
      -1,   -1,   -1,   -1,   -1,   -1,   -1,   -1,
      -1,   -1,   -1,   -1,   -1,   -1,   -1,   -1,
      -1,   -1,   -1,   -1,   -1,   -1,   -1,   -1,
      -1,   -1,   -1,   -1,   -1,   -1,   -1,   -1,
      -1,   -1,   -1,   -1,   -1,   -1,   -1,   -1,
      -1,   -1,   -1,   -1,   -1,   -1,   -1,   -1,
      -1,   -1,   -1,   -1,   -1,   -1,   -1,   -1,
      -1,   -1,   -1,   -1,   -1,   -1,   -1,   -1,
      -1,   -1,   -1,   -1,   -1,   -1,   -1,   -1,
      -1,   -1,   -1,   -1,   -1,   -1,   -1,   -1,
      -1,   -1,   -1,   -1,   -1,   -1,   -1,   -1,
      -1,   -1,   -1,   -1,   -1,   -1,   -1,   -1,
      -1,   -1,   -1,   -1,   -1,   -1,   -1,   -1,
      -1,   -1,   -1,   -1,   -1,   -1,   -1,   -1,
      -1,   -1,   -1,   -1,   -1,   -1,   -1,   -1,
      -1,   -1,   -1,   -1,   -1,   -1,   -1,   -1,
      -1,   -1,   -1,   -1,   -1,   -1,   -1,   -1,
      -1,   -1,   -1,   -1,   -1,   -1,   -1,   -1,
      -1,   -1,   -1,   -1,   -1,   -1,   -1,   -1,
      -1,   -1,   -1,   -1,   -1,   -1,   -1,   -1,
      -1,   -1,   -1,   -1,   -1,   -1,   -1,   -1,
      -1,   -1,   -1,   -1,   -1,   -1,   -1,   -1,
      -1,   -1,   -1,   -1,   -1,   -1,   -1,   -1,
      -1,   -1,   -1,   -1,   -1,   -1,   -1,   -1,
      -1,   -1,   -1,   -1,   -1,   -1,   -1,   -1,
      -1,   -1,   -1,   -1,   -1,   -1,   -1,   -1,
      -1,   -1,   -1,   -1,   -1,   -1,   -1,   -1,
      -1,   -1,   -1,   -1,   -1,   -1,   -1,   -1,
      -1,   -1,   -1,   -1,   -1,   -1,   -1,   -1,
      -1,   -1,   -1,   -1,   -1,   -1,   -1,   -1,
      -1,   -1,   -1,   -1,   -1,   -1,   -1,   -1,
      -1,   -1,   -1,   -1,   -1,   -1,   -1,   -1,
      -1,   -1,   -1,   -1,   -1,   -1,   -1,   -1,
      -1,   -1,   -1,   -1,   -1,   -1,   -1,   -1,
      -1,   -1,   -1,   -1,   -1,   -1,   -1,   -1,
      -1,   -1,   -1,   -1,   -1,   -1,   -1,   -1,
      -1,   -1,   -1,   -1,   -1,   -1,   -1,   -1,
      -1,   -1,   -1,   -1,   -1,   -1,   -1,   -1,
      -1,   -1,   -1,   -1,   -1,   -1,   -1,   -1,
      -1,   -1,   -1,   -1,   -1,   -1,   -1,   -1,
      -1,   -1,   -1,   -1,   -1,   -1,   -1,   -1,
      -1,   -1,   -1,   -1,   -1,   -1,   -1,   -1,
      -1,   -1,   -1,   -1,   -1,   -1,   -1,   -1,
      -1,   -1,   -1,   -1,   -1,   -1,   -1,   -1,
      -1,   -1,   -1,   -1,   -1,   -1,   -1,   -1,
      -1,   -1,   -1,   -1,   -1,   -1,   -1,   -1,
      -1,   -1,   -1,   -1,   -1,   -1,   -1,   -1,
      -1,   -1,   -1,   -1,   -1,   -1,   -1,   -1,
      -1,   -1,   -1,   -1,   -1,   -1,   -1,   -1,
      -1,   -1,   -1,   -1,   -1,   -1,   -1,   -1,
      -1,   -1,   -1,   -1,   -1,   -1,   -1,   -1,
      -1,   -1,   -1,   -1,   -1,   -1,   -1,   -1,
      -1,   -1,   -1,   -1,   -1,   -1,   -1,   -1,
      -1,   -1,   -1,   -1,   -1,   -1,   -1,   -1,
      -1,   -1,   -1,   -1,   -1,   -1,   -1,   -1,
      -1,   -1,   -1,   -1,   -1,   -1,   -1,   -1,
      -1,   -1,   -1,   -1,   -1,   -1,   -1,   -1,
      -1,   -1,   -1,   -1,   -1,   -1,   -1,   -1,
      -1,   -1,   -1,   -1,   -1,   -1,   -1,   -1,
      -1,   -1,   -1,   -1,   -1,   -1,   -1,   -1,
      -1,   -1,   -1,   -1,   -1,   -1,   -1,   -1,
      -1,   -1,   -1,   -1,   -1,   -1,   -1,   -1,
      -1,   -1,   -1,   -1,   -1,   -1,   -1,   -1,
      -1,   -1,   -1,   -1,   -1,   -1,   -1,   -1,
      -1,   -1,   -1,   -1,   -1,   -1,   -1,   -1,
      -1,   -1,   -1,   -1,   -1,   -1,   -1,   -1,
      -1,   -1,   -1,   -1,   -1,   -1,   -1,   -1,
      -1,   -1,   -1,   -1,   -1,   -1,   -1,   -1,
      -1,   -1,   -1,   -1,   -1,   -1,   -1,   -1,
      -1,   -1,   -1,   -1,   -1,   -1,   -1,   -1,
      -1,   -1,   -1,   -1,   -1,   -1,   -1,   -1,
      -1,   -1,   -1,   -1,   -1,   -1,   -1,   -1,
      -1,   -1,   -1,   -1,   -1,   -1,   -1,   -1,
      -1,   -1,   -1,   -1,   -1,   -1,   -1,   -1,
      -1,   -1,   -1,   -1,   -1,   -1,   -1,   -1,
      -1,   -1,   -1,   -1,   -1,   -1,   -1,   -1,
      -1,   -1,   -1,   -1,   -1,   -1,   -1,   -1,
      -1,   -1,   -1,   -1,   -1,   -1,   -1,   -1,
      -1,   -1,   -1,   -1,   -1,   -1,   -1,   -1,
      -1,   -1,   -1,   -1,   -1,   -1,   -1,   -1,
      -1,   -1,   -1,   -1,   -1,   -1,   -1,   -1,
      -1,   -1,   -1,   -1,   -1,   -1,   -1,   -1,
      -1,   -1,   -1,   -1,   -1,   -1,   -1,   -1,
      -1,   -1,   -1,   -1,   -1,   -1,   -1,   -1,
      -1,   -1,   -1,   -1,   -1,   -1,   -1,   -1,
      -1,   -1,   -1,   -1,   -1,   -1,   -1,   -1,
      -1,   -1,   -1,   -1,   -1,   -1,   -1,   -1,
      -1,   -1,   -1,   -1,   -1,   -1,   -1,   -1,
      -1,   -1,   -1,   -1,   -1,   -1,   -1,   -1,
      -1,   -1,   -1,   -1,   -1,   -1,   -1,   -1,
      -1,   -1,   -1,   -1,   -1,   -1,   -1,   -1,
      -1,   -1,   -1,   -1,   -1,   -1,   -1,   -1,
      -1,   -1,   -1,   -1,   -1,   -1,   -1,   -1,
      -1,   -1,   -1,   -1,   -1,   -1,   -1,   -1,
      -1,   -1,   -1,   -1,   -1,   -1,   -1,   -1,
      -1,   -1,   -1,   -1,   -1,   -1,   -1,   -1,
      -1,   -1,   -1,   -1,   -1,   -1,   -1,   -1,
      -1,   -1,   -1,   -1,   -1,   -1,   -1,   -1,
      -1,   -1,   -1,   -1,   -1,   -1,   -1,   -1,
      -1,   -1,   -1,   -1,   -1,   -1,   -1,   -1,
      -1,   -1,   -1,   -1,   -1,   -1,   -1,   -1,
      -1,   -1,   -1,   -1,   -1,   -1,   -1,   -1,
      -1,   -1,   -1,   -1,   -1,   -1,   -1,   -1,
      -1,   -1,   -1,   -1,   -1,   -1,   -1,   -1,
      -1,   -1,   -1,   -1,   -1,   -1,   -1,   -1,
      -1,   -1,   -1,   -1,   -1,   -1,   -1,   -1,
      -1,   -1,   -1,   -1,   -1,   -1,   -1,   -1,
      -1,   -1,   -1,   -1,   -1,   -1,   -1,   -1,
      -1,   -1,   -1,   -1,   -1,   -1,   -1,   -1,
      -1,   -1,   -1,   -1,   -1,   -1,   -1,   -1,
      -1,   -1,   -1,   -1,   -1,   -1,   -1,   -1,
      -1,   -1,   -1,   -1,   -1,   -1,   -1,   -1,
      -1,   -1,   -1,   -1,   -1,   -1,   -1,   -1,
      -1,   -1,   -1,   -1,   -1,   -1,   -1,   -1,
      -1,   -1,   -1,   -1,   -1,   -1,   -1,   -1,
      -1,   -1,   -1,   -1,   -1,   -1,   -1,   -1,
      -1,   -1,   -1,   -1,   -1,   -1,   -1,   -1,
      -1,   -1,   -1,   -1,   -1,   -1,   -1,   -1,
      -1,   -1,   -1,   -1,   -1,   -1,   -1,   -1,
      -1,   -1,   -1,   -1,   -1,   -1,   -1,   -1,
      -1,   -1,   -1,   -1,   -1,   -1,   -1,   -1,
      -1,   -1,   -1,   -1,   -1,   -1,   -1,   -1,
      -1,   -1,   -1,   -1,   -1,   -1,   -1,   -1,
      -1,   -1,   -1,   -1,   -1,   -1,   -1,   -1,
      -1,   -1,   -1,   -1,   -1,   -1,   -1,   -1,
      -1,   -1,   -1,   -1,   -1,   -1,   -1,   -1,
      -1,   -1,   -1,   -1,   -1,   -1,   -1,   -1,
      -1,   -1,   -1,   -1,   -1,   -1,   -1,   -1,
      -1,   -1,   -1,   -1,   -1,   -1,   -1,   -1,
      -1,   -1,   -1,   -1,   -1,   -1,   -1,   -1,
      -1,   -1,   -1,   -1,   -1,   -1,   -1,   -1,
      -1,   -1,   -1,   -1,   -1,   -1,   -1,   -1,
      -1,   -1,   -1,   -1,   -1,   -1,   -1,   -1,
      -1,   -1,   -1,   -1,   -1,   -1,   -1,   -1,
      -1,   -1,   -1,   -1,   -1,   -1,   -1,   -1,
      -1,   -1,   -1,   -1,   -1,   -1,   -1,   -1,
      -1,   -1,   -1,   -1,   -1,   -1,   -1,   -1,
      -1,   -1,   -1,   -1,   -1,   -1,   -1,   -1,
      -1,   -1,   -1,   -1,   -1,   -1,   -1,   -1,
      -1,   -1,   -1,   -1,   -1,   -1,   -1,   -1,
      -1,   -1,   -1,   -1,   -1,   -1,   -1,   -1,
      -1,   -1,   -1,   -1,   -1,   -1,   -1,   -1,
      -1,   -1,   -1,   -1,   -1,   -1,   -1,   -1,
      -1,   -1,   -1,   -1,   -1,   -1,   -1,   -1,
      -1,   -1,   -1,   -1,   -1,   -1,   -1,   -1,
      -1,   -1,   -1,   -1,   -1,   -1,   -1,   -1,
      -1,   -1,   -1,   -1,   -1,   -1,   -1,   -1,
      -1,   -1,   -1,   -1,   -1,   -1,   -1,   -1,
      -1,   -1,   -1,   -1,   -1,   -1,   -1,   -1,
      -1,   -1,   -1,   -1,   -1,   -1,   -1,   -1,
      -1,   -1,   -1,   -1,   -1,   -1,   -1,   -1,
      -1,   -1,   -1,   -1,   -1,   -1,   -1,   -1,
      -1,   -1,   -1,   -1,   -1,   -1,   -1,   -1,
      -1,   -1,   -1,   -1,   -1,   -1,   -1,   -1,
      -1,   -1,   -1,   -1,   -1,   -1,   -1,   -1,
      -1,   -1,   -1,   -1,   -1,   -1,   -1,   -1,
      -1,   -1,   -1,   -1,   -1,   -1,   -1,   -1,
      -1,   -1,   -1,   -1,   -1,   -1,   -1,   -1,
      -1,   -1,   -1,   -1,   -1,   -1,   -1,   -1,
      -1,   -1,   -1,   -1,   -1,   -1,   -1,   -1,
      -1,   -1,   -1,   -1,   -1,   -1,   -1,   -1,
      -1,   -1,   -1,   -1,   -1,   -1,   -1,   -1,
      -1,   -1,   -1,   -1,   -1,   -1,   -1,   -1,
      -1,   -1,   -1,   -1,   -1,   -1,   -1,   -1,
      -1,   -1,   -1,   -1,   -1,   -1,   -1,   -1,
      -1,   -1,   -1,   -1,   -1,   -1,   -1,   -1,
      -1,   -1,   -1,   -1,   -1,   -1,   -1,   -1,
      -1,   -1,   -1,   -1,   -1,   -1,   -1,   -1,
      -1,   -1,   -1,   -1,   -1,   -1,   -1,   -1,
      -1,   -1,   -1,   -1,   -1,   -1,   -1,   -1,
      -1,   -1,   -1,   -1,   -1,   -1,   -1,   -1,
      -1,   -1,   -1,   -1,   -1,   -1,   -1,   -1,
      -1,   -1,   -1,   -1,   -1,   -1,   -1,   -1,
      -1,   -1,   -1,   -1,   -1,   -1,   -1,   -1,
      -1,   -1,   -1,   -1,   -1,   -1,   -1,   -1,
      -1,   -1,   -1,   -1,   -1,   -1,   -1,   -1,
      -1,   -1,   -1,   -1,   -1,   -1,   -1,   -1,
      -1,   -1,   -1,   -1,   -1,   -1,   -1,   -1,
      -1,   -1,   -1,   -1,   -1,   -1,   -1,   -1,
      -1,   -1,   -1,   -1,   -1,   -1,   -1,   -1,
      -1,   -1,   -1,   -1,   -1,   -1,   -1,   -1,
      -1,   -1,   -1,   -1,   -1,   -1,   -1,   -1,
      -1,   -1,   -1,   -1,   -1,   -1,   -1,   -1,
      -1,   -1,   -1,   -1,   -1,   -1,   -1,   -1,
      -1,   -1,   -1,   -1,   -1,   -1,   -1,   -1,
      -1,   -1,   -1,   -1,   -1,   -1,   -1,   -1,
      -1,   -1,   -1,   -1,   -1,   -1,   -1,   -1,
      -1,   -1,   -1,   -1,   -1,   -1,   -1,   -1,
      -1,   -1,   -1,   -1,   -1,   -1,   -1,   -1,
      -1,   -1,   -1,   -1,   -1,   -1,   -1,   -1,
      -1,   -1,   -1,   -1,   -1,   -1,   -1,   -1,
      -1,   -1,   -1,   -1,   -1,   -1,   -1,   -1,
      -1,   -1,   -1,   -1,   -1,   -1,   -1,   -1,
      -1,   -1,   -1,   -1,   -1,   -1,   -1,   -1,
      -1,   -1,   -1,   -1,   -1,   -1,   -1,   -1,
      -1,   -1,   -1,   -1,   -1,   -1,   -1,   -1,
      -1,   -1,   -1,   -1,   -1,   -1,   -1,   -1,
      -1,   -1,   -1,   -1,   -1,   -1,   -1,   -1,
      -1,   -1,   -1,   -1,   -1,   -1,   -1,   -1,
      -1,   -1,   -1,   -1,   -1,   -1,   -1,   -1,
      -1,   -1,   -1,   -1,   -1,   -1,   -1,   -1,
      -1,   -1,   -1,   -1,   -1,   -1,   -1,   -1,
      -1,   -1,   -1,   -1,   -1,   -1,   -1,   -1,
      -1,   -1,   -1,   -1,   -1,   -1,   -1,   -1,
      -1,   -1,   -1,   -1,   -1,   -1,   -1,   -1,
      -1,   -1,   -1,   -1,   -1,   -1,   -1,   -1,
      -1,   -1,   -1,   -1,   -1,   -1,   -1,   -1,
      -1,   -1,   -1,   -1,   -1,   -1,   -1,   -1,
      -1,   -1,   -1,   -1,   -1,   -1,   -1,   -1,
      -1,   -1,   -1,   -1,   -1,   -1,   -1,   -1,
      -1,   -1,   -1,   -1,   -1,   -1,   -1,   -1,
      -1,   -1,   -1,   -1,   -1,   -1,   -1,   -1,
      -1,   -1,   -1,   -1,   -1,   -1,   -1,   -1,
      -1,   -1,   -1,   -1,   -1,   -1,   -1,   -1,
      -1,   -1,   -1,   -1,   -1,   -1,   -1,   -1,
      -1,   -1,   -1,   -1,   -1,   -1,   -1,   -1,
      -1,   -1,   -1,   -1,   -1,   -1,   -1,   -1,
      -1,   -1,   -1,   -1,   -1,   -1,   -1,   -1,
      -1,   -1,   -1,   -1,   -1,   -1,   -1,   -1,
      -1,   -1,   -1,   -1,   -1,   -1,   -1,   -1,
      -1,   -1,   -1,   -1,   -1,   -1,   -1,   -1,
      -1,   -1,   -1,   -1,   -1,   -1,   -1,   -1,
      -1,   -1,   -1,   -1,   -1,   -1,   -1,   -1,
      -1,   -1,   -1,   -1,   -1,   -1,   -1,   -1,
      -1,   -1,   -1,   -1,   -1,   -1,   -1,   -1,
      -1,   -1,   -1,   -1,   -1,   -1,   -1,   -1,
      -1,   -1,   -1,   -1,   -1,   -1,   -1,   -1,
      -1,   -1,   -1,   -1,   -1,   -1,   -1,   -1,
      -1,   -1,   -1,   -1,   -1,   -1,   -1,   -1,
      -1,   -1,   -1,   -1,   -1,   -1,   -1,   -1,
      -1,   -1,   -1,   -1,   -1,   -1,   -1,   -1,
      -1,   -1,   -1,   -1,   -1,   -1,   -1,   -1,
      -1,   -1,   -1,   -1,   -1,   -1,   -1,   -1,
      -1,   -1,   -1,   -1,   -1,   -1,   -1,   -1,
      -1,   -1,   -1,   -1,   -1,   -1,   -1,   -1,
      -1,   -1,   -1,   -1,   -1,   -1,   -1,   -1,
      -1,   -1,   -1,   -1,   -1,   -1,   -1,   -1,
      -1,   -1,   -1,   -1,   -1,   -1,   -1,   -1,
      -1,   -1,   -1,   -1,   -1,   -1,   -1,   -1,
      -1,   -1,   -1,   -1,   -1,   -1,   -1,   -1,
      -1,   -1,   -1,   -1,   -1,   -1,   -1,   -1,
      -1,   -1,   -1,   -1,   -1,   -1,   -1,   -1,
      -1,   -1,   -1,   -1,   -1,   -1,   -1,   -1,
      -1,   -1,   -1,   -1,   -1,   -1,   -1,   -1,
      -1,   -1,   -1,   -1,   -1,   -1,   -1,   -1,
      -1,   -1,   -1,   -1,   -1,   -1,   -1,   -1,
      -1,   -1,   -1,   -1,   -1,   -1,   -1,   -1,
      -1,   -1,   -1,   -1,   -1,   -1,   -1,   -1,
      -1,   -1,   -1,   -1,   -1,   -1,   -1,   -1,
      -1,   -1,   -1,   -1,   -1,   -1,   -1,   -1,
      -1,   -1,   -1,   -1,   -1,   -1,   -1,   -1,
      -1,   -1,   -1,   -1,   -1,   -1,   -1,   -1,
      -1,   -1,   -1,   -1,   -1,   -1,   -1,   -1,
      -1,   -1,   -1,   -1,   -1,   -1,   -1,   -1,
      -1,   -1,   -1,   -1,   -1,   -1,   -1,   -1,
      -1,   -1,   -1,   -1,   -1,   -1,   -1,   -1,
      -1,   -1,   -1,   -1,   -1,   -1,   -1,   -1,
      -1,   -1,   -1,   -1,   -1,   -1,   -1,   -1,
      -1,   -1,   -1,   -1,   -1,   -1,   -1,   -1,
      -1,   -1,   -1,   -1,   -1,   -1,   -1,   -1,
      -1,   -1,   -1,   -1,   -1,   -1,   -1,   -1,
      -1,   -1,   -1,   -1,   -1,   -1,   -1,   -1,
      -1,   -1,   -1,   -1,   -1,   -1,   -1,   -1,
      -1,   -1,   -1,   -1,   -1,   -1,   -1,   -1,
      -1,   -1,   -1,   -1,   -1,   -1,   -1,   -1,
      -1,   -1,   -1,   -1,   -1,   -1,   -1,   -1,
      -1,   -1,   -1,   -1,   -1,   -1,   -1,   -1,
      -1,   -1,   -1,   -1,   -1,   -1,   -1,   -1,
      -1,   -1,   -1,   -1,   -1,   -1,   -1,   -1,
      -1,   -1,   -1,   -1,   -1,   -1,   -1,   -1,
      -1,   -1,   -1,   -1,   -1,   -1,   -1,   -1,
      -1,   -1,   -1,   -1,   -1,   -1,   -1,   -1,
      -1,   -1,   -1,   -1,   -1,   -1,   -1,   -1,
      -1,   -1,   -1,   -1,   -1,   -1,   -1,   -1,
      -1,   -1,   -1,   -1,   -1,   -1,   -1,   -1,
      -1,   -1,   -1,   -1,   -1,   -1,   -1,   -1,
      -1,   -1,   -1,   -1,   -1,   -1,   -1,   -1,
      -1,   -1,   -1,   -1,   -1,   -1,   -1,   -1,
      -1,   -1,   -1,   -1,   -1,   -1,   -1,   -1,
      -1,   -1,   -1,   -1,   -1,   -1,   -1,   -1,
      -1,   -1,   -1,   -1,   -1,   -1,   -1,   -1,
      -1,   -1,   -1,   -1,   -1,   -1,   -1,   -1,
      -1,   -1,   -1,   -1,   -1,   -1,   -1,   -1,
      -1,   -1,   -1,   -1,   -1,   -1,   -1,   -1,
      -1,   -1,   -1,   -1,   -1,   -1,   -1,   -1,
      -1,   -1,   -1,   -1,   -1,   -1,   -1,   -1,
      -1,   -1,   -1,   -1,   -1,   -1,   -1,   -1,
      -1,   -1,   -1,   -1,   -1,   -1,   -1,   -1,
      -1,   -1,   -1,   -1,   -1,   -1,   -1,   -1,
      -1,   -1,   -1,   -1,   -1,   -1,   -1,   -1,
      -1,   -1,   -1,   -1,   -1,   -1,   -1,   -1,
      -1,   -1,   -1,   -1,   -1,   -1,   -1,   -1,
      -1,   -1,   -1,   -1,   -1,   -1,   -1,   -1,
      -1,   -1,   -1,   -1,   -1,   -1,   -1,   -1,
      -1,   -1,   -1,   -1,   -1,   -1,   -1,   -1,
      -1,   -1,   -1,   -1,   -1,   -1,   -1,   -1,
      -1,   -1,   -1,   -1,   -1,   -1,   -1,   -1,
      -1,   -1,   -1,   -1,   -1,   -1,   -1,   -1,
      -1,   -1,   -1,   -1,   -1,   -1,   -1,   -1,
      -1,   -1,   -1,   -1,   -1,   -1,   -1,   -1,
      -1,   -1,   -1,   -1,   -1,   -1,   -1,   -1,
      -1,   -1,   -1,   -1,   -1,   -1,   -1,   -1,
      -1,   -1,   -1,   -1,   -1,   -1,   -1,   -1,
      -1,   -1,   -1,   -1,   -1,   -1,   -1,   -1,
      -1,   -1,   -1,   -1,   -1,   -1,   -1,   -1,
      -1,   -1,   -1,   -1,   -1,   -1,   -1,   -1,
      -1,   -1,   -1,   -1,   -1,   -1,   -1,   -1,
      -1,   -1,   -1,   -1,   -1,   -1,   -1,   -1,
      -1,   -1,   -1,   -1,   -1,   -1,   -1,   -1,
      -1,   -1,   -1,   -1,   -1,   -1,   -1,   -1,
      -1,   -1,   -1,   -1,   -1,   -1,   -1,   -1,
      -1,   -1,   -1,   -1,   -1,   -1,   -1,   -1,
      -1,   -1,   -1,   -1,   -1,   -1,   -1,   -1,
      -1,   -1,   -1,   -1,   -1,   -1,   -1,   -1,
      -1,   -1,   -1,   -1,   -1,   -1,   -1,   -1,
      -1,   -1,   -1,   -1,   -1,   -1,   -1,   -1,
      -1,   -1,   -1,   -1,   -1,   -1,   -1,   -1,
      -1,   -1,   -1,   -1,   -1,   -1,   -1,   -1,
      -1,   -1,   -1,   -1,   -1,   -1,   -1,   -1,
      -1,   -1,   -1,   -1,   -1,   -1,   -1,   -1,
      -1,   -1,   -1,   -1,   -1,   -1,   -1,   -1,
      -1,   -1,   -1,   -1,   -1,   -1,   -1,   -1,
      -1,   -1,   -1,   -1,   -1,   -1,   -1,   -1,
      -1,   -1,   -1,   -1,   -1,   -1,   -1,   -1,
      -1,   -1,   -1,   -1,   -1,   -1,   -1,   -1,
      -1,   -1,   -1,   -1,   -1,   -1,   -1,   -1,
      -1,   -1,   -1,   -1,   -1,   -1,   -1,   -1,
      -1,   -1,   -1,   -1,   -1,   -1,   -1,   -1,
      -1,   -1,   -1,   -1,   -1,   -1,   -1,   -1,
      -1,   -1,   -1,   -1,   -1,   -1,   -1,   -1,
      -1,   -1,   -1,   -1,   -1,   -1,   -1,   -1,
      -1,   -1,   -1,   -1,   -1,   -1,   -1,   -1,
      -1,   -1,   -1,   -1,   -1,   -1,   -1,   -1,
      -1,   -1,   -1,   -1,   -1,   -1,   -1,   -1,
      -1,   -1,   -1,   -1,   -1,   -1,   -1,   -1,
      -1,   -1,   -1,   -1,   -1,   -1,   -1,   -1,
      -1,   -1,   -1,   -1,   -1,   -1,   -1,   -1,
      -1,   -1,   -1,   -1,   -1,   -1,   -1,   -1,
      -1,   -1,   -1,   -1,   -1,   -1,   -1,   -1,
      -1,   -1,   -1,   -1,   -1,   -1,   -1,   -1,
      -1,   -1,   -1,   -1,   -1,   -1,   -1,   -1,
      -1,   -1,   -1,   -1,   -1,   -1,   -1,   -1,
      -1,   -1,   -1,   -1,   -1,   -1,   -1,   -1,
      -1,   -1,   -1,   -1,   -1,   -1,   -1,   -1,
      -1,   -1,   -1,   -1,   -1,   -1,   -1,   -1,
      -1,   -1,   -1,   -1,   -1,   -1,   -1,   -1,
      -1,   -1,   -1,   -1,   -1,   -1,   -1,   -1,
      -1,   -1,   -1,   -1,   -1,   -1,   -1,   -1,
      -1,   -1,   -1,   -1,   -1,   -1,   -1,   -1,
      -1,   -1,   -1,   -1,   -1,   -1,   -1,   -1,
      -1,   -1,   -1,   -1,   -1,   -1,   -1,   -1,
      -1,   -1,   -1,   -1,   -1,   -1,   -1,   -1,
      -1,   -1,   -1,   -1,   -1,   -1,   -1,   -1,
      -1,   -1,   -1,   -1,   -1,   -1,   -1,   -1,
      -1,   -1,   -1,   -1,   -1,   -1,   -1,   -1,
      -1,   -1,   -1,   -1,   -1,   -1,   -1,   -1,
      -1,   -1,   -1,   -1,   -1,   -1,   -1,   -1,
      -1,   -1,   -1,   -1,   -1,   -1,   -1,   -1,
      -1,   -1,   -1,   -1,   -1,   -1,   -1,   -1,
      -1,   -1,   -1,   -1,   -1,   -1,   -1,   -1,
      -1,   -1,   -1,   -1,   -1,   -1,   -1,   -1,
      -1,   -1,   -1,   -1,   -1,   -1,   -1,   -1,
      -1,   -1,   -1,   -1,   -1,   -1,   -1,   -1,
      -1,   -1,   -1,   -1,   -1,   -1,   -1,   -1,
      -1,   -1,   -1,   -1,   -1,   -1,   -1,   -1,
      -1,   -1,   -1,   -1,   -1,   -1,   -1,   -1,
      -1,   -1,   -1,   -1,   -1,   -1,   -1,   -1,
      -1,   -1,   -1,   -1,   -1,   -1,   -1,   -1,
      -1,   -1,   -1,   -1,   -1,   -1,   -1,   -1,
      -1,   -1,   -1,   -1,   -1,   -1,   -1,   -1,
      -1,   -1,   -1,   -1,   -1,   -1,   -1,   -1,
      -1,   -1,   -1,   -1,   -1,   -1,   -1,   -1,
      -1,   -1,   -1,   -1,   -1,   -1,   -1,   -1,
      -1,   -1,   -1,   -1,   -1,   -1,   -1,   -1,
      -1,   -1,   -1,   -1,   -1,   -1,   -1,   -1,
      -1,   -1,   -1,   -1,   -1,   -1,   -1,   -1,
      -1,   -1,   -1,   -1,   -1,   -1,   -1,   -1,
      -1,   -1,   -1,   -1,   -1,   -1,   -1,   -1,
      -1,   -1,   -1,   -1,   -1,   -1,   -1,   -1,
      -1,   -1,   -1,   -1,   -1,   -1,   -1,   -1,
      -1,   -1,   -1,   -1,   -1,   -1,   -1,   -1,
      -1,   -1,   -1,   -1,   -1,   -1,   -1,   -1,
      -1,   -1,   -1,   -1,   -1,   -1,   -1,   -1,
      -1,   -1,   -1,   -1,   -1,   -1,   -1,   -1,
      -1,   -1,   -1,   -1,   -1,   -1,   -1,   -1,
      -1,   -1,   -1,   -1,   -1,   -1,   -1,   -1,
      -1,   -1,   -1,   -1,   -1,   -1,   -1,   -1,
      -1,   -1,   -1,   -1,   -1,   -1,   -1,   -1,
      -1,   -1,   -1,   -1,   -1,   -1,   -1,   -1,
      -1,   -1,   -1,   -1,   -1,   -1,   -1,   -1,
      -1,   -1,   -1,   -1,   -1,   -1,   -1,   -1,
      -1,   -1,   -1,   -1,   -1,   -1,   -1,   -1,
      -1,   -1,   -1,   -1,   -1,   -1,   -1,   -1,
      -1,   -1,   -1,   -1,   -1,   -1,   -1,   -1,
      -1,   -1,   -1,   -1,   -1,   -1,   -1,   -1,
      -1,   -1,   -1,   -1,   -1,   -1,   -1,   -1,
      -1,   -1,   -1,   -1,   -1,   -1,   -1,   -1,
      -1,   -1,   -1,   -1,   -1,   -1,   -1,   -1,
      -1,   -1,   -1,   -1,   -1,   -1,   -1,   -1,
      -1,   -1,   -1,   -1,   -1,   -1,   -1,   -1,
      -1,   -1,   -1,   -1,   -1,   -1,   -1,   -1,
      -1,   -1,   -1,   -1,   -1,   -1,   -1,   -1,
      -1,   -1,   -1,   -1,   -1,   -1,   -1,   -1,
      -1,   -1,   -1,   -1,   -1,   -1,   -1,   -1,
      -1,   -1,   -1,   -1,   -1,   -1,   -1,   -1,
      -1,   -1,   -1,   -1,   -1,   -1,   -1,   -1,
      -1,   -1,   -1,   -1,   -1,   -1,   -1,   -1,
      -1,   -1,   -1,   -1,   -1,   -1,   -1,   -1,
      -1,   -1,   -1,   -1,   -1,   -1,   -1,   -1,
      -1,   -1,   -1,   -1,   -1,   -1,   -1,   -1,
      -1,   -1,   -1,   -1,   -1,   -1,   -1,   -1,
      -1,   -1,   -1,   -1,   -1,   -1,   -1,   -1,
      -1,   -1,   -1,   -1,   -1,   -1,   -1,   -1,
      -1,   -1,   -1,   -1,   -1,   -1,   -1,   -1,
      -1,   -1,   -1,   -1,   -1,   -1,   -1,   -1,
      -1,   -1,   -1,   -1,   -1,   -1,   -1,   -1,
      -1,   -1,   -1,   -1,   -1,   -1,   -1,   -1,
      -1,   -1,   -1,   -1,   -1,   -1,   -1,   -1,
      -1,   -1,   -1,   -1,   -1,   -1,   -1,   -1,
      -1,   -1,   -1,   -1,   -1,   -1,   -1,   -1,
      -1,   -1,   -1,   -1,   -1,   -1,   -1,   -1,
      -1,   -1,   -1,   -1,   -1,   -1,   -1,   -1,
      -1,   -1,   -1,   -1,   -1,   -1,   -1,   -1,
      -1,   -1,   -1,   -1,   -1,   -1,   -1,   -1,
      -1,   -1,   -1,   -1,   -1,   -1,   -1,   -1,
      -1,   -1,   -1,   -1,   -1,   -1,   -1,   -1,
      -1,   -1,   -1,   -1,   -1,   -1,   -1,   -1,
      -1,   -1,   -1,   -1,   -1,   -1,   -1,   -1,
      -1,   -1,   -1,   -1,   -1,   -1,   -1,   -1,
      -1,   -1,   -1,   -1,   -1,   -1,   -1,   -1,
      -1,   -1,   -1,   -1,   -1,   -1,   -1,   -1,
      -1,   -1,   -1,   -1,   -1,   -1,   -1,   -1,
      -1,   -1,   -1,   -1,   -1,   -1,   -1,   -1,
      -1,   -1,   -1,   -1,   -1,   -1,   -1,   -1,
      -1,   -1,   -1,   -1,   -1,   -1,   -1,   -1,
      -1,   -1,   -1,   -1,   -1,   -1,   -1,   -1,
      -1,   -1,   -1,   -1,   -1,   -1,   -1,   -1,
      -1,   -1,   -1,   -1,   -1,   -1,   -1,   -1,
      -1,   -1,   -1,   -1,   -1,   -1,   -1,   -1,
      -1,   -1,   -1,   -1,   -1,   -1,   -1,   -1,
      -1,   -1,   -1,   -1,   -1,   -1,   -1,   -1,
      -1,   -1,   -1,   -1,   -1,   -1,   -1,   -1,
      -1,   -1,   -1,   -1,   -1,   -1,   -1,   -1,
      -1,   -1,   -1,   -1,   -1,   -1,   -1,   -1,
      -1,   -1,   -1,   -1,   -1,   -1,   -1,   -1,
      -1,   -1,   -1,   -1,   -1,   -1,   -1,   -1,
      -1,   -1,   -1,   -1,   -1,   -1,   -1,   -1,
      -1,   -1,   -1,   -1,   -1,   -1,   -1,   -1,
      -1,   -1,   -1,   -1,   -1,   -1,   -1,   -1,
      -1,   -1,   -1,   -1,   -1,   -1,   -1,   -1,
      -1,   -1,   -1,   -1,   -1,   -1,   -1,   -1,
      -1,   -1,   -1,   -1,   -1,   -1,   -1,   -1,
      -1,   -1,   -1,   -1,   -1,   -1,   -1,   -1,
      -1,   -1,   -1,   -1,   -1,   -1,   -1,   -1,
      -1,   -1,   -1,   -1,   -1,   -1,   -1,   -1,
      -1,   -1,   -1,   -1,   -1,   -1,   -1,   -1,
      -1,   -1,   -1,   -1,   -1,   -1,   -1,   -1,
      -1,   -1,   -1,   -1,   -1,   -1,   -1,   -1,
      -1,   -1,   -1,   -1,   -1,   -1,   -1,   -1,
      -1,   -1,   -1,   -1,   -1,   -1,   -1,   -1,
      -1,   -1,   -1,   -1,   -1,   -1,   -1,   -1,
      -1,   -1,   -1,   -1,   -1,   -1,   -1,   -1,
      -1,   -1,   -1,   -1,   -1,   -1,   -1,   -1,
      -1,   -1,   -1,   -1,   -1,   -1,   -1,   -1,
      -1,   -1,   -1,   -1,   -1,   -1,   -1,   -1,
      -1,   -1,   -1,   -1,   -1,   -1,   -1,   -1,
      -1,   -1,   -1,   -1,   -1,   -1,   -1,   -1,
      -1,   -1,   -1,   -1,   -1,   -1,   -1,   -1,
      -1,   -1,   -1,   -1,   -1,   -1,   -1,   -1,
      -1,   -1,   -1,   -1,   -1,   -1,   -1,   -1,
      -1,   -1,   -1,   -1,   -1,   -1,   -1,   -1,
      -1,   -1,   -1,   -1,   -1,   -1,   -1,   -1,
      -1,   -1,   -1,   -1,   -1,   -1,   -1,   -1,
      -1,   -1,   -1,   -1,   -1,   -1,   -1,   -1,
      -1,   -1,   -1,   -1,   -1,   -1,   -1,   -1,
      -1,   -1,   -1,   -1,   -1,   -1,   -1,   -1,
      -1,   -1,   -1,   -1,   -1,   -1,   -1,   -1,
      -1,   -1,   -1,   -1,   -1,   -1,   -1,   -1,
      -1,   -1,   -1,   -1,   -1,   -1,   -1,   -1,
      -1,   -1,   -1,   -1,   -1,   -1,   -1,   -1,
      -1,   -1,   -1,   -1,   -1,   -1,   -1,   -1,
      -1,   -1,   -1,   -1,   -1,   -1,   -1,   -1,
      -1,   -1,   -1,   -1,   -1,   -1,   -1,   -1,
      -1,   -1,   -1,   -1,   -1,   -1,   -1,   -1,
      -1,   -1,   -1,   -1,   -1,   -1,   -1,   -1,
      -1,   -1,   -1,   -1,   -1,   -1,   -1,   -1,
      -1,   -1,   -1,   -1,   -1,   -1,   -1,   -1,
      -1,   -1,   -1,   -1,   -1,   -1,   -1,   -1,
      -1,   -1,   -1,   -1,   -1,   -1,   -1,   -1,
      -1,   -1,   -1,   -1,   -1,   -1,   -1,   -1,
      -1,   -1,   -1,   -1,   -1,   -1,   -1,   -1,
      -1,   -1,   -1,   -1,   -1,   -1,   -1,   -1,
      -1,   -1,   -1,   -1,   -1,   -1,   -1,   -1,
      -1,   -1,   -1,   -1,   -1,   -1,   -1,   -1,
      -1,   -1,   -1,   -1,   -1,   -1,   -1,   -1,
      -1,   -1,   -1,   -1,   -1,   -1,   -1,   -1,
      -1,   -1,   -1,   -1,   -1,   -1,   -1,   -1,
      -1,   -1,   -1,   -1,   -1,   -1,   -1,   -1,
      -1,   -1,   -1,   -1,   -1,   -1,   -1,   -1,
      -1,   -1,   -1,   -1,   -1,   -1,   -1,   -1,
      -1,   -1,   -1,   -1,   -1,   -1,   -1,   -1,
      -1,   -1,   -1,   -1,   -1,   -1,   -1,   -1,
      -1,   -1,   -1,   -1,   -1,   -1,   -1,   -1,
      -1,   -1,   -1,   -1,   -1,   -1,   -1,   -1,
      -1,   -1,   -1,   -1,   -1,   -1,   -1,   -1,
      -1,   -1,   -1,   -1,   -1,   -1,   -1,   -1,
      -1,   -1,   -1,   -1,   -1,   -1,   -1,   -1,
      -1,   -1,   -1,   -1,   -1,   -1,   -1,   -1,
      -1,   -1,   -1,   -1,   -1,   -1,   -1,   -1,
      -1,   -1,   -1,   -1,   -1,   -1,   -1,   -1,
      -1,   -1,   -1,   -1,   -1,   -1,   -1,   -1,
      -1,   -1,   -1,   -1,   -1,   -1,   -1,   -1,
      -1,   -1,   -1,   -1,   -1,   -1,   -1,   -1,
      -1,   -1,   -1,   -1,   -1,   -1,   -1,   -1,
      -1,   -1,   -1,   -1,   -1,   -1,   -1,   -1,
      -1,   -1,   -1,   -1,   -1,   -1,   -1,   -1,
      -1,   -1,   -1,   -1,   -1,   -1,   -1,   -1,
      -1,   -1,   -1,   -1,   -1,   -1,   -1,   -1,
      -1,   -1,   -1,   -1,   -1,   -1,   -1,   -1,
      -1,   -1,   -1,   -1,   -1,   -1,   -1,   -1,
      -1,   -1,   -1,   -1,   -1,   -1,   -1,   -1,
      -1,   -1,   -1,   -1,   -1,   -1,   -1,   -1,
      -1,   -1,   -1,   -1,   -1,   -1,   -1,   -1,
      -1,   -1,   -1,   -1,   -1,   -1,   -1,   -1,
      -1,   -1,   -1,   -1,   -1,   -1,   -1,   -1,
      -1,   -1,   -1,   -1,   -1,   -1,   -1,   -1,
      -1,   -1,   -1,   -1,   -1,   -1,   -1,   -1,
      -1,   -1,   -1,   -1,   -1,   -1,   -1,   -1,
      -1,   -1,   -1,   -1,   -1,   -1,   -1,   -1,
      -1,   -1,   -1,   -1,   -1,   -1,   -1,   -1,
      -1,   -1,   -1,   -1,   -1,   -1,   -1,   -1,
      -1,   -1,   -1,   -1,   -1,   -1,   -1,   -1,
      -1,   -1,   -1,   -1,   -1,   -1,   -1,   -1,
      -1,   -1,   -1,   -1,   -1,   -1,   -1,   -1,
      -1,   -1,   -1,   -1,   -1,   -1,   -1,   -1,
      -1,   -1,   -1,   -1,   -1,   -1,   -1,   -1,
      -1,   -1,   -1,   -1,   -1,   -1,   -1,   -1,
      -1,   -1,   -1,   -1,   -1,   -1,   -1,   -1,
      -1,   -1,   -1,   -1,   -1,   -1,   -1,   -1,
      -1,   -1,   -1,   -1,   -1,   -1,   -1,   -1,
      -1,   -1,   -1,   -1,   -1,   -1,   -1,   -1,
      -1,   -1,   -1,   -1,   -1,   -1,   -1,   -1,
      -1,   -1,   -1,   -1,   -1,   -1,   -1,   -1,
      -1,   -1,   -1,   -1,   -1,   -1,   -1,   -1,
      -1,   -1,   -1,   -1,   -1,   -1,   -1,   -1,
      -1,   -1,   -1,   -1,   -1,   -1,   -1,   -1,
      -1,   -1,   -1,   -1,   -1,   -1,   -1,   -1,
      -1,   -1,   -1,   -1,   -1,   -1,   -1,   -1,
      -1,   -1,   -1,   -1,   -1,   -1,   -1,   -1,
      -1,   -1,   -1,   -1,   -1,   -1,   -1,   -1,
      -1,   -1,   -1,   -1,   -1,   -1,   -1,   -1,
      -1,   -1,   -1,   -1,   -1,   -1,   -1,   -1,
      -1,   -1,   -1,   -1,   -1,   -1,   -1,   -1,
      -1,   -1,   -1,   -1,   -1,   -1,   -1,   -1,
      -1,   -1,   -1,   -1,   -1,   -1,   -1,   -1,
      -1,   -1,   -1,   -1,   -1,   -1,   -1,   -1,
      -1,   -1,   -1,   -1,   -1,   -1,   -1,   -1,
      -1,   -1,   -1,   -1,   -1,   -1,   -1,   -1,
      -1,   -1,   -1,   -1,   -1,   -1,   -1,   -1,
      -1,   -1,   -1,   -1,   -1,   -1,   -1,   -1,
      -1,   -1,   -1,   -1,   -1,   -1,   -1,   -1,
      -1,   -1,   -1,   -1,   -1,   -1,   -1,   -1,
      -1,   -1,   -1,   -1,   -1,   -1,   -1,   -1,
      -1,   -1,   -1,   -1,   -1,   -1,   -1,   -1,
      -1,   -1,   -1,   -1,   -1,   -1,   -1,   -1,
      -1,   -1,   -1,   -1,   -1,   -1,   -1,   -1,
      -1,   -1,   -1,   -1,   -1,   -1,   -1,   -1,
      -1,   -1,   -1,   -1,   -1,   -1,   -1,   -1,
      -1,   -1,   -1,   -1,   -1,   -1,   -1,   -1,
      -1,   -1,   -1,   -1,   -1,   -1,   -1,   -1,
      -1,   -1,   -1,   -1,   -1,   -1,   -1,   -1,
      -1,   -1,   -1,   -1,   -1,   -1,   -1,   -1,
      -1,   -1,   -1,   -1,   -1,   -1,   -1,   -1,
      -1,   -1,   -1,   -1,   -1,   -1,   -1,   -1,
      -1,   -1,   -1,   -1,   -1,   -1,   -1,   -1,
      -1,   -1,   -1,   -1,   -1,   -1,   -1,   -1,
      -1,   -1,   -1,   -1,   -1,   -1,   -1,   -1,
      -1,   -1,   -1,   -1,   -1,   -1,   -1,   -1,
      -1,   -1,   -1,   -1,   -1,   -1,   -1,   -1,
      -1,   -1,   -1,   -1,   -1,   -1,   -1,   -1,
      -1,   -1,   -1,   -1,   -1,   -1,   -1,   -1,
      -1,   -1,   -1,   -1,   -1,   -1,   -1,   -1,
      -1,   -1,   -1,   -1,   -1,   -1,   -1,   -1,
      -1,   -1,   -1,   -1,   -1,   -1,   -1,   -1,
      -1,   -1,   -1,   -1,   -1,   -1,   -1,   -1,
      -1,   -1,   -1,   -1,   -1,   -1,   -1,   -1,
      -1,   -1,   -1,   -1,   -1,   -1,   -1,   -1,
      -1,   -1,   -1,   -1,   -1,   -1,   -1,   -1,
      -1,   -1,   -1,   -1,   -1,   -1,   -1,   -1,
      -1,   -1,   -1,   -1,   -1,   -1,   -1,   -1,
      -1,   -1,   -1,   -1,   -1,   -1,   -1,   -1,
      -1,   -1,   -1,   -1,   -1,   -1,   -1,   -1,
      -1,   -1,   -1,   -1,   -1,   -1,   -1,   -1,
      -1,   -1,   -1,   -1,   -1,   -1,   -1,   -1,
      -1,   -1,   -1,   -1,   -1,   -1,   -1,   -1,
      -1,   -1,   -1,   -1,   -1,   -1,   -1,   -1,
      -1,   -1,   -1,   -1,   -1,   -1,   -1,   -1,
      -1,   -1,   -1,   -1,   -1,   -1,   -1,   -1,
      -1,   -1,   -1,   -1,   -1,   -1,   -1,   -1,
      -1,   -1,   -1,   -1,   -1,   -1,   -1,   -1,
      -1,   -1,   -1,   -1,   -1,   -1,   -1,   -1,
      -1,   -1,   -1,   -1,   -1,   -1,   -1,   -1,
      -1,   -1,   -1,   -1,   -1,   -1,   -1,   -1,
      -1,   -1,   -1,   -1,   -1,   -1,   -1,   -1,
      -1,   -1,   -1,   -1,   -1,   -1,   -1,   -1,
      -1,   -1,   -1,   -1,   -1,   -1,   -1,   -1,
      -1,   -1,   -1,   -1,   -1,   -1,   -1,   -1,
      -1,   -1,   -1,   -1,   -1,   -1,   -1,   -1,
      -1,   -1,   -1,   -1,   -1,   -1,   -1,   -1,
      -1,   -1,   -1,   -1,   -1,   -1,   -1,   -1,
      -1,   -1,   -1,   -1,   -1,   -1,   -1,   -1,
      -1,   -1,   -1,   -1,   -1,   -1,   -1,   -1,
      -1,   -1,   -1,   -1,   -1,   -1,   -1,   -1,
      -1,   -1,   -1,   -1,   -1,   -1,   -1,   -1,
      -1,   -1,   -1,   -1,   -1,   -1,   -1,   -1,
      -1,   -1,   -1,   -1,   -1,   -1,   -1,   -1,
      -1,   -1,   -1,   -1,   -1,   -1,   -1,   -1,
      -1,   -1,   -1,   -1,   -1,   -1,   -1,   -1,
      -1,   -1,   -1,   -1,   -1,   -1,   -1,   -1,
      -1,   -1,   -1,   -1,   -1,   -1,   -1,   -1,
      -1,   -1,   -1,   -1,   -1,   -1,   -1,   -1,
      -1,   -1,   -1,   -1,   -1,   -1,   -1,   -1,
      -1,   -1,   -1,   -1,   -1,   -1,   -1,   -1,
      -1,   -1,   -1,   -1,   -1,   -1,   -1,   -1,
      -1,   -1,   -1,   -1,   -1,   -1,   -1,   -1,
      -1,   -1,   -1,   -1,   -1,   -1,   -1,   -1,
      -1,   -1,   -1,   -1,   -1,   -1,   -1,   -1,
      -1,   -1,   -1,   -1,   -1,   -1,   -1,   -1,
      -1,   -1,   -1,   -1,   -1,   -1,   -1,   -1,
      -1,   -1,   -1,   -1,   -1,   -1,   -1,   -1,
      -1,   -1,   -1,   -1,   -1,   -1,   -1,   -1,
      -1,   -1,   -1,   -1,   -1,   -1,   -1,   -1,
      -1,   -1,   -1,   -1,   -1,   -1,   -1,   -1,
      -1,   -1,   -1,   -1,   -1,   -1,   -1,   -1,
      -1,   -1,   -1,   -1,   -1,   -1,   -1,   -1,
      -1,   -1,   -1,   -1,   -1,   -1,   -1,   -1,
      -1,   -1,   -1,   -1,   -1,   -1,   -1,   -1,
      -1,   -1,   -1,   -1,   -1,   -1,   -1,   -1,
      -1,   -1,   -1,   -1,   -1,   -1,   -1,   -1,
      -1,   -1,   -1,   -1,   -1,   -1,   -1,   -1,
      -1,   -1,   -1,   -1,   -1,   -1,   -1,   -1,
      -1,   -1,   -1,   -1,   -1,   -1,   -1,   -1,
      -1,   -1,   -1,   -1,   -1,   -1,   -1,   -1,
      -1,   -1,   -1,   -1,   -1,   -1,   -1,   -1,
      -1,   -1,   -1,   -1,   -1,   -1,   -1,   -1,
      -1,   -1,   -1,   -1,   -1,   -1,   -1,   -1,
      -1,   -1,   -1,   -1,   -1,   -1,   -1,   -1,
      -1,   -1,   -1,   -1,   -1,   -1,   -1,   -1,
      -1,   -1,   -1,   -1,   -1,   -1,   -1,   -1,
      -1,   -1,   -1,   -1,   -1,   -1,   -1,   -1,
      -1,   -1,   -1,   -1,   -1,   -1,   -1,   -1,
      -1,   -1,   -1,   -1,   -1,   -1,   -1,   -1,
      -1,   -1,   -1,   -1,   -1,   -1,   -1,   -1,
      -1,   -1,   -1,   -1,   -1,   -1,   -1,   -1,
      -1,   -1,   -1,   -1,   -1,   -1,   -1,   -1,
      -1,   -1,   -1,   -1,   -1,   -1,   -1,   -1,
      -1,   -1,   -1,   -1,   -1,   -1,   -1,   -1,
      -1,   -1,   -1,   -1,   -1,   -1,   -1,   -1,
      -1,   -1,   -1,   -1,   -1,   -1,   -1,   -1,
      -1,   -1,   -1,   -1,   -1,   -1,   -1,   -1,
      -1,   -1,   -1,   -1,   -1,   -1,   -1,   -1,
      -1,   -1,   -1,   -1,   -1,   -1,   -1,   -1,
      -1,   -1,   -1,   -1,   -1,   -1,   -1,   -1,
      -1,   -1,   -1,   -1,   -1,   -1,   -1,   -1,
      -1,   -1,   -1,   -1,   -1,   -1,   -1,   -1,
      -1,   -1,   -1,   -1,   -1,   -1,   -1,   -1,
      -1,   -1,   -1,   -1,   -1,   -1,   -1,   -1,
      -1,   -1,   -1,   -1,   -1,   -1,   -1,   -1,
      -1,   -1,   -1,   -1,   -1,   -1,   -1,   -1,
      -1,   -1,   -1,   -1,   -1,   -1,   -1,   -1,
      -1,   -1,   -1,   -1,   -1,   -1,   -1,   -1,
      -1,   -1,   -1,   -1,   -1,   -1,   -1,   -1,
      -1,   -1,   -1,   -1,   -1,   -1,   -1,   -1,
      -1,   -1,   -1,   -1,   -1,   -1,   -1,   -1,
      -1,   -1,   -1,   -1,   -1,   -1,   -1,   -1,
      -1,   -1,   -1,   -1,   -1,   -1,   -1,   -1,
      -1,   -1,   -1,   -1,   -1,   -1,   -1,   -1,
      -1,   -1,   -1,   -1,   -1,   -1,   -1,   -1,
      -1,   -1,   -1,   -1,   -1,   -1,   -1,   -1,
      -1,   -1,   -1,   -1,   -1,   -1,   -1,   -1,
      -1,   -1,   -1,   -1,   -1,   -1,   -1,   -1,
      -1,   -1,   -1,   -1,   -1,   -1,   -1,   -1,
      -1,   -1,   -1,   -1,   -1,   -1,   -1,   -1,
      -1,   -1,   -1,   -1,   -1,   -1,   -1,   -1,
      -1,   -1,   -1,   -1,   -1,   -1,   -1,   -1,
      -1,   -1,   -1,   -1,   -1,   -1,   -1,   -1,
      -1,   -1,   -1,   -1,   -1,   -1,   -1,   -1,
      -1,   -1,   -1,   -1,   -1,   -1,   -1,   -1,
      -1,   -1,   -1,   -1,   -1,   -1,   -1,   -1,
      -1,   -1,   -1,   -1,   -1,   -1,   -1,   -1,
      -1,   -1,   -1,   -1,   -1,   -1,   -1,   -1,
      -1,   -1,   -1,   -1,   -1,   -1,   -1,   -1,
      -1,   -1,   -1,   -1,   -1,   -1,   -1,   -1,
      -1,   -1,   -1,   -1,   -1,   -1,   -1,   -1,
      -1,   -1,   -1,   -1,   -1,   -1,   -1,   -1,
      -1,   -1,   -1,   -1,   -1,   -1,   -1,   -1,
      -1,   -1,   -1,   -1,   -1,   -1,   -1,   -1,
      -1,   -1,   -1,   -1,   -1,   -1,   -1,   -1,
      -1,   -1,   -1,   -1,   -1,   -1,   -1,   -1,
      -1,   -1,   -1,   -1,   -1,   -1,   -1,   -1,
      -1,   -1,   -1,   -1,   -1,   -1,   -1,   -1,
      -1,   -1,   -1,   -1,   -1,   -1,   -1,   -1,
      -1,   -1,   -1,   -1,   -1,   -1,   -1,   -1,
      -1,   -1,   -1,   -1,   -1,   -1,   -1,   -1,
      -1,   -1,   -1,   -1,   -1,   -1,   -1,   -1,
      -1,   -1,   -1,   -1,   -1,   -1,   -1,   -1,
      -1,   -1,   -1,   -1,   -1,   -1,   -1,   -1,
      -1,   -1,   -1,   -1,   -1,   -1,   -1,   -1,
      -1,   -1,   -1,   -1,   -1,   -1,   -1,   -1,
      -1,   -1,   -1,   -1,   -1,   -1,   -1,   -1,
      -1,   -1,   -1,   -1,   -1,   -1,   -1,   -1,
      -1,   -1,   -1,   -1,   -1,   -1,   -1,   -1,
      -1,   -1,   -1,   -1,   -1,   -1,   -1,   -1,
      -1,   -1,   -1,   -1,   -1,   -1,   -1,   -1,
      -1,   -1,   -1,   -1,   -1,   -1,   -1,   -1,
      -1,   -1,   -1,   -1,   -1,   -1,   -1,   -1,
      -1,   -1,   -1,   -1,   -1,   -1,   -1,   -1,
      -1,   -1,   -1,   -1,   -1,   -1,   -1,   -1,
      -1,   -1,   -1,   -1,   -1,   -1,   -1,   -1,
      -1,   -1,   -1,   -1,   -1,   -1,   -1,   -1,
      -1,   -1,   -1,   -1,   -1,   -1,   -1,   -1,
      -1,   -1,   -1,   -1,   -1,   -1,   -1,   -1,
      -1,   -1,   -1,   -1,   -1,   -1,   -1,   -1,
      -1,   -1,   -1,   -1,   -1,   -1,   -1,   -1,
      -1,   -1,   -1,   -1,   -1,   -1,   -1,   -1,
      -1,   -1,   -1,   -1,   -1,   -1,   -1,   -1,
      -1,   -1,   -1,   -1,   -1,   -1,   -1,   -1,
      -1,   -1,   -1,   -1,   -1,   -1,   -1,   -1,
      -1,   -1,   -1,   -1,   -1,   -1,   -1,   -1,
      -1,   -1,   -1,   -1,   -1,   -1,   -1,   -1,
      -1,   -1,   -1,   -1,   -1,   -1,   -1,   -1,
      -1,   -1,   -1,   -1,   -1,   -1,   -1,   -1,
      -1,   -1,   -1,   -1,   -1,   -1,   -1,   -1,
      -1,   -1,   -1,   -1,   -1,   -1,   -1,   -1,
      -1,   -1,   -1,   -1,   -1,   -1,   -1,   -1,
      -1,   -1,   -1,   -1,   -1,   -1,   -1,   -1,
      -1,   -1,   -1,   -1,   -1,   -1,   -1,   -1,
      -1,   -1,   -1,   -1,   -1,   -1,   -1,   -1,
      -1,   -1,   -1,   -1,   -1,   -1,   -1,   -1,
      -1,   -1,   -1,   -1,   -1,   -1,   -1,   -1,
      -1,   -1,   -1,   -1,   -1,   -1,   -1,   -1,
      -1,   -1,   -1,   -1,   -1,   -1,   -1,   -1,
      -1,   -1,   -1,   -1,   -1,   -1,   -1,   -1,
      -1,   -1,   -1,   -1,   -1,   -1,   -1,   -1,
      -1,   -1,   -1,   -1,   -1,   -1,   -1,   -1,
      -1,   -1,   -1,   -1,   -1,   -1,   -1,   -1,
      -1,   -1,   -1,   -1,   -1,   -1,   -1,   -1,
      -1,   -1,   -1,   -1,   -1,   -1,   -1,   -1,
      -1,   -1,   -1,   -1,   -1,   -1,   -1,   -1,
      -1,   -1,   -1,   -1,   -1,   -1,   -1,   -1,
      -1,   -1,   -1,   -1,   -1,   -1,   -1,   -1,
      -1,   -1,   -1,   -1,   -1,   -1,   -1,   -1,
      -1,   -1,   -1,   -1,   -1,   -1,   -1,   -1,
      -1,   -1,   -1, 4280
  };

#ifdef __GNUC__
__inline
#ifdef __GNUC_STDC_INLINE__
__attribute__ ((__gnu_inline__))
#endif
#endif
const struct glyphlist *
glyph_name_to_uni (register const char *str, register unsigned int len)
{
  if (len <= MAX_WORD_LENGTH && len >= MIN_WORD_LENGTH)
    {
      register int key = glyph_name_hash (str, len);

      if (key <= MAX_HASH_VALUE && key >= 0)
        {
          register int index = lookup[key];

          if (index >= 0)
            {
              register const char *s = wordlist[index].name;

              if (*str == *s && !strcmp (str + 1, s + 1))
                return &wordlist[index];
            }
        }
    }
  return 0;
}
