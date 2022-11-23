#include <stdio.h>

// Criar uma função que criptografa uma letra minúscula, adicionando a letra e a chave;

char cryptLowerChar(char char2Cypher, int cypherKey)
{
    // c = (letra + chave) % 26
    // ASCII 97 - 122 -> Letras minúsculas
    int cypherChar = (char2Cypher + cypherKey);
    if (cypherChar > 'z')
    {
        cypherChar = cypherChar - 26;
    }
    return cypherChar;
}
char decryptLowerChar(char char2Decypher, int decypherKey)
{
    // c = (letra + chave) % 26
    // ASCII 97 - 122 -> Letras minúsculas
    int decypherChar = (char2Decypher - decypherKey);
    if (decypherChar < 'a')
    {
        decypherChar = decypherChar + 26;
    }
    return decypherChar;
}

char cryptUpperChar(char char2Cypher, int cypherKey)
{
    // c = (letra + chave) % 26
    // ASCII 65 to 90 -> Letras maiúsculas
    int cypherChar = (char2Cypher + cypherKey);
    if (cypherChar > 'Z')
    {
        cypherChar = cypherChar - 26;
    }
    return cypherChar;
}

char decryptUpperChar(char char2Decypher, int decypherKey)
{
    // c = (letra + chave) % 26
    // ASCII 65 to 90 -> Letras maiúsculas
    int decypherChar = (char2Decypher - decypherKey);
    if (decypherChar < 'A')
    {
        decypherChar = decypherChar + 26;
    }
    return decypherChar;
}

char cryptChar(char char2Cypher, int cypherKey)
{
    char cypherChar;
    if (char2Cypher >= 97 && char2Cypher <= 122)
    {
        cypherChar = cryptLowerChar(char2Cypher, cypherKey);
    }
    else if (char2Cypher >= 65 && char2Cypher <= 90)
    {
        cypherChar = cryptUpperChar(char2Cypher, cypherKey);
    }
    return cypherChar;
}

char decryptChar(char char2Decypher, int decypherKey)
{
    char decypherChar;
    if (char2Decypher >= 97 && char2Decypher <= 122)
    {
        decypherChar = decryptLowerChar(char2Decypher, decypherKey);
    }
    else if (char2Decypher >= 65 && char2Decypher <= 90)
    {
        decypherChar = decryptUpperChar(char2Decypher, decypherKey);
    }
    return decypherChar;
}

char *cryptText(char *text2Cypher, int cypherKey)
{
    for (char* quotePtr = text2Cypher; *quotePtr != '\0'; quotePtr++)
    {
        *quotePtr = cryptChar(*quotePtr, cypherKey);
    }
}

int main(int argc, char const *argv[])
{
    printf("%s, %s", "fabios", cryptText("fabios", 7));
    return 0;
}
