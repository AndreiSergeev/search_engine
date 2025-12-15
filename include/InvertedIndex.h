#pragma once

#include <map>

struct Entry
{
    size_t doc_id, count;
    // Данный оператор необходим для проведения тестовыхсценариев
    bool operator ==(const Entry& other) const
    {
        return (doc_id == other.doc_id && count == other.count);
    }
};

class InvertedIndex
{
public:
    InvertedIndex() = default;
    /**
    * Обновить или заполнить базу документов, по которой будем совершать поиск
    * @paramtexts_input содержимоедокументов
    */
    void UpdateDocumentBase(std::vector<std::string> input_docs);
    /** Метод определяет количество вхождений слова word в загруженной базе документов
    * @paramword слово,частоту вхождений которого необходимо определить
    * @return возвращает подготовленный список с частотой слов
    */
    std::vector<Entry> GetWordCount(const std::string& word);

private:
    /**std::vector<std::string> docs — коллекция для хранения текстов документов,
    в которой номер элемента в векторе определяет doc_id для формирования
    результата запроса;*/
    std::vector<std::string> docs;
    /**std::map<std::string, std:vector<Entry>> freq_dictionary или частотный словарь —
    это коллекция для хранения частоты слов, встречаемых в тексте. Entry
    представляет собой структуру:*/
    std::map<std::string, std::vector<Entry>> freq_dictionary;
};