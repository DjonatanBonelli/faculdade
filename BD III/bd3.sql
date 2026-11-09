-- Parte 1

UPDATE clientes c 
SET nome = 'joão' 
WHERE cpf = '68745120480';

UPDATE clientes c 
SET estado_civil = 'divorciado' 
WHERE c.cpf = '23548754210';

UPDATE veiculos v 
SET comprimento = 18 
WHERE v.matricula = 103;

UPDATE veiculos 
SET vldiaria = vldiaria * 1.124;

DELETE FROM funcionarios f 
WHERE f.nome = 'Marquito'

-- Parte 2

SELECT nome, estado_civil, data_nasc FROM Clientes;

SELECT nome, idade, telefone FROM Funcionarios;

SELECT *
FROM Habilitacoes
WHERE idade_min > 25;

SELECT nome
FROM Veiculos
WHERE comprimento > 10 AND potMotor > 120;

SELECT nome, comprimento
FROM Veiculos
WHERE potMotor BETWEEN 50 AND 300;

SELECT MAX(vlDiaria) AS maior_diaria,
       MIN(vlDiaria) AS menor_diaria
FROM Veiculos;

SELECT COUNT(codloc) AS total
FROM Locacoes
WHERE inicio = '2021-12-29';

SELECT MIN(idade) AS mais_novo,
       MAX(idade) AS mais_velho,
       AVG(idade) AS media_idades
FROM Funcionarios;

SELECT DISTINCT estado_civil FROM Clientes;

SELECT nome
FROM Funcionarios
UNION
SELECT nome
FROM Clientes;

-- Parte 3

SELECT v.nome, tv.descricao
FROM veiculos v JOIN tipos_veiculos tv ON v.codtipo = tv.codtipo;

SELECT f.nome 
FROM funcionarios f JOIN locacoes l ON f.codf = l.codf
WHERE l.inicio = '17-02-2022';

SELECT c.nome, c.num_filhos, c.estado_civil, h.descricao
FROM clientes c 
JOIN habilitacoes h ON c.codh = h.codh ;

SELECT v.nome, v.potmotor, tv.descricao, l.inicio, l.fim, c.nome 
FROM tipos_veiculos tv 
JOIN veiculos v ON tv.codtipo = v.codtipo
JOIN locacoes l ON l.matricula = v.matricula 
JOIN clientes c ON c.cpf = l.cpf
WHERE c.cpf = '68745120480';

SELECT tv.descricao , count(tv.codtipo)
FROM veiculos v 
JOIN tipos_veiculos tv ON v.codtipo = tv.codtipo
GROUP BY tv.descricao;

SELECT h.tipo, count(v.matricula)
FROM habilitacoes h
JOIN clientes c ON c.codh = h.codh
JOIN locacoes l ON c.cpf = l.cpf 
JOIN veiculos v ON l.matricula  = v.matricula
GROUP BY h.tipo;

SELECT 
    (SELECT v.nome 
     FROM Veiculos v
     JOIN Locacoes l ON v.matricula = l.matricula
     GROUP BY v.nome
     ORDER BY COUNT(*) DESC
     LIMIT 1) AS mais_locado,
     
    (SELECT v.nome 
     FROM Veiculos v
     JOIN Locacoes l ON v.matricula = l.matricula
     GROUP BY v.nome
     ORDER BY COUNT(*) ASC
     LIMIT 1) AS menos_locado;

SELECT codF, COUNT(*) AS qtd_locacoes
FROM Locacoes
GROUP BY codF
ORDER BY qtd_locacoes DESC
LIMIT 1;

SELECT AVG(fim - inicio) AS media_dias
FROM Locacoes;

SELECT v.codTipo, AVG(l.fim - l.inicio) AS media_dias
FROM Veiculos v
JOIN Locacoes l ON v.matricula = l.matricula
GROUP BY v.codTipo;

SELECT l.codLoc,
       f.nome AS funcionario,
       v.nome AS barco,
       c.nome AS cliente,
       l.valor * (l.fim - l.inicio) AS valor_calculado
FROM Locacoes l
JOIN Funcionarios f ON l.codF = f.codF
JOIN Veiculos v ON l.matricula = v.matricula
JOIN Clientes c ON l.cpf = c.cpf; 

-- Parte 4

SELECT c.nome 
FROM clientes c JOIN locacoes l ON c.cpf = l.cpf;

SELECT v.nome
FROM veiculos v
FULL OUTER JOIN locacoes l ON v.matricula = l.matricula 
WHERE v.matricula IS NULL OR l.matricula IS NULL;

SELECT v.nome, tv.descricao 
FROM veiculos v JOIN tipos_veiculos tv ON v.codtipo = tv.codtipo 
WHERE v.vlDiaria = (SELECT MAX(vlDiaria) FROM Veiculos)
   OR v.vlDiaria = (SELECT MIN(vlDiaria) FROM Veiculos);

SELECT MAX(valor) AS maior_valor,
       MIN(valor) AS menor_valor
FROM Locacoes
WHERE inicio = '2021-12-29';

SELECT *
FROM habilitacoes h
WHERE NOT EXISTS (
    SELECT 1
    FROM clientes c
    WHERE c.codH = h.codH
);

SELECT v.nome, l.inicio, COUNT(*) AS qtd
FROM Veiculos v
JOIN Locacoes l ON v.matricula = l.matricula
GROUP BY v.nome, l.inicio
HAVING COUNT(*) > 1;

SELECT *
FROM Veiculos v
WHERE NOT EXISTS (
    SELECT 1
    FROM Locacoes l
    WHERE l.matricula = v.matricula
);

SELECT *
FROM Clientes c
WHERE EXISTS (
    SELECT 1
    FROM Locacoes l
    WHERE l.cpf = c.cpf
      AND l.inicio = '2021-12-29'
);

SELECT v.*
FROM Veiculos v
WHERE NOT EXISTS (
    SELECT 1
    FROM Clientes c
    WHERE NOT EXISTS (
        SELECT 1
        FROM Locacoes l
        WHERE l.matricula = v.matricula
          AND l.cpf = c.cpf
    )
);

SELECT *
FROM Habilitacoes h
WHERE h.descricao ILIKE '%todas as embarcações%';
