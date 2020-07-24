#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include<assert.h>
#define MAX_CHARACTERS 1005
#define MAX_PARAGRAPHS 5

//Learning C is fun. Learning pointers is more fun.It is good to have pointers.

char* kth_word_in_mth_sentence_of_nth_paragraph(char**** document, int k, int m, int n) {
	return document[n-1][m-1][k-1];
}

char** kth_sentence_in_mth_paragraph(char**** document, int k, int m) { 
	return document[m-1][k-1];
}

char*** kth_paragraph(char**** document, int k) {
	return document[k-1];
}

char**** get_document(char* text) {
	typedef struct index
	{
		int start_index;
		int end_index;
	}index;

	int raw_text_length=strlen(text);
	int para_count=1,sentence_count=1,word_count=1;
	index para_indexes[5];
/*
	printf("text length: %d\n",raw_text_length);
	*/
	para_indexes[para_count-1].start_index=0;

	/* Calculating no.of paras */
	for(int i=0;i<=raw_text_length;i++)
	{
		if(text[i]=='\n')
		{
			para_indexes[para_count-1].end_index=i-1;

			/*
			printf("para_index[%d] : %d-%d ; %c-%c\n",
					para_count-1,para_indexes[para_count-1].start_index,para_indexes[para_count-1].end_index,
					text[para_indexes[para_count-1].start_index],text[para_indexes[para_count-1].end_index]);
			*/
			para_count++;
			para_indexes[para_count-1].start_index=i+1;
		}			
	}
	para_indexes[para_count-1].end_index=raw_text_length-1;
	/*printf("para_index[%d] : %d-%d ; %c-%c\n",
			para_count-1,para_indexes[para_count-1].start_index,para_indexes[para_count-1].end_index,
			text[para_indexes[para_count-1].start_index],text[para_indexes[para_count-1].end_index]);
			*/
	para_indexes[para_count].start_index=raw_text_length+1;
	para_indexes[para_count].end_index=raw_text_length+1;
	
	/*printf("para_index[%d] : %d-%d ; %c-%c\n",
			para_count,para_indexes[para_count].start_index,para_indexes[para_count].end_index,
			text[para_indexes[para_count].start_index],text[para_indexes[para_count].end_index]);
	printf("----no of paras: %d----\n\n",para_count);*/

	char ****doc=NULL;
	doc=(char****)calloc(para_count,sizeof(char***));

	/* Calculating no.of sentences per para */
	index **sentence_index=(index**)calloc(para_count,sizeof(index*));
	int *sentence_count_of_para=(int*)calloc(para_count,sizeof(int));

	for(int i=0;i<para_count;i++)
	{
		sentence_index[i]=(index*)realloc(sentence_index[i],sentence_count*sizeof(index));
		sentence_index[i][sentence_count-1].start_index=para_indexes[i].start_index;
		
		for(int j=para_indexes[i].start_index;j<para_indexes[i].end_index;j++)
		{
			if(text[j]=='.')
			{
				sentence_index[i][sentence_count-1].end_index=j-1;
				/*
				printf("sentence_index[%d][%d] : %d-%d ; %c-%c\n",
						i,sentence_count-1,sentence_index[i][sentence_count-1].start_index,sentence_index[i][sentence_count-1].end_index,
						text[sentence_index[i][sentence_count-1].start_index],text[sentence_index[i][sentence_count-1].end_index]);
				*/
				sentence_count++;
				sentence_index[i]=(index*)realloc(sentence_index[i],sentence_count*sizeof(index));
				sentence_index[i][sentence_count-1].start_index=j+1;
		
			}
		}
		sentence_index[i][sentence_count-1].end_index=para_indexes[i].end_index-1;
		/*
		printf("sentence_index[%d][%d] : %d-%d ; %c-%c\n",
				i,sentence_count-1,sentence_index[i][sentence_count-1].start_index,sentence_index[i][sentence_count-1].end_index,
				text[sentence_index[i][sentence_count-1].start_index],text[sentence_index[i][sentence_count-1].end_index]);
		*/
		doc[i]=(char***)calloc(sentence_count,sizeof(char**));
		sentence_count_of_para[i]=sentence_count;
		/*printf("----no of sentences of %d para : %d ----\n",i,sentence_count);*/
		sentence_count=1;
	}
	printf("\n");

	/* Calculating no.of words in each sentence */
	index ***word_index=(index***)calloc(para_count,sizeof(index**));
	int **word_count_of_sentence=(int**)calloc(para_count,sizeof(int*));
	for(int i=0;i<para_count;i++)
	{
		word_index[i]=(index**)calloc(sentence_count_of_para[i],sizeof(index**));
		word_count_of_sentence[i]=(int*)calloc(sentence_count_of_para[i],sizeof(int));
		for(int j=0;j<sentence_count_of_para[i];j++)
		{
			word_index[i][j]=(index*)realloc(word_index[i][j],word_count*sizeof(index));
			word_index[i][j][word_count-1].start_index=sentence_index[i][j].start_index;
			for(int k=sentence_index[i][j].start_index;k<=sentence_index[i][j].end_index;k++)
			{
				if(text[k]==' ')
				{
					word_index[i][j][word_count-1].end_index=k-1;
					/*
					printf("word_index[%d][%d][%d] : %d-%d ; %c-%c\n",
							i,j,word_count-1,word_index[i][j][word_count-1].start_index,word_index[i][j][word_count-1].end_index,
							text[word_index[i][j][word_count-1].start_index],text[word_index[i][j][word_count-1].end_index]);
					*/
					word_count++;
					word_index[i][j]=(index*)realloc(word_index[i][j],word_count*sizeof(index));
					word_index[i][j][word_count-1].start_index=k+1;
				}
			}
			word_index[i][j][word_count-1].end_index=sentence_index[i][j].end_index;
			/*
			printf("word_index[%d][%d][%d] : %d-%d ; %c-%c\n",
					i,j,word_count-1,word_index[i][j][word_count-1].start_index,word_index[i][j][word_count-1].end_index,
					text[word_index[i][j][word_count-1].start_index],text[word_index[i][j][word_count-1].end_index]);
			*/
			word_count_of_sentence[i][j]=word_count;
			doc[i][j]=(char**)calloc(word_count,sizeof(char*));
			word_count=1;
		}
		printf("\n");
	}

	/* Creating memory for words */
	for(int i=0;i<para_count;i++)
	{
		for(int j=0;j<sentence_count_of_para[i];j++)
		{
			for(int k=0;k<word_count_of_sentence[i][j];k++)
			{
				/* Create memory per word in each sentence */
				int cur_word_index=word_index[i][j][k].start_index;
				int next_word_index=word_index[i][j][k].end_index+1;
				int word_size=next_word_index-cur_word_index;
				doc[i][j][k]=(char*)calloc(word_size+1,sizeof(char));

				/* Copy that word into memory of that word */
				int l=0;
				for(l=0;l<word_size;l++)
				{
					doc[i][j][k][l]=text[cur_word_index++];
				}

				doc[i][j][k][l]='\0';					
				/*printf("%s\n",doc[i][j][k]);*/
			}
		}
	}

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
	printf("__DOC Creating DONE__\n");
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
