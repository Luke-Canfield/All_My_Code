from helper import remove_punc
from nltk.stem import PorterStemmer
import nltk
import numpy as np
import nltk.tokenize 
from nltk.corpus import stopwords
nltk.download('stopwords')
nltk.download('punkt')
#Clean and stem the contents of a document
#Takes in a file name to read in and clean
#Return a list of words, without stopwords and punctuation, and with all words stemmed
# NOTE: Do not append any directory names to doc -- assume we will give you
# a string representing a file name that will open correctly
def read_and_clean_doc(doc) :
    #1. Open document, read text into *single* string
    with open(doc,'r') as myfile:
        file = myfile.read()
        docs = file.splitlines()
    #2. Tokenize string using nltk.tokenize.word_tokenize
        doc_tokens = [nltk.word_tokenize(x) for x in docs]
    #3. Filter out punctuation from list of words (use remove_punc)
        doc_tokens = remove_punc(docs)
    #4. Make the words lower case
        for i in range(len(doc_tokens)):
            doc_tokens[i] = doc_tokens[i].lower()
    #5. Filter out stopwords
        stop = set(stopwords('english'))
        doc_tokens_c = [x for x in doc_tokens if x not in stop]
    #6. Stem words
        st = PorterStemmer()
        for w in doc_tokens_c:
            words = st.stem(w)

    return words
    
#Builds a doc-word matrix for a set of documents
#Takes in a *list of filenames*
#
#Returns 1) a doc-word matrix for the cleaned documents
#This should be a 2-dimensional numpy array, with one row per document and one 
#column per word (there should be as many columns as unique words that appear
#across *all* documents. Also, Before constructing the doc-word matrix, 
#you should sort the wordlist output and construct the doc-word matrix based on the sorted list
#
#Also returns 2) a list of words that should correspond to the columns in
#docword
def build_doc_word_matrix(doclist) :
    #1. Create word lists for each cleaned doc (use read_and_clean_doc)
    clean_doc_list = []
    for doc in len(doclist):
        clean_doc_list.append(read_and_clean_doc(doc))

    #2. Use these word lists to build the doc word matrix
    wordlist = []
    docword = []
    for doc in clean_doc_list:
        for x in doc:
            if(not(x in wordlist)):
                wordlist.append[x]
    for doc in clean_doc_list:
        doc_vec = [0]*len(wordlist)
        for x in doc:
            ix = wordlist.index(x)
            doc_vec[ix] += 1
        docword.append(doc_vec)

    return docword, wordlist
    
#Builds a term-frequency matrix
#Takes in a doc word matrix (as built in build_doc_word_matrix)
#Returns a term-frequency matrix, which should be a 2-dimensional numpy array
#with the same shape as docword
def build_tf_matrix(docword) :
    #fill in
    tf = []
    rows = len(docword)
    columns = len(docword[0])
    s_list = [0] * rows
    for x in range(rows):
        for y in range(columns):
            s_list[x] += y
    for x in range(rows):
        for y in range(columns):
            docword[x][y] = (docword[x]) / (s_list(y))
    tf = docword

    return tf
    
#Builds an inverse document frequency matrix
#Takes in a doc word matrix (as built in build_doc_word_matrix)
#Returns an inverse document frequency matrix (should be a 1xW numpy array where
#W is the number of words in the doc word matrix)
#Don't forget the log factor!
def build_idf_matrix(docword) :
    #fill in
    idf = []
    N = len(docword)
    columns = len(docword[0])
    for x in N:
        for y in columns:
            docword[x][y] = np.log10(N / docword[x][y])

    return idf
    
#Builds a tf-idf matrix given a doc word matrix
def build_tfidf_matrix(docword) :
    #fill in
    tfidf = []
    tfidf = (build_idf_matrix(docword) @ build_tf_matrix(docword))
    return tfidf
    
#Find the three most distinctive words, according to TFIDF, in each document
#Input: a docword matrix, a wordlist (corresponding to columns) and a doclist 
# (corresponding to rows)
#Output: a dictionary, mapping each document name from doclist to an (ordered
# list of the three most common words in each document
def find_distinctive_words(docword, wordlist, doclist) :
    distinctive_words = {}
    #fill in
    #you might find numpy.argsort helpful for solving this problem:
    #https://docs.scipy.org/doc/numpy/reference/generated/numpy.argsort.html
    
    return distinctive_words

if __name__ == '__main__':
    from os import listdir
    from os.path import isfile, join, splitext
    
    ### Test Cases ###
    directory='lecs'
    path1 = join(directory, '1_vidText.txt')
    path2 = join(directory, '2_vidText.txt')
    
    # Uncomment and recomment ths part where you see fit for testing purposes
    
    '''print("*** Testing read_and_clean_doc ***")
    print(read_and_clean_doc(path1)[0:5])
    print("*** Testing build_doc_word_matrix ***") 
    doclist =[path1, path2]
    docword, wordlist = build_doc_word_matrix(doclist)
    print(docword.shape)
    print(len(wordlist))
    print(docword[0][0:10])
    print(wordlist[0:10])
    print(docword[1][0:10])
    print("*** Testing build_tf_matrix ***") 
    tf = build_tf_matrix(docword)
    print(tf[0][0:10])
    print(tf[1][0:10])
    print(tf.sum(axis =1))
    print("*** Testing build_idf_matrix ***") 
    idf = build_idf_matrix(docword)
    print(idf[0][0:10])
    print("*** Testing build_tfidf_matrix ***") 
    tfidf = build_tfidf_matrix(docword)
    print(tfidf.shape)
    print(tfidf[0][0:10])
    print(tfidf[1][0:10])
    print("*** Testing find_distinctive_words ***")
    print(find_distinctive_words(docword, wordlist, doclist))
    '''
