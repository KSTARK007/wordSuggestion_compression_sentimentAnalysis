#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <ctype.h>

struct list
    {
    struct list * next;
    char string[30];
    };

char *strlwr(char *str)
    {
      unsigned char *p = (unsigned char *)str;

      while (*p)
      {
         *p = tolower((unsigned char)*p);
          p++;
      }

      return str;
    }

    char *readFile(char *fileName)
    {
        FILE *file = fopen(fileName, "r");
        char *code;
        size_t n = 0;
        int c;

        if (file == NULL)
            return NULL; //could not open file

        code = malloc(100000);

        while ((c = fgetc(file)) != EOF)
        {
           if(c != '.' && c != ',')
           {
            code[n++] = (char) c;
           }
        }

        // don't forget to terminate with the null character
        code[n] = '\0';
      //  fclose(fileName);
        return code;
    }


int main(void)
{


    FILE *fp,*fp1,*fp2,*fp3;
    char file[] = "check.txt";
    char file1[] = "check2.txt";
    struct list *head=NULL, **pp= &head;
    int ch;
    size_t len ;
    char buff[30];
    int i = 0;
    int weight = 0;
    char temp[100];
    char temp2[100];

  //  fp1 = fopen(file,"r");
    fp2 = fopen(file1,"w");
//  printf("%s",readFile(file));
  //  ba = readFile(file);
  fwrite(readFile(file),1000,10000000,fp2);




    char * hap[100];
    hap[0] = "amazing";
    hap[1] = "happy";
    hap[2] = "ambitious";
    hap[3] = "great";
    hap[4] = "glorious";
    hap[5] = "amazed";
    hap[6] = "lit";
    hap[7] = "cheerful";
    hap[8] = "jovial";
    hap[9] = "joyful";
    hap[10] = "radiant";
    hap[11] = "accomplish";
    hap[12] = "accomplishement";
    hap[13] = "adorable";
    hap[14] = "adore";
    hap[15] = "adored";
    hap[16] = "adventurous";
    hap[17] = "alluring";
    hap[18] = "amazement";
    hap[19] = "superb";
    hap[20] = "sexy";
    hap[21] = "amicable";
    hap[22] = "appealing";
    hap[23] ="swank";
    hap[24] = "applaud";
    hap[25] = "appreciate";
    hap[26] = "appreciated";
    hap[27] = "ardent";
    hap[28] = "aspire";
    hap[29] = "astonished";
    hap[30] = "astound";
    hap[31] = "astounded";
    hap[32] = "attractive";
    hap[33] = "award";
    hap[34] = "awarded";
    hap[35] = "beautiful";
    hap[36] = "beautifully";
    hap[37] = "beneficient";
    hap[38] = "beneficially";
    hap[39] = "benelovence";
    hap[40] = "benefits";
    hap[41] = "blissful";
    hap[42] = "blissfully";
    hap[43] = "blessing";
    hap[44] = "blossom";
    hap[45] = "bonus";
    hap[46] = "booming";
    hap[47] = "boundless";
    hap[48] = "bounty";
    hap[49] = "bountiful";
    hap[50] = "bravo";
    hap[51] = "brighten";
    hap[52] = "brightest";
    hap[53] = "brilliant";
    hap[54] = "charming";
    hap[55] = "charm";
    hap[56] = "classic";
    hap[57] = "complement";
    hap[58] = "complimentary";
    hap[59] = "confidence";
    hap[60] = "creative";
    hap[61] = "wow";
    hap[62] = "wonderful";
    hap[63] = "wise";
    hap[64] = "winner";
    hap[65] = "whoa";
    hap[66] = "well-educated";
    hap[67] = "wealthy";
    hap[68] = "warmhearted";
    hap[69] = "vivacious";
    hap[70] = "victorius";
    hap[71] = "vibrant";
    hap[72] = "damn";
    hap[73] = "unselfish";
    hap[74] = "unparalled";
    hap[75] = "positive";
    hap[76] = "unbiased";
    hap[77] = "trouble-free";
    hap[78] = "triumph";
    hap[79] = "triumphant";
    hap[80] = "treasure";
    hap[80] = "generous";
    hap[81] = "generosity";
    hap[82] = "glad";
    hap[83] = "gladness";
    hap[84] = "gleeful";
    hap[85] = "glorify";
    hap[86] = "good";
    hap[87] = "gorgeous";
    hap[88] = "grandeur";
    hap[89] = "heartwarming";
    hap[90] = "impeccable";
    hap[91] = "incredible";
    hap[92] = "inspirational";
    hap[93] = "jubilant";
    hap[94] = "joyous";
    hap[95] = "joy";
    // hap[96] = "marvellous";
    // hap[97] = "matchless";
    // hap[98] ="pleasant";
    // hap[99] ="satisying";
    // hap[100] = "superbly";
    //


    char * ano[100];
    ano[0] = "sad";
    ano[1] = "bad";
    ano[2] = "distressed";
    ano[3] = "lost";
    ano[4] = "sorrow";
    ano[5] = "pain";
    ano[6] = "unhappy";
    ano[7] = "unfortunate";
    ano[8] = "adamant";
    ano[9] = "alarmed";
    ano[10] = "allegation";
    ano[11] = "agonizing";
    ano[12] ="agony";
    ano[13] ="angrily";
    ano[14] ="annihilation";
    ano[15] ="annoyance";
    ano[16] ="annoyingly";
    ano[17] ="antagonize";
    ano[18] ="antagonism";
    ano[19] ="apprehension";
    ano[20] ="arrogance";
  //  ano[20] ="avenge";
    ano[21] ="unbearable";
    ano[22] ="boring";
    ano[23] ="bothered";
    ano[24] ="bored";
    ano[25] ="bothering";
    ano[26] ="bother";
    ano[27] ="boisterous";
    ano[28] ="break-up";
    ano[29] ="breakdown";
    ano[30] ="bruse";
    ano[31] ="brutal";
    ano[32] ="brutalize";
    ano[33] ="brutality";
    ano[34] ="bullshit";
    ano[35] ="bullying";
    ano[36] ="bully";
    ano[37] ="burden";
    ano[38] ="burdensome";
    ano[39] ="bust";
    ano[40] ="cancer";
    ano[41] ="cannibalize";
    ano[42] ="cheat";
    ano[43] ="cheated";
    ano[44] ="cheater";
    ano[45] ="cheerless";
    ano[46] ="choke";
    ano[47] ="chronic";
    ano[48] ="negativeness";
    ano[49] ="negative";
    ano[50] ="worry";
//    ano[41] ="worried";
//    ano[42] ="worrisome";
//    ano[43] ="worthless";
//    ano[44] ="weakness";
//    ano[45] ="unwatchable";
//    ano[46] ="unwilling";
//    ano[47] ="uneasy";
//    ano[48] ="unthinkable";
//    ano[49] ="unwelcome";
//    ano[50] ="unjustifiable";
    ano[51] ="unimaginable";
    ano[52] ="unfair";
    ano[53] = "unequal";
    ano[54] ="undesirable";
    ano[55] ="traumatized";
    ano[56] ="treason";
    ano[57] ="trap";
    ano[58] ="trapped";
    ano[59] ="threat";
    ano[60] ="thoughtless";
    ano[61] ="terrible";
    ano[62] ="terribly";
    ano[63] ="tedious";
    ano[64] ="suffer";
    ano[65] ="suffering";
    ano[66] ="suffered";
    ano[67] ="suck";
    ano[68] ="sucks";
    ano[69] ="stupid";
    ano[70] ="stupidity";
    ano[71] ="stuck";
    ano[72] ="struggle";
    ano[73] ="struggling";
    ano[74] ="stereotypical";
    ano[75] ="stampede";
    ano[76] ="sorrowfully";
    ano[77] ="sloppy";
    ano[78] ="skeptical";
    ano[79] ="shameless";
    ano[80] ="shameful";
    ano[81] ="selfish";
    ano[82] ="screwed";
    ano[83] ="sacrifice";
    ano[84] ="ruin";
    ano[85] ="ruined";
    ano[86] ="risk";
    ano[87] ="revenge";
    ano[88] ="remorse";
    ano[89] ="remorsefully";
    ano[90] ="punishable";
    ano[91] ="precarious";
    ano[92] ="prejudice";
    ano[93] ="perverts";
    ano[94] ="tragic";
    ano[95] ="undetermined";
    ano[96] ="underpowered";
    // ano[97] ="hazard";
    // ano[98] ="flaw";
    // ano[99] ="fearsome";
    // ano[100] ="fear";











    fp = fopen(file1, "r");

    // if (!fp)
    // {
    //   //  fprintf(stderr, "\nError opening file!");
    //   //  exit(EXIT_FAILURE);
    // }

  //  printf("\n File has been opened for reading.\n");

    for (len=0; len < sizeof buff;)
    {
        ch = fgetc(fp);
        if (ch == EOF && !len) break;
        if (ch == ' ' || ch ==  '\n' || ch == EOF)

           {
            if (!len) continue;
            buff[len] = '\0';
            *pp = malloc(sizeof **pp);
            if (!*pp) break;
            strcpy((*pp)->string, buff);
            (*pp)->next = NULL;
            pp = &(*pp)->next ;
            len=0; continue;
            }

        buff[len++] = ch;
    }

    if (len)
        {
    //      fprintf(stderr, "\nWord was too large, or out of memory\n");
        }


   struct list * q =head;

   for( ;head;head= head->next)
     {

     for(i = 0;i < 95;i++)
        {

          if(strcmp(strlwr(q->string),"not") == 0 && strcmp(strlwr(head->string),hap[i]) == 0)
          {
            weight = weight - 2;
          }
          else if(strcmp(strlwr(q->string),"very") == 0 && strcmp(strlwr(head->string),hap[i]) == 0)
          {
            weight = weight + 3;
          }
          else if(strcmp(strlwr(head->string),hap[i]) == 0)
          {
            weight = weight + 1;
          }
    //    / / / / // / / / / / / / / // / / // / / / / // / / / // / / / / / / / / / / /  / // / / // / / //  / / / / /

          if(strcmp(strlwr(q->string),"not") == 0 && strcmp(strlwr(head->string),ano[i]) == 0)
          {
              weight = weight + 2;
          }
          if(strcmp(strlwr(q->string),"very") == 0 && strcmp(strlwr(head->string),ano[i]) == 0)
          {
              weight = weight - 3;
          }
          else if(strcmp(strlwr(head->string),ano[i]) == 0)
          {
              weight = weight - 1;
          }

        }
        q = head;

    //  printf(" %s ",head->string);
     }
    // printf("\n %d ",weight);
     //
     //
     // fp3 = fopen("final.txt","w");
     if(weight > 7)
     {
       printf("%s ","HAPPY");
     }
     else if(weight > 3 && weight <= 7)
     {
       printf("%s ","NORMAL" );
     }
     else
     {
       printf("%s","SAD");
     }



    if (fclose(fp) ==  EOF)
    {
        fprintf(stderr, "\nError closing file!\n");
        exit(EXIT_FAILURE);
    }
    fclose(fp);
    fclose(check)
}
