import { Component, OnInit } from '@angular/core';
import { PetDataService } from '../services/pet-data.service';
import { Pet } from '../models/pet';

@Component({
  selector: 'app-pet-listing',
  standalone: true,
  imports: [PetCardComponent], // Import PetCardComponent
  templateUrl: './pet-listing.component.html',
  styleUrl: './pet-listing.component.css'
})
export class PetListingComponent implements OnInit {
  pets: Pet[] = []; // Array to store fetched pet data

  constructor(private petDataService: PetDataService) { }

  ngOnInit(): void {
    // Fetch pet data when the component initializes
    this.petDataService.getPets().subscribe(
      (pets) => {
        this.pets = pets;
      },
      (error) => {
        console.error('Error fetching pets:', error);
        // Handle error appropriately, e.g., display an error message
      }
    );
  }
}

