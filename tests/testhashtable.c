#include <stdio.h>
#include "pdfname.h"
#include "pdfmem.h"

static char* sequentials1[] =
{
    "GS0","GS1","GS2","GS3","GS4","GS5","GS6","GS7","GS8","GS9","GS10","GS11","GS12","GS13","GS14","GS15","GS16","GS17","GS18","GS19","GS20","GS21","GS22","GS23","GS24","GS25","GS26","GS27","GS28","GS29","GS30","GS31","GS32","GS33","GS34","GS35","GS36","GS37","GS38","GS39","GS40","GS41","GS42","GS43","GS44","GS45","GS46","GS47","GS48","GS49","GS50","GS51","GS52","GS53","GS54","GS55","GS56","GS57","GS58","GS59","GS60","GS61","GS62","GS63","GS64","GS65","GS66","GS67","GS68","GS69","GS70","GS71","GS72","GS73","GS74","GS75","GS76","GS77","GS78","GS79","GS80","GS81","GS82","GS83","GS84","GS85","GS86","GS87","GS88","GS89","GS90","GS91","GS92","GS93","GS94","GS95","GS96","GS97","GS98","GS99","GS100","GS101","GS102","GS103","GS104","GS105","GS106","GS107","GS108","GS109","GS110","GS111","GS112","GS113","GS114","GS115","GS116","GS117","GS118","GS119","GS120","GS121","GS122","GS123","GS124","GS125","GS126","GS127","GS128","GS129","GS130","GS131","GS132","GS133","GS134","GS135","GS136","GS137","GS138","GS139","GS140","GS141","GS142","GS143","GS144","GS145","GS146","GS147","GS148","GS149","GS150","GS151","GS152","GS153","GS154","GS155","GS156","GS157","GS158","GS159","GS160","GS161","GS162","GS163","GS164","GS165","GS166","GS167","GS168","GS169","GS170","GS171","GS172","GS173","GS174","GS175","GS176","GS177","GS178","GS179","GS180","GS181","GS182","GS183","GS184","GS185","GS186","GS187","GS188","GS189","GS190","GS191","GS192","GS193","GS194","GS195","GS196","GS197","GS198","GS199","GS200","GS201","GS202","GS203","GS204","GS205","GS206","GS207","GS208","GS209","GS210","GS211","GS212","GS213","GS214","GS215","GS216","GS217","GS218","GS219","GS220","GS221","GS222","GS223","GS224","GS225","GS226","GS227","GS228","GS229","GS230","GS231","GS232","GS233","GS234","GS235","GS236","GS237","GS238","GS239","GS240","GS241","GS242","GS243","GS244","GS245","GS246","GS247","GS248","GS249","GS250","GS251","GS252","GS253","GS254","GS255","GS256","GS257","GS258","GS259","GS260","GS261","GS262","GS263","GS264","GS265","GS266","GS267","GS268","GS269","GS270","GS271","GS272","GS273","GS274","GS275","GS276","GS277","GS278","GS279","GS280","GS281","GS282","GS283","GS284","GS285","GS286","GS287","GS288","GS289","GS290","GS291","GS292","GS293","GS294","GS295","GS296","GS297","GS298","GS299","GS300","GS301","GS302","GS303","GS304","GS305","GS306","GS307","GS308","GS309","GS310","GS311","GS312","GS313","GS314","GS315","GS316","GS317","GS318","GS319","GS320","GS321","GS322","GS323","GS324","GS325","GS326","GS327","GS328","GS329","GS330","GS331","GS332","GS333","GS334","GS335","GS336","GS337","GS338","GS339","GS340","GS341","GS342","GS343","GS344","GS345","GS346","GS347","GS348","GS349","GS350","GS351","GS352","GS353","GS354","GS355","GS356","GS357","GS358","GS359","GS360","GS361","GS362","GS363","GS364","GS365","GS366","GS367","GS368","GS369","GS370","GS371","GS372","GS373","GS374","GS375","GS376","GS377","GS378","GS379","GS380","GS381","GS382","GS383","GS384","GS385","GS386","GS387","GS388","GS389","GS390","GS391","GS392","GS393","GS394","GS395","GS396","GS397","GS398","GS399","GS400","GS401","GS402","GS403","GS404","GS405","GS406","GS407","GS408","GS409","GS410","GS411","GS412","GS413","GS414","GS415","GS416","GS417","GS418","GS419","GS420","GS421","GS422","GS423","GS424","GS425","GS426","GS427","GS428","GS429","GS430","GS431","GS432","GS433","GS434","GS435","GS436","GS437","GS438","GS439","GS440","GS441","GS442","GS443","GS444","GS445","GS446","GS447","GS448","GS449","GS450","GS451","GS452","GS453","GS454","GS455","GS456","GS457","GS458","GS459","GS460","GS461","GS462","GS463","GS464","GS465","GS466","GS467","GS468","GS469","GS470","GS471","GS472","GS473","GS474","GS475","GS476","GS477","GS478","GS479","GS480","GS481","GS482","GS483","GS484","GS485","GS486","GS487","GS488","GS489","GS490","GS491","GS492","GS493","GS494","GS495","GS496","GS497","GS498","GS499","GS500","GS501","GS502","GS503","GS504","GS505","GS506","GS507","GS508","GS509","GS510","GS511","GS512"
};

