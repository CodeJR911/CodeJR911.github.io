import { ComponentFixture, TestBed } from '@angular/core/testing';
import { PetCardComponent } from './pet-card.component';
import { Pet } from '../models/pet'; // Import the Pet interface

describe('PetCardComponent', () => {
  let component: PetCardComponent;
  let fixture: ComponentFixture<PetCardComponent>;

  beforeEach(async () => {
    await TestBed.configureTestingModule({
      imports: [PetCardComponent]
    })
    .compileComponents();

    fixture = TestBed.createComponent(PetCardComponent);
    component = fixture.componentInstance;

    // Define a sample pet object for testing
    component.pet = {
      id: 1,
      name: 'Buddy',
      species: 'Dog',
      breed: 'Golden Retriever',
      age: 2,
      imageUrl: 'https://example.com/dog.jpg',
      description: 'A friendly and playful dog.',
      adoptionStatus: 'Available'
    };

    fixture.detectChanges(); // Trigger initial data binding
  });

  it('should create', () => {
    expect(component).toBeTruthy();
  });

  it('should display pet details correctly', () => {
    const compiled = fixture.nativeElement as HTMLElement;
    expect(compiled.querySelector('.card-title')?.textContent).toContain('Buddy');
    expect(compiled.querySelector('.card-text')?.textContent).toContain('Dog');
    expect(compiled.querySelector('.card-text')?.textContent).toContain('Golden Retriever');
    // Add more expectations for other pet details
  });

  it('should display the pet image', () => {
    const compiled = fixture.nativeElement as HTMLElement;
    const imageElement = compiled.querySelector('img') as HTMLImageElement;
    expect(imageElement.src).toContain('https://example.com/dog.jpg');
    expect(imageElement.alt).toBe('Pet Image');
  });
});
