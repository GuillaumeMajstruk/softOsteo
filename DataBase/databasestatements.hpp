#ifndef DATABASESTATEMENTS_HPP
#define DATABASESTATEMENTS_HPP


typedef const char * Msg;

namespace Statement
{
    namespace connectionDatabase
    {
        static Msg createTableStatement = "CREATE TABLE IF NOT EXISTS users (Username TEXT PRIMARY KEY, Password TEXT )";
        static Msg insertStatement = "INSERT INTO users (Username, Password) VALUES  ( '%1','%2')";
    }

    namespace patientDatabase
    {
        static Msg getPatientIndex_byName = "SELECT patientID FROM general_infos WHERE patientName = '%1'";
    }
}

#endif // DATABASESTATEMENTS_HPP
