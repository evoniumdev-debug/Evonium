const express = require('express');
const cors = require('cors');
const db = require('./database');

const app = express();
app.use(cors());
app.use(express.json());

// Rota 1: Bom guys, essa aqui tá bem simples kkkk ela só retorna a lista de produto com o estoque atualizado, caso alguém queira add mais info, pls, comentar a linha para que eu possa entender o motivo da alteração, obg.
app.get('/api/produtos', (req, res) => {
    const sql = `
        SELECT p.*, e.qtde as estoque 
        FROM tab_produtos p
        JOIN tab_estoque e ON p.id_produto = e.id_produto
    `;
    db.all(sql, [], (err, rows) => {
        if (err) return res.status(500).json({ error: err.message });
        res.json(rows);
    });
});

// Rota 2, bom eu criei essa rota pensando em simular uma finalização de compra, caso alguém ai do gp altere algo, por favor, comentar a linha para que eu possa entender o motivo da alteração, obg.
app.post('/api/finalizar-compra', (req, res) => {
    const { id_cliente, id_usuario, itens, total } = req.body;

    db.serialize(() => {
        db.run("BEGIN TRANSACTION");

        const stmtPedido = db.prepare("INSERT INTO tab_pedidos (id_cliente, id_usuario, data, total) VALUES (?, ?, CURRENT_DATE, ?)");
        stmtPedido.run(id_cliente, id_usuario, total, function(err) {
            if (err) {
                db.run("ROLLBACK");
                return res.status(500).json({ error: "Erro ao gerar pedido" });
            }

            const id_pedido = this.lastID;

            for (let item of itens) {
                const subtotal = item.preco * item.qtde;

                db.run("INSERT INTO tab_itens_pedido (id_pedido, id_produto, valor, qtde, subtotal) VALUES (?, ?, ?, ?, ?)",
                    [id_pedido, item.id_produto, item.preco, item.qtde, subtotal]);

                db.run("UPDATE tab_estoque SET qtde = qtde - ? WHERE id_produto = ?", [item.qtde, item.id_produto]);
            }

            db.run("COMMIT");
            res.json({ success: true, message: "Compra simulada com sucesso!", id_pedido });
        });
    });
});

const PORT = 3000;
app.listen(PORT, () => console.log(`Servidor Evonium tá na porta ${PORT}`));
