/* GET pet view */
const pet = (req, res) => {
    // Example pet data (replace with database or API call)
    const petData = {
      name: 'Buddy',
      species: 'Dog',
      breed: 'Golden Retriever',
      age: 2,
      imageUrl: 'https://example.com/dog.jpg',
      description: 'A friendly and playful dog.',
    };
  
    res.render('pet', { title: 'Pet Rescue', pet: petData });
  };
  
  module.exports = { 
    pet 
  };
  