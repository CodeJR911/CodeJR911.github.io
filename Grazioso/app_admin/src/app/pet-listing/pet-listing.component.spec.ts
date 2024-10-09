import { ComponentFixture, TestBed } from '@angular/core/testing';
import { PetListingComponent } from './pet-listing.component';
import { PetCardComponent } from '../pet-card/pet-card.component';
import { PetDataService } from '../services/pet-data.service';
import { HttpClientTestingModule } from '@angular/common/http/testing';
import { of } from 'rxjs';
import { Pet } from '../models/pet';

describe('PetListingComponent', () => {
  let component: PetListingComponent;
  let fixture: ComponentFixture<PetListingComponent>;
  let petDataService: PetDataService;

  beforeEach(async () => {
    await TestBed.configureTestingModule({
      imports: [
        PetListingComponent,
        PetCardComponent, // Import PetCardComponent for testing
        HttpClientTestingModule // Import HttpClientTestingModule for mocking HTTP requests
      ],
      providers: [PetDataService] // Provide PetDataService for testing
    })
    .compileComponents();

    fixture = TestBed.createComponent(PetListingComponent);
    component = fixture.componentInstance;
    petDataService = TestBed.inject(PetDataService);
    fixture.detectChanges();
  });

  it('should create', () => {
    expect(component).toBeTruthy();
  });

  it('should fetch and display pets', () => {
    // Mock the petDataService.getPets method
    const mockPets: Pet[] = [
      {
        id: 1,
        name: 'Buddy',
        species: 'Dog',
        breed: 'Golden Retriever',
        age: 2,
        imageUrl: 'https://example.com/dog.jpg',
        description: 'A friendly and playful dog.',
        adoptionStatus: 'Available'
      },
      // Add more mock pets as needed
    ];
    spyOn(petDataService, 'getPets').and.returnValue(of(mockPets));

    // Trigger data fetching (e.g., ngOnInit)
    component.ngOnInit();

    // Verify that the pets array is populated
    expect(component.pets).toEqual(mockPets);

    // Verify that the PetCardComponent is rendered for each pet
    fixture.detectChanges(); // Update the view after data is fetched
    const petCards = fixture.nativeElement.querySelectorAll('app-pet-card');
    expect(petCards.length).toBe(mockPets.length);
  });
});

