#include "converterjson.h"
#include <exception>


ConverterJSON::ConverterJSON()
{
}

std::vector<std::string> ConverterJSON::GetTextDocuments()
{

    std::ifstream file("../config.json");

    if(file.is_open())
    {
        if (file.peek() == std::ifstream::traits_type::eof())
            throw std::runtime_error("config file is empty");
        else
            config = json::parse(file);
        file.close();
    }
    else throw std::runtime_error("config file is missing");

    std::vector<std::string> listOfFiles{};

    if(!config.empty())
    {
        for (const auto& el : config["files"])
        {
            listOfFiles.push_back(el);
        }
    }

    return listOfFiles;
}

int ConverterJSON::GetResponsesLimit()
{
    std::ifstream file("../config.json");

    if(file.is_open())
    {
        if (file.peek() == std::ifstream::traits_type::eof())
            throw std::runtime_error("config file is empty");
        else
            config = json::parse(file);
        file.close();
    }
    else throw std::runtime_error("config file is missing");

    int max_responses = 0;

    if(!config.empty())
    {
        max_responses = config["config"]["max_responses"];
    }

    return max_responses;

}

std::vector<std::string> ConverterJSON::GetRequests()
{
    std::ifstream file("../requests.json");

    json requestsJson;

    if(file.is_open())
    {
        if (file.peek() == std::ifstream::traits_type::eof())
            throw std::runtime_error("requests file is empty");
        else
            requestsJson = json::parse(file);
        file.close();
    }
    else throw std::runtime_error("requests file is missing");

    std::vector<std::string> requests{};

    if(!requestsJson.empty())
    {
        for (const auto& el : requestsJson["requests"])
        {
            requests.push_back(el);
        }
    }

    return requests;
}
