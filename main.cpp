#include <iostream>
#include "./include/ConverterJSON.h"
#include "./include/InvertedIndex.h"
#include "./include/SearchServer.h"

using namespace std;

int main(int argc, char **argv) {

    ConverterJSON data;
    InvertedIndex index;
    index.UpdateDocumentBase(data.GetTextDocuments());

    SearchServer search(index);
    data.PutAnswers(search.Search(data.GetRequests(), data.GetResponsesLimit()));
}