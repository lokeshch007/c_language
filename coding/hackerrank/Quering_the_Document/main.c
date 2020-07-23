#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include<assert.h>
#define MAX_CHARACTERS 1005
#define MAX_PARAGRAPHS 5

char* kth_word_in_mth_sentence_of_nth_paragraph(char**** document, int k, int m, int n) {

}

char** kth_sentence_in_mth_paragraph(char**** document, int k, int m) { 

}

char*** kth_paragraph(char**** document, int k) {

}

char**** get_document(char* text) {
	int raw_text_length=strlen(text);
	int para_count=1,sentence_count=1,word_count=1;
	int para_indexes[5]={0};
	/* Calculating no.of paras */
	for(int i=0;i<raw_text_length;i++)
	{
		if(text[i]=='\n')
		{
			para_indexes[para_count]=i+1;
			para_count++;
		}
	}

	char ****doc=NULL;
	doc=(char****)calloc(para_count,sizeof(char***));

	/* Calculating no.of sentences per para */
	int **sentence_index=(int**)calloc(para_count,sizeof(int*));
	int *sentence_count_of_para=(int*)calloc(para_count,sizeof(int));

	for(int i=0;i<para_count;i++)
	{
		sentence_index[i]=(int*)realloc(sentence_index[i],sentence_count*sizeof(int));
		sentence_index[i][sentence_count-1]=para_indexes[i];
		for(int j=para_indexes[i];j<para_indexes[i+1]-1;j++)
		{
			if(text[j]=='.')
			{
				if(text[j+1]!='\n')
				{
					sentence_count++;
					sentence_index[i]=(int*)realloc(sentence_index[i],sentence_count*sizeof(int));
					sentence_index[i][sentence_count-1]=j+1;
				}
			}
		}
		doc[i]=(char***)calloc(sentence_count,sizeof(char**));
		sentence_count_of_para[i]=sentence_count;
		sentence_count=1;
	}

	/* Calculating no.of words in each sentence */
	int ***word_index=(int***)calloc(para_count,sizeof(int**));
	int **word_count_of_sentence=(int**)calloc(para_count,sizeof(int*));
	for(int i=0;i<para_count;i++)
	{
		word_index[i]=(int**)calloc(sentence_count_of_para[i],sizeof(int**));
		word_count_of_sentence[i]=(int*)calloc(sentence_count_of_para[i],sizeof(int));
		for(int j=0;j<sentence_count_of_para[i];j++)
		{
			word_index[i][j]=(int*)realloc(word_index[i][j],word_count*sizeof(int));
			word_index[i][j][word_count-1]=sentence_index[i][j];
			for(int k=sentence_index[i][j];k<sentence_index[i][j+1]-1;k++)
			{
				if(text[k]==' ')
				{
					if(text[k+1]!='.')
					{
						word_count++;
						word_index[i][j]=(int*)realloc(word_index[i][j],word_count*sizeof(int));
						word_index[i][j][word_count-1]=k+1;
					}
				}
			}
			word_count_of_sentence[i][j]=word_count;
			doc[i][j]=(char**)calloc(word_count,sizeof(char*));
			word_count=1;
		}
	}

	/* create strlen(words) mem sizes for all words in doc[i]->sentence[i][j]=? */

	return doc;
}


char* get_input_text() {	
	int paragraph_count;
	scanf("%d", &paragraph_count);

	char p[MAX_PARAGRAPHS][MAX_CHARACTERS], doc[MAX_CHARACTERS];
	memset(doc, 0, sizeof(doc));
	getchar();
	for (int i = 0; i < paragraph_count; i++) {
		scanf("%[^\n]%*c", p[i]);
		strcat(doc, p[i]);
		if (i != paragraph_count - 1)
			strcat(doc, "\n");
	}

	char* returnDoc = (char*)malloc((strlen (doc)+1) * (sizeof(char)));
	strcpy(returnDoc, doc);
	return returnDoc;
}

void print_word(char* word) {
	printf("%s", word);
}

void print_sentence(char** sentence) {
	int word_count;
	scanf("%d", &word_count);
	for(int i = 0; i < word_count; i++){
		printf("%s", sentence[i]);
		if( i != word_count - 1)
			printf(" ");
	}
} 

void print_paragraph(char*** paragraph) {
	int sentence_count;
	scanf("%d", &sentence_count);
	for (int i = 0; i < sentence_count; i++) {
		print_sentence(*(paragraph + i));
		printf(".");
	}
}

int main() 
{
	char* text = get_input_text();
	char**** document = get_document(text);

	int q;
	scanf("%d", &q);

	while (q--) {
		int type;
		scanf("%d", &type);

		if (type == 3){
			int k, m, n;
			scanf("%d %d %d", &k, &m, &n);
			char* word = kth_word_in_mth_sentence_of_nth_paragraph(document, k, m, n);
			print_word(word);
		}

		else if (type == 2){
			int k, m;
			scanf("%d %d", &k, &m);
			char** sentence = kth_sentence_in_mth_paragraph(document, k, m);
			print_sentence(sentence);
		}

		else{
			int k;
			scanf("%d", &k);
			char*** paragraph = kth_paragraph(document, k);
			print_paragraph(paragraph);
		}
		printf("\n");
	}     
}
