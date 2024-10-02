/* GET pet view */
const travel = (req, res) => {
    res.render('pet', { title: 'Pet Rescue' });
};

module.exports = { 
    pet
};