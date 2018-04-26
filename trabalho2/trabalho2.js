function lista() {
  let start = null;
  let tamanho = 0;

  // Cria um novo no
  const Node = (value) => { return { value, next: null}};

  // Insere um novo valor a lista
  const insert = (value) =>{
    if(!start) {
      start = Node(value);
      tamanho++;
      return start;
    }
    let p = start;
    while(p.next) {
      p = p.next;
    }
    p.next = Node(value);
    tamanho++;
    return Node.next;  
  }

  // Remove o ultimo elemento
  const remove = () => {
    if(!start) {
      console.log("lista vazia");
    } else {
      let p = start;
      while(p.next.next) { p = p.next};
      p.next = null;
      tamanho--;
      return start;
    }
  }

  return { 
    tamanho: () => tamanho,
    insert:(value) => insert(value),
    printList: () => console.log(start),
    remove: () => remove()
  }
}

// Lista simplemente encadeada
const list = lista();
list.remove();
list.insert(1);
list.insert(2);
list.insert(3);
list.remove();
list.insert(4);
list.printList();

/* ========================================== */
// algoritmo de ordenacao

// Ordenação com mergeSort
mergeSort = (vet) => {
  if( vet.length === 1){
    return vet;
  }

  const meio = Math.floor(vet.length/2);
  const esquerda = vet.slice(0, meio);
  const direita = vet.slice(meio);

  return juntar(
    mergeSort(esquerda),
    mergeSort(direita)
  )
}

juntar = (esquerda, direita) => {
  let p = [];
  let indexE = 0;
  let indexD = 0;

  while(indexE < esquerda.length && indexD < direita.length) {
    if(esquerda[indexE] < direita[indexD]) {
      p.push(esquerda[indexE]);
      indexE++;
    } else {
      p.push(direita[indexD]);
      indexD++;
    }
  }

  return p.concat(esquerda.slice(indexE)).concat(direita.slice(indexD));
}

const vetor = [43,234,46,67,12,5,234,76,323,87,34];
console.log(mergeSort(vetor))
