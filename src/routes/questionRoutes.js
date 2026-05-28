import express from 'express';
import fs from 'fs';
import path from 'path';
import { fileURLToPath } from 'url';

const router = express.Router();

const __filename = fileURLToPath(import.meta.url);
const __dirname = path.dirname(__filename);

router.get('/:file', (req, res) => {
    try {
        const filePath = path.join(
            __dirname,
            '../codes',
            req.params.file
        );

        const code = fs.readFileSync(filePath, 'utf-8');

        res.setHeader('Content-Type', 'text/plain');
        res.send(code);

    } catch (error) {
        res.status(404).send('File not found');
    }
});

export default router;