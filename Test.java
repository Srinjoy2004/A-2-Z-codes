// public class Test {
//     public static void main(String[] args) {
//         int a = 10;
//         modifyValue(a);
//         System.out.println(a); // Outputs 10
//     }
//     public static void modifyValue(int x) {
//         x = 20; // Only changes the copy, not the original variable
//     }
// }
public class Test {
    public static void main(String[] args) {
        Person person = new Person("John");
        modifyPerson(person);
        System.out.println(person.name); // Outputs "Doe" because the original object was modified
    }
    public static void modifyPerson(Person p) {
        p.name = "Doe"; // Modifies the original object
        p = new Person("Smith"); // Changes the local copy of the reference
    }
}
class Person {
    String name;
    Person(String name) { this.name = name; }
}
