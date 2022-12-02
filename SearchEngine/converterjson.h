/**
*  Класс для работы с JSON-файлами
*/
#pragma once

#include <string>
#include <vector>
#include <fstream>
#include <nlohmann/json.hpp>

using json = nlohmann::json;



class ConverterJSON
{
private:
    json config;
public:
    ConverterJSON();
/**
* Метод получения содержимого файлов
* @return Возвращает список с содержимым файлов перечисленных
*       в config.json
*/
    std::vector<std::string> GetTextDocuments();
/**
* Метод считывает поле max_responses для определения предельного
*  количества ответов на один запрос
* @return
*/
    int GetResponsesLimit();
/**
* Метод получения запросов из файла requests.json
* @return возвращает список запросов из файла requests.json
*/
    std::vector<std::string> GetRequests();
/**
* Положить в файл answers.json результаты поисковых запросов
*/
    void putAnswers(std::vector<std::vector<std::pair<int, float>>> answers);

};
