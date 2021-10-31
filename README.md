# ArithmeticCoding
- I just upload my Arithmetic coding algorithm
- Arithmetic coding 알고리즘 입니다.

1. main.cpp의 main 함수 내 vector<char> symbols 에 중복되는 symbol 없이 symbol들을 작성해주세요
1. Just write symbols on vector<char> symbols without overlap

2. vector<float> p에 vector<char> symbols와 같은 순서로 각 심볼들의 확률을 작성해주세요
2. On vector<float> p write each symbol's probability sequentially

3. word에는 전송할 string으로서 symbol의 조합으로 반드시 이루어진 string을 작성해주세요
3. In string word please write string which is composited with vector<char> symobls 's components, this string is for sending

4. 현재 예외처리 같은게 없기 때문에 반드시 생성자 -> CalcRange -> ArithmeticAlgorithm -> GenCodeWords -> PrintCode 순서로 실행 시켜주세요
4. Now I haven't write exception part so, toy should run squentially like Class Generator -> CalcRange -> ArithmeticAlgorithm -> GenCodeWords -> PrintCode

5. 끝
5. Done

  2021. 10.31 Update
  1. 디코딩 기능이 추가되었습니다.
  1. Decoding function is added.
  
  2. 디코드를 하고 싶다면 위의 과정을 진행 후 Decode 함수를 호출해보세요.
  2. If you want to test it just call Decode function.