const static char *sequentials2[] =
{
    "IMG0","IMG1","IMG2","IMG3","IMG4","IMG5","IMG6","IMG7","IMG8","IMG9","IMG10","IMG11","IMG12","IMG13","IMG14","IMG15","IMG16","IMG17","IMG18","IMG19","IMG20","IMG21","IMG22","IMG23","IMG24","IMG25","IMG26","IMG27","IMG28","IMG29","IMG30","IMG31","IMG32","IMG33","IMG34","IMG35","IMG36","IMG37","IMG38","IMG39","IMG40","IMG41","IMG42","IMG43","IMG44","IMG45","IMG46","IMG47","IMG48","IMG49","IMG50","IMG51","IMG52","IMG53","IMG54","IMG55","IMG56","IMG57","IMG58","IMG59","IMG60","IMG61","IMG62","IMG63","IMG64","IMG65","IMG66","IMG67","IMG68","IMG69","IMG70","IMG71","IMG72","IMG73","IMG74","IMG75","IMG76","IMG77","IMG78","IMG79","IMG80","IMG81","IMG82","IMG83","IMG84","IMG85","IMG86","IMG87","IMG88","IMG89","IMG90","IMG91","IMG92","IMG93","IMG94","IMG95","IMG96","IMG97","IMG98","IMG99","IMG100","IMG101","IMG102","IMG103","IMG104","IMG105","IMG106","IMG107","IMG108","IMG109","IMG110","IMG111","IMG112","IMG113","IMG114","IMG115","IMG116","IMG117","IMG118","IMG119","IMG120","IMG121","IMG122","IMG123","IMG124","IMG125","IMG126","IMG127","IMG128","IMG129","IMG130","IMG131","IMG132","IMG133","IMG134","IMG135","IMG136","IMG137","IMG138","IMG139","IMG140","IMG141","IMG142","IMG143","IMG144","IMG145","IMG146","IMG147","IMG148","IMG149","IMG150","IMG151","IMG152","IMG153","IMG154","IMG155","IMG156","IMG157","IMG158","IMG159","IMG160","IMG161","IMG162","IMG163","IMG164","IMG165","IMG166","IMG167","IMG168","IMG169","IMG170","IMG171","IMG172","IMG173","IMG174","IMG175","IMG176","IMG177","IMG178","IMG179","IMG180","IMG181","IMG182","IMG183","IMG184","IMG185","IMG186","IMG187","IMG188","IMG189","IMG190","IMG191","IMG192","IMG193","IMG194","IMG195","IMG196","IMG197","IMG198","IMG199","IMG200","IMG201","IMG202","IMG203","IMG204","IMG205","IMG206","IMG207","IMG208","IMG209","IMG210","IMG211","IMG212","IMG213","IMG214","IMG215","IMG216","IMG217","IMG218","IMG219","IMG220","IMG221","IMG222","IMG223","IMG224","IMG225","IMG226","IMG227","IMG228","IMG229","IMG230","IMG231","IMG232","IMG233","IMG234","IMG235","IMG236","IMG237","IMG238","IMG239","IMG240","IMG241","IMG242","IMG243","IMG244","IMG245","IMG246","IMG247","IMG248","IMG249","IMG250","IMG251","IMG252","IMG253","IMG254","IMG255","IMG256"
};

int main(int argc, char **argv)
{
    hashtable *ht = hashtable_new();
    hashtable_entry e;
    int i;
    char *filename = NULL;

    e.next = 0;

    if (argc > 1)
        filename = argv[1];

    if (filename)
    {
        int bufsize = 1024;
        char buf[1024];
        FILE *fd = fopen(filename, "r");
        if (!fd)
            return 0;

        while (fgets(buf, bufsize, fd))
        {
            e.str = buf;
            hashtable_search(ht, &e);
        }
        hashtable_stat(ht);
        fclose(fd);
        return 0;
    }

    printf("Inserting the first 512 entries...\n");
    for (i = 0; i < 512; i++)
    {
        e.str = (unsigned char*)sequentials1[i];
        hashtable_search(ht, &e);
    }

    hashtable_stat(ht);

    printf("Inserting the 256 more entries...\n");
    for (i = 0; i < 256; i++)
    {
        e.str = (unsigned char*)sequentials2[i];
        hashtable_search(ht, &e);
    }

    hashtable_stat(ht);

    printf("Deleting the first 512 entries...\n");
    for (i = 0; i < 512; i++)
    {
        hashtable_entry *ent;
        e.str = (unsigned char*)sequentials1[i];
        ent = hashtable_delete_entry(ht, &e);
        if (ent)
            pdf_free(ent);
    }

    hashtable_stat(ht);


    hashtable_free(ht);

    return 0;
}