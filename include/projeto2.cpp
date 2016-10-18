class simbolo{

}

/*pipeline?
Ler string, se digito -> armazene
	número? string-to-int() para transformar em inteiro, enqueue
	operador? separe, enqueue
	simbolo errado? aborte


criar fila de simbolos com números e operadores
[34][+][2][*][5]

fila <simbolos> F //Formatopósfixo  //enqueue, dequeue, front
pilha <int> S
WHILE(fila_notempty()){
	simbolo x = F.front();
	F.dequeue();
	if (x.isOperand){
		S.push(x.getValue);
	} else {
		ope2 = S.pop();
		ope1 = S.pop();
		switch (x.getOperator()){
			case '+':
				r = ope1 + ope2;
			case '-':
				r = ope1 - ope2;
			...
		}
		S.push(r);
	}
	return S.pop();
}
for (auto: expression){
	if (is_operand(ch)){
		postfix.push_back(ch);
	} else if (ch == '(' ){
		S.pushback(ch);
	} else if (is_operand(element))
}