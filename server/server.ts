import express from 'express';
import cors from 'cors';
import bodyParser from 'body-parser';

const app = express();
const PORT = 3000;

app.use(cors());
app.use(bodyParser.json());

let posicaoAtual = {
    x: 0,
    y: 0,
    direcao: 'Centro'
};

// Rota POST que a placa vai chamar
app.post('/posicao', (req, res) => {
    const x = Number(req.body.x);
    const y = Number(req.body.y);
    const direcao = req.body.direcao;

    if (!isNaN(x) && !isNaN(y) && typeof direcao === 'string') {
        posicaoAtual = { x, y, direcao };
        console.log(`X: ${x}, Y: ${y}, Direção: ${direcao}`);
        res.status(201).send('Posição recebida com sucesso!');
    } else {
        res.status(400).send('Dados inválidos');
    }
});

// Rota GET que mostra os dados em tempo real
app.get('/', (req, res) => {
    res.send(`
        <html>
        <head>
            <meta http-equiv="refresh" content="1">
            <title>Leitura do Joystick</title>
        </head>
        <body>
            <h1>Leitura do Joystick</h1>
            <p><strong>X:</strong> ${posicaoAtual.x}</p>
            <p><strong>Y:</strong> ${posicaoAtual.y}</p>
            <p><strong>Direção:</strong> ${posicaoAtual.direcao}</p>
        </body>
        </html>
    `);
});

app.listen(PORT, () => {
    console.log(`Servidor rodando em http://192.168.1.84:${PORT}`);
});
