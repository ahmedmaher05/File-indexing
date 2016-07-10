objective :the tool analysis a text file and returns information about it's content , it can be considered as a simple search engine 

illustration :  this code uses an in-order linked list to build a file indexing and search engine service.
 The program will be passed a text file name and a file containing commands.
the code is expected to 
 * read the input file word-by-word
 * each word is then inserted into the in-order list, along with the line number in which it exists in the file. First line in the file is line #1. 
Note: words are considered to be case insensitive 

                

examples : 

 * wordCount
   input: a4.exe FileName CommandsFile
   wordCount exists in the CommandsFile
   output: 1010 words

 * distWords
   input: a4.exe FileName CommandsFile
   distWords exists in the CommandsFile
   output: 10 distinct words  

 * charCount
   input: a4.exe FileName CommandsFile
   charCount exists in the CommandsFile
   output: 50121 characters

 * frequentWord
   input: a4.exe FileName CommandsFile
   frequentWord exists in the CommandsFile
   output: Most frequent word is: book good

 * countWord
   input: a4.exe FileName CommandsFile
   countWord Nile exists in the CommandsFile
   output: Nile is repeated 50 times

 * starting
   input: a4.exe leName CommandsFile
   starting Te exists in the CommandsFile
   output: Temporary 10 Tease 5 

 * containing
   input: a4.exe leName CommandsFile
   containing al exists in the CommandsFile
   output: al 5 shall 2



 * search
   input: a4.exe leName CommandsFile
   search ne exists in the CommandsFile
   output: (separate word and line occurrences by tabs)
   neighbor: lines 5 62 123
   network: lines 12 17 278
   next: lines 110 114 119 1234

NOTES:
* The following is a sample CommandFile
  wordCount
  distWords
  charCount
  containing mega
  countWord Biology
  ending migo ==> should produce "Undened command" error
  search class

* error handling is done using the following error messages  
  File not found
  Undened command
  Incorrect number of arguments









 