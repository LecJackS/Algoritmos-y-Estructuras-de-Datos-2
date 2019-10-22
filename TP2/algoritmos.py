# CADA registro guarda su clave
Registro se representa con estrReg, donde
estrReg es tupla < clave:     nombreCampo,
                   registros: diccTrie(valor) >

# Supongo que las claves de diccTrie son String, por eso el diccionario solo toma
# el tipo 'tabla', que corresponde al tipo del valor, siendo string el tipo de la
# clave por defecto. 
#iFrom (in bdd: diccTrie(tabla), in nt: nombre_tabla) -> res: conj(registro)
iFrom (in bdd: estrBdD, in nt: nombre_tabla) -> res: conj(estrReg)
    estrTabla: t <- obtener(nt, bdd)
    res <- t.registros.valores #.valores
    # asi como diccionario tiene "claves", podemos extenderlo con "valores"?
    #Complejidad: O(1)
    #Justificación: el conjunto de valores se devuelve por referencia

# Usando auxiliar
obtenerValores(in d: diccTrie(estrReg)) -> res: conj(estrReg)
    for i <- 0 to Cardinal(d.claves) do 
        # quiero hacer
        res.Agregar(d[dameUno(d.claves)])
        # pero dameUno no existe en este universo



Claves(in d : diccString(α)) → res : conj(string)
Pre ≡ {true}
Post ≡ {alias(res = claves(d))}
Complejidad: O(1)
Descripción: devuelve el conjunto de las claves del diccionario.
Aliasing: res no es modificable.

Valores(in d : diccString(α)) → res : conj(α)
Pre ≡ {true}
Post ≡ {alias(res = valores(d))}
Complejidad: O(1)
Aliasing: res no es modificable.

### PROJ

Consulta se representa con estrConsulta, donde
estrConsulta es diccTrie(valor)

iProj (in consulta: estrConsulta, in conjC: conj(nombreCampo)) -> res: estrConsulta
    # Filtra campos de la consulta que coinciden con cc
    for ( campo : conjC ) do 
        if def?(campo, consulta)
            res.definir(campo, consulta[campo])

### UNION: Obs: falta especificar? 
iUnion (in consulta1: estrConsulta, in consulta2: estrConsulta) -> res: estrConsulta
    if cardinal(consulta2) < cardinal(consulta1)
        res <- consulta1
        for ( c2 : consulta2.claves ) do
            res.definir(c2, consulta2[c2])
    else
        res <- consulta2
        for ( c1 : consulta1.claves ) do
            res.definir(c1, consulta1[c1])

### INTER
iInter (in consulta1: estrConsulta, in consulta2: estrConsulta) -> res: estrConsulta
    for ( c1 : consulta1.claves ) do
        if(def?(c1, consulta2))
            # Solo consultas con mismas claves
            for ( r1 : consulta1[c1].registros.claves)
                # Reveer estructura consulta

### RENAME





### PRODUCT

### MATCH

### SELECT