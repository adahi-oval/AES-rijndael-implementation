#include "converters.cc"



stringmatrix AddRoundKey(stringmatrix mat1, stringmatrix mat2){
  stringmatrix result;
  stringvector aux;

  for (int i = 0; i < mat1.size(); i++){
    for (int j = 0; j < mat1.at(0).size(); j++){
      byte op1(HexToDecimal(mat1[i][j]));
      byte op2(HexToDecimal(mat2[i][j]));

      op1^=op2;

      aux.push_back(ByteToHex(op1));
    }
    result.push_back(aux);
    aux.clear();
  }

  return result;
}



int main(void){
  std::string clave = "328831e0435a3137f6309807a88da234";
  std::string mensaje = "2b28ab097eaef7cf15d2154f16a6883e";
  stringmatrix matrix = StringToHexMatrix(clave);
  stringmatrix mensajematrix = StringToHexMatrix(mensaje);
  stringmatrix result = AddRoundKey(matrix, mensajematrix);

  PrintHexMatrix(result);
}