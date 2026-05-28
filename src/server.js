import express from 'express';
import questionRoutes from './routes/questionRoutes.js';

const app = express();

app.use('/questions', questionRoutes);

app.listen(3000, () => {
    console.log('Server running on port 3000');
});